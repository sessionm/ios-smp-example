//
//  SMEventsManager.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef __SM_EVENTS_MANAGER__
#define __SM_EVENTS_MANAGER__

#import "SMActivityEventBuilder.h"
#import "SMActivityEventItemBuilder.h"
#import "SMBehaviorProgressFetchedResponse.h"
#import "SMEventPostedResponse.h"
#import "SMError.h"
#import "SMPurchaseEventBuilder.h"
#import "SMPurchaseEventItemBuilder.h"
#import "SMSimpleEventBuilder.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @const SM_EVENTS_MANAGER_REQUEST_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that an Events API request failed.
 @discussion An @link SMError @/link object containing information about why the request failed can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_ERROR_KEY @/link key.
 */
extern NSString *const SM_EVENTS_MANAGER_REQUEST_DID_FAIL_NOTIFICATION NS_SWIFT_NAME(eventsRequestFailureNotification);
/*!
 @const SM_EVENTS_MANAGER_DID_FETCH_BEHAVIOR_PROGRESS_NOTIFICATION
 @abstract Notifies observers that the user's behavior progress updates were fetched.
 @discussion An @link SMBehaviorProgressFetchedResponse @/link object can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_DATA_KEY @/link key.
 */
extern NSString *const SM_EVENTS_MANAGER_DID_FETCH_BEHAVIOR_PROGRESS_NOTIFICATION NS_SWIFT_NAME(fetchedBehaviorProgressNotification);
/*!
 @const SM_EVENTS_MANAGER_DID_POST_EVENT_NOTIFICATION
 @abstract Notifies observers that an event was posted to the SessionM Platform.
 @discussion An @link SMEventPostedResponse @/link object can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_DATA_KEY @/link key.
 */
extern NSString *const SM_EVENTS_MANAGER_DID_POST_EVENT_NOTIFICATION NS_SWIFT_NAME(postedEventNotification);

/*!
 @typedef FetchBehaviorProgressCompletionHandler
 @abstract Completion handler block type for @link fetchBehaviorProgressWithCompletionHandler: @/link.
 */
typedef void (^FetchBehaviorProgressCompletionHandler)(SMBehaviorProgressFetchedResponse * _Nullable response, SMError * _Nullable error);
/*!
 @typedef PostEventCompletionHandler
 @abstract Completion handler block type for @link postEvent:completionHandler: @/link and @link postEventFromBuilder:completionHandler: @/link.
 */
typedef void (^PostEventCompletionHandler)(SMEventPostedResponse * _Nullable response, SMError * _Nullable error);

/*!
 @class SMEventsManager
 @abstract This API manager contains methods for interacting with action items that the user can perform to participate in application-specific campaigns and incentives.
 */
@interface SMEventsManager : NSObject

/*!
 @abstract Singleton that interfaces with the SessionM Platform Events API.
 @result <code>SMEventsManager</code> service object.
 */
+ (SMEventsManager *)instance;

/*!
 @abstract Makes a request to fetch the latest action item updates.
 @param completionHandler The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)fetchBehaviorProgressWithCompletionHandler:(FetchBehaviorProgressCompletionHandler)completionHandler NS_SWIFT_NAME(fetchBehaviorProgress(completionHandler:));
/*!
 @abstract Makes a request to post the specified event to the SessionM Platform.
 @param event Event data to be posted.
 @param completionHandler The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)postEvent:(SMEvent *)event completionHandler:(PostEventCompletionHandler)completionHandler NS_SWIFT_NAME(postEvent(_:completionHandler:));
/*!
 @abstract Makes a request to post the specified event builder's generated event to the SessionM Platform.
 @param builder The event builder whose generated event will be posted.
 @param completionHandler The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)postEventFromBuilder:(SMEventBuilder *)builder completionHandler:(PostEventCompletionHandler)completionHandler NS_SWIFT_NAME(postEvent(from:completionHandler:));

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_EVENTS_MANAGER__ */
