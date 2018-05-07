//
//  PlaceOrderViewController.swift
//  SMPExample
//
//  Copyright © 2018 SessionM. All rights reserved.
//

import SessionMRewardsKit
import UIKit

class PlaceOrderViewController: UIViewController {
    @IBOutlet private var subheader: UIWebView!
    @IBOutlet private var header: UILabel!
    @IBOutlet private var details: UILabel!

    private let rewardsManager = SMRewardsManager.instance()
    private var alert: UIAlertController?

    var offer: SMOffer?

    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)

        if let o = self.offer, let data = o.data {
            header.text = o.name
            if let shipping = data["shipping_information"] as? String {
                details.text = shipping
            }
            if let html = data["long_description"] as? String {
                subheader.loadHTMLString(html.replacingOccurrences(of: "\\n", with: ""), baseURL: nil)
            }
        }
    }

    @IBAction private func placeOrder(_ sender: UIButton) {
        if let o = offer {
            if o.isSkillChallengeRequired {
                alert = UIAlertController(title: "Skill Question", message: "Fetching Skill Question", preferredStyle: .alert)
                present(alert!, animated: true, completion: nil)

                rewardsManager.fetchSkillQuestion(completionHandler: { (skillQuestion: SMSkillQuestion?, error: SMError?) in
                    if let err = error {
                        self.alert!.dismiss(animated: true) {
                            Util.failed(self, message: err.message)
                        }
                    } else if let question = skillQuestion {
                        self.onFetchSkillQuestion(question)
                    }
                })
            } else {
                placeTheOrder(o, challenge: nil)
            }
        }
    }

    private func onFetchSkillQuestion(_ skillQuestion: SMSkillQuestion) {
        if let a = alert {
            a.dismiss(animated: true, completion: {
                self.perform(#selector(self.gotQuestion), with: skillQuestion, afterDelay: 0.0)
            })
        }
    }

    @objc private func gotQuestion(_ skillQuestion: SMSkillQuestion) {
        self.alert = UIAlertController(title: "Skill Question", message: skillQuestion.question, preferredStyle: .alert)
        if let a = self.alert {
            a.addTextField(configurationHandler: { (textField: UITextField) in
                textField.placeholder = "Math!"
                textField.keyboardType = .decimalPad
            })
            a.addAction(UIAlertAction(title: "Submit", style: .default, handler: { (action: UIAlertAction) in
                a.dismiss(animated: true, completion: nil)
                if let fields = a.textFields, let text = fields[0].text {
                    self.perform(#selector(self.gotAnswer),
                                         with: [ "QuestionID": skillQuestion.questionID, "Answer": text ], afterDelay: 0.0)
                }
            }))
            a.view.setNeedsLayout()
            present(a, animated: true, completion: nil)
        }
    }

    @objc private func gotAnswer(_ data: [String : String]) {
        alert = UIAlertController(title: "Submitting Answer", message: "Thinking", preferredStyle: .alert)
        present(alert!, animated: true, completion: nil)
        if let o = offer, let questionID = data["QuestionID"], let answer = data["Answer"] {
            rewardsManager.answerSkillQuestion(forOfferID: o.offerID, questionID: questionID, answer: answer, completionHandler: { (skillChallenge: SMSkillChallenge?, error: SMError?) in
                if let err = error {
                    self.alert!.dismiss(animated: true) {
                        Util.failed(self, message: err.message)
                    }
                } else {
                    self.onAnswerSkillQuestion(skillChallenge)
                }
            })
        }
    }

    private func onAnswerSkillQuestion(_ challenge: SMSkillChallenge?) {
        if let a = alert {
            a.dismiss(animated: true, completion: {
                self.perform(#selector(self.placingOrder), with: challenge, afterDelay: 0.0)
            })
        }
    }

    @objc private func placingOrder(_ challenge: SMSkillChallenge?) {
        if let o = offer {
            placeTheOrder(o, challenge: challenge)
        }
    }

    private func placeTheOrder(_ offer: SMOffer, challenge: SMSkillChallenge?) {
        let request = SMOrderRequest(offerID: offer.offerID, quantity: 1)
        if let c = challenge {
            request.challengeID = c.challengeID
        }

        if let name = offer.name {
            self.alert = UIAlertController(title: "Placing Order", message: "Ordering: \(name)", preferredStyle: .alert)
            if let a = self.alert {
                self.present(a, animated: true, completion: nil)
                rewardsManager.placeOrder(request, completionHandler: { (order: SMOrder?, error: SMError?) in
                    if let err = error {
                        a.dismiss(animated: true) {
                            Util.failed(self, message: err.message)
                        }
                    } else {
                        if let o = order {
                            self.onPlaceOrder(o)
                        }
                    }
                })
            }
        }
    }

    private func onPlaceOrder(_ order: SMOrder) {
        if let a = self.alert {
            a.dismiss(animated: true, completion: {
                self.perform(#selector(self.placedOrder), with: order, afterDelay: 0.0)
            })
        }
    }

    @objc private func placedOrder(_ order: SMOrder) {
        self.alert = UIAlertController(title: "Placed Order", message: "Order: \(order.name!)", preferredStyle: .alert)
        if let a = self.alert {
            a.addAction(UIAlertAction(title: "Done", style: .cancel, handler: nil))
            self.present(a, animated: true, completion: nil)
        }
    }
}
