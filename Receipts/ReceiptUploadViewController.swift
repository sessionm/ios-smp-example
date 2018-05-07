//
//  ReceiptUploadViewController.swift
//  SMPExample
//
//  Copyright © 2018 SessionM. All rights reserved.
//

import Foundation
import Photos
import SessionMReceiptsKit

class ReceiptUploadViewController: UIViewController, UIImagePickerControllerDelegate, UINavigationControllerDelegate {
    private let imagePicker = UIImagePickerController()
    private let campaignID = "105"
    private let dismissButtonBase64 = "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"

    private var dismissButton: UIButton!, addImageButton: UIButton!, useImagesButton: UIButton!, progressActionButton: UIButton!, progressDismissButton: UIButton!
    private var titleLabel: UILabel!, progressDescriptionlabel: UILabel!, progressTitleLabel: UILabel!
    private var selectedImagesView: UIImageView!
    private var selectedImages = [UIImage]()
    private var filePaths = [String]()
    private var hasPrompted = false

    // MARK: - UIViewController overrides

    override func viewDidLoad() {
        super.viewDidLoad()

        view.backgroundColor = UIColor.white

        let dismissImageData = Data(base64Encoded: dismissButtonBase64, options: .ignoreUnknownCharacters)
        let dismissImage = UIImage(data: dismissImageData!)
        dismissButton = UIButton(type: .custom)
        dismissButton.addTarget(self, action: #selector(cleanUpAndDismiss), for: .touchUpInside)
        dismissButton.setImage(dismissImage, for: .normal)
        dismissButton.translatesAutoresizingMaskIntoConstraints = false
        dismissButton.isHidden = true
        view.addSubview(dismissButton)

        addImageButton = UIButton(type: .system)
        addImageButton.addTarget(self, action: #selector(openImageSourcePrompt), for: .touchUpInside)
        addImageButton.setTitle("Add Image", for: .normal)
        addImageButton.titleLabel?.font = UIFont.systemFont(ofSize: 20)
        addImageButton.translatesAutoresizingMaskIntoConstraints = false
        view.addSubview(addImageButton)

        useImagesButton = UIButton(type: .system)
        useImagesButton.addTarget(self, action: #selector(openProgressView), for: .touchUpInside)
        useImagesButton.setTitle("Upload Images", for: .normal)
        useImagesButton.titleLabel?.font = UIFont.systemFont(ofSize: 20)
        useImagesButton.translatesAutoresizingMaskIntoConstraints = false
        useImagesButton.isHidden = true
        view.addSubview(useImagesButton)

        titleLabel = UILabel()
        titleLabel.textAlignment = .center
        titleLabel.text = "Upload Receipt Images"
        titleLabel.font = UIFont.boldSystemFont(ofSize: 21)
        titleLabel.adjustsFontSizeToFitWidth = true
        titleLabel.translatesAutoresizingMaskIntoConstraints = false
        view.addSubview(titleLabel)

        selectedImagesView = UIImageView()
        selectedImagesView.translatesAutoresizingMaskIntoConstraints = false
        selectedImagesView.isHidden = true
        view.addSubview(selectedImagesView)

        let variableBindings = ["dismissButton": dismissButton,
                                "titleLabel": titleLabel,
                                "selectedImagesView": selectedImagesView,
                                "addImageButton": addImageButton,
                                "useImagesButton": useImagesButton] as [String : Any]

        view.addConstraints(NSLayoutConstraint.constraints(withVisualFormat: "H:[dismissButton(==50)]|",
                                                           options: NSLayoutFormatOptions(rawValue: 0),
                                                           metrics: nil,
                                                           views: variableBindings))
        view.addConstraints(NSLayoutConstraint.constraints(withVisualFormat: "V:|-[dismissButton(==50)]-[titleLabel]-[selectedImagesView]-[addImageButton]-|",
                                                           options: NSLayoutFormatOptions(rawValue: 0),
                                                           metrics: nil,
                                                           views: variableBindings))
        view.addConstraints(NSLayoutConstraint.constraints(withVisualFormat: "H:|-15-[addImageButton]",
                                                           options: NSLayoutFormatOptions(rawValue: 0),
                                                           metrics: nil,
                                                           views: variableBindings))
        view.addConstraints(NSLayoutConstraint.constraints(withVisualFormat: "H:[useImagesButton]-15-|",
                                                           options: NSLayoutFormatOptions(rawValue: 0),
                                                           metrics: nil,
                                                           views: variableBindings))
        view.addConstraints(NSLayoutConstraint.constraints(withVisualFormat: "H:|-[titleLabel]-|",
                                                           options: NSLayoutFormatOptions(rawValue: 0),
                                                           metrics: nil,
                                                           views: variableBindings))
        view.addConstraints(NSLayoutConstraint.constraints(withVisualFormat: "H:|-[selectedImagesView]-|",
                                                           options: NSLayoutFormatOptions(rawValue: 0),
                                                           metrics: nil,
                                                           views: variableBindings))
        view.addConstraint(NSLayoutConstraint(item: addImageButton,
                                              attribute: .centerY,
                                              relatedBy: .equal,
                                              toItem: useImagesButton,
                                              attribute: .centerY,
                                              multiplier: 1,
                                              constant: 0))

        imagePicker.delegate = self
        imagePicker.allowsEditing = false
    }

    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)

        if !hasPrompted {
            hasPrompted = true
            openImageSourcePrompt()
        }
    }

    // MARK: - UIImagePickerControllerDelegate

    @objc func openImageSourcePrompt() {
        let cancelHandler: (UIAlertAction) -> Void = { action in
            if self.selectedImagesView.image == nil {
                self.cleanUpAndDismiss()
            }
        }
        let actionHandler: (UIImagePickerControllerSourceType) -> Void = { source in
            guard UIImagePickerController.isSourceTypeAvailable(source) else {
                let alert = UIAlertController(title: "Not Available", message: nil, preferredStyle: .alert)
                alert.addAction(UIAlertAction(title: "Choose image from different source", style: .default) { action in
                    self.openImageSourcePrompt()
                })
                alert.addAction(UIAlertAction(title: "Cancel", style: .cancel, handler: cancelHandler))

                self.present(alert, animated: true)
                return
            }

            self.imagePicker.sourceType = source
            if source == .camera {
                if UIImagePickerController.isCameraDeviceAvailable(.rear) {
                    self.imagePicker.cameraDevice = .rear
                } else if UIImagePickerController.isCameraDeviceAvailable(.front) {
                    self.imagePicker.cameraDevice = .front
                } else {
                    return
                }
            }

            self.present(self.imagePicker, animated:true)
        }

        let actionSheet = UIAlertController(title: "Upload Receipt Images", message: nil, preferredStyle: .actionSheet)
        actionSheet.addAction(UIAlertAction(title: "Take photo", style: .default) { action in
            actionHandler(.camera)
        })
        actionSheet.addAction(UIAlertAction(title: "Choose existing image", style: .default) { action in
            actionHandler(.photoLibrary)
        })
        actionSheet.addAction(UIAlertAction(title: "Cancel", style: .cancel, handler: cancelHandler))

        actionSheet.popoverPresentationController?.sourceView = view
        present(actionSheet, animated: true)
    }

    func imagePickerController(_ picker: UIImagePickerController, didFinishPickingMediaWithInfo info: [String : Any]) {
        let receiptImage = info[UIImagePickerControllerOriginalImage] as! UIImage
        selectedImages.append(receiptImage)

        let multiImage = UIImage.animatedImage(with: selectedImages, duration: TimeInterval(selectedImages.count))
        selectedImagesView.image = multiImage

        let imageData = UIImageJPEGRepresentation(receiptImage, 0.5)
        let fileName = "sm_receipt_upload\(selectedImages.count - 1)"

        let filePath = self.filePath(forFileWithName: fileName)
        FileManager.default.createFile(atPath: filePath, contents: imageData, attributes: nil)
        filePaths.append(fileName)

        picker.dismiss(animated: true) {
            self.dismissButton.isHidden = false
            self.useImagesButton.isHidden = false
            self.selectedImagesView.isHidden = false
            self.addImageButton.isEnabled = self.selectedImages.count < 5
        }
    }

    func imagePickerControllerDidCancel(_ picker: UIImagePickerController) {
        picker.dismiss(animated: true)

        if selectedImagesView.image == nil {
            cleanUpAndDismiss()
        }
    }

    // MARK: - Receipt image uploading

    @objc func openProgressView() {
        let darkView = UIView(frame: view.frame)
        darkView.layer.backgroundColor = UIColor.black.cgColor
        darkView.layer.opacity = 0.5
        view.addSubview(darkView)

        let progressView = initializeProgressView()
        view.addSubview(progressView)

        let variableBindings = ["progressView": progressView]
        view.addConstraints(NSLayoutConstraint.constraints(withVisualFormat: "H:|-[progressView]-|",
                                                           options: NSLayoutFormatOptions(rawValue: 0),
                                                           metrics: nil,
                                                           views: variableBindings))
        view.addConstraints(NSLayoutConstraint.constraints(withVisualFormat: "V:[progressView(==\(view.frame.size.height * 0.5))]",
                                                           options: NSLayoutFormatOptions(rawValue: 0),
                                                           metrics: nil,
                                                           views: variableBindings))
        view.addConstraint(NSLayoutConstraint(item: progressView,
                                              attribute: .centerY,
                                              relatedBy: .equal,
                                              toItem: view,
                                              attribute: .centerY,
                                              multiplier: 1,
                                              constant: 0))

        uploadCurrentReceipt()
    }

    func initializeProgressView() -> UIView {
        let view = UIView()
        view.backgroundColor = UIColor.white
        view.layer.cornerRadius = 2.0

        progressActionButton = UIButton(type: .custom)
        progressActionButton.isEnabled = false
        progressActionButton.titleLabel?.font = UIFont.boldSystemFont(ofSize: 25)
        progressActionButton.setTitle("Continue", for: .normal)
        progressActionButton.setTitleColor(UIColor.white, for: .normal)
        progressActionButton.backgroundColor = UIColor.lightGray
        progressActionButton.alpha = 0.8
        progressActionButton.layer.cornerRadius = 2
        progressActionButton.translatesAutoresizingMaskIntoConstraints = false
        view.addSubview(progressActionButton)

        progressDismissButton = UIButton(type: .system)
        progressDismissButton.addTarget(self, action: #selector(cleanUpAndDismiss), for: .touchUpInside)
        progressDismissButton.titleLabel?.font = UIFont.systemFont(ofSize: 16)
        progressDismissButton.setTitle("Cancel", for: .normal)
        progressDismissButton.translatesAutoresizingMaskIntoConstraints = false
        view.addSubview(progressDismissButton)

        progressTitleLabel = UILabel()
        progressTitleLabel.textAlignment = .center
        progressTitleLabel.text = "Uploading receipt..."
        progressTitleLabel.font = UIFont.boldSystemFont(ofSize: 27)
        progressTitleLabel.adjustsFontSizeToFitWidth = true
        progressTitleLabel.translatesAutoresizingMaskIntoConstraints = false
        view.addSubview(progressTitleLabel)

        progressDescriptionlabel = UILabel()
        progressDescriptionlabel.numberOfLines = 0
        progressDescriptionlabel.textAlignment = .center
        progressDescriptionlabel.font = UIFont.systemFont(ofSize: 16)
        progressDescriptionlabel.translatesAutoresizingMaskIntoConstraints = false
        view.addSubview(progressDescriptionlabel)

        let variableBindings = ["progressTitleLabel": progressTitleLabel,
                                "progressDescriptionlabel": progressDescriptionlabel,
                                "progressActionButton": progressActionButton,
                                "progressDismissButton": progressDismissButton] as [String : Any]
        view.addConstraints(NSLayoutConstraint.constraints(withVisualFormat: "H:|-15-[progressTitleLabel]-15-|",
                                                           options: NSLayoutFormatOptions(rawValue: 0),
                                                           metrics: nil,
                                                           views: variableBindings))
        view.addConstraints(NSLayoutConstraint.constraints(withVisualFormat: "H:|-15-[progressDescriptionlabel]-15-|",
                                                           options: NSLayoutFormatOptions(rawValue: 0),
                                                           metrics: nil,
                                                           views: variableBindings))
        view.addConstraints(NSLayoutConstraint.constraints(withVisualFormat: "H:|-15-[progressActionButton]-15-|",
                                                           options: NSLayoutFormatOptions(rawValue: 0),
                                                           metrics: nil,
                                                           views: variableBindings))
        view.addConstraints(NSLayoutConstraint.constraints(withVisualFormat: "H:|-[progressDismissButton]-|",
                                                           options: NSLayoutFormatOptions(rawValue: 0),
                                                           metrics: nil,
                                                           views: variableBindings))
        view.addConstraints(NSLayoutConstraint.constraints(withVisualFormat: "V:|-20-[progressTitleLabel]-10-[progressDescriptionlabel]",
                                                           options: NSLayoutFormatOptions(rawValue: 0),
                                                           metrics: nil,
                                                           views: variableBindings))
        view.addConstraints(NSLayoutConstraint.constraints(withVisualFormat: "V:[progressDescriptionlabel]-20-[progressActionButton(==50)]-[progressDismissButton]-20-|",
                                                           options: NSLayoutFormatOptions(rawValue: 0),
                                                           metrics: nil,
                                                           views: variableBindings))

        view.translatesAutoresizingMaskIntoConstraints = false
        return view
    }

    func uploadCurrentReceipt() {
        SMReceiptsManager.instance().uploadImageFiles(atPaths: filePaths, campaignID: campaignID, placementID: nil, data: nil,completionHandler: { (receipt, error) in
            if let error = error {
                self.requestFailed(withError: error)
            } else if let receipt = receipt {
                self.uploadedReceipt(receipt)
            }
        }, progressHandler: { (receipt, error) in
            if let error = error {
                self.requestFailed(withError: error)
            } else if let receipt = receipt {
                self.printProgress(for: receipt)
            }
        })
    }

    func requestFailed(withError error: SMError) {
        progressTitleLabel.text = "We're Sorry."
        progressDescriptionlabel.text = "Receipt could not be uploaded at this time. Please try again later."
        let actionString = "Close"
        progressActionButton.titleLabel?.text = actionString
        progressActionButton.setTitle(actionString, for: .normal)
        progressActionButton.removeTarget(self, action: #selector(retryUpload), for: .touchUpInside)
        progressActionButton.addTarget(self, action: #selector(cleanUpAndDismiss), for: .touchUpInside)
        progressDismissButton.isHidden = true

        progressActionButton.isEnabled = true
        progressActionButton.backgroundColor = UIColor.blue
        progressActionButton.alpha = 1.0
    }

    func printProgress(for receipt: SMReceipt) {
        print("Uploaded receipt image \(receipt.imageURLs!.count) of \(receipt.imageCount)")
    }

    func uploadedReceipt(_ receipt: SMReceipt) {
        if receipt.invalidReason == nil || receipt.invalidReason?.count == 0 {
            progressTitleLabel.text = "Thank You!"
            progressDescriptionlabel.text = "Your receipt has been successfully uploaded."
            let actionString = "Continue"
            progressActionButton.titleLabel?.text = actionString
            progressActionButton.setTitle(actionString, for: .normal)
            progressActionButton.removeTarget(self, action: #selector(retryUpload), for: .touchUpInside)
            progressActionButton.addTarget(self, action: #selector(cleanUpAndDismiss), for: .touchUpInside)
            progressDismissButton.isHidden = true
        } else {
            progressTitleLabel.text = "We're Sorry."
            progressDescriptionlabel.text = "Something went wrong. Please try again."
            let actionString = "Retry"
            progressActionButton.titleLabel?.text = actionString
            progressActionButton.setTitle(actionString, for: .normal)
            progressActionButton.removeTarget(self, action: #selector(cleanUpAndDismiss), for: .touchUpInside)
            progressActionButton.addTarget(self, action: #selector(retryUpload), for: .touchUpInside)
            let dismissString = "Try again later"
            progressDismissButton.titleLabel?.text = dismissString
            progressDismissButton.setTitle(dismissString, for: .normal)
        }

        progressActionButton.isEnabled = true
        progressActionButton.backgroundColor = UIColor.blue
        progressActionButton.alpha = 1.0
    }

    @objc func retryUpload() {
        let cancelString = "Cancel"
        progressDismissButton.titleLabel?.text = cancelString
        progressDismissButton.setTitle(cancelString, for: .normal)
        progressActionButton.isEnabled = false
        progressActionButton.backgroundColor = UIColor.lightGray
        progressActionButton.alpha = 0.8
        progressTitleLabel.text = "Uploading receipt..."
        progressDescriptionlabel.text = ""

        uploadCurrentReceipt()
    }

    @objc func cleanUpAndDismiss() {
        dismiss(animated: true)
    }

    func filePath(forFileWithName name: String) -> String {
        let paths = NSSearchPathForDirectoriesInDomains(.documentDirectory, .userDomainMask, true)
        let documents = paths.first!

        return "\(documents)/\(name)"
    }
}
