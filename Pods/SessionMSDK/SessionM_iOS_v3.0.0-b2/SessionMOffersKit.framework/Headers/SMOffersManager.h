//
//  SMOffersManager.h
//  SessionMOffersKit
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SM_OFFERS_MANAGER__
#define __SM_OFFERS_MANAGER__

#import <SessionMCoreKit/SMBaseManager.h>
#import <SessionMCoreKit/SMError.h>

#import "SMOfferPurchasedResponse.h"
#import "SMStoreOffersFetchedResponse.h"
#import "SMUserOfferClaimedResponse.h"
#import "SMUserOffersFetchedResponse.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @const SM_OFFERS_MANAGER_VALIDATION_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that an Offers API validation failed.
 @discussion An <code>SMError</code> object containing information about why the validation failed can be accessed from the notification's <code>userInfo</code> property with the <code>SM_MANAGER_NOTIFICATION_ERROR_KEY</code> key.
 */
extern NSString *const SM_OFFERS_MANAGER_VALIDATION_DID_FAIL_NOTIFICATION NS_SWIFT_NAME(offersValidationFailureNotification);
/*!
 @const SM_OFFERS_MANAGER_REQUEST_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that an Offers API request failed.
 @discussion An <code>SMError</code> object containing information about why the request failed can be accessed from the notification's <code>userInfo</code> property with the <code>SM_MANAGER_NOTIFICATION_ERROR_KEY</code> key.
 */
extern NSString *const SM_OFFERS_MANAGER_REQUEST_DID_FAIL_NOTIFICATION NS_SWIFT_NAME(offersRequestFailureNotification);
/*!
 @const SM_OFFERS_MANAGER_DID_FETCH_STORE_OFFERS_NOTIFICATION
 @abstract Notifies observers that loyalty offers available for purchase were fetched.
 @discussion An <code>SMStoreOffersFetchedResponse</code> object can be accessed from the notification's <code>userInfo</code> property with the <code>SM_MANAGER_NOTIFICATION_DATA_KEY</code> key.
 */
extern NSString *const SM_OFFERS_MANAGER_DID_FETCH_STORE_OFFERS_NOTIFICATION NS_SWIFT_NAME(fetchedStoreOffersNotification);
/*!
 @const SM_OFFERS_MANAGER_DID_PURCHASE_OFFER_NOTIFICATION
 @abstract Notifies observers that a loyalty offer was purchased.
 @discussion An <code>SMOfferPurchasedResponse</code> object can be accessed from the notification's <code>userInfo</code> property with the <code>SM_MANAGER_NOTIFICATION_DATA_KEY</code> key.
 */
extern NSString *const SM_OFFERS_MANAGER_DID_PURCHASE_OFFER_NOTIFICATION NS_SWIFT_NAME(purchasedOfferNotification);
/*!
 @const SM_OFFERS_MANAGER_DID_FETCH_USER_OFFERS_NOTIFICATION
 @abstract Notifies observers that loyalty offers that have been purchsed by the user were fetched.
 @discussion An <code>SMUserOffersFetchedResponse</code> object can be accessed from the notification's <code>userInfo</code> property with the <code>SM_MANAGER_NOTIFICATION_DATA_KEY</code> key.
 */
extern NSString *const SM_OFFERS_MANAGER_DID_FETCH_USER_OFFERS_NOTIFICATION NS_SWIFT_NAME(fetchedUserOffersNotification);
/*!
 @const SM_OFFERS_MANAGER_DID_CLAIM_USER_OFFER_NOTIFICATION
 @abstract Notifies observers that a loyalty offer that was purchsed by the user has been claimed.
 @discussion An <code>SMUserOfferClaimedResponse</code> object can be accessed from the notification's <code>userInfo</code> property with the <code>SM_MANAGER_NOTIFICATION_DATA_KEY</code> key.
 */
extern NSString *const SM_OFFERS_MANAGER_DID_CLAIM_USER_OFFER_NOTIFICATION NS_SWIFT_NAME(claimedUserOfferNotification);


/*!
 @typedef FetchStoreOffersCompletionHandler
 @abstract Completion handler block type for <code>fetchStoreOffersWithRequest:completionHandler:</code> method calls.
 */
typedef void (^FetchStoreOffersCompletionHandler)(SMStoreOffersFetchedResponse * _Nullable response, SMError * _Nullable error);
/*!
 @typedef PurchaseOfferCompletionHandler
 @abstract Completion handler block type for <code>purchaseOfferWithRequest:completionHandler:</code> method calls.
 */
typedef void (^PurchaseOfferCompletionHandler)(SMOfferPurchasedResponse * _Nullable response, SMError * _Nullable error);
/*!
 @typedef FetchUserOffersCompletionHandler
 @abstract Completion handler block type for <code>fetchUserOffersWithRequest:completionHandler:</code> method calls.
 */
typedef void (^FetchUserOffersCompletionHandler)(SMUserOffersFetchedResponse * _Nullable response, SMError * _Nullable error);
/*!
 @typedef ClaimUserOfferCompletionHandler
 @abstract Completion handler block type for <code>claimUserOfferWithRequest:completionHandler:</code> method calls.
 */
typedef void (^ClaimUserOfferCompletionHandler)(SMUserOfferClaimedResponse * _Nullable response, SMError * _Nullable error);


/*!
 @class SMOffersManager
 @abstract This API manager contains methods for purchasing and redeeming loyalty offers.
 */
@interface SMOffersManager : SMBaseManager

/*!
 @property fetchStoreOffersResponse
 @abstract The response data from the most recent request to fetch loyalty offers available for purchase.
 @discussion This property is updated in response to a successful <code>fetchStoreOffersWithCompletionHandler:</code> or <code>forceFetchStoreOffersWithCompletionHandler:</code> call.
 */
@property(nullable, nonatomic, strong, readonly) SMStoreOffersFetchedResponse *fetchStoreOffersResponse;

/*!
 @abstract Makes a request to fetch loyalty offers available for purchase.
 @discussion Note: A cached value for <code>fetchStoreOffersResponse</code> will be provided if a fetch request was recently made. Use <code>forceFetchStoreOffersWithCompletionHandler:</code> to force a fetch request to be sent.
 @param completionHandler The block to execute after the request is processed.
 */
- (void)fetchStoreOffersWithCompletionHandler:(FetchStoreOffersCompletionHandler)completionHandler NS_SWIFT_NAME(fetchStoreOffers(completionHandler:));
/*!
 @abstract Makes a request to fetch loyalty offers available for purchase.
 @param completionHandler The block to execute after the request is processed.
 */
- (void)forceFetchStoreOffersWithCompletionHandler:(FetchStoreOffersCompletionHandler)completionHandler NS_SWIFT_NAME(forceFetchStoreOffers(completionHandler:));
/*!
 @abstract Makes a request to purchase the loyalty offer with the specified offer identifier.
 @param offerID The identifier for the offer that will be purchased.
 @param quantity The amount of individual instances of the offer that will be purchased.
 @param completionHandler The block to execute after the request is processed.
 */
- (void)purchaseOfferWithID:(NSString *)offerID quantity:(NSInteger)quantity completionHandler:(PurchaseOfferCompletionHandler)completionHandler NS_SWIFT_NAME(purchaseOffer(havingID:quantity:completionHandler:));
/*!
 @abstract Makes a request to fetch loyalty offers that have been purchased by the current user.
 @param completionHandler The block to execute after the request is processed.
 */
- (void)fetchUserOffersWithCompletionHandler:(FetchUserOffersCompletionHandler)completionHandler NS_SWIFT_NAME(fetchUserOffers(completionHandler:));
/*!
 @abstract Makes a request to claim the loyalty offer with the specified user offer identifier.
 @param userOfferID The user-specific identifier for the offer that will be claimed.
 @param completionHandler The block to execute after the request is processed.
 */
- (void)claimUserOfferWithID:(NSString *)userOfferID completionHandler:(ClaimUserOfferCompletionHandler)completionHandler NS_SWIFT_NAME(claimUserOffer(havingID:completionHandler:));

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_OFFERS_MANAGER__ */
