//
//  CardLinkingViewController.swift
//  SMPExample
//
//  Copyright © 2018 SessionM. All rights reserved.
//

import SessionMLoyaltyCardsKit
import UIKit

class RetailerCell: UITableViewCell {
    @IBOutlet var retailerIcon: UIImageView!
    @IBOutlet var retailerName: UILabel!
    @IBOutlet var cardName: UILabel!
}

class CardLinkingViewController: UIViewController, UITableViewDataSource, UITableViewDelegate, UISearchBarDelegate {
    @IBOutlet private var tableView: UITableView!
    @IBOutlet private var linkButton: UIButton!
    @IBOutlet private var retailerName: UILabel!
    @IBOutlet private var cardNumber: UITextField!

    private let loyaltyCardsManager = SMLoyaltyCardsManager.instance()
    private var retailers: [SMRetailer] = []
    private var searchResults: [SMRetailer] = []
    private var selectedRetailer: SMRetailer?

    override func viewDidLoad() {
        super.viewDidLoad()

        linkButton.layer.cornerRadius = 5.0
        linkButton.layer.borderWidth = 0.5
        linkButton.layer.borderColor = UIColor(red: 0.639, green: 0.745, blue: 0.372, alpha: 1.0).cgColor
    }

    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        fetchRetailers()
    }

    private func fetchRetailers() {
        tableView.reloadData()
        loyaltyCardsManager.fetchRetailers(completionHandler: { (retailers: [SMRetailer]?, error: SMError?) in
            if let err = error {
                Util.failed(self, message: err.message)
            } else if let newRetailers = retailers {
                self.retailers = newRetailers
                self.searchResults = newRetailers
                self.tableView.reloadData()
            }
        })
    }

    // MARK: - Card Linking

    @IBAction private func linkCard(_ sender: UIButton) {
        guard let cardText = cardNumber.text, !cardText.isEmpty else {
            let missingCardAlert = UIAlertController(title: "Card Number Not Entered", message: "Card number is required", preferredStyle: .alert)
            let dismissAction = UIAlertAction(title: "OK", style: .default)
            missingCardAlert.addAction(dismissAction)
            present(missingCardAlert, animated: true)
            return
        }
        guard let retailer = selectedRetailer else {
            let missingRetailerAlert = UIAlertController(title: "Retailer Not Selected", message: "Retailer is required", preferredStyle: .alert)
            let dismissAction = UIAlertAction(title: "OK", style: .default)
            missingRetailerAlert.addAction(dismissAction)
            present(missingRetailerAlert, animated: true)
            return
        }

        let linkCardAlert = UIAlertController(title: "Linking Card", message: "Linking card #\(cardText) from \(retailer.name!)", preferredStyle: .alert)
        present(linkCardAlert, animated: true, completion: {
            self.loyaltyCardsManager.linkCard(havingNumber: cardText, retailerID: retailer.retailerID, completionHandler: { (cardNumber: String?, error: SMError?) in
                self.dismiss(animated: true, completion: {
                    if let e = error {
                        Util.failed(self, message: e.message)
                    } else {
                        let linkedCardAlert = UIAlertController(title: "Card Linked", message: nil, preferredStyle: .alert)
                        let dismissAction = UIAlertAction(title: "OK", style: .default)
                        linkedCardAlert.addAction(dismissAction)
                        self.present(linkedCardAlert, animated: true)
                    }
                })
            })
        })
    }

    func searchBar(_ searchBar: UISearchBar, textDidChange searchText: String) {
        searchResults = retailers.filter({ (retailer) -> Bool in
            let search = searchText.lowercased()
            return search.isEmpty || retailer.name!.lowercased().contains(search) || retailer.card!.lowercased().contains(search)
        })
        tableView.reloadData()
    }

    // MARK: - Table view data source

    func numberOfSections(in tableView: UITableView) -> Int { return 1 }

    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return searchResults.count
    }

    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let retailer = searchResults[indexPath.row]
        let cell = tableView.dequeueReusableCell(withIdentifier: "RetailerCell", for: indexPath) as? RetailerCell

        if let c = cell {
            c.cardName.text = retailer.card
            c.retailerName.text = retailer.name
            if let icon = retailer.iconURL {
                Util.loadFrom(icon, callback: { (image) in
                    c.retailerIcon.image = image
                })
            }
        }

        return cell!
    }

    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        selectedRetailer = searchResults[indexPath.row]
        retailerName.text = selectedRetailer!.name
    }

    @IBAction private func logout(_ sender: AnyObject) {
        if let provider = SessionM.authenticationProvider() as? SessionMOAuthProvider {
            provider.logOutUser { (authState, error) in
                LoginViewController.loginIfNeeded(self)
            }
        }
    }
}
