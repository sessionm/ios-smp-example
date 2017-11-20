//
//  SMActivityEventBuilder.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef __SM_ACTIVITY_EVENT_BUILDER__
#define __SM_ACTIVITY_EVENT_BUILDER__

#import "SMEventBuilder.h"
#import "SMActivityEvent.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMActivityEventBuilder
 @abstract Class used for building @link SMActivityEvent @/link objects that represent a basic activity event performed by the user to make progress towards completing an application-specific campaign.
 */
@interface SMActivityEventBuilder : SMEventBuilder

/*!
 @abstract Generates an activity event based on the builder's current configuration.
 @result The generated @link SMActivityEvent @/link object.
 */
- (SMActivityEvent *)build;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_ACTIVITY_EVENT_BUILDER__ */
