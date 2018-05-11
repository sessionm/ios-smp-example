//
//  CampaignTableViewController.swift
//  SMPExample
//
//  Copyright © 2018 SessionM. All rights reserved.
//

import SessionMCampaignsKit
import UIKit

class CampaignCell: UITableViewCell {
    @IBOutlet var header: UILabel!
    @IBOutlet var subheader: UILabel!
    @IBOutlet var details: UILabel!
    @IBOutlet var icon: UIImageView!
    @IBOutlet var imge: UIImageView!

    @IBOutlet var imageWidth: NSLayoutConstraint!
}

class CampaignTableViewController: UITableViewController {
    private let campaignsManager = SMCampaignsManager.instance()
    private var feedMessages: [SMFeedMessage] = []

    @IBAction private func onRefresh(_ sender: UIRefreshControl) {
        fetchMessages()
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        fetchMessages()
    }

    private func fetchMessages() {
        self.refreshControl?.beginRefreshing()
        campaignsManager.fetchFeedMessages(completionHandler: { (messages: [SMFeedMessage]?, error: SMError?) in
            if let err = error {
                Util.failed(self, message: err.message)
            } else if let feed = messages {
                self.feedMessages = feed
                self.tableView.reloadData()
            }
            self.refreshControl?.endRefreshing()
        })
    }

    // MARK: - Table view data source

    override func numberOfSections(in tableView: UITableView) -> Int { return 1 }

    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return feedMessages.count
    }

    override func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        let message = feedMessages[indexPath.row]
        if message.imageURL != nil {
            return 240.0
        } else {
            return 96.0
        }
    }


    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let message = feedMessages[indexPath.row]

        var cell: CampaignCell? = nil

        if message.imageURL != nil {
            cell = tableView.dequeueReusableCell(withIdentifier: "CampaignCellImage", for: indexPath) as? CampaignCell
        } else {
            cell = tableView.dequeueReusableCell(withIdentifier: "CampaignCellNoImage", for: indexPath) as? CampaignCell
        }

        if let c = cell, let header = c.header, let subheader = c.subheader, let details = c.details, let icon = c.icon {
            header.text = message.header
            subheader.text = message.subheader
            details.text = message.details

            if let img = message.imageURL {
                Util.loadFrom(img, callback: { (image) in
                    if let i = c.imge {
                        i.image = nil
                        c.imageWidth.constant = c.frame.size.height
                        Util.imageToView(image, view: i, contain: c)
                    }
                })
            }

            if let icn = message.iconURL {
                if (icn.count > 0) {
                    Util.loadFrom(icn, callback: { (image) in
                        icon.image = image
                    })
                }
            }
        }
        message.notifySeen()
        return cell!
    }

    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        let message = feedMessages[indexPath.row]
        message.notifyTapped()
        campaignsManager.executeAction(for: message)
    }

    @IBAction private func logout(_ sender: AnyObject) {
        if let provider = SessionM.authenticationProvider() as? SessionMOAuthProvider {
            provider.logOutUser { (authState, error) in
                LoginViewController.loginIfNeeded(self)
            }
        }
    }
}
