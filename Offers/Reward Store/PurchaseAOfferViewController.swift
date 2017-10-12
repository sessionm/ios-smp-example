//
//  PurchaseAOfferViewController.swift
//  Offers
//
//  Created by Paul Mattheis on 10/11/17.
//  Copyright © 2017 SessionM. All rights reserved.
//

import UIKit

class PurchaseAOfferViewController: UIViewController {

    var item: SMStoreOfferItem? = nil;

    @IBOutlet weak var header: UILabel!
    @IBOutlet weak var terms: UILabel!

    @IBOutlet weak var available: UILabel!
    @IBOutlet weak var cost: UILabel!
    @IBOutlet weak var afterPurchase: UILabel!

    @IBOutlet weak var image: UIImageView!
    @IBOutlet weak var imgHeight: NSLayoutConstraint!

    override func viewDidLoad() {
        super.viewDidLoad()
    }

    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)

        if let item = self.item {

            header.text = item.name
            terms.text = "\(item.terms)\n\(item.details)"
            if let user = SMUserManager.instance().currentUser {
                available.text = "\(user.availablePoints)"
                afterPurchase.text = "\(Double(user.availablePoints) - item.price)"
            }
            cost.text = "\(item.price)"

            if (item.media.count > 0) {
                Common.loadImage(parent: nil, uri: item.media[0].uri, imgView: self.image, imageHeight: self.imgHeight, maxHeight: 200.0)
            }
        }
    }

    @IBAction func doDismiss(_ sender: Any) {
    }

    @IBAction func doPurchase(_ sender: Any) {
    }

}
