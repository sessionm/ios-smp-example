//
//  SMBaseDelegate.h
//  SessionM
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SM_BASE_DELEGATE__
#define __SM_BASE_DELEGATE__

#import "SMError.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @const SM_MANAGER_NOTIFICATION_DATA_KEY
 @abstract Used to access relevant data from a successful Platform API notification's <code>userInfo</code> property.
 */
extern NSString *const SM_MANAGER_NOTIFICATION_DATA_KEY NS_SWIFT_NAME(kManagerNotificationData);
/*!
 @const SM_MANAGER_NOTIFICATION_ERROR_KEY
 @abstract Used to access an @link SMError @/link object from a failed Platform API notification's <code>userInfo</code>.
 */
extern NSString *const SM_MANAGER_NOTIFICATION_ERROR_KEY NS_SWIFT_NAME(kManagerNotificationError);


/*!
 @protocol SMBaseDelegate
 @abstract Defines callbacks to be implemented by delegates of the SessionM Platform SDK API Manager classes.
 */
@protocol SMBaseDelegate <NSObject>

@optional

/*!
 @abstract Notifies delegate that an API request failed.
 @param error An @link SMError @/link object containing information about why the request failed.
 @deprecated Use API methods with block-based completion handlers instead.
 */
- (void)requestDidFail:(SMError *)error __attribute__((deprecated("Use API methods with block-based completion handlers instead"))) NS_SWIFT_NAME(requestDidFail(error:));

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_BASE_DELEGATE__ */
