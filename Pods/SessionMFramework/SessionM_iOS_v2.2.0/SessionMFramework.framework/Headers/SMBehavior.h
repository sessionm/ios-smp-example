//
//  SMBehavior.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef __SM_BEHAVIOR__
#define __SM_BEHAVIOR__

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SMBehavior : NSObject
/*!
 @property behaviorID
 @abstract Internal SessionM ID.
 */
@property(nonatomic, strong, readonly)NSString *behaviorID;
/*!
 @property eventName
 @abstract Name of the event.
 */
@property(nonatomic, strong, readonly)NSString *eventName;
/*!
 @property name
 @abstract External name.
 */
@property(nonatomic, strong, readonly)NSString *name;
/*!
 @property progress
 @abstract How far along if it requires multiple steps.
 */
@property(nonatomic, assign, readonly)NSInteger progress;
/*!
 @property goal
 @abstract Amount to achieve to earn the behavior.
 */
@property(nonatomic, assign, readonly)NSInteger goal;

@end

NS_ASSUME_NONNULL_END

#endif