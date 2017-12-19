//
//  ReferralDetailViewController.swift
//  SMPExample
//
//  Copyright © 2017 SessionM. All rights reserved.
//

import UIKit

class ReferralDetailViewController: UIViewController, UITextViewDelegate, UITextFieldDelegate {
    @IBOutlet private var idTop: NSLayoutConstraint!
    @IBOutlet private var idLabel: UILabel!
    @IBOutlet private var referralID: UILabel!
    @IBOutlet private var statusLabel: UILabel!
    @IBOutlet private var status: UILabel!
    @IBOutlet private var pendingTimeLabel: UILabel!
    @IBOutlet private var pendingTime: UILabel!
    @IBOutlet private var referee: UITextField!
    @IBOutlet private var email: UITextField!
    @IBOutlet private var phoneNumber: UITextField!
    @IBOutlet private var source: UITextField!
    @IBOutlet private var origin: UITextField!
    @IBOutlet private var clientData: UITextView!
    @IBOutlet private var submit: UIButton!

    private var baseY: CGFloat = 0.0
    private var latestY: CGFloat = 0.0

    var isAddingReferral = false
    var referral: SMReferral?

    @IBAction private func submit(_ sender: UIButton) {
        guard let emailText = email.text, emailText.characters.count > 0 else {
            let emailMissing = UIAlertController(title: "Email Missing", message: "Email is required", preferredStyle: .alert)
            emailMissing.addAction(UIAlertAction(title: "Dismiss", style: .default))
            self.present(emailMissing, animated: true)
            return
        }

        let referralRequest = SMReferralRequest(email: emailText, name: referee.text, phoneNumber: phoneNumber.text, origin: origin.text, source: source.text, clientData: clientData.text)
        let referralsRequest = SMReferralsRequest(requests: [referralRequest], referrer: "Me")
        SessionM.sharedInstance().referralsManager.sendReferrals(referralsRequest, completionHandler: {(referrals: [SMReferral]?, referralErrors: [SMReferralError]?, error: SMError?) in
            let referralAlert = UIAlertController(title: nil, message: nil, preferredStyle: .alert)
            var alertHandler: ((UIAlertAction?) -> Void)?
            if let errors = referralErrors {
                referralAlert.title = "Error"
                if let firstError = errors.first {
                    referralAlert.message = "\(firstError.referral.email)\n\(firstError.error.message)"
                } else {
                    referralAlert.message = "Error encountered when submitting referral"
                }
            } else {
                referralAlert.title = "Success"
                referralAlert.message = "Refferal sent to \(emailText)"
                alertHandler = { (action: UIAlertAction?) in
                    self.navigationController!.popViewController(animated: true)
                }
            }
            referralAlert.addAction(UIAlertAction(title: "Dismiss", style: .default, handler: alertHandler))
            self.present(referralAlert, animated: true)
        })
    }

    override func viewDidLoad() {
        super.viewDidLoad()

        clientData.delegate = self
        referee.delegate = self
        email.delegate = self
        phoneNumber.delegate = self
        source.delegate = self
        origin.delegate = self

        NotificationCenter.default.addObserver(self, selector: #selector(keyboardWillShow(_:)), name: .UIKeyboardWillShow, object: nil)
        NotificationCenter.default.addObserver(self, selector: #selector(keyboardWillHide(_:)), name: .UIKeyboardWillHide, object: nil)

        let tap = UITapGestureRecognizer(target: self, action: #selector(endEditing(_:)))
        self.view.addGestureRecognizer(tap)

        baseY = idTop.constant
    }

    @objc private func endEditing(_: UITapGestureRecognizer) {
        self.view.endEditing(true)
    }

    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        self.updateFieldVisibility()

        if !isAddingReferral, let r = referral {
            referralID.text = r.referralID
            status.text = SMReferral.string(from: r.status)
            pendingTime.text = r.pendingTime
            referee.text = r.referee
            email.text = r.email
            phoneNumber.text = r.phoneNumber
            source.text = r.source
            origin.text = r.origin
            clientData.text = "\(String(describing: r.clientData))"
        }
    }

    private func updateFieldVisibility() {
        if isAddingReferral {
            idTop.constant = baseY - (idLabel.frame.size.height + statusLabel.frame.size.height + pendingTimeLabel.frame.size.height)

            submit.isHidden = false
            idLabel.isHidden = true
            referralID.isHidden = true
            statusLabel.isHidden = true
            status.isHidden = true
            pendingTimeLabel.isHidden = true
            pendingTime.isHidden = true

            referee.borderStyle = .roundedRect
            email.borderStyle = .roundedRect
            phoneNumber.borderStyle = .roundedRect
            source.borderStyle = .roundedRect
            origin.borderStyle = .roundedRect

            referee.isEnabled = true
            email.isEnabled = true
            phoneNumber.isEnabled = true
            source.isEnabled = true
            origin.isEnabled = true
        } else {
            idTop.constant = baseY

            submit.isHidden = true
            idLabel.isHidden = false
            referralID.isHidden = false
            statusLabel.isHidden = false
            status.isHidden = false
            pendingTimeLabel.isHidden = false
            pendingTime.isHidden = false

            referee.borderStyle = .none
            email.borderStyle = .none
            phoneNumber.borderStyle = .none
            source.borderStyle = .none
            origin.borderStyle = .none

            referee.isEnabled = false
            email.isEnabled = false
            phoneNumber.isEnabled = false
            source.isEnabled = false
            origin.isEnabled = false
        }
    }

    func textViewShouldBeginEditing(_ textView: UITextView) -> Bool {
        latestY = textView.frame.origin.y
        return isAddingReferral
    }

    func textFieldShouldBeginEditing(_ textField: UITextField) -> Bool {
        latestY = textField.frame.origin.y
        return true
    }

    func textFieldShouldReturn(_ textField: UITextField) -> Bool {
        textField.resignFirstResponder()
        return true
    }

    @objc private func keyboardWillShow(_ notification: Notification) {
        idTop.constant = 80.0 - latestY
    }

    @objc private func keyboardWillHide(_ notification: Notification) {
        idTop.constant = baseY - (idLabel.frame.size.height + statusLabel.frame.size.height + pendingTimeLabel.frame.size.height)
    }
}
