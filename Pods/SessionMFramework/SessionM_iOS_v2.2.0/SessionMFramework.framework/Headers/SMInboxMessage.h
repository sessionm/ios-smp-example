//
//  SMInboxMessage.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef __SM_INBOX_MESSAGE__
#define __SM_INBOX_MESSAGE__

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @typedef SMInboxMessageState
 @abstract Indicates how the user has interacted with a message.

 @constant SMInboxMessageStateUnknown Message state is unknown.
 @constant SMInboxMessageStateNew Message has not been read.
 @constant SMInboxMessageStateRead Message has been read.
 @constant SMInboxMessageStateDeleted Message has been deleted.
 */
typedef NS_ENUM (NSInteger, SMInboxMessageState) {
    SMInboxMessageStateUnknown NS_SWIFT_NAME(unknown),
    SMInboxMessageStateNew NS_SWIFT_NAME(new),
    SMInboxMessageStateRead NS_SWIFT_NAME(read),
    SMInboxMessageStateDeleted NS_SWIFT_NAME(deleted)
};


/*!
 @class SMInboxMessage
 @abstract Defines the data associated with promotional messages that can be displayed in a user's inbox.
 */
@interface SMInboxMessage : NSObject
/*!
 @property messageID
 @abstract Unique ID for message.
 */
@property(nonnull, nonatomic, strong, readonly) NSString *messageID;
/*!
 @property externalID
 @abstract Developer-defined ID associated with the message.
 */
@property(nullable, nonatomic, strong, readonly) NSString *externalID;
/*!
 @property createdTime
 @abstract Indicates when message was created.
 */
@property(nullable, nonatomic, strong, readonly) NSString *createdTime;
/*!
 @property expiresTime
 @abstract Indicates when message will exipre.
 */
@property(nullable, nonatomic, strong, readonly) NSString *expiresTime;
/*!
 @property state
 @abstract Message state.
 */
@property(nonatomic, assign, readonly) SMInboxMessageState state;
/*!
 @property type
 @abstract Message type.
 */
@property(nullable, nonatomic, strong, readonly) NSString *type;
/*!
 @property subject
 @abstract Message subject.
 */
@property(nullable, nonatomic, strong, readonly) NSString *subject;
/*!
 @property body
 @abstract Message body.
 */
@property(nullable, nonatomic, strong, readonly) NSString *body;
/*!
 @property imageURL
 @abstract URL to image associated with the message.
 */
@property(nullable, nonatomic, strong, readonly) NSString *imageURL;
/*!
 @property metadata
 @abstract Metadata associated with the message.
 */
@property(nullable, nonatomic, strong, readonly) NSDictionary<NSString *, NSObject *> *metadata;
/*!
 @property data
 @abstract Contains optional configuration such as a message body or deep link URL.
 */
@property(nullable, nonatomic, strong, readonly) NSDictionary<NSString *, NSObject *> *data;
/*!
 @property extras
 @abstract Any data values that do not have an associated class property.
 */
@property(nullable, nonatomic, strong, readonly) NSDictionary<NSString *, NSObject *> *extras;

/*!
 @abstract Converts specified string value to the corresponding @link SMInboxMessageState @/link enum value.
 @param string String to convert.
 @result @link SMInboxMessageState @/link enum value.
 */
+ (SMInboxMessageState)stateForString:(NSString *)string NS_SWIFT_NAME(messageState(from:));
/*!
 @abstract Converts specified @link SMInboxMessageState @/link enum value to the corresponding string value.
 @param state State to convert.
 @result <code>NSString</code> value.
 */
+ (NSString *)stringForState:(SMInboxMessageState)state NS_SWIFT_NAME(string(from:));

@end

/*!
 @class SMNewInboxMessage
 @abstract Defines the data associated with an inbox message creation request.
 */
@interface SMNewInboxMessage : NSObject
/*!
 @property subject
 @abstract Message subject.
 */
@property(nonatomic, strong) NSString *subject;
/*!
 @property externalID
 @abstract Developer-defined ID associated with the message.
 */
@property(nullable, nonatomic, strong) NSString *externalID;
/*!
 @property imageURL
 @abstract URL to image associated with the message.
 */
@property(nullable, nonatomic, strong) NSString *imageURL;
/*!
 @property metadata
 @abstract Metadata associated with the message.
 */
@property(nullable, nonatomic, strong) NSDictionary<NSString *, NSObject *> *metadata;
/*!
 @property data
 @abstract Contains optional configuration such as a message body or deep link URL.
 */
@property(nullable, nonatomic, strong) NSDictionary<NSString *, NSObject *> *data;

/*!
 @abstract Creates a new instance of <code>SMNewInboxMessage</code> with the specified parameters.
 @param subject Message subject.
 @result <code>SMNewInboxMessage</code> instance.
 */
- (instancetype)initWithSubject:(NSString *)subject NS_SWIFT_NAME(init(subject:));
/*!
 @abstract Creates a new instance of <code>SMNewInboxMessage</code> with the specified parameters.
 @param subject Message subject.
 @param body Message body.
 @result <code>SMNewInboxMessage</code> instance.
 */
- (instancetype)initWithSubject:(NSString *)subject body:(NSString *)body NS_SWIFT_NAME(init(subject:body:));
/*!
 @abstract Creates a new instance of <code>SMNewInboxMessage</code> with the specified parameters.
 @param subject Message subject.
 @param data Contains optional configuration such as a message body or deep link URL.
 @param metadata Metadata associated with the message.
 @result <code>SMNewInboxMessage</code> instance.
 */
- (instancetype)initWithSubject:(NSString *)subject data:(NSDictionary<NSString *, NSObject *> * _Nullable)data metadata:(NSDictionary<NSString *, NSObject *> * _Nullable)metadata NS_SWIFT_NAME(init(subject:data:metadata:));
/*!
 @abstract Creates a new instance of <code>SMNewInboxMessage</code> with the specified parameters.
 @param subject Message subject.
 @param body Message body.
 @param data Contains optional configuration such as a message body or deep link URL.
 @param metadata Metadata associated with the message.
 @result <code>SMNewInboxMessage</code> instance.
 */
- (instancetype)initWithSubject:(NSString *)subject body:(NSString * _Nullable)body data:(NSDictionary<NSString *, NSObject *> * _Nullable)data metadata:(NSDictionary<NSString *, NSObject *> * _Nullable)metadata NS_SWIFT_NAME(init(subject:body:data:metadata:));

/*!
 @abstract Returns message data in a dictionary format.
 @result <code>NSDictionary</code> representation of message data.
 */
- (NSDictionary *)asDictionary;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_INBOX_MESSAGE__ */
