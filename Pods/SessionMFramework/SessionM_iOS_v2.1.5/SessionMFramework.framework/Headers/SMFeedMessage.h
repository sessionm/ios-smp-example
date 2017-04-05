//
//  SMFeedMessage.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef __SM_FEED_MESSAGE__
#define __SM_FEED_MESSAGE__

#import <UIKit/UIKit.h>
#import "SMMessage.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMFeedMessage
 @abstract Defines the data associated with an activity feed message.
 @discussion Note: the developer can configure the following properties for each message through the SessionM Mobile Marketing Cloud portal. The @link //apple_ref/occ/cl/SMActivityFeedViewCell @/link and @link //apple_ref/occ/cl/SMActivityFeedViewController @/link classes are provided as out-of-the-box implementations for presenting feed messages inside an activity feed. The @link //apple_ref/occ/cl/SMDefaultMessageView @/link class is provided for presenting outside an activity feed.
 */
@interface SMFeedMessage : SMMessage

/*!
 @property iconURL
 @abstract URL for icon displayed in @link //apple_ref/occ/cl/SMActivityFeedViewCell @/link instance.
 */
@property(nullable, nonatomic, copy, readonly) NSString *iconURL;
/*!
 @property imageURL
 @abstract URL for optional banner image displayed at bottom of @link //apple_ref/occ/cl/SMActivityFeedViewCell @/link instance.
 */
@property(nullable, nonatomic, copy, readonly) NSString *imageURL;
/*!
 @property videoURL
 @abstract URL for optional video content.
 */
@property(nullable, nonatomic, copy, readonly) NSString *videoURL;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_FEED_MESSAGE__ */
