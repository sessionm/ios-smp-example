// 
//  SMCustomerConfig.h
//  SessionMCoreKit
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SM_CUSTOMER_CONFIG__
#define __SM_CUSTOMER_CONFIG__

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMCustomerConfig
 @abstract Stores the current values for any local or remote app configuration settings defined by the customer.
 */
@interface SMCustomerConfig : NSObject

/*!
 @abstract Retrieves the value of the customer-defined configuration setting with the specified key path.
 @param keyPath A key path of the form relationship.property (with one or more relationships); for example “department.name” or “department.manager.lastName”.
 @result The value for the specified key path.
 */
- (nullable id)settingForKeyPath:(NSString *)keyPath NS_SWIFT_NAME(setting(forKeyPath:));

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_CUSTOMER_CONFIG__ */
