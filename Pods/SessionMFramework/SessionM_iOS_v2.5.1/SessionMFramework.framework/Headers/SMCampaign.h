//
//  SMCampaign.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef __SM_CAMPAIGN__
#define __SM_CAMPAIGN__

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMCampaign
 @abstract Defines the data associated with a campaign message.
 @discussion Note: the developer can configure the following properties for each message through the SessionM Platform portal.
 */
@interface SMCampaign : NSObject

/*!
 @property messageID
 @abstract Unique identifier for message.
 @discussion Identical to @link creativeID @/link.
 */
@property(nonatomic, strong, readonly) NSString *messageID;
/*!
 @property permalink
 @abstract Developer-defined string that can be used to reference the campaign.
 */
@property(nonatomic, strong, readonly) NSString *permalink;
/*!
 @property campaignID
 @abstract Identifier of campaign associated with the message.
 */
@property(nonatomic, strong, readonly) NSString *campaignID;
/*!
 @property creativeID
 @abstract Unique identifier for campaign creative.
 @discussion Identical to @link messageID @/link.
 */
@property(nonatomic, strong, readonly) NSString *creativeID;
/*!
 @property groupID
 @abstract Identifier of ad group that contains the campaign.
 */
@property(nullable, nonatomic, strong, readonly) NSString *groupID;

/*!
 @property name
 @abstract Campaign name.
 */
@property(nonatomic, strong, readonly) NSString *name;

/*!
 @property startTime
 @abstract Indicates when the campaign began.
 */
@property(nullable, nonatomic, strong, readonly) NSString *startTime;
/*!
 @property endTime
 @abstract Indicates when the campaign ends.
 */
@property(nullable, nonatomic, strong, readonly) NSString *endTime;

/*!
 @property version
 @abstract SessionM Platform Campaigns API version.
 */
@property(nullable, strong, nonatomic, readonly) NSNumber *version;
/*!
 @property type
 @abstract Message type.
 */
@property(nonatomic, strong, readonly) NSString *type;

/*!
 @property optInStartsAt
 @abstract Indicates when opt-in for the campaign began.
 */
@property(nullable, nonatomic, strong, readonly) NSString *optInStartsAt;
/*!
 @property optInEndsAt
 @abstract Indicates when opt-in for the campaign ends.
 */
@property(nullable, nonatomic, strong, readonly) NSString *optInEndsAt;

/*!
 @property extras
 @abstract Any data values that do not have an associated class property.
 */
@property(nullable, nonatomic, strong, readonly) NSDictionary<NSString *, NSObject *> *extras;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_CAMPAIGN__ */
