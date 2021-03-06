//
//  SessionMOAuthProvider+WebAuth.h
//  SessionMWebAuthKit
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SM_OAUTH_PROVIDER_WEB_AUTH__
#define __SM_OAUTH_PROVIDER_WEB_AUTH__

#import <SessionMIdentityKit/SessionMIdentityKit.h>
#import <UIKit/UIViewController.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^didRequestAuthCode)(NSString * _Nullable authCode, SMError * _Nullable error);

@interface SessionMOAuthProvider (WebAuth)

/*!
 @abstract Presents an instance of <code>SFSafariViewController</code> that points to a web page where the user's credentials can be authorized.
 @discussion If the authorization is successful, then a request is sent to authenticate the user in the SessionM Platform with the newly authorized access token.
 @param presenting View controller to use to present the <code>SFSafariViewController</code> instance.
 @param completionHandler The block to execute after the authentication request is processed.
 */
- (void)startWebAuthorizationInViewController:(UIViewController *)presenting completionHandler:(didUpdateAuthState)completionHandler NS_SWIFT_NAME(startWebAuthorization(in:completionHandler:));
/*!
 @abstract Presents an instance of <code>SFSafariViewController</code> that points to a web page where the user's credentials can be authorized (note: does not include automatic code exchange).
 @discussion If the authorization is successful, then an authorization code is passed to the <code>completionHandler</code> block.
 @param presenting View controller to use to present the <code>SFSafariViewController</code> instance.
 @param completionHandler The block to execute after the authentication request is processed.
 */
- (void)startWebAuthorizationForAuthCodeInViewController:(UIViewController *)presenting completionHandler:(didRequestAuthCode)completionHandler NS_SWIFT_NAME(startWebAuthorizationForAuthCode(in:completionHandler:));
/*!
 @abstract Attempts to handle the provided OAuth response redirect URI to continue authorization.
 @discussion A call to this method must be added to your application delegate's <code>application:openURL:options:</code> method to handle OAuth response redirects from <code>startWebAuthorizationInViewController:completionHandler:</code> and <code>startWebAuthorizationForAuthCodeInViewController:completionHandler:</code> method calls.
 @param redirect Potential redirect URI passed to the <code>application:openURL:options:</code> method.
 @result <code>BOOL</code> indicating whether the redirect URI was handled.
 */
- (BOOL)handleOAuthRedirectURI:(NSURL *)redirect;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_OAUTH_PROVIDER_WEB_AUTH__ */
