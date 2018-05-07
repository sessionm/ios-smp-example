//
//  SMPCore.h
//  SessionMCoreKit
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SMP_Startup__
#define __SMP_Startup__

#import <Foundation/Foundation.h>
#import "SMPConfig.h"
#import "SMError.h"
#import "SMAuthenticationProvider.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @abstract callback from SessionM.start methods
 */
typedef void(^SMPStartupHandler)(SMError * _Nullable error);
/*!
 @abstract callback from SessionM.stop method
 */
typedef void(^SMPShutdownHandler)(SMError * _Nullable error);

@interface SMPStartup : NSObject

@end

NS_ASSUME_NONNULL_END

#endif 
