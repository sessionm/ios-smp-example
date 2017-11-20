//
//  SMPurchaseEvent.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef __SM_PURCHASE_EVENT__
#define __SM_PURCHASE_EVENT__

#import "SMEvent.h"
#import "SMPurchaseEventItem.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMPurchaseEvent
 @abstract Defines the data associated with an event performed by the user that contains purchase metadata such as product SKUs.
 */
@interface SMPurchaseEvent : SMEvent

/*!
 @property items
 @abstract A list of separate instances of the event.
 */
@property(nonatomic, strong, readonly) NSArray<SMPurchaseEventItem *> *items;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_PURCHASE_EVENT__ */
