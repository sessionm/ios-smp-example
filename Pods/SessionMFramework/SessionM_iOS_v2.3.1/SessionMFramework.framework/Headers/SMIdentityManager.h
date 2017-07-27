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
 @typedef didRequestAuthCode
 @abstract Completion handler block type for method calls that request the user's authentication code.
 */
typedef void(^didRequestAuthCode)(NSString * _Nullable authCode, SMError * _Nullable error) NS_SWIFT_NAME(RequestAuthCodeCompletionHandler);
/*!
 @typedef AccessTokenHandler
 @abstract Handler block type for method calls that perform an action with the current user's access token.
 */
typedef void(^AccessTokenHandler)(NSString * _Nullable accessToken, SMError * _Nullable error);

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
 @abstract Makes a request to create a new user.
 @param data Data used to create the new account.
 @param completionHandler The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)createUser:(SMPUserCreate *)data completionHandler:(didUpdateAuthState)completionHandler NS_SWIFT_NAME(createUser(withData:completionHandler:));
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
 @abstract Makes a request to log out the current user.
 @param completionHandler The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)logOutUserWithCompletionHandler:(didUpdateAuthState)completionHandler NS_SWIFT_NAME(logOutUser(completionHandler:));

/*!
 @abstract Makes a request to fetch the current user's authentication code.
 @discussion This is a special case feature - please confer with the SessionM SDK team for more details.
 @param key The key that will be used to access the developer's clientID from the app's SMP configuration plist file (passing in a value of <code>nil</code> will cause the default key to be used).
 @param completionHandler The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)requestAuthCodeWithClientIDKey:(NSString * _Nullable)key completionHandler:(didRequestAuthCode)completionHandler NS_SWIFT_NAME(requestAuthCode(withClientIDKey:completionHandler:));

/*!
 @abstract Gets the current user's access token (refreshing it if necessary), and passes it to the specified @link AccessTokenHandler @/link handler.
 @discussion You should assume that the access token changes between invocations of this method.
 @param handler The block that will be called with the current user's access token.
 */
- (void)getAccessTokenWithHandler:(AccessTokenHandler)handler NS_SWIFT_NAME(getAccessToken(withHandler:));

@end

NS_ASSUME_NONNULL_END

#endif /* SM_IDENTITY_MANAGER */
