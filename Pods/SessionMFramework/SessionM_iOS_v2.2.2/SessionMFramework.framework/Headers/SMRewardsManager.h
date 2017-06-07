//
//  SMRewardsManager.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef __SM_REWARDS_MANAGER__
#define __SM_REWARDS_MANAGER__

#import <Foundation/Foundation.h>
#import "SMAddress.h"
#import "SMBaseDelegate.h"
#import "SMOffer.h"
#import "SMOrder.h"
#import "SMSkillChallenge.h"
#import "SMSkillQuestion.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @const SM_REWARDS_MANAGER_REQUEST_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that an API request failed.
 @discussion An @link SMError @/link object containing information about why the request failed can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_ERROR_KEY @/link key.
 */
extern NSString *const SM_REWARDS_MANAGER_REQUEST_DID_FAIL_NOTIFICATION NS_SWIFT_NAME(rewardsRequestFailureNotification);
/*!
 @const SM_REWARDS_MANAGER_VALIDATION_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that a Rewards API validation failed.
 @discussion An @link SMError @/link object containing information about why the validation failed can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_ERROR_KEY @/link key.
 */
extern NSString *const SM_REWARDS_MANAGER_VALIDATION_DID_FAIL_NOTIFICATION NS_SWIFT_NAME(rewardsValidationFailureNotification);

/*!
 @const SM_REWARDS_MANAGER_DID_FETCH_OFFERS_NOTIFICATION
 @abstract Notifies observers that available offers were fetched.
 @discussion An <code>NSArray</code> of @link SMOffer @/link objects can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_DATA_KEY @/link key.
 */
extern NSString *const SM_REWARDS_MANAGER_DID_FETCH_OFFERS_NOTIFICATION NS_SWIFT_NAME(fetchedOffersNotification);
/*!
 @const SM_REWARDS_MANAGER_DID_FETCH_ORDERS_NOTIFICATION
 @abstract Notifies observers that offer orders were fetched.
 @discussion An <code>NSArray</code> of @link SMOrder @/link objects can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_DATA_KEY @/link key.
 */
extern NSString *const SM_REWARDS_MANAGER_DID_FETCH_ORDERS_NOTIFICATION NS_SWIFT_NAME(fetchedOrdersNotification);
/*!
 @const SM_REWARDS_MANAGER_DID_PLACE_ORDER_NOTIFICATION
 @abstract Notifies observers that an offer order was placed.
 @discussion An @link SMOrder @/link object containing information about the placed order can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_DATA_KEY @/link key.
 */
extern NSString *const SM_REWARDS_MANAGER_DID_PLACE_ORDER_NOTIFICATION NS_SWIFT_NAME(placedOrderNotification);
/*!
 @const SM_REWARDS_MANAGER_DID_FETCH_SKILL_QUESTION_NOTIFICATION
 @abstract Notifies observers that a skill testing question was fetched.
 @discussion An @link SMSkillQuestion @/link object containing information about the fetched skill testing question can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_DATA_KEY @/link key.
 */
extern NSString *const SM_REWARDS_MANAGER_DID_FETCH_SKILL_QUESTION_NOTIFICATION NS_SWIFT_NAME(fetchedSkillQuestionNotification);
/*!
 @const SM_REWARDS_MANAGER_DID_ANSWER_SKILL_QUESTION_NOTIFICATION
 @abstract Notifies observers that a skill testing question was answered.
 @discussion An @link SMSkillChallenge @/link object containing information about the server-side response to the answered skill testing question can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_DATA_KEY @/link key.
 */
extern NSString *const SM_REWARDS_MANAGER_DID_ANSWER_SKILL_QUESTION_NOTIFICATION NS_SWIFT_NAME(answeredSkillQuestionNotification);

/*!
 @protocol SMRewardsDelegate
 @abstract Defines callbacks for @link SMRewardsManager @/link methods.
 */
@protocol SMRewardsDelegate <SMBaseDelegate>

@optional

/*!
 @abstract Notifies delegate that available offers were fetched.
 @discussion This method is called in response to @link fetchOffers @/link and @link fetchOffersWithLocale: @/link.
 @param offers Offers available for redemption.
 @deprecated Use block methods instead.
 */
- (void)didFetchOffers:(NSArray<SMOffer *> *)offers __attribute__((deprecated("Use block methods instead"))) NS_SWIFT_NAME(didFetchOffers(_:));

/*!
 @abstract Notifies delegate that the current user's sent orders were fetched.
 @discussion This method is called in response to @link fetchOrders @/link.
 @param orders Orders that have been made by the current user.
 @deprecated Use block methods instead.
 */
- (void)didFetchOrders:(NSArray<SMOrder *> *)orders __attribute__((deprecated("Use block methods instead"))) NS_SWIFT_NAME(didFetchOrders(_:));
/*!
 @abstract Notifies delegate that an order was placed for the current user.
 @discussion This method is called in response to @link placeOrder: @/link.
 @param order The order that was placed.
 @deprecated Use block methods instead.
 */
- (void)didPlaceOrder:(SMOrder *)order __attribute__((deprecated("Use block methods instead"))) NS_SWIFT_NAME(didPlaceOrder(_:));

/*!
 @abstract Notifies delegate that a skill testing question was fetched.
 @discussion This method is called in response to @link fetchSkillQuestion @/link.
 @param question The question to be answered by the user.
 @deprecated Use block methods instead.
 */
- (void)didFetchSkillQuestion:(SMSkillQuestion *)question __attribute__((deprecated("Use block methods instead"))) NS_SWIFT_NAME(didFetchSkillQuestion(_:));
/*!
 @abstract Notifies delegate that the user's answer to a skill testing question was processed.
 @discussion This method is called in response to @link answerSkillQuestionForOfferID:questionID:answer: @/link.
 @param result The server-side response to the user's answer.
 @deprecated Use block methods instead.
 */
- (void)didAnswerSkillQuestion:(SMSkillChallenge *)result __attribute__((deprecated("Use block methods instead"))) NS_SWIFT_NAME(didAnswerSkillQuestion(result:));

@end

/*!
 @typedef didFetchOffers
 @abstract Completion handler block type for @link fetchOffersWithCompletionHandler: @/link and @link fetchOffersWithLocale:completionHandler: @/link.
 */
typedef void (^didFetchOffers)(NSArray<SMOffer *>* _Nullable offers, SMError * _Nullable error) NS_SWIFT_NAME(FetchOffersCompletionHandler);
/*!
 @typedef didFetchOrders
 @abstract Completion handler block type for @link fetchOrdersWithCompletionHandler: @/link.
 */
typedef void (^didFetchOrders)(NSArray<SMOrder *>* _Nullable orders, SMError * _Nullable error) NS_SWIFT_NAME(FetchOrdersCompletionHandler);
/*!
 @typedef didPlaceOrder
 @abstract Completion handler block type for @link placeOrder:completionHandler: @/link.
 */
typedef void (^didPlaceOrder)(SMOrder * _Nullable order, SMError * _Nullable error) NS_SWIFT_NAME(PlaceOrderCompletionHandler);
/*!
 @typedef didFetchSkillQuestion
 @abstract Completion handler block type for @link fetchSkillQuestionWithCompletionHandler: @/link.
 */
typedef void (^didFetchSkillQuestion)(SMSkillQuestion * _Nullable skillQuestion, SMError * _Nullable error) NS_SWIFT_NAME(FetchSkillQuestionCompletionHandler);
/*!
 @typedef didAnswerSkillQuestion
 @abstract Completion handler block type for @link answerSkillQuestionForOfferID:questionID:answer:completionHandler: @/link.
 */
typedef void (^didAnswerSkillQuestion)(SMSkillChallenge * _Nullable challenge, SMError * _Nullable error) NS_SWIFT_NAME(AnswerSkillQuestionCompletionHandler);


/*!
 @class SMOrderRequest
 @abstract Defines the data associated with an offer order request.
 */
@interface SMOrderRequest : NSObject

/*!
 @property offerID
 @abstract ID of offer being redeemed.
 */
@property(nonatomic, strong, readwrite) NSString *offerID;
/*!
 @property quantity
 @abstract Amount of items to redeem.
 */
@property(nonatomic, strong, readwrite) NSNumber *quantity;
/*!
 @property email
 @abstract User's email.
 */
@property(nullable, nonatomic, strong, readwrite) NSString *email;
/*!
 @property ip
 @abstract User's IP address.
 */
@property(nullable, nonatomic, strong, readwrite) NSString *ip;
/*!
 @property shippingAddress
 @abstract Where physical items will be shipped after the order is processed.
 */
@property(nullable, nonatomic, strong, readwrite) SMAddress *shippingAddress;
/*!
 @property challengeID
 @abstract ID of server-side response for the answer to the skill testing question that gates the order.
 */
@property(nullable, nonatomic, strong, readwrite) NSString *challengeID;

/*!
 @abstract Creates a new instance of <code>SMOrderRequest</code> with the specified parameters.
 @param offerID ID of offer being redeemed.
 @param quantity Amount of items to redeem.
 @result <code>SMOrderRequest</code> instance.
 */
- (instancetype)initWithOfferID:(NSString *)offerID quantity:(NSNumber *)quantity NS_SWIFT_NAME(init(offerID:quantity:));
/*!
 @abstract Returns offer order request data in a dictionary format.
 @result <code>NSDictionary</code> respresentation of offer order request data.
 */
- (NSDictionary *)asDictionary;

@end


/*!
 @class SMRewardsManager
 @abstract This API manager contains methods for fetching and redeeming rewards offers.
 */
@interface SMRewardsManager : NSObject

+(SMRewardsManager *)instance;

/*!
 @property delegate
 @abstract Object that implements @link SMRewardsDelegate @/link callbacks.
 */
@property(nonatomic, weak) id<SMRewardsDelegate> _Nullable delegate;
/*!
 @property offers
 @abstract Offers that are available for redemption.
 @discussion This property is updated in response to a successful @link fetchOffersWithCompletionHandler: @/link or @link fetchOffersWithLocale:completionHandler: @/link call.
 */
@property(nonatomic, strong, readonly) NSArray<SMOffer *> *offers;
/*!
 @property orders
 @abstract Orders that have been made by the current user.
 @discussion This property is updated in response to a successful @link fetchOrdersWithCompletionHandler: @/link call.
 */
@property(nonatomic, strong, readonly) NSArray<SMOrder *> *orders;

/*!
 @abstract Makes a request to update @link offers @/link with rewards available in the current user's locale (default value is @link //apple_ref/occ/instp/SessionM/customLocale @/link if set and <code>[NSLocale currentLocale]</code> otherwise).
 @discussion @link didFetchOffers: @/link is called in response to this method.
 @result <code>BOOL</code> indicating whether the request will be sent.
 @deprecated Use @link fetchOffersWithCompletionHandler: @/link.
 */
- (BOOL)fetchOffers __attribute__((deprecated("Use fetchOffersWithCompletionHandler:")));
/*!
 @abstract Makes a request to update @link offers @/link with rewards available in the current user's locale (default value is @link //apple_ref/occ/instp/SessionM/customLocale @/link if set and <code>[NSLocale currentLocale]</code> otherwise).
 @param completionHandler The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)fetchOffersWithCompletionHandler:(didFetchOffers)completionHandler NS_SWIFT_NAME(fetchOffers(completionHandler:));
/*!
 @abstract Makes a request to update @link offers @/link with rewards available in the specified locale.
 @discussion @link didFetchOffers: @/link is called in response to this method.
 @param locale The locale in which the fetch will be restricted.
 @result <code>BOOL</code> indicating whether the request will be sent.
 @deprecated Use @link fetchOffersWithLocale:completionHandler: @/link.
 */
- (BOOL)fetchOffersWithLocale:(NSLocale *)locale __attribute__((deprecated("Use fetchOffersWithLocale:completionHandler:"))) NS_SWIFT_NAME(fetchOffers(for:));
/*!
 @abstract Makes a request to update @link offers @/link with rewards available in the specified locale.
 @param locale The locale in which the fetch will be restricted.
 @param completionHandler The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)fetchOffersWithLocale:(NSLocale *)locale completionHandler:(didFetchOffers)completionHandler NS_SWIFT_NAME(fetchOffers(for:completionHandler:));

/*!
 @abstract Makes a request to place the specified order.
 @discussion @link didPlaceOrder: @/link is called in response to this method.
 @param order The offer order request to be sent.
 @result <code>BOOL</code> indicating whether the request will be sent.
 @deprecated Use @link placeOrder:completionHandler: @/link.
 */
- (BOOL)placeOrder:(SMOrderRequest *)order __attribute__((deprecated("Use placeOrder:completionHandler:"))) NS_SWIFT_NAME(placeOrder(_:));
/*!
 @abstract Makes a request to place the specified order.
 @param order The offer order request to be sent.
 @param completionHandler The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)placeOrder:(SMOrderRequest *)order completionHandler:(didPlaceOrder)completionHandler NS_SWIFT_NAME(placeOrder(_:completionHandler:));
/*!
 @abstract Makes a request to update @link orders @/link with orders made by the current user.
 @discussion @link didFetchOrders: @/link is called in response to this method.
 @result <code>BOOL</code> indicating whether the request will be sent.
 @deprecated Use @link fetchOrdersWithCompletionHandler: @/link.
 */
- (BOOL)fetchOrders __attribute__((deprecated("Use fetchOrdersWithCompletionHandler:")));
/*!
 @abstract Makes a request to update @link orders @/link with orders made by the current user.
 @param completionHandler The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)fetchOrdersWithCompletionHandler:(didFetchOrders)completionHandler NS_SWIFT_NAME(fetchOrders(completionHandler:));

/*!
 @abstract Makes a request to fetch a skill testing question.
 @discussion @link didFetchSkillQuestion: @/link is called in response to this method.
 @result <code>BOOL</code> indicating whether the request will be sent.
 @deprecated Use @link fetchSkillQuestionWithCompletionHandler: @/link.
 */
- (BOOL)fetchSkillQuestion __attribute__((deprecated("Use fetchSkillQuestionWithCompletionHandler:")));
/*!
 @abstract Makes a request to fetch a skill testing question.
 @param completionHandler The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)fetchSkillQuestionWithCompletionHandler:(didFetchSkillQuestion)completionHandler NS_SWIFT_NAME(fetchSkillQuestion(completionHandler:));
/*!
 @abstract Makes a request to answer a skill testing question.
 @discussion @link didAnswerSkillQuestion: @/link is called in response to this method.
 @param offerID The ID of the offer the user is redeeming.
 @param questionID The ID of the question the user is answering.
 @param answer The user's response to the question.
 @result <code>BOOL</code> indicating whether the request will be sent.
 @deprecated Use @link answerSkillQuestionForOfferID:questionID:answer:completionHandler: @/link.
 */
- (BOOL)answerSkillQuestionForOfferID:(NSString *)offerID questionID:(NSString *)questionID answer:(NSString *)answer __attribute__((deprecated("Use answerSkillQuestionForOfferID:questionID:answer:completionHandler:"))) NS_SWIFT_NAME(answerSkillQuestion(forOfferID:questionID:answer:));
/*!
 @abstract Makes a request to answer a skill testing question.
 @param offerID The ID of the offer the user is redeeming.
 @param questionID The ID of the question the user is answering.
 @param answer The user's response to the question.
 @param completionHandler The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)answerSkillQuestionForOfferID:(NSString *)offerID questionID:(NSString *)questionID answer:(NSString *)answer completionHandler:(didAnswerSkillQuestion)completionHandler NS_SWIFT_NAME(answerSkillQuestion(forOfferID:questionID:answer:completionHandler:));

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_REWARDS_MANAGER__ */
