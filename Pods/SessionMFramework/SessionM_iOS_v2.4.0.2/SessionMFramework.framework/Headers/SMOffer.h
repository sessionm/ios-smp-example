//
//  SMOffer.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef __SM_OFFER__
#define __SM_OFFER__

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @typedef SMOfferStatus
 @abstract Offer eligibility status.

 @constant SMOfferStatusUnknown Offer status is unknown.
 @constant SMOfferStatusAvailable Offer is available for redemption.
 @constant SMOfferStatusVerificationRequired Offer requires verification.
 @constant SMOfferStatusNotQualified User is not qualified for offer.
 @constant SMOfferStatusInsufficientPoints User doesn't have enough points.
 @constant SMOfferStatusUserRequired Session needs to have a user active.
 @constant SMOfferStatusRegistrationRequired User needs to be registered.
 */
typedef NS_ENUM(NSInteger, SMOfferStatus) {
    SMOfferStatusUnknown NS_SWIFT_NAME(unknown),
    SMOfferStatusAvailable NS_SWIFT_NAME(available),
    SMOfferStatusVerificationRequired NS_SWIFT_NAME(verificationRequired),
    SMOfferStatusNotQualified NS_SWIFT_NAME(notQualified),
    SMOfferStatusInsufficientPoints NS_SWIFT_NAME(insufficientPoints),
    SMOfferStatusUserRequired NS_SWIFT_NAME(userRequired),
    SMOfferStatusRegistrationRequired NS_SWIFT_NAME(registrationRequired)
};


/*!
 @class SMOffer
 @abstract Defines the data associated with an offer order made by a user.
 */
@interface SMOffer : NSObject

/*!
 @property offerID
 @abstract Unique ID for offer.
 */
@property(nonnull, nonatomic, strong, readonly) NSString *offerID;
/*!
 @property name
 @abstract Offer name.
 */
@property(nullable, nonatomic, strong, readonly) NSString *name;
/*!
 @property type
 @abstract Reward type (e.g. "offer" or "coupon").
 */
@property(nullable, nonatomic, strong, readonly) NSString *type;
/*!
 @property descriptionText
 @abstract Offer description.
 */
@property(nullable, nonatomic, strong, readonly) NSString *descriptionText;
/*!
 @property points
 @abstract Amount of points needed to redeem offer.
 */
@property(nonatomic, assign, readonly) NSInteger points;
/*!
 @property startTime
 @abstract Indicates when the offer became available for redemption.
 */
@property(nullable, nonatomic, strong, readonly) NSString *startTime;
/*!
 @property endTime
 @abstract Indicates when the offer will no longer be available for redemption.
 */
@property(nullable, nonatomic, strong, readonly) NSString *endTime;
/*!
 @property weight
 @abstract Developer-defined numerical value that can be used to sort offers.
 */
@property(nonatomic, assign, readonly) NSInteger weight;
/*!
 @property isFeatured
 @abstract Defines whether the offer is in the rewards system's list of featured offers.
 */
@property(nonatomic, assign, readonly) BOOL isFeatured;
/*!
 @property isSkillChallengeRequired
 @abstract Defines whether a user must pass a skill challenge to redeem the offer.
 */
@property(nonatomic, assign, readonly) BOOL isSkillChallengeRequired;
/*!
 @property tier
 @abstract If tiers are enabled in the rewards system, defines what tier a user must reach to redeem the offer.
 */
@property(nullable, nonatomic, strong, readonly) NSString *tier;
/*!
 @property logoURL
 @abstract URL to image associated with the offer.
 */
@property(nullable, nonatomic, strong, readonly) NSString *logoURL;
/*!
 @property status
 @abstract Offer eligibility status.
 */
@property(nonatomic, assign, readonly) SMOfferStatus status;
/*!
 @property data
 @abstract Custom developer-defined data associated with the offer.
 */
@property(nullable, nonatomic, strong, readonly) NSDictionary<NSString *, NSObject *> *data;
/*!
 @property options
 @abstract List of variants for the offer that differ in some aspect (e.g. additional sizes for a shirt).
 */
@property(nullable, nonatomic, strong, readonly) NSArray<SMOffer *> *options;
/*!
 @property extras
 @abstract Any data values that do not have an associated class property.
 */
@property(nullable, nonatomic, strong, readonly) NSDictionary<NSString *, NSObject *> *extras;

/*!
 @abstract Converts specified string value to the corresponding @link SMOfferStatus @/link enum value.
 @param string String to convert.
 @result @link SMOfferStatus @/link enum value.
 */
+ (SMOfferStatus)statusForString:(NSString *)string NS_SWIFT_NAME(offerStatus(from:));
/*!
 @abstract Converts specified @link SMOfferStatus @/link enum value to the corresponding string value.
 @param status Status to convert.
 @result <code>NSString</code> value.
 */
+ (NSString *)stringForStatus:(SMOfferStatus)status NS_SWIFT_NAME(string(from:));

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_OFFER__ */
