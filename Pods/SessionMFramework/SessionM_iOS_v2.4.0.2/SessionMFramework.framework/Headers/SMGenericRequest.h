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
@property(nonatomic, strong, readonly) NSDictionary<NSString *, NSString *> *params;
/*!
 @property keepAround
 @abstract Dictionary representation of data that is kept through the entire request/response cycle.
 */
@property(nonatomic, strong, readonly) NSDictionary<NSString *, NSString *> *keepAround;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_GENERIC_REQUEST__ */
