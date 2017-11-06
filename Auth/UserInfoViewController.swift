//
//  UserInfoViewController.swift
//  SMPExample
//
//  Copyright © 2017 SessionM. All rights reserved.
//

import UIKit

class UserInfoViewController: UIViewController {
    @IBOutlet var userInfo: UITextView!

    private let identityManager = SMIdentityManager.instance()
    private let userManager = SMUserManager.instance()

    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)

        if let user = userManager.currentUser {
            let info = NSMutableAttributedString(string: "")
            let sortedUser = user.asDictionary().sorted(by: { ( kv1: (key: String, value: NSObject), kv2: (key: String, value: NSObject) ) -> Bool in
                return kv1.key < (kv2.key)
            })
            for (key, value) in sortedUser {
                let keyValue = NSMutableAttributedString(string: "\(key): \(value)\n")
                keyValue.addAttribute(NSAttributedStringKey.foregroundColor, value: UIColor.blue, range: NSMakeRange(0, key.count))
                info.append(keyValue)
            }
            userInfo.attributedText = info
        }
    }

    @IBAction private func logout(_ sender: AnyObject) {
        let alert = UIAlertController(title: "Logging out...", message: nil, preferredStyle: .alert)
        present(alert, animated: true) {
            self.identityManager.logOutUser() { (state: SMAuthState, error: SMError?) in
                alert.dismiss(animated: true) {
                    if let error = error {
                        Util.failed(self, message: error.message)
                    } else if state == .loggedOut {
                        self.navigationController?.popViewController(animated: true)
                    }
                }
            }
        }
    }
}
