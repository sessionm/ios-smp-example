Push
====

This app showcases how to use the APIs defined by the `SessionM` class to present a popup message when the user receives a push notification.

***
Note: if you would like to simply test the relevant APIs without setting up your own SessionM Platform app and push messaging campaigns, follow the steps under "Local Notification Testing". To perform an end-to-end test of the SessionM Platform's Push Messaging feature, follow the steps under "Remote Notification Testing".
***

Local Notification Testing
---

1. Open the app and enable the "Test With Local Notifications" switch.
2. Click on one of the test buttons.
3. Wait for the notification popup to appear, then click on the popup to showcase its associated action (e.g. presenting an ad or opening a web page in Safari).

Remote Notification Testing
---

The following steps should be completed through your Apple Developer Team website:

1. Register a new bundle ID for your app.
2. Create an "Apple Push Services" certificate and provisioning profile for your app.
3. Create a PEM file for your app.


The following steps should be completed through the SessionM Platform portal:

1. Register your app as a new Digital Property.
2. Add your PEM file to the property.
3. Create behaviors that will be logged in the app.
4. Create push messaging campaigns that use the behaviors and contact devsupport@sessionm.com to request their approval.


The following steps should be completed in Xcode:

1. Change the Push sample app's bundle ID to match your app's bundle ID.
2. Update the Push sample app's signing requirements to use your Apple Developer credentials.
3. Ensure the Push Notifications entitlement is added to the `Push.entitlements` file.
4. Edit the `APP_ID` and `SERVER_URL` constants in `AppDelegate.swift` to match the API key given to your property and your environment's server URL.
5. Edit the names of the behaviors that are logged in the `logActionForType` method in `PushViewController.swift` to match your behavior names.
6. Open the app and disable the "Test With Local Notifications" switch.
7. Click on one of the test buttons.
8. Wait for the notification popup to appear, then click on the popup to showcase its associated action (e.g. presenting an ad or opening a web page in Safari).


LICENSE: MIT
