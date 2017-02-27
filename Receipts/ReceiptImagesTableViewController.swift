//
//  ReceiptImagesTableViewController.swift
//  SMPExample
//
//  Copyright © 2017 SessionM. All rights reserved.
//

import UIKit

class ReceiptImagesTableViewController: UITableViewController {
    var receipt: SMReceipt!

    override func viewDidLoad() {
        super.viewDidLoad()

        tableView.register(UITableViewCell.self, forCellReuseIdentifier: "ReceiptImageCell")
        tableView.rowHeight = tableView.frame.size.width
    }

    // MARK: - Table view data source

    override func numberOfSections(in tableView: UITableView) -> Int { return 1 }

    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return receipt.imageURLs!.count
    }

    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "ReceiptImageCell", for: indexPath)

        guard let img = receipt.imageURLs?[indexPath.row], img.characters.count > 0 else {
            return cell
        }

        Util.loadFrom(img, callback: { (image) in
            let receiptImage = UIImageView(frame: CGRect.zero)
            cell.contentView.addSubview(receiptImage)
            Util.imageToView(image, view: receiptImage, contain: cell.contentView)
        })

        return cell
    }
}
