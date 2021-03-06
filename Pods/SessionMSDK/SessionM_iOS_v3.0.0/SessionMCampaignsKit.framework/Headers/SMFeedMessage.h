//
//  SMFeedMessage.h
//  SessionMCampaignsKit
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SM_FEED_MESSAGE__
#define __SM_FEED_MESSAGE__

#import <Foundation/Foundation.h>

#import "SMCampaign.h"
#import "SMTemplate.h"

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
@interface SMFeedMessage : SMCampaign

/*!
 @property eventMetaData
 @abstract Metadata associated with the message.
 @discussion Identical to <code>payloads</code>.
 */
@property(nonatomic, strong, readonly) NSDictionary<NSString *, id> *eventMetaData;
/*!
 @property payloads
 @abstract Metadata associated with the message.
 @discussion Identical to <code>eventMetaData</code>.
 */
@property(nonatomic, strong, readonly) NSDictionary<NSString *, id> *payloads;
/*!
 @property actionType
 @abstract Determines how the content pointed to by <code>actionURL</code> is displayed when <code>SMCampaignsManager executeMessageAction:</code> is called with an instance of this class.
 */
@property(nonatomic, assign, readonly) SMMessageActionType actionType;
/*!
 @property actionURL
 @abstract URL for content that is displayed when <code>SMCampaignsManager executeMessageAction:</code> is called with an instance of this class.
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
 @property details
 @abstract Message text.
 */
@property(nonatomic, strong, readonly) NSString *details;
/*!
 @property descriptionText
 @abstract Message text.
 @deprecated This property has been deprecated - use <code>details</code> instead.
 */
@property(nonatomic, strong, readonly) NSString *descriptionText __attribute__((deprecated));
/*!
 @property iconURL
 @abstract URL for feed message icon.
 */
@property(nullable, nonatomic, strong, readonly) NSString *iconURL;
/*!
 @property imageURL
 @abstract URL for optional feed message banner image.
 */
@property(nullable, nonatomic, strong, readonly) NSString *imageURL;
/*!
 @property videoURL
 @abstract URL for optional video content.
 */
@property(nullable, nonatomic, strong, readonly) NSString *videoURL;
/*!
 @property points
 @abstract The amount of points that use can earn by interacting with the message.
 */
@property(nonatomic, assign, readonly) NSInteger points;
/*!
 @property template
 @abstract Provides the data necessary for presenting UI for the feed message.
 */
@property(nonatomic, strong, readonly) SMFeedTemplate *template;

/*!
 @property data
 @abstract Custom, developer-defined data associated with the messsage.
 */
@property(nullable, nonatomic, strong, readonly) id data;

/*!
 @property trackingURLs
 @abstract URLs used to track an action associated with the message.
 */
@property(nullable, nonatomic, strong, readonly) NSArray<NSString *> *trackingURLs;

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
 @abstract Converts specified string value to the corresponding <code>SMMessageActionType</code> enum value.
 @param string String to convert.
 @result <code>SMMessageActionType</code> enum value.
 */
+ (SMMessageActionType)typeForString:(NSString *)string NS_SWIFT_NAME(actionType(from:));
/*!
 @abstract Converts specified <code>SMMessageActionType</code> enum value to the corresponding string value.
 @param type Type to convert.
 @result <code>NSString</code> value.
 */
+ (NSString *)stringForType:(SMMessageActionType)type NS_SWIFT_NAME(string(from:));

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_FEED_MESSAGE__ */
