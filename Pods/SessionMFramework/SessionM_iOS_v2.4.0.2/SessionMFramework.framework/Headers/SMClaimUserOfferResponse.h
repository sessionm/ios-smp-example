//
//  SMClaimUserOfferResponse.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef __SM_CLAIM_USER_OFFER_RESPONSE__
#define __SM_CLAIM_USER_OFFER_RESPONSE__

#import "SMOfferResponse.h"
#import "SMClaimedOfferItem.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMClaimUserOfferResponse
 @abstract Defines the data returned from a successful @link //apple_ref/occ/instm/SMOffersManager/claimUserOfferWithRequest:completionHandler: @/link method call.
 */
@interface SMClaimUserOfferResponse : SMOfferResponse

/*!
 @property claimedOffer
 @abstract The user's claimed offer item returned in the result.
 */
@property(nonatomic, strong, readonly) SMClaimedOfferItem *claimedOffer;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_CLAIM_USER_OFFER_RESPONSE__ */
