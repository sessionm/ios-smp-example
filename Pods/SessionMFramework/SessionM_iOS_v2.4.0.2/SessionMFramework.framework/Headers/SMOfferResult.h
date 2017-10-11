//
//  SMOfferResult.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef __SM_OFFER_RESULT__
#define __SM_OFFER_RESULT__

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMOfferResult
 @abstract Defines the data returned from a successful Offers API call.
 */
@interface SMOfferResult : NSObject

/*!
 @property extras
 @abstract Any data values that do not have an associated class property.
 */
@property(nullable, nonatomic, strong, readonly) NSDictionary<NSString *, NSObject *> *extras;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_OFFER_RESULT__ */
