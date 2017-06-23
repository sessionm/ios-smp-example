//
//  SMDefaultMessageView.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef __SM_DEFAULT_MESSAGE_VIEW__
#define __SM_DEFAULT_MESSAGE_VIEW__

#import "SMMessageView.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMDefaultMessageView
 @abstract Standard implementation of @link SMMessageView @/link.
 @discussion This class offers a standard implementation for presenting messages. In addition, it automatically notifies the SDK when a message view is presented or tapped.
 */
@interface SMDefaultMessageView : SMMessageView

/*!
 @property headerLabel
 @abstract Displays the header text for the associated message.
 @discussion Will be initialized to the @link //apple_ref/occ/instp/SMMessage/header @/link property of the associated @link SMMessage @/link instance.
 */
@property(nonatomic, strong, readonly) UILabel *headerLabel;
/*!
 @property descriptionLabel
 @abstract Displays the description text for the associated message.
 @discussion Will be initialized to the @link //apple_ref/occ/instp/SMMessage/descriptionText @/link property of the associated @link SMMessage @/link instance.
 */
@property(nonatomic, strong, readonly) UILabel *descriptionLabel;
/*!
 @property dismissButton
 @abstract Calls @link dismiss @/link when tapped.
 */
@property(nonatomic, strong, readonly) UIButton *dismissButton;

/*!
 @abstract Presents the message and notifies the SDK of the presentation.
 @discussion Message view is presented as a pop-up that includes the app icon, a dismiss button and the message header and text.
 */
- (void)present;
/*!
 @abstract Dismisses the message.
 @discussion Message view can be dismissed manually by tapping the dismiss button, or programmatically by calling this method. In addition, this method is automatically called if the user does not interact with the message view in a set amount of time.
 */
- (void)dismiss;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_DEFAULT_MESSAGE_VIEW__ */
