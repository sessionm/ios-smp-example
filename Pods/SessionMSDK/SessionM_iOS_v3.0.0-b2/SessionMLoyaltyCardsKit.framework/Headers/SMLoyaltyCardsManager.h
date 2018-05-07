//
//  SMLoyaltyCardsManager.h
//  SessionMLoyaltyCardsKit
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SM_LOYALTY_CARDS_MANAGER__
#define __SM_LOYALTY_CARDS_MANAGER__

#import <SessionMCoreKit/SMBaseManager.h>
#import <SessionMCoreKit/SMError.h>

#import "SMLoyaltyCard.h"
#import "SMLoyaltyCardTransaction.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @const SM_LCL_MANAGER_REQUEST_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that an API request failed.
 @discussion An <code>SMError</code> object containing information about why the request failed can be accessed from the notification's <code>userInfo</code> property with the <code>SM_MANAGER_NOTIFICATION_ERROR_KEY</code> key.
 */
extern NSString *const SM_LCL_MANAGER_REQUEST_DID_FAIL_NOTIFICATION NS_SWIFT_NAME(loyaltyCardsRequestFailureNotification);
/*!
 @const SM_LCL_MANAGER_VALIDATION_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that a Loyalty Cards API validation failed.
 @discussion An <code>SMError</code> object containing information about why the validation failed can be accessed from the notification's <code>userInfo</code> property with the <code>SM_MANAGER_NOTIFICATION_ERROR_KEY</code> key.
 */
extern NSString *const SM_LCL_MANAGER_VALIDATION_DID_FAIL_NOTIFICATION NS_SWIFT_NAME(loyaltyCardsValidationFailureNotification);

/*!
 @const SM_LCL_MANAGER_REQUEST_DID_FETCH_LOYALTY_CARDS_NOTIFICATION
 @abstract Notifies observers that linked loyalty cards were fetched.
 @discussion An <code>NSArray</code> of <code>SMLoyaltyCard</code> objects can be accessed from the notification's <code>userInfo</code> property with the <code>SM_MANAGER_NOTIFICATION_DATA_KEY</code> key.
 */
extern NSString *const SM_LCL_MANAGER_REQUEST_DID_FETCH_LOYALTY_CARDS_NOTIFICATION NS_SWIFT_NAME(fetchedLinkedCardsNotification);
/*!
 @const SM_LCL_MANAGER_REQUEST_DID_FETCH_LOYALTY_CARDS_TRANSACTIONS_NOTIFICATION
 @abstract Notifies observers that loyalty card transactions were fetched.
 @discussion An <code>NSArray</code> of <code>SMLoyaltyCardTransaction</code> objects can be accessed from the notification's <code>userInfo</code> property with the <code>SM_MANAGER_NOTIFICATION_DATA_KEY</code> key.
 */
extern NSString *const SM_LCL_MANAGER_REQUEST_DID_FETCH_LOYALTY_CARDS_TRANSACTIONS_NOTIFICATION NS_SWIFT_NAME(fetchedCardTransactionsNotification);
/*!
 @const SM_LCL_MANAGER_REQUEST_DID_FETCH_RETAILERS_NOTIFICATION
 @abstract Notifies observers that available retailers were fetched.
 @discussion An <code>NSArray</code> of <code>SMRetailer</code> objects can be accessed from the notification's <code>userInfo</code> property with the <code>SM_MANAGER_NOTIFICATION_DATA_KEY</code> key.
 */
extern NSString *const SM_LCL_MANAGER_REQUEST_DID_FETCH_RETAILERS_NOTIFICATION NS_SWIFT_NAME(fetchedRetailersNotification);
/*!
 @const SM_LCL_MANAGER_REQUEST_DID_LINK_LOYALTY_NOTIFICATION
 @abstract Notifies observers that a loyalty card was linked to a user's account.
 @discussion An <code>NSString</code> object containing the card number of the linked loyalty card can be accessed from the notification's <code>userInfo</code> property with the <code>SM_MANAGER_NOTIFICATION_DATA_KEY</code> key.
 */
extern NSString *const SM_LCL_MANAGER_REQUEST_DID_LINK_LOYALTY_NOTIFICATION NS_SWIFT_NAME(linkedCardNotification);
/*!
 @const SM_LCL_MANAGER_REQUEST_DID_UNLINK_LOYALTY_NOTIFICATION
 @abstract Notifies observers that a loyalty card was unlinked from a user's account.
 */
extern NSString *const SM_LCL_MANAGER_REQUEST_DID_UNLINK_LOYALTY_NOTIFICATION NS_SWIFT_NAME(unlinkedCardNotification);


/*!
 @typedef didFetchLoyaltyCards
 @abstract Completion handler block type for <code>fetchLinkedCardsWithCompletionHandler:</code>.
 */
typedef void (^didFetchLoyaltyCards)(NSArray<SMLoyaltyCard *> * _Nullable cards, SMError * _Nullable error) NS_SWIFT_NAME(FetchLinkedCardsCompletionHandler);
/*!
 @typedef didFetchLoyaltyCardTransactions
 @abstract Completion handler block type for <code>fetchLoyaltyCardTransactionsWithCompletionHandler:</code>.
 */
typedef void (^didFetchLoyaltyCardTransactions)(NSArray<SMLoyaltyCardTransaction *> * _Nullable transactions, SMError * _Nullable error) NS_SWIFT_NAME(FetchCardTransactionsCompletionHandler);
/*!
 @typedef didLinkLoyaltyCard
 @abstract Completion handler block type for <code>linkLoyaltyCardNumber:retailer:completionHandler:</code>.
 */
typedef void (^didLinkLoyaltyCard)(NSString * _Nullable cardNumber, SMError * _Nullable error) NS_SWIFT_NAME(LinkCardCompletionHandler);
/*!
 @typedef didUnlinkLoyaltyCard
 @abstract Completion handler block type for <code>unlinkLoyaltyCardID:completionHandler:</code>.
 */
typedef void (^didUnlinkLoyaltyCard)(SMError * _Nullable error) NS_SWIFT_NAME(UnlinkCardCompletionHandler);

/*!
 @typedef didFetchRetailers
 @abstract Completion handler block type for <code>fetchRetailersWithCompletionHandler:</code> and <code>fetchRetailersWithZipCode:completionHandler:</code>.
 */
typedef void (^didFetchRetailers)(NSArray<SMRetailer *> * _Nullable retailers, SMError * _Nullable error) NS_SWIFT_NAME(FetchRetailersCompletionHandler);


/*!
 @class SMLoyaltyCardsManager
 @abstract This API manager contains methods for linking and unlinking loyalty cards with a user's account, as well as fetching linked loyalty cards and supported retailers with loyalty programs.
 */
@interface SMLoyaltyCardsManager : SMBaseManager

/*!
 @property loyaltyCards
 @abstract The current user's linked loyalty cards.
 @discussion This property is updated in response to a successful <code>fetchLinkedCardsWithCompletionHandler:</code> call.
 */
@property(nonatomic, strong, readonly) NSArray<SMLoyaltyCard *> *loyaltyCards;
/*!
 @property retailers
 @abstract The retailers for which a user can link a loyalty card.
 @discussion This property is updated in response to a successful <code>fetchRetailersWithCompletionHandler:</code>, <code>fetchRetailersWithZipCode:completionHandler:</code> or  <code>forceFetchRetailersWithZipCode:completionHandler:</code> call.
 */
@property(nonatomic, strong, readonly) NSArray<SMRetailer *> *retailers;
/*!
 @property loyaltyCardTransactions
 @abstract Purchase data parsed from transactions made with the current user's linked loyalty cards.
 @discussion This property is updated in response to a successful <code>fetchLoyaltyCardTransactionsWithCompletionHandler:</code> call.
 */
@property(nonatomic, strong, readonly) NSArray<SMLoyaltyCardTransaction *> *loyaltyCardTransactions;

/*!
 @abstract Makes a request to fetch the current user's linked loyalty cards.
 @param completionHandler The block to execute after the request is processed.
 */
- (void)fetchLinkedCardsWithCompletionHandler:(didFetchLoyaltyCards)completionHandler NS_SWIFT_NAME(fetchLinkedCards(completionHandler:));
/*!
 @abstract Makes a request to update <code>loyaltyCardTransactions</code> with purchase data parsed from transactions made with the current user's linked loyalty cards.
 @param completionHandler The block to execute after the request is processed.
 */
- (void)fetchLoyaltyCardTransactionsWithCompletionHandler:(didFetchLoyaltyCardTransactions)completionHandler NS_SWIFT_NAME(fetchCardTransactions(completionHandler:));
/*!
 @abstract Makes a request to link a loyalty card issued by the specified retailer with the specified card number.
 @param cardNumber Loyalty card number.
 @param retailerID ID of retailer that issued the loyalty card.
 @param completionHandler The block to execute after the request is processed.
 */
- (void)linkLoyaltyCardNumber:(NSString *)cardNumber retailer:(NSString *)retailerID completionHandler:(didLinkLoyaltyCard)completionHandler NS_SWIFT_NAME(linkCard(havingNumber:retailerID:completionHandler:));
/*!
 @abstract Makes a request to unlink the loyalty card with the specified loyalty card ID.
 @param cardID The ID of the loyalty card to unlink.
 @param completionHandler The block to execute after the request is processed.
 */
- (void)unlinkLoyaltyCardID:(NSString *)cardID completionHandler:(didUnlinkLoyaltyCard)completionHandler NS_SWIFT_NAME(unlinkCard(havingID:completionHandler:));

/*!
 @abstract Makes a request to update <code>retailers</code> with retailers for which a user can link a loyalty card.
 @discussion Note: A cached value for <code>retailers</code> will be provided if a fetch request was recently made. Use <code>forceFetchRetailersWithZipCode:completionHandler:</code> to force a fetch request to be sent.
 @param completionHandler The block to execute after the request is processed.
 */
- (void)fetchRetailersWithCompletionHandler:(didFetchRetailers)completionHandler NS_SWIFT_NAME(fetchRetailers(completionHandler:));
/*!
 @abstract Makes a request to update <code>retailers</code> with retailers in the specified zipcode for which a user can link a loyalty card.
 @discussion Note: A cached value for <code>retailers</code> will be provided if a fetch request was recently made. Use <code>forceFetchRetailersWithZipCode:completionHandler:</code> to force a fetch request to be sent.
 @param zipCode Zipcode in which to search for retailers.
 @param completionHandler The block to execute after the request is processed.
 */
- (void)fetchRetailersWithZipCode:(NSString *)zipCode completionHandler:(didFetchRetailers)completionHandler NS_SWIFT_NAME(fetchRetailers(inZipCode:completionHandler:));
/*!
 @abstract Makes a request to update <code>retailers</code> with retailers in the specified zipcode for which a user can link a loyalty card.
 @param zipCode Zipcode in which to search for retailers.
 @param completionHandler The block to execute after the request is processed.
 */
- (void)forceFetchRetailersWithZipCode:(NSString *)zipCode completionHandler:(didFetchRetailers)completionHandler NS_SWIFT_NAME(forceFetchRetailers(inZipCode:completionHandler:));

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_LOYALTY_CARDS_MANAGER__ */
