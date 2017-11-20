//
//  SMWebView.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//


#ifndef SM_WEBVIEW_H
#define SM_WEBVIEW_H

#import <Foundation/Foundation.h>

#import <WebKit/WebKit.h>

#import "SMJSBridgeHandling.h"
#import "SMError.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @const SM_WEB_VIEW_RESULT_NOTIFICATION
 @abstract Notifies observers of WebView events.
 @discussion a notification of an action happening in the WebView.
 */
extern NSString *const SM_WEB_VIEW_RESULT_NOTIFICATION NS_SWIFT_NAME(webViewResultNotification);
/*!
 @const SM_WEB_VIEW_ERROR_NOTIFICATION
 @abstract Notifies observers of WebView errors.
 @discussion a error notification in the WebView.
 */
extern NSString *const SM_WEB_VIEW_ERROR_NOTIFICATION NS_SWIFT_NAME(webViewErrorNotification);

extern NSString *const kSMWebViewError;
extern NSString *const kSMWebViewData;

@class SMWebView;

@protocol SMWebViewDelegate <NSObject>
-(void)webView:(SMWebView *)webView jsBridgeDidFailWithError:(SMError *)error NS_SWIFT_NAME(webView(_:jsBridgeDidFailWithError:));
@end

IB_DESIGNABLE

@interface SMWebView : UIView
/*!
 @abstract delegate for @link SMWebView @/link to pass events to caller.
 @discussion This will pass a sub-set of the @link SMWebView @/link and SessionM custom events to the developer if they register..
 */
@property(nonatomic, weak, nullable) IBOutlet id<SMWebViewDelegate>delegate;

/*!
 @abstract url is used when the @link SMWebView @/link is displayed.
 @discussion This is the URL, if entered, that will show up when the @link SMWebView @/link is displayed.
 */
@property(nonatomic, strong) IBInspectable NSString *url;

#pragma mark - init methods

/*!
 @abstract Constructor is used if developer creates and displays view from code.
 @param frame is the desired size of the frame
 @return Instance of @link SMWebView @/link
 */
-(instancetype)initWithFrame:(CGRect)frame;
/*!
 @abstract Constructor is used if view is created from a xib or storyboard.
 @param coder pulls params from storyboard or xib
 @return Instance of @link SMWebView @/link
 */
-(instancetype _Nullable)initWithCoder:(NSCoder *)coder;

#pragma mark - load HTML page

/*!
 @abstract Forward to WKWebView.
 */
- (nullable WKNavigation *)loadRequest:(NSURLRequest *)request NS_SWIFT_NAME(loadRequest(_:));
/*!
 @abstract Forward to WKWebView.
 */
- (nullable WKNavigation *)loadHTMLString:(NSString *)string baseURL:(nullable NSURL *)baseURL NS_SWIFT_NAME(loadHTMLString(_:baseURL:));

#pragma mark - Back / Forward

/*!
 @abstract Forward to WKWebView.
 */
@property (nonatomic, readonly) BOOL canGoBack;
/*!
 @abstract Forward to WKWebView.
 */
@property (nonatomic, readonly) BOOL canGoForward;

/*!
 @abstract Forward to WKWebView.
 */
- (nullable WKNavigation *)goBack;
/*!
 @abstract Forward to WKWebView.
 */
- (nullable WKNavigation *)goForward;

#pragma mark - call JS (Might be made private

/*!
 @abstract Forward to WKWebView.
 */
- (void)evaluateJavaScript:(NSString *)javaScriptString completionHandler:(void (^ _Nullable)(_Nullable id, NSError * _Nullable error))completionHandler NS_SWIFT_NAME(evaluateJavaScript(_:completionHandler:));

#pragma mark - JS Bridge Handler and Delegate

/*!
 @abstract register a @link SMJSBridgeHandler @/link to include in processing.
 @param jsBridgeHandler the @link SMjsBridgeHandler @/link to register
 */
-(void)registerJSBridgeHandler:(SMJSBridgeHandler *)jsBridgeHandler NS_SWIFT_NAME(registerJSBridgeHandler(_:));
/*!
 @abstract unregister a @link SMJSBridgeHandler @/link from being processed.
 @param jsBridgeHandler the @link SMjsBridgeHandler @/link to unregister
 */
-(void)unregisterJSBridgeHandler:(SMJSBridgeHandler *)jsBridgeHandler NS_SWIFT_NAME(unregisterJSBridgeHandler(_:));
/*!
 @abstract unregister a @link SMJSBridgeHandler @/link from being processed.
 @param bridgeTag the tag (from registration) to unregister
 */
-(void)unregisterJSBridgeHandlerWithTag:(NSString *)bridgeTag NS_SWIFT_NAME(unregisterJSBridgeHandler(havingTag:));

/*!
 @abstract register a @link SMRedirectDelegate @/link to include in processing.
 @param redirectDelegate the @link SMRedirectDelegate @/link to register
 */
-(void)registerRedirectDelegate:(SMRedirectDelegate *)redirectDelegate NS_SWIFT_NAME(registerRedirectDelegate(_:));
/*!
 @abstract unregister a @link SMRedirectDelegate @/link from being processed.
 @param redirectDelegate the @link SMRedirectDelegate @/link to unregister
 */
-(void)unregisterRedirectDelegate:(SMRedirectDelegate *)redirectDelegate NS_SWIFT_NAME(unregisterRedirectDelegate(_:));
/*!
 @abstract unregister a @link SMJSBridgeHandler @/link from being processed.
 @param redirectPrefix the tag (from registration) to unregister
 */
-(void)unregisterRedirectDelegateWithPrefix:(NSString *)redirectPrefix NS_SWIFT_NAME(unregisterRedirectDelegate(havingPrefix:));

@end

NS_ASSUME_NONNULL_END

#endif
