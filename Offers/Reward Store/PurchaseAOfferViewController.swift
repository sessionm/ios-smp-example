//
//  PurchaseAOfferViewController.swift
//  Offers
//
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
            terms.text = "\(item.details)\n\n\(item.terms)"
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
        dismiss(animated: true, completion: nil)
    }

    @IBAction func doPurchase(_ sender: Any) {
        if let item = self.item {
            SMOffersManager.instance().purchaseOffer(havingID: item.offerID, quantity: 1) { (result: SMPurchaseOfferResult?, error: SMError?) in
                if let error = error {
                    self.present(UIAlertController(title: "No Purchase", message: error.message, preferredStyle: .alert), animated: true, completion: {})
                } else if let result = result {
                    let ctrlr = UIAlertController(title: "Purchased", message: result.userOffer.offerID, preferredStyle: .alert)
                    ctrlr.addAction(UIAlertAction(title: "Dismiss", style: .default, handler: nil))
                    self.present(ctrlr, animated: true, completion: {})
                }
            }
        }
    }

}
