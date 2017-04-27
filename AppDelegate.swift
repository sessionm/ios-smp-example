//
//  AppDelegate.swift
//  SMPExample
//
//  Copyright © 2017 SessionM. All rights reserved.
//

import AppAuth
import CoreLocation
import UIKit

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {
    var window: UIWindow?
    var currentAuthFlow: OIDAuthorizationFlowSession?

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

        let appID = Bundle.main.infoDictionary?["SessionMAPIKey"] as! String
        let serverURL = Bundle.main.infoDictionary?["SessionMServerURL"] as! String
        SessionM.setCustomServiceRegionWithServerURL(serverURL)
        sessionM.logLevel = .debug
        sessionM.startSession(appID: appID)
        
        return true
    }

    func application(_ application: UIApplication, didReceive notification: UILocalNotification) {
        if let userInfo = notification.userInfo {
            self.application(application, didReceiveRemoteNotification: userInfo)
        }
    }

    func application(_ application: UIApplication, didRegisterForRemoteNotificationsWithDeviceToken deviceToken: Data) {
        sessionM.storeDeviceToken(deviceToken)
    }

    func application(_ application: UIApplication, didReceiveRemoteNotification userInfo: [AnyHashable : Any]) {
        let payload = userInfo as! [String : NSObject]
        sessionM.handleRemoteNotification(payload: payload)
    }

    func application(_ app: UIApplication, open url: URL, options: [UIApplicationOpenURLOptionsKey : Any] = [:]) -> Bool {
        if let flow = currentAuthFlow, flow.resumeAuthorizationFlow(with: url) {
            currentAuthFlow = nil
            return true
        }

        return false
    }

    func application(_ application: UIApplication, open url: URL, sourceApplication: String?, annotation: Any) -> Bool {
        return self.application(application, open: url, options: [:])
    }
}

