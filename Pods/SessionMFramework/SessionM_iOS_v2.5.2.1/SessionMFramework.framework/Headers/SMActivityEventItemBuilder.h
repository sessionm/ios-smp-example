//
//  SMActivityEventItemBuilder.h
//  SessionM
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SM_ACTIVITY_EVENT_ITEM_BUILDER__
#define __SM_ACTIVITY_EVENT_ITEM_BUILDER__

#import "SMEventItemBuilder.h"
#import "SMActivityEventItem.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMActivityEventItemBuilder
 @abstract Class used for building @link SMActivityEventItem @/link objects that represent the data associated with a single instance of a triggered activity event.
 */
@interface SMActivityEventItemBuilder : SMEventItemBuilder

/*!
 @abstract Generates an activity event based on the builder's current configuration.
 @result The generated @link SMActivityEventItem @/link object.
 */
- (SMActivityEventItem *)build;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_ACTIVITY_EVENT_ITEM_BUILDER__ */
