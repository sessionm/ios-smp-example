//
//  SMUserTagsManager.h
//  SessionMIdentityKit
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SM_USER_TAGS_MANAGER__
#define __SM_USER_TAGS_MANAGER__

#import <SessionMCoreKit/SMBaseManager.h>
#import <SessionMCoreKit/SMError.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @const SM_USER_TAGS_MANAGER_REQUEST_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that a User Tags API request failed.
 @discussion An <code>SMError</code> object containing information about why the request failed can be accessed from the notification's <code>userInfo</code> property with the <code>SM_MANAGER_NOTIFICATION_ERROR_KEY</code> key.
 */
extern NSString *const SM_USER_TAGS_MANAGER_REQUEST_DID_FAIL_NOTIFICATION NS_SWIFT_NAME(userTagsRequestFailureNotification);
/*!
 @const SM_USER_TAGS_MANAGER_VALIDATION_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that a User Tags API validation failed.
 @discussion An <code>SMError</code> object containing information about why the validation failed can be accessed from the notification's <code>userInfo</code> property with the <code>SM_MANAGER_NOTIFICATION_ERROR_KEY</code> key.
 */
extern NSString *const SM_USER_TAGS_MANAGER_VALIDATION_DID_FAIL_NOTIFICATION NS_SWIFT_NAME(userTagsValidationFailureNotification);
/*!
 @const SM_USER_TAGS_MANAGER_DID_FETCH_USER_TAGS
 @abstract Notifies observers that tag data for the current user was fetched.
 @discussion An <code>NSDictionary</code> object containing information about the current user's tags can be accessed from the notification's <code>userInfo</code> property with the <code>SM_MANAGER_NOTIFICATION_DATA_KEY</code> key.
 */
extern NSString *const SM_USER_TAGS_MANAGER_DID_FETCH_USER_TAGS NS_SWIFT_NAME(fetchedUserTagsNotification);
/*!
 @const SM_USER_TAGS_MANAGER_DID_UPDATE_USER_TAGS
 @abstract Notifies observers that tag data for the current user was updated.
 @discussion An <code>NSDictionary</code> object containing information about the current user's tags can be accessed from the notification's <code>userInfo</code> property with the <code>SM_MANAGER_NOTIFICATION_DATA_KEY</code> key.
 */
extern NSString *const SM_USER_TAGS_MANAGER_DID_UPDATE_USER_TAGS NS_SWIFT_NAME(updatedUserTagsNotification);


/*!
 @typedef didFetchUserTags
 @abstract Completion handler block type for <code>fetchUserTagsWithCompletionHandler:</code>.
 */
typedef void (^didFetchUserTags)(NSDictionary<NSString *, id> * _Nullable tags, SMError * _Nullable error) NS_SWIFT_NAME(FetchUserTagsCompletionHandler);
/*!
 @typedef didUpdateUserTags
 @abstract Completion handler block type for <code>updateUserTags:timeToLive:completionHandler:</code>.
 */
typedef void (^didUpdateUserTags)(NSDictionary<NSString *, id> * _Nullable tags, SMError * _Nullable error) NS_SWIFT_NAME(UpdateUserTagsCompletionHandler);


/*!
 @class SMUserTagsManager
 @abstract This API manager contains methods for fetching and updating user tags, which can be used to define segments of customers.
 */
@interface SMUserTagsManager : SMBaseManager

/*!
 @abstract Makes a request to fetch the current user's tag data.
 @param completionHandler The block to execute after the request is processed.
 */
- (void)fetchUserTagsWithCompletionHandler:(didFetchUserTags)completionHandler NS_SWIFT_NAME(fetchUserTags(completionHandler:));
/*!
 @abstract Makes a request to update the current user's tag data.
 @param updates Data changes to make.
 @param timeToLive How long this change will be in effect on the server.
 @param completionHandler The block to execute after the request is processed.
 */
- (void)updateUserTags:(NSArray<NSString *> *)updates timeToLive:(NSInteger)timeToLive completionHandler:(didUpdateUserTags)completionHandler NS_SWIFT_NAME(updateUserTags(updates:timeToLive:completionHandler:));

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_USER_TAGS_MANAGER__ */
