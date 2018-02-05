//
//  SMGenericResponse.h
//  SessionM
//
//  Copyright © 2018 SessionM. All rights reserved.
//
//

#ifndef __SM_GENERIC_RESPONSE__
#define __SM_GENERIC_RESPONSE__

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMGenericResponse
 @abstract Defines the data associated with a generic SessionM Platform HTTP request response.
 */
@interface SMGenericResponse : NSObject

/*!
 @typedef body
 @abstract Dictionary representation of JSON response body.
 */
@property(nonatomic, strong, readonly) NSDictionary *body;
/*!
 @typedef bodyString
 @abstract String representation of JSON response body.
 */
@property(nonatomic, strong, readonly) NSString *bodyString;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_GENERIC_RESPONSE__ */
