// 
//  SMAuthenticationProvider.h
//  SessionMCoreKit
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SM_Authentication_Provider__
#define __SM_Authentication_Provider__

#import "SMError.h"
#import "SMHttpRequest.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @const SM_AUTHENTICATION_PROVIDER_DID_CLEAR_USER
 @abstract Notifies observers that the current user is no longer considered authenticated by the SDK.
 @discussion If you need to clean up when the user is no longer authenticated, listen for notification with this key.
 */
extern NSString *const SM_AUTHENTICATION_PROVIDER_DID_CLEAR_USER NS_SWIFT_NAME(clearedUserNotification);
/*!
 @const SM_AUTHENTICATION_PROVIDER_DID_SET_USER_ID
 @abstract Notifies observers that the current user is considered authenticated by the SDK.
 @discussion If you need to handle the user being authenticated, listen for notification with this key.
 */
extern NSString *const SM_AUTHENTICATION_PROVIDER_DID_SET_USER_ID NS_SWIFT_NAME(setUserIDNotification);

extern NSString *const kAuthProviderUserID;

typedef NS_ENUM(NSUInteger, SMAuthState) {
    SMAuthStateUnknown NS_SWIFT_NAME(unknown),
    SMAuthStateAuthenticated NS_SWIFT_NAME(authenticated),
    SMAuthStateLoggedOut NS_SWIFT_NAME(loggedOut),
    SMAuthStateFailed NS_SWIFT_NAME(failed)
};

typedef NS_ENUM(NSUInteger, SMRefreshState) {
    SMRefreshStateRefreshed NS_SWIFT_NAME(refreshed),
    SMRefreshStateNoChange NS_SWIFT_NAME(noChange),
    SMRefreshStateFailed NS_SWIFT_NAME(failed),
};

/*!
 @typedef RefreshTokenHandler
 @abstract Completion handler block type for <code>refreshTokenIfNeeded:</code>.
 */
typedef void(^RefreshTokenHandler)(SMRefreshState refreshed, SMError * _Nullable error);
/*!
 @typedef UserStateUpdateHandler
 @abstract Completion handler block type for <code>userAuthenticatedWithCompletionHandler:</code> and <code>userDeauthenticatedWithCompletionHandler:</code>.
 */
typedef void(^UserStateUpdateHandler)(SMError * _Nullable error);

/*!
 @abstract protocol for calls from the SDK into the  <code>SMAuthenticationProvider</code> implementations
 */
@protocol SMAuthenticationProvider

@required
/*!
 @abstract the SDK uses this to determine if the Authentication Provider considers itself authenticated.
 @discussion if it is not authenticated, the API call request will not be tried
 */
- (BOOL)isAuthenticated;

@optional
/*!
 @abstract the SDK uses this to allow the Authentication Provider to refresh it's token(s) before it attempts to use it.
 @discussion If the developer has expiring tokens, this gives them an opportunity to refresh before the SDK attempts to
 make API calls using the token.
 */
- (BOOL)refreshTokenIfNeededWithCompletionHandler:(RefreshTokenHandler)completionHandler NS_SWIFT_NAME(refreshTokenIfNeeded(completionHandler:));

/*!
 @abstract the SDK uses this to allow the Authentication Provider to add headers to the request (ie. Authentication: Bearer ...).
 @discussion can add any headers required for authentication
 */
- (NSDictionary<NSString *, NSString *> * _Nullable)authenticationHeaders;

/*!
 @abstract the SDK uses this incase the developer needs to change the request for authentication
 @discussion (ie some schemes put authentication information into the body.
 */
- (BOOL)updateAuthenticationRequestWithBuilder:(SMHttpRequestBuilder *)builder NS_SWIFT_NAME(updateAuthenticationRequest(usingBuilder:));

/*!
 @abstract the SDK calls this when it feels it's ready, in case the developer needs to wait until then
 */
- (BOOL)ready;

- (BOOL)isTestAuthenticationProvider;

@end

@interface SMAuthenticationProvider : NSObject
/*!
 @abstract the developer needs to call this from their authentication provider when it is ready to use with an authenticated user.
 @discussion the SDK needs to be notified when the authentication provider is ready to be used, and the user is authenticated
 */
+ (void)userAuthenticatedWithCompletionHandler:(nullable UserStateUpdateHandler)completionHandler NS_SWIFT_NAME(userAuthenticated(completionHandler:));
/*!
 @abstract the developer needs to call this from their authentication provider when the user is no longer authenticated.
 */
+ (void)userDeauthenticatedWithCompletionHandler:(nullable UserStateUpdateHandler)completionHandler NS_SWIFT_NAME(userDeauthenticated(completionHandler:));

@end

NS_ASSUME_NONNULL_END

#endif
