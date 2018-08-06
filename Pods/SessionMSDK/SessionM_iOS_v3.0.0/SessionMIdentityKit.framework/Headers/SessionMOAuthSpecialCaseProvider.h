// 
//  SessionMOAuthSpecialCaseProvider.h
//  SessionMIdentityKit
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SESSIONM_OAUTH_SPECIAL_CASE_PROVIDER__
#define __SESSIONM_OAUTH_SPECIAL_CASE_PROVIDER__

#import "SessionMOAuthProvider.h"
#import "SMIdentityError.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SessionMOAuthSpecialCaseProvider
 @abstract A default identity provider that provides support for special cases.
 @discussion The features provided by this class are only intended for use in special cases - please confer with the SessionM SDK team for more details.
 */
@interface SessionMOAuthSpecialCaseProvider : SessionMOAuthProvider <SMAuthenticationProvider>

/*!
 @abstract Authenticates a user using the specified OAuth data.
 @param authData OAuth data to use for authentication.
 @result <code>nil</code> if the authentication was successful - or an error describing why the authentication failed.
 */
- (SMIdentityError * _Nullable)provideSessionMOAuthTokenData:(NSDictionary *)authData NS_SWIFT_NAME(provideSessionMOAuthTokenData(_:));

@end

NS_ASSUME_NONNULL_END

#endif /* __SESSIONM_OAUTH_SPECIAL_CASE_PROVIDER__ */
