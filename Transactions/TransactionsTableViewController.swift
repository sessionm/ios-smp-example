//
//  TransactionsTableViewController.swift
//  SMPExample
//
//  Copyright © 2018 SessionM. All rights reserved.
//

import SessionMLoyaltyCardsKit
import SessionMReceiptsKit
import SessionMTransactionsKit
import UIKit

class TransactionCell: UITableViewCell {
    @IBOutlet var balanceLabel: UILabel!
    @IBOutlet var dateLabel: UILabel!
    @IBOutlet var descriptionLabel: UILabel!
    @IBOutlet var pointsLabel: UILabel!
    @IBOutlet var recordIDLabel: UILabel!
    @IBOutlet var transactionLabel: UILabel!
    @IBOutlet var sourceLabel: UILabel!
    @IBOutlet var typeLabel: UILabel!
}

class TransactionsTableViewController: UITableViewController {
    private let transactionsManager = SMTransactionsManager.instance()
    private let receiptsManager = SMReceiptsManager.instance()
    private let loyaltyCardsManager = SMLoyaltyCardsManager.instance()

    private var recordModelID: String?
    private var transactions: [SMTransaction] = []

    @IBAction private func onRefresh(_ sender: UIRefreshControl) {
        fetchTransactions()
    }

    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        fetchTransactions()
    }

    private func fetchTransactions() {
        self.refreshControl?.beginRefreshing()
        transactionsManager.fetchTransactions(completionHandler: { (transactions: [SMTransaction]?, hasMore: Bool, error: SMError?) in
            if let err = error {
                Util.failed(self, message: err.message)
            } else if let trans = transactions {
                self.onFetchTransactions(trans, hasMore: hasMore)
            }
            self.refreshControl?.endRefreshing()
        })
    }

    private func onFetchTransactions(_ transactions: [SMTransaction], hasMore: Bool) {
        self.transactions = transactions
        self.tableView.reloadData()
        if (hasMore) {
            self.refreshControl?.beginRefreshing()
            transactionsManager.fetchMoreTransactions(completionHandler: { (transactions: [SMTransaction]?, hasMore: Bool, error: SMError?) in
                if let err = error {
                    Util.failed(self, message: err.message)
                } else if let trans = transactions {
                    self.onFetchTransactions(trans, hasMore: hasMore)
                }
                self.refreshControl?.endRefreshing()
            })
        }
    }

    // MARK: - Table view data source

    override func numberOfSections(in tableView: UITableView) -> Int { return 1 }

    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return self.transactions.count
    }


    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "TransactionCell", for: indexPath) as! TransactionCell

        let transaction = self.transactions[indexPath.row]

        cell.balanceLabel?.text = "\(transaction.balance)"
        cell.dateLabel?.text = transaction.date
        cell.descriptionLabel?.text = transaction.details
        cell.pointsLabel?.text = "\(transaction.points)"
        cell.recordIDLabel?.text = transaction.recordID
        cell.transactionLabel?.text = SMTransaction.string(from: transaction.transaction)
        cell.sourceLabel?.text = SMTransaction.string(from: transaction.source)
        cell.typeLabel?.text = SMTransaction.string(from: transaction.type)

        return cell
    }

    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        let transaction = self.transactions[indexPath.row]
        self.recordModelID = transaction.recordModelID
        if (transaction.type == .receipt) {
            receiptsManager.fetchReceipts(completionHandler: { (receipts: [SMReceipt]?, error: SMError?) in
                if let err = error {
                    Util.failed(self, message: err.message)
                } else if let recps = receipts {
                    self.onFetchReceipts(recps)
                }
            })
        } else if (transaction.type == .loyaltyCard) {
            loyaltyCardsManager.fetchCardTransactions(completionHandler: { (transactions: [SMLoyaltyCardTransaction]?, error: SMError?) in
                if let err = error {
                    Util.failed(self, message: err.message)
                } else if let trans = transactions {
                    self.onFetchLoyaltyCardTransactions(trans)
                }
            })
        }
    }

    private func onFetchReceipts(_ receipts: [SMReceipt]) {
        var msg = ""
        for receipt in receipts {
            if let rs = receipt.results {
                for result in rs {
                    if (result.resultID == self.recordModelID) {
                        msg += "\(receipt.receiptID) \(String(describing: result.name))\n \(String(describing: result.details))"
                        break
                    }
                }
            }
        }
        let controller = UIAlertController(title: "Receipt", message: msg, preferredStyle: .alert)
        controller.addAction(UIAlertAction(title: "Dismiss", style: .default, handler: nil))
        self.present(controller, animated: true, completion: nil)
    }

    private func onFetchLoyaltyCardTransactions(_ transactions: [SMLoyaltyCardTransaction]) {
        for transaction in transactions {
            if (transaction.transactionID == self.recordModelID) {
                let msg = "\(transaction.name!)\n\(transaction.details!)\n\(transaction.quantity) @ \(transaction.price)"
                let controller = UIAlertController(title: "Loyalty Card", message: msg, preferredStyle: .alert)
                controller.addAction(UIAlertAction(title: "Dismiss", style: .default, handler: nil))
                self.present(controller, animated: true, completion: nil)
                break
            }
        }
    }

    @IBAction private func logout(_ sender: AnyObject) {
        if let provider = SessionM.authenticationProvider() as? SessionMOauthProvider {
            provider.logoutUser { (authState, error) in
                LoginViewController.loginIfNeeded(self)
            }
        }
    }
}
