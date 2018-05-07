// 
//  SMAuthenticationProvider.h
//
//  Copyright © 2018 SessionM. All rights reserved.
//
//

#ifndef __SM_Authentication_Provider__
#define __SM_Authentication_Provider__

#import "SMError.h"
#import "SMHttpRequest.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @const SM_Authentication_Provider_Clear_User
 @abstract Notifies observers that the current user is no longer considered authenticated by the SDK.
 @discussion If you need to clean up when the user is no longer authenticated, listen for notification with this key
 */
extern NSString *const SM_Authentication_Provider_Clear_User NS_SWIFT_NAME(clearUser);
/*!
 @const SM_Authentication_Provider_Set_UserID
 @abstract Notifies observers that the current user is considered authenticated by the SDK.
 @discussion If you need to handle when the user is longer authenticated, listen for notification with this key
 */
extern NSString *const SM_Authentication_Provider_Set_UserID NS_SWIFT_NAME(setUserID);

extern NSString *const kUser_ID;

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
 @typedef OnTokenRefreshed
 @abstract Completion handler block type for <code>refreshTokenIfNeeded:</code>.
 */
typedef void(^OnTokenRefreshed)(SMRefreshState refreshed, SMError * _Nullable error);
/*!
 @typedef OnAuthenticationProviderSetFromAuthenticationProvider
 @abstract Completion handler block type for <code>setAuthenticationProvider:onProviderSet:</code>.
 */
typedef void(^OnAuthenticationProviderSetFromAuthenticationProvider)(SMError * _Nullable error);

/*!
 @abstract protocol for calls from the SDK into the  <code>SMAuthenticationProvider</code> implementations
 */
@protocol SMAuthenticationProvider

@required
/*!
 @abstract the SDK uses this to determine if the Authentication Provider considers itself authenticated.
 @discussion if it is not authenticated, the API call request will not be tried
 */
-(BOOL)isAuthenticated NS_SWIFT_NAME(isAuthenticated());

@optional
/*!
 @abstract the SDK uses this to allow the Authentication Provider to refresh it's token(s) before it attempts to use it.
 @discussion If the developer has expiring tokens, this gives them an opportunity to refresh before the SDK attempts to
 make API calls using the token.
 */
-(BOOL)refreshTokenIfNeeded:(OnTokenRefreshed)onTokenRefreshed NS_SWIFT_NAME(refreshTokenIfNeeded(onRefreshed:));

/*!
 @abstract the SDK uses this to allow the Authentication Provider to add headers to the request (ie. Authentication: Bearer ...).
 @discussion can add any headers required for authentication
 */
-(NSDictionary<NSString *, NSString *> * _Nullable)headersForAuthenticate NS_SWIFT_NAME(headersForAuthenticate());

/*!
 @abstract the SDK uses this incase the developer needs to change the request for authentication
 @discussion (ie some schemes put authentication information into the body.
 */
-(BOOL)updateRequestForAuthentication:(SMHttpRequestBuilder *)builder NS_SWIFT_NAME(updateAuthenticationRequest(builder:));

/*!
 @abstract the SDK calls this when it feels it's ready, in case the developer needs to wait until then
 */
-(BOOL)ready;

-(BOOL)isTestAuthenticationProvider;

@end

@interface SMAuthenticationProvider : NSObject
/*!
 @abstract the developer needs to call this from their authentication provider when it is ready to use with an authenticated user.
 @discussion the SDK needs to be notified when the authentication provider is ready to be used, and the user is authenticated
 */
+(void)userAuthenticatedWithCompletionHandler:(nullable OnAuthenticationProviderSetFromAuthenticationProvider)completionHandler;
/*!
 @abstract the developer needs to call this from their authentication provider when the user is no longer authenticated.
 */
+(void)userDeauthenticatedWithCompletionHandler:(nullable OnAuthenticationProviderSetFromAuthenticationProvider)completionHandler;

@end

NS_ASSUME_NONNULL_END

#endif
