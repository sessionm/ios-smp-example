//
//  CLLRecordBase.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//
//

#ifndef LT_RECORD_BASE
#define LT_RECORD_BASE

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CLLRecordBase : NSObject
@property(nonatomic, readonly, strong)NSDictionary *dictionary;

@property(nonatomic, readonly)NSString *errorMessage;
@property(nonatomic, readonly)NSString *errorCode;

-(instancetype)initWithDictionary:(NSDictionary *)dict;

-(NSDate * _Nullable)dateFromString:(NSString *)dateString;
@end

NS_ASSUME_NONNULL_END

#endif
