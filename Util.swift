//
//  Util.swift
//  SMPExample
//
//  Copyright © 2018 SessionM. All rights reserved.
//

import UIKit

class Util: NSObject {
    private static let queue = DispatchQueue.global(qos: .userInteractive)

    static func loadFrom(_ url: String, callback: @escaping (_ image: UIImage) -> Void)  {
        queue.async {
            if let u = URL(string: url) {
                if let imageData = try? Data(contentsOf: u), let image = UIImage(data: imageData) {
                    DispatchQueue.main.async(execute: {
                        callback(image)
                    })
                }
            }
        }
    }

    static func imageToView(_ image: UIImage, view: UIImageView, contain: UIView) {
        view.image = image

        let isize = image.size
        let cf = contain.frame.size

        var wScale: CGFloat = 1.0
        var hScale: CGFloat = 1.0
        if (isize.width > cf.width) {
            wScale = cf.width / isize.width
        }
        if (isize.height > cf.height) {
            hScale = cf.height / isize.height
        }
        let scale = min(wScale, hScale)

        let siSize = CGSize(width: isize.width * scale, height: isize.height * scale)
        let ul = CGPoint(x: (cf.width / 2.0) - (siSize.width / 2.0), y: (cf.height / 2.0) - (siSize.height / 2.0))

        view.frame = CGRect(x: ul.x, y: ul.y, width: siSize.width, height: siSize.height)
    }

    static func failed(_ viewController: UIViewController, message: String, handler: ((UIAlertAction) -> Void)? = nil) {
        let ac = UIAlertController(title: "Failed", message: message, preferredStyle: .alert)
        ac.addAction(UIAlertAction(title: "OK", style: .default, handler: handler))
        viewController.present(ac, animated: true, completion: nil)
    }
}
