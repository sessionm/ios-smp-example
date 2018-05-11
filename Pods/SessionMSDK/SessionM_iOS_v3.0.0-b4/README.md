SessionM Platform iOS SDK
=========
Copyright © 2018 SessionM. All rights reserved.


CocoaPods Linking Instructions
==========

Follow the steps below to link the framework to your application target using CocoaPods:

1. Add the "use_frameworks!" attribute and "pod 'SessionMSDK'" dependency to your Podfile. 'SessionMSDK/Core' and other subspecs can be used for finer dependency management (additional subspecs can be found in the SessionMSDK Specs repository at https://github.com/CocoaPods/Specs/tree/master/Specs/d/f/8/SessionMSDK).
2. Make sure the Podfile's "platform" attribute is set to at least "9.0".
3. Run "pod install".
