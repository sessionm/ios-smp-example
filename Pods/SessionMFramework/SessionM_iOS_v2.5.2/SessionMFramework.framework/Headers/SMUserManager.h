//
//  SMUserManager.h
//  SessionM
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SM_USER_MANAGER__
#define __SM_USER_MANAGER__

#import "SMPUser.h"
#import "SMPUserUpdate.h"

#import "SMWebProfileManager.h"

#import "SMError.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @const SM_USER_MANAGER_REQUEST_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that a User API request failed.
 @discussion An @link SMError @/link object containing information about why the request failed can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_ERROR_KEY @/link key.
 */
extern NSString *const SM_USER_MANAGER_REQUEST_DID_FAIL_NOTIFICATION NS_SWIFT_NAME(userRequestFailureNotification);
/*!
 @const SM_USER_MANAGER_VALIDATION_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that a User API validation failed.
 @discussion An @link SMError @/link object containing information about why the validation failed can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_ERROR_KEY @/link key.
 */
extern NSString *const SM_USER_MANAGER_VALIDATION_DID_FAIL_NOTIFICATION NS_SWIFT_NAME(userValidationFailureNotification);
/*!
 @const SM_USER_MANAGER_DID_UPDATE_USER
 @abstract Notifies observers that account data for the current user was updated.
 @discussion An @link SMPUser @/link object containing information about the current user's account can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_DATA_KEY @/link key, and an <code>NSSet</code> of the names of the user properties that were updated can be accessed with the @link kUserDeltas @/link key.
 */
extern NSString *const SM_USER_MANAGER_DID_UPDATE_USER NS_SWIFT_NAME(updatedUserNotification);
/*!
 @const kUserDeltas
 @abstract Used to access an <code>NSSet</code> of the names of the user properties that were updated from a @link SM_USER_MANAGER_DID_UPDATE_USER @/link notification's <code>userInfo</code> property.
 @discussion See @link SMPUser @/link for a list of values that may appear in the set.
 */
extern NSString *const kUserDeltas;


/*!
 @typedef didUpdateUser
 @abstract Completion handler block type for @link fetchUserWithCompletionHandler: @/link and @link updateUser:completionHandler: @/link.
 */
typedef void(^didUpdateUser)(SMPUser * _Nullable user, NSSet<NSString *> * _Nullable deltas, SMError * _Nullable error) NS_SWIFT_NAME(UpdateUserCompletionHandler);


/*!
 @class SMUserManager
 @abstract This API manager contains methods for fetching and updating user data.
 */
@interface SMUserManager : NSObject

/*!
 @property currentUser
 @abstract Returns the currently cached user object.
 @discussion This property is updated in response to a successful @link fetchUserWithCompletionHandler: @/link or @link updateUser:completionHandler: @/link call - or to an internal change in the user's points value or authentication state (see @link //apple_ref/occ/cl/SMIdentityManager @/link).
 */
@property(nullable, nonatomic, strong, readonly) SMPUser *currentUser;
/*!
 @property webProfileManager
 @abstract Singleton that interfaces with the SessionM Platform User Web Profile API.
 */
@property(nonatomic, strong, readonly) SMWebProfileManager *webProfileManager;

/*!
 @abstract Singleton that interfaces with the SessionM Platform User API.
 @result <code>SMUserManager</code> service object.
 */
+ (SMUserManager *)instance;

/*!
 @abstract Makes a request to fetch the current user's data.
 @param completionHandler The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)fetchUserWithCompletionHandler:(didUpdateUser)completionHandler NS_SWIFT_NAME(fetchUser(completionHandler:));
/*!
 @abstract Makes a request to update the current user's data.
 @param updates Data changes to make.
 @param completionHandler The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)updateUser:(SMPUserUpdate *)updates completionHandler:(didUpdateUser)completionHandler NS_SWIFT_NAME(updateUser(updates:completionHandler:));

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_USER_MANAGER__ */
