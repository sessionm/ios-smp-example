//
//  SMReferralsManager.h
//  SessionM
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SM_REFERRALS_MANAGER__
#define __SM_REFERRALS_MANAGER__

#import "SMBaseDelegate.h"
#import "SMReferralError.h"
#import "SMReferralRequest.h"
#import "SMReferral.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @const SM_REFERRALS_MANAGER_NOTIFICATION_ERRORS_KEY
 @abstract Used to access an <code>NSArray</code> of @link SMReferralError @/link objects from a failed Referrals API notification's <code>userInfo</code> property.
 */
extern NSString *const SM_REFERRALS_MANAGER_NOTIFICATION_ERRORS_KEY NS_SWIFT_NAME(kReferralErrors);

/*!
 @const SM_REFERRALS_MANAGER_REQUEST_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that an API request failed.
 @discussion An @link SMError @/link object containing information about why the request failed can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_ERROR_KEY @/link key.
 */
extern NSString *const SM_REFERRALS_MANAGER_REQUEST_DID_FAIL_NOTIFICATION NS_SWIFT_NAME(referralsRequestFailureNotification);
/*!
 @const SM_REFERRALS_MANAGER_VALIDATION_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that a Referrals API validation failed.
 @discussion An @link SMError @/link object containing information about why the validation failed can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_ERROR_KEY @/link key.
 */
extern NSString *const SM_REFERRALS_MANAGER_VALIDATION_DID_FAIL_NOTIFICATION NS_SWIFT_NAME(referralsValidationFailureNotification);

/*!
 @const SM_REFERRALS_MANAGER_DID_SEND_REFERRALS_NOTIFICATION
 @abstract Notifies observers that referrals were sent.
 @discussion An <code>NSArray</code> of successfully sent @link SMReferral @/link objects can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_DATA_KEY @/link key. If any referral requests were denied, then an <code>NSArray</code> of @link SMReferralError @/link objects containing information about why a particular referral was denied can be accessed with the @link SM_REFERRALS_MANAGER_NOTIFICATION_ERRORS_KEY @/link key - and a general @link SMError @/link object can be accessed with the @link SM_MANAGER_NOTIFICATION_ERROR_KEY @/link key.
 */
extern NSString *const SM_REFERRALS_MANAGER_DID_SEND_REFERRALS_NOTIFICATION NS_SWIFT_NAME(sentReferralsNotification);
/*!
 @const SM_REFERRALS_MANAGER_DID_FETCH_REFERRALS_NOTIFICATION
 @abstract Notifies observers that referrals sent by the current user were fetched.
 @discussion An <code>NSArray</code> of @link SMReferral @/link objects can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_DATA_KEY @/link key.
 */
extern NSString *const SM_REFERRALS_MANAGER_DID_FETCH_REFERRALS_NOTIFICATION NS_SWIFT_NAME(fetchedReferralsNotification);

/*!
 @protocol SMReferralsDelegate
 @abstract Defines callbacks for @link SMReferralsManager @/link methods.
 */
@protocol SMReferralsDelegate <SMBaseDelegate>

@optional

/*!
 @abstract Notifies delegate that referral requests were created and sent.
 @discussion This method is called in response to @link sendReferrals: @/link.
 @param referrals The newly created referrals.
 @param referralErrors Errors for individual referrals.
 @param error Error for entire referral request.
 @deprecated Use block methods instead.
 */
- (void)didSendReferrals:(NSArray<SMReferral *> * _Nullable)referrals referralErrors:(NSArray<SMReferralError *> * _Nullable)referralErrors error:(SMError * _Nullable)error __attribute__((deprecated("Use block methods instead"))) NS_SWIFT_NAME(didSendReferrals(_:referralErrors:error:));
/*!
 @abstract Notifies delegate that the current user's sent referrals were fetched.
 @discussion This method is called in response to @link fetchReferrals @/link.
 @param referrals Referrals that have been sent by the current user.
 @deprecated Use block methods instead.
 */
- (void)didFetchReferrals:(NSArray<SMReferral *> *)referrals __attribute__((deprecated("Use block methods instead"))) NS_SWIFT_NAME(didFetchReferrals(_:));
/*!
 @abstract Notifies delegate that one of the current user's sent referrals was fetched.
 @discussion This method is called in response to @link fetchReferralWithID: @/link.
 @param referral A referral that has been sent by the current user.
 @deprecated Use block methods instead.
 */
- (void)didFetchSingleReferral:(SMReferral *)referral __attribute__((deprecated("Use block methods instead"))) NS_SWIFT_NAME(didFetchSingleReferral(_:));

@end

/*!
 @typedef didSendReferrals
 @abstract Completion handler block type for @link sendReferrals:completionHandler: @/link.
 */
typedef void (^didSendReferrals)(NSArray<SMReferral *>* _Nullable successfulReferrals, NSArray<SMReferralError *>* _Nullable referralErrors, SMError * _Nullable error) NS_SWIFT_NAME(SendReferralsCompletionHandler);
/*!
 @typedef didFetchReferrals
 @abstract Completion handler block type for @link fetchReferralsWithCompletionHandler: @/link.
 */
typedef void (^didFetchReferrals)(NSArray<SMReferral *>* _Nullable referrals, SMError * _Nullable error) NS_SWIFT_NAME(FetchReferralsCompletionHandler);
/*!
 @typedef didFetchSingleReferral
 @abstract Completion handler block type for @link fetchReferralWithID:completionHandler: @/link.
 */
typedef void (^didFetchSingleReferral)(SMReferral * _Nullable referral, SMError * _Nullable error) NS_SWIFT_NAME(FetchSingleReferralCompletionHandler);

/*!
 @class SMReferralsManager
 @abstract This API manager contains methods for sending and fetching registration referral requests.
 */
@interface SMReferralsManager : NSObject

+(SMReferralsManager *)instance;

/*!
 @property delegate
 @abstract Object that implements @link SMReferralsDelegate @/link callbacks.
 */
@property(nonatomic, weak) id<SMReferralsDelegate> _Nullable delegate;
/*!
 @property referrals
 @abstract Referrals that have been sent by the current user.
 @discussion This property is updated in response to a successful @link fetchReferralsWithCompletionHandler: @/link call.
 */
@property(nonatomic, strong, readonly) NSArray<SMReferral *> *referrals;

/*!
 @abstract Makes a request to send the specified referrals.
 @discussion @link didSendReferrals:referralErrors:error: @/link is called in response to this method.
 @param referrals The referrals request to be sent.
 @result <code>BOOL</code> indicating whether the request will be sent.
 @deprecated Use @link sendReferrals:completionHandler: @/link.
 */
- (BOOL)sendReferrals:(SMReferralsRequest *)referrals __attribute__((deprecated("Use sendReferrals:completionHandler:"))) NS_SWIFT_NAME(sendReferrals(_:));
/*!
 @abstract Makes a request to send the specified referrals.
 @param referrals The referrals request to be sent.
 @param completionHandler The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)sendReferrals:(SMReferralsRequest *)referrals completionHandler:(didSendReferrals)completionHandler NS_SWIFT_NAME(sendReferrals(_:completionHandler:));
/*!
 @abstract Makes a request to update @link referrals @/link with the current user's referrals.
 @discussion @link didFetchReferrals: @/link is called in response to this method.
 @result <code>BOOL</code> indicating whether the request will be sent.
 @deprecated Use @link fetchReferralsWithCompletionHandler: @/link.
 */
- (BOOL)fetchReferrals __attribute__((deprecated("Use fetchReferralsWithCompletionHandler:")));
/*!
 @abstract Makes a request to update @link referrals @/link with the current user's referrals.
 @param completionHandler The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)fetchReferralsWithCompletionHandler:(didFetchReferrals)completionHandler NS_SWIFT_NAME(fetchReferrals(completionHandler:));
/*!
 @abstract Makes a request to fetch the referral with the specified identifier.
 @discussion @link didFetchReferrals: @/link is called in response to this method.
 @param referralID The identifier of the referral to be fetched.
 @result <code>BOOL</code> indicating whether the request will be sent.
 @deprecated Use @link fetchReferralWithID:completionHandler: @/link.
 */
- (BOOL)fetchReferralWithID:(NSString *)referralID __attribute__((deprecated("Use fetchReferralWithID:completionHandler:"))) NS_SWIFT_NAME(fetchReferral(havingID:));
/*!
 @abstract Makes a request to fetch the referral with the specified identifier.
 @param referralID The identifier of the referral to be fetched.
 @param completionHandler The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)fetchReferralWithID:(NSString *)referralID completionHandler:(didFetchSingleReferral)completionHandler NS_SWIFT_NAME(fetchReferral(havingID:completionHandler:));

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_REFERRALS_MANAGER__ */
