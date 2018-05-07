//
//  SMCampaignsManager.h
//  SessionMCampaignsKit
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SM_CAMPAIGNS_MANAGER__
#define __SM_CAMPAIGNS_MANAGER__

#import <SessionMCoreKit/SMBaseManager.h>
#import <SessionMCoreKit/SMError.h>

#import "SMFeedMessage.h"
#import "SMPromotion.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @const SM_CAMPAIGNS_MANAGER_REQUEST_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that an API request failed.
 @discussion An <code>SMError</code> object containing information about why the request failed can be accessed from the notification's <code>userInfo</code> property with the <code>SM_MANAGER_NOTIFICATION_ERROR_KEY</code> key.
 */
extern NSString *const SM_CAMPAIGNS_MANAGER_REQUEST_DID_FAIL_NOTIFICATION NS_SWIFT_NAME(campaignsRequestFailureNotification);
/*!
 @const SM_CAMPAIGNS_MANAGER_DID_FETCH_FEED_MESSAGES_NOTIFICATION
 @abstract Notifies observers that feed message campaigns were fetched.
 @discussion An <code>NSArray</code> of <code>SMFeedMessage</code> objects can be accessed from the notification's <code>userInfo</code> property with the <code>SM_MANAGER_NOTIFICATION_DATA_KEY</code> key.
 */
extern NSString *const SM_CAMPAIGNS_MANAGER_DID_FETCH_FEED_MESSAGES_NOTIFICATION NS_SWIFT_NAME(fetchedFeedMessagesNotification);
/*!
 @const SM_CAMPAIGNS_MANAGER_DID_FETCH_PROMOTIONS_NOTIFICATION
 @abstract Notifies observers that promotional campaigns were fetched.
 @discussion An <code>NSArray</code> of <code>SMPromotion</code> objects can be accessed from the notification's <code>userInfo</code> property with the <code>SM_MANAGER_NOTIFICATION_DATA_KEY</code> key.
 */
extern NSString *const SM_CAMPAIGNS_MANAGER_DID_FETCH_PROMOTIONS_NOTIFICATION NS_SWIFT_NAME(fetchedPromotionsNotification);


/*!
 @typedef didFetchFeedMessages
 @abstract Completion handler block type for <code>fetchFeedMessagesWithCompletionHandler:</code> and <code>fetchFeedMessagesWithLocale:completionHandler:</code>.
 */
typedef void (^didFetchFeedMessages)(NSArray<SMFeedMessage *>* _Nullable messages, SMError * _Nullable error) NS_SWIFT_NAME(FetchFeedMessagesCompletionHandler);
/*!
 @typedef didFetchPromotions
 @abstract Completion handler block type for <code>fetchPromotionsWithCompletionHandler:</code> and <code>fetchPromotionsWithCompletionHandlerWithLocale:completionHandler:</code>.
 */
typedef void (^didFetchPromotions)(NSArray<SMPromotion *>* _Nullable promotions, SMError * _Nullable error) NS_SWIFT_NAME(FetchPromotionsCompletionHandler);

/*!
 @class SMCampaignsManager
 @abstract This API manager contains methods for fetching promotional campaign data.
 */
@interface SMCampaignsManager : SMBaseManager

/*!
 @property feedMessages
 @abstract Feed message campaigns.
 @discussion This property is updated in response to a successful <code>fetchFeedMessagesWithCompletionHandler:</code>, <code>fetchFeedMessagesWithLocale:completionHandler:</code> or <code>forceFetchFeedMessagesWithLocale:completionHandler:</code> call.
 */
@property(nonatomic, strong, readonly) NSArray<SMFeedMessage *> *feedMessages;
/*!
 @property promotions
 @abstract Promotional campaigns.
 @discussion This property is updated in response to a successful <code>fetchPromotionsWithCompletionHandler:</code>, <code>fetchPromotionsWithLocale:completionHandler:</code> or <code>forceFetchPromotionsWithLocale:completionHandler:</code> call.
 */
@property(nonatomic, strong, readonly) NSArray<SMPromotion *>   *promotions;

/*!
 @abstract Makes a request to update <code>feedMessages</code> with feed message campaigns targeted to the current user's locale (default value is <code>SessionM customLocale</code> if set and <code>NSLocale currentLocale</code> otherwise).
 @discussion Note: A cached value for <code>feedMessages</code> will be provided if a fetch request was recently made. Use <code>forceFetchFeedMessagesWithLocale:completionHandler:</code> to force a fetch request to be sent.
 @param completionHandler The block to execute after the request is processed.
 */
- (void)fetchFeedMessagesWithCompletionHandler:(didFetchFeedMessages)completionHandler NS_SWIFT_NAME(fetchFeedMessages(completionHandler:));
/*!
 @abstract Makes a request to update <code>feedMessages</code> with feed message campaigns targeted to the specified locale.
 @discussion Note: A cached value for <code>feedMessages</code> will be provided if a fetch request was recently made. Use <code>forceFetchFeedMessagesWithLocale:completionHandler:</code> to force a fetch request to be sent.
 @param locale The locale in which the fetch will be restricted.
 @param completionHandler The block to execute after the request is processed.
 */
- (void)fetchFeedMessagesWithLocale:(NSLocale *)locale completionHandler:(didFetchFeedMessages)completionHandler NS_SWIFT_NAME(fetchFeedMessages(for:completionHandler:));
/*!
 @abstract Makes a request to update <code>feedMessages</code> with feed message campaigns targeted to the specified locale.
 @param locale The locale in which the fetch will be restricted.
 @param completionHandler The block to execute after the request is processed.
 */
- (void)forceFetchFeedMessagesWithLocale:(NSLocale *)locale completionHandler:(didFetchFeedMessages)completionHandler NS_SWIFT_NAME(forceFetchFeedMessages(for:completionHandler:));

/*!
 @abstract Makes a request to update <code>promotions</code> with promotional campaigns targeted to the current user's locale (default value is <code>SessionM customLocale</code> if set and <code>NSLocale currentLocale</code> otherwise).
 @discussion Note: A cached value for <code>promotions</code> will be provided if a fetch request was recently made. Use <code>forceFetchPromotionsWithLocale:completionHandler:</code> to force a fetch request to be sent.
 @param completionHandler The block to execute after the request is processed.
 */
- (void)fetchPromotionsWithCompletionHandler:(didFetchPromotions)completionHandler NS_SWIFT_NAME(fetchPromotions(completionHandler:));
/*!
 @abstract Makes a request to update <code>promotions</code> with promotional campaigns targeted to the specified locale.
 @discussion Note: A cached value for <code>promotions</code> will be provided if a fetch request was recently made. Use <code>forceFetchPromotionsWithLocale:completionHandler:</code> to force a fetch request to be sent.
 @param locale The locale in which the fetch will be restricted.
 @param completionHandler The block to execute after the request is processed.
 */
- (void)fetchPromotionsWithLocale:(NSLocale *)locale completionHandler:(didFetchPromotions)completionHandler NS_SWIFT_NAME(fetchPromotions(for:completionHandler:));
/*!
 @abstract Makes a request to update <code>promotions</code> with promotional campaigns targeted to the specified locale.
 @param locale The locale in which the fetch will be restricted.
 @param completionHandler The block to execute after the request is processed.
 */
- (void)forceFetchPromotionsWithLocale:(NSLocale *)locale completionHandler:(didFetchPromotions)completionHandler NS_SWIFT_NAME(forceFetchPromotions(for:completionHandler:));

/*!
 @abstract Executes the action associated with the specified message.
 @param message The <code>SMFeedMessage</code> instance whose action will be executed.
 @discussion Performs the specified message's action as specified by <code>SMFeedMessage actionType</code>.
 */
- (void)executeActionForMessage:(SMFeedMessage *)message NS_SWIFT_NAME(executeAction(for:));

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_CAMPAIGNS_MANAGER__ */
