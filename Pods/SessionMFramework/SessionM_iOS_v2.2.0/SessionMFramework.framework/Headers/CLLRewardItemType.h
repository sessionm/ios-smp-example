//
//  CLLRewardItemType.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//
//

#ifndef LT_ITEM_TYPE
#define LT_ITEM_TYPE

#import <Foundation/Foundation.h>
#import "CLLRecordBase.h"

NS_ASSUME_NONNULL_BEGIN

@interface CLLRewardItemType : CLLRecordBase

@property(nonatomic, readonly, strong)NSString   *ID;
@property(nonatomic, readonly, strong)NSString   *name;
@property(nonatomic, readonly, assign)NSInteger   sortOrder;
@property(nonatomic, readonly, assign)BOOL        isRedeemable;

@end

NS_ASSUME_NONNULL_END

#endif
