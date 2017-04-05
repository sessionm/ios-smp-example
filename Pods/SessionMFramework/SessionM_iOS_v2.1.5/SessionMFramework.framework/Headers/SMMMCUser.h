//
//  SMMMCUser.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef __SM_MMC_USER__
#define __SM_MMC_USER__

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @typedef SMAccountStatus
 @abstract User account standing.

 @constant SMAccountStatusUnknown Account status is unknown.
 @constant SMAccountStatusGood User is in good standing.
 @constant SMAccountStatusMultipleAccountsViolation User has been blocked due to having multiple accounts.
 @constant SMAccountStatusReportedViolation User has been reported as violating the Terms of Service.
 @constant SMAccountStatusRequestedSuspension User has requested that their account be suspended.
 @constant SMAccountStatusReviewedReport User's reported Terms of Service violation has been reviewed by an admin.
 @constant SMAccountStatusTOSViolation User has been blocked due to violating the Terms of Service.
 @constant SMAccountStatusUnverified User's account has not been verified.
 @constant SMAccountStatusWarned User has been warned for violating the Terms of Service.
 */
typedef NS_ENUM(NSInteger, SMAccountStatus) {
    SMAccountStatusUnknown NS_SWIFT_NAME(unknown),
    SMAccountStatusGood NS_SWIFT_NAME(good),
    SMAccountStatusMultipleAccountsViolation NS_SWIFT_NAME(multipleAccountsViolation),
    SMAccountStatusReportedViolation NS_SWIFT_NAME(reported),
    SMAccountStatusRequestedSuspension NS_SWIFT_NAME(suspensionRequested),
    SMAccountStatusReviewedReport NS_SWIFT_NAME(reportReviewed),
    SMAccountStatusTOSViolation NS_SWIFT_NAME(tosViolation),
    SMAccountStatusUnverified NS_SWIFT_NAME(unverified),
    SMAccountStatusWarned NS_SWIFT_NAME(warned)
};

/*!
 @class SMMMCUser
 @abstract Defines the data associated with a user in the SessionM Mobile Marketing Cloud.
 */
@interface SMMMCUser : NSObject

/*!
 @property userID
 @abstract Unique ID for user.
 */
@property(nonnull, nonatomic, strong, readonly) NSString *userID;
/*!
 @property externalID
 @abstract Developer-defined ID associated with the user.
 */
@property(nullable, nonatomic, strong, readonly) NSString *externalID;
/*!
 @property proxyIDs
 @abstract IDs defined by third-party organizations that are associated with the user.
 */
@property(nullable, nonatomic, strong, readonly) NSArray<NSString *> *proxyIDs;
/*!
 @property createdTime
 @abstract Indicates when user data was created.
 */
@property(nullable, nonatomic, strong, readonly) NSString *createdTime;
/*!
 @property updatedTime
 @abstract Indicates when user data was last updated.
 */
@property(nullable, nonatomic, strong, readonly) NSString *updatedTime;
/*!
 @property firstName
 @abstract User's first name.
 */
@property(nullable, nonatomic, strong, readonly) NSString *firstName;
/*!
 @property lastName
 @abstract User's last name.
 */
@property(nullable, nonatomic, strong, readonly) NSString *lastName;
/*!
 @property email
 @abstract User's email address.
 */
@property(nullable, nonatomic, strong, readonly) NSString *email;
/*!
 @property dateOfBirth
 @abstract User's date of birth.
 */
@property(nullable, nonatomic, strong, readonly) NSString *dateOfBirth;
/*!
 @property gender
 @abstract User's gender.
 */
@property(nullable, nonatomic, strong, readonly) NSString *gender;
/*!
 @property zipCode
 @abstract User's home zip code.
 */
@property(nullable, nonatomic, strong, readonly) NSString *zipCode;
/*!
 @property DMA
 @abstract User's home designated market area.
 */
@property(nullable, nonatomic, strong, readonly) NSString *DMA;
/*!
 @property state
 @abstract User's state or province of residence.
 */
@property(nullable, nonatomic, strong, readonly) NSString *state;
/*!
 @property country
 @abstract User's country of residence.
 */
@property(nullable, nonatomic, strong, readonly) NSString *country;
/*!
 @property latitude
 @abstract User's current latitude.
 */
@property(nonatomic, assign, readonly) CLLocationDegrees latitude;
/*!
 @property longitude
 @abstract User's current longitude.
 */
@property(nonatomic, assign, readonly) CLLocationDegrees longitude;
/*!
 @property currentZipCode
 @abstract User's current zip code.
 */
@property(nullable, nonatomic, strong, readonly) NSString *currentZipCode;
/*!
 @property currentDMA
 @abstract User's current designated market area.
 */
@property(nullable, nonatomic, strong, readonly) NSString *currentDMA;
/*!
 @property currentState
 @abstract User's current state or province.
 */
@property(nullable, nonatomic, strong, readonly) NSString *currentState;
/*!
 @property currentCountry
 @abstract User's current country.
 */
@property(nullable, nonatomic, strong, readonly) NSString *currentCountry;
/*!
 @property userProfile
 @abstract Developer-defined attributes that can be used for analytics, targeting ads, etc.
 */
@property(nullable, nonatomic, strong, readonly) NSDictionary<NSString *, NSObject *> *userProfile;
/*!
 @property availablePoints
 @abstract User's current loyalty points balance.
 */
@property(nonatomic, assign, readonly) NSInteger availablePoints;
/*!
 @property testPoints
 @abstract The number of loyalty points that the user has earned from apps that are in development mode.
 */
@property(nonatomic, assign, readonly) NSInteger testPoints;
/*!
 @property unclaimedAchievementCount
 @abstract The number of achievements that the user has earned, but not claimed.
 */
@property(nonatomic, assign, readonly) NSInteger unclaimedAchievementCount;
/*!
 @property nextTierPercentage
 @abstract User's progress towards the next rewards tier.
 */
@property(nonatomic, assign, readonly) double nextTierPercentage;
/*!
 @property accountStatus
 @abstract User's account status.
 */
@property(nonatomic, assign, readonly) SMAccountStatus accountStatus;
/*!
 @property isSuspended
 @abstract Indicates whether the user's account is suspended.
 */
@property(nonatomic, assign, readonly) BOOL isSuspended;
/*!
 @property isTestAccount
 @abstract Indicates whether the user's account is a test account.
 */
@property(nonatomic, assign, readonly) BOOL isTestAccount;
/*!
 @property extras
 @abstract Any data values that do not have an associated class property.
 */
@property(nullable, nonatomic, strong, readonly) NSDictionary<NSString *, NSObject *> *extras;

/*!
 @abstract Returns user data in a dictionary format.
 @result <code>NSDictionary</code> representation of user data.
 */
- (NSDictionary *)asDictionary;

/*!
 @abstract Converts specified string value to the corresponding @link SMAccountStatus @/link enum value.
 @param string String to convert.
 @result @link SMAccountStatus @/link enum value.
 */
+ (SMAccountStatus)statusForString:(NSString *)string NS_SWIFT_NAME(accountStatus(from:));
/*!
 @abstract Converts specified @link SMAccountStatus @/link enum value to the corresponding string value.
 @param status Status to convert.
 @result <code>NSString</code> value.
 */
+ (NSString *)stringForStatus:(SMAccountStatus)status NS_SWIFT_NAME(string(from:));

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_MMC_USER__ */
