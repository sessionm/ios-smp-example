//
//  SMContentManager.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef __SM_CONTENT_MANAGER__
#define __SM_CONTENT_MANAGER__

#import <Foundation/Foundation.h>
#import "SMBaseDelegate.h"
#import "SMContent.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @const SM_CONTENT_MANAGER_REQUEST_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that an API request failed.
 @discussion An @link SMError @/link object containing information about why the request failed can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_ERROR_KEY @/link key.
 */
extern NSString *const SM_CONTENT_MANAGER_REQUEST_DID_FAIL_NOTIFICATION NS_SWIFT_NAME(contentRequestFailureNotification);
/*!
 @const SM_CONTENT_MANAGER_VALIDATION_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that a Content API validation failed.
 @discussion An @link SMError @/link object containing information about why the validation failed can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_ERROR_KEY @/link key.
 */
extern NSString *const SM_CONTENT_MANAGER_VALIDATION_DID_FAIL_NOTIFICATION NS_SWIFT_NAME(campaignsValidationFailureNotification);
/*!
 @const SM_CONTENT_MANAGER_DID_FETCH_CONTENTS_NOTIFICATION
 @abstract Notifies observers that content records were fetched.
 @discussion An <code>NSArray</code> of @link SMContent @/link objects can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_DATA_KEY @/link key.
 */
extern NSString *const SM_CONTENT_MANAGER_DID_FETCH_CONTENTS_NOTIFICATION NS_SWIFT_NAME(fetchedContentsNotification);
/*!
 @const SM_CONTENT_MANAGER_DID_FETCH_SINGLE_CONTENT_NOTIFICATION
 @abstract Notifies observers that a content record was fetched.
 @discussion An @link SMContent @/link object representing the content data can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_DATA_KEY @/link key. */
extern NSString *const SM_CONTENT_MANAGER_DID_FETCH_SINGLE_CONTENT_NOTIFICATION NS_SWIFT_NAME(fetchedSingleContentNotification);

/*!
 @typedef didFetchContents
 @abstract Completion handler block type for @link fetchContentsWithCompletionHandler: @/link and @link fetchContentsForPlacement:limit:page:completionHandler: @/link.
 */
typedef void (^didFetchContents)(NSArray<SMContent *> * _Nullable messages, NSString * _Nullable placement, SMError * _Nullable error) NS_SWIFT_NAME(FetchContentsCompletionHandler);
/*!
 @typedef didFetchSingleContent
 @abstract Completion handler block type for @link fetchSingleContentWithID:completionHandler: @/link and @link fetchSingleContentWithExternalID:completionHandler: @/link.
 */
typedef void (^didFetchSingleContent)(SMContent * _Nullable message, SMError * _Nullable error) NS_SWIFT_NAME(FetchSingleContentCompletionHandler);

/*!
 @class SMContentManager
 @abstract This API manager contains methods for fetching promotional content data records.
 */
@interface SMContentManager : NSObject

+(SMContentManager *)instance;

/*!
 @property contents
 @abstract Promotional content data records.
 @discussion This property is updated in response to a successful @link fetchContentsWithCompletionHandler: @/link or @link fetchContentsForPlacement:limit:page:completionHandler: @/link call.
 */
@property(nonatomic, strong, readonly) NSArray<SMContent *> *contents;

/*!
 @abstract Makes a request to update @link contents @/link with content records.
 @param completionHandler The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)fetchContentsWithCompletionHandler:(didFetchContents)completionHandler NS_SWIFT_NAME(fetchContents(completionHandler:));
/*!
 @abstract Makes a request to update @link contents @/link with a limited number of content records that have the specified content feed placement value.
 @param placement Filters the fetched content records based on where the containing content feed is displayed (e.g. "front_page") (optional).
 @param limit The maximum amount of content records to fetch (optional).
 @param page <code>limit * (page-1)</code> most recent content records will be skipped for the fetch (optional).
 @param completionHandler The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)fetchContentsForPlacement:(NSString * _Nullable)placement limit:(NSInteger)limit page:(NSInteger)page completionHandler:(didFetchContents)completionHandler NS_SWIFT_NAME(fetchContents(havingPlacement:limit:page:completionHandler:));
/*!
 @abstract Makes a request to fetch the content record with the specified identifier.
 @param contentID The identifier of the content record to be fetched.
 @param completionHandler The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)fetchSingleContentWithID:(NSString *)contentID completionHandler:(didFetchSingleContent)completionHandler NS_SWIFT_NAME(fetchContent(havingID:completionHandler:));
/*!
 @abstract Makes a request to fetch the content record with the specified external (developer-defined) identifier.
 @param externalID The external identifier of the content record to be fetched.
 @param completionHandler The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)fetchSingleContentWithExternalID:(NSString *)externalID completionHandler:(didFetchSingleContent)completionHandler NS_SWIFT_NAME(fetchContent(havingExternalID:completionHandler:));

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_CONTENT_MANAGER__ */
