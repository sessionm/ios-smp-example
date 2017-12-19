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
 @typedef ErrorMessageMaker
 @abstract Block type for @link errorMessageMaker @/link, which should return a human-readable error message based on the given request and error response.
 */
typedef NSString * _Nonnull (^ErrorMessageMaker)(SMGenericRequest *request, NSDictionary *error);

/*!
 @class SMGenericRequest
 @abstract Defines the data associated with a generic SessionM Platform HTTP request.
 @discussion The following tokens can be used for formatting:
 <ul>
 <li>':host:' - the SessionM Platform API host URL</li>
 <li>':api_key:' - the app's SessionM Platform API key</li>
 </ul>
 */
@interface SMGenericRequest : NSObject

/*!
 @property methodString
 @abstract String value of the HTTP request method (PUT/POST/GET/DELETE).
 */
@property(nonatomic, strong, readonly) NSString *methodString;
/*!
 @property url
 @abstract HTTP request URL.
 */
@property(nonatomic, strong, readonly) NSString *url;
/*!
 @property kind
 @abstract Developer-defined descriptor used to distinguish between kinds of requests.
 */
@property(nonatomic, strong, readonly) NSString *kind;
/*!
 @property method
 @abstract Enumeration value for HTTP request method (PUT/POST/GET/DELETE).
 */
@property(nonatomic, assign, readonly) SMGenericRequestMethodType method;

/*!
 @property body
 @abstract Dictionary representation of JSON request body.
 */
@property(nonatomic, strong, readonly) NSDictionary<NSString *, NSObject *> *body;
/*!
 @property bodyString
 @abstract String representation of JSON request body.
 */
@property(nonatomic, strong, readonly) NSString *bodyString;
/*!
 @property headers
 @abstract Dictionary representation of HTTP request headers.
 */
@property(nonatomic, strong, readonly) NSDictionary<NSString *, NSString *> *headers;
/*!
 @property params
 @abstract Dictionary representation of HTTP request parameters.
 */
@property(nonatomic, strong, readonly) NSDictionary<NSString *, NSObject *> *params;
/*!
 @property keepAround
 @abstract Dictionary representation of data that is kept through the entire request/response cycle.
 */
@property(nonatomic, strong, readonly) NSDictionary<NSString *, NSObject *> *keepAround;

/*!
 @property errorMessageMaker
 @abstract Can be used to provide a custom error message for the @link //apple_ref/occ/cl/SMError @/link object returned in the <code>completionHandler</code> parameter for the @link //apple_ref/occ/instm/SMGenericRequestManager/sendRequest:completionHandler: @/link method.
 @discussion This block will only be executed if an error is returned in the request response.
 */
@property(nullable, nonatomic, copy, readonly) ErrorMessageMaker errorMessageMaker;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_GENERIC_REQUEST__ */
