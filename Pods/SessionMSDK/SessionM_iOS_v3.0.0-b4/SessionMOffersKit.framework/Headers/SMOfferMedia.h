//
//  SMOfferMedia.h
//  SessionMOffersKit
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SM_OFFER_MEDIA__
#define __SM_OFFER_MEDIA__

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @typedef SMOfferMediaContentType
 @abstract Defines the type of media content pointed to by <code>uri</code>.

 @constant SMOfferMediaContentTypeImage Image content.
 @constant SMOfferMediaContentTypeVideo Video content.
 @constant SMOfferMediaContentTypeAudio Audio content.
 @constant SMOfferMediaContentTypeWebLink Web content.
 */
typedef NS_ENUM(NSInteger, SMOfferMediaContentType) {
    SMOfferMediaContentTypeImage NS_SWIFT_NAME(image) = 1,
    SMOfferMediaContentTypeVideo NS_SWIFT_NAME(video) = 2,
    SMOfferMediaContentTypeAudio NS_SWIFT_NAME(audio) = 4,
    SMOfferMediaContentTypeWebLink NS_SWIFT_NAME(webLink) = 5
};

/*!
 @class SMOfferMedia
 @abstract Defines the data associated with a loyalty offer's media content.
 */
@interface SMOfferMedia : NSObject

/*!
 @property offerMediaID
 @abstract Unique identifier for offer media content.
 */
@property(nonatomic, strong, readonly) NSString *offerMediaID;
/*!
 @property offerCategoryID
 @abstract Identifier of the offer category to which the media content belongs.
 */
@property(nonatomic, strong, readonly) NSString *offerCategoryID;
/*!
 @property categoryName
 @abstract Name of the offer category to which the media content belongs.
 */
@property(nonatomic, strong, readonly) NSString *categoryName;
/*!
 @property uri
 @abstract Media content URI.
 */
@property(nonatomic, strong, readonly) NSString *uri;
/*!
 @property contentType
 @abstract Type of media content pointed to by <code>uri</code>.
 */
@property(nonatomic, assign, readonly) SMOfferMediaContentType contentType;
/*!
 @property extras
 @abstract Any data values that do not have an associated class property.
 */
@property(nullable, nonatomic, strong, readonly) NSDictionary<NSString *, id> *extras;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_OFFER_MEDIA__ */
