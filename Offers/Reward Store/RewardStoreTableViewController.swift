//
//  RewardStoreTableViewController.swift
//  Offers
//
//  Created by Paul Mattheis on 10/10/17.
//  Copyright © 2017 SessionM. All rights reserved.
//

import UIKit

class RewardStoreTableViewCell: UITableViewCell {

    @IBOutlet weak var header: UILabel!
    @IBOutlet weak var validDates: UILabel!
    @IBOutlet weak var points: UILabel!
    
    @IBOutlet weak var img: UIImageView!
    @IBOutlet weak var imgHeight: NSLayoutConstraint!
}

class RewardStoreTableViewController: UIViewController, UITableViewDataSource, UITableViewDelegate {

    @IBOutlet weak var tableView: UITableView!
    @IBOutlet weak var user: UILabel!

    override func viewDidLoad() {
        super.viewDidLoad()

        self.tableView.rowHeight = UITableViewAutomaticDimension
        self.tableView.estimatedRowHeight = 200;

        let refresh = UIRefreshControl();
        refresh.addTarget(self, action: #selector(handleRefresh(refresh:)), for: UIControlEvents.valueChanged)
        self.tableView.addSubview(refresh);

        handleRefresh(refresh: nil)
    }

    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)

        performSelector(onMainThread: #selector(updateToolbar), with: nil, waitUntilDone: false)
    }

    func updateToolbar() {
        Common.showUserInToolbar(nav: navigationController!)
    }

    var _offers : [SMStoreOfferItem] = [];

    func handleRefresh(refresh: UIRefreshControl?) {
        SMOffersManager.instance().fetchOffersStore { (result: SMFetchOffersStoreResult?, error: SMError?) in
            if (refresh != nil && (refresh!.isRefreshing)) {
                refresh!.endRefreshing();
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

    func numberOfSections(in tableView: UITableView) -> Int {
        return 1
    }

    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return _offers.count
    }

    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "Reward Store Cell", for: indexPath) as! RewardStoreTableViewCell

        let item = _offers[indexPath.row];

        tableView.beginUpdates()
        cell.header.text = item.name;
        let df = DateFormatter()
        df.dateFormat = "dd.MM.yyyy"

        cell.validDates.text = "This offer is available \(df.string(from: item.startDate)) through \(df.string(from: item.endDate))"

        let points = NSNumber(value: item.price).intValue;
        cell.points.text = "\(points)";

        if (item.media.count > 0) {
            Common.loadImage(parent: self.tableView, uri: item.media[0].uri, imgView: cell.img, imageHeight: cell.imgHeight, maxHeight: 200)
        }
        tableView.endUpdates()

        return cell
    }

    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        let claimVC = storyboard?.instantiateViewController(withIdentifier: "ClaimOffer") as! PurchaseAOfferViewController
        claimVC.item = _offers[indexPath.row];
        modalPresentationStyle = .overCurrentContext
        definesPresentationContext = true;
        providesPresentationContextTransitionStyle = true;
        present(claimVC, animated: false) {}
    }
}
