//
//  SMMessagesManagerProtected.h
//  SessionMMessagesKit
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef __SM_MESSAGES_MANAGER_PROTECTED__
#define __SM_MESSAGES_MANAGER_PROTECTED__

#import "SMMessagesManager.h"

NS_ASSUME_NONNULL_BEGIN

extern NSString *const kDeviceToken;

@interface SMMessagesManager (Protected)
@property(nullable, nonatomic, strong, readonly) NSString *deviceToken;
@end

NS_ASSUME_NONNULL_END

#endif /* __SM_MESSAGES_MANAGER_PROTECTED__ */
