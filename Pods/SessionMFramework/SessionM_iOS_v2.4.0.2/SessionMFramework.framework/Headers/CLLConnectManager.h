//
//  CLLConnectManager.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//
//

#ifndef __POS_CONNECTMANAGER__
#define __POS_CONNECTMANAGER__

#import <Foundation/Foundation.h>
#import "SMGenericRequest.h"
#import "SMGenericResponse.h"
#import "SMGenericRequestManager.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @const SM_POSCONNECT_REQUEST_MANAGER_DID_SUCCEED_NOTIFICATION
 @abstract Notifies observers that an API request completed.
 */
extern NSString *const SM_POSCONNECT_REQUEST_MANAGER_DID_SUCCEED_NOTIFICATION NS_SWIFT_NAME(posConnectRequestSuccessNotification);

/*!
 @typedef onRequestComplete
 @abstract Completion handler block type for LoyalTree requests
 */
typedef void (^onRequestComplete)(id _Nullable response, SMError * _Nullable error, NSDictionary * _Nullable other, NSDictionary * _Nullable raw) NS_SWIFT_NAME(ExecuteGenericRequestCompletionHandler);

/*!
 @class CLLConnectManager
 @abstract This API manager supports calls to LoyalTree system.
 */
@interface CLLConnectManager : NSObject

+(CLLConnectManager *)instance;

/*!
 @abstract accountGet:onComplete Makes a call to LoyalTree /ext/account/get.
 @discussion Populates standard values for a LoyalTree call, then adds userID
 @param userID UserID for request @link SMMMCUser.externalID @/link
 @param onComplete on completion of call @link onRequestComplete @/link
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
-(BOOL)accountGet:(NSString *)userID onComplete:(onRequestComplete)onComplete;
/*!
 @abstract accountRewardsGet:skip:take:onComplete Makes a call to LoyalTree /ext/account/rewards/get.
 @discussion Populates standard values list of rewards for specified user
 @param userID UserID for request @link SMMMCUser.externalID @/link
 @param skip ???
 @param take ???
 @param onComplete on completion of call @link onRequestComplete @/link
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
-(BOOL)accountRewardsGet:(NSString *)userID skip:(int)skip take:(int)take onComplete:(onRequestComplete)onComplete;

-(BOOL)accountRewardClaim:(NSString *)userID rewardID:(NSString *)rewardID onComplete:(onRequestComplete)onComplete;

@end

NS_ASSUME_NONNULL_END

#endif
