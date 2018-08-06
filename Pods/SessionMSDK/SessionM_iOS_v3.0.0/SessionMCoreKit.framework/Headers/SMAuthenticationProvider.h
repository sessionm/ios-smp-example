// 
//  SMAuthenticationProvider.h
//  SessionMCoreKit
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SM_AUTHENTICATION_PROVIDER__
#define __SM_AUTHENTICATION_PROVIDER__

#import "SMError.h"
#import "SMHTTPRequestBuilder.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @const SM_AUTHENTICATION_PROVIDER_DID_CLEAR_USER
 @abstract Notifies observers that the current user is no longer considered authenticated by the SDK.
 */
extern NSString *const SM_AUTHENTICATION_PROVIDER_DID_CLEAR_USER NS_SWIFT_NAME(clearedUserNotification);
/*!
 @const SM_AUTHENTICATION_PROVIDER_DID_SET_USER_ID
 @abstract Notifies observers that the current user is considered authenticated by the SDK.
 @discussion The user's new ID can be accessed from the notification's <code>userInfo</code> property with the <code>kAuthProviderUserID</code> key.
 */
extern NSString *const SM_AUTHENTICATION_PROVIDER_DID_SET_USER_ID NS_SWIFT_NAME(setUserIDNotification);
/*!
 @const kAuthProviderUserID
 @abstract Used to access an <code>NSString</code> object representing the current user's new ID from a <code>SM_AUTHENTICATION_PROVIDER_DID_SET_USER_ID</code> notification's <code>userInfo</code> property.
 */
extern NSString *const kAuthProviderUserID;

/*!
 @typedef SMAuthState
 @abstract Result of user authentication or logout attempt.

 @const SMAuthStateUnknown Authentication state is unknown.
 @const SMAuthStateAuthenticated User is successfully authenticated.
 @const SMAuthStateLoggedOut User has successfully logged out and is no longer authenticated.
 @const SMAuthStateFailed Attempt to authenticate user failed.
 */
typedef NS_ENUM(NSUInteger, SMAuthState) {
    SMAuthStateUnknown NS_SWIFT_NAME(unknown),
    SMAuthStateAuthenticated NS_SWIFT_NAME(authenticated),
    SMAuthStateLoggedOut NS_SWIFT_NAME(loggedOut),
    SMAuthStateFailed NS_SWIFT_NAME(failed)
};

/*!
 @typedef SMRefreshState
 @abstract Result of attempt to refresh a user's access token.

 @const SMRefreshStateRefreshed Access token was successfully refreshed.
 @const SMRefreshStateNoChange Access token did not require a refresh.
 @const SMRefreshStateFailed Refresh attempt failed.
 */
typedef NS_ENUM(NSUInteger, SMRefreshState) {
    SMRefreshStateRefreshed NS_SWIFT_NAME(refreshed),
    SMRefreshStateNoChange NS_SWIFT_NAME(noChange),
    SMRefreshStateFailed NS_SWIFT_NAME(failed),
};

/*!
 @typedef RefreshTokenHandler
 @abstract Completion handler block type for <code>refreshTokenIfNeeded:</code>.
 */
typedef void(^RefreshTokenHandler)(SMRefreshState state, SMError * _Nullable error);
/*!
 @typedef UserStateUpdateHandler
 @abstract Completion handler block type for <code>userAuthenticatedWithCompletionHandler:</code> and <code>userDeauthenticatedWithCompletionHandler:</code>.
 */
typedef void(^UserStateUpdateHandler)(SMError * _Nullable error);


/*!
 @protocol SMAuthenticationProvider
 @abstract Defines methods that OAuth identity providers are expected to implement.
 */
@protocol SMAuthenticationProvider

@required
/*!
 @abstract Called by the SDK to determine whether the current user is authenticated.
 @discussion Note: the SDK will ignore certain API requests if the user is not authenticated.
 @result <code>BOOL</code> indicating whether the current user is authenticated.
 */
- (BOOL)isAuthenticated;

@optional
/*!
 @abstract Called by the SDK to allow the authentication provider to refresh the current user's access token before attempting to use it.
 @param completionHandler The block to execute after the refresh attempt is completed.
 */
- (void)refreshTokenIfNeededWithCompletionHandler:(RefreshTokenHandler)completionHandler NS_SWIFT_NAME(refreshTokenIfNeeded(completionHandler:));

/*!
 @abstract Called by the SDK to allow the authentication provider to add headers to an authentication request (e.g. "Authorization: Bearer ...") before sending it.
 @result <code>NSDictionary</code> representation of authentication request headers.
 */
- (NSDictionary<NSString *, NSString *> * _Nullable)authenticationHeaders;

/*!
 @abstract Called by the SDK to allow the authentication provider to update data for an authentication request before sending it.
 @param builder Updates made to the builder object will be reflected in the request.
 */
- (void)updateAuthenticationRequestWithBuilder:(SMHTTPRequestBuilder *)builder NS_SWIFT_NAME(updateAuthenticationRequest(usingBuilder:));

/*!
 @abstract Called by the SDK to determine whether the authentication provider is initialized and ready to handle authentication requests.
 @result <code>BOOL</code> indicating whether the authentication provider is initialized and ready to handle authentication requests.
 */
- (BOOL)isReady;

/*!
 @abstract Called by the SDK to determine whether the authentication provider is used for testing.
 @discussion Note: this method should not be implemented in production code.
 @result <code>BOOL</code> indicating whether the authentication provider is used for testing.
 */
- (BOOL)isTestAuthenticationProvider NS_SWIFT_NAME(isTestAuthenticationProvider());

@end


/*!
 @class SMAuthenticationProvider
 @abstract Defines helper methods that developers need to use when implementing their own identity providers.
 */
@interface SMAuthenticationProvider : NSObject

/*!
 @abstract The developer needs to call this method from their authentication provider after the current user has been authenticated.
 @discussion After this method is called, the SDK will begin initializing a new user session.
 @param completionHandler The block to execute after the new user session is initialized.
 */
+ (void)userAuthenticatedWithCompletionHandler:(nullable UserStateUpdateHandler)completionHandler NS_SWIFT_NAME(userAuthenticated(completionHandler:));
/*!
 @abstract The developer needs to call this method from their authentication provider after the current user has been deauthenticated.
 @discussion After this method is called, the SDK will begin cleaning up the current user session.
 @param completionHandler The block to execute after the current user session is cleaned up.
 */
+ (void)userDeauthenticatedWithCompletionHandler:(nullable UserStateUpdateHandler)completionHandler NS_SWIFT_NAME(userDeauthenticated(completionHandler:));

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_AUTHENTICATION_PROVIDER__ */
