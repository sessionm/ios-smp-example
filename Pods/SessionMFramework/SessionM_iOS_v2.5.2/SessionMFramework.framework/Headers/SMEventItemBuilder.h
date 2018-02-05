//
//  SMEventItemBuilder.h
//  SessionM
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SM_EVENT_ITEM_BUILDER__
#define __SM_EVENT_ITEM_BUILDER__

#import "SMEventItem.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMEventItemBuilder
 @abstract Class used for building @link SMEventItem @/link objects that represent the data associated with a single instance of a triggered event.
 */
@interface SMEventItemBuilder : NSObject

/*!
 @abstract Returns an event item builder.
 @result <code>SMEventItemBuilder</code> instance.
 */
+ (instancetype)builder;

/*!
 @abstract Generates an event based on the builder's current configuration.
 @result The generated @link SMEventItem @/link object.
 */
- (SMEventItem *)build;

/*!
 @abstract Sets a customer-defined key-value pair to be sent along with any generated events when posting to the SessionM Platform.
 @param value Value for specified key (a value of <code>nil</code> will remove <code>key</code> from the event data).
 @param key Customer-defined key.
 @discussion See @link //apple_ref/occ/instp/SMEventItem/additionalData @/link for more information.
 */
- (void)setAttribute:(id _Nullable)value forKey:(NSString *)key NS_SWIFT_NAME(setAttribute(value:forKey:));

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_EVENT_ITEM_BUILDER__ */
