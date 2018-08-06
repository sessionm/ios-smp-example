//
//  SMOffersResponse.h
//  SessionMOffersKit
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SM_OFFERS_RESPONSE__
#define __SM_OFFERS_RESPONSE__

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMOffersResponse
 @abstract Defines the data returned from a successful Offers API call.
 */
@interface SMOffersResponse : NSObject

/*!
 @property extras
 @abstract Any data values that do not have an associated class property.
 */
@property(nullable, nonatomic, strong, readonly) NSDictionary<NSString *, id> *extras;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_OFFERS_RESPONSE__ */
