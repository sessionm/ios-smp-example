//
//  SMTransaction.h
//  SessionM
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SM_TRANSACTION__
#define __SM_TRANSACTION__

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @typedef SMTransactionKind
 @abstract Transaction kind.

 @constant SMTransactionKindUnknown Transaction kind is unknown.
 @constant SMTransactionKindCredit User earned points from the transaction.
 @constant SMTransactionKindDebit User lost points from the transaction.
 */
typedef NS_ENUM (NSInteger, SMTransactionKind) {
    SMTransactionKindUnknown NS_SWIFT_NAME(unknown),
    SMTransactionKindCredit NS_SWIFT_NAME(credit),
    SMTransactionKindDebit NS_SWIFT_NAME(debit)
};

/*!
 @typedef SMTransactionSource
 @abstract Transaction source.

 @constant SMTransactionSourceUnknown Transaction source is unknown.
 @constant SMTransactionSourceAchievement Points were earned by claiming an achievement.
 @constant SMTransactionSourceContest Points were earned or lost from a contest.
 @constant SMTransactionSourceSponsor Points were earned by engaging with sponsored content.
 @constant SMTransactionSourceMerchantRewards Points were earned or lost from a loyalty rewards program transaction.
 @constant SMTransactionSourceEnterprise Points were earned through a server-to-server API call.
 @constant SMTransactionSourceComp Points were given to user as compensation.
 @constant SMTransactionSourceUsed Points were lost from making a rewards store purchase.
 */
typedef NS_ENUM (NSInteger, SMTransactionSource) {
    SMTransactionSourceUnknown NS_SWIFT_NAME(unknown),
    SMTransactionSourceAchievement NS_SWIFT_NAME(achievement),
    SMTransactionSourceContest NS_SWIFT_NAME(contest),
    SMTransactionSourceSponsor NS_SWIFT_NAME(sponsor),
    SMTransactionSourceMerchantRewards NS_SWIFT_NAME(merchantRewards),
    SMTransactionSourceEnterprise NS_SWIFT_NAME(enterprise),
    SMTransactionSourceComp NS_SWIFT_NAME(comp),
    SMTransactionSourceUsed NS_SWIFT_NAME(used)
};

/*!
 @typedef SMTransactionPointsType
 @abstract Transaction points type.

 @constant SMTransactionPointsTypeUnknown Transaction points type is unknown.
 @constant SMTransactionPointsTypeDonation A donation was made.
 @constant SMTransactionPointsTypeSweepstakes A sweepstakes was won or entered.
 @constant SMTransactionPointsTypeMerchandise Merchandise from a loyalty rewards program was purchased.
 @constant SMTransactionPointsTypeDigital A digital reward was purchased from the rewards store.
 @constant SMTransactionPointsTypePhysical A physical reward was purchased from the rewards store.
 @constant SMTransactionPointsTypeReceipt Points were earned from a receipt capture campaign.
 @constant SMTransactionPointsTypeLoyaltyCard Points were earned from a loyalty card transaction.
 @constant SMTransactionPointsTypeHistorical Indicates that the transaction data was migrated into the SessionM Platform from an external rewards system.
 */
typedef NS_ENUM (NSInteger, SMTransactionPointsType) {
    SMTransactionPointsTypeUnknown NS_SWIFT_NAME(unknown),
    SMTransactionPointsTypeDonation NS_SWIFT_NAME(donation),
    SMTransactionPointsTypeSweepstakes NS_SWIFT_NAME(sweepstakes),
    SMTransactionPointsTypeMerchandise NS_SWIFT_NAME(merchandise),
    SMTransactionPointsTypeDigital NS_SWIFT_NAME(digital),
    SMTransactionPointsTypePhysical NS_SWIFT_NAME(physical),
    SMTransactionPointsTypeReceipt NS_SWIFT_NAME(receipt),
    SMTransactionPointsTypeLoyaltyCard NS_SWIFT_NAME(loyaltyCard),
    SMTransactionPointsTypeHistorical NS_SWIFT_NAME(historical)
};


/*!
 @class SMTransaction
 @abstract Defines the data associated with a loyalty points transaction.
 */
@interface SMTransaction : NSObject

/*!
 @property recordID
 @abstract Unique ID for transaction record.
 */
@property(nonatomic, strong, readonly) NSString *recordID;
/*!
 @property balance
 @abstract User's loyalty points balance after the transaction was made.
 */
@property(nonatomic, assign, readonly) NSInteger balance;
/*!
 @property date
 @abstract Date of transaction.
 */
@property(nonatomic, strong, readonly) NSString *date;
/*!
 @property details
 @abstract Transaction details.
 */
@property(nonatomic, strong, readonly) NSString *details;
/*!
 @property descriptionText
 @abstract Transaction details.
 @deprecated This property has been deprecated - use @link details @/link instead.
 */
@property(nonatomic, strong, readonly) NSString *descriptionText __attribute__((deprecated));
/*!
 @property points
 @abstract Amount of points earned or lost from the transaction.
 */
@property(nonatomic, assign, readonly) NSInteger points;
/*!
 @property recordModelID
 @abstract Associated ID for corresponding receipt submission result or loyalty card transaction.
 */
@property(nullable, nonatomic, strong, readonly) NSString *recordModelID;
/*!
 @property transaction
 @abstract Kind of transaction.
 */
@property(nonatomic, assign, readonly) SMTransactionKind transaction;
/*!
 @property source
 @abstract Source that initialized the transaction.
 */
@property(nonatomic, assign, readonly) SMTransactionSource source;
/*!
 @property type
 @abstract Type of points earned or lost from the transaction.
 */
@property(nonatomic, assign, readonly) SMTransactionPointsType type;
/*!
 @property extras
 @abstract Any data values that do not have an associated class property.
 */
@property(nullable, nonatomic, strong, readonly) NSDictionary<NSString *, id> *extras;

/*!
 @abstract Converts specified string value to the corresponding @link SMTransactionKind @/link enum value.
 @param string String to convert.
 @result @link SMTransactionKind @/link enum value.
 */
+ (SMTransactionKind)transactionKindForString:(NSString *)string NS_SWIFT_NAME(transactionKind(from:));
/*!
 @abstract Converts specified string value to the corresponding @link SMTransactionSource @/link enum value.
 @param string String to convert.
 @result @link SMTransactionSource @/link enum value.
 */
+ (SMTransactionSource)transactionSourceForString:(NSString *)string NS_SWIFT_NAME(transactionSource(from:));
/*!
 @abstract Converts specified string value to the corresponding @link SMTransactionPointsType @/link enum value.
 @param string String to convert.
 @result @link SMTransactionPointsType @/link enum value.
 */
+ (SMTransactionPointsType)transactionPointsTypeForString:(NSString *)string NS_SWIFT_NAME(transactionPointsType(from:));

/*!
 @abstract Converts specified @link SMTransactionKind @/link enum value to the corresponding string value.
 @param kind Transaction kind to convert.
 @result <code>NSString</code> value.
 */
+ (NSString *)stringForTransactionKind:(SMTransactionKind)kind NS_SWIFT_NAME(string(from:));
/*!
 @abstract Converts specified @link SMTransactionSource @/link enum value to the corresponding string value.
 @param source Transaction source to convert.
 @result <code>NSString</code> value.
 */
+ (NSString *)stringForTransactionSource:(SMTransactionSource)source NS_SWIFT_NAME(string(from:));
/*!
 @abstract Converts specified @link SMTransactionPointsType @/link enum value to the corresponding string value.
 @param type Transaction points type to convert.
 @result <code>NSString</code> value.
 */
+ (NSString *)stringForTransactionPointsType:(SMTransactionPointsType)type NS_SWIFT_NAME(string(from:));

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_TRANSACTION__ */
