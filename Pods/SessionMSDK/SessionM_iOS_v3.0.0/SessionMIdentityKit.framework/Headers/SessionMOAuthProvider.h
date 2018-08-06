// 
//  SessionMOAuthProvider.h
//  SessionMIdentityKit
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SESSIONM_OAUTH_PROVIDER__
#define __SESSIONM_OAUTH_PROVIDER__

#import <Foundation/Foundation.h>

#import "SessionMOAuthProviderIDP.h"
#import "SMPUserCreate.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SessionMOAuthProvider
 @abstract A default identity provider that provides support for creating and authenticating users.
 */
@interface SessionMOAuthProvider : SessionMOAuthProviderIDP <SMAuthenticationProvider>

/*!
 @abstract Makes a request to create a new user using the default SessionM Platform identity service provider.
 @param data Data used to create the new account.
 @param completionHandler The block to execute after the request is processed.
 */
- (void)createUser:(SMPUserCreate *)data completionHandler:(didUpdateAuthState _Nullable)completionHandler NS_SWIFT_NAME(createUser(withData:completionHandler:));
/*!
 @abstract Makes a request to authenticate the given user credentials using the default SessionM Platform identity service provider.
 @param email User's email.
 @param password User's password.
 @param completionHandler The block to execute after the request is processed.
 */
- (void)authenticateUserWithEmail:(NSString *)email password:(NSString *)password completionHandler:(didUpdateAuthState _Nullable)completionHandler NS_SWIFT_NAME(authenticateUser(withEmail:password:completionHandler:));
/*!
 @abstract Makes a request to authenticate an OAuth token from the given identity service provider.
 @param token Token string from the provider.
 @param provider Used to identify provider for server processing.
 @param completionHandler The block to execute after the request is processed.
 */
- (void)authenticateUserWithToken:(NSString *)token provider:(NSString *)provider completionHandler:(didUpdateAuthState _Nullable)completionHandler NS_SWIFT_NAME(authenticateUser(withToken:provider:completionHandler:));

@end

NS_ASSUME_NONNULL_END

#endif /* __SESSIONM_OAUTH_PROVIDER__ */
