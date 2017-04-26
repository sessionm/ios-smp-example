//
//  SMPUser.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef __SMP_USER__
#define __SMP_USER__

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @const kUserNewUser
 @abstract Indicates new user object was created (e.g. after first call to @link //apple_ref/occ/instp/SMUserManager/fetchUserWithCompletionHandler: @/link).
 @discussion Using the <code>kUserDeltas</code> key on a @link SM_USER_MANAGER_DID_UPDATE_USER @/link notification's <code>userInfo</code> property will return a set containing this string if a new user object was created (see @link //apple_ref/occ/cl/SMUserManager @/link for more details).
 */
extern NSString *const kUserNewUser;
/*!
 @const kUserAccountStatus
 @abstract Used to access the @link accountStatus @/link value when using @link asDictionary @/link.
 */
extern NSString *const kUserAccountStatus;
/*!
 @const kUserAvailablePoints
 @abstract Used to access the @link availablePoints @/link value when using @link asDictionary @/link.
 @discussion Using the <code>kUserDeltas</code> key on a @link SM_USER_MANAGER_DID_UPDATE_USER @/link notification's <code>userInfo</code> property will return a set containing this string if the @link availablePoints @/link property was updated (see @link //apple_ref/occ/cl/SMUserManager @/link for more details).
 */
extern NSString *const kUserAvailablePoints;
/*!
 @const kUserCountry
 @abstract Used to access the @link country @/link value when using @link asDictionary @/link.
 @discussion Using the <code>kUserDeltas</code> key on a @link SM_USER_MANAGER_DID_UPDATE_USER @/link notification's <code>userInfo</code> property will return a set containing this string if the @link country @/link property was updated (see @link //apple_ref/occ/cl/SMUserManager @/link for more details).
 */
extern NSString *const kUserCountry;
/*!
 @const kUserCreatedTime
 @abstract Used to access the @link createdTime @/link value when using @link asDictionary @/link.
 */
extern NSString *const kUserCreatedTime;
/*!
 @const kUserCurrentCountry
 @abstract Used to access the @link currentCountry @/link value when using @link asDictionary @/link.
 */
extern NSString *const kUserCurrentCountry;
/*!
 @const kUserCurrentDMA
 @abstract Used to access the @link currentDMA @/link value when using @link asDictionary @/link.
 */
extern NSString *const kUserCurrentDMA;
/*!
 @const kUserCurrentState
 @abstract Used to access the @link currentState @/link value when using @link asDictionary @/link.
 */
extern NSString *const kUserCurrentState;
/*!
 @const kUserCurrentZipCode
 @abstract Used to access the @link currentZipCode @/link value when using @link asDictionary @/link.
 */
extern NSString *const kUserCurrentZipCode;
/*!
 @const kUserDateOfBirth
 @abstract Used to access the @link dateOfBirth @/link value when using @link asDictionary @/link.
 @discussion Using the <code>kUserDeltas</code> key on a @link SM_USER_MANAGER_DID_UPDATE_USER @/link notification's <code>userInfo</code> property will return a set containing this string if the @link dateOfBirth @/link property was updated (see @link //apple_ref/occ/cl/SMUserManager @/link for more details).
 */
extern NSString *const kUserDateOfBirth;
/*!
 @const kUserDMA
 @abstract Used to access the @link dma @/link value when using @link asDictionary @/link.
 @discussion Using the <code>kUserDeltas</code> key on a @link SM_USER_MANAGER_DID_UPDATE_USER @/link notification's <code>userInfo</code> property will return a set containing this string if the @link dma @/link property was updated (see @link //apple_ref/occ/cl/SMUserManager @/link for more details).
 */
extern NSString *const kUserDMA;
/*!
 @const kUserEmail
 @abstract Used to access the @link email @/link value when using @link asDictionary @/link.
 @discussion Using the <code>kUserDeltas</code> key on a @link SM_USER_MANAGER_DID_UPDATE_USER @/link notification's <code>userInfo</code> property will return a set containing this string if the @link email @/link property was updated (see @link //apple_ref/occ/cl/SMUserManager @/link for more details).
 */
extern NSString *const kUserEmail;
/*!
 @const kUserExternalID
 @abstract Used to access the @link externalID @/link value when using @link asDictionary @/link.
 @discussion Using the <code>kUserDeltas</code> key on a @link SM_USER_MANAGER_DID_UPDATE_USER @/link notification's <code>userInfo</code> property will return a set containing this string if the @link externalID @/link property was updated (see @link //apple_ref/occ/cl/SMUserManager @/link for more details).
 */
extern NSString *const kUserExternalID;
/*!
 @const kUserFirstName
 @abstract Used to access the @link firstName @/link value when using @link asDictionary @/link.
 @discussion Using the <code>kUserDeltas</code> key on a @link SM_USER_MANAGER_DID_UPDATE_USER @/link notification's <code>userInfo</code> property will return a set containing this string if the @link firstName @/link property was updated (see @link //apple_ref/occ/cl/SMUserManager @/link for more details).
 */
extern NSString *const kUserFirstName;
/*!
 @const kUserGender
 @abstract Used to access the @link gender @/link value when using @link asDictionary @/link.
 @discussion Using the <code>kUserDeltas</code> key on a @link SM_USER_MANAGER_DID_UPDATE_USER @/link notification's <code>userInfo</code> property will return a set containing this string if the @link gender @/link property was updated (see @link //apple_ref/occ/cl/SMUserManager @/link for more details).
 */
extern NSString *const kUserGender;
/*!
 @const kUserIsSuspended
 @abstract Used to access the @link isSuspended @/link value when using @link asDictionary @/link.
 */
extern NSString *const kUserIsSuspended;
/*!
 @const kUserIsTestAccount
 @abstract Used to access the @link isTestAccount @/link value when using @link asDictionary @/link.
 */
extern NSString *const kUserIsTestAccount;
/*!
 @const kUserLastName
 @abstract Used to access the @link lastName @/link value when using @link asDictionary @/link.
 @discussion Using the <code>kUserDeltas</code> key on a @link SM_USER_MANAGER_DID_UPDATE_USER @/link notification's <code>userInfo</code> property will return a set containing this string if the @link lastName @/link property was updated (see @link //apple_ref/occ/cl/SMUserManager @/link for more details).
 */
extern NSString *const kUserLastName;
/*!
 @const kUserLatitude
 @abstract Used to access the @link latitude @/link value when using @link asDictionary @/link.
 @discussion Using the <code>kUserDeltas</code> key on a @link SM_USER_MANAGER_DID_UPDATE_USER @/link notification's <code>userInfo</code> property will return a set containing this string if the @link latitude @/link property was updated (see @link //apple_ref/occ/cl/SMUserManager @/link for more details).
 */
extern NSString *const kUserLatitude;
/*!
 @const kUserLongitude
 @abstract Used to access the @link longitude @/link value when using @link asDictionary @/link.
 @discussion Using the <code>kUserDeltas</code> key on a @link SM_USER_MANAGER_DID_UPDATE_USER @/link notification's <code>userInfo</code> property will return a set containing this string if the @link longitude @/link property was updated (see @link //apple_ref/occ/cl/SMUserManager @/link for more details).
 */
extern NSString *const kUserLongitude;
/*!
 @const kUserNextTierPercentage
 @abstract Used to access the @link nextTierPercentage @/link value when using @link asDictionary @/link.
 */
extern NSString *const kUserNextTierPercentage;
/*!
 @const kUserProxyIDs
 @abstract Used to access the @link proxyIDs @/link value when using @link asDictionary @/link.
 */
extern NSString *const kUserProxyIDs;
/*!
 @const kUserState
 @abstract Used to access the @link state @/link value when using @link asDictionary @/link.
 @discussion Using the <code>kUserDeltas</code> key on a @link SM_USER_MANAGER_DID_UPDATE_USER @/link notification's <code>userInfo</code> property will return a set containing this string if the @link state @/link property was updated (see @link //apple_ref/occ/cl/SMUserManager @/link for more details).
 */
extern NSString *const kUserState;
/*!
 @const kUserTestPoints
 @abstract Used to access the @link testPoints @/link value when using @link asDictionary @/link.
 @discussion Using the <code>kUserDeltas</code> key on a @link SM_USER_MANAGER_DID_UPDATE_USER @/link notification's <code>userInfo</code> property will return a set containing this string if the @link testPoints @/link property was updated (see @link //apple_ref/occ/cl/SMUserManager @/link for more details).
 */
extern NSString *const kUserTestPoints;
/*!
 @const kUserUnclaimedAchievementCount
 @abstract Used to access the @link unclaimedAchievementCount @/link value when using @link asDictionary @/link.
 */
extern NSString *const kUserUnclaimedAchievementCount;
/*!
 @const kUserUpdatedTime
 @abstract Used to access the @link updatedTime @/link value when using @link asDictionary @/link.
 */
extern NSString *const kUserUpdatedTime;
/*!
 @const kUserUserProfile
 @abstract Used to access the @link userProfile @/link value when using @link asDictionary @/link.
 @discussion Using the <code>kUserDeltas</code> key on a @link SM_USER_MANAGER_DID_UPDATE_USER @/link notification's <code>userInfo</code> property will return a set containing this string if the @link userProfile @/link property was updated (see @link //apple_ref/occ/cl/SMUserManager @/link for more details).
 */
extern NSString *const kUserUserProfile;
/*!
 @const kUserUserID
 @abstract Used to access the @link userID @/link value when using @link asDictionary @/link.
 */
extern NSString *const kUserUserID;
/*!
 @const kUserZipCode
 @abstract Used to access the @link zipCode @/link value when using @link asDictionary @/link.
 @discussion Using the <code>kUserDeltas</code> key on a @link SM_USER_MANAGER_DID_UPDATE_USER @/link notification's <code>userInfo</code> property will return a set containing this string if the @link zipCode @/link property was updated (see @link //apple_ref/occ/cl/SMUserManager @/link for more details).
 */
extern NSString *const kUserZipCode;


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
 @class SMPUser
 @abstract Defines the data associated with a user in the SessionM Platform.
 */
@interface SMPUser : NSObject

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
 @abstract Indicates when server-side user record was last updated.
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
 @property timestamp
 @abstract Indicates when local user object was last updated.
 */
@property(nonatomic, assign, readonly) NSTimeInterval timestamp;
/*!
 @property extras
 @abstract Any data values that do not have an associated class property.
 */
@property(nullable, nonatomic, strong, readonly) NSDictionary<NSString *, NSObject *> *extras;

/*!
 @abstract Returns user data in a dictionary format.
 @result <code>NSDictionary</code> representation of user data.
 */
- (NSDictionary<NSString *, NSObject *> *)asDictionary;

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

#endif /* __SMP_USER__ */
