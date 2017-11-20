//
//  SMUserOfferItem.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef __SM_USER_OFFER_ITEM__
#define __SM_USER_OFFER_ITEM__

#import "SMOfferItem.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMUserOfferItem
 @abstract Defines the data associated with a loyalty offer item that has been purchased by a user.
 */
@interface SMUserOfferItem : SMOfferItem

/*!
 @property userOfferID
 @abstract Unique identifier for the user's instance of the purchased offer item.
 */
@property(nonatomic, strong, readonly) NSString *userOfferID;
/*!
 @property offerID
 @abstract Unique identifier that refers back to the associated store offer item.
 */
@property(nonatomic, strong, readonly) NSString *offerID;
/*!
 @property acquireDate
 @abstract Indicates when the offer item was purchased by the user.
 */
@property(nonatomic, strong, readonly) NSDate *acquireDate;
/*!
 @property expirationDate
 @abstract The date after which the offer item can no longer be redeemed by the user.
 */
@property(nullable, nonatomic, strong, readonly) NSDate *expirationDate;
/*!
 @property redeemDate
 @abstract Indicates when the offer item was redeemed by the user.
 */
@property(nullable, nonatomic, strong, readonly) NSDate *redeemDate;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_USER_OFFER_ITEM__ */
