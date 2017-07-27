//
//  CLLUserAccount.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//
//

#ifndef __CLLUserAccount_H__
#define __CLLUserAccount_H__

#import <Foundation/Foundation.h>
#import "CLLRecordBase.h"

NS_ASSUME_NONNULL_BEGIN

@interface CLLUserAccount : CLLRecordBase

/*!
 @property accountID
 @abstract Account ID (key)
 */
@property(nonatomic, readonly, strong)NSString *accountID;
/*!
 @property userName
 @abstract User Name
 */
@property(nonatomic, readonly, strong)NSString *userName;
/*!
 @property email
 @abstract Email address
 */
@property(nonatomic, readonly, strong)NSString *email;
/*!
 @property password
 @abstract Password (write only)
 */
@property(nonatomic, readonly, strong)NSString *password;
/*!
 @property imageURI
 @abstract Image of User
 */
@property(nonatomic, readonly, strong)NSString *imageURI;
/*!
 @property lastLogin
 @abstract Last login time
 */
@property(nonatomic, readonly, strong)NSDate *lastLogin;
/*!
 @property userSince
 @abstract User created time
 */
@property(nonatomic, readonly, strong)NSDate *userSince;
/*!
 @property isValid
 @abstract Is User valid
 */
@property(nonatomic, readonly, assign)BOOL isValid;
/*!
 @property emailVerified
 @abstract ???
 */
@property(nonatomic, readonly, assign)BOOL emailVerified;
/*!
 @property isAuthClaimOnly
 @abstract ???
 */
@property(nonatomic, readonly, assign)BOOL isAuthClaimOnly;
/*!
 @property isEmailVerified
 @abstract ???
 */
@property(nonatomic, readonly, assign)BOOL isEmailVerified;
/*!
 @property isSuspended
 @abstract is User suspended
 */
@property(nonatomic, readonly, assign)BOOL isSuspended;
/*!
 @property suspendedDate
 @abstract Suspension Date
 */
@property(nonatomic, readonly, strong)NSDate *suspendedDate;
/*!
 @property suspensionReason
 @abstract Reason for Suspension
 */
@property(nonatomic, readonly, strong)NSString *suspensionReason;
/*!
 @property claims
 @abstract ???
 */
@property(nonatomic, readonly, strong)NSString *claims;
@end

NS_ASSUME_NONNULL_END

#endif
