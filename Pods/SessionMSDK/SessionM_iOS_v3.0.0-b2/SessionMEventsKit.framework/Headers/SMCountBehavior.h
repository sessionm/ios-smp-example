//
//  SMCountBehavior.h
//  SessionMEventsKit
//
//  Copyright © 2018 SessionM. All rights reserved.
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
 @abstract Maximum number of times a user is allowed to complete the behavior in the time interval specified by <code>period</code>.
 @discussion A value of <code>-1</code> indicates that there is no maximum.
 */
@property(nonatomic, assign, readonly) NSInteger maxTimesRepeatablePerPeriod;
/*!
 @property period
 @abstract Defines the time interval (in seconds) that applies to <code>maxTimesRepeatablePerPeriod</code>.
 */
@property(nonatomic, assign, readonly) NSTimeInterval period;
/*!
 @property minTimeBetweenEvents
 @abstract Minimum amount of time a user is required to wait between attempts.
 @discussion A value of <code>-1</code> indicates that there is no minimum.
 */
@property(nonatomic, assign, readonly) NSInteger minTimeBetweenEvents;
/*!
 @property consecutive
 @abstract Requires that event must happen on consecutive days.
 */
@property(nonatomic, assign, readonly) BOOL consecutive;
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
