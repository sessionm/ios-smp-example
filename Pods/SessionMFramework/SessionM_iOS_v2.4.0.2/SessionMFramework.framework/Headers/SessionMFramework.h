//
//  SessionMFramework.h
//  SessionMFramework
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef __SESSIONM_FRAMEWORK__
#define __SESSIONM_FRAMEWORK__

// System Frameworks
#import <AdSupport/AdSupport.h>
#import <AVFoundation/AVFoundation.h>
#import <CoreData/CoreData.h>
#import <CoreGraphics/CoreGraphics.h>
#import <CoreLocation/CoreLocation.h>
#import <CoreMedia/CoreMedia.h>
#import <EventKit/EventKit.h>
#import <EventKitUI/EventKitUI.h>
#import <Foundation/Foundation.h>
#import <ImageIO/ImageIO.h>
#import <Security/Security.h>
#import <StoreKit/StoreKit.h>
#import <SystemConfiguration/SystemConfiguration.h>
#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>

// General mPLUS Rewards
#import "SessionM.h"
#import "SMAchievementData.h"
#import "SMActivityViewController.h"
#import "SMLoaderController.h"
#import "SMLocationEvent.h"
#import "SMLocationManager.h"

// General SessionM Platform
#import "SMAddress.h"
#import "SMBaseDelegate.h"
#import "SMError.h"

// Campaigns
#import "SMCampaignsManager.h"
#import "SMFeedMessage.h"

// Content
#import "SMContent.h"
#import "SMContentManager.h"

// Events
#import "SMActivityEvent.h"
#import "SMActivityEventBuilder.h"
#import "SMActivityEventItem.h"
#import "SMActivityEventItemBuilder.h"
#import "SMBehavior.h"
#import "SMBehaviorProgressFetchedResponse.h"
#import "SMCompositeBehavior.h"
#import "SMCountBehavior.h"
#import "SMEvent.h"
#import "SMEventBuilder.h"
#import "SMEventItem.h"
#import "SMEventItemBuilder.h"
#import "SMEventNotification.h"
#import "SMEventPostedResponse.h"
#import "SMEventsManager.h"
#import "SMEventsResponse.h"
#import "SMGoal.h"
#import "SMGroup.h"
#import "SMProgressBehavior.h"
#import "SMPurchaseEvent.h"
#import "SMPurchaseEventBuilder.h"
#import "SMPurchaseEventItem.h"
#import "SMPurchaseEventItemBuilder.h"
#import "SMSimpleEventBuilder.h"
#import "SMUniqueBehavior.h"

// Generic Requests
#import "SMGenericRequest.h"
#import "SMGenericResponse.h"
#import "SMGenericRequestBuilder.h"
#import "SMGenericRequestManager.h"

// Identity
#import "SMIdentityManager.h"
#import "SMPUser.h"
#import "SMPUserCreate.h"
#import "SMPUserUpdate.h"
#import "SMSVerification.h"
#import "SMSVerificationManager.h"
#import "SMUserManager.h"
#import "SMUserTagsManager.h"
#import "SMWebProfileManager.h"

// Inbox
#import "SMInboxManager.h"
#import "SMInboxMessage.h"

// Loyalty Card Linking
#import "SMLoyaltyCard.h"
#import "SMLoyaltyCardsManager.h"
#import "SMLoyaltyCardTransaction.h"
#import "SMRetailer.h"

// Messages
#import "SMMessagesManager.h"
#import "SMNotificationMessage.h"

// Offers
#import "SMClaimedOfferItem.h"
#import "SMClaimUserOfferResponse.h"
#import "SMFetchStoreOffersResponse.h"
#import "SMFetchUserOffersResponse.h"
#import "SMOfferCategory.h"
#import "SMOfferGroup.h"
#import "SMOfferItem.h"
#import "SMOfferMedia.h"
#import "SMOfferResponse.h"
#import "SMOffersManager.h"
#import "SMPurchaseOfferResponse.h"
#import "SMStoreOfferItem.h"
#import "SMUserOfferItem.h"

// Places
#import "SMPlace.h"
#import "SMPlaceCheckinResult.h"
#import "SMPlacesManager.h"

// Receipts
#import "SMReceipt.h"
#import "SMReceiptsManager.h"

// Referrals
#import "SMReferral.h"
#import "SMReferralError.h"
#import "SMReferralRequest.h"
#import "SMReferralsManager.h"

// Rewards
#import "SMOffer.h"
#import "SMOrder.h"
#import "SMRewardsManager.h"
#import "SMSkillChallenge.h"
#import "SMSkillQuestion.h"

// Transactions
#import "SMTransaction.h"
#import "SMTransactionsManager.h"

// Web View
#import "SMJSBridgeHandling.h"
#import "SMWebView.h"

#endif /* __SESSIONM_FRAMEWORK__ */
