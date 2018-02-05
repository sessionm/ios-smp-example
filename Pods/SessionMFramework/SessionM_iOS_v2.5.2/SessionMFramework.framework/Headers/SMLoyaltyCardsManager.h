//
//  SMLoyaltyCardsManager.h
//  SessionM
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SM_LOYALTY_CARDS_MANAGER__
#define __SM_LOYALTY_CARDS_MANAGER__

#import "SMLoyaltyCard.h"
#import "SMLoyaltyCardTransaction.h"
#import "SMBaseDelegate.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @const SM_LCL_MANAGER_REQUEST_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that an API request failed.
 @discussion An @link SMError @/link object containing information about why the request failed can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_ERROR_KEY @/link key.
 */
extern NSString *const SM_LCL_MANAGER_REQUEST_DID_FAIL_NOTIFICATION NS_SWIFT_NAME(loyaltyCardsRequestFailureNotification);
/*!
 @const SM_LCL_MANAGER_VALIDATION_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that a Loyalty Cards API validation failed.
 @discussion An @link SMError @/link object containing information about why the validation failed can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_ERROR_KEY @/link key.
 */
extern NSString *const SM_LCL_MANAGER_VALIDATION_DID_FAIL_NOTIFICATION NS_SWIFT_NAME(loyaltyCardsValidationFailureNotification);

/*!
 @const SM_LCL_MANAGER_REQUEST_DID_FETCH_LOYALTY_CARDS_NOTIFICATION
 @abstract Notifies observers that linked loyalty cards were fetched.
 @discussion An <code>NSArray</code> of @link SMLoyaltyCard @/link objects can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_DATA_KEY @/link key.
 */
extern NSString *const SM_LCL_MANAGER_REQUEST_DID_FETCH_LOYALTY_CARDS_NOTIFICATION NS_SWIFT_NAME(fetchedLinkedCardsNotification);
/*!
 @const SM_LCL_MANAGER_REQUEST_DID_FETCH_LOYALTY_CARDS_TRANSACTIONS_NOTIFICATION
 @abstract Notifies observers that loyalty card transactions were fetched.
 @discussion An <code>NSArray</code> of @link SMLoyaltyCardTransaction @/link objects can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_DATA_KEY @/link key.
 */
extern NSString *const SM_LCL_MANAGER_REQUEST_DID_FETCH_LOYALTY_CARDS_TRANSACTIONS_NOTIFICATION NS_SWIFT_NAME(fetchedCardTransactionsNotification);
/*!
 @const SM_LCL_MANAGER_REQUEST_DID_FETCH_RETAILERS_NOTIFICATION
 @abstract Notifies observers that available retailers were fetched.
 @discussion An <code>NSArray</code> of @link SMRetailer @/link objects can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_DATA_KEY @/link key.
 */
extern NSString *const SM_LCL_MANAGER_REQUEST_DID_FETCH_RETAILERS_NOTIFICATION NS_SWIFT_NAME(fetchedRetailersNotification);
/*!
 @const SM_LCL_MANAGER_REQUEST_DID_LINK_LOYALTY_NOTIFICATION
 @abstract Notifies observers that a loyalty card was linked to a user's account.
 @discussion An <code>NSString</code> object containing the card number of the linked loyalty card can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_DATA_KEY @/link key.
 */
extern NSString *const SM_LCL_MANAGER_REQUEST_DID_LINK_LOYALTY_NOTIFICATION NS_SWIFT_NAME(linkedCardNotification);
/*!
 @const SM_LCL_MANAGER_REQUEST_DID_UNLINK_LOYALTY_NOTIFICATION
 @abstract Notifies observers that a loyalty card was unlinked from a user's account.
 */
extern NSString *const SM_LCL_MANAGER_REQUEST_DID_UNLINK_LOYALTY_NOTIFICATION NS_SWIFT_NAME(unlinkedCardNotification);

/*!
 @protocol SMLoyaltyCardsDelegate
 @abstract Defines callbacks for @link SMLoyaltyCardsManager @/link methods.
 */
@protocol SMLoyaltyCardsDelegate <SMBaseDelegate>

@optional

/*!
 @abstract Notifies delegate that the current user's linked loyalty cards were fetched.
 @discussion This method is called in response to @link fetchLinkedCards @/link.
 @param cards The linked loyalty cards.
 @deprecated Use block methods instead.
 */
- (void)didFetchLoyaltyCards:(NSArray<SMLoyaltyCard *> *)cards __attribute__((deprecated("Use block methods instead"))) NS_SWIFT_NAME(didFetchLinkedCards(_:));
/*!
 @abstract Notifies delegate that the current user's loyalty card transactions were fetched.
 @discussion This method is called in response to @link fetchLoyaltyCardTransactions @/link.
 @param transactions The user's transactions.
 @deprecated Use block methods instead.
 */
- (void)didFetchLoyaltyCardTransactions:(NSArray<SMLoyaltyCardTransaction *> *)transactions __attribute__((deprecated("Use block methods instead"))) NS_SWIFT_NAME(didFetchCardTransactions(_:));
/*!
 @abstract Notifies delegate that a loyalty card was linked.
 @discussion This method is called in response to @link linkLoyaltyCardNumber:retailer: @/link.
 @param cardNumber The card number of the linked loyalty card.
 @deprecated Use block methods instead.
 */
- (void)didLinkLoyaltyCard:(NSString *)cardNumber __attribute__((deprecated("Use block methods instead"))) NS_SWIFT_NAME(didLinkCard(havingNumber:));
/*!
 @abstract Notifies delegate that a loyalty card was unlinked.
 @discussion This method is called in response to @link unlinkLoyaltyCardID: @/link.
 @deprecated Use block methods instead.
 */
- (void)didUnlinkLoyaltyCard __attribute__((deprecated("Use block methods instead"))) NS_SWIFT_NAME(didUnlinkCard());

/*!
 @abstract Notifies delegate that the available retailers were fetched.
 @discussion This method is called in response to @link fetchRetailers @/link and @link fetchRetailersWithZipCode: @/link.
 @param retailers The available retailers.
 @deprecated Use block methods instead.
 */
- (void)didFetchRetailers:(NSArray<SMRetailer *> *)retailers __attribute__((deprecated("Use block methods instead"))) NS_SWIFT_NAME(didFetchRetailers(_:));

@end

/*!
 @typedef didFetchLoyaltyCards
 @abstract Completion handler block type for @link fetchLinkedCardsWithCompletionHandler: @/link.
 */
typedef void (^didFetchLoyaltyCards)(NSArray<SMLoyaltyCard *> * _Nullable cards, SMError * _Nullable error) NS_SWIFT_NAME(FetchLinkedCardsCompletionHandler);
/*!
 @typedef didFetchLoyaltyCardTransactions
 @abstract Completion handler block type for @link fetchLoyaltyCardTransactionsWithCompletionHandler: @/link.
 */
typedef void (^didFetchLoyaltyCardTransactions)(NSArray<SMLoyaltyCardTransaction *> * _Nullable transactions, SMError * _Nullable error) NS_SWIFT_NAME(FetchCardTransactionsCompletionHandler);
/*!
 @typedef didLinkLoyaltyCard
 @abstract Completion handler block type for @link linkLoyaltyCardNumber:retailer:completionHandler: @/link.
 */
typedef void (^didLinkLoyaltyCard)(NSString * _Nullable cardNumber, SMError * _Nullable error) NS_SWIFT_NAME(LinkCardCompletionHandler);
/*!
 @typedef didUnlinkLoyaltyCard
 @abstract Completion handler block type for @link unlinkLoyaltyCardID:completionHandler: @/link.
 */
typedef void (^didUnlinkLoyaltyCard)(SMError * _Nullable error) NS_SWIFT_NAME(UnlinkCardCompletionHandler);

/*!
 @typedef didFetchRetailers
 @abstract Completion handler block type for @link fetchRetailersWithCompletionHandler: @/link and @link fetchRetailersWithZipCode:completionHandler: @/link.
 */
typedef void (^didFetchRetailers)(NSArray<SMRetailer *> * _Nullable retailers, SMError * _Nullable error) NS_SWIFT_NAME(FetchRetailersCompletionHandler);

/*!
 @class SMLoyaltyCardsManager
 @abstract This API manager contains methods for linking and unlinking loyalty cards with a user's account, as well as fetching linked loyalty cards and supported retailers with loyalty programs.
 */
@interface SMLoyaltyCardsManager : NSObject

+(SMLoyaltyCardsManager *)instance;
/*!
 @property delegate
 @abstract Object that implements @link SMLoyaltyCardsDelegate @/link callbacks.
 */
@property(nonatomic, weak) id<SMLoyaltyCardsDelegate> _Nullable delegate;
/*!
 @property loyaltyCards
 @abstract The current user's linked loyalty cards.
 @discussion This property is updated in response to a successful @link fetchLinkedCardsWithCompletionHandler: @/link call.
 */
@property(nonatomic, strong, readonly) NSArray<SMLoyaltyCard *> *loyaltyCards;
/*!
 @property retailers
 @abstract The retailers for which a user can link a loyalty card.
 @discussion This property is updated in response to a successful @link fetchRetailersWithCompletionHandler: @/link or @link fetchRetailersWithZipCode:completionHandler: @/link call.
 */
@property(nonatomic, strong, readonly) NSArray<SMRetailer *> *retailers;
/*!
 @property loyaltyCardTransactions
 @abstract Purchase data parsed from transactions made with the current user's linked loyalty cards.
 @discussion This property is updated in response to a successful @link fetchLoyaltyCardTransactionsWithCompletionHandler: @/link call.
 */
@property(nonatomic, strong, readonly) NSArray<SMLoyaltyCardTransaction *> *loyaltyCardTransactions;
/*!
 @abstract Makes a request to fetch the current user's linked loyalty cards.
 @discussion @link didFetchLoyaltyCards: @/link is called in response to this method.
 @result <code>BOOL</code> indicating whether the request will be sent.
 @deprecated Use @link fetchLinkedCardsWithCompletionHandler: @/link.
 */
- (BOOL)fetchLinkedCards __attribute__((deprecated("Use fetchLinkedCardsWithCompletionHandler:")));
/*!
 @abstract Makes a request to fetch the current user's linked loyalty cards.
 @param completionHandler The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)fetchLinkedCardsWithCompletionHandler:(didFetchLoyaltyCards)completionHandler NS_SWIFT_NAME(fetchLinkedCards(completionHandler:));
/*!
 @abstract Makes a request to update @link loyaltyCardTransactions @/link with purchase data parsed from transactions made with the current user's linked loyalty cards.
 @discussion @link didFetchLoyaltyCardTransactions: @/link is called in response to this method.
 @result <code>BOOL</code> indicating whether the request will be sent.
 @deprecated Use @link fetchLoyaltyCardTransactionsWithCompletionHandler: @/link.
 */
- (BOOL)fetchLoyaltyCardTransactions __attribute__((deprecated("Use fetchLoyaltyCardTransactionsWithCompletionHandler:")));
/*!
 @abstract Makes a request to update @link loyaltyCardTransactions @/link with purchase data parsed from transactions made with the current user's linked loyalty cards.
 @param completionHandler The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)fetchLoyaltyCardTransactionsWithCompletionHandler:(didFetchLoyaltyCardTransactions)completionHandler NS_SWIFT_NAME(fetchCardTransactions(completionHandler:));
/*!
 @abstract Makes a request to link a loyalty card issued by the specified retailer with the specified card number.
 @discussion @link didLinkLoyaltyCard: @/link is called in response to this method.
 @param cardNumber Loyalty card number.
 @param retailerID ID of retailer that issued the loyalty card.
 @result <code>BOOL</code> indicating whether the request will be sent.
 @deprecated Use @link linkLoyaltyCardNumber:retailer:completionHandler: @/link.
 */
- (BOOL)linkLoyaltyCardNumber:(NSString *)cardNumber retailer:(NSString *)retailerID __attribute__((deprecated("Use linkLoyaltyCardNumber:retailer:completionHandler:"))) NS_SWIFT_NAME(linkCard(havingNumber:retailerID:));
/*!
 @abstract Makes a request to link a loyalty card issued by the specified retailer with the specified card number.
 @param cardNumber Loyalty card number.
 @param retailerID ID of retailer that issued the loyalty card.
 @param completionHandler The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)linkLoyaltyCardNumber:(NSString *)cardNumber retailer:(NSString *)retailerID completionHandler:(didLinkLoyaltyCard)completionHandler NS_SWIFT_NAME(linkCard(havingNumber:retailerID:completionHandler:));
/*!
 @abstract Makes a request to unlink the loyalty card with the specified loyalty card ID.
 @discussion @link //apple_ref/occ/intfm/SMLoyaltyCardsDelegate/didUnlinkLoyaltyCard @/link is called in response to this method.
 @param cardID The ID of the loyalty card to unlink.
 @result <code>BOOL</code> indicating whether the request will be sent.
 @deprecated Use @link unlinkLoyaltyCardID:completionHandler: @/link.
 */
- (BOOL)unlinkLoyaltyCardID:(NSString *)cardID __attribute__((deprecated("Use unlinkLoyaltyCardID:completionHandler:"))) NS_SWIFT_NAME(unlinkCard(havingID:));
/*!
 @abstract Makes a request to unlink the loyalty card with the specified loyalty card ID.
 @param cardID The ID of the loyalty card to unlink.
 @param completionHandler The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)unlinkLoyaltyCardID:(NSString *)cardID completionHandler:(didUnlinkLoyaltyCard)completionHandler NS_SWIFT_NAME(unlinkCard(havingID:completionHandler:));

/*!
 @abstract Makes a request to update @link retailers @/link with retailers for which a user can link a loyalty card.
 @discussion @link didFetchRetailers: @/link is called in response to this method.
 @result <code>BOOL</code> indicating whether the request will be sent.
 @deprecated Use @link fetchRetailersWithCompletionHandler: @/link.
 */
- (BOOL)fetchRetailers __attribute__((deprecated("Use fetchRetailersWithCompletionHandler:")));
/*!
 @abstract Makes a request to update @link retailers @/link with retailers for which a user can link a loyalty card.
 @param completionHandler The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)fetchRetailersWithCompletionHandler:(didFetchRetailers)completionHandler NS_SWIFT_NAME(fetchRetailers(completionHandler:));
/*!
 @abstract Makes a request to update @link retailers @/link with retailers in the specified zipcode for which a user can link a loyalty card.
 @discussion @link didFetchRetailers: @/link is called in response to this method.
 @param zipCode Zipcode in which to search for retailers.
 @result <code>BOOL</code> indicating whether the request will be sent.
 @deprecated Use @link fetchRetailersWithZipCode:completionHandler: @/link.
 */
- (BOOL)fetchRetailersWithZipCode:(NSString *)zipCode __attribute__((deprecated("Use fetchRetailersWithZipCode:completionHandler:"))) NS_SWIFT_NAME(fetchRetailers(inZipCode:));
/*!
 @abstract Makes a request to update @link retailers @/link with retailers in the specified zipcode for which a user can link a loyalty card.
 @param zipCode Zipcode in which to search for retailers.
 @param completionHandler The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)fetchRetailersWithZipCode:(NSString *)zipCode completionHandler:(didFetchRetailers)completionHandler NS_SWIFT_NAME(fetchRetailers(inZipCode:completionHandler:));

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_LOYALTY_CARDS_MANAGER__ */
