//
//  SMIdentityError.h
//  SessionMIdentityKit
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SM_IDENTITY_MANAGER__
#define __SM_IDENTITY_MANAGER__

#import <SessionMCoreKit/SMBaseManager.h>
#import <SessionMCoreKit/SMError.h>

#import "SMPUser.h"
#import "SMPUserCreate.h"

NS_ASSUME_NONNULL_BEGIN

@interface SMIdentityError : SMError
@end

/*!
 @const SM_IDENTITY_MANAGER_REQUEST_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that an Identity API request failed.
 @discussion An <code>SMError</code> object containing information about why the request failed can be accessed from the notification's <code>userInfo</code> property with the <code>SM_MANAGER_NOTIFICATION_ERROR_KEY</code> key.
 */
extern NSString *const SM_IDENTITY_MANAGER_REQUEST_DID_FAIL_NOTIFICATION NS_SWIFT_NAME(identityRequestFailureNotification);
/*!
 @const SM_IDENTITY_MANAGER_VALIDATION_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that an Identity API validation failed.
 @discussion An <code>SMError</code> object containing information about why the validation failed can be accessed from the notification's <code>userInfo</code> property with the <code>SM_MANAGER_NOTIFICATION_ERROR_KEY</code> key.
 */
extern NSString *const SM_IDENTITY_MANAGER_VALIDATION_DID_FAIL_NOTIFICATION NS_SWIFT_NAME(identityValidationFailureNotification);

NS_ASSUME_NONNULL_END

#endif /* SM_IDENTITY_MANAGER */