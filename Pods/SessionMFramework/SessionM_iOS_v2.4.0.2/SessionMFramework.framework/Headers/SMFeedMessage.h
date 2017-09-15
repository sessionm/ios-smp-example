//
//  SMFeedMessage.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef __SM_FEED_MESSAGE__
#define __SM_FEED_MESSAGE__

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @typedef SMMessageActionType
 @abstract Determines how message content is displayed.

 @constant SMMessageActionTypeUnknown Unknown action type.
 @constant SMMessageActionTypeDeepLink Deep links into app.
 @constant SMMessageActionTypeFullScreen Presents full screen rich media message.
 @constant SMMessageActionTypeExternalLink Opens link in Safari.
 */
typedef NS_ENUM(NSInteger, SMMessageActionType) {
    SMMessageActionTypeUnknown NS_SWIFT_NAME(unknown),
    SMMessageActionTypeDeepLink NS_SWIFT_NAME(deepLink),
    SMMessageActionTypeFullScreen NS_SWIFT_NAME(fullScreen),
    SMMessageActionTypeExternalLink NS_SWIFT_NAME(externalLink)
};

/*!
 @class SMFeedMessage
 @abstract Defines the data associated with an activity feed message.
 @discussion Note: the developer can configure the following properties for each message through the SessionM Platform portal.
 */
@interface SMFeedMessage : NSObject

/*!
 @property messageID
 @abstract Unique ID for message.
 */
@property(nonatomic, strong, readonly) NSString *messageID;
/*!
 @property campaignID
 @abstract ID of promotional campaign associated with the message.
 */
@property(nonatomic, strong, readonly) NSString *campaignID;
/*!
 @property startTime
 @abstract Indicates when the promotion began.
 */
@property(nullable, nonatomic, strong, readonly) NSString *startTime;
/*!
 @property endTime
 @abstract Indicates when the promotion ends.
 */
@property(nullable, nonatomic, strong, readonly) NSString *endTime;
/*!
 @property type
 @abstract Message type.
 */
@property(nonatomic, strong, readonly) NSString *type;
/*!
 @property eventMetaData
 @abstract Metadata associated with the message from the @link //apple_ref/occ/instm/SessionM/logAction:withCount:payloads: @/link method.
 */
@property(nonatomic, strong, readonly) NSDictionary<NSString *, NSObject *> *eventMetaData;
/*!
 @property actionType
 @abstract Determines how the content pointed to by @link actionURL @/link is displayed when @link //apple_ref/occ/instm/SMCampaignsManager/executeMessageAction: @/link is called with an instance of this class.
 */
@property(nonatomic, assign, readonly) SMMessageActionType actionType;
/*!
 @property actionURL
 @abstract URL for content that is displayed when @link //apple_ref/occ/instm/SMCampaignsManager/executeMessageAction: @/link is called with an instance of this class.
 */
@property(nullable, nonatomic, strong, readonly) NSString *actionURL;
/*!
 @property header
 @abstract Message title.
 */
@property(nonatomic, strong, readonly) NSString *header;
/*!
 @property subheader
 @abstract Message subtitle.
 */
@property(nullable, nonatomic, strong, readonly) NSString *subheader;
/*!
 @property descriptionText
 @abstract Message text.
 */
@property(nonatomic, strong, readonly) NSString *descriptionText;
/*!
 @property iconURL
 @abstract URL for icon displayed in @link //apple_ref/occ/cl/SMActivityFeedViewCell @/link instance.
 */
@property(nullable, nonatomic, strong, readonly) NSString *iconURL;
/*!
 @property imageURL
 @abstract URL for optional banner image displayed at bottom of @link //apple_ref/occ/cl/SMActivityFeedViewCell @/link instance.
 */
@property(nullable, nonatomic, strong, readonly) NSString *imageURL;
/*!
 @property videoURL
 @abstract URL for optional video content.
 */
@property(nullable, nonatomic, strong, readonly) NSString *videoURL;
/*!
 @property data
 @abstract Custom, developer-defined data associated with the messsage.
 */
@property(nullable, nonatomic, strong, readonly) NSDictionary<NSString *, NSObject *> *data;
/*!
 @property points
 @abstract The amount of points that use can earn by interacting with the message.
 */
@property(nonatomic, assign, readonly) NSInteger points;
/*!
 @property extras
 @abstract Any data values that do not have an associated class property.
 */
@property(nullable, nonatomic, strong, readonly) NSDictionary<NSString *, NSObject *> *extras;

/*!
 @abstract Notifies the SDK that the view containing the associated message data was presented to the user. Used for reporting purposes.
 */
- (void)notifyPresented;
/*!
 @abstract Notifies the SDK that the view containing the associated message data was seen by the user. Used for reporting purposes.
 */
- (void)notifySeen;
/*!
 @abstract Notifies the SDK that the user tapped on the view containing the associated message data. Used for reporting purposes.
 */
- (void)notifyTapped;

/*!
 @abstract Converts specified string value to the corresponding @link SMMessageActionType @/link enum value.
 @param string String to convert.
 @result @link SMMessageActionType @/link enum value.
 */
+ (SMMessageActionType)typeForString:(NSString *)string NS_SWIFT_NAME(actionType(from:));
/*!
 @abstract Converts specified @link SMMessageActionType @/link enum value to the corresponding string value.
 @param type Type to convert.
 @result <code>NSString</code> value.
 */
+ (NSString *)stringForType:(SMMessageActionType)type NS_SWIFT_NAME(string(from:));

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_FEED_MESSAGE__ */
