//
//  TriggeredEventsTableViewController.swift
//  SMPExample
//
//  Copyright © 2018 SessionM. All rights reserved.
//

import SessionMGeofenceKit
import UIKit

class EventCell: UITableViewCell {
    @IBOutlet var date: UILabel!
    @IBOutlet var venueID: UILabel!
    @IBOutlet var eventName: UILabel!
    @IBOutlet var location: UILabel!
    @IBOutlet var distance: UILabel!
}

class TriggeredEventsTableViewController: UITableViewController {
    private var geofenceManager = SMGeofenceManager.instance()
    private var events: [[AnyHashable : Any]] = []

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

    @IBAction private func logout(_ sender: AnyObject) {
        if let provider = SessionM.authenticationProvider() as? SessionMOAuthProvider {
            provider.logOutUser { (authState, error) in
                LoginViewController.loginIfNeeded(self.tabBarController!)
            }
        }
    }
}
