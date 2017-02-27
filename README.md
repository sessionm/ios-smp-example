SessionM Platform SDK Example Apps
==================================

Included in `SMPExample.xcworkspace` are example projects that show how to use the SessionM Platform SDK for iOS. Follow the steps below to setup and build a project:

1. Run `gem install cocoapods` to install Cocoapods.
2. Run `pod setup` to create your `~/.cocoapods/repos` directory.
3. Run `pod install` to install the required pods for the example apps.
4. Open `SMPExample.xcworkspace` in Xcode.
5. Navigate to the Target settings for the app you would like to build, and update the signing requirements under the "General" tab to use your Apple Developer credentials.
6. In the Toolbar, set the scheme to the desired app and click the Run button.

For more info on a specific project, see the README.md file located under that project's directory.

By default, the example apps interface with a demo environment hosted by SessionM that contains preloaded sample data. To test the apps in your own environment, set your SessionM Platform API key and server URL in `AppDelegate.swift`:

```
private let APP_ID = "<YOUR_API_KEY>"
private let SERVER_URL = "<YOUR_SERVER_URL>"
```

For info on more SessionM Platform features, please [email us](mailto: devsupport@sessionm.com) directly.

For SessionM Platform SDK documentation, see https://mmc.sessionm.com/docs/mmc-sdk/


LICENSE: MIT
