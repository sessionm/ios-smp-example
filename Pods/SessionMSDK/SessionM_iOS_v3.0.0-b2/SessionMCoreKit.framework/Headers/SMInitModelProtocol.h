//
//  SMInitModelProtocol.h
//  SessionM
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SM_INIT_MODEL_PROTOCOL__
#define __SM_INIT_MODEL_PROTOCOL__

NS_ASSUME_NONNULL_BEGIN

@protocol SMInitModelProtocol <NSObject>

- (instancetype)initWithMutableDictionary:(NSMutableDictionary<NSString *, id> *)dict;

@end

NS_ASSUME_NONNULL_END

#endif 
