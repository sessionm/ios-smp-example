//
//  SMSimpleEventBuilder.h
//  SessionM
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SM_SIMPLE_EVENT_BUILDER__
#define __SM_SIMPLE_EVENT_BUILDER__

#import "SMEvent.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMSimpleEventBuilder
 @abstract Class used for building simple @link SMEvent @/link objects that represent a single event performed by the user to make progress towards completing an application-specific campaign.
 */
@interface SMSimpleEventBuilder : NSObject

/*!
 @property campaignID
 @abstract The internal SessionM Platform identifier of the campaign that the event data will be processed against when posting to the SessionM Platform.
 @discussion The event data will be processed against all campaigns if neither <code>campaignID</code> or <code>permalink</code> is set before calling @link //apple_ref/occ/instm/SMEventsManager/postEvent:completionHandler: @/link.
 */
@property(nullable, nonatomic, strong, readwrite) NSString *campaignID;
/*!
 @property permalink
 @abstract The customer-defined identifier of the campaign that the event data will be processed against when when posting to the SessionM Platform.
 @discussion The event will be processed against all campaigns if neither <code>campaignID</code> or <code>permalink</code> is set before calling @link //apple_ref/occ/instm/SMEventsManager/postEvent:completionHandler: @/link.
 */
@property(nullable, nonatomic, strong, readwrite) NSString *permalink;

/*!
 @abstract Returns an event builder that builds events with the specified event name.
 @param eventName The unique name used to trigger the event when posting to the SessionM Platform.
 @result <code>SMSimpleEventBuilder</code> instance.
 */
+ (instancetype)builderForEventWithName:(NSString *)eventName NS_SWIFT_NAME(builder(eventName:));

/*!
 @abstract Returns an event builder that builds events with the specified event name.
 @param eventName The unique name used to trigger the event when posting to the SessionM Platform.
 @result <code>SMSimpleEventBuilder</code> instance.
 */
- (instancetype)initWithEventName:(NSString *)eventName NS_SWIFT_NAME(init(eventName:));

/*!
 @abstract Generates an event based on the builder's current configuration.
 @result The generated @link SMEvent @/link object.
 */
- (SMEvent *)build;

/*!
 @abstract Sets a customer-defined key-value pair to be sent along with the generated event when posting to the SessionM Platform.
 @param value Value for specified key (a value of <code>nil</code> will remove <code>key</code> from the event data).
 @param key Customer-defined key.
 @discussion See @link //apple_ref/occ/instp/SMEventItem/additionalData @/link for more information.
 */
- (void)setAttribute:(id _Nullable)value forKey:(NSString *)key NS_SWIFT_NAME(setAttribute(value:forKey:));

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_SIMPLE_EVENT_BUILDER__ */
