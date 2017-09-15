//
//  SMUniqueBehavior.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef __SM_UNIQUE_BEHAVIOR__
#define __SM_UNIQUE_BEHAVIOR__

#import "SMProgressBehavior.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMUniqueBehavior
 @abstract Defines the data associated with an action item associated with a campaign or incentive that tracks unique actions that the user has made.
 */
@interface SMUniqueBehavior : SMProgressBehavior

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
 @property currentCount
 @abstract Number of unique events that have been logged towards completing the behavior.
 */
@property(nonatomic, assign, readonly) NSInteger currentCount;
/*!
 @property totalCount
 @abstract Total number of unique events that need to be logged before the behavior is completed.
 */
@property(nonatomic, assign, readonly) NSInteger totalCount;
/*!
 @property completedUniques
 @abstract Names of the events that the user has already logged.
 @discussion Note: this array is emptied when the behavior is completed and @link achieved @/link is incremented.
 */
@property(nonatomic, strong, readonly) NSArray<NSString *> *completedUniques;
/*!
 @property data
 @abstract Additional data associated with the behavior.
 */
@property(nullable, nonatomic, strong, readonly) id data;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_UNIQUE_BEHAVIOR__ */
