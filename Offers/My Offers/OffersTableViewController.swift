//
//  ViewController.swift
//  Events
//
//  Copyright © 2017 SessionM. All rights reserved.
//

import UIKit

class OffersTableViewCell: UITableViewCell {

    @IBOutlet weak var expires: UILabel!
    @IBOutlet weak var header: UILabel!

    @IBOutlet weak var img: UIImageView!
    @IBOutlet weak var imgHeight: NSLayoutConstraint!
}

class OffersTableViewController: UITableViewController {

    override func viewDidLoad() {
        super.viewDidLoad()

        NotificationCenter.default.addObserver(self, selector: #selector(updateToolbar), name: NSNotification.Name(updatedUserNotification), object: nil)

        self.tableView.rowHeight = UITableViewAutomaticDimension
        self.tableView.estimatedRowHeight = 200;

        self.tableView.contentInset = UIEdgeInsetsMake(64, 0, 0, 0);  // Put it below the navigation controller

        modalPresentationStyle = .overCurrentContext
        definesPresentationContext = true;
        providesPresentationContextTransitionStyle = true;

        handleRefresh(refresh: nil)
    }

    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)

        performSelector(onMainThread: #selector(updateToolbar), with: nil, waitUntilDone: false)
    }

    func updateToolbar() {
        navigationController?.navigationBar.topItem!.title = "My Rewards"
        Common.showUserInToolbar(nav: navigationController!)
    }

    var _offers : [SMUserOfferItem] = [];

    @IBAction func handleRefresh(refresh: UIRefreshControl?) {
        SMOffersManager.instance().fetchUserOffers { (result, error) in
            if let r = refresh, r.isRefreshing {
                r.endRefreshing();
            }

            if let error = error {
                self.present(UIAlertController(title: "Nothing Fetched", message: error.message, preferredStyle: .alert), animated: true, completion: {})
            } else if let offers = result?.userOffers {
                self._offers = offers;
                self.tableView.reloadData();
            }
        }
    }

    // MARK: - Table view data source

    override func numberOfSections(in tableView: UITableView) -> Int {
        return 1
    }

    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return _offers.count
    }

    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "My Reward Cell", for: indexPath) as! OffersTableViewCell

        let item = _offers[indexPath.row];

        cell.header.text = item.name;

        if let expirationDate = item.expirationDate {
            let df = DateFormatter()
            df.dateFormat = "dd.MM.yyyy"
            cell.expires.text = df.string(from: expirationDate);
        } else {
            cell.expires.text = "Expires: N/A"
        }

        if (item.media.count > 0) {
            Common.loadImage(parent: nil, uri: item.media[0].uri, imgView: cell.img, imageHeight: cell.imgHeight, maxHeight: 200)
        }

        return cell
    }

    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {

        let purchaseVC = storyboard?.instantiateViewController(withIdentifier: "PurchaseOffer") as! ClaimUserOfferViewController
        purchaseVC.item = _offers[indexPath.row];

        present(purchaseVC, animated: false) {}

    }
}



