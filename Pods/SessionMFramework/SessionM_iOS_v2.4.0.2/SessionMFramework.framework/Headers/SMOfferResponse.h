//
//  SMOfferResponse.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef __SM_OFFER_RESPONSE__
#define __SM_OFFER_RESPONSE__

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMOfferResponse
 @abstract Defines the data returned from a successful Offers API call.
 */
@interface SMOfferResponse : NSObject

/*!
 @property extras
 @abstract Any data values that do not have an associated class property.
 */
@property(nullable, nonatomic, strong, readonly) NSDictionary<NSString *, NSObject *> *extras;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_OFFER_RESPONSE__ */
