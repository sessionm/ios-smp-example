//
//  SMGeofenceManager.h
//  SessionMGeofenceKit
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef __SM_GEOFENCE_MANAGER__
#define __SM_GEOFENCE_MANAGER__

#import <Foundation/Foundation.h>
#import <SessionMCoreKit/SMBaseManager.h>
#import <SessionMEventsKit/SMGeolocationEvent.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @const SM_GEOFENCE_MANAGER_REQUEST_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that a Geofence API request failed.
 @discussion An <code>SMError</code> object containing information about why the request failed can be accessed from the notification's <code>userInfo</code> property with the <code>SM_MANAGER_NOTIFICATION_ERROR_KEY</code> key.
 */
extern NSString *const SM_GEOFENCE_MANAGER_REQUEST_DID_FAIL_NOTIFICATION NS_SWIFT_NAME(geofenceRequestFailureNotification);
/*!
 @const SM_GEOFENCE_MANAGER_VALIDATION_DID_FAIL_NOTIFICATION
 @abstract Notifies observers that a Geofence API validation failed.
 @discussion An <code>SMError</code> object containing information about why the validation failed can be accessed from the notification's <code>userInfo</code> property with the <code>SM_MANAGER_NOTIFICATION_ERROR_KEY</code> key.
 */
extern NSString *const SM_GEOFENCE_MANAGER_VALIDATION_DID_FAIL_NOTIFICATION NS_SWIFT_NAME(geofenceValidationFailureNotification);

/*!
 @const SM_GEOFENCE_MANAGER_DID_UPDATE_LOCATION
 @abstract Notifies observers that the user's current location was updated.
 @discussion The user's new location can be accessed from the notification's <code>userInfo</code> property with the <code>kSMGeofenceManagerLocation</code> key.
 */
extern NSString *const SM_GEOFENCE_MANAGER_DID_UPDATE_LOCATION NS_SWIFT_NAME(updatedLocationNotification);
/*!
 @const SM_GEOFENCE_MANAGER_DID_UPDATE_LOCATION_EVENTS
 @abstract Notifies observers that the currently monitored location events were updated.
 @discussion The monitored location events can be accessed from the notification's <code>userInfo</code> property with the <code>kSMGeofenceManagerLocationEvents</code> key. Monitored geofence regions can be accessed with the <code>kSMGeofenceManagerMonitoredRegions</code> key.
 */
extern NSString * const SM_GEOFENCE_MANAGER_DID_UPDATE_LOCATION_EVENTS NS_SWIFT_NAME(updatedLocationEventsNotification);
/*!
 @const SM_GEOFENCE_MANAGER_DID_TRIGGER_LOCATION_EVENT
 @abstract Notifies observers that a location event was triggered.
 @discussion Information about the location event and the user's location when the event was triggered can be accessed from the notification's <code>userInfo</code> property.
 */
extern NSString * const SM_GEOFENCE_MANAGER_DID_TRIGGER_LOCATION_EVENT NS_SWIFT_NAME(triggeredLocationEventNotification);

/*!
 @const kSMGeofenceManagerLocation
 @abstract Can be used to access the current location from a notification's <code>userInfo</code> property.
 */
extern NSString * const kSMGeofenceManagerLocation NS_SWIFT_NAME(kLocation);
/*!
 @const kSMGeofenceManagerLocationEvents
 @abstract Can be used to access the currently monitored location events from a notification's <code>userInfo</code> property.
 */
extern NSString * const kSMGeofenceManagerLocationEvents NS_SWIFT_NAME(kLocationEvents);
/*!
 @const kSMGeofenceManagerMonitoredRegions
 @abstract Can be used to access the currently monitored geofence regions from a notification's <code>userInfo</code> property.
 */
extern NSString * const kSMGeofenceManagerMonitoredRegions NS_SWIFT_NAME(kMonitoredRegions);

/*!
 @const SM_GEOFENCE_MANAGER_MONITORED_EVENT_LIMIT
 @abstract The default maximum size for the amount of monitored location events in the <code>locationEvents</code> array.
 */
extern NSInteger const SM_GEOFENCE_MANAGER_MONITORED_EVENT_LIMIT NS_SWIFT_NAME(monitoredEventLimit);


/*!
 @class SMGeofenceManager
 @abstract Interface for SessionM Platform location tracking and geofencing services.
 */
@interface SMGeofenceManager : SMBaseManager <CLLocationManagerDelegate>

/*!
 @property isLocationServiceStarted
 @abstract <code>BOOL</code> indicating whether location updates have started.
 */
@property(nonatomic, assign, readonly) BOOL isLocationServiceStarted;
/*!
 @property isGeofenceServiceStarted
 @abstract <code>BOOL</code> indicating whether geofence updates have started.
 */
@property(nonatomic, assign, readonly) BOOL isGeofenceServiceStarted;
/*!
 @property currentLocation
 @abstract Most current <code>CLLocation</code> returned by location services.
 */
@property(nullable, nonatomic, strong, readonly) CLLocation *currentLocation;
/*!
 @property locationEvents
 @abstract Currently monitored events that can be triggered by entering or exiting a geofence.
 */
@property(nonatomic, strong, readonly) NSArray<SMGeolocationEvent *> *locationEvents;
/*!
 @property eventLimit
 @abstract The maximum size for the amount of monitored location events in the <code>locationEvents</code> array (default value is <code>SM_GEOFENCE_MANAGER_MONITORED_EVENT_LIMIT</code>).
 @discussion Note: the recommended and default value is <code>50</code>. Using large values can result in out-of-memory exceptions.
 */
@property(nonatomic, assign, readwrite) NSInteger eventLimit;

/*!
 @abstract Starts location updates.
 */
+ (void)registerLocationService;
/*!
 @abstract Starts region monitoring.
 */
+ (void)registerGeofenceService;

/*!
 @abstract Starts location updates.
 @discussion This call made on the <code>SMGeofenceManager</code> shared instance will start location updates. If permission is denied an <code>SM_GEOFENCE_MANAGER_VALIDATION_DID_FAIL_NOTIFICATION</code> notification will be fired.
 */
- (void)startLocationService;
/*!
 @abstract Stops location updates.
 @discussion This call made on the <code>SMGeofenceManager</code> shared instance will stop location updates. This does not clear monitored regions that persist across app launches.
 */
- (void)stopLocationService;

/*!
 @abstract Starts region monitoring.
 @discussion This call made on the <code>SMGeofenceManager</code> shared instance will start monitoring regions.
 */
- (void)startGeofenceService;
/*!
 @abstract Refreshes region monitoring based on SessionM Platform portal configurations.
 @discussion This call made on the <code>SMGeofenceManager</code> shared instance will refresh monitoring regions based on configurations setup by the developer in the SessionM Platform portal. Regions monitored persist across app launches and are only cleared via <code>stopGeofenceService</code>.
 */
- (void)refreshGeofenceService;
/*!
 @abstract Stops all region monitoring.
 @discussion This call made on the <code>SMGeofenceManager</code> shared instance will stop monitoring all regions.
 */
- (void)stopGeofenceService;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_GEOFENCE_MANAGER__ */
