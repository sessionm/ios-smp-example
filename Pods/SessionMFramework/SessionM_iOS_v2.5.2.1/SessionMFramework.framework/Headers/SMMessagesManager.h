//
//  SMMessagesManager.h
//  SessionM
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SM_MESSAGES_MANAGER__
#define __SM_MESSAGES_MANAGER__

#import <Foundation/Foundation.h>
#import "SMNotificationMessage.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @typedef NotificationHandler
 @abstract Completion handler block type for @link handleRemoteNotification:handler: @/link.
 */
typedef void (^NotificationHandler)(BOOL success, SMNotificationMessage * _Nullable notification);

/*!
 @class SMMessagesManager
 @abstract This API manager contains methods for registering for and handling remote notifications.
 */
@interface SMMessagesManager : NSObject

/*!
 @property pendingNotification
 @abstract The most recent notification passed to @link handleRemoteNotification:handler: @/link.
 @discussion This property will be set to <code>nil</code> after a successful call to @link executePendingNotificationAction @/link or @/link executeActionForNotification: @/link.
 */
@property(nullable, nonatomic, strong, readonly) SMNotificationMessage *pendingNotification;
/*!
 @property hasPendingNotificationAction
 @discussion If a notification with an action was received but has not yet been executed, then this property will return <code>YES</code>. Otherwise it will return <code>NO</code>.
 */
@property(nonatomic, assign, readonly) BOOL hasPendingNotificationAction;

/*!
 @abstract Singleton that interfaces with notification messaging services such as Apple Push Notification service, Firebase Cloud Messaging, and Google Cloud Messaging.
 @result <code>SMMessagesManager</code> service object.
 */
+ (SMMessagesManager *)instance;

/*!
 @abstract Request user's permission to send remote notifications of all types.
 @discussion This method should be called from the developer's <code>application:didFinishLaunchingWithOptions:</code> delegate method.
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
 @discussion This method should be called with the given device token from the developer's <code>application:didRegisterForRemoteNotificationsWithDeviceToken:</code> delegate method. Note: this method cannot be used simultaneously with @link storePushRegistrationToken: @/link.
 @param token The user's device token.
 */
- (void)storeDeviceToken:(NSData *)token NS_SWIFT_NAME(storeDeviceToken(_:));
/*!
 @abstract Stores user's Firebase or Google Cloud Messaging registration token (required for users to receive remote notifications through FCM/GCM).
 @discussion This method should be called with the given registration token from the developer's <code>messaging:didRefreshRegistrationToken:</code> delegate method (or if using Google Cloud Messaging - from the registration handler in any calls to <code>tokenWithAuthorizedEntity:scope:options:handler:</code>). Note: this method cannot be used simultaneously with @link storeDeviceToken: @/link.
 @param token The user's registration token.
 */
- (void)storePushRegistrationToken:(NSString *)token NS_SWIFT_NAME(storePushRegistrationToken(_:));
/*!
 @abstract Executes the action associated with @link pendingNotification @/link.
 @discussion Performs the pending notification action as specified by @link //apple_ref/occ/instp/SMNotificationMessage/actionType @/link.
 */
- (void)executePendingNotificationAction;
/*!
 @abstract Executes the action associated with the specified notification message.
 @param notification The @link SMNotificationMessage @/link instance whose action will be executed.
 @discussion Performs the specified notification's action as specified by @link //apple_ref/occ/instp/SMNotificationMessage/actionType @/link.
 */
- (void)executeActionForNotification:(SMNotificationMessage *)notification NS_SWIFT_NAME(executeAction(for:));

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_MESSAGES_MANAGER__ */
