//
//  WebLoginViewController.swift
//  SMPExample
//
//  Copyright © 2017 SessionM. All rights reserved.
//

import AppAuth
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

        let info = Bundle.main.infoDictionary
        if let kClientID = info?["SessionMOAuthClientID"] as? String {
            rawClientID = kClientID
            clientID.text = "Client ID: \(kClientID)"
        }
        if let kAuthEndpoint = info?["SessionMOAuthAuthorizationEndpoint"] as? String {
            rawAuthEndpoint = kAuthEndpoint
            authEndpoint.text = "Auth Endpoint: \(kAuthEndpoint)"
        }
        if let kTokenEndpoint = info?["SessionMOAuthTokenEndpoint"] as? String {
            rawTokenEndpoint = kTokenEndpoint
            tokenEndpoint.text = "Token Endpoint: \(kTokenEndpoint)"
        }
        if let kRedirectURI = info?["SessionMOAuthRedirectURI"] as? String {
            rawRedirectURI = kRedirectURI
            redirectURI.text = "Redirect URI: \(kRedirectURI)"
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
        guard let authEndpointURL = URL(string: rawAuthEndpoint!) else {
            return
        }
        guard let tokenEndpointURL = URL(string: rawTokenEndpoint!) else {
            return
        }
        guard let redirectURL = URL(string: rawRedirectURI!) else {
            return
        }
        guard let appDelegate = UIApplication.shared.delegate as? AppDelegate else {
            return
        }

        let configuration = OIDServiceConfiguration(authorizationEndpoint: authEndpointURL, tokenEndpoint: tokenEndpointURL)
        let request = OIDAuthorizationRequest(configuration: configuration, clientId: rawClientID!, scopes: [OIDScopeOpenID, OIDScopeEmail, OIDScopeProfile], redirectURL: redirectURL, responseType: OIDResponseTypeToken, additionalParameters: nil)

        appDelegate.currentAuthFlow = OIDAuthState.authState(byPresenting: request, presenting: self, callback: { (state: OIDAuthState?, error: Error?) in
            if let token = state?.lastAuthorizationResponse.accessToken {
                let alert = UIAlertController(title: "Authenticating...", message: nil, preferredStyle: .alert)
                self.present(alert, animated: true) {
                    self.identityManager.authenticate(withToken: token) { (state: SMAuthState, error: SMError?) in
                        alert.dismiss(animated: true) {
                            if let error = error {
                                Util.failed(self, message: error.message)
                            }
                        }
                    }
                }
            } else if let error = error {
                Util.failed(self, message: error.localizedDescription)
            }
        })
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
