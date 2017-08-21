//
//  PushViewController.swift
//  SMPExample
//
//  Copyright © 2017 SessionM. All rights reserved.
//

import UIKit

class PushViewController: UIViewController, SessionMDelegate {
    @IBOutlet private var localNotifications: UISwitch!

    private let sessionM = SessionM.sharedInstance()
    private let messagesManager = SMMessagesManager.instance()

    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)

        sessionM.delegate = self
        messagesManager.registerForRemoteNotifications()
    }

    func sessionM(_ sessionM: SessionM, didUpdateUser user: SMUser) {
        LoginViewController.loginIfNeeded(self)
    }

    func sessionM(_ sessionM: SessionM, didReceiveDeepLinkString deepLink: String) {
        let alert = UIAlertController(title: "Received Deep Link", message: deepLink, preferredStyle: .alert)
        let dismissAction = UIAlertAction(title: "OK", style: .default)
        alert.addAction(dismissAction)
        present(alert, animated: true)
    }

    private func logActionForType(_ type: SMNotificationMessageActionType) {
        if (localNotifications.isOn) {
            scheduleLocalNotificationForActionType(type)
        } else {
            switch type {
            case .deepLink:
                sessionM.logAction("push_notification_deep_link")
            case .externalLink:
                sessionM.logAction("push_notification_external_link")
            case .fullScreen:
                sessionM.logAction("push_notification_open_ad")
            default:
                break
            }
        }
    }

    private func scheduleLocalNotificationForActionType(_ type: SMNotificationMessageActionType) {
        let typeString = SMNotificationMessage.string(from: type)
        let typeStringWithSpace = typeString.replacingOccurrences(of: "_", with: " ")
        let title = "Local Notification: \(typeStringWithSpace.capitalized)"
        let body = "Test for '\(typeStringWithSpace.lowercased())' local notification."
        var actionURL = ""

        switch type {
        case .deepLink:
            actionURL = "smp://alert"
        case .externalLink:
            actionURL = "https://sessionm.com"
        case .fullScreen:
            actionURL = "https://api.tour-sessionm.com/apps/41a44470ac984b11d8452530b0cd466ba1656280/ads/101509"
        default:
            break
        }

        let actionData = [
            "action_type": typeString,
            "url": actionURL
        ]
        let userInfo = [
                        "aps": [
                            "alert": [
                                "title": title,
                                "body": body
                                ]
                            ],
                        "data": actionData
                        ] as [String : Any]

        let notification = UILocalNotification()
        notification.userInfo = userInfo
        notification.alertBody = body
        notification.fireDate = Date(timeIntervalSinceNow: 5)
        UIApplication.shared.scheduleLocalNotification(notification)
    }

    @IBAction private func logDeepLinkAction(_ sender: UIButton) {
        logActionForType(.deepLink)
    }

    @IBAction private func logExternalLinkAction(_ sender: UIButton) {
        logActionForType(.externalLink)
    }

    @IBAction private func logFullScreenAction(_ sender: UIButton) {
        logActionForType(.fullScreen)
    }

    @IBAction private func logout(_ sender: UIBarButtonItem) {
        sessionM.logOutUser()
    }
}

