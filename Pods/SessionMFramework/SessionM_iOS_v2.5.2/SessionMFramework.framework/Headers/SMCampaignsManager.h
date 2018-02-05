//
//  SMCampaignsManager.h
//  SessionM
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SM_CAMPAIGNS_MANAGER__
#define __SM_CAMPAIGNS_MANAGER__

#import "SMFeedMessage.h"
#import "SMPromotion.h"

#import "SMError.h"
#import "SMBaseDelegate.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @const SM_CAMPAIGNS_MANAGER_REQUEST_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that an API request failed.
 @discussion An @link SMError @/link object containing information about why the request failed can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_ERROR_KEY @/link key.
 */
extern NSString *const SM_CAMPAIGNS_MANAGER_REQUEST_DID_FAIL_NOTIFICATION NS_SWIFT_NAME(campaignsRequestFailureNotification);
/*!
 @const SM_CAMPAIGNS_MANAGER_DID_FETCH_FEED_MESSAGES_NOTIFICATION
 @abstract Notifies observers that feed message campaigns were fetched.
 @discussion An <code>NSArray</code> of @link SMFeedMessage @/link objects can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_DATA_KEY @/link key.
 */
extern NSString *const SM_CAMPAIGNS_MANAGER_DID_FETCH_FEED_MESSAGES_NOTIFICATION NS_SWIFT_NAME(fetchedFeedMessagesNotification);
/*!
 @const SM_CAMPAIGNS_MANAGER_DID_FETCH_PROMOTIONS_NOTIFICATION
 @abstract Notifies observers that promotional campaigns were fetched.
 @discussion An <code>NSArray</code> of @link SMPromotion @/link objects can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_DATA_KEY @/link key.
 */
extern NSString *const SM_CAMPAIGNS_MANAGER_DID_FETCH_PROMOTIONS_NOTIFICATION NS_SWIFT_NAME(fetchedPromotionsNotification);

/*!
 @protocol SMCampaignsDelegate
 @abstract Defines callbacks for @link SMCampaignsManager @/link methods.
 */
@protocol SMCampaignsDelegate <SMBaseDelegate>

@optional

/*!
 @abstract Notifies delegate that feed message campaigns were fetched.
 @discussion This method is called in response to @link fetchFeedMessages @/link and @link fetchFeedMessagesWithLocale: @/link.
 @param messages The message campaigns.
 @deprecated Use block methods instead.
 */
- (void)didFetchFeedMessages:(NSArray<SMFeedMessage *> *)messages __attribute__((deprecated("Use block methods instead"))) NS_SWIFT_NAME(didFetchFeedMessages(_:));

@end

/*!
 @typedef didFetchFeedMessages
 @abstract Completion handler block type for @link fetchFeedMessagesWithCompletionHandler: @/link and @link fetchFeedMessagesWithLocale:completionHandler: @/link.
 */
typedef void (^didFetchFeedMessages)(NSArray<SMFeedMessage *>* _Nullable messages, SMError * _Nullable error) NS_SWIFT_NAME(FetchFeedMessagesCompletionHandler);
/*!
 @typedef didFetchPromotions
 @abstract Completion handler block type for @link fetchPromotionsWithCompletionHandler: @/link and @link fetchPromotionsWithCompletionHandlerWithLocale:completionHandler: @/link.
 */
typedef void (^didFetchPromotions)(NSArray<SMPromotion *>* _Nullable promotions, SMError * _Nullable error) NS_SWIFT_NAME(FetchPromotionsCompletionHandler);

/*!
 @class SMCampaignsManager
 @abstract This API manager contains methods for fetching promotional campaign data.
 */
@interface SMCampaignsManager : NSObject

/*!
 @abstract Singleton that interfaces with the SessionM Platform Campaigns API.
 @result <code>SMCampaignsManager</code> service object.
 */
+ (SMCampaignsManager *)instance;

/*!
 @property delegate
 @abstract Object that implements @link SMCampaignsDelegate @/link callbacks.
 */
@property(nonatomic, weak) id<SMCampaignsDelegate> _Nullable delegate;

/*!
 @property feedMessages
 @abstract Feed message campaigns.
 @discussion This property is updated in response to a successful @link fetchFeedMessagesWithCompletionHandler: @/link or @link fetchFeedMessagesWithLocale:completionHandler: @/link call.
 */
@property(nonatomic, strong, readonly) NSArray<SMFeedMessage *> *feedMessages;
/*!
 @property promotions
 @abstract Promotional campaigns.
 @discussion This property is updated in response to a successful @link fetchPromotionsWithCompletionHandler: @/link or @link fetchPromotionsWithLocale:completionHandler: @/link call.
 */
@property(nonatomic, strong, readonly) NSArray<SMPromotion *>   *promotions;

/*!
 @abstract Makes a request to update @link feedMessages @/link with feed message campaigns targeted to the current user's locale (default value is @link //apple_ref/occ/instp/SessionM/customLocale @/link if set and <code>[NSLocale currentLocale]</code> otherwise).
 @discussion @link didFetchFeedMessages: @/link is called in response to this method.
 @result <code>BOOL</code> indicating whether the request will be sent.
 @deprecated Use @link fetchFeedMessagesWithCompletionHandler: @/link.
 */
- (BOOL)fetchFeedMessages __attribute__((deprecated("Use fetchFeedMessagesWithCompletionHandler:")));
/*!
 @abstract Makes a request to update @link feedMessages @/link with feed message campaigns targeted to the current user's locale (default value is @link //apple_ref/occ/instp/SessionM/customLocale @/link if set and <code>[NSLocale currentLocale]</code> otherwise).
 @param completionHandler The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)fetchFeedMessagesWithCompletionHandler:(didFetchFeedMessages)completionHandler NS_SWIFT_NAME(fetchFeedMessages(completionHandler:));

/*!
 @abstract Makes a request to update @link feedMessages @/link with feed message campaigns targeted to the specified locale.
 @discussion @link didFetchFeedMessages: @/link is called in response to this method.
 @param locale The locale in which the fetch will be restricted.
 @result <code>BOOL</code> indicating whether the request will be sent.
 @deprecated Use @link fetchFeedMessagesWithLocale:completionHandler: @/link.
 */
- (BOOL)fetchFeedMessagesWithLocale:(NSLocale *)locale __attribute__((deprecated("Use fetchFeedMessagesWithLocale:completionHandler:"))) NS_SWIFT_NAME(fetchFeedMessages(for:));
/*!
 @abstract Makes a request to update @link feedMessages @/link with feed message campaigns targeted to the specified locale.
 @param locale The locale in which the fetch will be restricted.
 @param completionHandler The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)fetchFeedMessagesWithLocale:(NSLocale *)locale completionHandler:(didFetchFeedMessages)completionHandler NS_SWIFT_NAME(fetchFeedMessages(for:completionHandler:));

/*!
 @abstract Makes a request to update @link promotions @/link with promotional campaigns targeted to the current user's locale (default value is @link //apple_ref/occ/instp/SessionM/customLocale @/link if set and <code>[NSLocale currentLocale]</code> otherwise).
 @param completionHandler The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)fetchPromotionsWithCompletionHandler:(didFetchPromotions)completionHandler;
/*!
 @abstract Makes a request to update @link promotions @/link with promotional campaigns targeted to the specified locale.
 @param locale The locale in which the fetch will be restricted.
 @param completionHandler The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)fetchPromotionsWithLocale:(NSLocale *)locale completionHandler:(didFetchPromotions)completionHandler;

/*!
 @abstract Executes the action associated with the specified message.
 @param message The @link SMFeedMessage @/link instance whose action will be executed.
 @discussion Performs the specified message's action as specified by @link //apple_ref/occ/instp/SMFeedMessage/actionType @/link.
 */
- (void)executeActionForMessage:(SMFeedMessage *)message NS_SWIFT_NAME(executeAction(for:));

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_CAMPAIGNS_MANAGER__ */
