//
//  SMLogger.h
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
 @constant SMLogCategoryNone Disable logging.
 @constant SMLogCategoryAPI Receive logging for key API activity.
 @constant SMLogCategoryTrace For use in the debugger - receive logging related to the current code trace.
 @constant SMLogCategoryNetwork Receive logging for network activity.
 @constant SMLogCategoryGeo Receive logging for geofence-related activity.
 @constant SMLogCategoryUser Receive logging for user-related activity.
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


/*!
 @class SMLogger
 @abstract Defines available log settings and stores their current values.
 */
@interface SMLogger : NSObject

/*!
 @property logLevel
 @abstract Currently enabled log level (default value is <code>SMLogLevelOff</code>).
 */
@property(nonatomic, assign, readwrite) SMLogLevel logLevel;
/*!
 @property logCategories
 @abstract Bitmask of currently enabled log cateogries (default value is <code>SMLogCategoryAll</code>).
 */
@property(nonatomic, assign, readwrite) SMLogCategory logCategories;

/*!
 @abstract Singleton that stores current log settings.
 @result <code>SMLogger</code> service object.
 */
+ (SMLogger *)instance;

@end

#endif /* __SM_LOGGER__ */
