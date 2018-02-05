//
//  LaunchViewController.swift
//  SMPExample
//
//  Copyright © 2018 SessionM. All rights reserved.
//

import UIKit

class LaunchViewController: UIViewController, SessionMDelegate {
    let sessionM = SessionM.sharedInstance()

    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)

        sessionM.delegate = self
        if sessionM.sessionState == .startedOnline {
            presentNextController()
        }
    }

    func sessionM(_ sessionM: SessionM, didUpdateUser user: SMUser) {
        if sessionM.sessionState == .startedOnline {
            presentNextController()
        }
    }

    func presentNextController() {
        if sessionM.user.isRegistered {
            performSegue(withIdentifier: "Main", sender: self)
        } else {
            LoginViewController.login(self)
        }
    }
}
