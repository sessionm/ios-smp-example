//
//  SMReceiptsManager.h
//  SessionMReceiptsKit
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SM_RECEIPTS_MANAGER__
#define __SM_RECEIPTS_MANAGER__

#import <SessionMCoreKit/SMBaseManager.h>
#import <SessionMCoreKit/SMError.h>

#import "SMReceipt.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @const SM_RECEIPTS_MANAGER_REQUEST_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that an API request failed.
 @discussion An <code>SMError</code> object containing information about why the request failed can be accessed from the notification's <code>userInfo</code> property with the <code>SM_MANAGER_NOTIFICATION_ERROR_KEY</code> key.
 */
extern NSString *const SM_RECEIPTS_MANAGER_REQUEST_DID_FAIL_NOTIFICATION NS_SWIFT_NAME(receiptsRequestFailureNotification);
/*!
 @const SM_RECEIPTS_MANAGER_VALIDATION_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that a Receipts API validation failed.
 @discussion An <code>SMError</code> object containing information about why the validation failed can be accessed from the notification's <code>userInfo</code> property with the <code>SM_MANAGER_NOTIFICATION_ERROR_KEY</code> key.
 */
extern NSString *const SM_RECEIPTS_MANAGER_VALIDATION_DID_FAIL_NOTIFICATION NS_SWIFT_NAME(receiptsValidationFailureNotification);

/*!
 @const SM_RECEIPTS_MANAGER_UPLOAD_PROGRESS_NOTIFICATION
 @abstract Notifies observers that an image was successfully uploaded.
 @discussion An <code>SMReceipt</code> object representing the current receipt data can be accessed from the notification's <code>userInfo</code> property with the <code>SM_MANAGER_NOTIFICATION_DATA_KEY</code> key.
 */
extern NSString *const SM_RECEIPTS_MANAGER_UPLOAD_PROGRESS_NOTIFICATION NS_SWIFT_NAME(receiptUploadProgressNotification);
/*!
 @const SM_RECEIPTS_MANAGER_DID_UPLOAD_RECEIPT_NOTIFICATION
 @abstract Notifies observers that all receipt images were successfully uploaded.
 @discussion An <code>SMReceipt</code> object representing the final receipt data can be accessed from the notification's <code>userInfo</code> property with the <code>SM_MANAGER_NOTIFICATION_DATA_KEY</code> key.
 */
extern NSString *const SM_RECEIPTS_MANAGER_DID_UPLOAD_RECEIPT_NOTIFICATION NS_SWIFT_NAME(uploadedReceiptNotification);
/*!
 @const SM_RECEIPTS_MANAGER_DID_FETCH_RECEIPTS_NOTIFICATION
 @abstract Notifies observers that the current user's uploaded receipts were fetched.
 @discussion An <code>NSArray</code> object representing the uploaded receipts can be accessed from the notification's <code>userInfo</code> property with the <code>SM_MANAGER_NOTIFICATION_DATA_KEY</code> key.
 */
extern NSString *const SM_RECEIPTS_MANAGER_DID_FETCH_RECEIPTS_NOTIFICATION NS_SWIFT_NAME(fetchedReceiptsNotification);


/*!
 @typedef uploadProgress
 @abstract Progress handler block type for <code>uploadReceiptImages:withCampaignID:placementID:data:completionHandler:progressHandler:</code>, <code>uploadReceiptImageFiles:withCampaignID:placementID:data:completionHandler:progressHandler:</code> and <code>resumeIncompleteUploadForGroupID:completionHandler:progressHandler:</code>.
 */
typedef void (^uploadProgress)(SMReceipt * _Nullable receipt, SMError * _Nullable error) NS_SWIFT_NAME(UploadProgressHandler);
/*!
 @typedef didUploadReceipt
 @abstract Completion handler block type for <code>uploadReceiptImages:withCampaignID:placementID:data:completionHandler:progressHandler:</code>, <code>uploadReceiptImageFiles:withCampaignID:placementID:data:completionHandler:progressHandler:</code> and <code>resumeIncompleteUploadForGroupID:completionHandler:progressHandler:</code>.
 */
typedef void (^didUploadReceipt)(SMReceipt * _Nullable receipt, SMError * _Nullable error) NS_SWIFT_NAME(UploadReceiptCompletionHandler);
/*!
 @typedef didFetchReceipts
 @abstract Completion handler block type for <code>fetchReceiptsWithCompletionHandler:</code> and <code>fetchReceiptsWithLimit:page:completionHandler:</code>.
 */
typedef void (^didFetchReceipts)(NSArray<SMReceipt *> * _Nullable receipts, SMError * _Nullable error) NS_SWIFT_NAME(FetchReceiptsCompletionHandler);


/*!
 @class SMReceiptsManager
 @abstract This API manager contains methods for uploading receipt images and fetching uploaded receipt data.
 */
@interface SMReceiptsManager : SMBaseManager

/*!
 @property receipts
 @abstract The current user's uploaded receipts.
 @discussion This property is updated in response to a successful <code>fetchReceiptsWithCompletionHandler:</code> or <code>fetchReceiptsWithLimit:page:completionHandler:</code> call.
 */
@property(nonatomic, strong, readonly) NSArray<SMReceipt *> *receipts;

/*!
 @abstract Returns identifiers for the current user's incomplete receipt uploads (uploads from other users will be removed).
 @discussion An element of the returned array can be used as input for <code>resumeIncompleteUploadForGroupID:completionHandler:progressHandler:</code> or <code>removeIncompleteUploadForGroupID:</code>.
 @result <code>NSArray</code> of upload identifiers.
 */
- (NSArray<NSString *> *)incompleteUploadGroupIDs NS_SWIFT_NAME(groupIDsForIncompleteUploads());
/*!
 @abstract Returns identifiers for the current user's incomplete receipt uploads.
 @discussion An element of the returned array can be used as input for <code>resumeIncompleteUploadForGroupID:completionHandler:progressHandler:</code> or <code>removeIncompleteUploadForGroupID:</code>.
 @param keepOtherUploads Flag indicating if uploads from other users should be kept.
 @result <code>NSArray</code> of upload identifiers.
 */
- (NSArray<NSString *> *)incompleteUploadGroupIDsAndKeepOtherUsers:(BOOL)keepOtherUploads NS_SWIFT_NAME(groupIDsForIncompleteUploads(shouldKeepUploadsForOtherUsers:));

/*!
 @abstract Makes a request to remove all incomplete receipt uploads from storage.
 @discussion All group IDs are removed from <code>incompleteUploadGroupIDs</code> on success.
 */
- (void)removeAllIncompleteUploads;
/*!
 @abstract Makes a request to remove the incomplete receipt upload with the specified group ID from storage.
 @discussion Group ID is removed from <code>incompleteUploadGroupIDs</code> on success.
 @param groupID ID of receipt upload that will be removed.
 */
- (void)removeIncompleteUploadForGroupID:(NSString *)groupID NS_SWIFT_NAME(removeIncompleteUpload(havingGroupID:));

/*!
 @abstract Uploads the receipt images with the specified asset identifiers for the specified campaign.
 @param assetIDs Array of <code>PHObject</code> <code>localIdentifier</code> strings.
 @param campaignID ID of promotional campaign for which receipt is being uploaded.
 @param placementID ID of receipt placement (optional).
 @param data Custom, developer-defined data associated with the receipt (optional).
 @param completionHandler The block to execute after all images are uploaded.
 @param progressHandler The block to execute after each image is uploaded.
 @result Returns upload group ID on success (returns nil otherwise).
 */
- (NSString * _Nullable)uploadReceiptImages:(NSArray<NSString *> *)assetIDs withCampaignID:(NSString *)campaignID placementID:(NSString * _Nullable)placementID
                                       data:(NSDictionary<NSString *, id> * _Nullable)data completionHandler:(didUploadReceipt)completionHandler progressHandler:(uploadProgress)progressHandler NS_SWIFT_NAME(uploadImages(havingAssetIDs:campaignID:placementID:data:completionHandler:progressHandler:));
/*!
 @abstract Uploads the receipt images with the specified file paths for the specified campaign.
 @param paths Array of image file paths.
 @param campaignID ID of promotional campaign for which receipt is being uploaded.
 @param placementID ID of receipt placement (optional).
 @param data Custom, developer-defined data associated with the receipt (optional).
 @param completionHandler The block to execute after all images are uploaded.
 @param progressHandler The block to execute after each image is uploaded.
 @result Returns upload group ID on success (returns <code>nil</code> otherwise).
 */
- (NSString * _Nullable)uploadReceiptImageFiles:(NSArray<NSString *> *)paths withCampaignID:(NSString *)campaignID placementID:(NSString * _Nullable)placementID
                                           data:(NSDictionary<NSString *, id> * _Nullable)data completionHandler:(didUploadReceipt)completionHandler progressHandler:(uploadProgress)progressHandler NS_SWIFT_NAME(uploadImageFiles(atPaths:campaignID:placementID:data:completionHandler:progressHandler:));
/*!
 @abstract Resumes the incomplete receipt upload with the specified group ID.
 @param groupID ID of receipt upload that will be resumed.
 @param completionHandler The block to execute after all images are uploaded.
 @param progressHandler The block to execute after each image is uploaded.
 @result Returns upload group ID on success (returns <code>nil</code> otherwise).
 */
- (NSString * _Nullable)resumeIncompleteUploadForGroupID:(NSString *)groupID completionHandler:(didUploadReceipt)completionHandler progressHandler:(uploadProgress)progressHandler NS_SWIFT_NAME(resumeUpload(havingGroupID:completionHandler:progressHandler:));

/*!
 @abstract Makes a request to update <code>receipts</code> with the current user's uploaded receipts.
 @param completionHandler The block to execute after the request is processed.
 */
- (void)fetchReceiptsWithCompletionHandler:(didFetchReceipts)completionHandler NS_SWIFT_NAME(fetchReceipts(completionHandler:));
/*!
 @abstract Makes a request to update <code>receipts</code> with a limited number of the current user's uploaded receipts.
 @param limit The maximum amount of receipts to fetch (optional).
 @param page <code>limit * (page-1)</code> most recent receipt records will be skipped for the fetch (optional).
 @param completionHandler The block to execute after the request is processed.
 */
- (void)fetchReceiptsWithLimit:(int)limit page:(int)page completionHandler:(didFetchReceipts)completionHandler NS_SWIFT_NAME(fetchReceipts(limit:page:completionHandler:));

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_RECEIPTS_MANAGER__ */
