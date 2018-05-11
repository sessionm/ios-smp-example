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

@protocol SMManager

+ (instancetype)instance;

@end

@interface SMBaseManager : NSObject <SMManager>
@end

NS_ASSUME_NONNULL_END

#endif /* __SM_BASE_MANAGER__ */

