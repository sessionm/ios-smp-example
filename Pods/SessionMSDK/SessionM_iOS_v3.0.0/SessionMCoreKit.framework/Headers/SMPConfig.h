//
//  SMPConfig.h
//  SessionMCoreKit
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SMP_CONFIG__
#define __SMP_CONFIG__

#import <Foundation/Foundation.h>

#import "SMCustomerConfig.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMPConfig
 @abstract Defines configuration settings for the app and stores their current values.
 */
@interface SMPConfig : NSObject

/*!
 @abstract The API key for the developer's digital property.
 @result The API key for the developer's digital property.
 */
+ (nullable NSString *)apiKey;
/*!
 @abstract The URL used for HTTP requests made to the SessionM Platform on behalf of the developer.
 @result The URL used for HTTP requests made to the SessionM Platform on behalf of the developer.
 */
+ (nullable NSString *)serverURL;
/*!
 @abstract Indicates whether the SDK will track the user's location data for analytical purposes.
 @result <code>BOOL</code> indicating whether the SDK will track the user's location data for analytical purposes.
 */
+ (BOOL)collectsLocation;

/*!
 @abstract Indicates whether local and remote configurations have been loaded.
 @discussion This method must return <code>YES</code> before any HTTP requests can be made to the SessionM Platform.
 @result <code>BOOL</code> indicating whether local and remote configurations have been loaded.
 */
+ (BOOL)isConfigLoaded;
/*!
 @abstract Indicates whether configuration from the developer's config file has been loaded.
 @result <code>BOOL</code> indicating whether configuration from the developer's config file has been loaded.
 */
+ (BOOL)isLocalConfigLoaded;
/*!
 @abstract Indicates whether configuration from the SessionM Platform server has been loaded.
 @result <code>BOOL</code> indicating whether configuration from the SessionM Platform server has been loaded.
 */
+ (BOOL)isRemoteConfigLoaded;
/*!
 @abstract Resets any loaded configuration.
 @discussion If your app requires the use of multiple configurations, then this method should be called before changing configurations.
 */
+ (void)forgetConfig;

/*!
 @abstract Stores the current values for any local or remote app configuration settings defined by the customer.
 @result <code>SMCustomerConfig</code> service object.
 */
+ (SMCustomerConfig *)customerConfig;

@end

NS_ASSUME_NONNULL_END

#endif /* __SMP_CONFIG__ */
