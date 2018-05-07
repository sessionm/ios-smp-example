//
//  SessionMIdentityKit.h
//  SessionMIdentityKit
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SESSIONM_IDENTITY_KIT__
#define __SESSIONM_IDENTITY_KIT__

// SessionM Platform
#import <SessionMCoreKit/SessionMCoreKit.h>

// System Frameworks
#import <CoreLocation/CoreLocation.h>
#import <UIKit/UIKit.h>

// Identity
#import "SessionMOauthProviderIDP.h"
#import "SessionMOauthProvider.h"
#import "SessionMOauthSpecialCaseProvider.h"
#import "SMIdentityError.h"

// Profile
#import "SMPUser.h"
#import "SMPUserCreate.h"
#import "SMPUserUpdate.h"
#import "SMUserManager.h"
#import "SMUserManagerProtected.h"
#import "SMWebProfileManager.h"

// SMS
#import "SMSVerification.h"
#import "SMSVerificationManager.h"

// Tags
#import "SMUserTagsManager.h"


//! Project version number for SessionMIdentityKit.
FOUNDATION_EXPORT double SessionMIdentityKitVersionNumber;

//! Project version string for SessionMIdentityKit.
FOUNDATION_EXPORT const unsigned char SessionMIdentityKitVersionString[];

#endif /* __SESSIONM_IDENTITY_KIT__ */
