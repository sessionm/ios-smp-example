//
//  SMReferralsManager.h
//  SessionMReferralsKit
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SM_REFERRALS_MANAGER__
#define __SM_REFERRALS_MANAGER__

#import <SessionMCoreKit/SMBaseManager.h>
#import <SessionMCoreKit/SMError.h>

#import "SMReferralError.h"
#import "SMReferralRequest.h"
#import "SMReferral.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @const SM_REFERRALS_MANAGER_NOTIFICATION_ERRORS_KEY
 @abstract Used to access an <code>NSArray</code> of <code>SMReferralError</code> objects from a failed Referrals API notification's <code>userInfo</code> property.
 */
extern NSString *const SM_REFERRALS_MANAGER_NOTIFICATION_ERRORS_KEY NS_SWIFT_NAME(kReferralErrors);

/*!
 @const SM_REFERRALS_MANAGER_REQUEST_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that an API request failed.
 @discussion An <code>SMError</code> object containing information about why the request failed can be accessed from the notification's <code>userInfo</code> property with the <code>SM_MANAGER_NOTIFICATION_ERROR_KEY</code> key.
 */
extern NSString *const SM_REFERRALS_MANAGER_REQUEST_DID_FAIL_NOTIFICATION NS_SWIFT_NAME(referralsRequestFailureNotification);
/*!
 @const SM_REFERRALS_MANAGER_VALIDATION_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that a Referrals API validation failed.
 @discussion An <code>SMError</code> object containing information about why the validation failed can be accessed from the notification's <code>userInfo</code> property with the <code>SM_MANAGER_NOTIFICATION_ERROR_KEY</code> key.
 */
extern NSString *const SM_REFERRALS_MANAGER_VALIDATION_DID_FAIL_NOTIFICATION NS_SWIFT_NAME(referralsValidationFailureNotification);

/*!
 @const SM_REFERRALS_MANAGER_DID_SEND_REFERRALS_NOTIFICATION
 @abstract Notifies observers that referrals were sent.
 @discussion An <code>NSArray</code> of successfully sent <code>SMReferral</code> objects can be accessed from the notification's <code>userInfo</code> property with the <code>SM_MANAGER_NOTIFICATION_DATA_KEY</code> key. If any referral requests were denied, then an <code>NSArray</code> of <code>SMReferralError</code> objects containing information about why a particular referral was denied can be accessed with the <code>SM_REFERRALS_MANAGER_NOTIFICATION_ERRORS_KEY</code> key - and a general <code>SMError</code> object can be accessed with the <code>SM_MANAGER_NOTIFICATION_ERROR_KEY</code> key.
 */
extern NSString *const SM_REFERRALS_MANAGER_DID_SEND_REFERRALS_NOTIFICATION NS_SWIFT_NAME(sentReferralsNotification);
/*!
 @const SM_REFERRALS_MANAGER_DID_FETCH_REFERRALS_NOTIFICATION
 @abstract Notifies observers that referrals sent by the current user were fetched.
 @discussion An <code>NSArray</code> of <code>SMReferral</code> objects can be accessed from the notification's <code>userInfo</code> property with the <code>SM_MANAGER_NOTIFICATION_DATA_KEY</code> key.
 */
extern NSString *const SM_REFERRALS_MANAGER_DID_FETCH_REFERRALS_NOTIFICATION NS_SWIFT_NAME(fetchedReferralsNotification);


/*!
 @typedef didSendReferrals
 @abstract Completion handler block type for <code>sendReferrals:completionHandler:</code>.
 */
typedef void (^didSendReferrals)(NSArray<SMReferral *>* _Nullable successfulReferrals, NSArray<SMReferralError *>* _Nullable referralErrors, SMError * _Nullable error) NS_SWIFT_NAME(SendReferralsCompletionHandler);
/*!
 @typedef didFetchReferrals
 @abstract Completion handler block type for <code>fetchReferralsWithCompletionHandler:</code>.
 */
typedef void (^didFetchReferrals)(NSArray<SMReferral *>* _Nullable referrals, SMError * _Nullable error) NS_SWIFT_NAME(FetchReferralsCompletionHandler);
/*!
 @typedef didFetchSingleReferral
 @abstract Completion handler block type for <code>fetchReferralWithID:completionHandler:</code>.
 */
typedef void (^didFetchSingleReferral)(SMReferral * _Nullable referral, SMError * _Nullable error) NS_SWIFT_NAME(FetchSingleReferralCompletionHandler);


/*!
 @class SMReferralsManager
 @abstract This API manager contains methods for sending and fetching registration referral requests.
 */
@interface SMReferralsManager : SMBaseManager

/*!
 @property referrals
 @abstract Referrals that have been sent by the current user.
 @discussion This property is updated in response to a successful <code>fetchReferralsWithCompletionHandler:</code> call.
 */
@property(nonatomic, strong, readonly) NSArray<SMReferral *> *referrals;

/*!
 @abstract Makes a request to send the specified referrals.
 @param referrals The referrals request to be sent.
 @param completionHandler The block to execute after the request is processed.
 */
- (void)sendReferrals:(SMReferralsRequest *)referrals completionHandler:(didSendReferrals)completionHandler NS_SWIFT_NAME(sendReferrals(_:completionHandler:));
/*!
 @abstract Makes a request to update <code>referrals</code> with the current user's referrals.
 @param completionHandler The block to execute after the request is processed.
 */
- (void)fetchReferralsWithCompletionHandler:(didFetchReferrals)completionHandler NS_SWIFT_NAME(fetchReferrals(completionHandler:));
/*!
 @abstract Makes a request to fetch the referral with the specified identifier.
 @param referralID The identifier of the referral to be fetched.
 @param completionHandler The block to execute after the request is processed.
 */
- (void)fetchReferralWithID:(NSString *)referralID completionHandler:(didFetchSingleReferral)completionHandler NS_SWIFT_NAME(fetchReferral(havingID:completionHandler:));

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_REFERRALS_MANAGER__ */
