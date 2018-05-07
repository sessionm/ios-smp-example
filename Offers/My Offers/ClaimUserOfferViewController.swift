//
//  ClaimUserOfferViewController.swift
//  Offers
//
//  Copyright © 2018 SessionM. All rights reserved.
//

import SessionMOffersKit
import UIKit

class ClaimUserOfferViewController: UIViewController {

    var item: SMUserOfferItem? = nil;

    @IBOutlet weak var barCodeText: UILabel!

    @IBOutlet weak var barCodeImage: UIImageView!
    @IBOutlet weak var barCodeImageHeight: NSLayoutConstraint!

    @IBOutlet weak var image: UIImageView!
    @IBOutlet weak var imageHeight: NSLayoutConstraint!

    @IBOutlet weak var header: UILabel!
    @IBOutlet weak var details: UILabel!
    @IBOutlet weak var expires: UILabel!
    @IBOutlet weak var countDown: UILabel!

    override func viewDidLoad() {
        super.viewDidLoad()

        fetchClaim()
    }

    func fetchClaim() {
        SMOffersManager.instance().claimUserOffer(havingID: item!.userOfferID) { (result: SMUserOfferClaimedResponse?, error: SMError?) in
            if let error = error {
                self.present(UIAlertController(title: "Nothing Fetched", message: error.message, preferredStyle: .alert), animated: true, completion: {})
            } else if let claim = result?.claimedOffer {
                self.renderClaim(claim: claim)
            }
        }
    }

    func renderClaim(claim: SMClaimedOfferItem?) {

        if let claim = claim {

            barCodeText.text = claim.code;
            header.text = claim.name;
            details.text = claim.details;

            let df = DateFormatter()
            df.dateFormat = "dd.MM.yyyy"

            if let expirationDate = claim.expirationDate {
                expires.text = "Expires: \(df.string(from: expirationDate))";
            } else {
                expires.text = "Expires: N/A"
            }

            Common.loadImage(parent: nil, uri: claim.codeImageURI, imgView: self.barCodeImage, imageHeight: self.barCodeImageHeight, maxHeight: 70)
            if let uri = item?.media[0].uri {
                Common.loadImage(parent: nil, uri: uri, imgView: self.image, imageHeight: self.imageHeight, maxHeight: 150)
            }

            // Tick down 60 seconds
            Timer.scheduledTimer(timeInterval: 1.0, target: self, selector: #selector(onTick(timer:)), userInfo: nil, repeats: true).fire()
        }
    }

    var ticks = 60;
    @objc func onTick(timer: Timer) {
        if (ticks > 0) {
            countDown.text = ("in \(ticks) seconds");
            ticks -= 1;
        } else {
            timer.invalidate()
            dismiss(animated: true, completion: nil)
        }
    }

    @IBAction func doDismiss(_ sender: UIButton) {
        dismiss(animated: true, completion: nil)
    }
}
