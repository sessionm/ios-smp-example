//
//  AppDelegate.swift
//  ios-swift-smp-sample
//
//  Copyright © 2017 SessionM. All rights reserved.
//

import CoreLocation
import UIKit

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {
    var window: UIWindow?

    private let APP_ID = "41a44470ac984b11d8452530b0cd466ba1656280"
    private let SERVER_URL = "https://api.tour-sessionm.com"
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

        if (APP_ID.characters.count <= 0) {
            print("Enter the APP_ID before calling SMStart()")
            return false
        }

        if (SERVER_URL.characters.count <= 0) {
            print("Enter the SERVER_URL before calling SMStart()")
            return false
        }

        SessionM.setCustomServiceRegionWithServerURL(SERVER_URL)
        sessionM.logLevel = .debug
        sessionM.startSession(appID: APP_ID)
        
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
}

