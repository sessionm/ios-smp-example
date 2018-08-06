//
//  SMOfferPurchasedResponse.h
//  SessionMOffersKit
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SM_OFFER_PURCHASED_RESPONSE__
#define __SM_OFFER_PURCHASED_RESPONSE__

#import "SMOffersResponse.h"
#import "SMUserOfferItem.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMOfferPurchasedResponse
 @abstract Defines the data returned from a successful <code>SMOffersManager purchaseOfferWithRequest:completionHandler:</code> method call.
 */
@interface SMOfferPurchasedResponse : SMOffersResponse

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

#endif /* __SM_OFFER_PURCHASED_RESPONSE__ */
