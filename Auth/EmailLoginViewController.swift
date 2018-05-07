//
//  EmailLoginViewController.swift
//  SMPExample
//
//  Copyright © 2018 SessionM. All rights reserved.
//

import SessionMIdentityKit
import UIKit

class EmailLoginViewController: UIViewController, UITextFieldDelegate {
    @IBOutlet var email: UITextField!
    @IBOutlet var password: UITextField!
    @IBOutlet var logout: UIBarButtonItem!
    @IBOutlet var status: UILabel!
    @IBOutlet var userInfo: UIButton!

    private let authProvider = SessionM.authenticationProvider() as? SessionMOauthProvider
    private let userManager = SMUserManager.instance()

    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)

        if let user = userManager.currentUser {
            authProvider?.requestAuthCode { (authCode, error) in
                if let authCode = authCode {
                    DispatchQueue.main.async {
                        self.logout.isEnabled = true
                        self.userInfo.isEnabled = true
                        let email = (user.email != nil) ? user.email! : "Anonymous User"
                        self.status.text? = "Email: \(email)\nID: \(user.userID)\nAuth Code: \(authCode)"
                    }
                }
            }
        } else {
            logout.isEnabled = false
            userInfo.isEnabled = false
            status.text? = "Logged Out"
        }

        NotificationCenter.default.addObserver(self, selector: #selector(authStateDidUpdate(_:)), name: NSNotification.Name(updatedAuthStateNotification), object: nil)
        NotificationCenter.default.addObserver(self, selector: #selector(userDidUpdate(_:)), name: NSNotification.Name(updatedUserNotification), object: nil)
    }

    override func viewWillDisappear(_ animated: Bool) {
        NotificationCenter.default.removeObserver(self)
        super.viewWillDisappear(animated)
    }

    @objc private func authStateDidUpdate(_ notification: NSNotification) {
        guard let state = notification.userInfo?[kManagerNotificationData] as? NSNumber else {
            return
        }
        guard let authState = SMAuthState(rawValue: state.uintValue) else {
            return
        }

        switch authState {
        case .loggedOut:
            logout.isEnabled = false
            userInfo.isEnabled = false
            status.text? = "Logged Out"
        default:
            break
        }
    }

    @objc private func userDidUpdate(_ notification: NSNotification) {
        if let user = userManager.currentUser {
            authProvider?.requestAuthCode { (authCode, error) in
                if let authCode = authCode {
                    DispatchQueue.main.async {
                        self.logout.isEnabled = true
                        self.userInfo.isEnabled = true
                        let email = (user.email != nil) ? user.email! : "Anonymous User"
                        self.status.text? = "Email: \(email)\nID: \(user.userID)\nAuth Code: \(authCode)"
                    }
                }
            }
        } else {
            logout.isEnabled = false
            userInfo.isEnabled = false
            status.text? = "Logged Out"
        }
    }


    @IBAction private func authenticate(_ sender: UIButton) {
        guard let emailText = email.text, !emailText.isEmpty else {
            Util.failed(self, message: "Email is required")
            return
        }
        guard let passwordText = password.text, !passwordText.isEmpty else {
            Util.failed(self, message: "Password is required")
            return
        }

        let alert = UIAlertController(title: "Authenticating...", message: nil, preferredStyle: .alert)
        present(alert, animated: true) {
            self.authProvider?.authenticateUser(emailText, password: passwordText) { (state: SMAuthState, error: SMError?) in
                alert.dismiss(animated: true) {
                    if let error = error {
                        Util.failed(self, message: error.message)
                    }
                }
            }
        }
    }

    @IBAction private func createUser(_ sender: UIButton) {
        guard let emailText = email.text, !emailText.isEmpty else {
            Util.failed(self, message: "Email is required")
            return
        }
        guard let passwordText = password.text, !passwordText.isEmpty else {
            Util.failed(self, message: "Password is required")
            return
        }

        let userData = SMPUserCreate(email: emailText, password: passwordText)
        let alert = UIAlertController(title: "Creating user...", message: nil, preferredStyle: .alert)
        present(alert, animated: true) {
            self.authProvider?.createUser(userData) { (state: SMAuthState, error: SMError?) in
                alert.dismiss(animated: true) {
                    if let error = error {
                        Util.failed(self, message: error.message)
                    }
                }
            }
        }
    }

    @IBAction private func logoutUser(_ sender: UIBarButtonItem) {
        let alert = UIAlertController(title: "Logging out...", message: nil, preferredStyle: .alert)
        present(alert, animated: true) {
            self.authProvider?.logoutUser { (state: SMAuthState, error: SMError?) in
                alert.dismiss(animated: true) {
                    if let error = error {
                        Util.failed(self, message: error.message)
                    }
                }
            }
        }
    }

    func textFieldShouldReturn(_ textField: UITextField) -> Bool {
        textField.resignFirstResponder()
        if textField.isEqual(email) {
            password.becomeFirstResponder()
        }

        return false
    }
}
