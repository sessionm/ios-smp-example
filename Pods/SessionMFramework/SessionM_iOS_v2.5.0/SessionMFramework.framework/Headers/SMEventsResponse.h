//
//  SMEventsResponse.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef __SM_EVENTS_RESPONSE__
#define __SM_EVENTS_RESPONSE__

#import "SMBehavior.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMEventsResponse
 @abstract Defines the data returned from a successful Events API call.
 */
@interface SMEventsResponse : NSObject

/*!
 @property behaviors
 @abstract Data representing the application's action items and the user's progress towards completing them.
*/
@property(nonatomic, strong, readonly) NSDictionary<NSString *, __kindof SMBehavior *> *behaviors;
/*!
 @property availablePoints
 @abstract User's current loyalty points balance.
 */
@property(nonatomic, assign, readonly) NSInteger availablePoints;
/*!
 @property extras
 @abstract Any data values that do not have an associated class property.
 */
@property(nullable, nonatomic, strong, readonly) NSDictionary<NSString *, NSObject *> *extras;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_EVENTS_RESPONSE__ */
