//
//  SMWebProfileManager.h
//  SessionM
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SM_WEB_PROFILE_MANAGER__
#define __SM_WEB_PROFILE_MANAGER__

#import <Foundation/Foundation.h>
#import <UIKit/UIViewController.h>

#import "SMError.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @const SM_WEB_PROFILE_MANAGER_VALIDATION_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that a User Web Profile API validation failed.
 @discussion An @link SMError @/link object containing information about why the validation failed can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_ERROR_KEY @/link key.
 */
extern NSString *const SM_WEB_PROFILE_MANAGER_VALIDATION_DID_FAIL_NOTIFICATION NS_SWIFT_NAME(webProfileValidationFailureNotification);

/*!
 @typedef PresentationHandler
 @abstract Completion handler block type called after an instance of <code>SFSafariViewController</code> is presented.
 */
typedef void (^PresentationHandler)(SMError * _Nullable error);
/*!
 @typedef DismissalHandler
 @abstract Completion handler block type called after an instance of <code>SFSafariViewController</code> is dismissed.
 */
typedef void (^DismissalHandler)();

/*!
 @class SMWebProfileManager
 @abstract This API manager contains methods for viewing web pages relating to a user's profile (e.g. updating a user's account data, resetting a user's password, etc.).
 */
@interface SMWebProfileManager : NSObject

/*!
 @abstract Singleton that interfaces with the SessionM Platform User Web Profile API.
 @result <code>SMWebProfileManager</code> service object.
 */
+ (SMWebProfileManager *)instance;

/*!
 @abstract Presents an instance of <code>SFSafariViewController</code> (the Safari app is opened instead on iOS 8 devices) that points to a web page where the user's account information can be viewed and updated.
 @discussion The user must be authenticated before this method is called.
 @param presenting View controller to use to present the <code>SFSafariViewController</code> instance.
 @param presentationHandler Block called after the <code>SFSafariViewController</code> instance is presented - or if an error is encountered during presentation.
 @param dismissalHandler Block called after the <code>SFSafariViewController</code> instance is dismissed.
 */
- (void)updateUserProfileInViewController:(UIViewController *)presenting presentationHandler:(_Nullable PresentationHandler)presentationHandler dismissalHandler:(_Nullable DismissalHandler)dismissalHandler NS_SWIFT_NAME(updateUserProfile(in:presentationHandler:dismissalHandler:));

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_WEB_PROFILE_MANAGER__ */
