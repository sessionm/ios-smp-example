//
//  SMLoyaltyCard.h
//  SessionM
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SM_LOYALTY_CARD__
#define __SM_LOYALTY_CARD__

#import "SMRetailer.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMLoyaltyCard
 @abstract Defines the data associated with a loyalty card that has been linked with a user's account.
 */
@interface SMLoyaltyCard : NSObject

/*!
 @property cardID
 @abstract Unique ID for loyalty card.
 */
@property(nonnull, nonatomic, strong, readonly) NSString *cardID;
/*!
 @property cardNumber
 @abstract Number associated with loyalty card (issued by retailer).
 */
@property(nullable, nonatomic, strong, readonly) NSString *cardNumber;
/*!
 @property retailer
 @abstract Retailer associated with loyalty card.
 */
@property(nullable, nonatomic, strong, readonly) SMRetailer *retailer;
/*!
 @property isLinked
 @abstract Indicates whether the current user has linked a loyalty card issued by the associated retailer.
 */
@property(nonatomic, assign, readonly) BOOL isLinked;
/*!
 @property extras
 @abstract Any data values that do not have an associated class property.
 */
@property(nullable, nonatomic, strong, readonly) NSDictionary<NSString *, id> *extras;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_LOYALTY_CARD__ */
