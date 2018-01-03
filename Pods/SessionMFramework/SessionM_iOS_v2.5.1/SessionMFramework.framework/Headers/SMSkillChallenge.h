//
//  SMSkillChallenge.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef __SM_SKILL_CHALLENGE__
#define __SM_SKILL_CHALLENGE__

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMSkillChallenge
 @abstract Defines the data associated with the server-side response for a user's answer to a skill testing question (see @link //apple_ref/occ/cl/SMSkillTestQuestion @/link).
 */
@interface SMSkillChallenge : NSObject

/*!
 @property challengeID
 @abstract Unique ID for skill challenge.
 */
@property(nonatomic, strong, readonly) NSString *challengeID;
/*!
 @property status
 @abstract Response status for the answered skill testing question (e.g. "valid" or "invalid").
 */
@property(nonatomic, strong, readonly) NSString *status;
/*!
 @property extras
 @abstract Any data values that do not have an associated class property.
 */
@property(nullable, nonatomic, strong, readonly) NSDictionary<NSString *, NSObject *> *extras;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_SKILL_CHALLENGE__ */
