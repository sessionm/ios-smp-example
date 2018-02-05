//
//  AppDelegate.swift
//  SMPExample
//
//  Copyright © 2018 SessionM. All rights reserved.
//

import CoreLocation
import UIKit

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {
    var window: UIWindow?

    private let sessionM = SessionM.sharedInstance()

    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {
        if let options = launchOptions {
            if options.keys.contains(.location) {
                CLLocationManager().startMonitoringSignificantLocationChanges()
                SMLocationManager.registerGeofenceService()
            } else if options.keys.contains(.localNotification) {
                self.application(application, didReceive: options[UIApplicationLaunchOptionsKey.localNotification] as! UILocalNotification)
            } else if options.keys.contains(.remoteNotification) {
                self.application(application, didReceiveRemoteNotification: options[UIApplicationLaunchOptionsKey.remoteNotification] as! [AnyHashable : Any])
            }
        }

        #if DEBUG
            sessionM.isDebugMode = true
        #endif /* DEBUG */
        sessionM.logLevel = .debug
        sessionM.startWithConfigFile()

        return true
    }

    func application(_ application: UIApplication, didReceive notification: UILocalNotification) {
        if let userInfo = notification.userInfo {
            self.application(application, didReceiveRemoteNotification: userInfo)
        }
    }

    func application(_ application: UIApplication, didRegisterForRemoteNotificationsWithDeviceToken deviceToken: Data) {
        SMMessagesManager.instance().storeDeviceToken(deviceToken)
    }

    func application(_ application: UIApplication, didReceiveRemoteNotification userInfo: [AnyHashable : Any]) {
        let payload = userInfo as! [String : NSObject]
        SMMessagesManager.instance().handleRemoteNotification(payload: payload) { (success, message) in
            if success, let message = message {
                let alert = UIAlertController(title: "Received Notification", message: message.actionURL, preferredStyle: .alert)

                let executeAction = UIAlertAction(title: "Execute", style: .default) { (action) in
                    SMMessagesManager.instance().executeAction(for: message)
                }
                let dismissAction = UIAlertAction(title: "Dismiss", style: .default)

                alert.addAction(executeAction)
                alert.addAction(dismissAction)

                guard var presenting = self.window?.rootViewController else {
                    return
                }
                while presenting.presentedViewController != nil {
                    presenting = presenting.presentedViewController!
                }

                presenting.present(alert, animated: true)
            }
        }
    }

    func application(_ app: UIApplication, open url: URL, options: [UIApplicationOpenURLOptionsKey : Any] = [:]) -> Bool {
        if SMIdentityManager.instance().handleOAuthRedirectURI(url) {
            return true
        } else {
            let alert = UIAlertController(title: "Received Deep Link", message: url.absoluteString, preferredStyle: .alert)
            let dismissAction = UIAlertAction(title: "OK", style: .default)
            alert.addAction(dismissAction)

            guard var presenting = self.window?.rootViewController else {
                return false
            }
            while presenting.presentedViewController != nil {
                presenting = presenting.presentedViewController!
            }

            presenting.present(alert, animated: true)

            return true
        }
    }

    func application(_ application: UIApplication, open url: URL, sourceApplication: String?, annotation: Any) -> Bool {
        return self.application(application, open: url, options: [:])
    }
}

