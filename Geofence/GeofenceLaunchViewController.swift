//
//  GeofenceLaunchViewController.swift
//  SMPExample
//
//  Copyright © 2018 SessionM. All rights reserved.
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
        locationManager.delegate = self

        if CLLocationManager.authorizationStatus() == .authorizedWhenInUse || CLLocationManager.authorizationStatus() == .authorizedAlways {
            if sessionM.user.isRegistered {
                performSegue(withIdentifier: "Main", sender: self)
            } else {
                LoginViewController.login(self)
            }
        } else {
            locationManager.requestWhenInUseAuthorization()
        }
    }

    func locationManager(_ manager: CLLocationManager, didChangeAuthorization status: CLAuthorizationStatus) {
        switch status {
        case .authorizedWhenInUse:
            presentNextController()
        case .authorizedAlways:
            presentNextController()
        default:
            break
        }
    }
}
