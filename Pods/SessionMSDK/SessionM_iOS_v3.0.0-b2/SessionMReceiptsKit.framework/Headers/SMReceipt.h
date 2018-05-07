//
//  SMReceipt.h
//  SessionMReceiptsKit
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SM_RECEIPT__
#define __SM_RECEIPT__

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @typedef SMReceiptStatus
 @abstract Receipt upload status.

 @constant SMReceiptStatusUnknown Upload status is unknown.
 @constant SMReceiptStatusPending Upload is pending review.
 @constant SMReceiptStatusValid Upload was approved.
 @constant SMReceiptStatusInvalid Upload was rejected.
 @constant SMReceiptStatusIncomplete Multiple image upload is partially finished.
 */
typedef NS_ENUM(NSInteger, SMReceiptStatus) {
    SMReceiptStatusUnknown NS_SWIFT_NAME(unknown),
    SMReceiptStatusPending NS_SWIFT_NAME(pending),
    SMReceiptStatusValid NS_SWIFT_NAME(valid),
    SMReceiptStatusInvalid NS_SWIFT_NAME(invalid),
    SMReceiptStatusIncomplete NS_SWIFT_NAME(incomplete)
};


/*!
 @class SMReceiptResult
 @abstract Defines the purchase data for an item on a receipt.
 */
@interface SMReceiptResult : NSObject

/*!
 @property resultID
 @abstract Unique ID for result.
 @discussion This ID will be equal to <code>SMTransaction recordModelID</code> in the corresponding transaction record.
 */
@property(nonnull, nonatomic, strong, readonly) NSString *resultID;
/*!
 @property name
 @abstract Item name.
 */
@property(nullable, nonatomic, strong, readonly) NSString *name;
/*!
 @property details
 @abstract Item description.
 */
@property(nullable, nonatomic, strong, readonly) NSString *details;
/*!
 @property descriptionText
 @abstract Item description.
 @deprecated This property has been deprecated - use <code>details</code> instead.
 */
@property(nullable, nonatomic, strong, readonly) NSString *descriptionText __attribute__((deprecated));
/*!
 @property price
 @abstract Individual item price.
 */
@property(nonatomic, assign, readonly) float price;
/*!
 @property quantity
 @abstract Amount of item purchased.
 */
@property(nonatomic, assign, readonly) NSInteger quantity;
/*!
 @property points
 @abstract Amount of points user earned for uploading the receipt.
 */
@property(nonatomic, assign, readonly) NSInteger points;
/*!
 @property extras
 @abstract Any data values that do not have an associated class property.
 */
@property(nullable, nonatomic, strong, readonly) NSDictionary<NSString *, id> *extras;

@end


/*!
 @class SMReceipt
 @abstract Defines the data associated with a receipt uploaded by the user.
 */
@interface SMReceipt : NSObject

/*!
 @property receiptID
 @abstract Unique ID for receipt.
 */
@property(nonnull, nonatomic, strong, readonly) NSString *receiptID;
/*!
 @property campaignID
 @abstract ID of promotional campaign associated with the receipt.
 */
@property(nullable, nonatomic, strong, readonly) NSString *campaignID;
/*!
 @property placementID
 @abstract ID of receipt placement.
 */
@property(nullable, nonatomic, strong, readonly) NSString *placementID;
/*!
 @property userID
 @abstract ID of user that uploaded the receipt images.
 */
@property(nullable, nonatomic, strong, readonly) NSString *userID;
/*!
 @property groupID
 @abstract ID used to identify partially-finished multiple image upload.
 */
@property(nullable, nonatomic, strong, readonly) NSString *groupID;
/*!
 @property invalidCode
 @abstract Error code for a rejected receipt upload.
 @discussion <ul>
    <li>0 Unknown</li>
    <li>1 Receipt cannot be read clearly</li>
    <li>2 Receipt is cropped</li>
    <li>3 Receipt submitted twice</li>
    <li>4 Receipt processing unavailable</li>
    <li>5 Image is not a receipt</li>
    <li>6 No valid purchases found</li>
    <li>7 Purchases are from a non-qualifying store</li>
    <li>8 Image cannot be read clearly</li>
    <li>9 Image is unrelated to campaign</li>
    <li>10 Image submitted twice</li>
    <li>11 Image processing unavailable</li>
    <li>12 Image has no valid purchases found, similar to 6</li>
    <li>13 Multiple submissions not allowed for this campaign</li>
 </ul>
 */
@property(nonatomic, assign, readonly) NSInteger invalidCode;
/*!
 @property invalidReason
 @abstract Explains why a receipt upload was rejected.
 */
@property(nullable, nonatomic, strong, readonly) NSString *invalidReason;
/*!
 @property imageCount
 @abstract Number of images uploaded for the receipt.
 */
@property(nonatomic, assign, readonly) NSInteger imageCount;
/*!
 @property imageURLs
 @abstract URLs of uploaded receipt images.
 */
@property(nullable, nonatomic, strong, readonly) NSArray<NSString *> *imageURLs;
/*!
 @property createdTime
 @abstract Indicates when receipt data was created.
 */
@property(nullable, nonatomic, strong, readonly) NSString *createdTime;
/*!
 @property updatedTime
 @abstract Indicates when receipt data was last updated.
 */
@property(nullable, nonatomic, strong, readonly) NSString *updatedTime;
/*!
 @property status
 @abstract Receipt upload status.
 */
@property(nonatomic, assign, readonly) SMReceiptStatus status;
/*!
 @property results
 @abstract Returns results of processing receipt images for purchase data.
 @discussion Each array element represents purchase data for a single item.
 */
@property(nullable, nonatomic, strong, readonly) NSArray<SMReceiptResult *> *results;
/*!
 @property storeName
 @abstract The name of the store from which the receipt was issued.
 */
@property(nullable, nonatomic, strong, readonly) NSString *storeName;
/*!
 @property receiptDate
 @abstract The date on which the receipt was issued.
 */
@property(nullable, nonatomic, strong, readonly) NSString *receiptDate;
/*!
 @property extras
 @abstract Any data values that do not have an associated class property.
 */
@property(nullable, nonatomic, strong, readonly) NSDictionary<NSString *, id> *extras;

/*!
 @abstract Converts specified string value to the corresponding <code>SMReceiptStatus</code> enum value.
 @param string String to convert.
 @result <code>SMReceiptStatus</code> enum value.
 */
+ (SMReceiptStatus)statusForString:(NSString *)string NS_SWIFT_NAME(receiptStatus(from:));
/*!
 @abstract Converts specified <code>SMReceiptStatus</code> enum value to the corresponding string value.
 @param status Status to convert.
 @result <code>NSString</code> value.
 */
+ (NSString *)stringForStatus:(SMReceiptStatus)status NS_SWIFT_NAME(string(from:));

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_RECEIPT__ */
