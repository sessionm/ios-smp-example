//
//  SMTemplate.h
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef __SM_TEMPLATE__
#define __SM_TEMPLATE__

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMTemplate
 @abstract Provides the data necessary for presenting UI for a campaign message.
 */
@interface SMTemplate : NSObject

/*!
 @property type
 @abstract Message type.
 */
@property(nonatomic, strong, readonly) NSString *type;
/*!
 @property extras
 @abstract Any data values that do not have an associated class property.
 */
@property(nullable, nonatomic, strong, readonly) NSDictionary<NSString *, NSObject *> *extras;

@end


@class SMTemplateMessage;
@class SMTemplateAction;

/*!
 @class SMFeedTemplate
 @abstract Provides the data necessary for presenting UI for a feed message.
 @discussion Note: the developer can configure the following properties for each message through the SessionM Platform portal.
 */
@interface SMFeedTemplate : SMTemplate

/*!
 @property message
 @abstract The ad URL for the current user.
 */
@property(nonatomic, strong, readonly) SMTemplateMessage *message;
/*!
 @property action
 @abstract The ad URL for the current user.
 */
@property(nonatomic, strong, readonly) SMTemplateAction *action;
/*!
 @property data
 @abstract Custom, developer-defined data associated with the messsage.
 */
@property(nullable, nonatomic, strong, readonly) NSObject *data;

@end


/*!
 @class SMPromotionTemplate
 @abstract Provides the data necessary for presenting UI for a promotion.
 @discussion Note: the developer can configure the following properties for each message through the SessionM Platform portal.
 */
@interface SMPromotionTemplate : SMTemplate

/*!
 @property htmlPayload
 @abstract The ad URL for the current user.
 */
@property(nullable, nonatomic, strong, readonly) NSString *htmlPayload;

@end


/*!
 @class SMTemplateMessage
 @abstract Contains feed message text and layout configuration data.
 @discussion Note: the developer can configure the following properties for each message through the SessionM Platform portal.
 */
@interface SMTemplateMessage : NSObject

/*!
 @property header
 @abstract Message title.
 */
@property(nonatomic, strong, readonly) NSString *header;
/*!
 @property subheader
 @abstract Message subtitle.
 @discussion Identical to @link callToAction @/link.
 */
@property(nullable, nonatomic, strong, readonly) NSString *subheader;
/*!
 @property descriptionText
 @abstract Message text.
 @deprecated This property has been deprecated - use @link details @/link instead.
 */
@property(nonatomic, strong, readonly) NSString *descriptionText __attribute__((deprecated));
/*!
 @property details
 @abstract Message text.
 */
@property(nonatomic, strong, readonly) NSString *details;
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
 @property callToAction
 @abstract Message subtitle.
 @discussion Identical to @link subheader @/link.
 */
@property(nullable, nonatomic, strong, readonly) NSString *callToAction;
/*!
 @property extras
 @abstract Any data values that do not have an associated class property.
 */
@property(nullable, nonatomic, strong, readonly) NSDictionary<NSString *, NSObject *> *extras;

@end


@class SMEventMetaData;

/*!
 @class SMTemplateAction
 @abstract Contains feed message action configuration data.
 @discussion Note: the developer can configure the following properties for each message through the SessionM Platform portal.
 */
@interface SMTemplateAction : NSObject

/*!
 @property type
 @abstract Determines how the content pointed to by @link url @/link is displayed when @link //apple_ref/occ/instm/SMCampaignsManager/executeMessageAction: @/link is called with the corresponding //apple_ref/occ/cl/SMFeedMessage @/link instance.
 */
@property(nullable, nonatomic, strong, readonly) NSString *type;
/*!
 @property url
 @abstract URL for content that is displayed when @link //apple_ref/occ/instm/SMCampaignsManager/executeMessageAction: @/link is called with the corresponding //apple_ref/occ/cl/SMFeedMessage @/link instance.
 */
@property(nullable, nonatomic, strong, readonly) NSString *url;
/*!
 @property trackingURLs
 @abstract URLs used to track an action associated with the message.
 */
@property(nullable, nonatomic, strong, readonly) NSArray<NSString *> *trackingURLs;
/*!
 @property eventMetaData
 @abstract Metadata associated with the message.
 */
@property(nullable, nonatomic, strong, readonly) SMEventMetaData *eventMetaData;
/*!
 @property extras
 @abstract Any data values that do not have an associated class property.
 */
@property(nullable, nonatomic, strong, readonly) NSDictionary<NSString *, NSObject *> *extras;

@end


/*!
 @class SMEventMetaData
 @abstract Metadata associated with a feed message.
 */
@interface SMEventMetaData : NSObject

/*!
 @property adUnitID
 @abstract Ad unit identifier.
 */
@property(nullable, nonatomic, strong, readonly) NSString *adUnitID;
/*!
 @property adStatID
 @abstract Ad stat identifier.
 */
@property(nullable, nonatomic, strong, readonly) NSString *adStatID;
/*!
 @property extras
 @abstract Any data values that do not have an associated class property.
 */
@property(nullable, nonatomic, strong, readonly) NSDictionary<NSString *, NSObject *> *extras;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_TEMPLATE__ */
