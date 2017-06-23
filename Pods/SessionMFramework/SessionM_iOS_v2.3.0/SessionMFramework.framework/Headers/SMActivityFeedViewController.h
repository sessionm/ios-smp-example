//
//  SMActivityFeedViewController.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef __SM_ACTIVITY_FEED_VIEW_CONTROLLER__
#define __SM_ACTIVITY_FEED_VIEW_CONTROLLER__

#import <UIKit/UIKit.h>
#import "SMFeedMessage.h"
#import "SMCampaignsManager.h"

NS_ASSUME_NONNULL_BEGIN

#define TABLEVIEW_BACKGROUND_COLOR [UIColor colorWithRed:224.f/255.f green:224.f/255.f blue:224.f/255.f alpha:1]

/*!
 @class SMActivityFeedViewController
 @abstract A standard implementation for presenting instances of @link SMFeedMessage @/link in an activity feed.
 */
@interface SMActivityFeedViewController : UIViewController <UITableViewDataSource,UITableViewDelegate,UIContentContainer,SMCampaignsDelegate>

/*!
 @property tableView
 @abstract The table view in which the activity feed is presented.
 */
@property(nonatomic, strong) UITableView *tableView;

/*!
 @abstract Initializes an instance of this class with the specified frame and style.
 @param frame Frame in which the activity feed will be presented.
 @param style The section grouping style.
 @result <code>SMActivityFeedViewController</code> instance with the specified frame and style.
 */
- (instancetype)initWithFrame:(CGRect)frame andStyle:(UITableViewStyle)style NS_SWIFT_NAME(init(frame:style:));
/*!
 @abstract Gets the message data corresponding to the specified index path.
 @param indexPath An index path in the activity feed.
 @result @link SMFeedMessage @/link instance at the specified index path.
 */
- (SMFeedMessage *)messageAtIndexPath:(NSIndexPath *)indexPath NS_SWIFT_NAME(message(at:));

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_ACTIVITY_FEED_VIEW_CONTROLLER__ */
