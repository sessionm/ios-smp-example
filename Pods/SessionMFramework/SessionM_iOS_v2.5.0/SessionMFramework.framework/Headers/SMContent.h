//
//  SMContent.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef __SM_CONTENT__
#define __SM_CONTENT__

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @typedef SMContentState
 @abstract Content development state.

 @constant SMContentStateUnknown Content state is unknown.
 @constant SMContentStateLive Content is live and should be made visible to users.
 @constant SMContentStatePreview Content is in development and should not be made visible to users.
 */
typedef NS_ENUM (NSInteger, SMContentState) {
    SMContentStateUnknown NS_SWIFT_NAME(unknown),
    SMContentStateLive NS_SWIFT_NAME(live),
    SMContentStatePreview NS_SWIFT_NAME(preview)
};


/*!
 @class SMContent
 @abstract Defines the data associated with a promotional item in a content feed.
 */
@interface SMContent : NSObject
/*!
 @property contentID
 @abstract Unique ID for content.
 */
@property(nonnull, nonatomic, strong, readonly) NSString *contentID;
/*!
 @property externalID
 @abstract Developer-defined ID associated with the content.
 */
@property(nullable, nonatomic, strong, readonly) NSString *externalID;
/*!
 @property name
 @abstract Content name.
 */
@property(nonatomic, strong, readonly) NSString *name;
/*!
 @property type
 @abstract Content type.
 */
@property(nonatomic, strong, readonly) NSString *type;
/*!
 @property contentState
 @abstract String value converted from @link state @/link.
 */
@property(nonatomic, strong, readonly) NSString *contentState;
/*!
 @property state
 @abstract Content state.
 */
@property(nonatomic, assign, readonly) SMContentState state;
/*!
 @property details
 @abstract Content description.
 */
@property(nullable, nonatomic, strong, readonly) NSString *details;
/*!
 @property descriptionText
 @abstract Content description.
 @deprecated This property has been deprecated - use @link details @/link instead.
 */
@property(nullable, nonatomic, strong, readonly) NSString *descriptionText __attribute__((deprecated));
/*!
 @property weight
 @abstract Developer-defined numerical value that can be used to sort contents.
 */
@property(nonatomic, assign, readonly) NSInteger weight;
/*!
 @property imageURL
 @abstract URL to image associated with the content.
 */
@property(nullable, nonatomic, strong, readonly) NSString *imageURL;
/*!
 @property createdTime
 @abstract Indicates when content was created.
 */
@property(nonatomic, strong, readonly) NSString *createdTime;
/*!
 @property updatedTime
 @abstract Indicates when content was updated.
 */
@property(nullable, nonatomic, strong, readonly) NSString *updatedTime;
/*!
 @property expiresTime
 @abstract Indicates when content will expire.
 */
@property(nullable, nonatomic, strong, readonly) NSString *expiresTime;
/*!
 @property metadata
 @abstract Metadata associated with the content.
 */
@property(nullable, nonatomic, strong, readonly) NSDictionary<NSString *, NSObject *> *metadata;
/*!
 @property extras
 @abstract Any data values that do not have an associated class property.
 */
@property(nullable, nonatomic, strong, readonly) NSDictionary<NSString *, NSObject *> *extras;

/*!
 @abstract Converts specified string value to the corresponding @link SMContentState @/link enum value.
 @param string String to convert.
 @result @link SMContentState @/link enum value.
 */
+ (SMContentState)stateForString:(NSString *)string NS_SWIFT_NAME(contentState(from:));
/*!
 @abstract Converts specified @link SMContentState @/link enum value to the corresponding string value.
 @param state State to convert.
 @result <code>NSString</code> value.
 */
+ (NSString *)stringForState:(SMContentState)state NS_SWIFT_NAME(string(from:));

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_CONTENT__ */
