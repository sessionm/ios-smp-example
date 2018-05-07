//
//  SMMessagesManager.h
//  SessionMMessagesKit
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SM_MESSAGES_MANAGER__
#define __SM_MESSAGES_MANAGER__

#import <Foundation/Foundation.h>
#import <SessionMCoreKit/SMBaseManager.h>

#import "SMNotificationMessage.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @const SM_MESSAGES_MANAGER_REQUEST_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that a Messages API request failed.
 @discussion An <code>SMError</code> object containing information about why the request failed can be accessed from the notification's <code>userInfo</code> property with the <code>SM_MANAGER_NOTIFICATION_ERROR_KEY</code> key.
 */
extern NSString *const SM_MESSAGES_MANAGER_REQUEST_DID_FAIL_NOTIFICATION NS_SWIFT_NAME(messagesRequestFailureNotification);

/*!
 @typedef SMPushEnvironment
 @abstract Push environment.

 @constant SMPushEnvironmentLive Live (production/release) push environment.
 @constant SMPushEnvironmentSandbox Sandbox (development/debug) push environment.
 */
typedef NS_ENUM (NSInteger, SMPushEnvironment) {
    SMPushEnvironmentLive NS_SWIFT_NAME(live),
    SMPushEnvironmentSandbox NS_SWIFT_NAME(sandbox)
};

/*!
 @typedef NotificationHandler
 @abstract Completion handler block type for <code>handleRemoteNotification:handler:</code>.
 */
typedef void (^NotificationHandler)(BOOL success, SMNotificationMessage * _Nullable notification);


/*!
 @class SMMessagesManager
 @abstract This API manager contains methods for registering for and handling remote notifications.
 */
@interface SMMessagesManager : SMBaseManager

/*!
 @abstract Returns the currently set push environment (the default value is <code>SMPushEnvironmentLive</code>).
 @result Currently set push environment.
 */
+ (SMPushEnvironment)pushEnvironment;
/*!
 @abstract Sets the current push environment.
 @discussion Before starting the SDK, use this method to set the push environment based on the <code>DEBUG</code> preprocessor macro. This value is used to notify our servers whether the sandbox or live environment should be used when connecting to the Apple Push Notification service.
 @param environment The new push environment value.
 */
+ (void)setPushEnvironment:(SMPushEnvironment)environment;

/*!
 @property pendingNotification
 @abstract The most recent notification passed to <code>handleRemoteNotification:handler:</code>.
 @discussion This property will be set to <code>nil</code> after a successful call to <code>executePendingNotificationAction</code> or @/link executeActionForNotification: @/link.
 */
@property(nullable, nonatomic, strong, readonly) SMNotificationMessage *pendingNotification;
/*!
 @property hasPendingNotificationAction
 @discussion If a notification with an action was received but has not yet been executed, then this property will return <code>YES</code>. Otherwise it will return <code>NO</code>.
 */
@property(nonatomic, assign, readonly) BOOL hasPendingNotificationAction;

/*!
 @abstract Request user's permission to send remote notifications of all types.
 @discussion This method should be called when the developer is ready to prompt the user for permission to send remote notifications. If the user gives permission, this method should be called from the developer's <code>application:didFinishLaunchingWithOptions:</code> delegate method on subsequent app launches in case the user's device token has changed.
 */
- (void)registerForRemoteNotifications;
/*!
 @abstract Checks if the given remote notification was sent by the SessionM Platform.
 @discussion This method should be called from the developer's <code>application:didReceiveRemoteNotification:</code> and <code>application:didFinishLaunchingWithOptions:</code> delegate methods with the respective <code>userInfo</code> or <code>launchOptions</code> payload. If the payload contains a SessionM Platform notification, then an <code>SMNotificationMessage</code> object will be returned to the developer via the <code>handler</code> parameter - and the <code>success</code> boolean will be set to <code>YES</code>.
 @param payload The <code>NSDictionary</code> payload data.
 @param handler The handler block to be called after processing the notification payload.
 @result <code>BOOL</code> indicating whether notification was sent by the SessionM Platform.
 */
- (BOOL)handleRemoteNotification:(NSDictionary<NSString *, id> *)payload handler:(_Nullable NotificationHandler)handler NS_SWIFT_NAME(handleRemoteNotification(payload:handler:));
/*!
 @abstract Stores user's Apple Push Notification Service device token (required for users to receive remote notifications through APNS).
 @discussion This method should be called with the given device token from the developer's <code>application:didRegisterForRemoteNotificationsWithDeviceToken:</code> delegate method. Note: this method cannot be used simultaneously with <code>storePushRegistrationToken:</code>.
 @param token The user's device token.
 */
- (void)storeDeviceToken:(NSData *)token NS_SWIFT_NAME(storeDeviceToken(_:));
/*!
 @abstract Stores user's Firebase or Google Cloud Messaging registration token (required for users to receive remote notifications through FCM/GCM).
 @discussion This method should be called with the given registration token from the developer's <code>messaging:didRefreshRegistrationToken:</code> delegate method (or if using Google Cloud Messaging - from the registration handler in any calls to <code>tokenWithAuthorizedEntity:scope:options:handler:</code>). Note: this method cannot be used simultaneously with <code>storeDeviceToken:</code>.
 @param token The user's registration token.
 */
- (void)storePushRegistrationToken:(NSString *)token NS_SWIFT_NAME(storePushRegistrationToken(_:));
/*!
 @abstract Executes the action associated with <code>pendingNotification</code>.
 @discussion Performs the pending notification action as specified by <code>SMNotificationMessage actionType</code>.
 */
- (void)executePendingNotificationAction;
/*!
 @abstract Executes the action associated with the specified notification message.
 @param notification The <code>SMNotificationMessage</code> instance whose action will be executed.
 @discussion Performs the specified notification's action as specified by <code>SMNotificationMessage actionType</code>.
 */
- (void)executeActionForNotification:(SMNotificationMessage *)notification NS_SWIFT_NAME(executeAction(for:));

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_MESSAGES_MANAGER__ */
