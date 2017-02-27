//
//  ReferralsTableViewController.swift
//  SMPExample
//
//  Copyright © 2017 SessionM. All rights reserved.
//

import UIKit

class ReferralCell: UITableViewCell {
    @IBOutlet var referralID: UILabel!
    @IBOutlet var status: UILabel!
    @IBOutlet var pendingTime: UILabel!
    @IBOutlet var referee: UILabel!
    @IBOutlet var email: UILabel!
    @IBOutlet var phoneNumber: UILabel!
}

class ReferralsTableViewController: UITableViewController, SessionMDelegate {
    private let sessionM = SessionM.sharedInstance()
    private var referralsManager: SMReferralsManager = SessionM.sharedInstance().referralsManager
    private var referrals: [SMReferral] = []

    @IBAction private func onRefresh(_ sender: UIRefreshControl) {
        fetchReferrals()
    }

    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)

        sessionM.delegate = self
        fetchReferrals()
    }

    private func fetchReferrals() {
        self.refreshControl?.beginRefreshing()
        referralsManager.fetchReferrals(completionHandler: { (referrals: [SMReferral]?, error: SMError?) in
            if let err = error {
                Util.failed(self, message: err.message)
            } else if let newReferrals = referrals {
                self.referrals = newReferrals
                self.tableView.reloadData()
            }
            self.refreshControl?.endRefreshing()
        })
    }

    // MARK: - Table view data source

    override func numberOfSections(in tableView: UITableView) -> Int { return 1 }

    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return referrals.count
    }

    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let referral = referrals[indexPath.row]
        let cell = tableView.dequeueReusableCell(withIdentifier: "ReferralCell", for: indexPath) as? ReferralCell

        if let c = cell {
            c.referralID.text = referral.referralID
            c.status.text = SMReferral.string(from: referral.status)
            c.pendingTime.text = referral.pendingTime
            c.referee.text = referral.referee
            c.email.text = referral.email
            c.phoneNumber.text = referral.phoneNumber
            c.tag = indexPath.row
        }

        return cell!
    }

    func sessionM(_ sessionM: SessionM, didUpdateUser user: SMUser) {
        LoginViewController.loginIfNeeded(self)
    }

    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        let destination = segue.destination as! ReferralDetailViewController
        if sender is UIBarButtonItem {
            destination.isAddingReferral = true
        } else if sender is ReferralCell {
            let cell = sender as! ReferralCell
            destination.referral = referrals[cell.tag]
            destination.isAddingReferral = false
        }
    }

    @IBAction private func logout(_ sender: AnyObject) {
        sessionM.logOutUser()
    }
}
