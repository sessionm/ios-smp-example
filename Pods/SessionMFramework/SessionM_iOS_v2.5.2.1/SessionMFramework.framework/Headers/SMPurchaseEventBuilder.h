//
//  SMPurchaseEventBuilder.h
//  SessionM
//
//  Copyright © 2018 SessionM. All rights reserved.
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
 @property channel
 @abstract Medium used to submit the transaction (e.g. digital).
 */
@property(nullable, nonatomic, strong, readwrite) NSString *channel;
/*!
 @property subChannel
 @abstract Detailed medium used to submit the transaction (e.g. mobile).
 */
@property(nullable, nonatomic, strong, readwrite) NSString *subChannel;
/*!
 @property store
 @abstract Unique identifier for the store where the transaction occurred.
 */
@property(nullable, nonatomic, strong, readwrite) NSString *store;
/*!
 @property postalCode
 @abstract Postal code where purchase was made.
 */
@property(nullable, nonatomic, strong, readwrite) NSString *postalCode;
/*!
 @property country
 @abstract Country where purchase was made.
 */
@property(nullable, nonatomic, strong, readwrite) NSString *country;
/*!
 @property currency
 @abstract Type of currency used to make the purchase.
 */
@property(nullable, nonatomic, strong, readwrite) NSString *currency;
/*!
 @property transactionID
 @abstract Unique identifier for the transaction.
 */
@property(nullable, nonatomic, strong, readwrite) NSString *transactionID;
/*!
 @property transactionType
 @abstract Type of transaction.
 */
@property(nullable, nonatomic, strong, readwrite) NSString *transactionType;
/*!
 @property reloadAmount
 @abstract Reload amount.
 */
@property(nonatomic, assign, readwrite) NSInteger reloadAmount;
/*!
 @property reloadType
 @abstract Reload type.
 */
@property(nullable, nonatomic, strong, readwrite) NSString *reloadType;
/*!
 @property subtotalAmount
 @abstract The subtotal amount for the transaction in cents.
 */
@property(nonatomic, assign, readwrite) NSInteger subtotalAmount;

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
