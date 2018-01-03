//
//  SMPurchaseEventItemBuilder.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef __SM_PURCHASE_EVENT_ITEM_BUILDER__
#define __SM_PURCHASE_EVENT_ITEM_BUILDER__

#import "SMEventItemBuilder.h"
#import "SMPurchaseEventItem.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMPurchaseEventItemBuilder
 @abstract Class used for building @link SMPurchaseEventItem @/link objects that represent the data associated with a single instance of a triggered purchase event.
 */
@interface SMPurchaseEventItemBuilder : SMEventItemBuilder

/*!
 @property name
 @abstract Unique identifier for the item in the product catalog.
 */
@property(nullable, nonatomic, strong, readwrite) NSString *name;
/*!
 @property parentName
 @abstract Generic name of item in the product catalog that has variant subitems (e.g. a shirt that has multiple sizes).
 */
@property(nullable, nonatomic, strong, readwrite) NSString *parentName;
/*!
 @property details
 @abstract Description of item.
 */
@property(nullable, nonatomic, strong, readwrite) NSString *details;
/*!
 @property time
 @abstract Time of purchase.
 */
@property(nullable, nonatomic, strong, readwrite) NSString *time;
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
 @property quantity
 @abstract The number of items purchased.
 */
@property(nonatomic, assign, readwrite) NSInteger quantity;
/*!
 @property priceAmount
 @abstract The price of the item in cents.
 */
@property(nonatomic, assign, readwrite) NSInteger priceAmount;
/*!
 @property overridePriceAmount
 @abstract A non-standard price of the item in cents as specified for the transaction.
 */
@property(nonatomic, assign, readwrite) NSInteger overridePriceAmount;
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
 @property amount
 @abstract The amount of the transaction in cents.
 */
@property(nonatomic, assign, readwrite) NSInteger amount;

/*!
 @abstract Generates a purchase event based on the builder's current configuration.
 @result The generated @link SMPurchaseEventItem @/link object.
 */
- (SMPurchaseEventItem *)build;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_PURCHASE_EVENT_ITEM_BUILDER__ */
