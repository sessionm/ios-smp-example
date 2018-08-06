// 
//  SessionMOAuthProviderIDP.h
//  SessionMIdentityKit
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SESSIONM_OAUTH_PROVIDER_IDP__
#define __SESSIONM_OAUTH_PROVIDER_IDP__

#import <Foundation/Foundation.h>
#import <SessionMCoreKit/SessionMCoreKit.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @const SESSIONM_OAUTH_PROVIDER_DID_UPDATE_AUTH_STATE
 @abstract Notifies observers that the current user authentication state has been updated.
 @discussion An <code>NSNumber</code> object representing the user's authentication state can be accessed from the notification's <code>userInfo</code> property with the <code>SM_MANAGER_NOTIFICATION_DATA_KEY</code> key.
 */
extern NSString *const SESSIONM_OAUTH_PROVIDER_DID_UPDATE_AUTH_STATE NS_SWIFT_NAME(updatedAuthStateNotification);

/*!
 @typedef AccessTokenHandler
 @abstract Handler block type for method calls that perform an action with the current user's access token.
 */
typedef void(^AccessTokenHandler)(NSString * _Nullable accessToken, SMError * _Nullable error);
/*!
 @typedef AuthCodeHandler
 @abstract Completion handler block type for method calls that request the user's authentication code.
 */
typedef void(^AuthCodeHandler)(NSString *_Nullable authCode, SMError * _Nullable error);
/*!
 @typedef didUpdateAuthState
 @abstract Completion handler block type for method calls that update the user's authentication state.
 */
typedef void(^didUpdateAuthState)(SMAuthState state, SMError * _Nullable error);

/*!
 @class SessionMOAuthProviderIDP
 @abstract A default identity provider that provides general OAuth support.
 */
@interface SessionMOAuthProviderIDP : NSObject <SMAuthenticationProvider>

/*!
 @property needsRefresh
 @abstract Indicates whether the current user's access token should be refreshed when the next SessionM Platform HTTP request is sent.
 @discussion The SessionM OAuth provider will refresh the current user's access token if it has expired, but this property can be set to <code>YES</code> to force an earlier refresh.
 */
@property(nonatomic, assign, readwrite) BOOL needsRefresh;

/*!
 @abstract Gets the current user's access token (refreshing it if necessary), and passes it to the specified <code>AccessTokenCallback</code> handler.
 @discussion You should assume that the access token changes between invocations of this method.
 @param handler The block that will be called with the current user's access token.
 */
- (void)getAccessTokenWithHandler:(AccessTokenHandler)handler NS_SWIFT_NAME(getAccessToken(handler:));
/*!
 @abstract Makes a request to fetch the current user's authentication code.
 @discussion This is a special case feature - please confer with the SessionM SDK team for more details.
 @param completionHandler The block to execute after the request is processed.
 */
- (void)requestAuthCodeWithCompletionHandler:(AuthCodeHandler)completionHandler NS_SWIFT_NAME(requestAuthCode(completionHandler:));

/*!
 @abstract Makes a request to log out the current user.
 @param completionHandler The block to execute after the request is processed.
 */
- (void)logOutUserWithCompletionHandler:(didUpdateAuthState _Nullable)completionHandler NS_SWIFT_NAME(logOutUser(completionHandler:));

@end

NS_ASSUME_NONNULL_END /* __SESSIONM_OAUTH_PROVIDER_IDP__ */

#endif /* __SessionM_OAuth_Provider__ */
