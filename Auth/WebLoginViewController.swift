//
//  WebLoginViewController.swift
//  SMPExample
//
//  Copyright © 2017 SessionM. All rights reserved.
//

import UIKit

class WebLoginViewController: UIViewController {
    @IBOutlet var clientID: UILabel!
    @IBOutlet var authEndpoint: UILabel!
    @IBOutlet var tokenEndpoint: UILabel!
    @IBOutlet var redirectURI: UILabel!
    @IBOutlet var logout: UIBarButtonItem!
    @IBOutlet var status: UILabel!
    @IBOutlet var userInfo: UIButton!

    private var rawClientID: String?
    private var rawAuthEndpoint: String?
    private var rawTokenEndpoint: String?
    private var rawRedirectURI: String?

    private let identityManager = SMIdentityManager.instance()
    private let userManager = SMUserManager.instance()

    override func viewDidLoad() {
        super.viewDidLoad()

        guard let configFile = Bundle.main.path(forResource: "SMPConfig", ofType: "plist") else {
            return
        }

        let info = NSDictionary(contentsOfFile: configFile)
        if let kClientID = info?["OAuthClientID"] as? String {
            rawClientID = kClientID
            clientID.text = "Client ID: \(kClientID)"
        }
        if let kRedirectURI = info?["OAuthRedirectURI"] as? String {
            rawRedirectURI = kRedirectURI
            redirectURI.text = "Redirect URI: \(kRedirectURI)"
        }
        if let kOAuthHostURL = info?["OAuthHostURL"] as? String {
            let kAuthEndpoint = kOAuthHostURL.appending("/authorize")
            rawAuthEndpoint = kAuthEndpoint
            authEndpoint.text = "Auth Endpoint: \(kAuthEndpoint)"

            let kTokenEndpoint = kOAuthHostURL.appending("/token")
            rawTokenEndpoint = kTokenEndpoint
            tokenEndpoint.text = "Token Endpoint: \(kTokenEndpoint)"
        }
    }

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

    @IBAction func openWebAuthentication(_ sender: UIButton) {
        identityManager.startWebAuthorization(in: self) { (state: SMAuthState, error: SMError?) in
            if let error = error {
                Util.failed(self, message: error.message)
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
}
