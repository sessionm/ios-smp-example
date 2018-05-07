// 
//  SessionMOauthSpecialCaseProvider.h
//
//  Copyright © 2018 SessionM. All rights reserved.
//
//

#ifndef SessionMOauthSpecialCaseProvider_h
#define SessionMOauthSpecialCaseProvider_h

#import "SessionMOauthProvider.h"

NS_ASSUME_NONNULL_BEGIN

@interface SessionMOauthSpecialCaseProvider : SessionMOauthProvider <SMAuthenticationProvider>

/*!
 @abstract Makes a request to authenticate a user using the specified OAuth data.
 @discussion This is a special case feature - please confer with the SessionM SDK team for more details.
 @param authData OAuth data to use for authentication.
 ???param onComplete The block to execute after the request is processed.
 */
-(SMIdentityError * _Nullable)provideSessionMOAuthTokenData:(NSDictionary *)authData;

@end

NS_ASSUME_NONNULL_END

#endif /* SessionMOauthSpecialCaseProvider_h */
