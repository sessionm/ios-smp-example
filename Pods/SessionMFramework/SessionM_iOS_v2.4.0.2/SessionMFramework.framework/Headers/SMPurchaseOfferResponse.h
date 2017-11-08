//
//  SMPurchaseOfferResponse.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef __SM_PURCHASE_OFFER_RESPONSE__
#define __SM_PURCHASE_OFFER_RESPONSE__

#import "SMOfferResponse.h"
#import "SMUserOfferItem.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMPurchaseOfferResponse
 @abstract Defines the data returned from a successful @link //apple_ref/occ/instm/SMOffersManager/purchaseOfferWithRequest:completionHandler: @/link method call.
 */
@interface SMPurchaseOfferResponse : SMOfferResponse

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
/*!
 @property isSuccessful
 @abstract Indicates whether the offer item was purchased successfully.
 */
@property(nonatomic, assign, readonly) BOOL isSuccessful;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_PURCHASE_OFFER_RESPONSE__ */
