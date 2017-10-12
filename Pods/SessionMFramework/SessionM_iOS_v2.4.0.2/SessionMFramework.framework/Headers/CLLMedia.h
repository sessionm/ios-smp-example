//
//  CLLMedia.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//
//

#ifndef LT_MEDIA
#define LT_MEDIA

#import <Foundation/Foundation.h>
#import "CLLRecordBase.h"

NS_ASSUME_NONNULL_BEGIN

@interface CLLMedia : CLLRecordBase

@property(nonatomic, readonly, strong)NSString   *name;
@property(nonatomic, readonly, strong)NSString   *uri;
@property(nonatomic, readonly, assign)NSUInteger  mediaType;
@property(nonatomic, readonly, strong)NSDate     *timeStamp;

@end

NS_ASSUME_NONNULL_END

#endif
