//
//  SMPUtils.h
//  SessionMCoreKit
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SMP_UTILS__
#define __SMP_UTILS__

#import "SMError.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @const SM_MANAGER_NOTIFICATION_DATA_KEY
 @abstract Used to access relevant data from a successful Platform API notification's <code>userInfo</code> property.
 */
extern NSString *const SM_MANAGER_NOTIFICATION_DATA_KEY NS_SWIFT_NAME(kManagerNotificationData);
/*!
 @const SM_MANAGER_NOTIFICATION_ERROR_KEY
 @abstract Used to access an <code>SMError</code> object from a failed Platform API notification's <code>userInfo</code>.
 */
extern NSString *const SM_MANAGER_NOTIFICATION_ERROR_KEY NS_SWIFT_NAME(kManagerNotificationError);

NS_ASSUME_NONNULL_END

#endif /* __SMP_UTILS__ */
