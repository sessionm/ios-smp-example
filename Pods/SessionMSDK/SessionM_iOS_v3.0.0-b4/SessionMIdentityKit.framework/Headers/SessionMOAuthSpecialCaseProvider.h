// 
//  SessionMOAuthSpecialCaseProvider.h
//  SessionMIdentityKit
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef SessionMOAuthSpecialCaseProvider_h
#define SessionMOAuthSpecialCaseProvider_h

#import "SessionMOAuthProvider.h"

NS_ASSUME_NONNULL_BEGIN

@interface SessionMOAuthSpecialCaseProvider : SessionMOAuthProvider <SMAuthenticationProvider>

/*!
 @abstract Makes a request to authenticate a user using the specified OAuth data.
 @discussion This is a special case feature - please confer with the SessionM SDK team for more details.
 @param authData OAuth data to use for authentication.
 */
- (SMIdentityError * _Nullable)provideSessionMOAuthTokenData:(NSDictionary *)authData NS_SWIFT_NAME(provideSessionMOAuthTokenData(_:));

@end

NS_ASSUME_NONNULL_END

#endif /* SessionMOAuthSpecialCaseProvider_h */
