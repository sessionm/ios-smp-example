//
//  CLLBaseItem.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef CLLBaseItem_H
#define CLLBaseItem_H

#import <Foundation/Foundation.h>

#import "CLLRecordBase.h"
#import "CLLMedia.h"

NS_ASSUME_NONNULL_BEGIN

@interface CLLBaseItem : CLLRecordBase

@property(nonatomic, readonly, strong)NSString *ID;
@property(nonatomic, readonly, strong)NSString *name;
@property(nonatomic, readonly, strong)NSString *details;  // Note, because of Apple bug, cannot be description
@property(nonatomic, readonly, strong)NSString *terms;
@property(nonatomic, readonly, strong)NSString *categoryName;
@property(nonatomic, readonly, strong)NSString *categoryID;
@property(nonatomic, readonly, strong)NSString *typeID;

@property(nonatomic, readonly, strong)NSDate   *startDate;
@property(nonatomic, readonly, strong)NSDate   *endDate;
@property(nonatomic, readonly, strong)NSDate   *expireDate;
@property(nonatomic, readonly, strong)NSArray<CLLMedia *> *media;
@property(nonatomic, readonly, assign)BOOL      isRedeemable;

@end

NS_ASSUME_NONNULL_END

#endif
