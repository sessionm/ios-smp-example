//
//  SMProgress.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//
//

#ifndef __SM_PROGRESS__
#define __SM_PROGRESS__

#import <Foundation/Foundation.h>
#import "SMBehavior.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @typedef SMProgressState
 @abstract Determines Progress.

 @constant SMProgressStateUnknown Unknown action type.
 @constant SMProgressStateCompleted Progress completed.
 @constant SMProgressStateInProgress Progress in-progress.
 @constant SMProgressStateOptedIn Opted In.
 @constant SMProgressStateOptedOut Opted Out.
 @constant SMProgressStateQualified Progress qualified for progress.
 @constant SMProgressStateNotQualified Progress not qualified.
 */
typedef NS_ENUM(NSUInteger, SMProgressState) {
    SMProgressStateUnknown NS_SWIFT_NAME(unknown),
    SMProgressStateCompleted NS_SWIFT_NAME(completed),
    SMProgressStateInProgress NS_SWIFT_NAME(inProgress),
    SMProgressStateOptedIn NS_SWIFT_NAME(optedIn),
    SMProgressStateOptedOut NS_SWIFT_NAME(optedOut),
    SMProgressStateQualified NS_SWIFT_NAME(qualified),
    SMProgressStateNotQualified NS_SWIFT_NAME(notQualified)
};

@interface SMProgress : NSObject
/*!
 @property state
 @abstract The users’ current status for this campaign @link SMProgressState @/link.
 */
@property(nonatomic, assign, readonly)SMProgressState state;
/*!
 @property isOptedIn
 @abstract Is Opted In for message.
 */
@property(nonatomic, assign, readonly)BOOL isOptedIn;
/*!
 @property behaviors
 @abstract List of @link SMBehavior /@link for message.
 */
@property(nonatomic, strong, readonly)NSArray<SMBehavior *> *behaviors;

/*!
 @abstract Converts string value to type value @link SMProgressState @/link enum.
 @param type String to convert.
 @result @link SMProgressState @/link enum value.
 */
+(SMProgressState)typeForString:(NSString *)type NS_SWIFT_NAME(progressState(from:));
/*!
 @abstract Converts value of the corresponding @link SMProgressState @/link to a string.
 @param state Type to convert.
 @result String value.
 */
+(NSString *)stringForType:(SMProgressState)state NS_SWIFT_NAME(string(from:));

@end

NS_ASSUME_NONNULL_END

#endif
