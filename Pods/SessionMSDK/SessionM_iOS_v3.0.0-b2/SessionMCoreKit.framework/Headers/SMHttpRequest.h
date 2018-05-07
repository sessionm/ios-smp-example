//
//  SMHttpRequest.h
//  SessionMCoreKit
//
//  Copyright © 2018 session M. All rights reserved.
//
//

//
// Internal Class.  Holds all of the information required to perform the Http request
// This is carried around as all stages of the queueing and http request need information from it.

#ifndef SM_HTTP_REQUEST_
#define SM_HTTP_REQUEST_

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, SMHttpClientMethod) {
    HttpPOST, HttpGET, HttpDELETE, HttpPUT
};

NS_ASSUME_NONNULL_BEGIN

@class SMHttpRequestBuilder;

@interface SMHttpRequest : NSObject
@end

//
// Gathers all of the information so that the SMHttpRequest can be immutable
//

@interface SMHttpRequestBuilder : NSObject

@property(nonatomic, strong, readwrite)NSString                                   *contentType;
@property(nullable, nonatomic, strong, readwrite)NSDictionary                     *body;
@property(nonatomic, assign, readwrite)BOOL                                        followRedirect;

@property(nonatomic, strong, readonly)NSMutableDictionary<NSString *, id> *params;
@property(nonatomic, strong, readonly)NSMutableDictionary<NSString *, NSString *> *headers;
@property(nonatomic, strong, readonly)NSMutableDictionary<NSString *, id> *keepAround;

@end

NS_ASSUME_NONNULL_END

#endif
