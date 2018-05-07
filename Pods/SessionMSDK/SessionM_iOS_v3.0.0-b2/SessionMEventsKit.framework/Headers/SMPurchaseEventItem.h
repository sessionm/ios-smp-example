//
//  SMPurchaseEventItem.h
//  SessionMEventsKit
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SM_PURCHASE_EVENT_ITEM__
#define __SM_PURCHASE_EVENT_ITEM__

#import "SMEventItem.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMPurchaseEventItem
 @abstract Defines the data associated with a single instance of a triggered purchase event.
 */
@interface SMPurchaseEventItem : SMEventItem

/*!
 @property name
 @abstract Unique identifier for the item in the product catalog.
 */
@property(nullable, nonatomic, strong, readonly) NSString *name;
/*!
 @property parentName
 @abstract Generic name of item in the product catalog that has variant subitems (e.g. a shirt that has multiple sizes).
 */
@property(nullable, nonatomic, strong, readonly) NSString *parentName;
/*!
 @property details
 @abstract Description of item.
 */
@property(nullable, nonatomic, strong, readonly) NSString *details;
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
 @property quantity
 @abstract The number of items purchased.
 */
@property(nonatomic, assign, readonly) NSInteger quantity;
/*!
 @property priceAmount
 @abstract The price of the item in cents.
 */
@property(nonatomic, assign, readonly) NSInteger priceAmount;
/*!
 @property overridePriceAmount
 @abstract A non-standard price of the item in cents as specified for the transaction.
 */
@property(nonatomic, assign, readonly) NSInteger overridePriceAmount;
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
/*!
 @property amount
 @abstract The amount of the transaction in cents.
 */
@property(nonatomic, assign, readonly) NSInteger amount;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_PURCHASE_EVENT_ITEM__ */
