//
//  SMGenericRequestManager.h
//  SessionMCoreKit
//
//  Copyright © 2018 SessionM. All rights reserved.
//
//

#ifndef __SM_GENERIC_REQUEST_MANAGER__
#define __SM_GENERIC_REQUEST_MANAGER__

#import <Foundation/Foundation.h>

#import "SMBaseManager.h"
#import "SMGenericRequestBuilder.h"
#import "SMGenericResponse.h"
#import "SMError.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @const SM_GENERIC_REQUEST_MANAGER_REQUEST_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that an API request failed.
 @discussion An <code>SMError</code> object containing information about why the request failed can be accessed from the notification's <code>userInfo</code> property with the <code>SM_MANAGER_NOTIFICATION_ERROR_KEY</code> key.
 */
extern NSString *const SM_GENERIC_REQUEST_MANAGER_REQUEST_DID_FAIL_NOTIFICATION NS_SWIFT_NAME(genericRequestFailureNotification);
/*!
 @const SM_GENERIC_REQUEST_MANAGER_DID_SUCCEED_NOTIFICATION
 @abstract Notifies observers that an API request succeeded.
 @discussion An <code>SMGenericResponse</code> object containing information about the request response can be accessed from the notification's <code>userInfo</code> property with the <code>SM_GENERIC_REQUEST_MANAGER_NOTIFICATION_RESPONSE_KEY</code> key.
 */
extern NSString *const SM_GENERIC_REQUEST_MANAGER_DID_SUCCEED_NOTIFICATION NS_SWIFT_NAME(genericRequestSuccessNotification);
/*!
 @const SM_GENERIC_REQUEST_MANAGER_NOTIFICATION_RESPONSE_KEY
 @abstract Used to access response data from a successful generic request notification's <code>userInfo</code> property.
 */
extern NSString *const SM_GENERIC_REQUEST_MANAGER_NOTIFICATION_RESPONSE_KEY NS_SWIFT_NAME(kGenericManagerNotificationResponse);


/*!
 @typedef CompletionHandler
 @abstract Completion handler block type for <code>sendRequest:completionHandler:</code>.
 */
typedef void(^CompletionHandler)(NSString *kind, SMGenericResponse * _Nullable response, SMError * _Nullable error, NSDictionary * _Nullable other);


/*!
 @class SMGenericRequestManager
 @abstract This class supports sending generic SessionM Platform HTTP requests.
 */
@interface SMGenericRequestManager : SMBaseManager

/*!
 @abstract Sends an HTTP request with the specified completion handler.
 @param genericRequest Request to be sent.
 @param completionHandler The block to execute after the request is processed.
 */
- (void)sendRequest:(SMGenericRequest * _Nonnull)genericRequest completionHandler:(CompletionHandler _Nonnull)completionHandler;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_GENERIC_REQUEST_MANAGER__ */
