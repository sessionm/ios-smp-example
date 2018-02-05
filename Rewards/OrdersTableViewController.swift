//
//  OrdersTableViewController.swift
//  SMPExample
//
//  Copyright © 2018 SessionM. All rights reserved.
//

import UIKit

class OrderCell: UITableViewCell {
    @IBOutlet var logo: UIImageView!
    @IBOutlet var orderID: UILabel!
    @IBOutlet var name: UILabel!
    @IBOutlet var quantity: UILabel!
    @IBOutlet var points: UILabel!
    @IBOutlet var status: UILabel!
    @IBOutlet var details: UILabel!
    @IBOutlet var createdAt: UILabel!
}

class OrdersTableViewController: UITableViewController, SessionMDelegate {
    private let sessionM = SessionM.sharedInstance()
    private var rewardsManager: SMRewardsManager = SessionM.sharedInstance().rewardsManager
    private var orders: [SMOrder] = []

    @IBAction private func onRefresh(_ sender: UIRefreshControl) {
        fetchOrders()
    }

    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)

        sessionM.delegate = self
        fetchOrders()
    }

    private func fetchOrders() {
        self.refreshControl?.beginRefreshing()
        rewardsManager.fetchOrders(completionHandler: { (orders: [SMOrder]?, error: SMError?) in
            if let err = error {
                Util.failed(self, message: err.message)
            } else if let newOrders = orders {
                self.orders = newOrders
                self.tableView.reloadData()
            }
            self.refreshControl?.endRefreshing()
        })
    }

    // MARK: - Table view data source

    override func numberOfSections(in tableView: UITableView) -> Int { return 1 }

    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return orders.count
    }

    override func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        let order = orders[indexPath.row]
        if order.logoURL != nil {
            return 240.0
        } else {
            return 96.0
        }
    }

    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let order = orders[indexPath.row]
        let cell = tableView.dequeueReusableCell(withIdentifier: "OrderCell", for: indexPath) as? OrderCell

        if let c = cell {
            c.orderID.text = order.orderID
            c.name.text = order.name
            c.quantity.text = "\(order.quantity)"
            c.points.text = "\(order.points) pts"
            c.status.text = order.stringFromCurrentStatus()
            c.details.text = order.details
            c.createdAt.text = order.createdTime
            c.tag = indexPath.row

            if let img = order.logoURL {
                Util.loadFrom(img, callback: { (image) in
                    c.logo.image = image
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
}
