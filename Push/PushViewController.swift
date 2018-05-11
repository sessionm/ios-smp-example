//
//  PushViewController.swift
//  SMPExample
//
//  Copyright © 2018 SessionM. All rights reserved.
//

import SessionMEventsKit
import SessionMMessagesKit
import UIKit

class PushViewController: UIViewController {
    @IBOutlet private var localNotifications: UISwitch!

    private let messagesManager = SMMessagesManager.instance()

    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        messagesManager.registerForRemoteNotifications()
    }

    private func logActionForType(_ type: SMNotificationMessageActionType) {
        if (localNotifications.isOn) {
            scheduleLocalNotificationForActionType(type)
        } else {
            var builder: SMSimpleEventBuilder
            switch type {
            case .deepLink:
                builder = SMSimpleEventBuilder.builder(eventName: "push_notification_deep_link")
            case .externalLink:
                builder = SMSimpleEventBuilder.builder(eventName: "push_notification_external_link")
            case .fullScreen:
                builder = SMSimpleEventBuilder.builder(eventName: "push_notification_open_ad")
            default:
                builder = SMSimpleEventBuilder.builder(eventName: "push_notification_open_ad")
            }

            SMEventsManager.instance().postEvent(builder.build()) { (response, error) in }
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
            actionURL = "https://sessionm.com"
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
        if let provider = SessionM.authenticationProvider() as? SessionMOAuthProvider {
            provider.logOutUser { (authState, error) in
                LoginViewController.loginIfNeeded(self)
            }
        }
    }
}
