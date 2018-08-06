//
//  SMPromotion.h
//  SessionMCampaignsKit
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SM_PROMOTION__
#define __SM_PROMOTION__

#import <Foundation/Foundation.h>
#import <SessionMEventsKit/SMBehavior.h>

#import "SMCampaign.h"
#import "SMTemplate.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMPromotion
 @abstract Defines the data associated with a promotional message.
 @discussion Note: the developer can configure the following properties for each message through the SessionM Platform portal.
 */
@interface SMPromotion : SMCampaign
/*!
 @property behaviors
 @abstract Action items the user can perform to participate in the campaign.
 */
@property(nullable, nonatomic, strong, readonly) NSDictionary<NSString *, SMBehavior *> *behaviors;
/*!
 @property template
 @abstract Provides the data necessary for presenting UI for the promotion.
 */
@property(nonatomic, strong, readonly) SMPromotionTemplate *template;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_PROMOTION__ */
