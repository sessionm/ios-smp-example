//
//  SMUserManager.h
//  SessionMIdentityKit
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SM_USER_MANAGER__
#define __SM_USER_MANAGER__

#import <SessionMCoreKit/SMBaseManager.h>
#import <SessionMCoreKit/SMError.h>

#import "SMPUser.h"
#import "SMPUserUpdate.h"

#import "SMWebProfileManager.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @const SM_USER_MANAGER_REQUEST_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that a User API request failed.
 @discussion An <code>SMError</code> object containing information about why the request failed can be accessed from the notification's <code>userInfo</code> property with the <code>SM_MANAGER_NOTIFICATION_ERROR_KEY</code> key.
 */
extern NSString *const SM_USER_MANAGER_REQUEST_DID_FAIL_NOTIFICATION NS_SWIFT_NAME(userRequestFailureNotification);
/*!
 @const SM_USER_MANAGER_VALIDATION_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that a User API validation failed.
 @discussion An <code>SMError</code> object containing information about why the validation failed can be accessed from the notification's <code>userInfo</code> property with the <code>SM_MANAGER_NOTIFICATION_ERROR_KEY</code> key.
 */
extern NSString *const SM_USER_MANAGER_VALIDATION_DID_FAIL_NOTIFICATION NS_SWIFT_NAME(userValidationFailureNotification);
/*!
 @const SM_USER_MANAGER_DID_UPDATE_USER
 @abstract Notifies observers that account data for the current user was updated.
 @discussion An <code>SMPUser</code> object containing information about the current user's account can be accessed from the notification's <code>userInfo</code> property with the <code>SM_MANAGER_NOTIFICATION_DATA_KEY</code> key, and an <code>NSSet</code> of the names of the user properties that were updated can be accessed with the <code>kUserDeltas</code> key.
 */
extern NSString *const SM_USER_MANAGER_DID_UPDATE_USER NS_SWIFT_NAME(updatedUserNotification);
/*!
 @const kUserDeltas
 @abstract Used to access an <code>NSSet</code> of the names of the user properties that were updated from a <code>SM_USER_MANAGER_DID_UPDATE_USER</code> notification's <code>userInfo</code> property.
 @discussion See <code>SMPUser</code> for a list of values that may appear in the set.
 */
extern NSString *const kUserDeltas;


/*!
 @typedef didUpdateUser
 @abstract Completion handler block type for <code>fetchUserWithCompletionHandler:</code> and <code>updateUser:completionHandler:</code>.
 */
typedef void(^didUpdateUser)(SMPUser * _Nullable user, NSSet<NSString *> * _Nullable deltas, SMError * _Nullable error) NS_SWIFT_NAME(UpdateUserCompletionHandler);


/*!
 @class SMUserManager
 @abstract This API manager contains methods for fetching and updating user data.
 */
@interface SMUserManager : SMBaseManager

/*!
 @property currentUser
 @abstract Returns the currently cached user object.
 @discussion This property is updated in response to a successful <code>fetchUserWithCompletionHandler:</code> or <code>updateUser:completionHandler:</code> call - or to an internal change in the user's points value or authentication state (see <code>SMIdentityManager</code>).
 */
@property(nullable, nonatomic, strong, readonly) SMPUser *currentUser;
/*!
 @property webProfileManager
 @abstract Singleton that interfaces with the SessionM Platform User Web Profile API.
 */
@property(nonatomic, strong, readonly) SMWebProfileManager *webProfileManager;

/*!
 @abstract Makes a request to fetch the current user's data.
 @param completionHandler The block to execute after the request is processed.
 */
- (void)fetchUserWithCompletionHandler:(didUpdateUser)completionHandler NS_SWIFT_NAME(fetchUser(completionHandler:));
/*!
 @abstract Makes a request to update the current user's data.
 @param updates Data changes to make.
 @param completionHandler The block to execute after the request is processed.
 */
- (void)updateUser:(SMPUserUpdate *)updates completionHandler:(didUpdateUser)completionHandler NS_SWIFT_NAME(updateUser(updates:completionHandler:));

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_USER_MANAGER__ */
