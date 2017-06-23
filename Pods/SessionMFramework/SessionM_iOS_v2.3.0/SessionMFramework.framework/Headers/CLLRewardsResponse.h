//
//  CLLRewardsResponse.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef CLLRewardsResponse_H
#define CLLRewardsResponse_H

#import "CLLRewardItemType.h"
#import "CLLPurchasedReward.h"

NS_ASSUME_NONNULL_BEGIN

@interface CLLRewardsResponse : CLLRecordBase

@property(readonly)NSArray<CLLPurchasedReward *> *rewards;
@property(readonly)NSArray<CLLRewardItemType *>  *itemTypes;
@property(readonly)NSInteger                      totalRecords;
@property(readonly)NSInteger                      totalPoints;
@property(readonly)NSInteger                      availablePoints;


@property(nonatomic, readonly, strong)NSString *userID;
@property(nonatomic, readonly, assign)BOOL wasAuthReissued;

@end

NS_ASSUME_NONNULL_END

#endif
