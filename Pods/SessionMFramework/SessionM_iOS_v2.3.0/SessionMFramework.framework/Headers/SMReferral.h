//
//  SMReferral.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef __SM_REFERRAL__
#define __SM_REFERRAL__

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @typedef SMReferralStatus
 @abstract Member referral status.

 @constant SMReferralStatusUnknown Referral status is unknown.
 @constant SMReferralStatusPending Referral is pending engagement by the referee.
 @constant SMReferralStatusEngaged Referee engaged with the referral.
 @constant SMReferralStatusRegistered Referee registered an account.
 @constant SMReferralStatusConverted Referrer received loyalty points for the referral.
 @constant SMReferralStatusLimitPeriod Referrer reached the referral limit for the current period - conversion will award 0 loyalty points.
 @constant SMReferralStatusLimitLifetime Referrer reached the lifetime referral limit - conversion will award 0 loyalty points.
 @constant SMReferralStatusVoided Referral was voided due to referee registering for an account through other means.
 */
typedef NS_ENUM(NSInteger, SMReferralStatus) {
    SMReferralStatusUnknown NS_SWIFT_NAME(unknown),
    SMReferralStatusPending NS_SWIFT_NAME(pending),
    SMReferralStatusEngaged NS_SWIFT_NAME(engaged),
    SMReferralStatusRegistered NS_SWIFT_NAME(registered),
    SMReferralStatusConverted NS_SWIFT_NAME(converted),
    SMReferralStatusLimitPeriod NS_SWIFT_NAME(limitPeriod),
    SMReferralStatusLimitLifetime NS_SWIFT_NAME(limitLifetime),
    SMReferralStatusVoided NS_SWIFT_NAME(voided)
};


/*!
 @class SMReferral
 @abstract Defines the data associated with a registration referral.
 */
@interface SMReferral : NSObject

/*!
 @property referralID
 @abstract Unique ID for referral.
 */
@property(nonnull, nonatomic, strong, readonly) NSString *referralID;
/*!
 @property referee
 @abstract Name of person being referred.
 */
@property(nullable, nonatomic, strong, readonly) NSString *referee;
/*!
 @property referrer
 @abstract Name of person who sent the referral.
 */
@property(nullable, nonatomic, strong, readonly) NSString *referrer;
/*!
 @property email
 @abstract Referee's email address.
 */
@property(nullable, nonatomic, strong, readonly) NSString *email;
/*!
 @property phoneNumber
 @abstract Referee's phone number.
 */
@property(nullable, nonatomic, strong, readonly) NSString *phoneNumber;
/*!
 @property origin
 @abstract Referral origin.
 */
@property(nullable, nonatomic, strong, readonly) NSString *origin;
/*!
 @property source
 @abstract Referral source.
 */
@property(nullable, nonatomic, strong, readonly) NSString *source;
/*!
 @property pendingTime
 @abstract Indicates when referral was created.
 */
@property(nullable, nonatomic, strong, readonly) NSString *pendingTime;
/*!
 @property engagedTime
 @abstract Indicates when referee engaged with the referral.
 */
@property(nullable, nonatomic, strong, readonly) NSString *engagedTime;
/*!
 @property registeredTime
 @abstract Indicates when referee registered for an account.
 */
@property(nullable, nonatomic, strong, readonly) NSString *registeredTime;
/*!
 @property convertedTime
 @abstract Indicates when referrer received loyalty points for the referral.
 */
@property(nullable, nonatomic, strong, readonly) NSString *convertedTime;
/*!
 @property voidedTime
 @abstract Indicates when referral was voided due to referee registering for an account through other means.
 */
@property(nullable, nonatomic, strong, readonly) NSString *voidedTime;
/*!
 @property clientData
 @abstract Opaque developer-defined data.
 */
@property(nullable, nonatomic, strong, readonly) id clientData;
/*!
 @property conversionPoints
 @abstract The number of points the referrer will or did receive when the referee registers for an account.
 */
@property(nonatomic, assign, readonly) NSInteger conversionPoints;
/*!
 @property status
 @abstract Referral status.
 */
@property(nonatomic, assign, readonly) SMReferralStatus status;
/*!
 @property extras
 @abstract Any data values that do not have an associated class property.
 */
@property(nullable, nonatomic, strong, readonly) NSDictionary<NSString *, NSObject *> *extras;

/*!
 @abstract Converts specified string value to the corresponding @link SMReferralStatus @/link enum value.
 @param string String to convert.
 @result @link SMReferralStatus @/link enum value.
 */
+ (SMReferralStatus)statusForString:(NSString *)string NS_SWIFT_NAME(referralStatus(from:));
/*!
 @abstract Converts specified @link SMReferralStatus @/link enum value to the corresponding string value.
 @param status Status to convert.
 @result <code>NSString</code> value.
 */
+ (NSString *)stringForStatus:(SMReferralStatus)status NS_SWIFT_NAME(string(from:));

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_REFERRAL__ */
