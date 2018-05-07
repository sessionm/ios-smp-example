//
//  SMUserOffersFetchedResponse.h
//  SessionMOffersKit
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SM_USER_OFFERS_FETCHED_RESPONSE__
#define __SM_USER_OFFERS_FETCHED_RESPONSE__

#import "SMOffersResponse.h"
#import "SMOfferCategory.h"
#import "SMOfferGroup.h"
#import "SMUserOfferItem.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMUserOffersFetchedResponse
 @abstract Defines the data returned from a successful <code>SMOffersManager fetchUserOffersWithRequest:completionHandler:</code> method call.
 */
@interface SMUserOffersFetchedResponse : SMOffersResponse

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

#endif /* __SM_USER_OFFERS_FETCHED_RESPONSE__ */
