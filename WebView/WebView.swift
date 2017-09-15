//
//  WebView.swift
//  WebView
//
//  Copyright © 2017 SessionM. All rights reserved.
//

import UIKit
import WebKit
import SessionMFramework

class WebView: UIViewController, SMWebViewDelegate {
    @IBOutlet weak var webView: SMWebView!
    
    func webView(_ webView: SMWebView, jsBridgeDidFailWithError error: SMError) {
    }

        override func viewDidLoad() {
        super.viewDidLoad()

    }

    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated);

        webView.registerJSBridgeHandler(SMJSBridgeHandler(bridgeTag: "viewController", handlerClass: self));

        webView.registerRedirectDelegate(SMRedirectDelegate(prefix: "smp://",
                                                            redirectHandler: { (path: String, pathComponents: [Any], params: [String : [Any]], prefix: String) -> Bool in
                                                                let route = path.replacingOccurrences(of: prefix, with: "")

                                                                let controller = UIAlertController(title: "Received", message: route, preferredStyle: .alert)
                                                                controller.addAction(UIAlertAction(title: "Ok", style: .default, handler: nil))
                                                                self.present(controller, animated: true, completion: nil)
                                                                return true;
        }));

        webView.url = "http://localhost:4000/index.html";
    }

    func handleTastyMessage(message : Dictionary<String, Any>) -> Dictionary<String, Any> {
        let controller = UIAlertController(title: "Tasty", message: "Soooo Tasty", preferredStyle: .alert)
        controller.addAction(UIAlertAction(title: "Ok", style: .default, handler: nil))
        self.present(controller, animated: true, completion: nil)

        return ["tasty" : "yes"];
    }

    func handleDeeplinkMessage(message : Dictionary<String, Any>) -> Dictionary<String, Any> {
        print("Going Deep: \(message)");
        return ["Carnival":"Feast"];
    }

}

