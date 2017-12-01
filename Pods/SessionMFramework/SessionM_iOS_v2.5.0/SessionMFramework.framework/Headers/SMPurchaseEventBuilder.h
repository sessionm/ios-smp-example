//
//  SMPurchaseEventBuilder.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef __SM_PURCHASE_EVENT_BUILDER__
#define __SM_PURCHASE_EVENT_BUILDER__

#import "SMEventBuilder.h"
#import "SMPurchaseEvent.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMPurchaseEventBuilder
 @abstract Class used for building @link SMPurchaseEvent @/link objects that represent an event performed by the user that contains purchase metadata such as product SKUs.
 */
@interface SMPurchaseEventBuilder : SMEventBuilder

/*!
 @abstract Returns a purchase event builder that builds events with the "purchase" event name.
 @result <code>SMPurchaseEventBuilder</code> instance.
 */
+ (instancetype)builder;
/*!
 @discussion This method is unavailable - use @link builder @/link instead.
 */
+ (instancetype)builderForEventWithName:(NSString *)eventName NS_SWIFT_NAME(builder(eventName:)) NS_UNAVAILABLE;

/*!
 @discussion This method is unavailable - use @link init @/link instead.
 */
- (instancetype)initWithEventName:(NSString *)eventName NS_SWIFT_NAME(init(eventName:)) NS_UNAVAILABLE;

/*!
 @abstract Generates a purchase event based on the builder's current configuration.
 @result The generated @link SMPurchaseEvent @/link object.
 */
- (SMPurchaseEvent *)build;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_PURCHASE_EVENT_BUILDER__ */
