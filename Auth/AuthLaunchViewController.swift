//
//  AuthLaunchViewController.swift
//  SMPExample
//
//  Copyright © 2018 SessionM. All rights reserved.
//

import UIKit

class AuthLaunchViewController: LaunchViewController {
    override func presentNextController() {
        performSegue(withIdentifier: "Main", sender: self)
    }
}
