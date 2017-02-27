//
//  ContentsTableViewController.swift
//  ios-swift-smp-sample
//
//  Copyright © 2017 SessionM. All rights reserved.
//

import UIKit

class ContentCell: UITableViewCell {
    @IBOutlet var name: UILabel!
    @IBOutlet var contentImage: UIImageView!
    @IBOutlet var imageHeight: NSLayoutConstraint!
    @IBOutlet var imageWidth: NSLayoutConstraint!
}

class ContentsTableViewController: UITableViewController, SessionMDelegate {
    private let sessionM = SessionM.sharedInstance()
    private let contentManager: SMContentManager = SessionM.sharedInstance().contentManager
    private var contents: [SMContent] = []

    @IBAction private func onRefresh(_ sender: UIRefreshControl) {
        fetchContents()
    }

    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)

        sessionM.delegate = self
        fetchContents()
    }

    private func fetchContents() {
        self.refreshControl?.beginRefreshing()
        contentManager.fetchContents(completionHandler: { (contents: [SMContent]?, placement: String?, error: SMError?) in
            if let err = error {
                Util.failed(self, message: err.message)
            } else if let newContents = contents {
                self.contents = newContents
                self.tableView.reloadData()
            }
            self.refreshControl?.endRefreshing()
        })
    }

    // MARK: - Table view data source

    override func numberOfSections(in tableView: UITableView) -> Int { return 1 }

    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return contents.count
    }

    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let content = contents[indexPath.row]
        let cell = tableView.dequeueReusableCell(withIdentifier: "ContentCell", for: indexPath) as? ContentCell

        if let c = cell {
            c.name.text = content.name
            c.tag = indexPath.row

            if let img = content.imageURL {
                Util.loadFrom(img, callback: { (image) in
                    c.contentImage.image = image
                    c.imageHeight.constant = min(c.bounds.size.height - c.name.bounds.size.height - 10.0, image.size.height)
                    c.imageWidth.constant = min(c.bounds.size.width, (((c.imageHeight.constant - 20.0) / image.size.height) * image.size.width))
                })
            }
        }

        return cell!
    }

    func sessionM(_ sessionM: SessionM, didUpdateUser user: SMUser) {
        LoginViewController.loginIfNeeded(self)
    }

    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        let destination = segue.destination as! ContentDetailsViewController
        let cell = sender as! ContentCell
        destination.content = contents[cell.tag]
    }

    @IBAction private func logout(_ sender: AnyObject) {
        sessionM.logOutUser()
    }
}
