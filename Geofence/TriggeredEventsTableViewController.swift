//
//  TriggeredEventsTableViewController.swift
//  SMPExample
//
//  Copyright © 2017 SessionM. All rights reserved.
//

import UIKit

class EventCell: UITableViewCell {
    @IBOutlet var date: UILabel!
    @IBOutlet var venueID: UILabel!
    @IBOutlet var eventName: UILabel!
    @IBOutlet var location: UILabel!
    @IBOutlet var distance: UILabel!
}

class TriggeredEventsTableViewController: UITableViewController, SessionMDelegate {
    private let sessionM = SessionM.sharedInstance()
    private var locationManager: SMLocationManager = SMLocationManager.sharedInstance()
    private var events: [[AnyHashable : Any]] = []

    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)

        sessionM.delegate = self
    }

    // MARK: - Table view data source

    override func numberOfSections(in tableView: UITableView) -> Int { return 1 }

    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return events.count
    }

    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "EventCell", for: indexPath) as? EventCell

        if let c = cell {
            let event = events[indexPath.row]
            let geofence = event["geofence"] as! NSDictionary
            let triggerType = geofence["trigger_type"] as! String
            let time = event["timestamp"] as! NSNumber
            let date = Date(timeIntervalSince1970: (time.doubleValue/1000.0))
            let formatter = DateFormatter()
            formatter.dateStyle = .none
            formatter.timeStyle = .short
            c.date.text = "\(formatter.string(from: date)) - \(triggerType)"

            let data = event["data"] as! NSDictionary
            let venueID = data["venue_id"] as! NSNumber
            c.venueID.text = "Venue ID: \(venueID.stringValue)"

            let eventName = event["event"] as! String
            c.eventName.text = "Event: \(eventName)"

            let location = event["location"] as! NSDictionary
            let latitude = location["latitude"] as! NSNumber
            let longitude = location["longitude"] as! NSNumber
            c.location.text = String.localizedStringWithFormat("Location: %.7f, %.7f", latitude.doubleValue, longitude.doubleValue)

            let distance = event["distance"] as! NSNumber
            c.distance.text = String.localizedStringWithFormat("Distance from center: %.7f", distance.doubleValue)
        }

        return cell!
    }

    func addEvent(_ event: [AnyHashable : Any]) {
        events.append(event)
        tableView.reloadData()
    }

    func sessionM(_ sessionM: SessionM, didUpdateUser user: SMUser) {
        LoginViewController.loginIfNeeded(self.tabBarController!)
    }

    @IBAction private func logout(_ sender: AnyObject) {
        sessionM.logOutUser()
    }
}
