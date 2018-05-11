//
//  SMEventBuilder.h
//  SessionMEventsKit
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SM_EVENT_BUILDER__
#define __SM_EVENT_BUILDER__

#import <Foundation/Foundation.h>
#import "SMEvent.h"
#import "SMEventItemBuilder.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMEventBuilder
 @abstract Class used for building <code>SMEvent</code> objects that represent an event performed by the user to make progress towards completing an application-specific campaign.
 */
@interface SMEventBuilder : NSObject

/*!
 @property campaignID
 @abstract The internal SessionM Platform identifier of the campaign that the event data will be processed against when posting to the SessionM Platform.
 @discussion The event data will be processed against all campaigns if neither <code>campaignID</code> or <code>permalink</code> is set before calling <code>SMEventsManager postEvent:completionHandler:</code>.
 */
@property(nullable, nonatomic, strong, readwrite) NSString *campaignID;
/*!
 @property permalink
 @abstract The customer-defined identifier of the campaign that the event data will be processed against when when posting to the SessionM Platform.
 @discussion The event will be processed against all campaigns if neither <code>campaignID</code> or <code>permalink</code> is set before calling <code>SMEventsManager postEvent:completionHandler:</code>.
 */
@property(nullable, nonatomic, strong, readwrite) NSString *permalink;
/*!
 @property time
 @abstract Indicates when the event will be recorded as having taken place (represented as the number of milliseconds since 00:00:00 UTC on 1 January 1970).
 @discussion If not set by the developer, then the default value will be the time at which the event builder was initialized.
 */
@property(nonatomic, assign, readwrite) NSTimeInterval time;

/*!
 @abstract Returns an event builder that builds events with the specified event name.
 @param eventName The unique name used to trigger the event when posting to the SessionM Platform.
 @result <code>SMEventBuilder</code> instance.
 */
+ (instancetype)builderForEventWithName:(NSString *)eventName NS_SWIFT_NAME(builder(eventName:));

/*!
 @abstract Returns an event builder that builds events with the specified event name.
 @param eventName The unique name used to trigger the event when posting to the SessionM Platform.
 @result <code>SMEventBuilder</code> instance.
 */
- (instancetype)initWithEventName:(NSString *)eventName NS_SWIFT_NAME(init(eventName:));

/*!
 @abstract Generates an event based on the builder's current configuration.
 @result The generated <code>SMEvent</code> object.
 */
- (SMEvent *)build;
/*!
 @abstract Adds the specified event item to the generated event's <code>SMEvent items</code> array.
 @param item The event item to add.
 */
- (void)addItem:(SMEventItem *)item NS_SWIFT_NAME(addItem(_:));
/*!
 @abstract Adds the specified event items to the generated event's <code>SMEvent items</code> array.
 @param items The event items to add.
 */
- (void)addItems:(NSArray<SMEventItem *> *)items NS_SWIFT_NAME(addItems(_:));
/*!
 @abstract Uses the specified event item builder to build an event item that will be added to the generated event's <code>SMEvent items</code> array.
 @param builder The event item builder whose generated event item will be added.
 */
- (void)addItemFromBuilder:(SMEventItemBuilder *)builder NS_SWIFT_NAME(addItem(from:));
/*!
 @abstract Uses the specified event item builders to build event items that will be added to the generated event's <code>SMEvent items</code> array.
 @param builders The event item builders whose generated event items will be added.
 */
- (void)addItemsFromBuilders:(NSArray<SMEventItemBuilder *> *)builders NS_SWIFT_NAME(addItems(from:));
/*!
 @abstract Removes any event items that would have been added to the generated event's <code>SMEvent items</code> array.
 */
- (void)removeAllItems;

/*!
 @abstract Sets a customer-defined key-value pair to be sent along with any generated events when posting to the SessionM Platform.
 @param value Value for specified key (a value of <code>nil</code> will remove <code>key</code> from the event data).
 @param key Customer-defined key.
 @discussion See <code>SMEvent additionalData</code> for more information.
 */
- (void)setAttribute:(id _Nullable)value forKey:(NSString *)key NS_SWIFT_NAME(setAttribute(value:forKey:));

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_EVENT_BUILDER__ */
