//
//  SMNotificationMessage.h
//  SessionMMessagesKit
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SM_NOTIFICATION_MESSAGE__
#define __SM_NOTIFICATION_MESSAGE__

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @typedef SMNotificationMessageActionType
 @abstract Determines how message content is displayed.

 @constant SMNotificationMessageActionTypeUnknown Unknown action type.
 @constant SMNotificationMessageActionTypeOpenApp Launches app with no additional action.
 @constant SMNotificationMessageActionTypeDeepLink Deep links into app.
 @constant SMNotificationMessageActionTypeFullScreen Presents full screen rich media message.
 @constant SMNotificationMessageActionTypeExternalLink Opens link in Safari.
 */
typedef NS_ENUM(NSInteger, SMNotificationMessageActionType) {
    SMNotificationMessageActionTypeUnknown NS_SWIFT_NAME(unknown),
    SMNotificationMessageActionTypeOpenApp NS_SWIFT_NAME(openApp),
    SMNotificationMessageActionTypeDeepLink NS_SWIFT_NAME(deepLink),
    SMNotificationMessageActionTypeFullScreen NS_SWIFT_NAME(fullScreen),
    SMNotificationMessageActionTypeExternalLink NS_SWIFT_NAME(externalLink)
};

/*!
 @class SMNotificationMessage
 @abstract Defines the data associated with a push notification or behavior notification message.
 @discussion Note: the developer can configure the following properties for each message through the SessionM Platform portal.
 */
@interface SMNotificationMessage : NSObject

/*!
 @property title
 @abstract Notification message title.
 */
@property(nullable, nonatomic, strong, readonly) NSString *title;
/*!
 @property body
 @abstract Notification message body.
 */
@property(nullable, nonatomic, strong, readonly) NSString *body;
/*!
 @property actionType
 @abstract Determines how the content pointed to by <code>actionURL</code> is displayed when <code>SMMessagesManager executePendingNotificationAction</code> or <code>SMMessagesManager executeActionForNotification:</code> is called.
 */
@property(nonatomic, assign, readonly) SMNotificationMessageActionType actionType;
/*!
 @property actionURL
 @abstract URL for content that is displayed when <code>SMMessagesManager executePendingNotificationAction</code> or <code>SMMessagesManager executeActionForNotification:</code> is called.
 */
@property(nullable, nonatomic, strong, readonly) NSString *actionURL;

/*!
 @property extras
 @abstract Any data values that do not have an associated class property.
 */
@property(nullable, nonatomic, strong, readonly) NSDictionary<NSString *, id> *extras;

/*!
 @abstract Converts specified string value to the corresponding <code>SMNotificationMessageActionType</code> enum value.
 @param string String to convert.
 @result <code>SMNotificationMessageActionType</code> enum value.
 */
+ (SMNotificationMessageActionType)typeForString:(NSString *)string NS_SWIFT_NAME(actionType(from:));
/*!
 @abstract Converts specified <code>SMNotificationMessageActionType</code> enum value to the corresponding string value.
 @param type Type to convert.
 @result <code>NSString</code> value.
 */
+ (NSString *)stringForType:(SMNotificationMessageActionType)type NS_SWIFT_NAME(string(from:));

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_NOTIFICATION_MESSAGE__ */
