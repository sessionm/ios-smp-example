//
//  SMOfferItem.h
//  SessionMOffersKit
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SM_OFFER_ITEM__
#define __SM_OFFER_ITEM__

#import <Foundation/Foundation.h>
#import "SMOfferMedia.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMOfferItem
 @abstract Defines the data associated with a loyalty offer item.
 */
@interface SMOfferItem : NSObject

/*!
 @property offerGroupID
 @abstract Identifier of the offer group to which the offer item belongs.
 */
@property(nonatomic, strong, readonly) NSString *offerGroupID;
/*!
 @property offerType
 @abstract Description of the offer item's offer type (e.g. "fixed_amount_discount" or "percent_discount").
 */
@property(nonatomic, strong, readonly) NSString *offerType;
/*!
 @property name
 @abstract Offer item name.
 */
@property(nonatomic, strong, readonly) NSString *name;
/*!
 @property details
 @abstract Offer item description.
 */
@property(nonatomic, strong, readonly) NSString *details;
/*!
 @property terms
 @abstract Terms of service for the offer item.
 */
@property(nonatomic, strong, readonly) NSString *terms;
/*!
 @property startDate
 @abstract Indicates when the offer item became available for purchase.
 */
@property(nonatomic, strong, readonly) NSDate *startDate;
/*!
 @property endDate
 @abstract The date after which the offer item will no longer be available for purchase.
 */
@property(nullable, nonatomic, strong, readonly) NSDate *endDate;
/*!
 @property media
 @abstract Media content items applicable to the offer item.
 */
@property(nonatomic, strong, readonly) NSArray<SMOfferMedia *> *media;
/*!
 @property isRedeemable
 @abstract Indicates whether the offer item can currently be redeemed.
 */
@property(nonatomic, assign, readonly) BOOL isRedeemable;
/*!
 @property extras
 @abstract Any data values that do not have an associated class property.
 */
@property(nullable, nonatomic, strong, readonly) NSDictionary<NSString *, id> *extras;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_OFFER_ITEM__ */
