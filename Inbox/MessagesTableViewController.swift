//
//  MessagesTableViewController.swift
//  SMPExample
//
//  Copyright © 2018 SessionM. All rights reserved.
//

import SessionMInboxKit
import UIKit

class MessageCell: UITableViewCell {
    @IBOutlet var subject: UILabel!
    @IBOutlet var createdTime: UILabel!
}

class MessagesTableViewController: UITableViewController {
    private let inboxManager = SMInboxManager.instance()
    private var messages: [SMInboxMessage] = []
    private var selectedMessages: [SMInboxMessage] = []

    @IBAction private func onRefresh(_ sender: UIRefreshControl) {
        fetchMessages()
    }

    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        fetchMessages()
    }

    private func fetchMessages() {
        self.refreshControl?.beginRefreshing()
        inboxManager.fetchMessages(completionHandler: { (messages: [SMInboxMessage]?, error: SMError?) in
            if let err = error {
                Util.failed(self, message: err.message)
            } else if let newMessages = messages {
                self.messages = newMessages
                self.tableView.reloadData()
            }
            self.refreshControl?.endRefreshing()
        })
    }

    // MARK: - Table view data source

    override func numberOfSections(in tableView: UITableView) -> Int { return 1 }

    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return messages.count
    }

    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let message = messages[indexPath.row]
        let cell = tableView.dequeueReusableCell(withIdentifier: "MessageCell", for: indexPath) as? MessageCell

        if let c = cell {
            c.subject.text = message.subject
            if let time = message.createdTime {
                let formatter = DateFormatter()
                formatter.dateFormat = "yyyy-MM-dd'T'HH:mm:ss'Z'"
                if let date = formatter.date(from: time) {
                    if Calendar.current.isDateInToday(date) {
                        formatter.dateStyle = .none
                        formatter.timeStyle = .short
                    } else {
                        formatter.dateStyle = .short
                        formatter.timeStyle = .none
                    }
                    c.createdTime.text = formatter.string(from: date)
                } else {
                    c.createdTime.text = ""
                }
            }
            switch message.state {
            case .new:
                c.subject.font = UIFont.boldSystemFont(ofSize: c.subject.font.pointSize)
                c.createdTime.font = UIFont.boldSystemFont(ofSize: c.subject.font.pointSize)
                c.backgroundColor = UIColor.white
            case .read:
                c.subject.font = UIFont.systemFont(ofSize: c.subject.font.pointSize)
                c.createdTime.font = UIFont.systemFont(ofSize: c.subject.font.pointSize)
                c.backgroundColor = UIColor(red: 0.95, green: 0.95, blue: 0.95, alpha: 1.0)
            default:
                break
            }
            c.tag = indexPath.row
        }

        return cell!
    }

    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        let destination = segue.destination as! MessageDetailViewController
        let cell = sender as! MessageCell
        destination.message = messages[cell.tag]
        inboxManager.updateMessage(destination.message!, toState: .read, completionHandler: { (messages: [SMInboxMessage]?, error: SMError?) in })
    }

    @IBAction private func logout(_ sender: AnyObject) {
        if let provider = SessionM.authenticationProvider() as? SessionMOAuthProvider {
            provider.logOutUser { (authState, error) in
                LoginViewController.loginIfNeeded(self)
            }
        }
    }
}
