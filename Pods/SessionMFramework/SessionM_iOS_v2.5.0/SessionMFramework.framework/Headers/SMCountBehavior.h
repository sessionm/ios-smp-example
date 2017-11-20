//
//  SMCountBehavior.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef __SM_COUNT_BEHAVIOR__
#define __SM_COUNT_BEHAVIOR__

#import "SMProgressBehavior.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMCountBehavior
 @abstract Defines the data associated with a simple action item associated with a campaign or incentive.
 */
@interface SMCountBehavior : SMProgressBehavior

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
 @property eventName
 @abstract Name of the event associated with the behavior.
 */
@property(nonatomic, strong, readonly) NSString *eventName;
/*!
 @property currentCount
 @abstract Current number of events logged towards completing the behavior.
 */
@property(nonatomic, assign, readonly) NSInteger currentCount;
/*!
 @property totalCount
 @abstract Total number of events that need to be logged before the behavior is completed.
 */
@property(nonatomic, assign, readonly) NSInteger totalCount;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_COUNT_BEHAVIOR__ */
