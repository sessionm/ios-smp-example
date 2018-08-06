//
//  SMEventItem.h
//  SessionMEventsKit
//
//  Copyright © 2018 SessionM. All rights reserved.
//


#ifndef __SM_EVENT_ITEM__
#define __SM_EVENT_ITEM__

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMEventItem
 @abstract Defines the data associated with a single instance of a triggered event.
 */
@interface SMEventItem : NSObject

/*!
 @property additionalData
 @abstract Customer-defined data that will be sent along with the event when posting to the SessionM Platform.
 @discussion See <code>SMEventItemBuilder setAttribute:forKey:</code> for more information.
 */
@property(nonatomic, strong, readonly) NSDictionary<NSString *, id> *additionalData;

/*!
 @abstract Returns event item data in a dictionary format.
 @result <code>NSDictionary</code> representation of event data.
 */
- (NSDictionary<NSString *, id> *)asDictionary;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_EVENT_ITEM__ */
