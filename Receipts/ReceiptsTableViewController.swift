//
//  ReceiptsTableViewController.swift
//  SMPExample
//
//  Copyright © 2018 SessionM. All rights reserved.
//

import SessionMReceiptsKit
import UIKit

class ReceiptCell: UITableViewCell {
    @IBOutlet var receiptID: UILabel!
    @IBOutlet var status: UILabel!
    @IBOutlet var uploadedTime: UILabel!
    @IBOutlet var imageCount: UILabel!
}

class ReceiptsTableViewController: UITableViewController {
    private var receiptsManager = SMReceiptsManager.instance()
    private var receipts: [SMReceipt] = []

    @IBAction private func addReceipt(_ sender: UIBarButtonItem) {
        present(ReceiptUploadViewController(), animated: true)
    }

    @IBAction private func onRefresh(_ sender: UIRefreshControl) {
        fetchReceipts()
    }

    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        fetchReceipts()
    }

    private func fetchReceipts() {
        self.refreshControl?.beginRefreshing()
        receiptsManager.fetchReceipts(completionHandler: { (receipts: [SMReceipt]?, error: SMError?) in
            if let err = error {
                Util.failed(self, message: err.message)
            } else if let newReceipts = receipts {
                self.receipts = newReceipts
                self.tableView.reloadData()
            }
            self.refreshControl?.endRefreshing()
        })
    }

    // MARK: - Table view data source

    override func numberOfSections(in tableView: UITableView) -> Int { return 1 }

    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return receipts.count
    }

    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let receipt = receipts[indexPath.row]
        let cell = tableView.dequeueReusableCell(withIdentifier: "ReceiptCell", for: indexPath) as? ReceiptCell

        if let c = cell {
            c.receiptID.text = "ID: \(receipt.receiptID)"
            c.uploadedTime.text = "Uploaded Time: \(receipt.createdTime!)"
            c.imageCount.text = "Image Count: (Count: \(receipt.imageCount)) (URLs: \(receipt.imageURLs!.count))"
            switch receipt.status {
            case .invalid:
                c.status.text = receipt.invalidReason
            default:
                c.status.text = "Status: \(SMReceipt.string(from: receipt.status).capitalized)"
            }
            c.tag = indexPath.row
        }

        return cell!
    }

    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        let destination = segue.destination as! ReceiptImagesTableViewController
        let cell = sender as! ReceiptCell
        destination.receipt = receipts[cell.tag]
    }

    @IBAction private func logout(_ sender: AnyObject) {
        if let provider = SessionM.authenticationProvider() as? SessionMOAuthProvider {
            provider.logOutUser { (authState, error) in
                LoginViewController.loginIfNeeded(self)
            }
        }
    }
}
