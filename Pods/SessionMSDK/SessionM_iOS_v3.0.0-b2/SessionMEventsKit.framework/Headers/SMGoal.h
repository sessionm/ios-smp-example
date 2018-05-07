//
//  SMGoal.h
//  SessionMEventsKit
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SM_GOAL__
#define __SM_GOAL__

#import "SMProgressBehavior.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMGoal
 @abstract Defines the user's progress towards completing an action item that make up a composite behavior.
 */
@interface SMGoal : NSObject

/*!
 @property groupID
 @abstract ID of the rule group that the goal belongs to.
 */
@property(nonatomic, strong, readonly) NSString *groupID;
/*!
 @property type
 @abstract Goal type.
 */
@property(nonatomic, strong, readonly) NSString *type;
/*!
 @property points
 @abstract Points rewarded from goal.
 */
@property(nonatomic, assign, readonly) NSInteger points;
/*!
 @property earnCount
 @abstract Counts earned for goal.
 */
@property(nonatomic, assign, readonly) NSInteger earnCount;
/*!
 @property isCompleted
 @abstract Indicates whether the goal has been completed by the user.
 */
@property(nonatomic, assign, readonly) BOOL isCompleted;
/*!
 @property isRequired
 @abstract Indicates whether the user needs to complete the goal in order to complete the associated composite behavior.
 */
@property(nonatomic, assign, readonly) BOOL isRequired;
/*!
 @property progress
 @abstract Behavior data associated with the goal.
 */
@property(nonatomic, strong, readonly) SMProgressBehavior *progress;
/*!
 @property extras
 @abstract Any data values that do not have an associated class property.
 */
@property(nullable, nonatomic, strong, readonly) NSDictionary<NSString *, id> *extras;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_GOAL__ */
