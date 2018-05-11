//
//  PlacesTableViewController.swift
//  SMPExample
//
//  Copyright © 2018 SessionM. All rights reserved.
//

import SessionMPlacesKit
import UIKit

class PlaceCell: UITableViewCell {
    @IBOutlet var placeID: UILabel!
    @IBOutlet var name: UILabel!
    @IBOutlet var status: UILabel!
    @IBOutlet var points: UILabel!
    @IBOutlet var address: UILabel!
    @IBOutlet var distance: UILabel!
    @IBOutlet var distanceUnits: UILabel!
    @IBOutlet var brandImage: UIImageView!
    @IBOutlet var imageWidth: NSLayoutConstraint!
    @IBOutlet var imageHeight: NSLayoutConstraint!
}

class PlacesTableViewController: UITableViewController, CLLocationManagerDelegate {
    private let placesManager = SMPlacesManager.instance()
    private let locationManager = CLLocationManager()
    private var lastUpdate: TimeInterval = Date.timeIntervalSinceReferenceDate
    private var places: [SMPlace] = []
    private var checkinAlert = UIAlertController()

    override func viewDidLoad() {
        super.viewDidLoad()

        locationManager.distanceFilter = 5.0
        locationManager.desiredAccuracy = kCLLocationAccuracyNearestTenMeters
        locationManager.delegate = self
    }

    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)

        if ((CLLocationManager.authorizationStatus() == .authorizedAlways) || (CLLocationManager.authorizationStatus() == .authorizedWhenInUse)) {
            if let location = locationManager.location {
                startFetch(location)
            } else {
                locationManager.requestWhenInUseAuthorization()
            }
        }
    }

    override func viewDidDisappear(_ animated: Bool) {
        self.locationManager.stopUpdatingLocation()
        super.viewDidDisappear(animated)
    }

    func locationManager(_ manager: CLLocationManager, didChangeAuthorization status: CLAuthorizationStatus) {
        if ((CLLocationManager.authorizationStatus() == .authorizedAlways) || (CLLocationManager.authorizationStatus() == .authorizedWhenInUse)) {
            self.locationManager.startUpdatingLocation()
            if let location = locationManager.location {
                startFetch(location)
            }
        } else {
            locationManager.requestWhenInUseAuthorization()
        }
    }

    func locationManager(_ manager: CLLocationManager, didUpdateLocations locations: [CLLocation]) {
        if let location = locations.first {
            let now = Date.timeIntervalSinceReferenceDate
            if ((now - lastUpdate) > 10.0) {
                lastUpdate = now
                startFetch(location)
            }
        }
    }

    @IBAction private func onRefresh(_ x: AnyObject) {
        if let location = self.locationManager.location {
            startFetch(location)
        }
    }

    private func startFetch(_ location: CLLocation) {
        self.refreshControl?.beginRefreshing()
        placesManager.fetchPlaces(near: location) { (places: [SMPlace]?, error: SMError?) in
            if let err = error {
                Util.failed(self, message: err.message)
            } else {
                self.onFetchPlaces(places)
            }
            self.refreshControl?.endRefreshing()
        }
    }

    private func onFetchPlaces(_ places: [SMPlace]?) {
        if let unsorted = places {
            self.places = unsorted.sorted(by: { (place1: SMPlace, place2: SMPlace) -> Bool in
                return place1.distance < place2.distance
            })
            tableView.reloadData()
        }
    }

    // MARK: - Table view data source

    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return self.places.count
    }


    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "PlaceCell", for: indexPath) as! PlaceCell

        let place = self.places[indexPath.row]

        cell.placeID.text = "ID: \(place.placeID)"
        cell.name.text = "Name: \(place.name!)"
        cell.status.text = "Status: \(place.checkinStatus)"
        cell.points.text = "Points: \(place.points)"
        cell.address.text = "Address: \(place.address!)"
        cell.distance.text = "Distance: \(place.distance)"
        cell.distanceUnits.text = "\(place.distanceLabel!)"

        if let img = place.iconURL, img.count > 0 {
            Util.loadFrom(img, callback: { (image) in
                cell.brandImage.backgroundColor = UIColor.darkGray
                cell.brandImage.image = image

                let maxImageHeight = min(cell.contentView.bounds.size.height - cell.brandImage.frame.origin.y - 20, image.size.height)
                let maxImageWidth =  min(cell.contentView.bounds.size.width, image.size.width)
                var ratio: CGFloat = 1.0
                if (maxImageWidth < maxImageHeight) {
                    ratio = maxImageWidth / image.size.width
                } else {
                    ratio = maxImageHeight / image.size.height
                }
                cell.imageHeight.constant = image.size.height * ratio
                cell.imageWidth.constant = image.size.width * ratio
            })
        }

        return cell
    }

    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {

        let place = self.places[indexPath.row]
        let msg = "Check In: \(place.name!)"

        checkinAlert = UIAlertController(title: "Check in", message: msg, preferredStyle: .alert)
        present(checkinAlert, animated: true) {
            self.placesManager.checkIntoPlace(place, completionHandler: { (checkin: SMPlaceCheckinResult?, error: SMError?) in
                if let err = error {
                    self.checkinAlert.dismiss(animated: true) {
                        Util.failed(self, message: err.message)
                    }
                } else {
                    self.onCheckin(checkin)
                }
            })
        }
    }

    private func onCheckin(_ checkin: SMPlaceCheckinResult?) {
        if let checkedIn = checkin {
            checkinAlert.message = "Success: \(checkedIn.placeID)"
            checkinAlert.addAction(UIAlertAction(title: "Dismiss", style: .default, handler: { (alert: UIAlertAction) in
                self.startFetch(self.locationManager.location!)
            }))
        }
    }

    @IBAction private func logout(_ sender: AnyObject) {
        if let provider = SessionM.authenticationProvider() as? SessionMOAuthProvider {
            provider.logOutUser { (authState, error) in
                LoginViewController.loginIfNeeded(self)
            }
        }
    }
}
