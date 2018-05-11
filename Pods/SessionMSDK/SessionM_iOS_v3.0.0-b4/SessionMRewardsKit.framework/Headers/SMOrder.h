//
//  SMOrder.h
//  SessionMRewardKit
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SM_ORDER__
#define __SM_ORDER__

#import <SessionMCoreKit/SMAddress.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @typedef SMOrderStatus
 @abstract Order redemption status.

 @constant SMOrderStatusUnknown Order status is unknown.
 @constant SMOrderStatusApproved Order is approved.
 @constant SMOrderStatusRejected Order redemption was rejected by Customer Care Team (e.g. due to Terms of Service violation).
 @constant SMOrderStatusPending Order is pending review.
 @constant SMOrderStatusRedemptionError Error was received while attempting to redeem order.
 */
typedef NS_ENUM(NSInteger, SMOrderStatus) {
    SMOrderStatusUnknown NS_SWIFT_NAME(unknown),
    SMOrderStatusApproved NS_SWIFT_NAME(approved),
    SMOrderStatusRejected NS_SWIFT_NAME(rejected),
    SMOrderStatusPending NS_SWIFT_NAME(pending),
    SMOrderStatusRedemptionError NS_SWIFT_NAME(redemptionError)
};


/*!
 @class SMOrderUser
 @abstract Defines the data associated with a user who made an offer order.
 */
@interface SMOrderUser : NSObject

/*!
 @property userID
 @abstract ID of user who made the order.
 */
@property(nonnull, nonatomic, strong, readonly) NSString *userID;
/*!
 @property availablePoints
 @abstract User's current loyalty points balance.
 */
@property(nonatomic, assign, readonly) NSInteger availablePoints;
/*!
 @property testPoints
 @abstract The number of loyalty points that the user has earned from apps that are in development mode.
 */
@property(nonatomic, assign, readonly) NSInteger testPoints;

@end


/*!
 @class SMOrder
 @abstract Defines the data associated with an offer order made by a user.
 */
@interface SMOrder : NSObject

/*!
 @property orderID
 @abstract Unique ID for order.
 */
@property(nonnull, nonatomic, strong, readonly) NSString *orderID;
@property(nullable, nonatomic, strong, readonly) NSString *offerType;
@property(nullable, nonatomic, strong, readonly) NSString *userID;
@property(nullable, nonatomic, strong, readonly) NSString *externalID;
/*!
 @property offerID
 @abstract ID of offer that was redeemed.
 */
@property(nonnull, nonatomic, strong, readonly) NSString *offerID;
/*!
 @property user
 @abstract Data associated with the user who made the order.
 */
@property(nullable, nonatomic, strong, readonly) SMOrderUser *user;
/*!
 @property quantity
 @abstract Amount of items redeemed in the order.
 */
@property(nonatomic, assign, readonly) NSInteger quantity;
/*!
 @property points
 @abstract Amount of points spent in the order.
 */
@property(nonatomic, assign, readonly) NSInteger points;
/*!
 @property createdTime
 @abstract Indicates when the order was created.
 */
@property(nullable, nonatomic, strong, readonly) NSString *createdTime;
/*!
 @property name
 @abstract Name of offer redeemed in the order.
 */
@property(nullable, nonatomic, strong, readonly) NSString *name;
/*!
 @property logoURL
 @abstract URL to image associated with the offer redeemed in the order.
 */
@property(nullable, nonatomic, strong, readonly) NSString *logoURL;
/*!
 @property details
 @abstract Description of offer redeemed in the order.
 */
@property(nullable, nonatomic, strong, readonly) NSString *details;
/*!
 @property descriptionText
 @abstract Description of offer redeemed in the order.
 @deprecated This property has been deprecated - use <code>details</code> instead.@deprecated This property has been deprecated - use <code>details</code> instead.
 */
@property(nullable, nonatomic, strong, readonly) NSString *descriptionText __attribute__((deprecated));
/*!
 @property shippingAddress
 @abstract Where physical items will be shipped after the order is processed.
 */
@property(nullable, nonatomic, strong, readonly) SMAddress *shippingAddress;
/*!
 @property data
 @abstract Contains voucher data associated with order.
 */
@property(nullable, nonatomic, strong, readonly) NSDictionary<NSString *, id> *data;
/*!
 @property status
 @abstract Order redemption status.
 */
@property(nonatomic, assign, readonly) SMOrderStatus status;
/*!
 @property extras
 @abstract Any data values that do not have an associated class property.
 */
@property(nullable, nonatomic, strong, readonly) NSDictionary<NSString *, id> *extras;

/*!
 @abstract Converts current order status to the corresponding string value.
 @result <code>NSString</code> value.
 */
- (NSString *)stringForCurrentStatus NS_SWIFT_NAME(stringFromCurrentStatus());

/*!
 @abstract Converts specified string value to the corresponding <code>SMOrderStatus</code> enum value.
 @param string String to convert.
 @result <code>SMOrderStatus</code> enum value.
 */
+ (SMOrderStatus)statusForString:(NSString *)string NS_SWIFT_NAME(orderStatus(from:));
/*!
 @abstract Converts specified <code>SMOrderStatus</code> enum value to the corresponding string value.
 @param status Status to convert.
 @result <code>NSString</code> value.
 */
+ (NSString *)stringForStatus:(SMOrderStatus)status NS_SWIFT_NAME(string(from:));

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_ORDER__ */
