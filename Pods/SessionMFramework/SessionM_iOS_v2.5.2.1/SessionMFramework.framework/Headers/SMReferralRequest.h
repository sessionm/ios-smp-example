//
//  SMReferralRequest.h
//  SessionM
//
//  Copyright © 2018 SessionM. All rights reserved.
//
//

#ifndef __SM_REFERRAL_REQUEST__
#define __SM_REFERRAL_REQUEST__

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMReferralRequest
 @abstract Defines the data associated with a registration referral request.
 */
@interface SMReferralRequest : NSObject

/*!
 @property email
 @abstract Referee's email address.
 */
@property(nonatomic, strong, readonly) NSString *email;
/*!
 @property name
 @abstract Name of person being referred.
 */
@property(nullable, nonatomic, strong, readonly) NSString *name;
/*!
 @property phoneNumber
 @abstract Referee's phone number.
 */
@property(nullable, nonatomic, strong, readonly) NSString *phoneNumber;
/*!
 @property origin
 @abstract Referral origin.
 */
@property(nullable, nonatomic, strong, readonly) NSString *origin;
/*!
 @property source
 @abstract Referral source.
 */
@property(nullable, nonatomic, strong, readonly) NSString *source;
/*!
 @property clientData
 @abstract Opaque developer-defined data.
 */
@property(nullable, nonatomic, strong, readonly) id clientData;

/*!
 @abstract Creates a new instance of <code>SMReferralRequest</code> with the specified parameters.
 @param email Referee's email address.
 @param name Name of person being referred (optional).
 @param phoneNumber Referee's phone number (optional).
 @param origin Referral origin (optional).
 @param source Referral source (optional).
 @param clientData Opaque developer-defined data (optional).
 @result <code>SMReferralRequest</code> instance.
 */
- (instancetype)initWithEmail:(NSString *)email name:(NSString * _Nullable)name phoneNumber:(NSString * _Nullable)phoneNumber origin:(NSString * _Nullable)origin source:(NSString * _Nullable)source clientData:(id _Nullable)clientData NS_SWIFT_NAME(init(email:name:phoneNumber:origin:source:clientData:));
/*!
 @abstract Returns referral request data in a dictionary format.
 @result <code>NSDictionary</code> respresentation of referral request data.
 */
- (NSDictionary *)asDictionary;

@end

/*!
 @class SMReferralsRequest
 @abstract Encapsulates an array of referral requests.
 */
@interface SMReferralsRequest : NSObject

/*!
 @property requests
 @abstract Referral requests to be sent (see @link //apple_ref/occ/instm/SMReferralsManager/sendReferrals:completionHandler: @/link).
 */
@property(nonatomic, strong, readonly) NSArray<SMReferralRequest *> *requests;
/*!
 @property referrer
 @abstract Name of user sending referrals.
 */
@property(nullable, nonatomic, strong, readonly) NSString *referrer;

/*!
 @abstract Creates a new instance of <code>SMReferralsRequest</code> with the specified parameters.
 @param requests The referral requests to be sent.
 @param referrer Name of user sending referrals (optional).
 @result <code>SMReferralsRequest</code> instance.
 */
- (instancetype)initWithRequests:(NSArray<SMReferralRequest *> *)requests referrer:(NSString * _Nullable)referrer NS_SWIFT_NAME(init(requests:referrer:));

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_REFERRAL_REQUEST__ */
