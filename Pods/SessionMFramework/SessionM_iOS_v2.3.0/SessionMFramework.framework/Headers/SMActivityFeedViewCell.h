//
//  SMActivityFeedViewCell.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef __SM_ACTIVITY_FEED_VIEW_CELL__
#define __SM_ACTIVITY_FEED_VIEW_CELL__

#import <UIKit/UIKit.h>
#import "SMFeedMessage.h"

NS_ASSUME_NONNULL_BEGIN

#define TILE_MARGIN_TOP 22
#define TILE_MARGIN_BOTTOM 22
#define TILE_MARGIN_LEFT 12
#define TILE_MARGIN_RIGHT 12
#define ICON_LENGTH 40
#define ICON_MARGIN_TOP 6
#define ICON_MARGIN_BOTTOM 12
#define ICON_MARGIN_RIGHT 10
#define DESCRIPTION_MARGIN_BOTTOM 12
#define HEADER_MARGIN_BOTTOM 9
#define CONTAINER_MARGIN 10
#define HEADER_LABEL_COLOR [UIColor blackColor]
#define SUBHEADER_LABEL_COLOR [UIColor colorWithRed:0.549 green:0.564 blue:0.607 alpha:1]
#define DESCRIPTION_LABEL_COLOR [UIColor blackColor]
#define CONTAINER_BACKGROUND_COLOR [UIColor whiteColor]

/*!
 @protocol SMActivityFeedViewCellDelegate
 @abstract Defines callbacks for @link SMActivityFeedViewCell @/link methods.
 */
@protocol SMActivityFeedViewCellDelegate

- (void)reloadCellForFeedMessage:(SMFeedMessage *)message NS_SWIFT_NAME(reloadCell(havingFeedMessage:));

@end


/*!
 @class SMActivityFeedViewCell
 @abstract A standard implementation for the table view cells in an instance of @link //apple_ref/occ/cl/SMActivityFeedViewController @/link.
 */
@interface SMActivityFeedViewCell : UITableViewCell

/*!
 @property message
 @abstract The message data that will be presented in the cell.
 */
@property(nonatomic, strong) SMFeedMessage *message;
/*!
 @property isSizingCell
 @abstract Represents whether the cell is a placeholder cell used for resizing.
 */
@property(nonatomic, assign) BOOL isSizingCell;
/*!
 @property delegate
 @abstract @link SMActivityFeedViewCellDelegate @/link object to tell to reload this cell after all images are loaded.
 */
@property(nonatomic, weak) id<SMActivityFeedViewCellDelegate> delegate;

/*!
 @abstract Asynchronously loads the icon and banner image for each message in the specified message list.
 @param messages Current message list.
 */
- (void)seedMessages:(NSArray*)messages NS_SWIFT_NAME(seedMessages(_:));
/*!
 @abstract Returns the height of the cell (including content and margins).
 @result <code>CGFloat</code> cell height.
 */
- (CGFloat)heightForCell NS_SWIFT_NAME(height());

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_ACTIVITY_FEED_VIEW_CELL__ */
