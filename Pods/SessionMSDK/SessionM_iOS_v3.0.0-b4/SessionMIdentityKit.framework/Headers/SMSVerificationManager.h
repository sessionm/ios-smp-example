//
//  SMSVerificationManager.h
//  SessionMIdentityKit
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SMS_VERIFICATION_MANAGER__
#define __SMS_VERIFICATION_MANAGER__

#import <SessionMCoreKit/SMBaseManager.h>
#import <SessionMCoreKit/SMError.h>

#import "SMSVerification.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @const SMS_VERIFICATION_MANAGER_REQUEST_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that an SMS Verification API request failed.
 @discussion An <code>SMError</code> object containing information about why the request failed can be accessed from the notification's <code>userInfo</code> property with the <code>SM_MANAGER_NOTIFICATION_ERROR_KEY</code> key.
 */
extern NSString *const SMS_VERIFICATION_MANAGER_REQUEST_DID_FAIL_NOTIFICATION NS_SWIFT_NAME(smsVerificationRequestFailureNotification);
/*!
 @const SMS_VERIFICATION_MANAGER_VALIDATION_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that an SMS Verification API validation failed.
 @discussion An <code>SMError</code> object containing information about why the validation failed can be accessed from the notification's <code>userInfo</code> property with the <code>SM_MANAGER_NOTIFICATION_ERROR_KEY</code> key.
 */
extern NSString *const SMS_VERIFICATION_MANAGER_VALIDATION_DID_FAIL_NOTIFICATION NS_SWIFT_NAME(smsVerificationValidationFailureNotification);
/*!
 @const SMS_VERIFICATION_MANAGER_DID_SEND_SMS_VERIFICATION_MESSAGE_NOTIFICATION
 @abstract Notifies observers that an SMS verification message was sent via phone number.
 @discussion An <code>SMSVerification</code> object containing information about the current user's verification status can be accessed from the notification's <code>userInfo</code> property with the <code>SM_MANAGER_NOTIFICATION_DATA_KEY</code> key.
 */
extern NSString *const SMS_VERIFICATION_MANAGER_DID_SEND_SMS_VERIFICATION_MESSAGE_NOTIFICATION NS_SWIFT_NAME(sentVerificationMessageNotification);
/*!
 @const SMS_VERIFICATION_MANAGER_DID_CHECK_SMS_VERIFICATION_CODE_NOTIFICATION
 @abstract Notifies observers that an SMS verification code was checked.
 @discussion An <code>SMSVerification</code> object containing information about the current user's verification status can be accessed from the notification's <code>userInfo</code> property with the <code>SM_MANAGER_NOTIFICATION_DATA_KEY</code> key.
 */
extern NSString *const SMS_VERIFICATION_MANAGER_DID_CHECK_SMS_VERIFICATION_CODE_NOTIFICATION NS_SWIFT_NAME(checkedVerificationCodeNotification);
/*!
 @const SMS_VERIFICATION_MANAGER_DID_FETCH_VERIFICATION_NOTIFICATION
 @abstract Notifies observers that the current user's SMS verification status was fetched.
 @discussion An <code>SMSVerification</code> object containing information about the current user's verification status can be accessed from the notification's <code>userInfo</code> property with the <code>SM_MANAGER_NOTIFICATION_DATA_KEY</code> key.
 */
extern NSString *const SMS_VERIFICATION_MANAGER_DID_FETCH_VERIFICATION_NOTIFICATION NS_SWIFT_NAME(fetchedVerificationDataNotification);


/*!
 @typedef verificationResponseSMS
 @abstract Completion handler block type for <code>sendSMSVerificationMessageToPhoneNumber:completionHandler:</code>, <code>checkSMSVerificationCode:completionHandler:</code> and <code>fetchSMSVerificationWithCompletionHandler:</code>.
 */
typedef void (^verificationResponseSMS)(SMSVerification * _Nullable verification, SMError * _Nullable error) NS_SWIFT_NAME(VerificationTaskCompletionHandler);


/*!
 @class SMSVerificationManager
 @abstract This API manager contains methods for sending SMS messages with verification codes, validating verification codes, and fetching verification data.
 */
@interface SMSVerificationManager : SMBaseManager

/*!
 @abstract Makes a request to send an SMS verification message to the specified phone number.
 @param phoneNumber The phone number to which the SMS message will be sent.
 @param completionHandler The block to execute after the request is processed.
 */
- (void)sendSMSVerificationMessageToPhoneNumber:(NSString *)phoneNumber completionHandler:(verificationResponseSMS)completionHandler NS_SWIFT_NAME(sendVerificationMessage(toPhoneNumber:completionHandler:));
/*!
 @abstract Makes a request to validate the specified verification code.
 @param code The verification code to validate.
 @param completionHandler The block to execute after the request is processed.
 */
- (void)checkSMSVerificationCode:(NSString *)code completionHandler:(verificationResponseSMS)completionHandler NS_SWIFT_NAME(checkVerificationCode(_:completionHandler:));
/*!
 @abstract Makes a request to fetch the current user's verification data.
 @param completionHandler The block to execute after the request is processed.
 */
- (void)fetchSMSVerificationWithCompletionHandler:(verificationResponseSMS)completionHandler NS_SWIFT_NAME(fetchVerificationData(completionHandler:));

@end

NS_ASSUME_NONNULL_END

#endif /* __SMS_VERIFICATION_MANAGER__ */
