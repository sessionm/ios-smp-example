//
//  SMPurchaseEvent.h
//  SessionMEventsKit
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SM_PURCHASE_EVENT__
#define __SM_PURCHASE_EVENT__

#import "SMEvent.h"
#import "SMPurchaseEventItem.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMPurchaseEvent
 @abstract Defines the data associated with an event performed by the user that contains purchase metadata such as product SKUs.
 */
@interface SMPurchaseEvent : SMEvent

/*!
 @property items
 @abstract A list of separate instances of the event.
 */
@property(nonatomic, strong, readonly) NSArray<SMPurchaseEventItem *> *items;

/*!
 @property channel
 @abstract Medium used to submit the transaction (e.g. digital).
 */
@property(nullable, nonatomic, strong, readonly) NSString *channel;
/*!
 @property subChannel
 @abstract Detailed medium used to submit the transaction (e.g. mobile).
 */
@property(nullable, nonatomic, strong, readonly) NSString *subChannel;
/*!
 @property store
 @abstract Unique identifier for the store where the transaction occurred.
 */
@property(nullable, nonatomic, strong, readonly) NSString *store;
/*!
 @property postalCode
 @abstract Postal code where purchase was made.
 */
@property(nullable, nonatomic, strong, readonly) NSString *postalCode;
/*!
 @property country
 @abstract Country where purchase was made.
 */
@property(nullable, nonatomic, strong, readonly) NSString *country;
/*!
 @property currency
 @abstract Type of currency used to make the purchase.
 */
@property(nullable, nonatomic, strong, readonly) NSString *currency;
/*!
 @property transactionID
 @abstract Unique identifier for the transaction.
 */
@property(nullable, nonatomic, strong, readonly) NSString *transactionID;
/*!
 @property transactionType
 @abstract Type of transaction.
 */
@property(nullable, nonatomic, strong, readonly) NSString *transactionType;
/*!
 @property reloadAmount
 @abstract Reload amount.
 */
@property(nonatomic, assign, readonly) NSInteger reloadAmount;
/*!
 @property reloadType
 @abstract Reload type.
 */
@property(nullable, nonatomic, strong, readonly) NSString *reloadType;
/*!
 @property subtotalAmount
 @abstract The subtotal amount for the transaction in cents.
 */
@property(nonatomic, assign, readonly) NSInteger subtotalAmount;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_PURCHASE_EVENT__ */
