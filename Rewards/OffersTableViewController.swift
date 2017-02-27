//
//  OffersTableViewController.swift
//  ios-swift-smp-sample
//
//  Copyright © 2017 SessionM. All rights reserved.
//

import UIKit

class OfferCell: UITableViewCell {
    @IBOutlet var details: UILabel!
    @IBOutlet var header: UILabel!
    @IBOutlet var offerImage: UIImageView!
    @IBOutlet var imageWidth: NSLayoutConstraint!
    @IBOutlet var points: UILabel!
}

class OffersTableViewController: UITableViewController, SessionMDelegate {
    private let sessionM = SessionM.sharedInstance()
    private var rewardsManager: SMRewardsManager = SessionM.sharedInstance().rewardsManager
    private var offers: [SMOffer] = []

    @IBAction private func onRefresh(_ sender: UIRefreshControl) {
        fetchOffers()
    }

    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)

        sessionM.delegate = self
        fetchOffers()
    }

    private func fetchOffers() {
        self.refreshControl?.beginRefreshing()
        rewardsManager.fetchOffers(completionHandler: { (offers: [SMOffer]?, error: SMError?) in
            if let err = error {
                Util.failed(self, message: err.message)
            } else if let newOffers = offers {
                self.offers = newOffers
                self.tableView.reloadData()
            }
            self.refreshControl?.endRefreshing()
        })
    }

    // MARK: - Table view data source

    override func numberOfSections(in tableView: UITableView) -> Int { return 1 }

    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return offers.count
    }

    override func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        let offer = offers[indexPath.row]
        if offer.logoURL != nil {
            return 240.0
        } else {
            return 96.0
        }
    }

    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let offer = offers[indexPath.row]
        let cell = tableView.dequeueReusableCell(withIdentifier: "OfferCell", for: indexPath) as? OfferCell

        if let c = cell {
            c.details.text = offer.descriptionText
            c.header.text = offer.type
            c.points.text = "\(offer.points) pts"
            c.tag = indexPath.row

            if let img = offer.logoURL {
                Util.loadFrom(img, callback: { (image) in
                    c.offerImage.image = image
                    c.imageWidth.constant = min(c.bounds.size.width, ((c.offerImage.frame.size.height / image.size.height) * image.size.width))
                })
            }
        }

        return cell!
    }

    func sessionM(_ sessionM: SessionM, didUpdateUser user: SMUser) {
        LoginViewController.loginIfNeeded(self.tabBarController!)
    }

    @IBAction private func logout(_ sender: AnyObject) {
        sessionM.logOutUser()
    }

    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        let placeOrder = segue.destination as! PlaceOrderViewController
        let cell = sender as! OfferCell
        placeOrder.offer = offers[cell.tag]
    }
}
