//
//  SMPUserReferral.h
//  SessionM
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SMP_USER_REFERRAL__
#define __SMP_USER_REFERRAL__

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMPUserReferral
 @abstract Defines the data associated with a user referral.
 */
@interface SMPUserReferral : NSObject

/*!
 @property referralCode
 @abstract A referral code received from a user that can be provided when creating or updating an account as part of a refer-a-friend program.
 */
@property(nonatomic, strong, readonly) NSString *referralCode;
/*!
 @property source
 @abstract Name of the user who provided the referral code.
 */
@property(nullable, nonatomic, strong, readonly) NSString *source;

/*!
 @abstract Creates a new instance of <code>SMPUserReferral</code> with the specified parameters.
 @param referralCode A referral code received from a user that can be provided when creating or updating an account as part of a refer-a-friend program.
 @param source Name of the user who provided the referral code.
 @result <code>SMPUserReferral</code> instance.
 */
- (instancetype)initWithReferralCode:(NSString *)referralCode source:(NSString * _Nullable)source;

/*!
 @abstract Returns user referral data in a dictionary format.
 @result <code>NSDictionary</code> representation of user referral data.
 */
- (NSDictionary<NSString *, id> *)asDictionary;

@end

NS_ASSUME_NONNULL_END

#endif /* __SMP_USER_REFERRAL__ */
