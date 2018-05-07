// 
//  SessionMOauthProviderIDP.h
//
//  Copyright © 2018 SessionM. All rights reserved.
//
//

#ifndef __SessionM_OAuth_Provider__
#define __SessionM_OAuth_Provider__

#import <Foundation/Foundation.h>
#import <SessionMCoreKit/SessionMCoreKit.h>
#import "SMIdentityError.h"
#import "SMPUserCreate.h"

NS_ASSUME_NONNULL_BEGIN

NSString *const SM_IDENTITY_MANAGER_REQUEST_DID_FAIL_NOTIFICATION = @"com.sessionm.identity.manager.request.did.fail";
/*!
 @const SM_IDENTITY_MANAGER_DID_UPDATE_AUTH_STATE
 @abstract Notifies observers that the current user authentication state has been updated.
 @discussion An <code>NSNumber</code> object representing the user's authentication state can be accessed from the notification's <code>userInfo</code> property with the <code>SM_MANAGER_NOTIFICATION_DATA_KEY</code> key.
 */
extern NSString *const SM_IDENTITY_MANAGER_DID_UPDATE_AUTH_STATE NS_SWIFT_NAME(updatedAuthStateNotification);

typedef void(^AccessTokenCallback)(NSString * _Nullable accessToken, SMError * _Nullable error);
typedef void(^AuthCodeCallback)(NSString *_Nullable authCode, SMError * _Nullable error);
typedef void(^didUpdateAuthState)(SMAuthState state, SMError * _Nullable error);

@interface SessionMOauthProviderIDP : NSObject <SMAuthenticationProvider>

@property (nonatomic, assign)BOOL needsRefresh;

/*!
 @abstract Gets the current user's access token (refreshing it if necessary), and passes it to the specified <code>AccessTokenHandler</code> handler.
 @discussion You should assume that the access token changes between invocations of this method.
 @param onComplete The block that will be called with the current user's access token.
 */
-(void)getAccessTokenOnComplete:(AccessTokenCallback)onComplete;
/*!
 @abstract Makes a request to fetch the current user's authentication code.
 @discussion This is a special case feature - please confer with the SessionM SDK team for more details.
 @param onComplete The block to execute after the request is processed.
 */
-(void)requestAuthCodeOnComplete:(AuthCodeCallback)onComplete;

/*!
 @abstract Makes a request to log out the current user.
 @param onComplete The block to execute after the request is processed.
 */
-(void)logoutUserOnComplete:(_Nullable didUpdateAuthState)onComplete;

@end

NS_ASSUME_NONNULL_END

#endif
