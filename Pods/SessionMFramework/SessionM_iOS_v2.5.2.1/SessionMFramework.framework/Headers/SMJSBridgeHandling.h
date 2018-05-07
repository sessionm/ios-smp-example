//
//  SMJSBridgeHandling.h
//  SessionM
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SM_JS_BRIDGE_HANDLING__
#define __SM_JS_BRIDGE_HANDLING__

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @class SMJSBridgeHandler
 @abstract An instance of this class can be registered to an instance of @link //apple_ref/occ/cl/SMWebView @/link to handle JSBridge messages evaluated by the web view.
 @discussion A JSBridge handler should have methods that follow the naming convention "handleXYZMessage:" or "handleXYZMessageAsync:", where "XYZ" is the name of the JavaScript message evaluated by the web view. These methods should have a single <code>NSDictionary</code> parameter and a return value of <code>NSDictionary</code>.
 */
@interface SMJSBridgeHandler : NSObject

/*!
 @abstract Returns a JSBridge handler that can handle JSBridge messages evaluated by the web view to which the handler is registered.
 @param bridgeTag Used to identify the handler.
 @param handlerClass Class that contains the handler methods.
 @result <code>SMJSBridgeHandler</code> instance.
 */
- (instancetype)initWithBridgeTag:(NSString *)bridgeTag handlerClass:(id)handlerClass;

@end


/*!
 @typedef RedirectHandler
 @abstract Block type for handling JSBridge redirects that are successfully matched by an @link SMRedirectDelegate @/link instance.
 @discussion Parameters:
 <ul>
 <li>'path' - The full path of the redirect</li>
 <li>'pathComponents' - The pieces of the redirect path, broken into an array</li>
 <li>'params' - The URL query parameters that follow "?", with <code>p=1</code> becoming <code>{ "p" : [1] }</code></li>
 <li>'prefix' - The URL prefix that was matched, i.e. "jsBridge://"</li>
 </ul>
 */
typedef BOOL(^RedirectHandler)(NSString *path, NSArray *pathComponents, NSDictionary<NSString *, NSArray *> *params, NSString *prefix);

/*!
 @class SMRedirectDelegate
 @abstract An instance of this class can be registered to an instance of @link //apple_ref/occ/cl/SMWebView @/link to handle JSBridge redirects evaluated by the web view.
 @discussion A redirect delegate's handler is invoked when a URL request with the delegate's URL prefix is loaded by the web view.
 */
@interface SMRedirectDelegate : NSObject

/*!
 @abstract Returns a redirect delegate that will invoke the specified handler when a URL request with the specified prefix is loaded by the web view to which the delegate is registered.
 @param prefix URL prefix string to match against URL requests.
 @param redirectHandler The block to invoke when a URL prefix match is found.
 @result <code>SMRedirectDelegate</code> instance.
 */
- (instancetype)initWithPrefix:(NSString *)prefix redirectHandler:(RedirectHandler)redirectHandler;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_JS_BRIDGE_HANDLING__ */
