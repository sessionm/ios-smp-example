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

#import "SMError.h"

NS_ASSUME_NONNULL_BEGIN

extern NSString *const SMPConfigBaseFileName;

@interface SMPConfig : NSObject

/*!
 @property apiKey The Api Key for this SessionM client.
 @abstract This comes from the SMPConfig.plist file.  SMPConfig is the default name, can be other names.
 */
+(nullable NSString *)apiKey;
/*!
 @property serverURL The URL for this SessionM client.
 @abstract This comes from the SMPConfig.plist file.  SMPConfig is the default name, can be other names.
 */
+(nullable NSString *)serverURL;
+(BOOL)collectsLocation;

/*!
 @property isConfigLoaded Has all of the config been loaded
 @abstract Required before making API calls
 */
+(BOOL)isConfigLoaded;
/*!
 @property isLocalConfigLoaded Has the config been loaded from SMPConfig file
 @abstract Required before any requests to the servers
 */
+(BOOL)isLocalConfigLoaded;
/*!
 @property isRemoteConfigLoaded Has the config been loaded from the SessionM server
 @abstract Required before any requests to the servers
 */
+(BOOL)isRemoteConfigLoaded;
/*!
 @abstract Causes the SDK to forget any loaded configuration.
 @discussion This is useful for testing, and if there is more than one configuration required for your APP
 */
+(void)forgetConfig;

/*!
 @property customerConfig Special configuration that was add for the customer
 @abstract If a SessionM customer needs additional special configuration, it can be added to the SMPConfig file
 or to the Remote configuration
 */
+(SMCustomerConfig *)customerConfig;

@end

NS_ASSUME_NONNULL_END

#endif /* __SMP_CONFIG__ */
