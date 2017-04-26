//
//  AuthLaunchViewController.swift
//  SMPExample
//
//  Copyright © 2017 SessionM. All rights reserved.
//

import UIKit

class AuthLaunchViewController: LaunchViewController {
    override func presentNextController() {
        performSegue(withIdentifier: "Main", sender: self)
    }
}
