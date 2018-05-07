//
//  SMTransactionsManager.h
//  SessionMTransactionsKit
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SM_TRANSACTIONS_MANAGER__
#define __SM_TRANSACTIONS_MANAGER__

#import <SessionMCoreKit/SMBaseManager.h>
#import <SessionMCoreKit/SMError.h>

#import "SMTransaction.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @const SM_TRANSACTIONS_MANAGER_REQUEST_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that an API request failed.
 @discussion An <code>SMError</code> object containing information about why the request failed can be accessed from the notification's <code>userInfo</code> property with the <code>SM_MANAGER_NOTIFICATION_ERROR_KEY</code> key.
 */
extern NSString *const SM_TRANSACTIONS_MANAGER_REQUEST_DID_FAIL_NOTIFICATION NS_SWIFT_NAME(transactionsRequestFailureNotification);
/*!
 @const SM_TRANSACTIONS_MANAGER_VALIDATION_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that a Transactions API validation failed.
 @discussion An <code>SMError</code> object containing information about why the validation failed can be accessed from the notification's <code>userInfo</code> property with the <code>SM_MANAGER_NOTIFICATION_ERROR_KEY</code> key.
 */
extern NSString *const SM_TRANSACTIONS_MANAGER_VALIDATION_DID_FAIL_NOTIFICATION NS_SWIFT_NAME(transactionsValidationFailureNotification);

/*!
 @const SM_TRANSACTIONS_MANAGER_DID_FETCH_TRANSACTIONS
 @abstract Notifies observers that transactions were fetched.
 @discussion An <code>NSArray</code> of <code>SMTransaction</code> objects can be accessed from the notification's <code>userInfo</code> property with the <code>SM_MANAGER_NOTIFICATION_DATA_KEY</code> key.
 */
extern NSString *const SM_TRANSACTIONS_MANAGER_DID_FETCH_TRANSACTIONS NS_SWIFT_NAME(fetchedTransactionsNotification);


/*!
 @typedef didFetchTransactions
 @abstract Completion handler block type for <code>fetchTransactionsWithCompletionHandler:</code>, <code>fetchTransactionsWithStartDate:endDate:limit:completionHandler:</code> and <code>fetchMoreTransactionsWithCompletionHandler:</code>.
 */
typedef void (^didFetchTransactions)(NSArray<SMTransaction *>* _Nullable transactions, BOOL hasMore, SMError * _Nullable error) NS_SWIFT_NAME(FetchTransactionsCompletionHandler);


/*!
 @class SMTransactionsManager
 @abstract This API manager contains methods for fetching loyalty points transaction data.
 */
@interface SMTransactionsManager : SMBaseManager

/*!
 @property transactions
 @abstract The current user's points transactions.
 @discussion This property is updated in response to a successful <code>fetchTransactionsWithCompletionHandler:</code>, <code>fetchTransactionsWithStartDate:endDate:limit:completionHandler:</code> or <code>fetchMoreTransactionsWithCompletionHandler:</code> call.
 */
@property(nonatomic, strong, readonly) NSArray<SMTransaction *> *transactions;

/*!
 @abstract Makes a request to update <code>transactions</code> with the current user's points transactions.
 @param completionHandler The block to execute after the request is processed.
 */
- (void)fetchTransactionsWithCompletionHandler:(didFetchTransactions)completionHandler NS_SWIFT_NAME(fetchTransactions(completionHandler:));
/*!
 @abstract Makes a request to update <code>transactions</code> with a limited number of the current user's points transactions that took place between the specified start and end dates.
 @param startDate Transactions after this date will not be fetched (optional).
 @param endDate Transactions before this date will not be fetched (optional).
 @param limit The maximum amount of transactions to fetch (optional).
 @param completionHandler The block to execute after the request is processed.
 */
- (void)fetchTransactionsWithStartDate:(NSDate * _Nullable)startDate endDate:(NSDate * _Nullable)endDate limit:(int)limit completionHandler:(didFetchTransactions)completionHandler NS_SWIFT_NAME(fetchTransactions(from:to:limit:completionHandler:));
/*!
 @abstract Makes a request to update <code>transactions</code> with points transactions that were not included in the previous fetch.
 @param completionHandler The block to execute after the request is processed.
 */
- (void)fetchMoreTransactionsWithCompletionHandler:(didFetchTransactions)completionHandler NS_SWIFT_NAME(fetchMoreTransactions(completionHandler:));

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_TRANSACTIONS_MANAGER__ */
