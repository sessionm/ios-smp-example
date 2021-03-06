//
//  ViewController.swift
//  Events
//
//  Copyright © 2018 SessionM. All rights reserved.
//

import SessionMEventsKit
import UIKit

class ViewController: UIViewController {

    @IBOutlet weak var user: UILabel!
    @IBOutlet weak var points: UILabel!
    @IBOutlet weak var authenticate: UIButton!
    @IBOutlet weak var eventName: UITextField!
    @IBOutlet weak var behaviorsList: UITextView!

    var showing: BehaviorsList.OrderShowing = .behavior
    let eventsManager = SMEventsManager.instance()
    var behaviors: BehaviorsList? = nil;

    @IBAction func postEvent(_ sender: UIButton) {
        if let eventName = eventName.text {
            if eventName.count > 0 {
                let itemBuilder = SMActivityEventItemBuilder();
                let builder = SMActivityEventBuilder(eventName: eventName)
                builder.addItem(from: itemBuilder)
                eventsManager.postEvent(builder.build(), completionHandler: { (response: SMEventPostedResponse?, error: SMError?) in
                    if let err = error {
                        let vc = UIAlertController(title: "Error Posting", message: "\(err.message)", preferredStyle: .alert);
                        vc.addAction(UIAlertAction(title: "Ok", style: .default, handler: nil))
                        self.present(vc, animated: true, completion: nil)
                    } else {
                        self.behaviors = BehaviorsList(behaviors: response);
                        self.behaviorsList.text = self.behaviors?.show(showing: self.showing)
                    }
                })
            }
        }
    }

    @IBAction func quickPostEvent(_ sender: UIButton) {
        if let eventName = eventName.text {
            if eventName.count > 0 {
                eventsManager.postEvent(SMSimpleEventBuilder(eventName: eventName).build(), completionHandler: { (response: SMEventPostedResponse?, error: SMError?) in
                    if let err = error {
                        let vc = UIAlertController(title: "Error Posting", message: "\(err.message)", preferredStyle: .alert);
                        vc.addAction(UIAlertAction(title: "Ok", style: .default, handler: nil))
                        self.present(vc, animated: true, completion: nil)
                    } else {
                        self.behaviors = BehaviorsList(behaviors: response);
                        self.behaviorsList.text = self.behaviors?.show(showing: self.showing)
                    }
                })
            }
        }
    }

    func fetchBehaviors() {
        eventsManager.fetchBehaviorProgress { (response: SMBehaviorProgressFetchedResponse?, error: SMError?) in
            self.behaviors = BehaviorsList(behaviors: response);
            self.behaviorsList.text = self.behaviors?.show(showing: self.showing);
        }
    }

    override func viewDidLoad() {
        super.viewDidLoad()

    }

    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)

        if let usr = SMUserManager.instance().currentUser {
            user.text = usr.email;
            points.text = "\(usr.availablePoints) pts"
        }

        decideTab()

        fetchBehaviors()
    }

    @IBAction func doAuthenticate(_ sender: UIButton) {
        if let provider = SessionM.authenticationProvider() as? SessionMOAuthProvider {
            provider.logOutUser { (authState, error) in
                LoginViewController.loginIfNeeded(self)
            }
        }
    }

    @IBOutlet weak var leftLine: UIView!
    @IBOutlet weak var behaviorOrder: UIButton!

    @IBAction func doBehaviorOrder(_ sender: UIButton) {
        showing = .behavior;
        decideTab()
    }

    @IBOutlet weak var rightLine: UIView!
    @IBOutlet weak var eventsOrder: UIButton!

    @IBAction func doEventsOrder(_ sender: UIButton) {
        showing = .events
        decideTab()
    }

    func decideTab() {
        if (showing == .behavior) {
            leftLine.isHidden = false;
            rightLine.isHidden = true;
        } else {
            leftLine.isHidden = true;
            rightLine.isHidden = false;
        }
        self.behaviorsList.text = self.behaviors?.show(showing: showing);
    }
}
