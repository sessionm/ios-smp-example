//
//  PurchaseEventViewController.swift
//  SMPExample
//
//  Created by Paul Mattheis on 9/18/17.
//  Copyright © 2017 SessionM. All rights reserved.
//

import UIKit

class PurchaseEventViewController: UIViewController {

    var showing : BehaviorsList.OrderShowing = .behavior
    var behaviors : BehaviorsList? = nil;

    let eventsManager = SMEventsManager.instance()
    var purchaseBuilder = SMPurchaseEventBuilder();
    var items : [SMPurchaseEventItem] = [];

    @IBOutlet weak var behaviorsList: UITextView!
    @IBOutlet weak var itemsList: UITextView!

    @IBOutlet weak var name: UITextField!
    @IBOutlet weak var quantity: UITextField!
    @IBOutlet weak var amount: UITextField!
    @IBOutlet weak var store: UITextField!


    func fetchBehaviors() {
        eventsManager.fetchBehaviorProgress { (response: SMBehaviorProgressFetchedResponse?, error: SMError?) in
            self.behaviors = BehaviorsList(behaviors: response);
            self.behaviorsList.text = self.behaviors?.show(showing: self.showing);
        }
    }

    @IBAction func doAddItem(_ sender: UIButton) {

        var add = false;
        let builder = SMPurchaseEventItemBuilder();

        if let n = name.text, n.characters.count > 0 {
            add = true;
            builder.name = n;
        }
        if let q = quantity.text, q.characters.count > 0, let qty = Int(q) {
            add = true;
            builder.quantity = qty
        }
        if let a = amount.text, a.characters.count > 0, let amt = Double(a) {
            add = true;
            builder.amount = Int(amt * 100.0);
        }
        if let s = store.text, s.characters.count > 0 {
            add = true;
            builder.store = s;
        }

        if (add) {
            items.append(builder.build())
            purchaseBuilder.addItem(from: builder)
            var text = ""
            for item in items {
                if let n = item.name { text += "\(n)\t"; }
                if let s = item.store { text += "\(s)\t"; }
                if item.quantity > 0 { text += "\(item.quantity)\t"; }
                if item.amount > 0 { text += "\(item.amount)\t"; }
                text += "\n";
            }
            itemsList.text = "\(text)\n";
        }

    }

    @IBAction func doPostEvent(_ sender: UIButton) {
        eventsManager.postEvent(from: purchaseBuilder) { (response: SMEventPostedResponse?, error: SMError?) in
            if let err = error {
                let vc = UIAlertController(title: "Error Posting", message: "\(err.message)", preferredStyle: .alert);
                vc.addAction(UIAlertAction(title: "Ok", style: .default, handler: nil))
                self.present(vc, animated: true, completion: nil)
            } else {
                self.behaviors = BehaviorsList(behaviors: response);
                self.behaviorsList.text = self.behaviors?.show(showing: self.showing)
            }
        }
    }

    override func viewDidLoad() {
        super.viewDidLoad()
    }

    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)

        purchaseBuilder = SMPurchaseEventBuilder();

        decideTab()
        fetchBehaviors()
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
