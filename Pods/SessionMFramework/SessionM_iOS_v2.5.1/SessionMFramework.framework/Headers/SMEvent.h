//
//  SMEvent.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef __SM_EVENT__
#define __SM_EVENT__

#import "SMEventItem.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMEvent
 @abstract Defines the data associated with an event performed by the user to make progress towards completing an application-specific campaign.
 */
@interface SMEvent : NSObject

/*!
 @property eventName
 @abstract A unique name used to trigger the event when posting to the SessionM Platform.
 */
@property(nonatomic, strong, readonly) NSString *eventName;
/*!
 @property campaignID
 @abstract The internal SessionM Platform identifier of the campaign that the event data will be processed against when posting to the SessionM Platform.
 @discussion The event data will be processed against all campaigns if neither <code>campaignID</code> or <code>permalink</code> is set before calling @link //apple_ref/occ/instm/SMEventsManager/postEvent:completionHandler: @/link.
 */
@property(nullable, nonatomic, strong, readonly) NSString *campaignID;
/*!
 @property permalink
 @abstract The customer-defined identifier of the campaign that the event data will be processed against when when posting to the SessionM Platform.
 @discussion The event will be processed against all campaigns if neither <code>campaignID</code> or <code>permalink</code> is set before calling @link //apple_ref/occ/instm/SMEventsManager/postEvent:completionHandler: @/link.
 */
@property(nullable, nonatomic, strong, readonly) NSString *permalink;
/*!
 @property items
 @abstract A list of separate instances of the triggered event.
 */
@property(nonatomic, strong, readonly) NSArray<__kindof SMEventItem *> *items;

/*!
 @abstract Returns event data in a dictionary format.
 @result <code>NSDictionary</code> representation of event data.
 */
- (NSDictionary<NSString *, NSObject *> *)asDictionary;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_EVENT__ */
