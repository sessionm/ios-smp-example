//
//  SMGroup.h
//  SessionM
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SM_GROUP__
#define __SM_GROUP__

#import "SMGoal.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMGroup
 @abstract Defines the user's progress towards completing a group of action items that make up a composite behavior.
 */
@interface SMGroup : NSObject

/*!
 @property type
 @abstract Group type.
 */
@property(nonatomic, strong, readonly) NSString *type;
/*!
 @property currentCount
 @abstract Current number of completed goals in the rule group.
 */
@property(nonatomic, assign, readonly) NSInteger currentCount;
/*!
 @property totalCount
 @abstract Total number of goals that need to be completed in order to complete the rule group (note: this value may be different from @link numGoals @/link if some of the goals in the rule group are not required).
 */
@property(nonatomic, assign, readonly) NSInteger totalCount;
/*!
 @property numGoals
 @abstract Number of goals in the rule group.
 */
@property(nonatomic, assign, readonly) NSInteger numGoals;
/*!
 @property isCompleted
 @abstract Indicates whether the rule group has been completed.
 */
@property(nonatomic, assign, readonly) BOOL isCompleted;
/*!
 @property goals
 @abstract Goals associated with the rule group.
 */
@property(nonatomic, strong, readonly) NSDictionary<NSString *, SMGoal *> *goals;
/*!
 @property extras
 @abstract Any data values that do not have an associated class property.
 */
@property(nullable, nonatomic, strong, readonly) NSDictionary<NSString *, id> *extras;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_GROUP__ */
