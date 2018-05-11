//
//  SMLoggerProtected.h
//  SessionMCoreKit
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SM_LOGGER__
#define __SM_LOGGER__

#import <Foundation/Foundation.h>

/*!
 @typedef SMLogLevel
 @abstract Log level.

 @constant SMLogLevelOff Disables logging.
 @constant SMLogLevelInfo Enables logging of key API events such as session start, action logging, etc.
 @constant SMLogLevelDebug Enables logging of detailed information about SDK operations such as, for example, network activity in addition to basic API tracing. This level should be used when diagnosing SDK integration problems.
 */
typedef NS_ENUM(NSInteger, SMLogLevel) {
    SMLogLevelOff NS_SWIFT_NAME(off),
    SMLogLevelInfo NS_SWIFT_NAME(info),
    SMLogLevelDebug NS_SWIFT_NAME(debug)
};

/*!
 @typedef SMLogCategory
 @abstract Bitmask of log categories.

 @constant SMLogCategoryAll Receive logging for all categories.
 @constant SMLogCategoryAPI Receive logging for key API activity.
 @constant SMLogCategoryUI Receive logging for UI activity.
 @constant SMLogCategoryNetwork Receive logging for network activity.
 @constant SMLogCategorySession Receive logging for session state changes.
 @constant SMLogCategoryCPI Deprecated: receive logging for CPI activity.
 */
typedef NS_OPTIONS(NSInteger, SMLogCategory) {
    SMLogCategoryAll NS_SWIFT_NAME(all)                             = 0xFF,
    SMLogCategoryNone NS_SWIFT_NAME(none)                           = 0x00,
    SMLogCategoryAPI NS_SWIFT_NAME(api)                             = 0x01,
    SMLogCategoryTrace NS_SWIFT_NAME(trace)                         = 0x02,
    SMLogCategoryNetwork NS_SWIFT_NAME(network)                     = 0x04,
    SMLogCategoryGeo NS_SWIFT_NAME(geo)                             = 0x08,
    SMLogCategoryUser NS_SWIFT_NAME(user)                           = 0x10
};

@interface SMLogger : NSObject

@property(nonatomic) SMLogLevel logLevel;
@property(nonatomic) SMLogCategory logCategories;

+ (SMLogger *)instance;

@end

#endif /* __SM_LOGGER__ */
