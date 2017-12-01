//
//  SMCompositeBehavior.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef __SM_COMPOSITE_BEHAVIOR__
#define __SM_COMPOSITE_BEHAVIOR__

#import "SMBehavior.h"
#import "SMGoal.h"
#import "SMGroup.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMCompositeBehavior
 @abstract Defines the data associated with a composite action item comprising other count and unique behaviors.
 */
@interface SMCompositeBehavior : SMBehavior

/*!
 @property achieved
 @abstract Number of times the behavior has been completed.
 */
@property(nonatomic, assign, readonly) NSInteger achieved;
/*!
 @property points
 @abstract Number of points awarded to the user for completing the behavior.
 */
@property(nonatomic, assign, readonly) NSInteger points;
/*!
 @property maxTimesRepeatable
 @abstract Maximum number of times a user is allowed to complete the behavior.
 @discussion A value of <code>-1</code> indicates that there is no maximum.
 */
@property(nonatomic, assign, readonly) NSInteger maxTimesRepeatable;
/*!
 @property maxTimesRepeatablePerPeriod
 @abstract Maximum number of times a user is allowed to complete the behavior in the time interval specified by @link period @/link.
 @discussion A value of <code>-1</code> indicates that there is no maximum.
 */
@property(nonatomic, assign, readonly) NSInteger maxTimesRepeatablePerPeriod;
/*!
 @property period
 @abstract Defines the time interval (in seconds) that applies to @link maxTimesRepeatablePerPeriod @/link.
 */
@property(nonatomic, assign, readonly) NSTimeInterval period;
/*!
 @property goals
 @abstract Goals associated with the behavior.
 */
@property(nonatomic, strong, readonly) NSDictionary<NSString *, SMGoal *> *goals;
/*!
 @property groups
 @abstract Rule groups to which the behavior's goals can belong.
 */
@property(nonatomic, strong, readonly) NSDictionary<NSString *, SMGroup *> *groups;

/*!
 @abstract Returns goals associated with the behavior that belong to the rule group with the specified identifier.
 @param groupID The identifier for the rule group whose goals will be returned.
 @result <code>NSDictionary</code> of mappings from behavior names to goals.
 */
- (NSDictionary<NSString *, SMGoal *> *)goalsForGroupID:(NSString *)groupID NS_SWIFT_NAME(goals(forGroupID:));

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_COMPOSITE_BEHAVIOR__ */
