//
//  RewardsLaunchViewController.swift
//  SMPExample
//
//  Copyright © 2018 SessionM. All rights reserved.
//

import UIKit

class RewardsLaunchViewController: LaunchViewController {
    override func presentNextController() {
        if sessionM.user.isLoggedIn {
            performSegue(withIdentifier: "Main", sender: self)
        } else {
            LoginViewController.login(self)
        }
    }
}
