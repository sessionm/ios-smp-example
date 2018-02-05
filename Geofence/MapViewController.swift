//
//  MapViewController.swift
//  SMPExample
//
//  Copyright © 2018 SessionM. All rights reserved.
//

import CCHMapClusterController
import MapKit
import UIKit

class MapViewController: UIViewController, SessionMDelegate, MKMapViewDelegate, CCHMapClusterControllerDelegate, UITableViewDataSource, UITableViewDelegate, CLLocationManagerDelegate {
    @IBOutlet private var mapView: MKMapView!
    @IBOutlet private var annotationTableView: UITableView!

    private let sessionM = SessionM.sharedInstance()
    private let locationManager = SMLocationManager.sharedInstance()
    private var infoClusterController: CCHMapClusterController!
    private var triggerClusterController: CCHMapClusterController!
    private var infoAnnotations: [GeofenceAnnotation] = []

    override func viewDidLoad() {
        super.viewDidLoad()

        infoClusterController = CCHMapClusterController(mapView: mapView)
        infoClusterController.cellSize = 30.0
        infoClusterController.delegate = self
        triggerClusterController = CCHMapClusterController(mapView: mapView)
        triggerClusterController.cellSize = 30.0
        triggerClusterController.delegate = self

        NotificationCenter.default.addObserver(self, selector: #selector(locationDidUpdate(_:)), name: NSNotification.Name(locationUpdateNotification), object: nil)
        NotificationCenter.default.addObserver(self, selector: #selector(locationEventsDidUpdate(_:)), name: NSNotification.Name(updatedLocationEventsNotification), object: nil)
        NotificationCenter.default.addObserver(self, selector: #selector(triggeredEvent(_:)), name: NSNotification.Name(triggeredLocationEventNotification), object: nil)
        SMLocationManager.registerGeofenceService()
        updateMapViewRegion()
    }

    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)

        sessionM.delegate = self
        SMMessagesManager.instance().registerForRemoteNotifications()

        let clManager = CLLocationManager()
        clManager.delegate = self
        clManager.requestAlwaysAuthorization()
    }

    private func updateMapViewRegion() {
        if let location = locationManager.currentGeoLocation {
            let point = MKMapPointForCoordinate(location.coordinate)
            let region = MKCoordinateRegionMakeWithDistance(MKCoordinateForMapPoint(point), 200, 480)
            mapView.setRegion(region, animated: true)
            NotificationCenter.default.removeObserver(self, name: NSNotification.Name(locationUpdateNotification), object: nil)
        }
    }

    @objc private func locationDidUpdate(_ notification: Notification) {
        updateMapViewRegion()
    }

    @objc private func locationEventsDidUpdate(_ notification: Notification) {
        if let info = notification.userInfo {
            let monitoredRegions = info[kMonitoredRegions] as! Set<CLCircularRegion>
            let locationEvents = info[kLocationEvents] as! [SMGeolocationEvent]
            mapView.removeOverlays(mapView.overlays)
            infoClusterController.removeAnnotations(infoAnnotations, withCompletionHandler: nil)
            infoAnnotations.removeAll()
            for region in monitoredRegions {
                let circle = MKCircle(center: region.center, radius: region.radius)
                mapView.add(circle, level: .aboveLabels)
                let regionEvents = locationEvents.filter({ (event) -> Bool in
                    return region.identifier == event.identifier
                })
                for event in regionEvents {
                    let infoAnnotation = GeofenceAnnotation(type: .info)
                    infoAnnotation.coordinate = CLLocationCoordinate2DMake(region.center.latitude, region.center.longitude)
                    infoAnnotation.title = "Event: \(event.eventName)"
                    infoAnnotation.subtitle = String.localizedStringWithFormat("%@ at (%.7f, %.7f)", event.triggerTypeString, infoAnnotation.coordinate.latitude, infoAnnotation.coordinate.longitude)
                    infoAnnotations.append(infoAnnotation)
                }
                infoClusterController.addAnnotations(infoAnnotations, withCompletionHandler: nil)
            }
        }
    }

    @objc private func triggeredEvent(_ notification: Notification) {
        guard let info = notification.userInfo else {
            return
        }
        guard let eventArray = info.values.first as? Array<Dictionary<String, Any>> else {
            return
        }
        guard var eventDict = eventArray.first else {
            return
        }

        let eventName = info.keys.first as! String
        let geofence = eventDict["geofence"] as! NSDictionary
        let triggerType = geofence["trigger_type"] as! String
        let location = eventDict["location"] as! NSDictionary
        let latitude = location["latitude"] as! NSNumber
        let longitude = location["longitude"] as! NSNumber
        let triggerAnnotation = GeofenceAnnotation(type: .trigger(triggerType))
        triggerAnnotation.coordinate = CLLocationCoordinate2DMake(latitude.doubleValue, longitude.doubleValue)
        triggerAnnotation.title = "Event: \(eventName)"
        triggerAnnotation.subtitle = String.localizedStringWithFormat("%@ at (%.7f, %.7f)", triggerType, triggerAnnotation.coordinate.latitude, triggerAnnotation.coordinate.longitude)
        triggerClusterController.addAnnotations([triggerAnnotation], withCompletionHandler: nil)
        if let navController = tabBarController?.viewControllers?[1] as? UINavigationController {
            if let root = navController.viewControllers.first as? TriggeredEventsTableViewController {
                eventDict["event"] = eventName
                root.addEvent(eventDict)
            }
        }
    }

    func mapView(_ mapView: MKMapView, viewFor annotation: MKAnnotation) -> MKAnnotationView? {
        guard let clusterAnnotation = annotation as? CCHMapClusterAnnotation else {
            return nil
        }
        guard let geoAnnotation = clusterAnnotation.annotations.first as? GeofenceAnnotation else {
            return nil
        }

        let identifier = "\(geoAnnotation.type.annotationTitle)"
        guard let view = mapView.dequeueReusableAnnotationView(withIdentifier: identifier) as? MKPinAnnotationView else {
            let view = MKPinAnnotationView(annotation: clusterAnnotation, reuseIdentifier: identifier)
            view.pinTintColor = geoAnnotation.type.pinTintColor
            view.canShowCallout = false
            return view
        }

        view.annotation = annotation
        return view
    }

    func mapView(_ mapView: MKMapView, rendererFor overlay: MKOverlay) -> MKOverlayRenderer {
        let renderer = MKCircleRenderer(overlay: overlay)
        renderer.strokeColor = GeofenceAnnotationType.info.pinTintColor
        renderer.fillColor = GeofenceAnnotationType.info.pinTintColor
        renderer.alpha = 0.2
        renderer.lineWidth = 2.0
        return renderer
    }

    func mapView(_ mapView: MKMapView, didSelect view: MKAnnotationView) {
        if view.annotation!.isEqual(mapView.userLocation) {
            return
        }

        annotationTableView.reloadData()
        mapView.addSubview(annotationTableView)
        annotationTableView.flashScrollIndicators()
    }

    func mapView(_ mapView: MKMapView, didDeselect view: MKAnnotationView) {
        annotationTableView.removeFromSuperview()
    }

    func mapClusterController(_ mapClusterController: CCHMapClusterController!, titleFor mapClusterAnnotation: CCHMapClusterAnnotation!) -> String! {
        if mapClusterAnnotation.annotations.count == 1, let annotation = mapClusterAnnotation.annotations.first as? MKAnnotation {
            return annotation.title!!
        } else {
            return ""
        }
    }

    func mapClusterController(_ mapClusterController: CCHMapClusterController!, subtitleFor mapClusterAnnotation: CCHMapClusterAnnotation!) -> String! {
        if mapClusterAnnotation.annotations.count == 1, let annotation = mapClusterAnnotation.annotations.first as? MKAnnotation {
            return annotation.subtitle!!
        } else {
            return ""
        }
    }

    func mapClusterController(_ mapClusterController: CCHMapClusterController!, willReuse mapClusterAnnotation: CCHMapClusterAnnotation!) {
    }

    func numberOfSections(in tableView: UITableView) -> Int {
        return 1
    }

    func tableView(_ tableView: UITableView, titleForHeaderInSection section: Int) -> String? {
        guard let clusterAnnotation = mapView.selectedAnnotations.first as? CCHMapClusterAnnotation else {
            return nil
        }
        guard let annotation = Array(clusterAnnotation.annotations).first! as? GeofenceAnnotation else {
            return nil
        }
        return annotation.type.annotationTitle
    }

    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        guard let annotation = mapView.selectedAnnotations.first as? CCHMapClusterAnnotation else {
            return 0
        }
        return annotation.annotations.count
    }

    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "AnnotationCell", for: indexPath)
        guard let clusterAnnotation = mapView.selectedAnnotations.first as? CCHMapClusterAnnotation else {
            return cell
        }
        guard let annotation = Array(clusterAnnotation.annotations)[indexPath.row] as? MKAnnotation else {
            return cell
        }
        cell.textLabel!.text = annotation.title!!
        cell.detailTextLabel!.text = annotation.subtitle!!
        return cell
    }

    func sessionM(_ sessionM: SessionM, didUpdateUser user: SMUser) {
        LoginViewController.loginIfNeeded(self.tabBarController!)
    }

    @IBAction private func logout(_ sender: AnyObject) {
        sessionM.logOutUser()
    }

    @IBAction private func centerMap(_ sender: UIBarButtonItem) {
        if let location = locationManager.currentGeoLocation {
            mapView.setCenter(location.coordinate, animated: true)
        }
    }
}
