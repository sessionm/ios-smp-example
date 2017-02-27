//
//  GeofenceAnnotation.swift
//  ios-swift-smp-sample
//
//  Copyright © 2017 SessionM. All rights reserved.
//

import MapKit
import UIKit

private let enterTriggerType = "ENTER"
private let exitTriggerType = "EXIT"

enum GeofenceAnnotationType {
    case info
    case trigger(String)

    var pinTintColor: UIColor {
        get {
            switch self {
            case .info:
                return UIColor.green
            case .trigger(let triggerType):
                if triggerType == exitTriggerType {
                    return UIColor.purple
                } else {
                    return UIColor.red
                }
            }
        }
    }

    var pinColor: MKPinAnnotationColor {
        get {
            switch self {
            case .info:
                return .green
            case .trigger(let triggerType):
                if triggerType == exitTriggerType {
                    return .purple
                } else {
                    return .red
                }
            }
        }
    }

    var annotationTitle: String {
        get {
            switch self {
            case .info:
                return "Geofences"
            case .trigger:
                return "Event Triggers"
            }
        }
    }
}

class GeofenceAnnotation: MKPointAnnotation {
    let type: GeofenceAnnotationType

    init(type: GeofenceAnnotationType) {
        self.type = type
    }
}
