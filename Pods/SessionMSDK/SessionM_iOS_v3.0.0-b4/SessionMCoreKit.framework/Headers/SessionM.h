//
//  SessionM.h
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SESSIONM__
#define __SESSIONM__

#import <Foundation/Foundation.h>
#import "SMAuthenticationProvider.h"
#import "SMPStartup.h"
#import "SMLogger.h"

NS_ASSUME_NONNULL_BEGIN

extern NSString * const __SESSIONM_SDK_VERSION__;
extern double const __SESSIONM_SDK_MIN_SUPPORTED_DEVICE_VERSION__;

typedef NS_OPTIONS(NSUInteger, SMReadyReasonCodes) {
    SMReadyReasonCodeNone                     = 0x00,
    SMReadyReasonCodeNoConfig                 = 0x01,
    SMReadyReasonCodeNoAuthenticationProvider = 0x02,
    SMReadyReasonCodeNotAuthenticated         = 0x04
};

/*!
 @typedef SMPServerType
 @abstract SessionM Platform server type (see <code>startWithConfigFileServerType:</code> for more info).

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
 @class SessionM
 @abstract SessionM service interface.
*/
@interface SessionM : NSObject

/*!
 @property logLevel
 @abstract Log level.
 */
+(void)setLogLevel:(SMLogLevel)logLevel;
/*!
 @property logCategories
 @abstract Bitmask of log categories.
 */
+(void)setLogCategories:(SMLogCategory)categories;
/*!
 @property pluginSDK
 @abstract The name of the plug-in SDK.
 */
+(NSString * _Nullable)pluginSDK;
/*!
 @property pluginSDKVersion
 @abstract The version number of the plug-in SDK being used.
 */
+(NSString * _Nullable)pluginSDKVersion;
/*!
 @abstract Sets the SessionM plug-in SDK name and version number.
 @discussion This method should be called from the plug-in SDK before a session is started.
 @param name The plug-in SDK name
 @param version The plug-in SDK version number
 */
+(void)setPluginSDK:(NSString * _Nullable)name version:(NSString * _Nullable)version NS_SWIFT_NAME(setPluginSDKName(_:version:));
/*!
 @property customLocale
 @abstract Determines the default locale to use when making API calls (<code>NSLocale currentLocale</code> is used as the default locale when this property is set to <code>nil</code>).
 @discussion This property can only be set when the session is stopped.
 */
+(NSLocale * _Nullable)customLocale;
+(void)setCustomLocale:(NSLocale * _Nullable)customLocale NS_SWIFT_NAME(setCustomLocale(_:));
/*!
 @property shouldCollectIDFA
 @abstract Indicates whether the SDK will request the user's advertising identifier when starting a session (default value is <code>YES</code>).
 */
+(BOOL)shouldCollectIDFA;
+(void)setShouldCollectIDFA:(BOOL)shouldCollectIDFA;

+(nullable id<SMAuthenticationProvider>)authenticationProvider;
+(void)setAuthenticationProvider:(nullable id<SMAuthenticationProvider>)authenticationProvider completionHandler:(nullable SetAuthenticationProviderHandler)completionHandler NS_SWIFT_NAME(setAuthenticationProvider(_:completionHandler:));

+ (void)startWithCompletionHandler:(nullable SMPStartupHandler)completionHandler NS_SWIFT_NAME(start(completionHandler:));
/*!
 @abstract Starts session with parameters from the app's SessionM Platform configuration file.
 @discussion In order to use this method, you must download the configuration file for your app from the SessionM Platform portal, and then drag the file into Xcode to copy it to your app.
 Use this method if you would like to use "SMPConfig.plist" as your configuration file name.
 This method is executed asynchronously with its outcome communicated via <code>sessionM:didTransitionToState:</code> or <code>sessionM:didFailWithError:</code> delegate callbacks.
 This method should be called as early as possible in the application lifecycle, typically in <code>application:didFinishLaunchingWithOptions:</code> method of <code>UIApplicationDelegate</code>.
 */
+ (void)startWithAuthenticationProvider:(nullable id<SMAuthenticationProvider>)provider completionHandler:(nullable SMPStartupHandler)completionHandler NS_SWIFT_NAME(start(authenticationProvider:completionHandler:));
+ (void)startWithConfigFileInBundleWithIdentifier:(NSString *)bundleID completionHandler:(nullable SMPStartupHandler)completionHandler NS_SWIFT_NAME(start(configFileBundleID:completionHandler:));
/*!
 @abstract Starts session with parameters from the SessionM Platform configuration file in the bundle with the specified identifier.
 @discussion In order to use this method, you must download the configuration file for your app from the SessionM Platform portal, and then drag the file into Xcode to copy it to your app.
 Use this method if you would like to use "SMPConfig.plist" as your configuration file name.
 This method is executed asynchronously with its outcome communicated via <code>sessionM:didTransitionToState:</code> or <code>sessionM:didFailWithError:</code> delegate callbacks.
 This method should be called as early as possible in the application lifecycle, typically in <code>application:didFinishLaunchingWithOptions:</code> method of <code>UIApplicationDelegate</code>.
 @param bundleID Identifier for the bundle in which the SDK will look for the configuration file.
 */
+ (void)startWithConfigFileInBundleWithIdentifier:(NSString *)bundleID authProvider:(nullable id<SMAuthenticationProvider>)provider completionHandler:(nullable SMPStartupHandler)completionHandler NS_SWIFT_NAME(start(configFileBundleID:authenticationProvider:completionHandler:));
+ (void)startWithConfigFileServerType:(SMPServerType)type completionHandler:(nullable SMPStartupHandler)completionHandler NS_SWIFT_NAME(start(configFileServerType:completionHandler:));
/*!
 @abstract Starts session with parameters from the app's SessionM Platform configuration file having the specified server type in its name (e.g. "SMPConfig-production.plist").
 @discussion In order to use this method, you must download the configuration file for your app from the SessionM Platform portal, and then drag the file into Xcode to copy it to your app.
 Use this method if you have multiple configuration files corresponding to your development environments.
 This method is executed asynchronously with its outcome communicated via <code>sessionM:didTransitionToState:</code> or <code>sessionM:didFailWithError:</code> delegate callbacks.
 This method should be called as early as possible in the application lifecycle, typically in <code>application:didFinishLaunchingWithOptions:</code> method of <code>UIApplicationDelegate</code>.
 @param type The server type to be used as a suffix in the configuration file name (e.g. passing in <code>SMPServerTypeStaging</code> will cause this method to use the "SMPConfig-staging.plist" configuration file).
 */
+ (void)startWithConfigFileServerType:(SMPServerType)type authProvider:(nullable id<SMAuthenticationProvider>)provider completionHandler:(nullable SMPStartupHandler)completionHandler NS_SWIFT_NAME(start(configFileServerType:authenticationProvider:completionHandler:));
+ (void)startWithConfigFileServerType:(SMPServerType)type bundleIdentifier:(NSString *)bundleID completionHandler:(nullable SMPStartupHandler)completionHandler NS_SWIFT_NAME(start(configFileServerType:bundleIdentifier:completionHandler:));
/*!
 @abstract Starts session with parameters from the SessionM Platform configuration file having the specified server type in its name (e.g. "SMPConfig-production.plist") in the bundle with the specified identifier.
 @discussion In order to use this method, you must download the configuration file for your app from the SessionM Platform portal, and then drag the file into Xcode to copy it to your app.
 Use this method if you have multiple configuration files corresponding to your development environments.
 This method is executed asynchronously with its outcome communicated via <code>sessionM:didTransitionToState:</code> or <code>sessionM:didFailWithError:</code> delegate callbacks.
 This method should be called as early as possible in the application lifecycle, typically in <code>application:didFinishLaunchingWithOptions:</code> method of <code>UIApplicationDelegate</code>.
 @param type The server type to be used as a suffix in the configuration file name (e.g. passing in <code>SMPServerTypeStaging</code> will cause this method to use the "SMPConfig-staging.plist" configuration file).
 @param bundleID Identifier for the bundle in which the SDK will look for the configuration file.
 */
+ (void)startWithConfigFileServerType:(SMPServerType)type bundleIdentifier:(NSString *)bundleID authProvider:(nullable id<SMAuthenticationProvider>)provider completionHandler:(nullable SMPStartupHandler)completionHandler NS_SWIFT_NAME(start(configFileServerType:bundleIdentifier:authenticationProvider:completionHandler:));
+ (void)startWithConfigFileName:(NSString *)name completionHandler:(nullable SMPStartupHandler)completionHandler NS_SWIFT_NAME(start(configFileName:completionHandler:));
/*!
 @abstract Starts session with parameters from the app's SessionM Platform configuration file having the specified name.
 @discussion In order to use this method, you must download the configuration file for your app from the SessionM Platform portal, and then drag the file into Xcode to copy it to your app.
 Use this method if you would like to use a custom name for your configuration file.
 This method is executed asynchronously with its outcome communicated via <code>sessionM:didTransitionToState:</code> or <code>sessionM:didFailWithError:</code> delegate callbacks.
 This method should be called as early as possible in the application lifecycle, typically in <code>application:didFinishLaunchingWithOptions:</code> method of <code>UIApplicationDelegate</code>.
 @param name Configuration file name (note: passing in the ".plist" file extension is not required).
 */
+ (void)startWithConfigFileName:(NSString *)name authProvider:(nullable id<SMAuthenticationProvider>)provider completionHandler:(nullable SMPStartupHandler)completionHandler NS_SWIFT_NAME(start(configFileName:authenticationProvider:completionHandler:));
+ (void)startWithConfigFileName:(NSString *)name bundleIdentifier:(NSString *)bundleID completionHandler:(nullable SMPStartupHandler)completionHandler NS_SWIFT_NAME(start(configFileName:bundleIdentifier:completionHandler:));
/*!
 @abstract Starts session with parameters from the SessionM Platform configuration file having the specified name in the bundle with the specified identifier.
 @discussion In order to use this method, you must download the configuration file for your app from the SessionM Platform portal, and then drag the file into Xcode to copy it to your app.
 Use this method if you would like to use a custom name for your configuration file.
 This method is executed asynchronously with its outcome communicated via <code>sessionM:didTransitionToState:</code> or <code>sessionM:didFailWithError:</code> delegate callbacks.
 This method should be called as early as possible in the application lifecycle, typically in <code>application:didFinishLaunchingWithOptions:</code> method of <code>UIApplicationDelegate</code>.
 @param name Configuration file name (note: passing in the ".plist" file extension is not required).
 @param bundleID Identifier for the bundle in which the SDK will look for the configuration file.
 */
+ (void)startWithConfigFileName:(NSString *)name bundleIdentifier:(NSString *)bundleID authProvider:(nullable id<SMAuthenticationProvider>)provider completionHandler:(nullable SMPStartupHandler)completionHandler NS_SWIFT_NAME(start(configFileName:bundleIdentifier:authenticationProvider:completionHandler:));
+ (void)startWithConfigFileAtPath:(NSString *)path completionHandler:(nullable SMPStartupHandler)completionHandler NS_SWIFT_NAME(start(configFilePath:completionHandler:));
/*!
 @abstract Starts session with parameters from the SessionM Platform configuration file located at the specified local file path.
 @discussion Use this method if you would like to use a configuration file created during runtime.
 This method is executed asynchronously with its outcome communicated via <code>sessionM:didTransitionToState:</code> or <code>sessionM:didFailWithError:</code> delegate callbacks.
 This method should be called as early as possible in the application lifecycle, typically in <code>application:didFinishLaunchingWithOptions:</code> method of <code>UIApplicationDelegate</code>.
 @param path Local configuration file path.
 */
+ (void)startWithConfigFileAtPath:(NSString *)path authProvider:(nullable id<SMAuthenticationProvider>)provider completionHandler:(nullable SMPStartupHandler)completionHandler NS_SWIFT_NAME(start(configFilePath:authenticationProvider:completionHandler:));

+(void)stop:(nullable SMPShutdownHandler)completionHandler NS_SWIFT_NAME(stop(completionHandler:));

+ (BOOL)isSDKReady;
+ (SMReadyReasonCodes)notReadyReason;

@end

NS_ASSUME_NONNULL_END

#endif /* __SESSIONM__ */
