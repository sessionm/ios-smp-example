//
//  LoginViewController.swift
//  SMPExample
//
//  Copyright © 2017 SessionM. All rights reserved.
//

import UIKit

class LoginViewController: UIViewController, UITextFieldDelegate, SessionMDelegate {
    private let sessionM = SessionM.sharedInstance()

    private let testToken = "test"
    private let testEmail = "unitTestLogin@sessionm.com"
    private let testPassword = "sessionm"

    private var emailRegex: NSRegularExpression!

    @IBOutlet private var pleaseLogIn: UILabel!
    @IBOutlet private var registered: UILabel!
    @IBOutlet private var signedIn: UILabel!
    @IBOutlet private var sessionState: UILabel!

    @IBOutlet private var email: UITextField!
    @IBOutlet private var password: UITextField!
    @IBOutlet private var token: UITextField!

    @IBOutlet private var loginButton: UIButton!
    @IBOutlet private var authenticateButton: UIButton!

    static func login(_ parent: UIViewController) {
        let login = LoginViewController(nibName: "Login", bundle: nil)
        parent.present(login, animated: true)
    }

    static func loginIfNeeded(_ parent: UIViewController) {
        if !SessionM.sharedInstance().user.isRegistered {
            LoginViewController.login(parent)
        }
    }


    override func viewDidLoad() {
        super.viewDidLoad()

        sessionM.delegate = self

        if let e = email, let p = password, let t = token {
            e.delegate = self
            p.delegate = self
            t.delegate = self
        }

        emailRegex = try! NSRegularExpression(pattern: "[a-zA-Z0-9+._%-]{1,256}[@][a-zA-Z0-9][a-zA-Z0-9-]{0,64}([.][a-zA-Z0-9][a-zA-Z0-9-]{0,25})+", options: .caseInsensitive)
    }

    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)

        sessionM.delegate = self

        if let label = sessionState {
            switch (sessionM.sessionState) {
            case .startedOffline:
                label.text = "Offline"
            case .startedOnline:
                label.text = "Online"
            case .stopped:
                label.text = "Stopped"
            }
        }

        if let reg = registered, let sign = signedIn {
            reg.text = sessionM.user.isRegistered ? "Yes" : "No"
            sign.text = sessionM.user.isLoggedIn ? "Yes" : "No"
        }
    }

    @IBAction private func loginUser(_ sender: UIButton) {
        if let email = email.text, let password = password.text {
            sessionM.logInUser(withEmail: email, password: password)
        }
    }

    @IBAction private func authenticateUser(_ sender: UIButton) {
        if let token = token.text {
            sessionM.authenticate(withToken: token, provider: "api_auth_token")
        }
    }

    @IBAction private func loginSampleUser(_ sender: UIButton) {
        sessionM.logInUser(withEmail: testEmail, password: testPassword)
    }

    @IBAction private func authenticateSampleUser(_ sender: UIButton) {
        sessionM.authenticate(withToken: testToken, provider: "api_auth_token")
    }

    func sessionM(_ sessionM: SessionM, didTransitionToState state: SessionMState) {
        if let label = sessionState {
            switch (state) {
            case .startedOffline:
                label.text = "Offline"
            case .startedOnline:
                label.text = "Online"
            case .stopped:
                label.text = "Stopped"
            }
        }
    }

    func sessionM(_ sessionM: SessionM, didUpdateUser user: SMUser) {
        if let reg = registered, let sign = signedIn {
            reg.text = user.isRegistered ? "Yes" : "No"
            sign.text = user.isLoggedIn ? "Yes" : "No"

            if (sessionM.sessionState == .startedOnline) && (user.isRegistered) {
                dismiss(animated: true)
            }
        }
    }

    func textField(_ textField: UITextField, shouldChangeCharactersIn range: NSRange, replacementString string: String) -> Bool {
        if let text = textField.text, let login = loginButton, let authenticate = authenticateButton {
            let nstext = text as NSString
            let result = nstext.replacingCharacters(in: NSRangeFromString(nstext as String), with: string)
            if (textField == self.email) {
                login.isEnabled = emailRegex.matches(in: result, options: [], range: NSRangeFromString(result)).count > 0
            } else if (textField == token) {
                authenticate.isEnabled = result.characters.count > 0
            } else if (textField == password) {
                login.isEnabled = result.characters.count > 0
            }
        }
        return true
    }
}
