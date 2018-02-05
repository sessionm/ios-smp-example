//
//  LinkedCardsTableViewController.swift
//  SMPExample
//
//  Copyright © 2018 SessionM. All rights reserved.
//

import UIKit

class CardCell: UITableViewCell {
    @IBOutlet var retailerIcon: UIImageView!
    @IBOutlet var retailerName: UILabel!
    @IBOutlet var cardNumber: UILabel!
}

class LinkedCardsTableViewController: UITableViewController, SessionMDelegate {
    private let sessionM = SessionM.sharedInstance()
    private let loyaltyCardsManager: SMLoyaltyCardsManager = SessionM.sharedInstance().loyaltyCardsManager
    private var cards: [SMLoyaltyCard] = []

    @IBAction private func onRefresh(_ sender: UIRefreshControl) {
        fetchLinkedCards()
    }

    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)

        sessionM.delegate = self
        fetchLinkedCards()
    }

    private func fetchLinkedCards() {
        self.refreshControl?.beginRefreshing()
        loyaltyCardsManager.fetchLinkedCards(completionHandler: { (cards: [SMLoyaltyCard]?, error: SMError?) in
            if let err = error {
                Util.failed(self, message: err.message)
            } else if let newCards = cards {
                self.cards = newCards
                self.tableView.reloadData()
            }
            self.refreshControl?.endRefreshing()
        })
    }

    // MARK: - Table view data source

    override func numberOfSections(in tableView: UITableView) -> Int { return 1 }

    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return cards.count
    }

    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let card = cards[indexPath.row]
        let cell = tableView.dequeueReusableCell(withIdentifier: "CardCell", for: indexPath) as? CardCell

        if let c = cell {
            c.retailerName.text = card.retailer?.name
            c.cardNumber.text = card.cardNumber
            if let icon = card.retailer?.imageURL {
                Util.loadFrom(icon, callback: { (image) in
                    c.retailerIcon.image = image
                })
            }
        }

        return cell!
    }

    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        let card = cards[indexPath.row]
        let unlinkCardAlert = UIAlertController(title: "Unlink Loyalty Card", message: "Unlink card #\(card.cardNumber!) from \(card.retailer!.name!)?", preferredStyle: .alert)
        let unlinkAction = UIAlertAction(title: "Unlink", style: .default, handler: { (action) in
            self.unlink(card)
            })
        let cancelAction = UIAlertAction(title: "Cancel", style: .cancel)
        unlinkCardAlert.addAction(unlinkAction)
        unlinkCardAlert.addAction(cancelAction)
        present(unlinkCardAlert, animated: true)
    }

    private func unlink(_ card: SMLoyaltyCard) {
        loyaltyCardsManager.unlinkCard(havingID: card.cardID, completionHandler: { (error) in
            if let e = error {
                Util.failed(self, message: e.message)
            } else {
                let unlinkedCardAlert = UIAlertController(title: "Card Unlinked", message: nil, preferredStyle: .alert)
                let dismissAction = UIAlertAction(title: "OK", style: .default, handler: { (action) in
                    self.fetchLinkedCards()
                })
                unlinkedCardAlert.addAction(dismissAction)
                self.present(unlinkedCardAlert, animated: true)
            }
        })
    }

    func sessionM(_ sessionM: SessionM, didUpdateUser user: SMUser) {
        LoginViewController.loginIfNeeded(self)
    }

    @IBAction private func logout(_ sender: AnyObject) {
        sessionM.logOutUser()
    }
}
