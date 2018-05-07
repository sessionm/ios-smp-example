//
//  Common.swift
//  Offers
//
//  Copyright © 2018 SessionM. All rights reserved.
//

import SessionMIdentityKit
import UIKit

class Common: NSObject {
    static func loadImage(parent: UIView?, uri: String, imgView: UIImageView, imageHeight: NSLayoutConstraint?, maxHeight: CGFloat) {
        DispatchQueue.global().async {
            do {
                if let imageURL = URL(string: uri.replacingOccurrences(of: "http:", with: "https:")) {
                    let imageData = try Data(contentsOf: imageURL);
                    DispatchQueue.main.async {
                        if let img = UIImage(data: imageData) {
                            if let p = parent as? UITableView {
                                p.beginUpdates()
                            }
                            imgView.image = img;
                            if let imgHeight = imageHeight {
                                imgHeight.constant = img.size.height > maxHeight ? maxHeight : img.size.height
                            }
                            if let p = parent as? UITableView {
                                p.endUpdates()
                            }
                        }
                    }
                }
            } catch {
                print(error);
            }
        }
    }

    static func showUserInToolbar(nav: UINavigationController) {
        if let usr = SMUserManager.instance().currentUser, let email = usr.email {
            let text = "\(email) \(usr.availablePoints) pts";
            nav.setToolbarHidden(false, animated: true)
            nav.toolbar.items = [ UIBarButtonItem(barButtonSystemItem: .flexibleSpace, target: nil, action: nil),
                                  UIBarButtonItem(title: text, style: .plain, target: nil, action: nil),
                                  UIBarButtonItem(barButtonSystemItem: .flexibleSpace, target: nil, action: nil)]
        } else {
            nav.setToolbarHidden(true, animated: true)
        }
    }
}
