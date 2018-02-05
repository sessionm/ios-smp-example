//
//  RewardStoreTableViewController.swift
//  Offers
//
//  Copyright © 2018 SessionM. All rights reserved.
//

import UIKit

class RewardStoreTableViewCell: UITableViewCell {

    @IBOutlet weak var header: UILabel!
    @IBOutlet weak var validDates: UILabel!
    @IBOutlet weak var points: UILabel!
    
    @IBOutlet weak var img: UIImageView!
}

class RewardStoreTableViewController: UITableViewController {

    override func viewDidLoad() {
        super.viewDidLoad()

        NotificationCenter.default.addObserver(self, selector: #selector(updateToolbar), name: NSNotification.Name(updatedUserNotification), object: nil)

        self.tableView.rowHeight = UITableViewAutomaticDimension
        self.tableView.estimatedRowHeight = 200;

        self.tableView.contentInset = UIEdgeInsetsMake(64,0,0,0);  // Put it below the navigation controller

        modalPresentationStyle = .overCurrentContext
        definesPresentationContext = true;
        providesPresentationContextTransitionStyle = true;

        handleRefresh(refresh: nil)
    }

    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)

        performSelector(onMainThread: #selector(updateToolbar), with: nil, waitUntilDone: false)
    }

    @objc func updateToolbar() {
        if let controller = navigationController {
            controller.navigationBar.topItem!.title = "Rewards Store"
            Common.showUserInToolbar(nav: controller)
        }
    }

    var _offers : [SMStoreOfferItem] = [];

    @IBAction func handleRefresh(refresh: UIRefreshControl?) {
        SMOffersManager.instance().fetchStoreOffers { (result: SMStoreOffersFetchedResponse?, error: SMError?) in
            if let r = refresh, r.isRefreshing {
                r.endRefreshing();
            }

            if let error = error {
                self.present(UIAlertController(title: "Nothing Fetched", message: error.message, preferredStyle: .alert), animated: true, completion: {})
            } else if let offers = result?.offers {
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
        let cell = tableView.dequeueReusableCell(withIdentifier: "Reward Store Cell", for: indexPath) as! RewardStoreTableViewCell

        let item = _offers[indexPath.row];

        cell.header.text = item.name;

        let df = DateFormatter()
        df.dateFormat = "dd.MM.yyyy"
        if let endDate = item.endDate {
            cell.validDates.text = "This offer is available \(df.string(from: item.startDate)) through \(df.string(from: endDate))"
        }

        let points = NSNumber(value: item.price).intValue;
        cell.points.text = "\(points)";

        if (item.media.count > 0) {
            Common.loadImage(parent: self.tableView, uri: item.media[0].uri, imgView: cell.img, imageHeight: nil, maxHeight: 200)
        }

        return cell
    }

    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {

        let claimVC = storyboard?.instantiateViewController(withIdentifier: "ClaimOffer") as! PurchaseAOfferViewController
        claimVC.item = _offers[indexPath.row];

        present(claimVC, animated: false) {}
    }
}
