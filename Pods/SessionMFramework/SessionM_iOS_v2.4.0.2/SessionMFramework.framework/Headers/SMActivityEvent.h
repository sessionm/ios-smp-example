//
//  SMActivityEvent.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef __SM_ACTIVITY_EVENT__
#define __SM_ACTIVITY_EVENT__

#import "SMEvent.h"
#import "SMActivityEventItem.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMActivityEvent
 @abstract Defines the data associated with a basic activity event performed by the user to make progress towards completing an application-specific campaign.
 */
@interface SMActivityEvent : SMEvent

/*!
 @property items
 @abstract A list of separate instances of the event.
 */
@property(nonatomic, strong, readonly) NSArray<SMActivityEventItem *> *items;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_ACTIVITY_EVENT__ */
