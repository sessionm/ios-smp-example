//
//  SMUserOfferClaimedResponse.h
//  SessionM
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SM_USER_OFFER_CLAIMED_RESPONSE__
#define __SM_USER_OFFER_CLAIMED_RESPONSE__

#import "SMOffersResponse.h"
#import "SMClaimedOfferItem.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMUserOfferClaimedResponse
 @abstract Defines the data returned from a successful @link //apple_ref/occ/instm/SMOffersManager/claimUserOfferWithRequest:completionHandler: @/link method call.
 */
@interface SMUserOfferClaimedResponse : SMOffersResponse

/*!
 @property claimedOffer
 @abstract The user's claimed offer item returned in the result.
 */
@property(nonatomic, strong, readonly) SMClaimedOfferItem *claimedOffer;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_USER_OFFER_CLAIMED_RESPONSE__ */
