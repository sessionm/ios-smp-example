//
//  SMClaimedOfferItem.h
//  SessionM
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SM_CLAIMED_OFFER_ITEM__
#define __SM_CLAIMED_OFFER_ITEM__

#import "SMUserOfferItem.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMClaimedOfferItem
 @abstract Defines the data associated with a loyalty offer item that has been claimed for redemption by a user.
 */
@interface SMClaimedOfferItem : SMUserOfferItem

/*!
 @property code
 @abstract A redemption code that the user can use to redeem the offer item.
 */
@property(nonatomic, strong, readonly) NSString *code;
/*!
 @property codeImageURI
 @abstract A URI that points to a barcode image that represents a redemption code that the user can use to redeem the offer item.
 */
@property(nonatomic, strong, readonly) NSString *codeImageURI;
/*!
 @property codeCreationTime
 @abstract Indicates when the redemption code was created.
 */
@property(nonatomic, strong, readonly) NSDate *codeCreationTime;
/*!
 @property codeExpirationTime
 @abstract The date after which the redemption code can no longer be used to redeem the offer item.
 */
@property(nonatomic, strong, readonly) NSDate *codeExpirationTime;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_CLAIMED_OFFER_ITEM__ */
