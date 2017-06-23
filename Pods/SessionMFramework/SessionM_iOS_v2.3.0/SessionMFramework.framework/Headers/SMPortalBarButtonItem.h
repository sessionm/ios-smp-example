//
//  SMPortalBarButtonItem.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef __SM_PORTAL_BAR_BUTTON_ITEM__
#define __SM_PORTAL_BAR_BUTTON_ITEM__

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMPortalBarButtonItem
 @abstract Portal bar button item.
 */
@interface SMPortalBarButtonItem : UIBarButtonItem

/*!
 @property presentingController
 @discussion UIViewController object to use as presenting controller for portal view controller.
 */
@property(nullable, nonatomic, strong, readwrite) UIViewController *presentingController;

/*!
 Returns new instance.
 @result New <code>SMPortalBarButtonItem</code> object
 */
+ (instancetype _Nullable)newInstance NS_SWIFT_NAME(init());

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_PORTAL_BAR_BUTTON_ITEM__ */
