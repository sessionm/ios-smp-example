//
//  SMGenericRequestBuilder.h
//  SessionMCoreKit
//
//  Copyright © 2018 SessionM. All rights reserved.
//
//

#ifndef __SM_GENERIC_REQUEST_BUILDER__
#define __SM_GENERIC_REQUEST_BUILDER__

#import "SMGenericRequest.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMGenericRequestBuilder
 @abstract Class used for building <code>SMGenericRequest</code> objects that represent generic SessionM Platform HTTP requests.
 @discussion The following tokens can be used when formatting <code>baseURL</code>:
 <ul>
 <li>':host' - the app's SessionM Platform API host URL</li>
 <li>':appid' - the app's SessionM Platform API key</li>
 </ul>
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
@property(nonatomic, strong) NSMutableDictionary<NSString *, id> *body;
/*!
 @property headers
 @abstract A dictionary of key-value pairs that correspond to the headers in a request.
 */
@property(nonatomic, strong, readonly) NSMutableDictionary<NSString *, NSString *> *headers;
/*!
 @property params
 @abstract Additional query parameters added to the request URL.
 */
@property(nonatomic, strong, readonly) NSMutableDictionary<NSString *, id> *params;
/*!
 @property keepAround
 @abstract Values to keep for the entire request/response cycle.
 @discussion These are values that you want to pass through the whole request/response cycle. Because the call 
 is asynchronous, we need a mechanism so that values are available, such as when the response is returned.
 The values will be available at that point.
 */
@property(nonatomic, strong, readonly) NSMutableDictionary<NSString *, NSString *> *keepAround;

/*!
 @property errorMessageMaker
 @abstract Can be used to provide a custom error message for the <code>SMError</code> object returned in the <code>completionHandler</code> parameter for the <code>SMGenericRequestManager sendRequest:completionHandler:</code> method.
 @discussion This block will only be executed if an error is returned in the request response.
 */
@property(nullable, nonatomic, copy, readwrite) ErrorMessageMaker errorMessageMaker;

/*!
 @abstract Returns a request builder that builds requests with the given method type.
 @param method <code>SMGenericRequestMethodType</code> (PUT/POST/GET/DELETE).
 @result <code>SMGenericRequestBuilder</code> instance.
 */
+ (instancetype)requestBuilderWithMethod:(SMGenericRequestMethodType)method kind:(NSString *)kind;

/*!
 @abstract Initializes a request builder that builds requests with the given method type
 @param method <code>SMGenericRequestMethodType</code> (PUT/POST/GET/DELETE).
 @result <code>SMGenericRequestBuilder</code> instance.
 */
- (instancetype)initWithMethod:(SMGenericRequestMethodType)method kind:(NSString *)kind;

/*!
 @abstract Generates an immutable HTTP request object.
 @return The generated <code>SMGenericRequest</code> object.
 */
- (SMGenericRequest *)build;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_GENERIC_REQUEST_BUILDER__ */
