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
 @abstract A block that the developer can use to create context-based request URLs.
 */
@property(nonatomic, copy,   readwrite) URLFormatter baseURL;
/*!
 @property method
 @abstract The method of the request (GET/POST/PUT/DELETE).
 */
@property(nonatomic, assign, readwrite) SMGenericRequestMethodType method;
/*!
 @property body
 @abstract The body of the request - a dictionary that can be converted to JSON.
 */
@property(nonatomic, strong, readwrite) NSDictionary<NSString *, NSObject *> *body;
/*!
 @property headers
 @abstract A dictionary of key-value pairs that correspond to the headers in a request.
 */
@property(nonatomic, strong, readwrite) NSDictionary<NSString *, NSString *> *headers;
/*!
 @property params
 @abstract Additional query parameters added to the request URL.
 */
@property(nonatomic, strong, readwrite) NSDictionary<NSString *, NSString *> *params;
/*!
 @property keepAround
 @abstract Values to keep for the entire request/response cycle.
 @discussion These are values that you want to pass through the whole request/response cycle. Because the call 
 is asynchronous, we need a mechanism so that values are available, such as when the response is returned.
 The values will be available at that point.
 */
@property(nonatomic, strong, readwrite) NSDictionary<NSString *, NSString *> *keepAround;

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
+ (instancetype)requestBuilderWithMethod:(SMGenericRequestMethodType)method;

/*!
 @abstract Initializes a request builder that builds requests with the given method type
 @param method @link SMGenericRequestMethodType @/link (PUT/POST/GET/DELETE).
 @result @link SMGenericRequestBuilder @/link instance.
 */
- (instancetype)initWithMethod:(SMGenericRequestMethodType)method;

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

#endif /* __SM_GENERIC_REQUEST_BUILDER__ */
