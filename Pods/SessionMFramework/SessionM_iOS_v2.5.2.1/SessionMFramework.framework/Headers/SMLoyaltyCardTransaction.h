//
//  SMLoyaltyCardTransaction.h
//  SessionM
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifndef __SM_LOYALTY_CARD_TRANSACTION__
#define __SM_LOYALTY_CARD_TRANSACTION__

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMLoyaltyCardTransaction
 @abstract Defines the purchase data for an item purchased with a loyalty card linked to a user's account.
 */
@interface SMLoyaltyCardTransaction : NSObject

/*!
 @property transactionID
 @abstract Unique ID for transaction.
 @discussion This ID will be equal to @link //apple_ref/occ/instp/SMTransaction/recordModelID @/link in the corresponding transaction record.
 */
@property(nonnull, nonatomic, strong, readonly) NSString *transactionID;
/*!
 @property name
 @abstract Item name.
 */
@property(nullable, nonatomic, strong, readonly) NSString *name;
/*!
 @property details
 @abstract Item description.
 */
@property(nullable, nonatomic, strong, readonly) NSString *details;
/*!
 @property descriptionText
 @abstract Item description.
 @deprecated This property has been deprecated - use @link details @/link instead.
 */
@property(nullable, nonatomic, strong, readonly) NSString *descriptionText __attribute__((deprecated));
/*!
 @property price
 @abstract Individual item price.
 */
@property(nonatomic, assign, readonly) double price;
/*!
 @property quantity
 @abstract Amount of items purchased.
 */
@property(nonatomic, assign, readonly) NSInteger quantity;
/*!
 @property points
 @abstract Amount of points user earned for the transaction.
 */
@property(nonatomic, assign, readonly) NSInteger points;
/*!
 @property transactionTime
 @abstract Indicates when the transaction took place.
 */
@property(nullable, nonatomic, strong, readonly) NSString *transactionTime;
/*!
 @property createdTime
 @abstract Indicates when the transaction record was created.
 */
@property(nullable, nonatomic, strong, readonly) NSString *createdTime;
/*!
 @property updatedTime
 @abstract Indicates when the transaction record was last updated.
 */
@property(nullable, nonatomic, strong, readonly) NSString *updatedTime;
/*!
 @property extras
 @abstract Any data values that do not have an associated class property.
 */
@property(nullable, nonatomic, strong, readonly) NSDictionary<NSString *, id> *extras;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_LOYALTY_CARD_TRANSACTION__ */
