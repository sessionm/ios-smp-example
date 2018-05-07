//
//  MessageDetailViewController.swift
//  SMPExample
//
//  Copyright © 2018 SessionM. All rights reserved.
//

import SessionMInboxKit
import UIKit

class MessageDetailViewController: UIViewController {
    @IBOutlet private var body: UILabel!

    private let inboxManager = SMInboxManager.instance()

    var message: SMInboxMessage!

    override func viewDidLoad() {
        super.viewDidLoad()

        self.navigationItem.title = message!.subject
        self.body.text = message.body
    }

    @IBAction private func showMessageOptions(_ sender: UIBarButtonItem) {
        let optionsAlert = UIAlertController(title: "Options", message: nil, preferredStyle: .actionSheet)
        let markAsNewAction = UIAlertAction(title: "Mark as New", style: .default, handler: { (action) in
            self.inboxManager.updateMessage(self.message, toState: .new, completionHandler: { (messages: [SMInboxMessage]?, error: SMError?) in })
        })
        let markAsReadAction = UIAlertAction(title: "Mark as Read", style: .default, handler: { (action) in
            self.inboxManager.updateMessage(self.message, toState: .read, completionHandler: { (messages: [SMInboxMessage]?, error: SMError?) in })
        })
        let deleteAction = UIAlertAction(title: "Delete", style: .destructive, handler: { (action) in
            self.inboxManager.updateMessage(self.message, toState: .deleted, completionHandler: { (messages: [SMInboxMessage]?, error: SMError?) in
                self.navigationController!.popViewController(animated: true)
            })
        })
        let cancelAction = UIAlertAction(title: "Cancel", style: .cancel)

        optionsAlert.addAction(markAsNewAction)
        optionsAlert.addAction(markAsReadAction)
        optionsAlert.addAction(deleteAction)
        optionsAlert.addAction(cancelAction)

        present(optionsAlert, animated: true)
    }
}
