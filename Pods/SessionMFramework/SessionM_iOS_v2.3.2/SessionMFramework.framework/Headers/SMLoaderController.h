//
//  SMLoaderController.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef __SM_LOADER_CONTROLLER__
#define __SM_LOADER_CONTROLLER__

#import <UIKit/UIKit.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

NS_ASSUME_NONNULL_BEGIN

/*!
 @typedef SMLoaderControllerLoadStatus
 @abstract Status of the current load.

 @constant SMLoaderControllerLoadStatusLoading Indicates portal content is loading.
 @constant SMLoaderControllerLoadStatusFailed Indicates session is online, but content could not be reached.
 @constant SMLoaderControllerLoadStatusUnavailable Indicates content is unavailable (because session is not online, etc.).
 @deprecated mPLUS Rewards APIs are deprecated. For more information, please refer to the SessionM Platform documentation site: https://mmc.sessionm.com/docs/mmc-sdk/
 */
__attribute__((deprecated("mPLUS Rewards APIs are deprecated. For more information, please refer to the SessionM Platform documentation site: @link https://mmc.sessionm.com/docs/mmc-sdk/")))
typedef NS_ENUM(NSInteger, SMLoaderControllerLoadStatus) {
    SMLoaderControllerLoadStatusLoading NS_SWIFT_NAME(loading) = 100,
    SMLoaderControllerLoadStatusFailed NS_SWIFT_NAME(failed) = 101,
    SMLoaderControllerLoadStatusUnavailable NS_SWIFT_NAME(unavailable) = 102
};


/*!
 @class SMLoaderController
 @abstract View controller for portal load screen.
 @discussion This class encapsulates the view that is displayed when portal content is being loaded, along with the state and behavior associated with that view. A developer who is implementing a custom load screen must subclass this class and override the @link updateViewForLoadStatus: @/link method to use their custom view.
 @deprecated mPLUS Rewards APIs are deprecated. For more information, please refer to the SessionM Platform documentation site: https://mmc.sessionm.com/docs/mmc-sdk/
 */
__attribute__((deprecated("mPLUS Rewards APIs are deprecated. For more information, please refer to the SessionM Platform documentation site: @link https://mmc.sessionm.com/docs/mmc-sdk/")))
@interface SMLoaderController : UIViewController

/*!
 @property loadStatus
 @abstract SMLoaderControllerLoadStatus - represents the status of the current load.
 */
@property(nonatomic, assign, readonly) SMLoaderControllerLoadStatus loadStatus;

/*!
 @abstract Updates the view based on the current load status.
 @discussion Called when the value of @link loadStatus @/link changes. This method should not be called directly, but the developer should override it to update their custom view based on the current load status.
 @param status Current load status.
 */
- (void)updateViewForLoadStatus:(SMLoaderControllerLoadStatus)status NS_SWIFT_NAME(updateView(for:));
/*!
 @abstract Attempts to reload the portal content after a failed attempt.
 @discussion Called by the developer when implementing a custom load screen. Note: this method has no effect unless the current load status is @link SMLoaderControllerLoadStatusFailed @/link.
 */
- (void)reloadPortalContent;
/*!
 @abstract Dismisses the portal.
 @discussion Called by the developer when implementing a custom load screen.
 */
- (void)dismissPortal;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop

#endif /* __SM_LOADER_CONTROLLER__ */
