//
//  BehaviorsList.swift
//  SMPExample
//
//  Copyright © 2018 SessionM. All rights reserved.
//

import UIKit

class BehaviorsList: NSObject {

    enum OrderShowing {
        case behavior
        case events
    }

    var behaviors : SMEventsResponse?;

    init(behaviors : SMEventsResponse?) {
        self.behaviors = behaviors;
    }

    func show(showing : OrderShowing) -> String {
        if (showing == .behavior) {
            return showByBehavior();
        } else {
            return showByEvent();
        }
    }

    struct LineItem {
        var eventName: String
        var second: String
        var third: String
        var behaviorName: String

        var achieved: Int
        var current: Int
        var total: Int

        init(behaviorName: String, second: String, third: String, behavior: SMBehavior) {
            self.behaviorName = behaviorName;
            self.second = second;
            self.third = third

            self.achieved = (behavior as! SMCountBehavior).achieved
            self.current = (behavior as! SMCountBehavior).currentCount
            self.total = (behavior as! SMCountBehavior).totalCount;
            self.eventName = (behavior as! SMCountBehavior).eventName
        }
    }

    func showByEvent() -> String {
        var out = "";

        var items : [String:[LineItem]] = [:];
        if let behaviors = self.behaviors?.behaviors {
            for behavi0r in behaviors {
                let behavior = behavi0r.value;
                switch behavior.type {
                case .composite:
                    for goal in (behavior as! SMCompositeBehavior).goals {
                        addItem(map: &items, item: LineItem(behaviorName: behavi0r.key, second:goal.key, third:goal.value.groupID, behavior: goal.value.progress));
                    }
                case .count: break;
                case .unique: break;
                default: break;
                }
            }
        }

        if let behaviors = self.behaviors {
            out += "Points: \(String(describing: behaviors.availablePoints))\n\n";
        }

        for item in (items.sorted { (v1: (k: String, v: [BehaviorsList.LineItem]), v2: (k: String, v: [BehaviorsList.LineItem])) -> Bool in
            return (v1.k < v2.k);
        }) {
            out += "   \(item.key)\n";
            for row in item.value.sorted(by: { (v1, v2) -> Bool in
                if (v1.second != v2.second) {
                    return v1.second < v2.second;
                } else {
                    return v1.third < v2.third;
                }
            }) {

                out += "     \(row.achieved) \(row.current) of \(row.total) \(row.behaviorName)\n"
            }
        }

        return out;
    }

    func addItem( map: inout [String:[LineItem]], item:  LineItem) {
        let items = map[item.eventName];
        if (items == nil) {
            map[item.eventName] = [item];
        } else {
            map[item.eventName]?.append(item);
        }
    }

    func showByBehavior() -> String {
        var out = "";
        if let behaviors = behaviors {
            out = "Points: \(String(describing: behaviors.availablePoints))\n\n";

            for behavior in behaviors.behaviors {
                out += "   '\(behavior.key)' (\(SMBehavior.string(from: behavior.value.type)))\n"

                switch behavior.value.type {
                case .composite:
                    let composite = behavior.value as! SMCompositeBehavior
                    for group in composite.groups {
                        for goale in group.value.goals {
                            let goal : SMGoal = goale.value;
                            if (goal.progress.type == .count) {
                                let progress = goal.progress as! SMCountBehavior
                                out += "     \(progress.achieved) \(progress.currentCount) of \(progress.totalCount) '\(progress.eventName)'\n"
                            } else if (goal.progress.type == .count) {
                                let progress = goal.progress as! SMUniqueBehavior
                                out += "     \(progress.achieved) \(progress.currentCount) of \(progress.totalCount) '\(progress.points)'\n"
                            }
                        }
                    }
                case .count:
                    let count = behavior.value as! SMCountBehavior
                    out += "     \(count.achieved) \(count.currentCount) of \(count.totalCount) '\(count.eventName)'\n"
                case .unique:
                    let unique = behavior.value as! SMUniqueBehavior
                    out += "     \(unique.achieved) \(unique.currentCount) of \(unique.totalCount) '\(unique.points)'\n"
                default: break;
                }

            }
        }

        return out;
    }
}
