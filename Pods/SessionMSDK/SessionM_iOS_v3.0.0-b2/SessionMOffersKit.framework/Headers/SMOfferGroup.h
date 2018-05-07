//
//  SMOfferGroup.h
//  SessionMOffersKit
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SM_OFFER_GROUP__
#define __SM_OFFER_GROUP__

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMOfferGroup
 @abstract Defines the data associated with a loyalty offer group.
 */
@interface SMOfferGroup : NSObject

/*!
 @property offerGroupID
 @abstract Unique identifier for offer group.
 */
@property(nonatomic, strong, readonly) NSString *offerGroupID;
/*!
 @property name
 @abstract Offer group name.
 */
@property(nonatomic, strong, readonly) NSString *name;
/*!
 @property sortOrder
 @abstract Sorting position among all offer groups.
 */
@property(nonatomic, assign, readonly) NSInteger sortOrder;
/*!
 @property extras
 @abstract Any data values that do not have an associated class property.
 */
@property(nullable, nonatomic, strong, readonly) NSDictionary<NSString *, id> *extras;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_OFFER_GROUP__ */
