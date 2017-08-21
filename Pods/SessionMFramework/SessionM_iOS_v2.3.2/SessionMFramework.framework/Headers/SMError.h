//
//  SMError.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef __SM_ERROR__
#define __SM_ERROR__

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @typedef SMErrorType
 @abstract Indicates how error occurred.

 @constant SMErrorTypeUnknown Error type is unknown.
 @constant SMErrorTypeNetwork API request failed due to network connection loss.
 @constant SMErrorTypeValidation Input to method was invalid.
 @constant SMErrorTypeServerError Server returned an error.
 */
typedef NS_ENUM (NSInteger, SMErrorType) {
    SMErrorTypeUnknown NS_SWIFT_NAME(unknown),
    SMErrorTypeNetwork NS_SWIFT_NAME(network),
    SMErrorTypeValidation NS_SWIFT_NAME(validation),
    SMErrorTypeServerError NS_SWIFT_NAME(server),
    SMErrorTypeServerAuthorization NS_SWIFT_NAME(authorization),
    SMErrorTypeWebView NS_SWIFT_NAME(webView)
};


/*!
 @class SMError
 @abstract Defines the data associated with an error received from a SessionM Platform SDK API method.
 */
@interface SMError : NSObject

/*!
 @property type
 @abstract Error type.
 */
@property(nonatomic, assign, readonly) SMErrorType type;
/*!
 @property message
 @abstract Error message text.
 */
@property(nonatomic, strong, readonly) NSString *message;
/*!
 @property code
 @abstract Error code from server.
 */
@property(nonatomic, strong, readonly) NSString *code;
/*!
 @property raw
 @abstract Raw error data returned by the server.
 */
@property(nonatomic, strong, readonly) NSDictionary *raw;

/*!
 @abstract Class method to create an instance of <code>SMError</code> with the specified error type and message text.
 @param type Error type.
 @param message Error message text.
 @result <code>SMError</code> instance.
 */
+(instancetype)errorWithType:(SMErrorType)type code:(NSString *)code message:(NSString *)message NS_SWIFT_NAME(error(type:code:message:));
/*!
 @abstract Class method to create an instance of <code>SMError</code> with the specified error type and message text.
 @param type Error type.
 @param dictionary Entire dictionary error result given to message formatter.
 @param messageFormatter Block that is called to convert error into a message.
 @result <code>SMError</code> instance.
 */
+(instancetype)errorWithType:(SMErrorType)type result:(NSDictionary *)dictionary makeMessage:(NSString *(^)(NSDictionary *error))messageFormatter NS_SWIFT_NAME(error(type:dictionary:messageFormatter:));

/*!
 @abstract Creates an instance of <code>SMError</code> with the specified error type and message text.
 @param type Error type.
 @param message Error message text.
 @result <code>SMError</code> instance.
 */
- (instancetype)initWithType:(SMErrorType)type code:(NSString *)code message:(NSString *)message NS_SWIFT_NAME(init(type:code:message:));
/*!
 @abstract Creates an instance of <code>SMError</code> with the specified error type and message text.
 @param type Error type.
 @param dictionary Entire dictionary error result given to message formatter.
 @param messageFormatter Block that is called to convert error into a message.
 @result <code>SMError</code> instance.
 */
- (instancetype)initWithType:(SMErrorType)type result:(NSDictionary *)dictionary makeMessage:(NSString *(^)(NSDictionary *error))messageFormatter NS_SWIFT_NAME(init(type:dictionary:messageFormatter:));

/*!
 @abstract Converts specified string value to the corresponding @link SMErrorType @/link enum value.
 @param string String to convert.
 @result @link SMErrorType @/link enum value.
 */
+ (SMErrorType)errorTypeForString:(NSString *)string NS_SWIFT_NAME(errorType(from:));
/*!
 @abstract Converts specified @link SMErrorType @/link enum value to the corresponding string value.
 @param type Error type to convert.
 @result <code>NSString</code> value.
 */
+ (NSString *)stringForErrorType:(SMErrorType)type NS_SWIFT_NAME(string(from:));

extern NSString * const SMErrorServerIssue NS_SWIFT_NAME(serverErrorCannotProcess);
extern NSString * const SMErrorServerNoRequest NS_SWIFT_NAME(serverErrorNoRequest);
extern NSString * const SMErrorServerBadJson NS_SWIFT_NAME(serverErrorBadJSON);

extern NSString * const SMErrorAuthenticationFail NS_SWIFT_NAME(authenticateFail);
extern NSString * const SMErrorValidationNoUpdates NS_SWIFT_NAME(validationErrorNoUpdates);
extern NSString * const SMErrorValidationNoCreate NS_SWIFT_NAME(validationErrorCreate);
extern NSString * const SMErrorValidationNoToken NS_SWIFT_NAME(validationErrorNoToken);
extern NSString * const SMErrorValidationNoProvider NS_SWIFT_NAME(validationErrorNoProvider);
extern NSString * const SMErrorValidationNoEmailPassword NS_SWIFT_NAME(validationErrorNoEmailPassword);
extern NSString * const SMErrorValidationInvalidOAuthServiceConfiguration NS_SWIFT_NAME(validationErrorInvalidOAuthServiceConfiguration);
extern NSString * const SMErrorNoAccessToken NS_SWIFT_NAME(errorNoAccessToken);
extern NSString * const SMErrorValidationNoPhone NS_SWIFT_NAME(validationErrorNoPhone);
extern NSString * const SMErrorValidationNoCode NS_SWIFT_NAME(validationErrorNoCode);
extern NSString * const SMErrorValidationNoCardNumber NS_SWIFT_NAME(validationErrorNoCardNumber);
extern NSString * const SMErrorValidationNoCardID NS_SWIFT_NAME(validationErrorNoCardID);
extern NSString * const SMErrorValidationNoRetailerID NS_SWIFT_NAME(validationErrorNoRetailerID);
extern NSString * const SMErrorValidationGenericRequest NS_SWIFT_NAME(validationGenericRequest);
extern NSString * const SMErrorValidationNoLocation NS_SWIFT_NAME(validationErrorNoLocation);
extern NSString * const SMErrorValidationNoPlace NS_SWIFT_NAME(validationErrorNoPlace);
extern NSString * const SMErrorValidationNoPlaceID NS_SWIFT_NAME(validationErrorNoPlaceID);
extern NSString * const SMErrorValidationNoPaths NS_SWIFT_NAME(validationErrorNoPaths);
extern NSString * const SMErrorValidationNoCampaignID NS_SWIFT_NAME(validationErrorNoCampaignID);
extern NSString * const SMErrorValidationNoAssetIDs NS_SWIFT_NAME(validationErrorNoAssetIDs);
extern NSString * const SMErrorValidationBadGroupID NS_SWIFT_NAME(validationErrorBadGroupID);
extern NSString * const SMErrorValidationNoGroupID NS_SWIFT_NAME(validationErrorNoGroupID);
extern NSString * const SMErrorValidationBadUploadData NS_SWIFT_NAME(validationErrorBadUploadData);
extern NSString * const SMErrorValidationInvalidReferral NS_SWIFT_NAME(validationErrorInvalidReferral);
extern NSString * const SMErrorValidationInvalidEmail NS_SWIFT_NAME(validationErrorInvalidEmail);
extern NSString * const SMErrorValidationDuplicateEmail NS_SWIFT_NAME(validationErrorDuplicateEmail);
extern NSString * const SMErrorValidationNoReferral NS_SWIFT_NAME(validationErrorNoReferral);
extern NSString * const SMErrorValidationNoReferralID NS_SWIFT_NAME(validationErrorNoReferralID);
extern NSString * const SMErrorValidationNoOfferID NS_SWIFT_NAME(validationErrorNoOfferID);
extern NSString * const SMErrorValidationNoQuestionID NS_SWIFT_NAME(validationErrorNoQuestionID);
extern NSString * const SMErrorValidationNoAnswer NS_SWIFT_NAME(validationErrorNoAnswer);
extern NSString * const SMErrorValidationBadDates NS_SWIFT_NAME(validationErrorBadDates);
extern NSString * const SMErrorValidationNoContentID NS_SWIFT_NAME(validationErrorNoContentID);
extern NSString * const SMErrorValidationNoExternalID NS_SWIFT_NAME(validationErrorNoExternalID);
extern NSString * const SMErrorValidationNoZipCode NS_SWIFT_NAME(validationErrorNoZipCode);
extern NSString * const SMErrorValidationNoMessageID NS_SWIFT_NAME(validationErrorNoMessageID);
extern NSString * const SMErrorValidationNoMessage NS_SWIFT_NAME(validationErrorNoMessage);

extern NSString * const SMErrorWebViewPageNotLoaded;
extern NSString * const SMErrorWebViewJSIssue;

extern NSString * const SMErrorJSBridgeNoHandler NS_SWIFT_NAME(jsBridgeNoHandler);
extern NSString * const SMErrorJSBridgeNoMessage NS_SWIFT_NAME(jsBridgeNoMessage);
extern NSString * const SMErrorJSBridgeHandlerIssue NS_SWIFT_NAME(jsBridgeHandlerIssue);
extern NSString * const SMErrorJSBridgeJSCallIssue NS_SWIFT_NAME(jsBridgeJSCallIssue);

extern NSString * const LTErrorInvalidResult NS_SWIFT_NAME(validationErrorInvalidResult);
extern NSString * const SMErrorInternalError NS_SWIFT_NAME(errorInternalError);

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_ERROR__ */
