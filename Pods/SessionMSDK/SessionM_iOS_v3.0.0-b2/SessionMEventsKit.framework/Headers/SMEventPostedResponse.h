//
//  SMEventPostedResponse.h
//  SessionMEventsKit
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SM_EVENT_POSTED_RESPONSE__
#define __SM_EVENT_POSTED_RESPONSE__

#import "SMEventsResponse.h"
#import "SMEventNotification.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMEventPostedResponse
 @abstract Defines the data returned from a successful <code>SMEventsManager postEvent:completionHandler:</code> or <code>postEventFromBuilder:completionHandler:</code> call.
 */
@interface SMEventPostedResponse : SMEventsResponse

/*!
 @property notifications
 @abstract Any notifications to be presented to the user as a result of posting the event.
 */
@property(nonatomic, strong, readonly) NSArray<SMEventNotification *> *notifications;
/*!
 @property deltas
 @abstract Any changes to the user's progress towards completing any action items as a result of posting the event.
 */
@property(nonatomic, strong, readonly) NSDictionary<NSString *, id> *deltas;
/*!
 @property user
 @abstract Any changes to the user's account status (e.g. point balance or rewards tier) as a result of posting the event.
 */
@property(nonatomic, strong, readonly) NSDictionary<NSString *, id> *user;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_EVENT_POSTED_RESPONSE__ */
