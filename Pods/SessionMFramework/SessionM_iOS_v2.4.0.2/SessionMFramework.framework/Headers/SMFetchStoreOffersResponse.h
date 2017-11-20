//
//  SMFetchStoreOffersResponse.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef __SM_FETCH_STORE_OFFERS_RESPONSE__
#define __SM_FETCH_STORE_OFFERS_RESPONSE__

#import "SMOfferResponse.h"
#import "SMOfferCategory.h"
#import "SMOfferGroup.h"
#import "SMStoreOfferItem.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMFetchStoreOffersResponse
 @abstract Defines the data returned from a successful @link //apple_ref/occ/instm/SMOffersManager/fetchStoreOffersWithRequest:completionHandler: @/link method call.
 */
@interface SMFetchStoreOffersResponse : SMOfferResponse

/*!
 @property offers
 @abstract The offer items returned in the result.
 */
@property(nonatomic, strong, readonly) NSArray<SMStoreOfferItem *> *offers;
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

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_FETCH_STORE_OFFERS_RESPONSE__ */
