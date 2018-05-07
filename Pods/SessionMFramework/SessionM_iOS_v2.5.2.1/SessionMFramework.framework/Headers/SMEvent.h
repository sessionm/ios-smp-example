//
//  SMEvent.h
//  SessionM
//
//  Copyright © 2018 SessionM. All rights reserved.
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
 @abstract The developer-defined identifier of the campaign that the event data will be processed against when when posting to the SessionM Platform.
 @discussion The event will be processed against all campaigns if neither <code>campaignID</code> or <code>permalink</code> is set before calling @link //apple_ref/occ/instm/SMEventsManager/postEvent:completionHandler: @/link.
 */
@property(nullable, nonatomic, strong, readonly) NSString *permalink;
/*!
 @property time
 @abstract Indicates when the event will be recorded as having taken place (represented as the number of milliseconds since 00:00:00 UTC on 1 January 1970).
 @discussion If not set by the developer, then the default value will be the time at which the corresponding @link //apple_ref/occ/cl/SMEventBuilder @/link object was initialized.
 */
@property(nonatomic, assign, readonly) NSTimeInterval time;
/*!
 @property items
 @abstract A list of separate instances of the triggered event.
 */
@property(nonatomic, strong, readonly) NSArray<__kindof SMEventItem *> *items;
/*!
 @property additionalData
 @abstract Developer-defined data that will be sent along with the event when posting to the SessionM Platform.
 @discussion See @link //apple_ref/occ/instm/SMEventBuilder/setAttribute:forKey: @/link for more information.
 */
@property(nonatomic, strong, readonly) NSDictionary<NSString *, id> *additionalData;

/*!
 @abstract Returns event data in a dictionary format.
 @result <code>NSDictionary</code> representation of event data.
 */
- (NSDictionary<NSString *, id> *)asDictionary;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_EVENT__ */
