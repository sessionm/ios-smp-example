//
//  CLLPurchaseRewardResponse.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef CLLPurchaseRewardResponse_H
#define CLLPurchaseRewardResponse_H

#import "CLLPurchasedReward.h"

NS_ASSUME_NONNULL_BEGIN

@interface CLLPurchaseRewardResponse : CLLRecordBase
@property(readonly)CLLPurchasedReward *reward;
@property(readonly)NSNumber           *pointsRemaining;
@end

NS_ASSUME_NONNULL_END

#endif
