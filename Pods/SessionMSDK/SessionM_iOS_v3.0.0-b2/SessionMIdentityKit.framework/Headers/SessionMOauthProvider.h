// 
//  SessionMOauthProvider.h
//
//  Copyright © 2018 SessionM. All rights reserved.
//
//


#ifndef SessionMOauthProvider_h
#define SessionMOauthProvider_h

#import <Foundation/Foundation.h>
#import "SessionMOauthProviderIDP.h"

NS_ASSUME_NONNULL_BEGIN

@interface SessionMOauthProvider : SessionMOauthProviderIDP <SMAuthenticationProvider>
/*!
 @abstract Makes a request to create an user using the default SessionM Platform identity service provider.
 @param create Users initial information.
 @param onComplete The block to execute after the request is processed.
 */
-(void)createUser:(SMPUserCreate *)create onComplete:(_Nullable didUpdateAuthState)onComplete;
/*!
 @abstract Makes a request to authenticate the given user credentials using the default SessionM Platform identity service provider.
 @param email User's email.
 @param password User's password.
 @param onComplete The block to execute after the request is processed.
 */
-(void)authenticateUser:(NSString *)email password:(NSString *)password onComplete:(_Nullable didUpdateAuthState)onComplete;
/*!
 @abstract Makes a request to authenticate an OAuth token from the given identity service provider.
 @param token Token string from the provider.
 @param provider Used to identify provider for server processing.
 @param onComplete The block to execute after the request is processed.
 */
-(void)authenticateWithToken:(NSString *)token provider:(NSString *)provider onComplete:(_Nullable didUpdateAuthState)onComplete;

@end

NS_ASSUME_NONNULL_END

#endif

