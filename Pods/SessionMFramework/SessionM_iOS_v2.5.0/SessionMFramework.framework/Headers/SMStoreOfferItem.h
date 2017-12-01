//
//  SMStoreOfferItem.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef __SM_STORE_OFFER_ITEM__
#define __SM_STORE_OFFER_ITEM__

#import "SMOfferItem.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMStoreOfferItem
 @abstract Defines the data associated with a loyalty offer item available for purchase.
 */
@interface SMStoreOfferItem : SMOfferItem

/*!
 @property offerID
 @abstract Unique identifier for the store offer item.
 */
@property(nonatomic, strong, readonly) NSString *offerID;
/*!
 @property quantity
 @abstract Number of individual instances of the offer item available for purchase.
 */
@property(nonatomic, assign, readonly) NSInteger quantity;
/*!
 @property price
 @abstract Price of offer item.
 */
@property(nonatomic, assign, readonly) double price;
/*!
 @property weight
 @abstract Sorting position among all offer items.
 */
@property(nonatomic, assign, readonly) NSInteger weight;
/*!
 @property isVerificationRequired
 @abstract Indicates whether customer verification is required prior to purchasing the offer item.
 */
@property(nonatomic, assign, readonly) BOOL isVerificationRequired;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_STORE_OFFER_ITEM__ */
