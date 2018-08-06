//
//  SMBaseManager.h
//  SessionMCoreKit
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifndef __SM_BASE_MANAGER__
#define __SM_BASE_MANAGER__

NS_ASSUME_NONNULL_BEGIN

/*!
 @protocol SMManager
 @abstract Defines methods that all API managers in the SessionM Platform SDK are expected to implement.
 */
@protocol SMManager

/*!
 @abstract Singleton that interfaces with the SessionM Platform Campaigns API.
 @result <code>SMCampaignsManager</code> service object.
 */

/*!
 @abstract Singleton that interfaces with a SessionM Platform API.
 @result Service object whose type will be a subclass of <code>SMBaseManager</code>.
 */
+ (instancetype)instance;

@end


/*!
 @class SMBaseManager
 @abstract Defines default functionality for all API managers in the SessionM Platform SDK.
 */
@interface SMBaseManager : NSObject <SMManager>
@end

NS_ASSUME_NONNULL_END

#endif /* __SM_BASE_MANAGER__ */
