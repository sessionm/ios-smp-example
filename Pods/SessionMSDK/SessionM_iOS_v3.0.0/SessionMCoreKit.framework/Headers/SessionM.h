//
//  SessionM.h
//  SessionMCoreKit
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SESSIONM__
#define __SESSIONM__

#import <Foundation/Foundation.h>

#import "SMAuthenticationProvider.h"
#import "SMLogger.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @const __SESSIONM_SDK_VERSION__
 @abstract The current SDK version.
 */
extern NSString * const __SESSIONM_SDK_VERSION__;
/*!
 @const __SESSIONM_SDK_MIN_SUPPORTED_DEVICE_VERSION__
 @abstract The minimum iOS version supported by the SDK.
 */
extern double const __SESSIONM_SDK_MIN_SUPPORTED_DEVICE_VERSION__;

/*!
 @typedef SMReadyReasonCodes
 @abstract Bitmask of error codes indicating whether the SDK is ready to initialize a user session.

 @constant SMReadyReasonCodeNone No error - SDK is ready.
 @constant SMReadyReasonCodeNoConfig App configuration is not loaded.
 @constant SMReadyReasonCodeNoAuthenticationProvider Authentication provider is not set.
 @constant SMReadyReasonCodeNotAuthenticated User is not authenticated.
 */
typedef NS_OPTIONS(NSUInteger, SMReadyReasonCodes) {
    SMReadyReasonCodeNone NS_SWIFT_NAME(none)                                         = 0x00,
    SMReadyReasonCodeNoConfig NS_SWIFT_NAME(noConfig)                                 = 0x01,
    SMReadyReasonCodeNoAuthenticationProvider NS_SWIFT_NAME(noAuthenticationProvider) = 0x02,
    SMReadyReasonCodeNotAuthenticated NS_SWIFT_NAME(notAuthenticated)                 = 0x04
};

/*!
 @typedef SMPServerType
 @abstract SessionM Platform server type (see <code>startWithConfigFileServerType:completionHandler:</code> and its variants for more info).

 @constant SMPServerTypeProduction Production server environment (used for applications ready for release).
 @constant SMPServerTypeStaging Staging server environment (used for applications in development).
 @constant SMPServerTypeDevelopment Development server environment (used for applications in development).
 */
typedef NS_ENUM(NSInteger, SMPServerType) {
    SMPServerTypeProduction NS_SWIFT_NAME(production),
    SMPServerTypeStaging NS_SWIFT_NAME(staging),
    SMPServerTypeDevelopment NS_SWIFT_NAME(development)
};


/*!
 @typedef SetAuthenticationProviderHandler
 @abstract Completion handler block type for <code>setAuthenticationProvider:completionHandler:</code>.
 */
typedef void(^SetAuthenticationProviderHandler)(SMError * _Nullable error);
/*!
 @typdef SMPStartupHandler
 @abstract Completion handler block type for <code>startWithCompletionHandler:</code> and its variants.
 */
typedef void(^SMPStartupHandler)(SMError * _Nullable error);
/*!
 @typdef SMPShutdownHandler
 @abstract Completion handler block type for <code>stopWithCompletionHandler:</code>.
 */
typedef void(^SMPShutdownHandler)(SMError * _Nullable error);


/*!
 @class SessionM
 @abstract SessionM service interface.
*/
@interface SessionM : NSObject

/*!
 @abstract Set the enabled log level.
 @param logLevel New log level.
 */
+ (void)setLogLevel:(SMLogLevel)logLevel;
/*!
 @abstract Set the enabled log categories.
 @param categories Bitmask of new log categories.
 */
+ (void)setLogCategories:(SMLogCategory)categories;
/*!
 @abstract The name of the plug-in SDK.
 @result The name of the plug-in SDK.
 */
+ (NSString * _Nullable)pluginSDK;
/*!
 @abstract The version number of the plug-in SDK being used.
 @result The version number of the plug-in SDK being used.
 */
+ (NSString * _Nullable)pluginSDKVersion;
/*!
 @abstract Sets the SessionM plug-in SDK name and version number.
 @discussion This method should be called from the plug-in SDK before a session is started.
 @param name The plug-in SDK name
 @param version The plug-in SDK version number
 */
+ (void)setPluginSDK:(NSString * _Nullable)name version:(NSString * _Nullable)version NS_SWIFT_NAME(setPluginSDKName(_:version:));
/*!
 @abstract Determines the default locale to use when making API calls.
 @result Determines the default locale to use when making API calls.
 */
+ (NSLocale * _Nullable)customLocale;
/*!
 @abstract Sets the default locale to use when making API calls (<code>NSLocale currentLocale</code> will be used as the default locale when <code>nil</code> is passed in).
 @param customLocale New locale value.
 */
+ (void)setCustomLocale:(NSLocale * _Nullable)customLocale NS_SWIFT_NAME(setCustomLocale(_:));
/*!
 @abstract Indicates whether the SDK will request the user's advertising identifier when starting a session (default value is <code>YES</code>).
 @result Indicates whether the SDK will request the user's advertising identifier when starting a session (default value is <code>YES</code>).
 */
+ (BOOL)shouldCollectIDFA;
/*!
 @abstract Sets whether the SDK will request the user's advertising identifier when starting a session.
 @param shouldCollectIDFA New value for <code>shouldCollectIDFA</code>.
 */
+ (void)setShouldCollectIDFA:(BOOL)shouldCollectIDFA;

/*!
 @abstract The OAuth identity provider that will be used to handle authentication requests.
 @result The OAuth identity provider that will be used to handle authentication requests.
 */
+ (nullable id<SMAuthenticationProvider>)authenticationProvider;
/*!
 @abstract Sets the OAuth identity provider that will be used to handle authentication requests (if SessionMIdentityKit is linked, then an instance of <code>SessionMOAuthProvider</code> will be used as the default provider when <code>nil</code> is passed in).
 @param authenticationProvider New authentication provider value.
 @param completionHandler Block to execute after setting the authentication provider.
 */
+ (void)setAuthenticationProvider:(nullable id<SMAuthenticationProvider>)authenticationProvider completionHandler:(nullable SetAuthenticationProviderHandler)completionHandler NS_SWIFT_NAME(setAuthenticationProvider(_:completionHandler:));

/*!
 @abstract Initializes a user session with parameters from the app's SessionM Platform configuration file.
 @discussion In order to use this method, you must download the configuration file for your app from the SessionM Platform portal, and then drag the file into Xcode to copy it to your app.
 Use this method if you would like to use "SMPConfig.plist" as your configuration file name.
 This method should be called as early as possible in the application lifecycle, typically in <code>application:didFinishLaunchingWithOptions:</code> method of <code>UIApplicationDelegate</code>.
 @param completionHandler Block to execute after initializing the user session.
 */
+ (void)startWithCompletionHandler:(nullable SMPStartupHandler)completionHandler NS_SWIFT_NAME(start(completionHandler:));
/*!
 @abstract Initializes a user session with parameters from the app's SessionM Platform configuration file.
 @discussion In order to use this method, you must download the configuration file for your app from the SessionM Platform portal, and then drag the file into Xcode to copy it to your app.
 Use this method if you would like to use "SMPConfig.plist" as your configuration file name.
 This method should be called as early as possible in the application lifecycle, typically in <code>application:didFinishLaunchingWithOptions:</code> method of <code>UIApplicationDelegate</code>.
 @param provider The OAuth identity provider that will be used to handle authentication requests.
 @param completionHandler Block to execute after initializing the user session.
 */
+ (void)startWithAuthenticationProvider:(nullable id<SMAuthenticationProvider>)provider completionHandler:(nullable SMPStartupHandler)completionHandler NS_SWIFT_NAME(start(authenticationProvider:completionHandler:));
/*!
 @abstract Initializes a user session with parameters from the app's SessionM Platform configuration file in the resource bundle with the specified identifier.
 @discussion In order to use this method, you must download the configuration file for your app from the SessionM Platform portal, and then drag the file into Xcode to copy it to your app.
 Use this method if you would like to use "SMPConfig.plist" as your configuration file name.
 This method should be called as early as possible in the application lifecycle, typically in <code>application:didFinishLaunchingWithOptions:</code> method of <code>UIApplicationDelegate</code>.
 @param bundleID The identifier for the resource bundle in which the SDK will look for the configuration file.
 @param completionHandler Block to execute after initializing the user session.
 */
+ (void)startWithConfigFileInBundleWithIdentifier:(NSString *)bundleID completionHandler:(nullable SMPStartupHandler)completionHandler NS_SWIFT_NAME(start(configFileBundleID:completionHandler:));
/*!
 @abstract Initializes a user session with parameters from the app's SessionM Platform configuration file in the resource bundle with the specified identifier.
 @discussion In order to use this method, you must download the configuration file for your app from the SessionM Platform portal, and then drag the file into Xcode to copy it to your app.
 Use this method if you would like to use "SMPConfig.plist" as your configuration file name.
 This method should be called as early as possible in the application lifecycle, typically in <code>application:didFinishLaunchingWithOptions:</code> method of <code>UIApplicationDelegate</code>.
 @param bundleID The identifier for the resource bundle in which the SDK will look for the configuration file.
 @param provider The OAuth identity provider that will be used to handle authentication requests.
 @param completionHandler Block to execute after initializing the user session.
 */
+ (void)startWithConfigFileInBundleWithIdentifier:(NSString *)bundleID authProvider:(nullable id<SMAuthenticationProvider>)provider completionHandler:(nullable SMPStartupHandler)completionHandler NS_SWIFT_NAME(start(configFileBundleID:authenticationProvider:completionHandler:));
/*!
 @abstract Initializes a user session with parameters from the app's SessionM Platform configuration file having the specified server type in its name (e.g. "SMPConfig-production.plist").
 @discussion In order to use this method, you must download the configuration file for your app from the SessionM Platform portal, and then drag the file into Xcode to copy it to your app.
 Use this method if you have multiple configuration files corresponding to your development environments.
 This method should be called as early as possible in the application lifecycle, typically in <code>application:didFinishLaunchingWithOptions:</code> method of <code>UIApplicationDelegate</code>.
 @param type The server type to be used as a suffix in the configuration file name (e.g. passing in <code>SMPServerTypeStaging</code> will cause this method to use the "SMPConfig-staging.plist" configuration file).
 @param completionHandler Block to execute after initializing the user session.
 */
+ (void)startWithConfigFileServerType:(SMPServerType)type completionHandler:(nullable SMPStartupHandler)completionHandler NS_SWIFT_NAME(start(configFileServerType:completionHandler:));
/*!
 @abstract Initializes a user session with parameters from the app's SessionM Platform configuration file having the specified server type in its name (e.g. "SMPConfig-production.plist").
 @discussion In order to use this method, you must download the configuration file for your app from the SessionM Platform portal, and then drag the file into Xcode to copy it to your app.
 Use this method if you have multiple configuration files corresponding to your development environments.
 This method should be called as early as possible in the application lifecycle, typically in <code>application:didFinishLaunchingWithOptions:</code> method of <code>UIApplicationDelegate</code>.
 @param type The server type to be used as a suffix in the configuration file name (e.g. passing in <code>SMPServerTypeStaging</code> will cause this method to use the "SMPConfig-staging.plist" configuration file).
 @param provider The OAuth identity provider that will be used to handle authentication requests.
 @param completionHandler Block to execute after initializing the user session.
 */
+ (void)startWithConfigFileServerType:(SMPServerType)type authProvider:(nullable id<SMAuthenticationProvider>)provider completionHandler:(nullable SMPStartupHandler)completionHandler NS_SWIFT_NAME(start(configFileServerType:authenticationProvider:completionHandler:));
/*!
 @abstract Initializes a user session with parameters from the SessionM Platform configuration file having the specified server type in its name (e.g. "SMPConfig-production.plist") in the resource bundle with the specified identifier.
 @discussion In order to use this method, you must download the configuration file for your app from the SessionM Platform portal, and then drag the file into Xcode to copy it to your app.
 Use this method if you have multiple configuration files corresponding to your development environments.
 This method should be called as early as possible in the application lifecycle, typically in <code>application:didFinishLaunchingWithOptions:</code> method of <code>UIApplicationDelegate</code>.
 @param type The server type to be used as a suffix in the configuration file name (e.g. passing in <code>SMPServerTypeStaging</code> will cause this method to use the "SMPConfig-staging.plist" configuration file).
 @param bundleID The identifier for the resource bundle in which the SDK will look for the configuration file.
 @param completionHandler Block to execute after initializing the user session.
 */
+ (void)startWithConfigFileServerType:(SMPServerType)type bundleIdentifier:(NSString *)bundleID completionHandler:(nullable SMPStartupHandler)completionHandler NS_SWIFT_NAME(start(configFileServerType:bundleIdentifier:completionHandler:));
/*!
 @abstract Initializes a user session with parameters from the SessionM Platform configuration file having the specified server type in its name (e.g. "SMPConfig-production.plist") in the resource bundle with the specified identifier.
 @discussion In order to use this method, you must download the configuration file for your app from the SessionM Platform portal, and then drag the file into Xcode to copy it to your app.
 Use this method if you have multiple configuration files corresponding to your development environments.
 This method should be called as early as possible in the application lifecycle, typically in <code>application:didFinishLaunchingWithOptions:</code> method of <code>UIApplicationDelegate</code>.
 @param type The server type to be used as a suffix in the configuration file name (e.g. passing in <code>SMPServerTypeStaging</code> will cause this method to use the "SMPConfig-staging.plist" configuration file).
 @param bundleID The identifier for the resource bundle in which the SDK will look for the configuration file.
 @param provider The OAuth identity provider that will be used to handle authentication requests.
 @param completionHandler Block to execute after initializing the user session.
 */
+ (void)startWithConfigFileServerType:(SMPServerType)type bundleIdentifier:(NSString *)bundleID authProvider:(nullable id<SMAuthenticationProvider>)provider completionHandler:(nullable SMPStartupHandler)completionHandler NS_SWIFT_NAME(start(configFileServerType:bundleIdentifier:authenticationProvider:completionHandler:));
/*!
 @abstract Initializes a user session with parameters from the app's SessionM Platform configuration file having the specified name.
 @discussion In order to use this method, you must download the configuration file for your app from the SessionM Platform portal, and then drag the file into Xcode to copy it to your app.
 Use this method if you would like to use a custom name for your configuration file.
 This method should be called as early as possible in the application lifecycle, typically in <code>application:didFinishLaunchingWithOptions:</code> method of <code>UIApplicationDelegate</code>.
 @param name Configuration file name (note: passing in the ".plist" file extension is not required).
 @param completionHandler Block to execute after initializing the user session.
 */
+ (void)startWithConfigFileName:(NSString *)name completionHandler:(nullable SMPStartupHandler)completionHandler NS_SWIFT_NAME(start(configFileName:completionHandler:));
/*!
 @abstract Initializes a user session with parameters from the app's SessionM Platform configuration file having the specified name.
 @discussion In order to use this method, you must download the configuration file for your app from the SessionM Platform portal, and then drag the file into Xcode to copy it to your app.
 Use this method if you would like to use a custom name for your configuration file.
 This method should be called as early as possible in the application lifecycle, typically in <code>application:didFinishLaunchingWithOptions:</code> method of <code>UIApplicationDelegate</code>.
 @param name Configuration file name (note: passing in the ".plist" file extension is not required).
 @param provider The OAuth identity provider that will be used to handle authentication requests.
 @param completionHandler Block to execute after initializing the user session.
 */
+ (void)startWithConfigFileName:(NSString *)name authProvider:(nullable id<SMAuthenticationProvider>)provider completionHandler:(nullable SMPStartupHandler)completionHandler NS_SWIFT_NAME(start(configFileName:authenticationProvider:completionHandler:));
/*!
 @abstract Initializes a user session with parameters from the SessionM Platform configuration file having the specified name in the bundle with the specified identifier.
 @discussion In order to use this method, you must download the configuration file for your app from the SessionM Platform portal, and then drag the file into Xcode to copy it to your app.
 Use this method if you would like to use a custom name for your configuration file.
 This method should be called as early as possible in the application lifecycle, typically in <code>application:didFinishLaunchingWithOptions:</code> method of <code>UIApplicationDelegate</code>.
 @param name Configuration file name (note: passing in the ".plist" file extension is not required).
 @param bundleID The identifier for the resource bundle in which the SDK will look for the configuration file.
 @param completionHandler Block to execute after initializing the user session.
 */
+ (void)startWithConfigFileName:(NSString *)name bundleIdentifier:(NSString *)bundleID completionHandler:(nullable SMPStartupHandler)completionHandler NS_SWIFT_NAME(start(configFileName:bundleIdentifier:completionHandler:));
/*!
 @abstract Initializes a user session with parameters from the SessionM Platform configuration file having the specified name in the resource bundle with the specified identifier.
 @discussion In order to use this method, you must download the configuration file for your app from the SessionM Platform portal, and then drag the file into Xcode to copy it to your app.
 Use this method if you would like to use a custom name for your configuration file.
 This method should be called as early as possible in the application lifecycle, typically in <code>application:didFinishLaunchingWithOptions:</code> method of <code>UIApplicationDelegate</code>.
 @param name Configuration file name (note: passing in the ".plist" file extension is not required).
 @param bundleID The identifier for the resource bundle in which the SDK will look for the configuration file.
 @param provider The OAuth identity provider that will be used to handle authentication requests.
 @param completionHandler Block to execute after initializing the user session.
 */
+ (void)startWithConfigFileName:(NSString *)name bundleIdentifier:(NSString *)bundleID authProvider:(nullable id<SMAuthenticationProvider>)provider completionHandler:(nullable SMPStartupHandler)completionHandler NS_SWIFT_NAME(start(configFileName:bundleIdentifier:authenticationProvider:completionHandler:));
/*!
 @abstract Initializes a user session with parameters from the SessionM Platform configuration file located at the specified local file path.
 @discussion Use this method if you would like to use a configuration file created during runtime.
 This method should be called as early as possible in the application lifecycle, typically in <code>application:didFinishLaunchingWithOptions:</code> method of <code>UIApplicationDelegate</code>.
 @param path Local configuration file path.
 @param completionHandler Block to execute after initializing the user session.
 */
+ (void)startWithConfigFileAtPath:(NSString *)path completionHandler:(nullable SMPStartupHandler)completionHandler NS_SWIFT_NAME(start(configFilePath:completionHandler:));
/*!
 @abstract Initializes a user session with parameters from the SessionM Platform configuration file located at the specified local file path.
 @discussion Use this method if you would like to use a configuration file created during runtime.
 This method should be called as early as possible in the application lifecycle, typically in <code>application:didFinishLaunchingWithOptions:</code> method of <code>UIApplicationDelegate</code>.
 @param path Local configuration file path.
 @param provider The OAuth identity provider that will be used to handle authentication requests.
 @param completionHandler Block to execute after initializing the user session.
 */
+ (void)startWithConfigFileAtPath:(NSString *)path authProvider:(nullable id<SMAuthenticationProvider>)provider completionHandler:(nullable SMPStartupHandler)completionHandler NS_SWIFT_NAME(start(configFilePath:authenticationProvider:completionHandler:));

/*!
 @abstract Cleans up the current user session.
 @param completionHandler Block to execute after cleaning up the user session.
 */
+ (void)stopWithCompletionHandler:(nullable SMPShutdownHandler)completionHandler NS_SWIFT_NAME(stop(completionHandler:));

/*!
 @abstract Indicates whether the SDK is currently ready to initialize a user session.
 @discussion Note: this method only returns <code>YES</code> when <code>notReadyReason</code> returns <code>SMReadyReasonCodeNone</code>.
 @result Indicates whether the SDK is currently ready to initialize a user session.
 */
+ (BOOL)isSDKReady;
/*!
 @abstract Bitmask of error codes indicating whether the SDK is currently ready to initialize a user session.
 @result Bitmask of error codes indicating whether the SDK is currently ready to initialize a user session.
 */
+ (SMReadyReasonCodes)notReadyReason;

@end

NS_ASSUME_NONNULL_END

#endif /* __SESSIONM__ */
