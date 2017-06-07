//
//  SMMessageView.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef __SM_MESSAGE_VIEW__
#define __SM_MESSAGE_VIEW__

#import <UIKit/UIKit.h>
#import "SMMessage.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMMessageView
 @abstract Stores message data for presentation and provides methods for notifying the SDK that a message view was presented or tapped.
 @discussion A developer can inherit from this class to display messages with their own custom UI. A standard implementation is also provided in @link //apple_ref/occ/cl/SMDefaultMessageView @/link.
 */
@interface SMMessageView : UIView

/*!
 @property message
 @abstract The message data that will be presented.
 */
@property(nonatomic, strong, readonly) SMMessage *message;

/*!
 @abstract Initializes a view with the given message data.
 @discussion Sets @link //apple_ref/occ/instp/SMMessageView/message @/link to the given instance of @link SMMessage @/link. Messages can be accessed from the @link //apple_ref/occ/instp/SMCampaignsManager/feedMessages @/link property.
 @param message The data representing the message that will be presented.
 @result <code>SMMessageView</code> instance (result will be nil if <code>data</code> is nil).
 */
- (instancetype)initWithMessage:(SMMessage *)message NS_SWIFT_NAME(init(message:));
/*!
 @abstract Notifies the SDK that the message was presented.
 @discussion If you are inheriting from this class to use a custom presentation, be sure to call this method after the message view is presented.
 */
- (void)notifyPresented;
/*!
 @abstract Notifies the SDK that the message was tapped.
 @discussion If you are inheriting from this class to use a custom presentation, be sure to call this method after the message view is tapped.
 */
- (void)notifyTapped;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_MESSAGE_VIEW__ */
