//
//  SMGenericRequestBuilder.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//
//

#ifndef __SM_GENERIC_REQUEST_BUILDER__
#define __SM_GENERIC_REQUEST_BUILDER__

#import "SMGenericRequest.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMGenericRequestBuilder
 @abstract Class used for building @link SMGenericRequest @/link objects that represent generic SessionM Platform HTTP requests.
 */
@interface SMGenericRequestBuilder : NSObject

/*!
 @property baseURL
 @abstract The context-based request URL.
 */
@property(nonatomic, copy,   readwrite) NSString *baseURL;
/*!
 @property method
 @abstract The method of the request (GET/POST/PUT/DELETE).
 */
@property(nonatomic, assign, readwrite) SMGenericRequestMethodType method;
/*!
 @property kind
 @abstrat Developer-defined descriptor used to distinguish between kinds of requests.
 */
@property(nonatomic, strong, readonly) NSString *kind;
/*!
 @property body
 @abstract The body of the request - a dictionary that can be converted to JSON.
 */
@property(nonatomic, strong) NSMutableDictionary<NSString *, NSObject *> *body;
/*!
 @property headers
 @abstract A dictionary of key-value pairs that correspond to the headers in a request.
 */
@property(nonatomic, strong, readonly) NSMutableDictionary<NSString *, NSString *> *headers;
/*!
 @property params
 @abstract Additional query parameters added to the request URL.
 */
@property(nonatomic, strong, readonly) NSMutableDictionary<NSString *, NSObject *> *params;
/*!
 @property keepAround
 @abstract Values to keep for the entire request/response cycle.
 @discussion These are values that you want to pass through the whole request/response cycle. Because the call 
 is asynchronous, we need a mechanism so that values are available, such as when the response is returned.
 The values will be available at that point.
 */
@property(nonatomic, strong, readonly) NSMutableDictionary<NSString *, NSString *> *keepAround;

/*!
 @abstract Generates an immutable HTTP request object.
 @return The generated @link SMGenericRequest @/link object.
 */
- (SMGenericRequest *)build;

/*!
 @abstract Returns a request builder that builds requests with the given method type.
 @param method @link SMGenericRequestMethodType @/link (PUT/POST/GET/DELETE).
 @result @link SMGenericRequestBuilder @/link instance.
 */
+ (instancetype)requestBuilderWithMethod:(SMGenericRequestMethodType)method kind:(NSString *)kind;

/*!
 @abstract Initializes a request builder that builds requests with the given method type
 @param method @link SMGenericRequestMethodType @/link (PUT/POST/GET/DELETE).
 @result @link SMGenericRequestBuilder @/link instance.
 */
- (instancetype)initWithMethod:(SMGenericRequestMethodType)method kind:(NSString *)kind;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_GENERIC_REQUEST_BUILDER__ */
