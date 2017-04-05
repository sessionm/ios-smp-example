//
//  SMTransactionsManager.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef __SM_TRANSACTIONS_MANAGER__
#define __SM_TRANSACTIONS_MANAGER__

#import "SMBaseDelegate.h"
#import "SMTransaction.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @const SM_TRANSACTIONS_MANAGER_REQUEST_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that an API request failed.
 @discussion An @link SMError @/link object containing information about why the request failed can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_ERROR_KEY @/link key.
 */
extern NSString *const SM_TRANSACTIONS_MANAGER_REQUEST_DID_FAIL_NOTIFICATION NS_SWIFT_NAME(transactionsRequestFailureNotification);
/*!
 @const SM_TRANSACTIONS_MANAGER_VALIDATION_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that a Transactions API validation failed.
 @discussion An @link SMError @/link object containing information about why the validation failed can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_ERROR_KEY @/link key.
 */
extern NSString *const SM_TRANSACTIONS_MANAGER_VALIDATION_DID_FAIL_NOTIFICATION NS_SWIFT_NAME(transactionsValidationFailureNotification);

/*!
 @const SM_TRANSACTIONS_MANAGER_DID_FETCH_TRANSACTIONS
 @abstract Notifies observers that transactions were fetched.
 @discussion An <code>NSArray</code> of @link SMTransaction @/link objects can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_DATA_KEY @/link key.
 */
extern NSString *const SM_TRANSACTIONS_MANAGER_DID_FETCH_TRANSACTIONS NS_SWIFT_NAME(fetchedTransactionsNotification);

/*!
 @protocol SMTransactionsDelegate
 @abstract Defines callbacks for @link SMTransactionsManager @/link methods.
 */
@protocol SMTransactionsDelegate <SMBaseDelegate>

@optional

/*!
 @abstract Notifies delegate that points transactions were fetched.
 @discussion This method is called in response to @link fetchTransactions @/link, @link fetchTransactionsWithStartDate:endDate:limit: @/link and @link fetchMoreTransactions @/link.
 @param transactions The points transactions.
 @param hasMore Indicates whether there are more transactions that can be fetched by calling @link fetchMoreTransactions @/link .
 @deprecated Use block methods instead.
 */
- (void)didFetchTransactions:(NSArray<SMTransaction *> *)transactions hasMore:(BOOL)hasMore __attribute__((deprecated("Use block methods instead"))) NS_SWIFT_NAME(didFetchTransactions(_:hasMore:));

@end

/*!
 @typedef didFetchTransactions
 @abstract Completion handler block type for @link fetchTransactionsWithCompletionHandler: @/link, @link fetchTransactionsWithStartDate:endDate:limit:completionHandler: @/link and @link fetchMoreTransactionsWithCompletionHandler: @/link.
 */
typedef void (^didFetchTransactions)(NSArray<SMTransaction *>* _Nullable transactions, BOOL hasMore, SMError * _Nullable error) NS_SWIFT_NAME(FetchTransactionsCompletionHandler);


/*!
 @class SMTransactionsManager
 @abstract This API manager contains methods for fetching loyalty points transaction data.
 */
@interface SMTransactionsManager : NSObject

/*!
 @property delegate
 @abstract Object that implements @link SMTransactionsDelegate @/link callbacks.
 */
@property(nonatomic, weak) id<SMTransactionsDelegate> _Nullable delegate;
/*!
 @property transactions
 @abstract The current user's points transactions.
 @discussion This property is updated in response to a successful @link fetchTransactionsWithCompletionHandler: @/link, @link fetchTransactionsWithStartDate:endDate:limit:completionHandler: @/link or @link fetchMoreTransactionsWithCompletionHandler: @/link call.
 */
@property(nonatomic, strong, readonly) NSArray<SMTransaction *> *transactions;

/*!
 @abstract Makes a request to update @link transactions @/link with the current user's points transactions.
 @discussion @link didFetchTransactions:hasMore: @/link is called in response to this method.
 @result <code>BOOL</code> indicating whether the request will be sent.
 @deprecated Use @link fetchTransactionsWithCompletionHandler: @/link.
 */
- (BOOL)fetchTransactions __attribute__((deprecated("Use fetchTransactionsWithCompletionHandler:")));
/*!
 @abstract Makes a request to update @link transactions @/link with the current user's points transactions.
 @param completionHandler The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)fetchTransactionsWithCompletionHandler:(didFetchTransactions)completionHandler NS_SWIFT_NAME(fetchTransactions(completionHandler:));
/*!
 @abstract Makes a request to update @link transactions @/link with a limited number of the current user's points transactions that took place between the specified start and end dates.
 @discussion @link didFetchTransactions:hasMore: @/link is called in response to this method.
 @param startDate Transactions after this date will not be fetched (optional).
 @param endDate Transactions before this date will not be fetched (optional).
 @param limit The maximum amount of transactions to fetch (optional).
 @result <code>BOOL</code> indicating whether the request will be sent.
 @deprecated Use @link fetchTransactionsWithStartDate:endDate:limit:completionHandler: @/link.
 */
- (BOOL)fetchTransactionsWithStartDate:(NSDate * _Nullable)startDate endDate:(NSDate * _Nullable)endDate limit:(int)limit __attribute__((deprecated("Use fetchTransactionsWithStartDate:endDate:limit:completionHandler:"))) NS_SWIFT_NAME(fetchTransactions(from:to:limit:));
/*!
 @abstract Makes a request to update @link transactions @/link with a limited number of the current user's points transactions that took place between the specified start and end dates.
 @param startDate Transactions after this date will not be fetched (optional).
 @param endDate Transactions before this date will not be fetched (optional).
 @param limit The maximum amount of transactions to fetch (optional).
 @param completionHandler The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)fetchTransactionsWithStartDate:(NSDate * _Nullable)startDate endDate:(NSDate * _Nullable)endDate limit:(int)limit completionHandler:(didFetchTransactions)completionHandler NS_SWIFT_NAME(fetchTransactions(from:to:limit:completionHandler:));
/*!
 @abstract Makes a request to update @link transactions @/link with points transactions that were not included in the previous fetch.
 @discussion @link didFetchTransactions:hasMore: @/link is called in response to this method. This method should only be called if <code>hasMore</code> is set to <code>YES</code>.
 @result <code>BOOL</code> indicating whether the request will be sent.
 @deprecated Use @link fetchMoreTransactionsWithCompletionHandler: @/link.
 */
- (BOOL)fetchMoreTransactions __attribute__((deprecated("Use fetchMoreTransactionsWithCompletionHandler:")));
/*!
 @abstract Makes a request to update @link transactions @/link with points transactions that were not included in the previous fetch.
 @param completionHandler The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)fetchMoreTransactionsWithCompletionHandler:(didFetchTransactions)completionHandler NS_SWIFT_NAME(fetchMoreTransactions(completionHandler:));

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_TRANSACTIONS_MANAGER__ */
