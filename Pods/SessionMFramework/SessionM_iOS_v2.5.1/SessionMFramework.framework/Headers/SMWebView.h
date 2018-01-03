//
//  SMWebView.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//


#ifndef __SM_WEB_VIEW__
#define __SM_WEB_VIEW__

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>

#import "SMJSBridgeHandling.h"
#import "SMError.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @const SM_WEB_VIEW_RESULT_NOTIFICATION
 @abstract Notifies observers of successful JSBridge handler evaluations.
 @discussion An @link id @/link object containing data returned by the JavaScript evaluation can be accessed from the notification's <code>userInfo</code> property with the @link kSMWebViewData @/link key.
 */
extern NSString *const SM_WEB_VIEW_RESULT_NOTIFICATION NS_SWIFT_NAME(webViewResultNotification);
/*!
 @const SM_WEB_VIEW_ERROR_NOTIFICATION
 @abstract Notifies observers of failed JSBridge handler evaluations.
 @discussion An @link SMError @/link object containing information about why the JavaScript evaluation failed can be accessed from the notification's <code>userInfo</code> property with the @link kSMWebViewError @/link key.
 */
extern NSString *const SM_WEB_VIEW_ERROR_NOTIFICATION NS_SWIFT_NAME(webViewErrorNotification);

/*!
 @const kSMWebViewData
 @abstract Used to access data returned by a successful JavaScript evaluation in a @link SM_WEB_VIEW_RESULT_NOTIFICATION @/link object's <code>userInfo</code> property.
 */
extern NSString *const kSMWebViewData;
/*!
 @const kSMWebViewError
 @abstract Used to access an @link SMError @/link object from a failed JavaScript evaluation in a @link SM_WEB_VIEW_ERROR_NOTIFICATION @/link object's <code>userInfo</code> property.
 */
extern NSString *const kSMWebViewError;


@class SMWebView;

/*!
 @protocol SMWebViewDelegate
 @abstract Defines callbacks to be implemented by delegates of @link SMWebView @/link instances.
 */
@protocol SMWebViewDelegate <NSObject>

/*!
 @abstract Notifies delegate that a JSBridge handler evaluation failed with the specified error.
 @param webView <code>SMWebView</code> instance that processed the JavaScript evaluation.
 @param error Contains information about why the JavaScript evaluation failed.
 */
- (void)webView:(SMWebView *)webView jsBridgeDidFailWithError:(SMError *)error NS_SWIFT_NAME(webView(_:jsBridgeDidFailWithError:));

@end


IB_DESIGNABLE

/*!
 @class SMWebView
 @abstract A <code>WKWebView</code> wrapper that can register objects to handle JSBridge messages and redirects initiated by the SessionM Platform.
 */
@interface SMWebView : UIView

/*!
 @property delegate
 @abstract Object that implements @link SMWebViewDelegate @/link callbacks.
 */
@property(nullable, nonatomic, weak, readwrite) IBOutlet id<SMWebViewDelegate> delegate;

/*!
 @property url
 @discussion The active URL.
 */
@property(nonatomic, strong, readwrite) IBInspectable NSString *url;

#pragma mark - Initialization

/*!
 @abstract Returns a web view initialized with the specified frame and the default web view configuration.
 @param frame The frame for the new web view.
 @result @link SMWebView @/link instance.
 */
- (instancetype)initWithFrame:(CGRect)frame;
/*!
 @abstract Returns a web view initialized from data in the specified unarchiver.
 @param aDecoder An unarchiver object.
 @result @link SMWebView @/link instance, or nil if an instance could not be initialized.
 */
- (instancetype _Nullable)initWithCoder:(NSCoder *)aDecoder;

#pragma mark - Navigation

/*!
 @abstract Navigates to a requested URL.
 @discussion Method invocation is forwarded to wrapped <code>WKWebView</code> instance.
 @param request The request specifying the URL to navigate to.
 @result A new navigation for the given request.
 */
- (WKNavigation * _Nullable)loadRequest:(NSURLRequest *)request NS_SWIFT_NAME(loadRequest(_:));
/*!
 @abstract Sets the webpage contents and base URL.
 @discussion Method invocation is forwarded to wrapped <code>WKWebView</code> instance.
 @param string The string to use as the contents of the webpage.
 @param baseURL A URL used to resolve relative URLs within the document.
 @result A new navigation.
 */
- (WKNavigation * _Nullable)loadHTMLString:(NSString *)string baseURL:(NSURL * _Nullable)baseURL NS_SWIFT_NAME(loadHTMLString(_:baseURL:));

/*!
 @property canGoBack
 @abstract A Boolean value indicating whether there is a back item in the back-forward list that can be navigated to.
 @discussion Method invocation is forwarded to wrapped <code>WKWebView</code> instance.
 */
@property(nonatomic, assign, readonly) BOOL canGoBack;
/*!
 @property canGoForward
 @abstract A Boolean value indicating whether there is a forward item in the back-forward list that can be navigated to.
 @discussion Method invocation is forwarded to wrapped <code>WKWebView</code> instance.
 */
@property(nonatomic, assign, readonly) BOOL canGoForward;

/*!
 @abstract Navigates to the back item in the back-forward list.
 @discussion Method invocation is forwarded to wrapped <code>WKWebView</code> instance.
 @result A new navigation to the requested item, or nil if there is no back item in the back-forward list.
 */
- (WKNavigation * _Nullable)goBack;
/*!
 @abstract Navigates to the forward item in the back-forward list.
 @discussion Method invocation is forwarded to wrapped <code>WKWebView</code> instance.
 @result A new navigation to the requested item, or nil if there is no forward item in the back-forward list.
 */
- (WKNavigation * _Nullable)goForward;

#pragma mark - JSBridge Handler and Redirect Delegate

/*!
 @abstract Evaluates a JavaScript string.
 @discussion Method invocation is forwarded to wrapped <code>WKWebView</code> instance.
 @param javaScriptString The JavaScript string to evaluate.
 @param completionHandler A block to invoke when script evaluation completes or fails.
 */
- (void)evaluateJavaScript:(NSString *)javaScriptString completionHandler:(void (^ _Nullable)(_Nullable id, NSError * _Nullable error))completionHandler NS_SWIFT_NAME(evaluateJavaScript(_:completionHandler:));

/*!
 @abstract Registers the specified @link SMJSBridgeHandler @/link instance to be included in processing.
 @param jsBridgeHandler The handler object to register.
 */
- (void)registerJSBridgeHandler:(SMJSBridgeHandler *)jsBridgeHandler NS_SWIFT_NAME(registerJSBridgeHandler(_:));
/*!
 @abstract Unregisters the specified @link SMJSBridgeHandler @/link instance from being processed.
 @param jsBridgeHandler The handler object to unregister.
 */
- (void)unregisterJSBridgeHandler:(SMJSBridgeHandler *)jsBridgeHandler NS_SWIFT_NAME(unregisterJSBridgeHandler(_:));
/*!
 @abstract Unregisters the @link SMJSBridgeHandler @/link instance having the specified bridge tag from being processed.
 @param bridgeTag The bridge tag of the handler object to unregister.
 */
- (void)unregisterJSBridgeHandlerWithTag:(NSString *)bridgeTag NS_SWIFT_NAME(unregisterJSBridgeHandler(havingTag:));

/*!
 @abstract Registers the specified @link SMRedirectDelegate @/link instance to be included in processing.
 @param redirectDelegate The delegate object to register.
 */
- (void)registerRedirectDelegate:(SMRedirectDelegate *)redirectDelegate NS_SWIFT_NAME(registerRedirectDelegate(_:));
/*!
 @abstract Unregisters the specified @link SMRedirectDelegate @/link instance from being processed.
 @param redirectDelegate The delegate object to unregister.
 */
- (void)unregisterRedirectDelegate:(SMRedirectDelegate *)redirectDelegate NS_SWIFT_NAME(unregisterRedirectDelegate(_:));
/*!
 @abstract Unregisters the @link SMRedirectDelegate @/link instance having the specified redirect prefix from being processed.
 @param redirectPrefix The redirect prefix of the delegate object to unregister.
 */
- (void)unregisterRedirectDelegateWithPrefix:(NSString *)redirectPrefix NS_SWIFT_NAME(unregisterRedirectDelegate(havingPrefix:));

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_WEB_VIEW__ */
