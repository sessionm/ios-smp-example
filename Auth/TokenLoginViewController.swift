//
//  TokenLoginViewController.swift
//  SMPExample
//
//  Copyright © 2018 SessionM. All rights reserved.
//

import SessionMIdentityKit
import UIKit

class TokenLoginViewController: UIViewController, UITextFieldDelegate {
    @IBOutlet var token: UITextField!
    @IBOutlet var provider: UITextField!
    @IBOutlet var logout: UIBarButtonItem!
    @IBOutlet var status: UILabel!
    @IBOutlet var userInfo: UIButton!

    private let authProvider = SessionM.authenticationProvider() as? SessionMOauthProvider
    private let userManager = SMUserManager.instance()

    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)

        if let user = userManager.currentUser {
            logout.isEnabled = true
            userInfo.isEnabled = true
            let email = (user.email != nil) ? user.email! : "Anonymous User"
            status.text? = "Email: \(email)\nID: \(user.userID)"
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
            let email = (user.email != nil) ? user.email! : "Anonymous User"
            status.text? = "Email: \(email)\nID: \(user.userID)"
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
            self.authProvider?.authenticate(withToken: tokenText, provider: providerText) { (state: SMAuthState, error: SMError?) in
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
            self.authProvider?.authenticate(withToken: "eyJ0eXAiOiJKV1QiLCJhbGciOiJSUzI1NiJ9.eyJpYXQiOiIyMDE3LTA5LTI3IDE1OjMwOjU1ICswMDAwIiwiZXhwIjoiMjAxNy0xMC0xMSAxNTozMDo1NSArMDAwMCIsImRhdGEiOnsiaWQiOiJkYTYxZGNkYS1hMzk4LTExZTctODcxZi05ZjZkNTQzYmUwNDAifX0.iBrHv9-INszE-SSL9rsuNnLDv7DBBaIUuqM6XDUvecxzap2CuoN4v3juXPvw-dZWuzbiHY2H3TPJJlRcI5_fZPxH2FjDqGA1S5nwEwEYVn9D1oMvnXUB6jLIq3ev4omE7ZUj5zVytsn_rKdryllfHro_8g5TneiOUoFBa_1N_RcC9AK_8640xbYPtZaNWhxsJiCwTsKWaLSYQ6RQv_xo1M4reL56dbjJ16Y-50HUy6Pxax6biKVvpjNRDizrkY0bka07lHMLAHMZD5-D3OYnxpxyg9aVX2kJd36iZuwsKaXVMtrCzwmzzGuhQD1PUUhC43wkNUbYw9z2d94v0FDxvQ", provider: "") { (state: SMAuthState, error: SMError?) in
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
        if textField.isEqual(token) {
            provider.becomeFirstResponder()
        }
        
        return false
    }
}
