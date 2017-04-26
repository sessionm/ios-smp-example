//
//  SMTokenType.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//
//

#ifndef __SM_TOKEN_TYPE__
#define __SM_TOKEN_TYPE__

/*!
 @typedef SMRequestTokenType
 @abstract Authentication types.

 @constant SMRequestTokenTypeSMOauthToken Use oauth token in headers.
 @constant SMRequestTokenTypeSessionMToken Use session token in headers.
 @constant SMRequestTokenTypeTransition Transition between session cookie and tokens.
 @constant SMRequestTokenTypeAllBlank For authenticate token, purge everything before handling.
 */
typedef NS_ENUM(NSUInteger, SMRequestTokenType) {
    SMRequestTokenTypeSMOauthToken,
    SMRequestTokenTypeSessionMToken,
    SMRequestTokenTypeTransition,
    SMRequestTokenTypeAllBlank
};

#endif /* __SM_TOKEN_TYPE__ */
