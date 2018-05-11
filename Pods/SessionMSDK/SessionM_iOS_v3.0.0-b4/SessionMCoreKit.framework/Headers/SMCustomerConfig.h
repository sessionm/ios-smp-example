// 
//  SMCustomerConfig.h
//  SessionMCoreKit
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef Customer_Config__
#define Customer_Config__

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SMCustomerConfig : NSObject

/*!
 @abstract used to get config data from the customer config
 @discussion the customer config can be stored as a structure, so this always iOS path navigation
 */
-(nullable id)getForPath:(NSString *)path;

@end

NS_ASSUME_NONNULL_END

#endif
