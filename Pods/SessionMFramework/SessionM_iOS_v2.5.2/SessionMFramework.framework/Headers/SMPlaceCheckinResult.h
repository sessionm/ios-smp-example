//
//  SMPlaceCheckinResult.h
//  SessionM
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SM_PLACE_CHECKIN_RESULT__
#define __SM_PLACE_CHECKIN_RESULT__

#import <Foundation/Foundation.h>
#import "SMNotificationMessage.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMPlaceCheckinResult
 @abstract Defines the data associated with the server-side response for checking into a location.
 */
@interface SMPlaceCheckinResult : NSObject

/*!
 @property message
 @abstract Defines data associated with a bonus opportunity earned for a successful checkin.
 */
@property(nullable, nonatomic, strong, readonly) SMNotificationMessage *message;
/*!
 @property placeID
 @abstract ID of place that was checked into.
 */
@property(nonnull, nonatomic, strong, readonly) NSString *placeID;
/*!
 @property state
 @abstract Checkin state.
 */
@property(nonatomic, strong, readonly) NSString *state;
/*!
 @property canCheckInAgainAt
 @abstract Indicates when place can be checked into again.
 */
@property(nullable, nonatomic, strong, readonly) NSString *canCheckInAgainAt;
/*!
 @property extras
 @abstract Any data values that do not have an associated class property.
 */
@property(nullable, nonatomic, strong, readonly) NSDictionary<NSString *, id> *extras;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_PLACE_CHECKIN_RESULT__ */
