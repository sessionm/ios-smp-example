//
//  GeofenceLaunchViewController.swift
//  SMPExample
//
//  Copyright © 2017 SessionM. All rights reserved.
//

import CoreLocation
import UIKit

class GeofenceLaunchViewController: LaunchViewController, CLLocationManagerDelegate {
    private let locationManager = CLLocationManager()

    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)

        if sessionM.sessionState != .startedOnline && UIApplication.shared.applicationState == .background {
            presentNextController()
        }
    }

    override func presentNextController() {
        if CLLocationManager.authorizationStatus() == .authorizedAlways {
            if sessionM.user.isRegistered {
                performSegue(withIdentifier: "Main", sender: self)
            } else {
                LoginViewController.login(self)
            }
        } else {
            locationManager.delegate = self
            locationManager.requestAlwaysAuthorization()
        }
    }

    func locationManager(_ manager: CLLocationManager, didChangeAuthorization status: CLAuthorizationStatus) {
        switch status {
        case .authorizedAlways:
            presentNextController()
        default:
            break
        }
    }
}
