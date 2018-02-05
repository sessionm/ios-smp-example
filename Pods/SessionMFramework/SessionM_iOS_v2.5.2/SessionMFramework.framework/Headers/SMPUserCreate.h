//
//  SMPUserCreate.h
//  SessionM
//
//  Copyright © 2018 SessionM. All rights reserved.
//
//

#ifndef __SMP_USER_CREATE__
#define __SMP_USER_CREATE__

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMPUserCreate
 @abstract Defines the data associated with a user creation request.
 */
@interface SMPUserCreate : NSObject

// Required fields

/*!
 @property email
 @abstract User's email address.
 */
@property(nonatomic, strong, readwrite) NSString *email;
/*!
 @property password
 @abstract User's password.
 */
@property(nonatomic, strong, readwrite) NSString *password;

// Optional fields

/*!
 @property firstName
 @abstract User's first name.
 */
@property(nullable, nonatomic, strong, readwrite) NSString *firstName;
/*!
 @property lastName
 @abstract User's last name.
 */
@property(nullable, nonatomic, strong, readwrite) NSString *lastName;
/*!
 @property gender
 @abstract User's gender.
 */
@property(nullable, nonatomic, strong, readwrite) NSString *gender;
/*!
 @property dateOfBirth
 @abstract User's date of birth.
 */
@property(nullable, nonatomic, strong, readwrite) NSString *dateOfBirth;
/*!
 @property city
 @abstract User's city of residence.
 */
@property(nullable, nonatomic, strong, readwrite) NSString *city;
/*!
 @property state
 @abstract User's state or province of residence.
 */
@property(nullable, nonatomic, strong, readwrite) NSString *state;
/*!
 @property zipCode
 @abstract User's home zip code.
 */
@property(nullable, nonatomic, strong, readwrite) NSString *zipCode;
/*!
 @property country
 @abstract User's country of residence.
 */
@property(nullable, nonatomic, strong, readwrite) NSString *country;
/*!
 @property locale
 @abstract User's locale identifier.
 */
@property(nullable, nonatomic, strong, readwrite) NSString *locale;
/*!
 @property DMA
 @abstract User's home designated market area.
 */
@property(nullable, nonatomic, strong, readwrite) NSString *DMA;
/*!
 @property ipAddress
 @abstract User's IP address.
 */
@property(nullable, nonatomic, strong, readwrite) NSString *ipAddress;
/*!
 @property externalID
 @abstract User's non-SessionM ID.
 */
@property(nullable, nonatomic, strong, readwrite) NSString *externalID;

/*!
 @property dictionary
 @abstract Returns creation request data in a dictionary format.
 */
@property(nonatomic, strong, readonly) NSDictionary<NSString *, id> *dictionary;

/*!
 @abstract Creates a new instance of <code>SMPUserCreate</code> with the specified parameters.
 @param email User's email.
 @param password User's password.
 @result <code>SMPUserCreate</code> instance.
 */
- (instancetype)initWithEmail:(NSString *)email password:(NSString *)password;

@end

NS_ASSUME_NONNULL_END

#endif /* __SMP_USER_CREATE__ */
