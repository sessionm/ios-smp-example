//
//  ContentDetailsViewController.swift
//  ios-swift-smp-sample
//
//  Copyright © 2017 SessionM. All rights reserved.
//

import AVKit
import UIKit

class ContentDetailsViewController: UIViewController {
    @IBOutlet private var contentID: UILabel!
    @IBOutlet private var externalID: UILabel!
    @IBOutlet private var name: UILabel!
    @IBOutlet private var type: UILabel!
    @IBOutlet private var state: UILabel!
    @IBOutlet private var details: UILabel!
    @IBOutlet private var weight: UILabel!
    @IBOutlet private var createdTime: UILabel!
    @IBOutlet private var updatedTime: UILabel!
    @IBOutlet private var expiresTime: UILabel!

    @IBOutlet private var imageContainer: UIView!
    @IBOutlet private var contentImage: UIImageView!
    @IBOutlet private var imageWidth: NSLayoutConstraint!
    @IBOutlet private var imageHeight: NSLayoutConstraint!


    @IBOutlet private var playButton: UIBarButtonItem!

    var content: SMContent?

    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)

        if let c = content {
            contentID.text = contentID.text?.appending(c.contentID)
            name.text = name.text?.appending(c.name)
            navigationItem.title = name.text
            type.text = type.text?.appending(c.type)
            state.text = state.text?.appending(SMContent.string(from: c.state))
            weight.text = weight.text?.appending("\(c.weight)")
            createdTime.text = createdTime.text?.appending(c.createdTime)
            if let extID = c.externalID {
                externalID.text = externalID.text?.appending(extID)
            }
            if let descr = c.descriptionText {
                details.text = details.text?.appending(descr)
            }
            if let updTime = c.updatedTime {
                updatedTime.text = updatedTime.text?.appending(updTime)
            }
            if let expTime = c.expiresTime {
                expiresTime.text = expiresTime.text?.appending(expTime)
            }

            if let img = c.imageURL {
                Util.loadFrom(img, callback: { (image) in
                    self.contentImage.image = image
                    let availableHeight = self.imageContainer.frame.size.height - self.contentImage.frame.origin.y
                    let ratioH = availableHeight / image.size.height
                    let ratioW = self.imageContainer.frame.size.width / image.size.width
                    let ratio = min(ratioH, ratioW)
                    self.imageWidth.constant = image.size.width * ratio
                    self.imageHeight.constant = image.size.height * ratio
                })
            }

            if c.type == "Video" {
                playButton.isEnabled = true
            }
        }
    }

    @IBAction private func playVideo(_ sender: UIBarButtonItem) {
        guard let videoTitle = externalID.text?.replacingOccurrences(of: "External ID:", with: "") else {
            return
        }
        guard let videoURL = URL(string: "https://grafton.s3.amazonaws.com/content_demo/".appending(videoTitle.replacingOccurrences(of: "-mp4", with: ".mp4"))) else {
            return
        }

        let playerController = AVPlayerViewController()
        playerController.player = AVPlayer(url: videoURL)
        present(playerController, animated: true) {
            playerController.player!.play()
        }
    }
}
