//
//  SMEventNotification.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef __SM_EVENT_NOTIFICATION__
#define __SM_EVENT_NOTIFICATION__

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMEventNotification
 @abstract Defines the data associated with a notification to be presented to the user as a result of posting an event to the SessionM Platform.
 */
@interface SMEventNotification : NSObject

/*!
 @property notificationID
 @abstract Unique identifier for the notification.
 */
@property(nonatomic, strong, readonly) NSString *notificationID;
/*!
 @property campaignID
 @abstract Unique identifier for the campaign targeted by the event.
 */
@property(nonatomic, strong, readonly) NSString *campaignID;
/*!
 @property notificationType
 @abstract Type of notification.
 */
@property(nonatomic, strong, readonly) NSString *notificationType;
/*!
 @property behaviorName
 @abstract Name of the behavior associated with the event.
 */
@property(nonatomic, strong, readonly) NSString *behaviorName;
/*!
 @property actionType
 @abstract Determines how the content pointed to by @link actionURL @/link is displayed.
 */
@property(nullable, nonatomic, strong, readonly) NSString *actionType;
/*!
 @property actionURL
 @abstract Notification message URL.
 */
@property(nullable, nonatomic, strong, readonly) NSString *actionURL;
/*!
 @property message
 @abstract Notification message body.
 */
@property(nullable, nonatomic, strong, readonly) NSString *message;
/*!
 @property payload
 @abstract Customer-defined creative content associated with the campaign.
 */
@property(nullable, nonatomic, strong, readonly) NSDictionary<NSString *, NSObject *> *payload;
/*!
 @property data
 @abstract Additional data associated with the notification.
 */
@property(nullable, nonatomic, strong, readonly) id data;
/*!
 @property extras
 @abstract Any data values that do not have an associated class property.
 */
@property(nullable, nonatomic, strong, readonly) NSDictionary<NSString *, NSObject *> *extras;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_EVENT_NOTIFICATION__ */
