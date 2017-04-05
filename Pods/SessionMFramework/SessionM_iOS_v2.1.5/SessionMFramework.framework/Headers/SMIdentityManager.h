//
//  SMIdentityManager.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef __SM_IDENTITY_MANAGER__
#define __SM_IDENTITY_MANAGER__

#import "SMBaseDelegate.h"
#import "SMMMCUser.h"
#import "SMMMCUserUpdate.h"
#import "SMSVerification.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @const SM_IDENTITY_MANAGER_REQUEST_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that an API request failed.
 @discussion An @link SMError @/link object containing information about why the request failed can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_ERROR_KEY @/link key.
 */
extern NSString *const SM_IDENTITY_MANAGER_REQUEST_DID_FAIL_NOTIFICATION NS_SWIFT_NAME(identityRequestFailureNotification);
/*!
 @const SM_IDENTITY_MANAGER_VALIDATION_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that an Identity API validation failed.
 @discussion An @link SMError @/link object containing information about why the validation failed can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_ERROR_KEY @/link key.
 */
extern NSString *const SM_IDENTITY_MANAGER_VALIDATION_DID_FAIL_NOTIFICATION NS_SWIFT_NAME(identityValidationFailureNotification);

/*!
 @const SM_IDENTITY_MANAGER_DID_SEND_SMS_VERIFICATION_MESSAGE_NOTIFICATION
 @abstract Notifies observers that an SMS verification message was sent via phone number.
 @discussion An @link SMSVerification @/link object containing information about the current user's verification status can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_DATA_KEY @/link key.
 */
extern NSString *const SM_IDENTITY_MANAGER_DID_SEND_SMS_VERIFICATION_MESSAGE_NOTIFICATION NS_SWIFT_NAME(sentVerificationMessageNotification);
/*!
 @const SM_IDENTITY_MANAGER_DID_CHECK_SMS_VERIFICATION_CODE_NOTIFICATION
 @abstract Notifies observers that an SMS verification code was checked.
 @discussion An @link SMSVerification @/link object containing information about the current user's verification status can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_DATA_KEY @/link key.
 */
extern NSString *const SM_IDENTITY_MANAGER_DID_CHECK_SMS_VERIFICATION_CODE_NOTIFICATION NS_SWIFT_NAME(checkedVerificationCodeNotification);
/*!
 @const SM_IDENTITY_MANAGER_DID_FETCH_VERIFICATION_NOTIFICATION
 @abstract Notifies observers that the current user's SMS verification status was fetched.
 @discussion An @link SMSVerification @/link object containing information about the current user's verification status can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_DATA_KEY @/link key.
 */
extern NSString *const SM_IDENTITY_MANAGER_DID_FETCH_VERIFICATION_NOTIFICATION NS_SWIFT_NAME(fetchedVerificationDataNotification);

/*!
 @const SM_IDENTITY_MANAGER_DID_FETCH_MMC_USER
 @abstract Notifies observers that account data for the current user was fetched.
 @discussion An @link SMMMCUser @/link object containing information about the current user's account can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_DATA_KEY @/link key.
 */
extern NSString *const SM_IDENTITY_MANAGER_DID_FETCH_MMC_USER NS_SWIFT_NAME(fetchedMMCUserNotification);
/*!
 @const SM_IDENTITY_MANAGER_DID_UPDATE_MMC_USER
 @abstract Notifies observers that account data for the current user was updated.
 @discussion An @link SMMMCUser @/link object containing information about the current user's account can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_DATA_KEY @/link key.
 */
extern NSString *const SM_IDENTITY_MANAGER_DID_UPDATE_MMC_USER NS_SWIFT_NAME(updatedMMCUserNotification);

/*!
 @const SM_IDENTITY_MANAGER_DID_FETCH_MMC_USER_TAGS
 @abstract Notifies observers that tag data for the current user was fetched.
 @discussion An @link NSDictionary @/link object containing information about the current user's tags can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_DATA_KEY @/link key.
 */
extern NSString *const SM_IDENTITY_MANAGER_DID_FETCH_MMC_USER_TAGS NS_SWIFT_NAME(fetchedUserTagsNotification);
/*!
 @const SM_IDENTITY_MANAGER_DID_UPDATE_MMC_USER_TAGS
 @abstract Notifies observers that tag data for the current user was updated.
 @discussion An @link NSDictionary @/link object containing information about the current user's tags can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_DATA_KEY @/link key.
 */
extern NSString *const SM_IDENTITY_MANAGER_DID_UPDATE_MMC_USER_TAGS NS_SWIFT_NAME(updatedUserTagsNotification);
/*!
 @const SM_IDENTITY_MANAGER_DID_FETCH_MMC_USER_METADATA
 @abstract Notifies observers that metadata for the current user was fetched.
 @discussion An @link NSDictionary @/link object containing information about the current user's metadata can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_DATA_KEY @/link key.
 */
extern NSString *const SM_IDENTITY_MANAGER_DID_FETCH_MMC_USER_METADATA NS_SWIFT_NAME(fetchedUserMetadataNotification);
/*!
 @const SM_IDENTITY_MANAGER_DID_UPDATE_MMC_USER_METADATA
 @abstract Notifies observers that metadata for the current user was updated.
 @discussion An @link NSDictionary @/link object containing information about the current user's metadata can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_DATA_KEY @/link key.
 */
extern NSString *const SM_IDENTITY_MANAGER_DID_UPDATE_MMC_USER_METADATA NS_SWIFT_NAME(updatedUserMetadataNotification);
/*!
 @protocol SMIdentityDelegate
 @abstract Defines callbacks for @link SMIdentityManager @/link methods.
 */
@protocol SMIdentityDelegate <SMBaseDelegate>

@optional

/*!
 @abstract Notifies delegate that the current user's data was fetched.
 @discussion This method is called in response to @link fetchMMCUser @/link.
 @param user The current user's data.
 @deprecated Use block methods instead.
 */
- (void)didFetchMMCUser:(SMMMCUser *)user __attribute__((deprecated("Use block methods instead"))) NS_SWIFT_NAME(didFetchUser(_:));
/*!
 @abstract Notifies delegate that the current user's data was updated.
 @discussion This method is called in response to @link updateMMCUser: @/link.
 @param user The current user's data.
 @deprecated Use block methods instead.
 */
- (void)didUpdateMMCUser:(SMMMCUser *)user __attribute__((deprecated("Use block methods instead"))) NS_SWIFT_NAME(didUpdateUser(_:));

/*!
 @abstract Notifies delegate that the SMS message was successfully sent.
 @discussion This method is called in response to @link sendSMSVerificationMessageToPhoneNumber: @/link.
 @param verification The verification data.
 @deprecated Use block methods instead.
 */
- (void)didSendSMSVerificationMessage:(SMSVerification *)verification __attribute__((deprecated("Use block methods instead"))) NS_SWIFT_NAME(didSendVerificationMessage(verificationData:));
/*!
 @abstract Notifies delegate that the verification code validation was completed.
 @discussion This method is called in response to @link checkSMSVerificationCode: @/link.
 @param verification The verification data.
 @deprecated Use block methods instead.
 */
- (void)didCheckSMSVerificationCode:(SMSVerification *)verification __attribute__((deprecated("Use block methods instead"))) NS_SWIFT_NAME(didCheckVerificationCode(verificationData:));
/*!
 @abstract Notifies delegate that the current user's verification data was fetched.
 @discussion This method is called in response to @link fetchSMSVerification @/link.
 @param verification The verification data.
 @deprecated Use block methods instead.
 */
- (void)didFetchSMSVerification:(SMSVerification *)verification __attribute__((deprecated("Use block methods instead"))) NS_SWIFT_NAME(didFetchVerificationData(_:));

@end

/*!
 @typedef didFetchMMCUser
 @abstract Completion handler block type for @link fetchMMCUserWithCompletionHandler: @/link.
 */
typedef void (^didFetchMMCUser)(SMMMCUser * _Nullable user, SMError * _Nullable error) NS_SWIFT_NAME(FetchUserCompletionHandler);
/*!
 @typedef didUpdateMMCUser
 @abstract Completion handler block type for @link updateMMCUser:completionHandler: @/link.
 */
typedef void (^didUpdateMMCUser)(SMMMCUser * _Nullable user, SMError * _Nullable error) NS_SWIFT_NAME(UpdateUserCompletionHandler);
/*!
 @typedef verificationResponseSMS
 @abstract Completion handler block type for @link sendSMSVerificationMessageToPhoneNumber:completionHandler: @/link, @link checkSMSVerificationCode:completionHandler: @/link and @link fetchSMSVerificationWithCompletionHandler: @/link.
 */
typedef void (^verificationResponseSMS)(SMSVerification * _Nullable verification, SMError * _Nullable error) NS_SWIFT_NAME(VerificationTaskCompletionHandler);

/*!
 @typedef didFetchUserTags
 @abstract Completion handler block type for @link fetchMMCUserTagsWithCompletionHandler: @/link.
 */
typedef void (^didFetchUserTags)(NSDictionary<NSString *, NSObject *> *tags, SMError *error) NS_SWIFT_NAME(FetchUserTagsCompletionHandler);
/*!
 @typedef didUpdateMMCUserTags
 @abstract Completion handler block type for @link updateMMCUserTags:timeToLive:completionHandler: @/link.
 */
typedef void (^didUpdateMMCUserTags)(NSDictionary<NSString *, NSObject *> *tags, SMError *error) NS_SWIFT_NAME(UpdateUserTagsCompletionHandler);

/*!
 @typedef didFetchUserMetadata
 @abstract Completion handler block type for @link fetchMMCUserMetadataWithCompletionHandler: @/link.
 */
typedef void (^didFetchUserMetadata)(NSDictionary<NSString *, NSObject *> *metadata, SMError *error) NS_SWIFT_NAME(FetchUserMetadataCompletionHandler);
/*!
 @typedef didUpdateUserMetadata
 @abstract Completion handler block type for @link updateMMCUserMetadata:completionHandler: @/link.
 */
typedef void (^didUpdateUserMetadata)(NSDictionary<NSString *, NSObject *> *metadata, SMError *error) NS_SWIFT_NAME(UpdateUserMetadataCompletionHandler);

/*!
 @class SMIdentityManager
 @abstract This API manager contains methods for fetching user data, sending SMS messages with verification codes, validating verification codes, and fetching verification data.
 */
@interface SMIdentityManager : NSObject

/*!
 @property delegate
 @abstract Object that implements @link SMIdentityDelegate @/link callbacks.
 */
@property(nonatomic, weak) id<SMIdentityDelegate> _Nullable delegate;

/*!
 @abstract Makes a request to fetch the current user's data.
 @discussion @link didFetchMMCUser: @/link is called in response to this method.
 @result <code>BOOL</code> indicating whether the request will be sent.
 @deprecated Use @link fetchMMCUserWithCompletionHandler: @/link.
 */
- (BOOL)fetchMMCUser __attribute__((deprecated("Use fetchMMCUserWithCompletionHandler:"))) NS_SWIFT_NAME(fetchUser());
/*!
 @abstract Makes a request to fetch the current user's data.
 @param completionHandler The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)fetchMMCUserWithCompletionHandler:(didFetchMMCUser)completionHandler NS_SWIFT_NAME(fetchUser(completionHandler:));

/*!
 @abstract Makes a request to update the current user's data.
 @discussion @link didUpdateMMCUser: @/link is called in response to this method.
 @param updates Data changes to make.
 @result <code>BOOL</code> indicating whether the request will be sent.
 @deprecated Use @link updateMMCUser:completionHandler: @/link.
 */
- (BOOL)updateMMCUser:(SMMMCUserUpdate *)updates __attribute__((deprecated("Use updateMMCUser:completionHandler:"))) NS_SWIFT_NAME(updateUser(updates:));
/*!
 @abstract Makes a request to update the current user's data.
 @param updates Data changes to make.
 @param completionHandler The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)updateMMCUser:(SMMMCUserUpdate *)updates completionHandler:(didUpdateMMCUser)completionHandler NS_SWIFT_NAME(updateUser(updates:completionHandler:));
/*!
 @abstract Makes a request to fetch the current user's tag data.
 @param completionHandler The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)fetchMMCUserTagsWithCompletionHandler:(didFetchUserTags)completionHandler NS_SWIFT_NAME(fetchUserTags(completionHandler:));
/*!
 @abstract Makes a request to update the current user's tag data.
 @param updates Data changes to make.
 @param timeToLive How long this change will be in effect on the server.
 @result <code>BOOL</code> indicating whether the request will be sent.
 @deprecated Use @link updateMMCUser:completionHandler: @/link.
 */
- (BOOL)updateMMCUserTags:(NSArray<NSString *> *)updates timeToLive:(NSInteger)timeToLive completionHandler:(didUpdateMMCUserTags)completionHandler NS_SWIFT_NAME(updateUserTags(updates:timeToLive:completionHandler:));

/*!
 @abstract Makes a request to fetch the current user's metadata.
 @param completionHandler The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)fetchMMCUserMetadataWithCompletionHandler:(didFetchUserMetadata)completionHandler NS_SWIFT_NAME(fetchUserMetadata(completionHandler:));
/*!
 @abstract Makes a request to update the current user's metadata.
 @param updates Data changes to make.
 @param completionHandler The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)updateMMCUserMetadata:(NSDictionary<NSString *, NSObject *> *)updates completionHandler:(didUpdateUserMetadata)completionHandler NS_SWIFT_NAME(updateUserMetadata(updates:completionHandler:));
/*!
 @abstract Makes a request to send an SMS verification message to the specified phone number.
 @discussion @link didSendSMSVerificationMessage: @/link is called in response to this method.
 @param phoneNumber The phone number to which the SMS message will be sent.
 @result <code>BOOL</code> indicating whether the request will be sent.
 @deprecated Use @link sendSMSVerificationMessageToPhoneNumber:completionHandler: @/link.
 */
- (BOOL)sendSMSVerificationMessageToPhoneNumber:(NSString *)phoneNumber __attribute__((deprecated("Use sendSMSVerificationMessageToPhoneNumber:completionHandler:"))) NS_SWIFT_NAME(sendVerificationMessage(toPhoneNumber:));
/*!
 @abstract Makes a request to send an SMS verification message to the specified phone number.
 @param phoneNumber The phone number to which the SMS message will be sent.
 @param completionHandler The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)sendSMSVerificationMessageToPhoneNumber:(NSString *)phoneNumber completionHandler:(verificationResponseSMS)completionHandler NS_SWIFT_NAME(sendVerificationMessage(toPhoneNumber:completionHandler:));
/*!
 @abstract Makes a request to validate the specified verification code.
 @discussion @link didCheckSMSVerificationCode: @/link is called in response to this method.
 @param code The verification code to validate.
 @result <code>BOOL</code> indicating whether the request will be sent.
 @deprecated Use @link checkSMSVerificationCode:completionHandler: @/link.
 */
- (BOOL)checkSMSVerificationCode:(NSString *)code __attribute__((deprecated("Use checkSMSVerificationCode:completionHandler:"))) NS_SWIFT_NAME(checkVerificationCode(_:));
/*!
 @abstract Makes a request to validate the specified verification code.
 @param code The verification code to validate.
 @param completionHandler The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)checkSMSVerificationCode:(NSString *)code completionHandler:(verificationResponseSMS)completionHandler NS_SWIFT_NAME(checkVerificationCode(_:completionHandler:));
/*!
 @abstract Makes a request to fetch the current user's verification data.
 @discussion @link didFetchSMSVerification: @/link is called in response to this method.
 @result <code>BOOL</code> indicating whether the request will be sent.
 @deprecated Use @link fetchSMSVerificationWithCompletionHandler: @/link.
 */
- (BOOL)fetchSMSVerification __attribute__((deprecated("Use fetchSMSVerificationWithCompletionHandler:"))) NS_SWIFT_NAME(fetchVerificationData());
/*!
 @abstract Makes a request to fetch the current user's verification data.
 @param completionHandler The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)fetchSMSVerificationWithCompletionHandler:(verificationResponseSMS)completionHandler NS_SWIFT_NAME(fetchVerificationData(completionHandler:));

@end

NS_ASSUME_NONNULL_END

#endif /* SM_IDENTITY_MANAGER */
