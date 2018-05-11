//
//  SMSVerification.h
//  SessionMIdentityKit
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SMS_VERIFICATION__
#define __SMS_VERIFICATION__

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @typedef SMSVerificationStatus
 @abstract User verification status.

 @constant SMSVerificationStatusUnknown Verification status is unknown.
 @constant SMSVerificationStatusValid Verification code was approved and user is verified.
 @constant SMSVerificationStatusPending Verification code is pending validation.
 @constant SMSVerificationStatusInvalid Verification code was rejected.
 @constant SMSVerificationStatusExpired Verification code is expired, need to re-issue.
 */
typedef NS_ENUM(NSInteger, SMSVerificationStatus) {
    SMSVerificationStatusUnknown NS_SWIFT_NAME(unknown),
    SMSVerificationStatusValid NS_SWIFT_NAME(valid),
    SMSVerificationStatusPending NS_SWIFT_NAME(pending),
    SMSVerificationStatusInvalid NS_SWIFT_NAME(invalid),
    SMSVerificationStatusExpired NS_SWIFT_NAME(expired)
};


/*!
 @class SMSVerification
 @abstract Defines the data associated with a user's verification request.
 */
@interface SMSVerification : NSObject

/*!
 @property verificationID
 @abstract Unique ID for verification.
 */
@property(nonnull, nonatomic, strong, readonly) NSString *verificationID;
/*!
 @property status
 @abstract User verification status.
 */
@property(nonatomic, assign, readonly) SMSVerificationStatus status;
/*!
 @property mode
 @abstract Medium used to send verification code to user (e.g. "sms").
 */
@property(nullable, nonatomic, strong, readonly) NSString *mode;
/*!
 @property extras
 @abstract Any data values that do not have an associated class property.
 */
@property(nullable, nonatomic, strong, readonly) NSDictionary<NSString *, id> *extras;

/*!
 @abstract Converts specified string value to the corresponding <code>SMSVerificationStatus</code> enum value.
 @param string String to convert.
 @result <code>SMSVerificationStatus</code> enum value.
 */
+ (SMSVerificationStatus)statusForString:(NSString *)string NS_SWIFT_NAME(verificationStatus(from:));
/*!
 @abstract Converts specified <code>SMSVerificationStatus</code> enum value to the corresponding string value.
 @param status Status to convert.
 @result <code>NSString</code> value.
 */
+ (NSString *)stringForStatus:(SMSVerificationStatus)status NS_SWIFT_NAME(string(from:));

@end

NS_ASSUME_NONNULL_END

#endif /* __SMS_VERIFICATION__ */
