//
//  SMGenericRequest.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//
//

#ifndef __SM_GENERIC_REQUEST__
#define __SM_GENERIC_REQUEST__

#import <Foundation/Foundation.h>

#import "SMError.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @typedef SMGenericRequestMethodType
 @abstract SessionM Platform HTTP request method type.

 @constant SMGenericRequestMethodTypeGET Fetch an entity.
 @constant SMGenericRequestMethodTypePOST Create an entity.
 @constant SMGenericRequestMethodTypePUT Update an entity.
 @constant SMGenericRequestMethodTypeDELETE Delete an entity.
 */
typedef NS_ENUM(NSUInteger, SMGenericRequestMethodType) {
    SMGenericRequestMethodTypeGET NS_SWIFT_NAME(get),
    SMGenericRequestMethodTypePOST NS_SWIFT_NAME(post),
    SMGenericRequestMethodTypePUT NS_SWIFT_NAME(put),
    SMGenericRequestMethodTypeDELETE NS_SWIFT_NAME(delete)
};

@class SMGenericRequest;

/*!
 @typedef VerificationHandler
 @abstract Type for blocks used to verify requests before they are processed.
 */
typedef BOOL(^VerificationHandler)(SMGenericRequest *request, SMError * _Nullable * _Nullable error);

/*!
 @typedef URLFormatter
 @abstract Type for blocks used to format request URLs.
 @discussion The following tokens can be used for formatting:
 <ul>
 <li>':host:' - the SessionM Platform API host URL</li>
 <li>':lt_host:' - the LoyalTree API host URL</li>
 <li>':api_key:' - the app's SessionM Platform API key</li>
 </ul>
 */
typedef NSString * _Nullable (^URLFormatter)(SMGenericRequest *request);

/*!
 @class SMGenericRequest
 @abstract Defines the data associated with a generic SessionM Platform HTTP request.
 */
@interface SMGenericRequest : NSObject

/*!
 @typedef body
 @abstract Dictionary representation of JSON request body.
 */
@property(nonatomic, strong, readonly) NSDictionary<NSString *, NSObject *> *body;
/*!
 @typedef bodyString
 @abstract String representation of JSON request body.
 */
@property(nonatomic, strong, readonly) NSString *bodyString;
/*!
 @typedef headers
 @abstract Dictionary representation of HTTP request headers.
 */
@property(nonatomic, strong, readonly) NSDictionary<NSString *, NSString *> *headers;

/*!
 @abstract Creates a new instance of <code>SMGenericRequest</code> with the specified parameters.
 @param body Dictionary representation of JSON request body.
 @param method HTTP method.
 @param urlFormatter Block used to format request URL.
 @param headers Dictionary representation of HTTP request headers.
 @result <code>SMGenericRequest</code> instance.
 */
+ (instancetype)requestWithBody:(NSDictionary<NSString *, NSObject *> *)body
                         method:(SMGenericRequestMethodType)method
                   urlFormatter:(URLFormatter)urlFormatter
                        headers:(NSDictionary<NSString *, NSString *> * _Nullable)headers;

/*!
 @abstract Creates a new instance of <code>SMGenericRequest</code> with the specified parameters.
 @param body Dictionary representation of JSON request body.
 @param method HTTP method.
 @param urlFormatter Block used to format request URL.
 @param headers Dictionary representation of HTTP request headers.
 @result <code>SMGenericRequest</code> instance.
 */
- (instancetype)initWithBody:(NSDictionary<NSString *, NSObject *> *)body
                      method:(SMGenericRequestMethodType)method
                urlFormatter:(URLFormatter)urlFormatter
                     headers:(NSDictionary<NSString *,NSString *> * _Nullable)headers;

/*!
 @abstract Adds a handler to the request that will verify request data before the request is sent.
 @param verificationHandler Block to execute to verify request data - request will not be sent if return value is false.
 */
- (void)addVerificationHandler:(VerificationHandler)verificationHandler;

/*!
 @abstract Adds additional values to request body.
 @param key Dictionary key name.
 @param value Value for key.
 */
- (void)addBodyKey:(NSString *)key value:(NSObject *)value;
/*!
 @abstract Adds additional values to request header.
 @param key Dictionary key name.
 @param value Value for key.
 */
- (void)addHeaderKey:(NSString *)key value:(NSString *)value;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_GENERIC_REQUEST__ */
