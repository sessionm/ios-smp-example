//
//  SMNotificationMessage.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef __SM_NOTIFICATION_MESSAGE__
#define __SM_NOTIFICATION_MESSAGE__

#import "SMMessage.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMNotificationMessage
 @abstract Defines the data associated with a push notification or behavior notification message.
 @discussion Note: the developer can configure the following properties for each message through the SessionM Platform portal. The @link //apple_ref/occ/cl/SMDefaultMessageView @/link class is provided for presenting notification messages (note: notification messages cannot be presented inside an activity feed).
 */
@interface SMNotificationMessage : SMMessage

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_NOTIFICATION_MESSAGE__ */