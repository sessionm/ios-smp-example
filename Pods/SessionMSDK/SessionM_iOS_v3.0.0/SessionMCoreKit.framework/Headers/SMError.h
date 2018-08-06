//
//  SMError.h
//  SessionMCoreKit
//
//  Copyright © 2018 SessionM. All rights reserved.
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
 @constant SMErrorTypeAuthentication Authorization credentials for network request were missing.
 @constant SMErrorTypeWebView Error encountered when performing web view network request or JavaScript call.
 @constant SMErrorTypeInvalidState
 */
typedef NS_ENUM (NSInteger, SMErrorType) {
    SMErrorTypeUnknown NS_SWIFT_NAME(unknown),
    SMErrorTypeNetwork NS_SWIFT_NAME(network),
    SMErrorTypeValidation NS_SWIFT_NAME(validation),
    SMErrorTypeServerError NS_SWIFT_NAME(server),
    SMErrorTypeAuthentication NS_SWIFT_NAME(authentication),
    SMErrorTypeWebView NS_SWIFT_NAME(webView),
    SMErrorTypeInvalidState NS_SWIFT_NAME(invalidState)
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
 @abstract Converts specified string value to the corresponding <code>SMErrorType</code> enum value.
 @param string String to convert.
 @result <code>SMErrorType</code> enum value.
 */
+ (SMErrorType)errorTypeForString:(NSString *)string NS_SWIFT_NAME(errorType(from:));
/*!
 @abstract Converts specified <code>SMErrorType</code> enum value to the corresponding string value.
 @param type Error type to convert.
 @result <code>NSString</code> value.
 */
+ (NSString *)stringForErrorType:(SMErrorType)type NS_SWIFT_NAME(string(from:));

/*!
 @const SMErrorNetworkIssue
 @abstract Indicates that the network connection is down.
 */
extern NSString * const SMErrorNetworkIssue NS_SWIFT_NAME(networkErrorCannotProcess);

/*!
 @const SMErrorServerIssue
 @abstract Indicates that error occurred due to server processing failure.
 */
extern NSString * const SMErrorServerIssue NS_SWIFT_NAME(serverErrorCannotProcess);
/*!
 @const SMErrorServerBadJson
 @abstract Indicates that error occurred due to malformed JSON in the request body.
 */
extern NSString * const SMErrorServerBadJson NS_SWIFT_NAME(serverErrorBadJSON);
/*!
 @const SMErrorServerBadRequest
 @abstract Indicates that error occurred due to malformed request data.
 */
extern NSString * const SMErrorServerBadRequest NS_SWIFT_NAME(serverErrorBadRequest);
/*!
 @const SMErrorServerUnauthorized
 @abstract Indicates that the user is not authenticated.
 */
extern NSString * const SMErrorServerUnauthorized NS_SWIFT_NAME(serverErrorUnauthorized);
/*!
 @const SMErrorServerPathNotFound
 @abstract Indicates that error occurred due to a 404 "not found" HTTP response status.
 */
extern NSString * const SMErrorServerPathNotFound NS_SWIFT_NAME(serverErrorPathNotFound);
/*!
 @const SMErrorServerNotAcceptable
 @abstract Indicates that error occurred due to an invalid user session.
 */
extern NSString * const SMErrorServerNotAcceptable NS_SWIFT_NAME(serverErrorNotAcceptable);
/*!
 @const SMErrorServerRequestTimedOut
 @abstract Indicates that error occurred due to a request timeout.
 */
extern NSString * const SMErrorServerRequestTimedOut NS_SWIFT_NAME(serverErrorRequestTimedOut);
/*!
 @const SMErrorServerUserNotFound
 @abstract Indicates that error occurred due to the current user not being found in the SessionM Platform.
 */
extern NSString * const SMErrorServerUserNotFound NS_SWIFT_NAME(serverErrorUserNotFound);
/*!
 @const SMErrorServerOfferNotFound
 @abstract Indicates that the specified offer could not be found by the SessionM Platform.
 */
extern NSString * const SMErrorServerOfferNotFound NS_SWIFT_NAME(serverOfferNotFound);

/*!
 @const SMErrorAuthenticateNoAuthenticationProvider
 @abstract Indicates that the OAuth identity provider has not been set.
 */
extern NSString * const SMErrorAuthenticateNoAuthenticationProvider NS_SWIFT_NAME(noAuthenticationProvider);

/*!
 @const SMErrorNotAuthorized401
 @abstract Indicates that the user is not authenticated.
 */
extern NSString * const SMErrorNotAuthorized401 NS_SWIFT_NAME(notAuthorized401);
/*!
 @const SMErrorPathNotFound404
 @abstract Indicates that error occurred due to a 404 "not found" HTTP response status.
 */
extern NSString * const SMErrorPathNotFound404 NS_SWIFT_NAME(pathNotFound404);
/*!
 @const SMErrorNotAcceptable406
 @abstract Indicates that error occurred due to an invalid user session.
 */
extern NSString * const SMErrorNotAcceptable406 NS_SWIFT_NAME(notAcceptable406);
/*!
 @const SMErrorServerTimeout408
 @abstract Indicates that error occurred due to a request timeout.
 */
extern NSString * const SMErrorServerTimeout408 NS_SWIFT_NAME(serverTimeout408);
/*!
 @const SMErrorServer4xx
 @abstract Indicates that request failed with an HTTP response status in the 400s.
 */
extern NSString * const SMErrorServer4xx NS_SWIFT_NAME(server4xx);
/*!
 @const SMErrorServer5xx
 @abstract Indicates that request failed with an HTTP response status in the 500s.
 */
extern NSString * const SMErrorServer5xx NS_SWIFT_NAME(server5xx);
/*!
 @const SMErrorServer6xx
 @abstract Indicates that request failed with an HTTP response status in the 600s.
 */
extern NSString * const SMErrorServer6xx NS_SWIFT_NAME(server6xx);

/*!
 @const SMErrorNoChange
 @abstract Indicates that the SDK was not able to initialize a new user session.
 */
extern NSString * const SMErrorNoChange NS_SWIFT_NAME(noChange);

/*!
 @const SMErrorConfigNotLoaded
 @abstract Indicates that app configuration is not loaded.
 */
extern NSString * const SMErrorConfigNotLoaded NS_SWIFT_NAME(configNotLoaded);

/*!
 @const SMErrorAuthenticationFail
 @abstract Indicates that the current user's access token is invalid.
 */
extern NSString * const SMErrorAuthenticationFail NS_SWIFT_NAME(authenticateFail);
/*!
 @const SMErrorValidationNoUpdates
 @abstract Indicates that no user updates were specified for an <code>updateUser:completionHandler:</code> call.
 */
extern NSString * const SMErrorValidationNoUpdates NS_SWIFT_NAME(validationErrorNoUpdates);
/*!
 @const SMErrorValidationNoCreate
 @abstract Indicates that no user creation data was specified for a <code>createUser:completionHandler:</code> call.
 */
extern NSString * const SMErrorValidationNoCreate NS_SWIFT_NAME(validationErrorCreate);
/*!
 @const SMErrorValidationNoToken
 @abstract Indicates that no authentication token was specified for an <code>authenticateUserWithToken:provider:completionHandler:</code> call.
 */
extern NSString * const SMErrorValidationNoToken NS_SWIFT_NAME(validationErrorNoToken);
/*!
 @const SMErrorValidationNoProvider
 @abstract Indicates that no authentication provider was specified for an <code>authenticateUserWithToken:provider:completionHandler:</code> call.
 */
extern NSString * const SMErrorValidationNoProvider NS_SWIFT_NAME(validationErrorNoProvider);
/*!
 @const SMErrorValidationNoEmailPassword
 @abstract Indicates that either no email or password was specified for an <code>authenticateUserWithEmail:password:completionHandler:</code> call.
 */
extern NSString * const SMErrorValidationNoEmailPassword NS_SWIFT_NAME(validationErrorNoEmailPassword);
/*!
 @const SMErrorServiceOAuthNotAuthenticated
 @abstract Indicates that an auth code could not be fetched for the current user.
 */
extern NSString * const SMErrorServiceOAuthNotAuthenticated NS_SWIFT_NAME(serviceErrorOAuthNotAuthenticated);
/*!
 @const SMErrorValidationInvalidOAuthServiceConfiguration
 @abstract Indicates that the app's OAuth service configuration is invalid.
 */
extern NSString * const SMErrorValidationInvalidOAuthServiceConfiguration NS_SWIFT_NAME(validationErrorInvalidOAuthServiceConfiguration);
/*!
 @const SMErrorNoAccessToken
 @abstract Indicates that the current user has no access token.
 */
extern NSString * const SMErrorNoAccessToken NS_SWIFT_NAME(errorNoAccessToken);
/*!
 @const SMErrorValidationNoPhone
 @abstract Indicates that no phone number was specified for a <code>sendSMSVerificationMessageToPhoneNumber:completionHandler:</code> call.
 */
extern NSString * const SMErrorValidationNoPhone NS_SWIFT_NAME(validationErrorNoPhone);
/*!
 @const SMErrorValidationNoCode
 @abstract Indicates that no verification code was specified for a <code>checkSMSVerificationCode:completionHandler:</code> call.
 */
extern NSString * const SMErrorValidationNoCode NS_SWIFT_NAME(validationErrorNoCode);
/*!
 @const SMErrorValidationNoCardNumber
 @abstract Indicates that no loyalty card number was specified for a <code>linkLoyaltyCardNumber:retailer:completionHandler:</code> call.
 */
extern NSString * const SMErrorValidationNoCardNumber NS_SWIFT_NAME(validationErrorNoCardNumber);
/*!
 @const SMErrorValidationNoCardID
 @abstract Indicates that no loyalty card ID was specified for an <code>unlinkLoyaltyCardID:completionHandler:</code> call.
 */
extern NSString * const SMErrorValidationNoCardID NS_SWIFT_NAME(validationErrorNoCardID);
/*!
 @const SMErrorValidationNoRetailerID
 @abstract Indicates that no retailer ID was specified for a <code>linkLoyaltyCardNumber:retailer:completionHandler:</code> call.
 */
extern NSString * const SMErrorValidationNoRetailerID NS_SWIFT_NAME(validationErrorNoRetailerID);
/*!
 @const SMErrorValidationGenericRequest
 @abstract Indicates that an invalid request was specified for a <code>sendRequest:completionHandler:</code> call.
 */
extern NSString * const SMErrorValidationGenericRequest NS_SWIFT_NAME(validationGenericRequest);
/*!
 @const SMErrorValidationNoLocation
 @abstract Indicates that no location was specified for a <code>fetchPlacesAroundLocation:completionHandler:</code> call.
 */
extern NSString * const SMErrorValidationNoLocation NS_SWIFT_NAME(validationErrorNoLocation);
/*!
 @const SMErrorValidationNoPlace
 @abstract Indicates that no place data was specified for a <code>checkInPlace:completionHandler:</code> call.
 */
extern NSString * const SMErrorValidationNoPlace NS_SWIFT_NAME(validationErrorNoPlace);
/*!
 @const SMErrorValidationNoPlaceID
 @abstract Indicates that no place ID was specified for a <code>checkInPlace:completionHandler:</code> call.
 */
extern NSString * const SMErrorValidationNoPlaceID NS_SWIFT_NAME(validationErrorNoPlaceID);
/*!
 @const SMErrorValidationNoPaths
 @abstract Indicates that no file paths were specified for an <code>uploadReceiptImageFiles:withCampaignID:placementID:data::completionHandler:progressHandler:</code> call.
 */
extern NSString * const SMErrorValidationNoPaths NS_SWIFT_NAME(validationErrorNoPaths);
/*!
 @const SMErrorValidationNoCampaignID
 @abstract Indicates that no campaign ID was specified for an <code>uploadReceiptImageFiles:withCampaignID:placementID:data::completionHandler:progressHandler:</code> or <code>uploadReceiptImages:withCampaignID:placementID:data::completionHandler:progressHandler:</code> call.
 */
extern NSString * const SMErrorValidationNoCampaignID NS_SWIFT_NAME(validationErrorNoCampaignID);
/*!
 @const SMErrorValidationNoAssetIDs
 @abstract Indicates that no asset IDs were specified for an <code>uploadReceiptImages:withCampaignID:placementID:data::completionHandler:progressHandler:</code> call.
 */
extern NSString * const SMErrorValidationNoAssetIDs NS_SWIFT_NAME(validationErrorNoAssetIDs);
/*!
 @const SMErrorValidationBadGroupID
 @abstract Indicates that an invalid group ID was specified for a <code>resumeIncompleteUploadForGroupID:completionHandler:progressHandler:</code> call.
 */
extern NSString * const SMErrorValidationBadGroupID NS_SWIFT_NAME(validationErrorBadGroupID);
/*!
 @const SMErrorValidationNoGroupID
 @abstract Indicates that a group ID could not be created for a group of receipt images during upload.
 */
extern NSString * const SMErrorValidationNoGroupID NS_SWIFT_NAME(validationErrorNoGroupID);
/*!
 @const SMErrorValidationBadUploadData
 @abstract Indicates that invalid upload data was specified for a <code>resumeIncompleteUploadForGroupID:completionHandler:progressHandler:</code> call.
 */
extern NSString * const SMErrorValidationBadUploadData NS_SWIFT_NAME(validationErrorBadUploadData);
/*!
 @const SMErrorValidationInvalidReferral
 @abstract Indicates that invalid referral data was specified for a <code>sendReferrals:completionHandler:</code> call.
 */
extern NSString * const SMErrorValidationInvalidReferral NS_SWIFT_NAME(validationErrorInvalidReferral);
/*!
 @const SMErrorValidationInvalidEmail
 @abstract Indicates that an invalid email was specified for a <code>sendReferrals:completionHandler:</code> call.
 */
extern NSString * const SMErrorValidationInvalidEmail NS_SWIFT_NAME(validationErrorInvalidEmail);
/*!
 @const SMErrorValidationDuplicateEmail
 @abstract Indicates that a duplicate email was specified for a <code>sendReferrals:completionHandler:</code> call.
 */
extern NSString * const SMErrorValidationDuplicateEmail NS_SWIFT_NAME(validationErrorDuplicateEmail);
/*!
 @const SMErrorValidationNoReferral
 @abstract Indicates that no referral data was specified for a <code>sendReferrals:completionHandler:</code> call.
 */
extern NSString * const SMErrorValidationNoReferral NS_SWIFT_NAME(validationErrorNoReferral);
/*!
 @const SMErrorValidationNoReferralID
 @abstract Indicates that no referral ID was specified for a <code>fetchReferralWithID:completionHandler:</code> call.
 */
extern NSString * const SMErrorValidationNoReferralID NS_SWIFT_NAME(validationErrorNoReferralID);
/*!
 @const SMErrorValidationNoOfferID
 @abstract Indicates that no offer ID was specified for a <code>purchaseOfferWithID:quantity:completionHandler:</code>, <code>claimUserOfferWithID:completionHandler:</code> or <code>answerSkillQuestionForOfferID:questionID:answer:completionHandler:</code> call.
 */
extern NSString * const SMErrorValidationNoOfferID NS_SWIFT_NAME(validationErrorNoOfferID);
/*!
 @const SMErrorValidationNoOrderRequest
 @abstract Indicates that no order request was specified for a <code>placeOrder:completionHandler:</code> call.
 */
extern NSString * const SMErrorValidationNoOrderRequest NS_SWIFT_NAME(validationErrorNoOrderRequest);
/*!
 @const SMErrorValidationNoQuestionID
 @abstract Indicates that no question ID was specified for an <code>answerSkillQuestionForOfferID:questionID:answer:completionHandler:</code> call.
 */
extern NSString * const SMErrorValidationNoQuestionID NS_SWIFT_NAME(validationErrorNoQuestionID);
/*!
 @const SMErrorValidationNoAnswer
 @abstract Indicates that no answer was specified for an <code>answerSkillQuestionForOfferID:questionID:answer:completionHandler:</code> call.
 */
extern NSString * const SMErrorValidationNoAnswer NS_SWIFT_NAME(validationErrorNoAnswer);
/*!
 @const SMErrorValidationBadDates
 @abstract Indicates that invalid start and end dates were specified when fetching transactions.
 */
extern NSString * const SMErrorValidationBadDates NS_SWIFT_NAME(validationErrorBadDates);
/*!
 @const SMErrorValidationNoMessageID
 @abstract Indicates that no message ID was specified for an <code>updateInboxMessageID:state:completionHandler:</code> or <code>updateInboxMessageIDs:state:completionHandler:</code> call.
 */
extern NSString * const SMErrorValidationNoMessageID NS_SWIFT_NAME(validationErrorNoMessageID);
/*!
 @const SMErrorValidationNoMessage
 @abstract Indicates that no message data was specified for a <code>createInboxMessage:completionHandler:</code> call.
 */
extern NSString * const SMErrorValidationNoMessage NS_SWIFT_NAME(validationErrorNoMessage);
/*!
 @const SMErrorValidationNoLocationPermission
 @abstract Indicates that the user has not provided access to their location data.
 */
extern NSString * const SMErrorValidationNoLocationPermission NS_SWIFT_NAME(validationErrorNoLocationPermission);
/*!
 @const SMErrorValidationNoWhenInUseLocationPermission
 @abstract Indicates that the user has not provided access to their location data while the app is in use.
 */
extern NSString * const SMErrorValidationNoWhenInUseLocationPermission NS_SWIFT_NAME(validationErrorNoWhenInUseLocationPermission);
/*!
 @const SMErrorInvalidStateConfigFile
 @abstract Indicates that the SDK could not parse the specified config file when attempting to load configuration data.
 */
extern NSString * const SMErrorInvalidStateConfigFile NS_SWIFT_NAME(invalidStateConfigFile);
/*!
 @const SMErrorMissingConfigFile
 @abstract Indicates that the SDK could not locate the specified config file when attempting to load configuration data.
 */
extern NSString * const SMErrorMissingConfigFile NS_SWIFT_NAME(missingConfigFile);
/*!
 @const SMErrorInvalidStateMissingServerURL
 @abstract Indicates that the SDK did not find a server URL when attempting to load configuration data.
 */
extern NSString * const SMErrorInvalidStateMissingServerURL NS_SWIFT_NAME(invalidStateMissingServerURL);
/*!
 @const SMErrorInvalidStateMissingAppKey
 @abstract Indicates that the SDK did not find an API key when attempting to load configuration data.
 */
extern NSString * const SMErrorInvalidStateMissingAppKey NS_SWIFT_NAME(invalidStateMissingAppKey);
/*!
 @const SMErrorWebViewPageNotLoaded
 @abstract Indicates that the SDK web profile manager failed to load the specified web page.
 */
extern NSString * const SMErrorWebViewPageNotLoaded;

/*!
 @const SMErrorWebViewJSIssue
 @abstract Indicates that the SDK web view could not evaluate a JavaScript string.
 */
extern NSString * const SMErrorWebViewJSIssue;

/*!
 @const SMErrorJSBridgeNoHandler
 @abstract Indicates that no handler name was provided in the specified JSBridge message.
 */
extern NSString * const SMErrorJSBridgeNoHandler NS_SWIFT_NAME(jsBridgeNoHandler);
/*!
 @const SMErrorJSBridgeNoMessage
 @abstract Indicates that no data was provided in the specified JSBridge message.
 */
extern NSString * const SMErrorJSBridgeNoMessage NS_SWIFT_NAME(jsBridgeNoMessage);
/*!
 @const SMErrorJSBridgeHandlerIssue
 @abstract Indicates that an invalid handler name was provided in the specified JSBridge message.
 */
extern NSString * const SMErrorJSBridgeHandlerIssue NS_SWIFT_NAME(jsBridgeHandlerIssue);
/*!
 @const SMErrorJSBridgeJSCallIssue
 @abstract Indicates that invalid data was provided in the specified JSBridge message.
 */
extern NSString * const SMErrorJSBridgeJSCallIssue NS_SWIFT_NAME(jsBridgeJSCallIssue);

/*!
 @const SMErrorInternalError
 @abstract Indicates that an internal SDK error occurred.
 */
extern NSString * const SMErrorInternalError NS_SWIFT_NAME(errorInternalError);

/*!
 @const SMErrorUnknownCode
 @abstract Indicates that error occurred for an unknown reason.
 */
extern NSString * const SMErrorUnknownCode NS_SWIFT_NAME(unknownCode);
/*!
 @const SMErrorUnknownMessage
 @abstract Indicates that error occurred for an unknown reason.
 */
extern NSString * const SMErrorUnknownMessage NS_SWIFT_NAME(unknownMessage);

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_ERROR__ */
