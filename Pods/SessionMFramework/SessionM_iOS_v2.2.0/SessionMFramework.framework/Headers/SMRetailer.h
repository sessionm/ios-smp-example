//
//  SMRetailer.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef __SM_RETAILER__
#define __SM_RETAILER__

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMRetailer
 @abstract Defines the data associated with a retailer that has a loyalty program.
 */
@interface SMRetailer : NSObject

/*!
 @property retailerID
 @abstract Unique ID for retailer.
 */
@property(nonnull, nonatomic, strong, readonly) NSString *retailerID;
/*!
 @property name
 @abstract Retailer name.
 */
@property(nullable, nonatomic, strong, readonly) NSString *name;
/*!
 @property card
 @abstract Loyalty card name.
 */
@property(nullable, nonatomic, strong, readonly) NSString *card;
/*!
 @property icon
 @abstract URL for retailer thumbnail icon.
 */
@property(nullable, nonatomic, strong, readonly) NSString *iconURL;
/*!
 @property image
 @abstract URL for retailer banner image.
 */
@property(nullable, nonatomic, strong, readonly) NSString *imageURL;
/*!
 @property isLinked
 @abstract Indicates whether the current user has linked a loyalty card issued by the retailer.
 */
@property(nonatomic, assign, readonly) BOOL      isLinked;
/*!
 @property extras
 @abstract Any data values that do not have an associated class property.
 */
@property(nullable, nonatomic, strong, readonly) NSDictionary<NSString *, NSObject *> *extras;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_RETAILER__ */
