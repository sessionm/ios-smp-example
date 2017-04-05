//
//  SMPlacesManager.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef __SM_PLACES_MANAGER__
#define __SM_PLACES_MANAGER__

#import <CoreLocation/CLLocation.h>
#import "SMBaseDelegate.h"
#import "SMPlace.h"
#import "SMPlaceCheckinResult.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @const SM_PLACES_MANAGER_REQUEST_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that an API request failed.
 @discussion An @link SMError @/link object containing information about why the request failed can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_ERROR_KEY @/link key.
 */
extern NSString *const SM_PLACES_MANAGER_REQUEST_DID_FAIL_NOTIFICATION NS_SWIFT_NAME(placesRequestFailureNotification);
/*!
 @const SM_PLACES_MANAGER_VALIDATION_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that a Places API validation failed.
 @discussion An @link SMError @/link object containing information about why the validation failed can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_ERROR_KEY @/link key.
 */
extern NSString *const SM_PLACES_MANAGER_VALIDATION_DID_FAIL_NOTIFICATION NS_SWIFT_NAME(placesValidationFailureNotification);

/*!
 @const SM_PLACES_MANAGER_DID_FETCH_PLACES
 @abstract Notifies observers that places available for check in were fetched.
 @discussion An <code>NSArray</code> of @link SMPlace @/link objects can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_DATA_KEY @/link key.
 */
extern NSString *const SM_PLACES_MANAGER_DID_FETCH_PLACES NS_SWIFT_NAME(fetchedPlacesNotification);
/*!
 @const SM_PLACES_MANAGER_REQUEST_DID_CHECKIN_PLACE
 @abstract Notifies observers that a place was checked into.
 @discussion An @link SMPlaceCheckinResult @/link object containing information about the checkin result can be accessed from the notification's <code>userInfo</code> property with the @link SM_MANAGER_NOTIFICATION_DATA_KEY @/link key.
 */
extern NSString *const SM_PLACES_MANAGER_REQUEST_DID_CHECKIN_PLACE NS_SWIFT_NAME(checkedInNotification);

/*!
 @protocol SMPlacesDelegate
 @abstract Defines callbacks for @link SMPlacesManager @/link methods.
 */
@protocol SMPlacesDelegate <SMBaseDelegate>

@optional

/*!
 @abstract Notifies delegate that places available for check in were fetched.
 @discussion This method is called in response to @link fetchPlacesAroundLocation: @/link and @link fetchPlacesAroundLocation:withRadius:limit:adUnitID: @/link.
 @param places Places available for check in.
 @deprecated Use block methods instead.
 */
- (void)didFetchPlaces:(NSArray<SMPlace *> *)places __attribute__((deprecated("Use block methods instead"))) NS_SWIFT_NAME(didFetchPlaces(_:));
/*!
 @abstract Notifies delegate that a place was checked into.
 @discussion This method is called in response to @link checkInPlace: @/link.
 @param result The checkin result.
 @deprecated Use block methods instead.
 */
- (void)didCheckIn:(SMPlaceCheckinResult *)result __attribute__((deprecated("Use block methods instead"))) NS_SWIFT_NAME(didCheckIn(result:));

@end

/*!
 @typedef didFetchPlaces
 @abstract Completion handler block type for @link fetchPlacesAroundLocation:completionHandler: @/link and @link fetchPlacesAroundLocation:withRadius:limit:adUnitID:completionHandler: @/link.
 */
typedef void (^didFetchPlaces)(NSArray<SMPlace *>* _Nullable places, SMError * _Nullable error) NS_SWIFT_NAME(FetchPlacesCompletionHandler);
/*!
 @typedef didCheckIn
 @abstract Completion handler block type for @link checkInPlace:completionHandler: @/link.
 */
typedef void (^didCheckIn)(SMPlaceCheckinResult * _Nullable checkin, SMError * _Nullable error) NS_SWIFT_NAME(CheckInCompletionHandler);


/*!
 @class SMPlacesManager
 @abstract This API manager contains methods for fetching and checking into sponsored venues.
 */
@interface SMPlacesManager : NSObject

/*!
 @property delegate
 @abstract Object that implements @link SMPlacesDelegate @/link callbacks.
 */
@property(nonatomic, weak) id<SMPlacesDelegate> _Nullable delegate;
/*!
 @property places
 @abstract Places that are available for check in.
 @discussion This property is updated in response to a successful @link fetchPlacesAroundLocation:completionHandler: @/link or @link fetchPlacesAroundLocation:withRadius:limit:adUnitID:completionHandler: @/link call.
 */
@property(nonatomic, strong, readonly) NSArray<SMPlace *> *places;

/*!
 @abstract Makes a request to update @link places @/link with venues available for check inside a circle centered at the specified location.
 @discussion @link didFetchPlaces: @/link is called in response to this method.
 @param location The center of the circle in which places will be fetched.
 @result <code>BOOL</code> indicating whether the request will be sent.
 @deprecated Use @link fetchPlacesAroundLocation:completionHandler: @/link.
 */
- (BOOL)fetchPlacesAroundLocation:(CLLocation *)location __attribute__((deprecated("Use fetchPlacesAroundLocation:completionHandler:"))) NS_SWIFT_NAME(fetchPlaces(near:));
/*!
 @abstract Makes a request to update @link places @/link with venues available for check inside a circle centered at the specified location.
 @param location The center of the circle in which places will be fetched.
 @param completionHandler The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)fetchPlacesAroundLocation:(CLLocation *)location completionHandler:(didFetchPlaces)completionHandler NS_SWIFT_NAME(fetchPlaces(near:completionHandler:));
/*!
 @abstract Makes a request to update @link places @/link with a limited number of venues available for check in inside the circle with the specified radius centered at the specified location.
 @discussion @link didFetchPlaces: @/link is called in response to this method.
 @param location The center of the circle in which places will be fetched.
 @param radius The radius in meters of the circle in which places will be fetched (optional).
 @param limit The maximum amount of places to fetch (optional).
 @param adUnitID Fetched places that do not have a bonus opportunity linking to the ad unit with the specified ID will be filtered out (optional - developers can setup ad units from the Campaigns module in the SessionM Mobile Marketing Cloud portal).
 @result <code>BOOL</code> indicating whether the request will be sent.
 @deprecated Use @link fetchPlacesAroundLocation:withRadius:limit:adUnitID:completionHandler: @/link.
 */
- (BOOL)fetchPlacesAroundLocation:(CLLocation *)location withRadius:(float)radius limit:(int)limit adUnitID:(NSString * _Nullable)adUnitID __attribute__((deprecated("Use fetchPlacesAroundLocation:withRadius:limit:adUnitID:completionHandler:"))) NS_SWIFT_NAME(fetchPlaces(near:radius:limit:adUnitID:));
/*!
 @abstract Makes a request to update @link places @/link with a limited number of venues available for check in inside the circle with the specified radius centered at the specified location.
 @param location The center of the circle in which places will be fetched.
 @param radius The radius in meters of the circle in which places will be fetched (optional).
 @param limit The maximum amount of places to fetch (optional).
 @param adUnitID Fetched places that do not have a bonus opportunity linking to the ad unit with the specified ID will be filtered out (optional - developers can setup ad units from the Campaigns module in the SessionM Mobile Marketing Cloud portal).
 @param completionHandler The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)fetchPlacesAroundLocation:(CLLocation *)location withRadius:(float)radius limit:(int)limit adUnitID:(NSString * _Nullable)adUnitID completionHandler:(didFetchPlaces)completionHandler NS_SWIFT_NAME(fetchPlaces(near:radius:limit:adUnitID:completionHandler:));
/*!
 @abstract Makes a request to check into the specified place.
 @discussion @link didCheckIn: @/link is called in response to this method.
 @param place The place to check into.
 @result <code>BOOL</code> indicating whether the request will be sent.
 @deprecated Use @link checkInPlace:completionHandler: @/link.
 */
- (BOOL)checkInPlace:(SMPlace *)place __attribute__((deprecated("Use checkInPlace:completionHandler:"))) NS_SWIFT_NAME(checkIntoPlace(_:));
/*!
 @abstract Makes a request to check into the specified place.
 @param place The place to check into.
 @param completionHandler The block to execute after the request is processed.
 @result <code>BOOL</code> indicating whether the request will be sent.
 */
- (BOOL)checkInPlace:(SMPlace *)place completionHandler:(didCheckIn)completionHandler NS_SWIFT_NAME(checkIntoPlace(_:completionHandler:));

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_PLACES_MANAGER__ */
