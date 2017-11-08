//
//  SMSkillQuestion.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef __SM_SKILL_QUESTION__
#define __SM_SKILL_QUESTION__

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMSkillQuestion
 @abstract Defines the data associated with a skill testing question used to gate sweepstakes entries.
 */
@interface SMSkillQuestion : NSObject

/*!
 @property questionID
 @abstract Unique ID for skill question.
 */
@property(nonatomic, strong, readonly) NSString *questionID;
/*!
 @property question
 @abstract The question that must be answered correctly in order to enter the sweepstakes (e.g. a mathematical equation).
 */
@property(nonatomic, strong, readonly) NSString *question;
/*!
 @property extras
 @abstract Any data values that do not have an associated class property.
 */
@property(nullable, nonatomic, strong, readonly) NSDictionary<NSString *, NSObject *> *extras;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_SKILL_QUESTION__ */
