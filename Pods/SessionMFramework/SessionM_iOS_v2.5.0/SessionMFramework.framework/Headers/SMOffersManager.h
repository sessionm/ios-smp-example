//
//  SMOffersManager.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef __SM_OFFERS_MANAGER__
#define __SM_OFFERS_MANAGER__

#import "SMError.h"

#import "SMOfferPurchasedResponse.h"
#import "SMStoreOffersFetchedResponse.h"
#import "SMUserOfferClaimedResponse.h"
#import "SMUserOffersFetchedResponse.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @const SM_OFFERS_MANAGER_VALIDATION_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that an Offers API validation failed.
 @discussion An @link SMError @/link object containing information about why the validation failed can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_ERROR_KEY @/link key.
 */
extern NSString *const SM_OFFERS_MANAGER_VALIDATION_DID_FAIL_NOTIFICATION NS_SWIFT_NAME(offersValidationFailureNotification);
/*!
 @const SM_OFFERS_MANAGER_REQUEST_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that an Offers API request failed.
 @discussion An @link SMError @/link object containing information about why the request failed can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_ERROR_KEY @/link key.
 */
extern NSString *const SM_OFFERS_MANAGER_REQUEST_DID_FAIL_NOTIFICATION NS_SWIFT_NAME(offersRequestFailureNotification);
/*!
 @const SM_OFFERS_MANAGER_DID_FETCH_STORE_OFFERS_NOTIFICATION
 @abstract Notifies observers that loyalty offers available for purchase were fetched.
 @discussion An @link SMStoreOffersFetchedResponse @/link object can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_DATA_KEY @/link key.
 */
extern NSString *const SM_OFFERS_MANAGER_DID_FETCH_STORE_OFFERS_NOTIFICATION NS_SWIFT_NAME(fetchedStoreOffersNotification);
/*!
 @const SM_OFFERS_MANAGER_DID_PURCHASE_OFFER_NOTIFICATION
 @abstract Notifies observers that a loyalty offer was purchased.
 @discussion An @link SMOfferPurchasedResponse @/link object can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_DATA_KEY @/link key.
 */
extern NSString *const SM_OFFERS_MANAGER_DID_PURCHASE_OFFER_NOTIFICATION NS_SWIFT_NAME(purchasedOfferNotification);
/*!
 @const SM_OFFERS_MANAGER_DID_FETCH_USER_OFFERS_NOTIFICATION
 @abstract Notifies observers that loyalty offers that have been purchsed by the user were fetched.
 @discussion An @link SMUserOffersFetchedResponse @/link object can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_DATA_KEY @/link key.
 */
extern NSString *const SM_OFFERS_MANAGER_DID_FETCH_USER_OFFERS_NOTIFICATION NS_SWIFT_NAME(fetchedUserOffersNotification);
/*!
 @const SM_OFFERS_MANAGER_DID_CLAIM_USER_OFFER_NOTIFICATION
 @abstract Notifies observers that a loyalty offer that was purchsed by the user has been claimed.
 @discussion An @link SMUserOfferClaimedResponse @/link object can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_DATA_KEY @/link key.
 */
extern NSString *const SM_OFFERS_MANAGER_DID_CLAIM_USER_OFFER_NOTIFICATION NS_SWIFT_NAME(claimedUserOfferNotification);

/*!
 @typedef FetchStoreOffersCompletionHandler
 @abstract Completion handler block type for @link fetchStoreOffersWithRequest:completionHandler: @/link method calls.
 */
typedef void (^FetchStoreOffersCompletionHandler)(SMStoreOffersFetchedResponse * _Nullable response, SMError * _Nullable error);
/*!
 @typedef PurchaseOfferCompletionHandler
 @abstract Completion handler block type for @link purchaseOfferWithRequest:completionHandler: @/link method calls.
 */
typedef void (^PurchaseOfferCompletionHandler)(SMOfferPurchasedResponse * _Nullable response, SMError * _Nullable error);
/*!
 @typedef FetchUserOffersCompletionHandler
 @abstract Completion handler block type for @link fetchUserOffersWithRequest:completionHandler: @/link method calls.
 */
typedef void (^FetchUserOffersCompletionHandler)(SMUserOffersFetchedResponse * _Nullable response, SMError * _Nullable error);
/*!
 @typedef ClaimUserOfferCompletionHandler
 @abstract Completion handler block type for @link claimUserOfferWithRequest:completionHandler: @/link method calls.
 */
typedef void (^ClaimUserOfferCompletionHandler)(SMUserOfferClaimedResponse * _Nullable response, SMError * _Nullable error);

/*!
 @class SMOffersManager
 @abstract This API manager contains methods for purchasing and redeeming loyalty offers.
 */
@interface SMOffersManager : NSObject

/*!
 @abstract Singleton that interfaces with the SessionM Platform Offers API.
 @result <code>SMOffersManager</code> service object.
 */
+ (SMOffersManager *)instance;

/*!
 @abstract Makes a request to fetch loyalty offers available for purchase.
 @param completionHandler The block to execute after the request is processed.
 @result <code>SMError</code> object returned if request validation fails.
 */
- (SMError * _Nullable)fetchStoreOffersWithCompletionHandler:(FetchStoreOffersCompletionHandler)completionHandler NS_SWIFT_NAME(fetchStoreOffers(completionHandler:));
/*!
 @abstract Makes a request to purchase the loyalty offer with the specified offer identifier.
 @param offerID The identifier for the offer that will be purchased.
 @param quantity The amount of individual instances of the offer that will be purchased.
 @param completionHandler The block to execute after the request is processed.
 @result <code>SMError</code> object returned if request validation fails.
 */
- (SMError * _Nullable)purchaseOfferWithID:(NSString *)offerID quantity:(NSInteger)quantity completionHandler:(PurchaseOfferCompletionHandler)completionHandler NS_SWIFT_NAME(purchaseOffer(havingID:quantity:completionHandler:));
/*!
 @abstract Makes a request to fetch loyalty offers that have been purchased by the current user.
 @param completionHandler The block to execute after the request is processed.
 @result <code>SMError</code> object returned if request validation fails.
 */
- (SMError * _Nullable)fetchUserOffersWithCompletionHandler:(FetchUserOffersCompletionHandler)completionHandler NS_SWIFT_NAME(fetchUserOffers(completionHandler:));
/*!
 @abstract Makes a request to claim the loyalty offer with the specified user offer identifier.
 @param userOfferID The user-specific identifier for the offer that will be claimed.
 @param completionHandler The block to execute after the request is processed.
 @result <code>SMError</code> object returned if request validation fails.
 */
- (SMError * _Nullable)claimUserOfferWithID:(NSString *)userOfferID completionHandler:(ClaimUserOfferCompletionHandler)completionHandler NS_SWIFT_NAME(claimUserOffer(havingID:completionHandler:));

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_OFFERS_MANAGER__ */
