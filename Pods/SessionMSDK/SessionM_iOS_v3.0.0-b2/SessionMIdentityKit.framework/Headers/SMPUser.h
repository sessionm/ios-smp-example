//
//  SMPUser.h
//  SessionMIdentityKit
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SMP_USER__
#define __SMP_USER__

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @const kUserNewUser
 @abstract Indicates new user object was created (e.g. after first call to <code>SMUserManager fetchUserWithCompletionHandler:</code>).
 @discussion Using the <code>kUserDeltas</code> key on a <code>SM_USER_MANAGER_DID_UPDATE_USER</code> notification's <code>userInfo</code> property will return a set containing this string if a new user object was created (see <code>SMUserManager</code> for more details).
 */
extern NSString *const kUserNewUser;
/*!
 @const kUserAccountStatus
 @abstract Used to access the <code>accountStatus</code> value when using <code>asDictionary</code>.
 */
extern NSString *const kUserAccountStatus;
/*!
 @const kUserAvailablePoints
 @abstract Used to access the <code>availablePoints</code> value when using <code>asDictionary</code>.
 @discussion Using the <code>kUserDeltas</code> key on a <code>SM_USER_MANAGER_DID_UPDATE_USER</code> notification's <code>userInfo</code> property will return a set containing this string if the <code>availablePoints</code> property was updated (see <code>SMUserManager</code> for more details).
 */
extern NSString *const kUserAvailablePoints;
/*!
 @const kUserLocale
 @abstract Used to access the <code>locale</code> value when using <code>asDictionary</code>.
 @discussion Using the <code>kUserDeltas</code> key on a <code>SM_USER_MANAGER_DID_UPDATE_USER</code> notification's <code>userInfo</code> property will return a set containing this string if the <code>locale</code> property was updated (see <code>SMUserManager</code> for more details).
 */
extern NSString *const kUserLocale;
/*!
 @const kUserCountry
 @abstract Used to access the <code>country</code> value when using <code>asDictionary</code>.
 @discussion Using the <code>kUserDeltas</code> key on a <code>SM_USER_MANAGER_DID_UPDATE_USER</code> notification's <code>userInfo</code> property will return a set containing this string if the <code>country</code> property was updated (see <code>SMUserManager</code> for more details).
 */
extern NSString *const kUserCountry;
/*!
 @const kUserCreatedTime
 @abstract Used to access the <code>createdTime</code> value when using <code>asDictionary</code>.
 */
extern NSString *const kUserCreatedTime;
/*!
 @const kUserCurrentDMA
 @abstract Used to access the <code>currentDMA</code> value when using <code>asDictionary</code>.
 */
extern NSString *const kUserCurrentDMA;
/*!
 @const kUserCurrentCity
 @abstract Used to access the <code>currentCity</code> value when using <code>asDictionary</code>.
 @discussion Using the <code>kUserDeltas</code> key on a <code>SM_USER_MANAGER_DID_UPDATE_USER</code> notification's <code>userInfo</code> property will return a set containing this string if the <code>currentCity</code> property was updated (see <code>SMUserManager</code> for more details).
 */
extern NSString *const kUserCurrentCity;
/*!
 @const kUserCurrentState
 @abstract Used to access the <code>currentState</code> value when using <code>asDictionary</code>.
 */
extern NSString *const kUserCurrentState;
/*!
 @const kUserCurrentZipCode
 @abstract Used to access the <code>currentZipCode</code> value when using <code>asDictionary</code>.
 */
extern NSString *const kUserCurrentZipCode;
/*!
 @const kUserCurrentCountry
 @abstract Used to access the <code>currentCountry</code> value when using <code>asDictionary</code>.
 */
extern NSString *const kUserCurrentCountry;
/*!
 @const kUserDateOfBirth
 @abstract Used to access the <code>dateOfBirth</code> value when using <code>asDictionary</code>.
 @discussion Using the <code>kUserDeltas</code> key on a <code>SM_USER_MANAGER_DID_UPDATE_USER</code> notification's <code>userInfo</code> property will return a set containing this string if the <code>dateOfBirth</code> property was updated (see <code>SMUserManager</code> for more details).
 */
extern NSString *const kUserDateOfBirth;
/*!
 @const kUserDMA
 @abstract Used to access the <code>dma</code> value when using <code>asDictionary</code>.
 @discussion Using the <code>kUserDeltas</code> key on a <code>SM_USER_MANAGER_DID_UPDATE_USER</code> notification's <code>userInfo</code> property will return a set containing this string if the <code>dma</code> property was updated (see <code>SMUserManager</code> for more details).
 */
extern NSString *const kUserDMA;
/*!
 @const kUserEmail
 @abstract Used to access the <code>email</code> value when using <code>asDictionary</code>.
 @discussion Using the <code>kUserDeltas</code> key on a <code>SM_USER_MANAGER_DID_UPDATE_USER</code> notification's <code>userInfo</code> property will return a set containing this string if the <code>email</code> property was updated (see <code>SMUserManager</code> for more details).
 */
extern NSString *const kUserEmail;
/*!
 @const kUserExternalID
 @abstract Used to access the <code>externalID</code> value when using <code>asDictionary</code>.
 @discussion Using the <code>kUserDeltas</code> key on a <code>SM_USER_MANAGER_DID_UPDATE_USER</code> notification's <code>userInfo</code> property will return a set containing this string if the <code>externalID</code> property was updated (see <code>SMUserManager</code> for more details).
 */
extern NSString *const kUserExternalID;
/*!
 @const kUserFirstName
 @abstract Used to access the <code>firstName</code> value when using <code>asDictionary</code>.
 @discussion Using the <code>kUserDeltas</code> key on a <code>SM_USER_MANAGER_DID_UPDATE_USER</code> notification's <code>userInfo</code> property will return a set containing this string if the <code>firstName</code> property was updated (see <code>SMUserManager</code> for more details).
 */
extern NSString *const kUserFirstName;
/*!
 @const kUserGender
 @abstract Used to access the <code>gender</code> value when using <code>asDictionary</code>.
 @discussion Using the <code>kUserDeltas</code> key on a <code>SM_USER_MANAGER_DID_UPDATE_USER</code> notification's <code>userInfo</code> property will return a set containing this string if the <code>gender</code> property was updated (see <code>SMUserManager</code> for more details).
 */
extern NSString *const kUserGender;
/*!
 @const kUserIsSuspended
 @abstract Used to access the <code>isSuspended</code> value when using <code>asDictionary</code>.
 */
extern NSString *const kUserIsSuspended;
/*!
 @const kUserIsTestAccount
 @abstract Used to access the <code>isTestAccount</code> value when using <code>asDictionary</code>.
 */
extern NSString *const kUserIsTestAccount;
/*!
 @const kUserLastName
 @abstract Used to access the <code>lastName</code> value when using <code>asDictionary</code>.
 @discussion Using the <code>kUserDeltas</code> key on a <code>SM_USER_MANAGER_DID_UPDATE_USER</code> notification's <code>userInfo</code> property will return a set containing this string if the <code>lastName</code> property was updated (see <code>SMUserManager</code> for more details).
 */
extern NSString *const kUserLastName;
/*!
 @const kUserLatitude
 @abstract Used to access the <code>latitude</code> value when using <code>asDictionary</code>.
 @discussion Using the <code>kUserDeltas</code> key on a <code>SM_USER_MANAGER_DID_UPDATE_USER</code> notification's <code>userInfo</code> property will return a set containing this string if the <code>latitude</code> property was updated (see <code>SMUserManager</code> for more details).
 */
extern NSString *const kUserLatitude;
/*!
 @const kUserLongitude
 @abstract Used to access the <code>longitude</code> value when using <code>asDictionary</code>.
 @discussion Using the <code>kUserDeltas</code> key on a <code>SM_USER_MANAGER_DID_UPDATE_USER</code> notification's <code>userInfo</code> property will return a set containing this string if the <code>longitude</code> property was updated (see <code>SMUserManager</code> for more details).
 */
extern NSString *const kUserLongitude;
/*!
 @const kUserNextTierPercentage
 @abstract Used to access the <code>nextTierPercentage</code> value when using <code>asDictionary</code>.
 */
extern NSString *const kUserNextTierPercentage;
/*!
 @const kUserProxyIDs
 @abstract Used to access the <code>proxyIDs</code> value when using <code>asDictionary</code>.
 */
extern NSString *const kUserProxyIDs;
/*!
 @const kUserCity
 @abstract Used to access the <code>city</code> value when using <code>asDictionary</code>.
 @discussion Using the <code>kUserDeltas</code> key on a <code>SM_USER_MANAGER_DID_UPDATE_USER</code> notification's <code>userInfo</code> property will return a set containing this string if the <code>city</code> property was updated (see <code>SMUserManager</code> for more details).
 */
extern NSString *const kUserCity;
/*!
 @const kUserState
 @abstract Used to access the <code>state</code> value when using <code>asDictionary</code>.
 @discussion Using the <code>kUserDeltas</code> key on a <code>SM_USER_MANAGER_DID_UPDATE_USER</code> notification's <code>userInfo</code> property will return a set containing this string if the <code>state</code> property was updated (see <code>SMUserManager</code> for more details).
 */
extern NSString *const kUserState;
/*!
 @const kUserTestPoints
 @abstract Used to access the <code>testPoints</code> value when using <code>asDictionary</code>.
 @discussion Using the <code>kUserDeltas</code> key on a <code>SM_USER_MANAGER_DID_UPDATE_USER</code> notification's <code>userInfo</code> property will return a set containing this string if the <code>testPoints</code> property was updated (see <code>SMUserManager</code> for more details).
 */
extern NSString *const kUserTestPoints;
/*!
 @const kUserUnclaimedAchievementCount
 @abstract Used to access the <code>unclaimedAchievementCount</code> value when using <code>asDictionary</code>.
 */
extern NSString *const kUserUnclaimedAchievementCount;
/*!
 @const kUserUpdatedTime
 @abstract Used to access the <code>updatedTime</code> value when using <code>asDictionary</code>.
 */
extern NSString *const kUserUpdatedTime;
/*!
 @const kUserUserProfile
 @abstract Used to access the <code>userProfile</code> value when using <code>asDictionary</code>.
 @discussion Using the <code>kUserDeltas</code> key on a <code>SM_USER_MANAGER_DID_UPDATE_USER</code> notification's <code>userInfo</code> property will return a set containing this string if the <code>userProfile</code> property was updated (see <code>SMUserManager</code> for more details).
 */
extern NSString *const kUserUserProfile;
/*!
 @const kUserUserID
 @abstract Used to access the <code>userID</code> value when using <code>asDictionary</code>.
 */
extern NSString *const kUserUserID;
/*!
 @const kUserZipCode
 @abstract Used to access the <code>zipCode</code> value when using <code>asDictionary</code>.
 @discussion Using the <code>kUserDeltas</code> key on a <code>SM_USER_MANAGER_DID_UPDATE_USER</code> notification's <code>userInfo</code> property will return a set containing this string if the <code>zipCode</code> property was updated (see <code>SMUserManager</code> for more details).
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
 @property city
 @abstract User's city of residence.
 */
@property(nullable, nonatomic, strong, readonly) NSString *city;
/*!
 @property state
 @abstract User's state or province of residence.
 */
@property(nullable, nonatomic, strong, readonly) NSString *state;
/*!
 @property zipCode
 @abstract User's home zip code.
 */
@property(nullable, nonatomic, strong, readonly) NSString *zipCode;
/*!
 @property country
 @abstract User's country of residence.
 */
@property(nullable, nonatomic, strong, readonly) NSString *country;
/*!
 @property locale
 @abstract User's locale identifier.
 */
@property(nullable, nonatomic, strong, readwrite) NSString *locale;
/*!
 @property DMA
 @abstract User's home designated market area.
 */
@property(nullable, nonatomic, strong, readonly) NSString *DMA;
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
 @property currentDMA
 @abstract User's current designated market area.
 */
@property(nullable, nonatomic, strong, readonly) NSString *currentDMA;
/*!
 @property currentCity
 @abstract User's city of residence.
 */
@property(nullable, nonatomic, strong, readonly) NSString *currentCity;
/*!
 @property currentState
 @abstract User's current state or province.
 */
@property(nullable, nonatomic, strong, readonly) NSString *currentState;
/*!
 @property currentZipCode
 @abstract User's current zip code.
 */
@property(nullable, nonatomic, strong, readonly) NSString *currentZipCode;
/*!
 @property currentCountry
 @abstract User's current country.
 */
@property(nullable, nonatomic, strong, readonly) NSString *currentCountry;
/*!
 @property userProfile
 @abstract Developer-defined attributes that can be used for analytics, targeting ads, etc.
 */
@property(nullable, nonatomic, strong, readonly) NSDictionary<NSString *, id> *userProfile;
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
@property(nullable, nonatomic, strong, readonly) NSDictionary<NSString *, id> *extras;

/*!
 @abstract Returns user data in a dictionary format.
 @result <code>NSDictionary</code> representation of user data.
 */
- (NSDictionary<NSString *, id> *)asDictionary;

/*!
 @abstract Converts specified string value to the corresponding <code>SMAccountStatus</code> enum value.
 @param string String to convert.
 @result <code>SMAccountStatus</code> enum value.
 */
+ (SMAccountStatus)statusForString:(NSString *)string NS_SWIFT_NAME(accountStatus(from:));
/*!
 @abstract Converts specified <code>SMAccountStatus</code> enum value to the corresponding string value.
 @param status Status to convert.
 @result <code>NSString</code> value.
 */
+ (NSString *)stringForStatus:(SMAccountStatus)status NS_SWIFT_NAME(string(from:));

@end

NS_ASSUME_NONNULL_END

#endif /* __SMP_USER__ */
