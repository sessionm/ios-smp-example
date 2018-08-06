//
//  SMHTTPRequestBuilder.h
//  SessionMCoreKit
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SM_HTTP_REQUEST_BUILDER__
#define __SM_HTTP_REQUEST_BUILDER__

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMHTTPRequestBuilder
 @abstract If the current authentication provider's <code>updateAuthenticationRequestWithBuilder:</code> method is implemented, then the SDK will call the method with an instance of this class before sending an HTTP request to the SessionM Platform, allowing the developer to update the request data.
 */
@interface SMHTTPRequestBuilder : NSObject

/*!
 @property contentType
 @abstract Value to be used for the request's "Content-Type" header (default vlaue is "application/json").
 */
@property(nonatomic, strong, readwrite) NSString *contentType;
/*!
 @property body
 @abstract Dictionary representation of JSON request body.
 */
@property(nullable, nonatomic, strong, readwrite) NSDictionary *body;
/*!
 @property followRedirect
 @abstract Indicates whether HTTP redirects should be handled automatically by the SDK (default value is <code>YES</code>).
 */
@property(nonatomic, assign, readwrite) BOOL followRedirect;
/*!
 @property params
 @abstract Dictionary representation of HTTP request parameters.
 */
@property(nonatomic, strong, readonly) NSMutableDictionary<NSString *, id> *params;
/*!
 @property headers
 @abstract Dictionary representation of HTTP request headers.
 */
@property(nonatomic, strong, readonly) NSMutableDictionary<NSString *, NSString *> *headers;
/*!
 @property keepAround
 @abstract Dictionary representation of data that is kept through the entire request/response cycle.
 */
@property(nonatomic, strong, readonly) NSMutableDictionary<NSString *, id> *keepAround;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_HTTP_REQUEST_BUILDER__ */
