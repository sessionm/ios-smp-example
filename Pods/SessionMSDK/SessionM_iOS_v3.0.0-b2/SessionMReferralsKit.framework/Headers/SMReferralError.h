//
//  SMReferralError.h
//  SessionMReferralsKit
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SM_REFERRAL_ERROR__
#define __SM_REFERRAL_ERROR__

#import <Foundation/Foundation.h>
#import <SessionMCoreKit/SMError.h>

#import "SMReferral.h"
#import "SMReferralRequest.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMReferralError
 @abstract Defines the data associated with a registration referral error.
 */
@interface SMReferralError : NSObject

/*!
 @property error
 @abstract Error associated with the invalid referral request.
 */
@property(nonatomic, strong, readonly) SMError           *error;
/*!
 @property referral
 @abstract The invalid referral request data.
 */
@property(nonatomic, strong, readonly) SMReferralRequest *referral;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_REFERRAL_ERROR__ */
