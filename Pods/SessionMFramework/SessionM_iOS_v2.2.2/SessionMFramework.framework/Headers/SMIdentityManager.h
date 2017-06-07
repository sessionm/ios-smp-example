//
//  SMIdentityManager.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef __SM_IDENTITY_MANAGER__
#define __SM_IDENTITY_MANAGER__

#import "SMPUser.h"
#import "SMPUserCreate.h"

#import "SMError.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @const SM_IDENTITY_MANAGER_REQUEST_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that an Identity API request failed.
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
 @const SM_IDENTITY_MANAGER_DID_UPDATE_AUTH_STATE
 @abstract Notifies observers that the current user authentication state has been updated.
 @discussion An <code>NSNumber</code> object representing the user's authentication state can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_DATA_KEY @/link key.
 */
extern NSString *const SM_IDENTITY_MANAGER_DID_UPDATE_AUTH_STATE NS_SWIFT_NAME(updatedAuthStateNotification);


/*!
 @typedef SMAuthState
 @abstract Result of user authentication or log out attempt.

 @constant SMAuthStateUnknown Authentication state is unknown.
 @constant SMAuthStateAuthenticated User is successfully authenticated.
 @constant SMAuthStateLoggedOut User has successfully logged out and is no longer authenticated.
 @constant SMAuthStateFailed Attempt to authenticate user failed.
 */
typedef NS_ENUM(NSUInteger, SMAuthState) {
    SMAuthStateUnknown NS_SWIFT_NAME(unknown),
    SMAuthStateAuthenticated NS_SWIFT_NAME(authenticated),
    SMAuthStateLoggedOut NS_SWIFT_NAME(loggedOut),
    SMAuthStateFailed NS_SWIFT_NAME(failed)
};

/*!
 @typedef didUpdateAuthState
 @abstract Completion handler block type for method calls that update the user's authentication state.
 */
typedef void(^didUpdateAuthState)(SMAuthState state, SMError * _Nullable error) NS_SWIFT_NAME(UpdateAuthStateCompletionHandler);

/*!
 @class SMIdentityManager
 @abstract This API manager contains methods for creating and authenticating users.
 */
@interface SMIdentityManager : NSObject

/*!
 @abstract Singleton that interfaces with the SessionM Platform Identity API.
 @result <code>SMIdentityManager</code> service object.
 */
+ (SMIdentityManager *)instance;

/*!
 @abstract Makes a request to create a new user using the given identity service provider.
 @param data Data used to create the new account.
 @param provider Used to identify provider for server processing.
 @param completionHandler The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)createUser:(SMPUserCreate *)data provider:(NSString *)provider completionHandler:(didUpdateAuthState)completionHandler NS_SWIFT_NAME(createUser(withData:provider:completionHandler:));
/*!
 @abstract Makes a request to create a new user.
 @param data Data used to create the new account.
 @param completionHandler The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)createUser:(SMPUserCreate *)data completionHandler:(didUpdateAuthState)completionHandler NS_SWIFT_NAME(createUser(withData:completionHandler:));
/*!
 @abstract Makes a request to authenticate the given user credentials using the given identity service provider.
 @param email User's email.
 @param password User's password.
 @param provider Used to identify provider for server processing.
 @param completionHandler The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)authenticateUserEmail:(NSString *)email password:(NSString *)password provider:(NSString *)provider completionHandler:(didUpdateAuthState)completionHandler NS_SWIFT_NAME(authenticateUser(withEmail:password:provider:completionHandler:));
/*!
 @abstract Makes a request to authenticate the given user credentials using the default SessionM Platform identity service provider.
 @param email User's email.
 @param password User's password.
 @param completionHandler The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)authenticateUserEmail:(NSString *)email password:(NSString *)password completionHandler:(didUpdateAuthState)completionHandler NS_SWIFT_NAME(authenticateUser(withEmail:password:completionHandler:));
/*!
 @abstract Makes a request to authenticate an OAuth token from the given identity service provider.
 @param token Token string from the provider.
 @param provider Used to identify provider for server processing.
 @param completionHandler The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)authenticateWithToken:(NSString *)token provider:(NSString *)provider completionHandler:(didUpdateAuthState)completionHandler NS_SWIFT_NAME(authenticate(withToken:provider:completionHandler:));
/*!
 @abstract Makes a request to authenticate an OAuth token from the default SessionM Platform identity service provider.
 @param token Token string from the provider.
 @param completionHandler The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)authenticateWithToken:(NSString *)token completionHandler:(didUpdateAuthState)completionHandler NS_SWIFT_NAME(authenticate(withToken:completionHandler:));
/*!
 @abstract Makes a request to log out the current user.
 @param completionHandler The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)logOutUserWithCompletionHandler:(didUpdateAuthState)completionHandler NS_SWIFT_NAME(logOutUser(completionHandler:));

@end

NS_ASSUME_NONNULL_END

#endif /* SM_IDENTITY_MANAGER */
