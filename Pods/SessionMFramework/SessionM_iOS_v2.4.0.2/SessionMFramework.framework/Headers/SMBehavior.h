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

/*!
 @typedef SMBehaviorType
 @abstract Behavior type.

 @constant SMBehaviorTypeUnknown Behavior type is unknown.
 @constant SMBehaviorTypeComposite Behavior that is made up of other count and unique behaviors.
 @constant SMBehaviorTypeCount Simple behavior associated with a campaign or incentive.
 @constant SMBehaviorTypeUnique Behavior associated with a campaign or incentive that tracks unique actions that the user has made.
 */
typedef NS_ENUM (NSInteger, SMBehaviorType) {
    SMBehaviorTypeUnknown NS_SWIFT_NAME(unknown),
    SMBehaviorTypeComposite NS_SWIFT_NAME(composite),
    SMBehaviorTypeCount NS_SWIFT_NAME(count),
    SMBehaviorTypeUnique NS_SWIFT_NAME(unique)
};

/*!
 @class SMBehavior
 @abstract Defines the data associated with an action item that the user can perform to participate in application-specific campaigns and incentives.
 */
@interface SMBehavior : NSObject

/*!
 @property type
 @abstract Behavior type.
 */
@property(nonatomic, assign, readonly) SMBehaviorType type;
/*!
 @property extras
 @abstract Any data values that do not have an associated class property.
 */
@property(nullable, nonatomic, strong, readonly) NSDictionary<NSString *, NSObject *> *extras;

/*!
 @abstract Converts specified string value to the corresponding @link SMBehaviorType @/link enum value.
 @param string String to convert.
 @result @link SMBehaviorType @/link enum value.
 */
+ (SMBehaviorType)typeForString:(NSString *)string NS_SWIFT_NAME(behaviorType(from:));
/*!
 @abstract Converts specified @link SMBehaviorType @/link enum value to the corresponding string value.
 @param type Type to convert.
 @result <code>NSString</code> value.
 */
+ (NSString *)stringForType:(SMBehaviorType)type NS_SWIFT_NAME(string(from:));

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_BEHAVIOR__ */
