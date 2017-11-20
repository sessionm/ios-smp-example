//
//  SMFetchUserOffersResponse.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef __SM_FETCH_USER_OFFERS_RESPONSE__
#define __SM_FETCH_USER_OFFERS_RESPONSE__

#import "SMOfferResponse.h"
#import "SMOfferCategory.h"
#import "SMOfferGroup.h"
#import "SMUserOfferItem.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMFetchStoreOffersResponse
 @abstract Defines the data returned from a successful @link //apple_ref/occ/instm/SMOffersManager/fetchUserOffersWithRequest:completionHandler: @/link method call.
 */
@interface SMFetchUserOffersResponse : SMOfferResponse

/*!
 @property userOffers
 @abstract The user's purchased offer items returned in the result.
 */
@property(nonatomic, strong, readonly) NSArray<SMUserOfferItem *> *userOffers;
/*!
 @property offerGroups
 @abstract Offer groups associated with the offer items in the result.
 */
@property(nonatomic, strong, readonly) NSArray<SMOfferGroup *> *offerGroups;
/*!
 @property offerCategories
 @abstract Offer categories associated with the offer items in the result.
 */
@property(nonatomic, strong, readonly) NSArray<SMOfferCategory *> *offerCategories;
/*!
 @property totalPoints
 @abstract The total number of points that have been spent by the user.
 */
@property(nonatomic, assign, readonly) NSInteger totalPoints;
/*!
 @property availablePoints
 @abstract The user's remaining point balance.
 */
@property(nonatomic, assign, readonly) NSInteger availablePoints;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_FETCH_USER_OFFERS_RESPONSE__ */
