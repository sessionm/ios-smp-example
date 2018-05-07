//
//  LaunchViewController.swift
//  SMPExample
//
//  Copyright © 2018 SessionM. All rights reserved.
//

import SessionMCoreKit
import UIKit

class LaunchViewController: UIViewController {
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)

        while SessionM.notReadyReason().contains([.noAuthenticationProvider, .noConfig]) {}
        presentNextController()
    }

    func presentNextController() {
        if let provider = SessionM.authenticationProvider(), provider.isAuthenticated() {
            performSegue(withIdentifier: "Main", sender: self)
        } else {
            LoginViewController.login(self)
        }
    }
}
