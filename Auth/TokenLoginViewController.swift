//
//  TokenLoginViewController.swift
//  SMPExample
//
//  Copyright © 2017 SessionM. All rights reserved.
//

import UIKit

class TokenLoginViewController: UIViewController, UITextFieldDelegate {
    @IBOutlet var token: UITextField!
    @IBOutlet var provider: UITextField!
    @IBOutlet var logout: UIBarButtonItem!
    @IBOutlet var status: UILabel!
    @IBOutlet var userInfo: UIButton!

    private let identityManager = SMIdentityManager.instance()
    private let userManager = SMUserManager.instance()

    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)

        if let user = userManager.currentUser {
            logout.isEnabled = true
            userInfo.isEnabled = true
            status.text? = "Email: \(user.email!)\nID: \(user.userID)"
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
            logout.isEnabled = true
            userInfo.isEnabled = true
            status.text? = "Email: \(user.email!)\nID: \(user.userID)"
        } else {
            logout.isEnabled = false
            userInfo.isEnabled = false
            status.text? = "Logged Out"
        }
    }


    @IBAction private func authenticate(_ sender: UIButton) {
        guard let tokenText = token.text, !tokenText.isEmpty else {
            Util.failed(self, message: "Token is required")
            return
        }

        var providerText: String
        if let text = provider.text, !text.isEmpty {
            providerText = text
        } else {
            providerText = "sessionm_oauth"
        }

        let alert = UIAlertController(title: "Authenticating...", message: nil, preferredStyle: .alert)
        present(alert, animated: true) {
            self.identityManager.authenticate(withToken: tokenText, provider: providerText) { (state: SMAuthState, error: SMError?) in
                alert.dismiss(animated: true) {
                    if let error = error {
                        Util.failed(self, message: error.message)
                    }
                }
            }
        }
    }

    @IBAction private func authenticateWithSampleUser(_ sender: UIButton) {
        let alert = UIAlertController(title: "Authenticating...", message: nil, preferredStyle: .alert)
        present(alert, animated: true) {
            self.identityManager.authenticate(withToken: "v2--Sd2T8UBqlCGQovVPnsUs4eqwFe0-1i9JV4nq__RWmsA=--dWM8r8RggUJCToOaiiT6NXmiOipkovvD9HueM_jZECStExtGFkZzVmCUhkdDJe5NQw==") { (state: SMAuthState, error: SMError?) in
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
            self.identityManager.logOutUser() { (state: SMAuthState, error: SMError?) in
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
        if textField.isEqual(token) {
            provider.becomeFirstResponder()
        }
        
        return false
    }
}
