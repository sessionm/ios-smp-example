//
//  SessionMEventsKit.h
//  SessionMEventsKit
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SESSIONM_EVENTS_KIT__
#define __SESSIONM_EVENTS_KIT__

// SessionM Platform
#import <SessionMCoreKit/SessionMCoreKit.h>
#import <SessionMIdentityKit/SessionMIdentityKit.h>

// Behaviors
#import "SMBehavior.h"
#import "SMCompositeBehavior.h"
#import "SMCountBehavior.h"
#import "SMGoal.h"
#import "SMGroup.h"
#import "SMProgressBehavior.h"
#import "SMUniqueBehavior.h"

// Events
#import "SMActivityEvent.h"
#import "SMActivityEventBuilder.h"
#import "SMActivityEventItem.h"
#import "SMActivityEventItemBuilder.h"
#import "SMEvent.h"
#import "SMEventBuilder.h"
#import "SMEventItem.h"
#import "SMEventItemBuilder.h"
#import "SMEventNotification.h"
#import "SMEventsManager.h"
#import "SMGeolocationEvent.h"
#import "SMPurchaseEvent.h"
#import "SMPurchaseEventBuilder.h"
#import "SMPurchaseEventItem.h"
#import "SMPurchaseEventItemBuilder.h"
#import "SMSimpleEventBuilder.h"

// Responses
#import "SMBehaviorProgressFetchedResponse.h"
#import "SMEventPostedResponse.h"
#import "SMEventsResponse.h"


//! Project version number for SessionMEventsKit.
FOUNDATION_EXPORT double SessionMEventsKitVersionNumber;

//! Project version string for SessionMEventsKit.
FOUNDATION_EXPORT const unsigned char SessionMEventsKitVersionString[];

#endif /* __SESSIONM_EVENTS_KIT__ */
