SessionM Platform SDK Example Apps
==================================

Included in `SMPExample.xcworkspace` are example projects that show how to use the SessionM Platform SDK for iOS. Follow the steps below to setup and build a project:

1. Open `SMPExample.xcworkspace` in Xcode.
2. Navigate to the Target settings for the app you would like to build, and update the signing requirements under the "General" tab to use your Apple Developer credentials.
3. In the Toolbar, set the scheme to the desired app and click the Run button.

For more info on a specific project, see the README.md file located under that project's directory.

By default, the example apps interface with a demo environment hosted by SessionM that contains preloaded sample data. To test an app in your own environment, set your SessionM Platform API key and server URL with the `SessionMAPIKey` and `SessionMServerURL` keys in the app's `Info.plist` file:

```
<key>SessionMAPIKey</key>
<string>YOUR_API_KEY</string>
<key>SessionMServerURL</key>
<string>YOUR_SERVER_URL</string>
```

For info on more SessionM Platform features, please [email us](mailto: devsupport@sessionm.com) directly.

For SessionM Platform SDK documentation, see https://mmc.sessionm.com/docs/mmc-sdk/

LICENSE: MIT

## Authentication

This app showcases how to use the SessionM SDK to authenticate a user in the SessionM Platform.

API docs: https://mmc.sessionm.com/docs/mmc-sdk/#identity-api

On the "Choose Authentication Type" view, you can choose to authenticate a user with a SessionM Platform email and password, with a SessionM Platform authentication token, or with credentials from a third-party authentication provider such as Facebook or Google. Custom OAuth credentials can be set in the Auth/Info.plist file by using the 'SessionMOAuthClientID', 'SessionMOAuthAuthorizationEndpoint', 'SessionMOAuthTokenEndpoint' and 'SessionMOAuthRedirectURI' keys.

After selecting an authentication type, you can enter credentials to either authenticate an existing user or create a new one. After the user has been authenticated, you can see details about the user's account on the "User Info" view.

## Campaigns

This app showcases how to use the SessionM SDK to fetch promotional campaign messages for presentation in an activity feed.

API docs: https://mmc.sessionm.com/docs/mmc-sdk/#campaigns

A message tile can be clicked to showcase its associated action (e.g. presenting an ad or opening a web page in Safari).

There are three different actions to trigger different types of feed message: Open ad, deep link and external link. Click on any of the tiles gives you different actions:

- Open Ad: Opens a pre-set Ad in the app’s portal.
- Deep Link: Opens a dialog with a sample deep link schema
- External Link: Opens native browser with sample URL

## Contents

This app showcases how to use the SessionM SDK to fetch promotional content data for presentation in a content feed.

A content tile can be clicked to see metadata and start video playback (if applicable).

## Geofence

This app showcases how to use the SessionM SDK to track the user's location and monitor regions that the user enters and exits.

API Docs: https://mmc.sessionm.com/docs/mmc-sdk/#geofences

The "Map" tab contains a view of the user's immediate surroundings, and can contain three colored pin annotations:

- Green pins and their circular overlays mark geofences that are actively being monitored. Click on a pin to see the location events associated with the geofence, and whether they are triggered by entering or exiting the geofence.
- Red pins mark the user's location at the time of an "Enter" location event trigger. Click on a pin to see the coordinates and time of the trigger.
- Purple pins mark the user's location at the time of an "Exit" location event trigger. Click on a pin to see the coordinates and time of the trigger.

Note: geofence and event trigger annotations in the same location will be clustered into one pin, and clicking on that pin will list the data for each of the contained annotations in a table.

The "Triggered Events" tab contains a more detailed history of event triggers.
When running the Geofence app through Xcode, the sessionm.gpx file is used to walk a simulated path through some of the geofences in the SessionM demo environment. To use your own GPX file, navigate in Xcode to "Debug" -> "Simulate Location" -> "Add GPX File to Workspace".

## Inbox

This app showcases how to use the SessionM SDK to create UI for a user inbox.

API Docs: https://mmc.sessionm.com/docs/mmc-sdk/#inbox-api

The main view shows a list of messages in the user's inbox, with titles and creation dates for each message. Unread messages are denoted with bold text and a white background, while read messages have regular text and a gray background.

Clicking on a message will show its body and give options for marking the message as "new" or "read", as well as deleting the message.

## Loyalty Cards

This app showcases how to use the SessionM SDK to link and unlink loyalty cards to a user's account.

API Docs: https://mmc.sessionm.com/docs/mmc-sdk/#loyalty-card-linking-api

The main view shows a list of loyalty cards that have been linked to the user's account. Clicking on a card will give you the option to unlink the card from the user's account, after which the card will be removed from the list.

Clicking on the "+" symbol will give you the option to link a new card. Use the search bar to search for a retailer whose loyalty card you would like to link. After selecting the retailer, enter the card number and press the "Link" button to finish linking the card.

## Places

This app showcases how to use the SessionM SDK to allow users to earn points and promotional opportunities by checking in to sponsored venues.

API Docs: https://mmc.sessionm.com/docs/mmc-sdk/#places-api

The main view shows a list of sponsored venues available for check ins, along with how far the user is from each venue. Clicking on a venue will attempt to check the user into that venue.

## Push Notification

This app showcases how to use the SessionM SDK to present a popup message when the user receives a push notification.

API Docs: https://mmc.sessionm.com/docs/mmc-sdk/#push-notifications

Note: if you would like to simply test the relevant APIs without setting up your own SessionM Platform app and push messaging campaigns, follow the steps under "Local Notification Testing". To perform an end-to-end test of the SessionM Platform's Push Messaging feature, follow the steps under "Remote Notification Testing".

### Local Notification Testing

- Open the app and enable the "Test With Local Notifications" switch.
- Click on one of the test buttons.
- Wait for the notification popup to appear, then click on the popup to showcase its associated action (e.g. presenting an ad or opening a web page in Safari).

### Remote Notification Testing

The following steps should be completed through your Apple Developer Team website:

- Register a new bundle ID for your app.
- Create an "Apple Push Services" certificate and provisioning profile for your app.
- Create a PEM file for your app.

The following steps should be completed through the SessionM Platform portal:

- Register your app as a new Digital Property.
- Add your PEM file to the property.
- Create behaviors that will be logged in the app.
- Create push messaging campaigns that use the behaviors and contact devsupport@sessionm.com to request their approval.

The following steps should be completed in Xcode:

- Change the Push sample app's bundle ID to match your app's bundle ID.
- Update the Push sample app's signing requirements to use your Apple Developer credentials.
- Ensure the Push Notifications entitlement is added to the Push.entitlements file.
- Edit the SessionMAPIKey and SessionMServerURL key values in Info.plist to match the API key given to your property and your environment's server URL.
- Edit the names of the behaviors that are logged in the logActionForType method in PushViewController.swift to match your behavior names.
- Open the app and disable the "Test With Local Notifications" switch.
- Click on one of the test buttons.
- Wait for the notification popup to appear, then click on the popup to showcase its associated action (e.g. presenting an ad or opening a web page in Safari).

## Receipts

This app showcases how to use the SessionM SDK to allow users to upload receipt images.

API Docs: https://mmc.sessionm.com/docs/mmc-sdk/#receipts-api

The main view shows a list of receipts that have already been uploaded by the user. Clicking on a receipt tile will show the images that were included in that upload.

Clicking on the "+" symbol will give you the option to upload images for a new receipt. Follow the onscreen instructions to take a new photo or upload an existing image from your photo library.

## Referrals

This app showcases how to use the SessionM SDK to allow users to send an email to refer other potential users to sign up for an account.

API Docs: https://mmc.sessionm.com/docs/mmc-sdk/#referrals-api

The main view shows a list of referrals that have already been sent by the user. Clicking on a referral tile will show more details about the referral.

Clicking on the "+" symbol will give you the option to send a new referral. Fill out the presented form (note: only email is required) and click "Submit" to finish sending the referral.

## Rewards

This app showcases how to use the SessionM SDK to allow users to spend loyalty points to purchase rewards.

API Docs: https://mmc.sessionm.com/docs/mmc-sdk/#rewards-api

The "Offers" tab shows a list of offers that are available for purchase. Click on an offer to see more details and make a purchase. If the offer is gated by a skills test (e.g. for a sweepstakes entry), then an alert will appear with a random question. Enter the correct answer to complete the purchase.
The "Orders" tab shows a list of the user's order transactions and their approval statuses (e.g. "pending", "approved", "rejected").

## Transactions

This app showcases how to use the SessionM SDK to view a user's loyalty points transaction history.

API Docs: https://mmc.sessionm.com/docs/mmc-sdk/#transactions-api

The main view shows a list of loyalty points transactions made by the user, and the resulting points balance after each transaction. "Receipt" and "Loyalty Card" transaction tiles can be clicked on to present an alert with more details on the transaction.

