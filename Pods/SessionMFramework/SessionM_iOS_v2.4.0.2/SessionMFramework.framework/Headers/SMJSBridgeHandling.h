//
//  SMJSBridgeHandling.h
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef SMJSBridgeHandler_H
#define SMJSBridgeHandler_H

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMJSBridgeHandler
 @abstract Class that supports the developer assigining a class that will have handleXYZmessage methods, where XYZ is the type of message coming from the jsBridge handler.
 This is used by the javascript bridge scripting functionality.  see http://doc.sessionm.com/tbd
 */

@interface SMJSBridgeHandler : NSObject  // This allows the developer to assign a class with handleXYZmessage methods

/*!
 @abstract Create an instance of a bridge handler with the class that will have the handleXYZmessage methods..
 @param bridgeTag identifies the handler, can be used to remove.
 @param handlerClass class that contains the handler methods.
 @return @link SMjsBridgeHandler @/link instance
 */
-(instancetype)initWithBridgeTag:(NSString *)bridgeTag handlerClass:(id)handlerClass;

@end

/*!
 @class SMRedirectDelegate
 @abstract Class that supports the developer adding a block of code to handle jsBridge handling.  This is triggered by using a custom prefix to the URL.  ie.  jsbridge://bridging/method
 This is used by the javascript bridge scripting functionality.  see http://doc.sessionm.com/tbd
 */

/*!
 @typedef handleRedirectBlock
 @abstract Handle the redirect from the jsBridge.
 @discussion parameters:
 <ul>
 <li>'path' - The full path of the redirect</li>
 <li>'pathComponents' - The pieces of the path, broken into an array</li>
 <li>'params' - The part of the URL after "?", with p=1 -> { "p" : 1 }</li>
 <li>'prefix' - The prefix that was matched ie. jsBridge://</li>
 </ul>
 */
typedef BOOL(^RedirectHandler)(NSString *path, NSArray *pathComponents, NSDictionary<NSString *, NSArray *> *params, NSString *prefix);

@interface SMRedirectDelegate : NSObject

/*!
 @abstract Create an instance of a bridge handler with the block that will be called for the prefix.
 @param prefix to watch for with incoming JS generated URLs.
 @param redirectHandler what to call when prefix match is found.
 @return @link SMRedirectDelegate @/link instance
 */
-(instancetype)initWithPrefix:(NSString *)prefix redirectHandler:(RedirectHandler)redirectHandler;

@end

NS_ASSUME_NONNULL_END

#endif
