//
//  SMRewardsManager.h
//  SessionMRewardKit
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SM_REWARDS_MANAGER__
#define __SM_REWARDS_MANAGER__

#import <Foundation/Foundation.h>
#import <SessionMCoreKit/SMAddress.h>
#import <SessionMCoreKit/SMBaseManager.h>
#import <SessionMCoreKit/SMError.h>

#import "SMOffer.h"
#import "SMOrder.h"
#import "SMSkillChallenge.h"
#import "SMSkillQuestion.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @const SM_REWARDS_MANAGER_REQUEST_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that an API request failed.
 @discussion An <code>SMError</code> object containing information about why the request failed can be accessed from the notification's <code>userInfo</code> property with the <code>SM_MANAGER_NOTIFICATION_ERROR_KEY</code> key.
 */
extern NSString *const SM_REWARDS_MANAGER_REQUEST_DID_FAIL_NOTIFICATION NS_SWIFT_NAME(rewardsRequestFailureNotification);
/*!
 @const SM_REWARDS_MANAGER_VALIDATION_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that a Rewards API validation failed.
 @discussion An <code>SMError</code> object containing information about why the validation failed can be accessed from the notification's <code>userInfo</code> property with the <code>SM_MANAGER_NOTIFICATION_ERROR_KEY</code> key.
 */
extern NSString *const SM_REWARDS_MANAGER_VALIDATION_DID_FAIL_NOTIFICATION NS_SWIFT_NAME(rewardsValidationFailureNotification);

/*!
 @const SM_REWARDS_MANAGER_DID_FETCH_OFFERS_NOTIFICATION
 @abstract Notifies observers that available offers were fetched.
 @discussion An <code>NSArray</code> of <code>SMOffer</code> objects can be accessed from the notification's <code>userInfo</code> property with the <code>SM_MANAGER_NOTIFICATION_DATA_KEY</code> key.
 */
extern NSString *const SM_REWARDS_MANAGER_DID_FETCH_OFFERS_NOTIFICATION NS_SWIFT_NAME(fetchedOffersNotification);
/*!
 @const SM_REWARDS_MANAGER_DID_FETCH_ORDERS_NOTIFICATION
 @abstract Notifies observers that offer orders were fetched.
 @discussion An <code>NSArray</code> of <code>SMOrder</code> objects can be accessed from the notification's <code>userInfo</code> property with the <code>SM_MANAGER_NOTIFICATION_DATA_KEY</code> key.
 */
extern NSString *const SM_REWARDS_MANAGER_DID_FETCH_ORDERS_NOTIFICATION NS_SWIFT_NAME(fetchedOrdersNotification);
/*!
 @const SM_REWARDS_MANAGER_DID_PLACE_ORDER_NOTIFICATION
 @abstract Notifies observers that an offer order was placed.
 @discussion An <code>SMOrder</code> object containing information about the placed order can be accessed from the notification's <code>userInfo</code> property with the <code>SM_MANAGER_NOTIFICATION_DATA_KEY</code> key.
 */
extern NSString *const SM_REWARDS_MANAGER_DID_PLACE_ORDER_NOTIFICATION NS_SWIFT_NAME(placedOrderNotification);
/*!
 @const SM_REWARDS_MANAGER_DID_FETCH_SKILL_QUESTION_NOTIFICATION
 @abstract Notifies observers that a skill testing question was fetched.
 @discussion An <code>SMSkillQuestion</code> object containing information about the fetched skill testing question can be accessed from the notification's <code>userInfo</code> property with the <code>SM_MANAGER_NOTIFICATION_DATA_KEY</code> key.
 */
extern NSString *const SM_REWARDS_MANAGER_DID_FETCH_SKILL_QUESTION_NOTIFICATION NS_SWIFT_NAME(fetchedSkillQuestionNotification);
/*!
 @const SM_REWARDS_MANAGER_DID_ANSWER_SKILL_QUESTION_NOTIFICATION
 @abstract Notifies observers that a skill testing question was answered.
 @discussion An <code>SMSkillChallenge</code> object containing information about the server-side response to the answered skill testing question can be accessed from the notification's <code>userInfo</code> property with the <code>SM_MANAGER_NOTIFICATION_DATA_KEY</code> key.
 */
extern NSString *const SM_REWARDS_MANAGER_DID_ANSWER_SKILL_QUESTION_NOTIFICATION NS_SWIFT_NAME(answeredSkillQuestionNotification);


/*!
 @typedef didFetchOffers
 @abstract Completion handler block type for <code>fetchOffersWithCompletionHandler:</code> and <code>fetchOffersWithLocale:completionHandler:</code>.
 */
typedef void (^didFetchOffers)(NSArray<SMOffer *>* _Nullable offers, SMError * _Nullable error) NS_SWIFT_NAME(FetchOffersCompletionHandler);
/*!
 @typedef didFetchOrders
 @abstract Completion handler block type for <code>fetchOrdersWithCompletionHandler:</code>.
 */
typedef void (^didFetchOrders)(NSArray<SMOrder *>* _Nullable orders, SMError * _Nullable error) NS_SWIFT_NAME(FetchOrdersCompletionHandler);
/*!
 @typedef didPlaceOrder
 @abstract Completion handler block type for <code>placeOrder:completionHandler:</code>.
 */
typedef void (^didPlaceOrder)(SMOrder * _Nullable order, SMError * _Nullable error) NS_SWIFT_NAME(PlaceOrderCompletionHandler);
/*!
 @typedef didFetchSkillQuestion
 @abstract Completion handler block type for <code>fetchSkillQuestionWithCompletionHandler:</code>.
 */
typedef void (^didFetchSkillQuestion)(SMSkillQuestion * _Nullable skillQuestion, SMError * _Nullable error) NS_SWIFT_NAME(FetchSkillQuestionCompletionHandler);
/*!
 @typedef didAnswerSkillQuestion
 @abstract Completion handler block type for <code>answerSkillQuestionForOfferID:questionID:answer:completionHandler:</code>.
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
@interface SMRewardsManager : SMBaseManager

/*!
 @property offers
 @abstract Offers that are available for redemption.
 @discussion This property is updated in response to a successful <code>fetchOffersWithCompletionHandler:</code>, <code>fetchOffersWithLocale:completionHandler:</code> or <code>forceFetchOffersWithLocale:completionHandler:</code> call.
 */
@property(nonatomic, strong, readonly) NSArray<SMOffer *> *offers;
/*!
 @property orders
 @abstract Orders that have been made by the current user.
 @discussion This property is updated in response to a successful <code>fetchOrdersWithCompletionHandler:</code> call.
 */
@property(nonatomic, strong, readonly) NSArray<SMOrder *> *orders;

/*!
 @abstract Makes a request to update <code>offers</code> with rewards available in the current user's locale (default value is <code>SessionM customLocale</code> if set and <code>NSLocale currentLocale</code> otherwise).
 @discussion Note: A cached value for <code>offers</code> will be provided if a fetch request was recently made. Use <code>forceFetchOffersWithLocale:completionHandler:</code> to force a fetch request to be sent.
 @param completionHandler The block to execute after the request is processed.
 */
- (void)fetchOffersWithCompletionHandler:(didFetchOffers)completionHandler NS_SWIFT_NAME(fetchOffers(completionHandler:));
/*!
 @abstract Makes a request to update <code>offers</code> with rewards available in the specified locale.
 @discussion Note: A cached value for <code>offers</code> will be provided if a fetch request was recently made. Use <code>forceFetchOffersWithLocale:completionHandler:</code> to force a fetch request to be sent.
 @param locale The locale in which the fetch will be restricted.
 @param completionHandler The block to execute after the request is processed.
 */
- (void)fetchOffersWithLocale:(NSLocale *)locale completionHandler:(didFetchOffers)completionHandler NS_SWIFT_NAME(fetchOffers(for:completionHandler:));
/*!
 @abstract Makes a request to update <code>offers</code> with rewards available in the specified locale.
 @param locale The locale in which the fetch will be restricted.
 @param completionHandler The block to execute after the request is processed.
 */
- (void)forceFetchOffersWithLocale:(NSLocale *)locale completionHandler:(didFetchOffers)completionHandler NS_SWIFT_NAME(forceFetchOffers(for:completionHandler:));

/*!
 @abstract Makes a request to place the specified order.
 @param order The offer order request to be sent.
 @param completionHandler The block to execute after the request is processed.
 */
- (void)placeOrder:(SMOrderRequest *)order completionHandler:(didPlaceOrder)completionHandler NS_SWIFT_NAME(placeOrder(_:completionHandler:));
/*!
 @abstract Makes a request to update <code>orders</code> with orders made by the current user.
 @param completionHandler The block to execute after the request is processed.
 */
- (void)fetchOrdersWithCompletionHandler:(didFetchOrders)completionHandler NS_SWIFT_NAME(fetchOrders(completionHandler:));

/*!
 @abstract Makes a request to fetch a skill testing question.
 @param completionHandler The block to execute after the request is processed.
 */
- (void)fetchSkillQuestionWithCompletionHandler:(didFetchSkillQuestion)completionHandler NS_SWIFT_NAME(fetchSkillQuestion(completionHandler:));
/*!
 @abstract Makes a request to answer a skill testing question.
 @param offerID The ID of the offer the user is redeeming.
 @param questionID The ID of the question the user is answering.
 @param answer The user's response to the question.
 @param completionHandler The block to execute after the request is processed.
 */
- (void)answerSkillQuestionForOfferID:(NSString *)offerID questionID:(NSString *)questionID answer:(NSString *)answer completionHandler:(didAnswerSkillQuestion)completionHandler NS_SWIFT_NAME(answerSkillQuestion(forOfferID:questionID:answer:completionHandler:));

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_REWARDS_MANAGER__ */
