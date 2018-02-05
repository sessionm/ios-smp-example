//
//  SMActivityViewController.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef __SM_ACTIVITY_VIEW_CONTROLLER__
#define __SM_ACTIVITY_VIEW_CONTROLLER__

#import <UIKit/UIKit.h>
#import "SessionM.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

NS_ASSUME_NONNULL_BEGIN

@class SMActivityViewController;

/*!
 @protocol SMActivityViewControllerDelegate
 @abstract Activity view controller delegate
 @deprecated mPLUS Rewards APIs are deprecated. For more information, please refer to the SessionM Platform documentation site: https://mmc.sessionm.com/docs/mmc-sdk/
 */
__attribute__((deprecated("mPLUS Rewards APIs are deprecated. For more information, please refer to the SessionM Platform documentation site: @link https://mmc.sessionm.com/docs/mmc-sdk/")))
@protocol SMActivityViewControllerDelegate<NSObject>

@optional

/*!
 @abstract Notifies that controller will start media playback.
 @param controller Activity controller object.
 */
- (void)activityControllerWillStartMedia:(SMActivityViewController *)controller NS_SWIFT_NAME(activityControllerWillStartMedia(controller:));
/*!
 @abstract Notifies that controller will finish media playback.
 @param controller Activity controller object.
 */
- (void)activityControllerDidFinishMedia:(SMActivityViewController *)controller NS_SWIFT_NAME(activityControllerDidFinishMedia(controller:));
/*!
 @abstract Notifies that controller will be dismissed by the user.
 @param controller Activity controller object.
 */
- (void)activityViewControllerWillDismiss:(SMActivityViewController *)controller NS_SWIFT_NAME(activityControllerWillDismiss(controller:));
/*!
 @abstract Notifies that controller has been dismissed by the user. 
 @param controller Activity controller object.
 */
- (void)activityViewControllerDidDismiss:(SMActivityViewController *)controller NS_SWIFT_NAME(activityControllerDidDismiss(controller:));

@end


/*!
 @class SMActivityViewController
 @abstract Activity view controller. 
 @discussion Allows presentaton of portal or interstitial content using a <code>UIViewController</code> object. This presentation methods should be used as an alternative to calling @link presentActivity: @/link on @link SessionM @/link instance if desired.
 The following restrictions apply when using activity view controller:
 <ol>
 <li>Achievement activity cannot be presented as a view controller.</li>
 </ol>
 @deprecated mPLUS Rewards APIs are deprecated. For more information, please refer to the SessionM Platform documentation site: https://mmc.sessionm.com/docs/mmc-sdk/
 */
__attribute__((deprecated("mPLUS Rewards APIs are deprecated. For more information, please refer to the SessionM Platform documentation site: @link https://mmc.sessionm.com/docs/mmc-sdk/")))
@interface SMActivityViewController : UIViewController 

/*!
 @property delegate
 @abstract Object that implements @link SMActivityViewControllerDelegate @/link callbacks.
 */
@property(nullable, nonatomic, weak) id<SMActivityViewControllerDelegate> delegate;
/*!
 @property activityType
 @abstract Activity type. By default, it is set to @link SMActivityTypePortal @/link.
 @deprecated Use method @link newInstanceWithActivityType: @/link instead.
 */
@property(nonatomic) SMActivityType activityType __attribute__((deprecated));
/*!
 @abstract Returns new activity controller object. 
 @discussion By default, controller object is configured to display user portal, @link SMActivityTypePortal @/link. To display different content application should set property @link //apple_ref/occ/instp/SMActivityViewController/activityType @/link before presenting the controller.
 @result <code>SMActivityViewController</code> object.
 @deprecated Use method @link newInstanceWithActivityType: @/link instead.
 */
+ (SMActivityViewController * _Nullable)newInstance __attribute__((deprecated)) NS_SWIFT_NAME(init());
/*!
 @abstract Returns new activity controller object with specified type or <code>nil</code> if content for specified type is not available.
 @param type Type of activity to create.
 @result <code>SMActivityViewController</code> object.
 */
+ (SMActivityViewController * _Nullable)newInstanceWithActivityType:(SMActivityType)type NS_SWIFT_NAME(init(activityType:));
/*!
 @abstract Returns new activity controller object with specified type or <code>nil</code> if content for specified type is not available. Activity will be presented in the specified navigation controller.
 @param type Type of activity to create.
 @param navigationController Navigation controller in which the created activity view controller will be presented.
 @result <code>SMActivityViewController</code> object.
 */
+ (SMActivityViewController * _Nullable)newInstanceWithActivityType:(SMActivityType)type inNavigationController:(UINavigationController * _Nullable)navigationController NS_SWIFT_NAME(init(activityType:navigationController:));
/*!
 @abstract Returns new activity controller object with specified type or <code>nil</code> if content for specified type is not available. Activity will be presented in the specified tab bar controller.
 @param type Type of activity to create.
 @param tabBarController Tab bar controller in which the created activity view controller will be presented.
 @result <code>SMActivityViewController</code> object.
 */
+ (SMActivityViewController * _Nullable)newInstanceWithActivityType:(SMActivityType)type inTabBarController:(UITabBarController *)tabBarController NS_SWIFT_NAME(init(activityType:tabBarController:));
/*!
 @abstract Returns new activity controller object with specified type or <code>nil</code> if content for specified type is not available. Activity will be presented in the specified navigation and tab bar controller.
 @param type Type of activity to create.
 @param navigationController Navigation controller in which the created activity view controller will be presented.
 @param tabBarController Tab bar controller in which the created activity view controller will be presented.
 @result <code>SMActivityViewController</code> object.
 */
+ (SMActivityViewController * _Nullable)newInstanceWithActivityType:(SMActivityType)type inNavigationController:(UINavigationController * _Nullable)navigationController inTabBarController:(UITabBarController* _Nullable)tabBarController NS_SWIFT_NAME(init(activityType:navigationController:tabBarController:));

/*!
 @abstract Disable the Close Button for the Portal View.
 */
- (void)disableCloseButton;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop

#endif /* __SM_ACTIVITY_VIEW_CONTROLLER__ */
