//
//  SMClaimUserOfferResult.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef __SM_CLAIM_USER_OFFER_RESULT__
#define __SM_CLAIM_USER_OFFER_RESULT__

#import "SMOfferResult.h"
#import "SMClaimedOfferItem.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMClaimUserOfferResult
 @abstract Defines the data returned from a successful @link //apple_ref/occ/instm/SMOffersManager/claimUserOfferWithRequest:completionHandler: @/link method call.
 */
@interface SMClaimUserOfferResult : SMOfferResult

/*!
 @property claimedOffer
 @abstract The user's claimed offer item returned in the result.
 */
@property(nonatomic, strong, readonly) SMClaimedOfferItem *claimedOffer;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_CLAIM_USER_OFFER_RESULT__ */
