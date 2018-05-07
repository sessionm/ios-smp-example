//
//  SMPlacesManager.h
//  SessionMPlacesKit
//
//  Copyright © 2018 SessionM. All rights reserved.
//

#ifndef __SM_PLACES_MANAGER__
#define __SM_PLACES_MANAGER__

#import <CoreLocation/CLLocation.h>
#import <SessionMCoreKit/SMBaseManager.h>
#import <SessionMCoreKit/SMError.h>

#import "SMPlace.h"
#import "SMPlaceCheckinResult.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @const SM_PLACES_MANAGER_REQUEST_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that an API request failed.
 @discussion An <code>SMError</code> object containing information about why the request failed can be accessed from the notification's <code>userInfo</code> property with the <code>SM_MANAGER_NOTIFICATION_ERROR_KEY</code> key.
 */
extern NSString *const SM_PLACES_MANAGER_REQUEST_DID_FAIL_NOTIFICATION NS_SWIFT_NAME(placesRequestFailureNotification);
/*!
 @const SM_PLACES_MANAGER_VALIDATION_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that a Places API validation failed.
 @discussion An <code>SMError</code> object containing information about why the validation failed can be accessed from the notification's <code>userInfo</code> property with the <code>SM_MANAGER_NOTIFICATION_ERROR_KEY</code> key.
 */
extern NSString *const SM_PLACES_MANAGER_VALIDATION_DID_FAIL_NOTIFICATION NS_SWIFT_NAME(placesValidationFailureNotification);

/*!
 @const SM_PLACES_MANAGER_DID_FETCH_PLACES
 @abstract Notifies observers that places available for check in were fetched.
 @discussion An <code>NSArray</code> of <code>SMPlace</code> objects can be accessed from the notification's <code>userInfo</code> property with the <code>SM_MANAGER_NOTIFICATION_DATA_KEY</code> key.
 */
extern NSString *const SM_PLACES_MANAGER_DID_FETCH_PLACES NS_SWIFT_NAME(fetchedPlacesNotification);
/*!
 @const SM_PLACES_MANAGER_REQUEST_DID_CHECKIN_PLACE
 @abstract Notifies observers that a place was checked into.
 @discussion An <code>SMPlaceCheckinResult</code> object containing information about the checkin result can be accessed from the notification's <code>userInfo</code> property with the <code>SM_MANAGER_NOTIFICATION_DATA_KEY</code> key.
 */
extern NSString *const SM_PLACES_MANAGER_REQUEST_DID_CHECKIN_PLACE NS_SWIFT_NAME(checkedInNotification);


/*!
 @typedef didFetchPlaces
 @abstract Completion handler block type for <code>fetchPlacesAroundLocation:completionHandler:</code> and <code>fetchPlacesAroundLocation:withRadius:limit:adUnitID:completionHandler:</code>.
 */
typedef void (^didFetchPlaces)(NSArray<SMPlace *>* _Nullable places, SMError * _Nullable error) NS_SWIFT_NAME(FetchPlacesCompletionHandler);
/*!
 @typedef didCheckIn
 @abstract Completion handler block type for <code>checkInPlace:completionHandler:</code>.
 */
typedef void (^didCheckIn)(SMPlaceCheckinResult * _Nullable checkin, SMError * _Nullable error) NS_SWIFT_NAME(CheckInCompletionHandler);


/*!
 @class SMPlacesManager
 @abstract This API manager contains methods for fetching and checking into sponsored venues.
 */
@interface SMPlacesManager : SMBaseManager

/*!
 @property places
 @abstract Places that are available for check in.
 @discussion This property is updated in response to a successful <code>fetchPlacesAroundLocation:completionHandler:</code> or <code>fetchPlacesAroundLocation:withRadius:limit:adUnitID:completionHandler:</code> call.
 */
@property(nonatomic, strong, readonly) NSArray<SMPlace *> *places;

/*!
 @abstract Makes a request to update <code>places</code> with venues available for check inside a circle centered at the specified location.
 @param location The center of the circle in which places will be fetched.
 @param completionHandler The block to execute after the request is processed.
 */
- (void)fetchPlacesAroundLocation:(CLLocation *)location completionHandler:(didFetchPlaces)completionHandler NS_SWIFT_NAME(fetchPlaces(near:completionHandler:));
/*!
 @abstract Makes a request to update <code>places</code> with a limited number of venues available for check in inside the circle with the specified radius centered at the specified location.
 @param location The center of the circle in which places will be fetched.
 @param radius The radius in meters of the circle in which places will be fetched (optional).
 @param limit The maximum amount of places to fetch (optional).
 @param adUnitID Fetched places that do not have a bonus opportunity linking to the ad unit with the specified ID will be filtered out (optional - developers can setup ad units from the Campaigns module in the SessionM Platform portal).
 @param completionHandler The block to execute after the request is processed.
 */
- (void)fetchPlacesAroundLocation:(CLLocation *)location withRadius:(float)radius limit:(int)limit adUnitID:(NSString * _Nullable)adUnitID completionHandler:(didFetchPlaces)completionHandler NS_SWIFT_NAME(fetchPlaces(near:radius:limit:adUnitID:completionHandler:));

/*!
 @abstract Makes a request to check into the specified place.
 @param place The place to check into.
 @param completionHandler The block to execute after the request is processed.
  */
- (void)checkInPlace:(SMPlace *)place completionHandler:(didCheckIn)completionHandler NS_SWIFT_NAME(checkIntoPlace(_:completionHandler:));

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_PLACES_MANAGER__ */
