//
//  SMPurchaseOfferResult.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef __SM_PURCHASE_OFFER_RESULT__
#define __SM_PURCHASE_OFFER_RESULT__

#import "SMOfferResult.h"
#import "SMUserOfferItem.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMPurchaseOfferResult
 @abstract Defines the data returned from a successful @link //apple_ref/occ/instm/SMOffersManager/purchaseOfferWithRequest:completionHandler: @/link method call.
 */
@interface SMPurchaseOfferResult : SMOfferResult

/*!
 @property userOffer
 @abstract The user's purchased offer item returned in the result.
 */
@property(nonatomic, strong, readonly) SMUserOfferItem *userOffer;
/*!
 @property pointsRemaining
 @abstract The user's remaining point balance after purchasing the offer item.
 */
@property(nonatomic, assign, readonly) NSInteger pointsRemaining;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_PURCHASE_OFFER_RESULT__ */
