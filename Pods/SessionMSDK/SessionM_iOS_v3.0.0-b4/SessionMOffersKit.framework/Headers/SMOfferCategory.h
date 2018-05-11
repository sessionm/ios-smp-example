//
//  SMOfferCategory.h
//  SessionMOffersKit
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SM_OFFER_CATEGORY__
#define __SM_OFFER_CATEGORY__

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMOfferCategory
 @abstract Defines the data associated with a loyalty offer category.
 */
@interface SMOfferCategory : NSObject

/*!
 @property offerCategoryID
 @abstract Unique identifier for offer category.
 */
@property(nonatomic, strong, readonly) NSString *offerCategoryID;
/*!
 @property name
 @abstract Offer category name.
 */
@property(nonatomic, strong, readonly) NSString *name;
/*!
 @property offerTypes
 @abstract Offer types applicable to the offery category.
 */
@property(nonatomic, strong, readonly) NSArray<NSString *> *offerTypes;
/*!
 @property sortOrder
 @abstract Sorting position among all offer categories.
 */
@property(nonatomic, assign, readonly) NSInteger sortOrder;
/*!
 @property extras
 @abstract Any data values that do not have an associated class property.
 */
@property(nullable, nonatomic, strong, readonly) NSDictionary<NSString *, id> *extras;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_OFFER_CATEGORY__ */
