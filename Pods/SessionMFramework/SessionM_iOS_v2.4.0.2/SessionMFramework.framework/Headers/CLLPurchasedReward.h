//
//  CLLPurchasedReward.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//
//

#ifndef CLLPurchasedReward_h
#define CLLPurchasedReward_h

#import <Foundation/Foundation.h>
#import "CLLBaseItem.h"

NS_ASSUME_NONNULL_BEGIN

@interface CLLPurchasedReward : CLLBaseItem

@property(nonatomic, readonly, strong)NSString *storeItemID;
@property(nonatomic, readonly, strong)NSDate   *serverUTCDateTime;

@property(nonatomic, readonly, strong)NSString *code;
@property(nonatomic, readonly, strong)NSString *codeImageUri;
@property(nonatomic, readonly, strong)NSString *sharedCode;

@property(nonatomic, readonly, strong)NSDate   *acquireDate;

@end

NS_ASSUME_NONNULL_END

#endif
