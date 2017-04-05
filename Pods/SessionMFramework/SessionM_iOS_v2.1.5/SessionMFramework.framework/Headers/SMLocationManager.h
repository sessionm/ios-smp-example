//
//  SMLocationManager.h
//  SessionM
//
//  Copyright © 2017 SessionM. All rights reserved.
//

#ifndef __SM_LOCATION_MANAGER__
#define __SM_LOCATION_MANAGER__

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "SMLocationEvent.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @const SMLocationManagerUpdateNotification
 @abstract This notification is sent when the location is updated.
 @discussion The notification's <code>userInfo</code> will have the <code>\@"location"</code> key set to the current location.
 */
extern NSString *const SMLocationManagerUpdateNotification NS_SWIFT_NAME(locationUpdateNotification);
/*!
 @const SMLocationManagerLocationServicesDisabled
 @abstract This notification is sent when location services are disabled.
 @discussion Whenever the location service has been started but the device does not have permission to use location services, this notification is fired.
 */
extern NSString *const SMLocationManagerLocationServicesDisabled NS_SWIFT_NAME(disabledLocationServicesNotification);
/*!
 @const SMLocationManagerMonitorRegionsDidFailWithErrorNotification
 @abstract This notification is sent when region monitoring fails.
 @discussion When this notification is recieved, region monitoring did not start. Simply call @link startGeofenceService @/link to try again. The notification's <code>userInfo</code> will have the <code>\@"error"</code> key set to the error.
 */
extern NSString *const SMLocationManagerMonitorRegionsDidFailWithErrorNotification NS_SWIFT_NAME(regionMonitoringFailureNotification);
/*!
 @const SMLocationManagerAlwaysOnLocationServicesDisabled
 @abstract This notification is sent when region monitoring fails due to not having always on permission.
 @discussion When this notification is recieved, region monitoring did not start because always on permission was not granted. Simply call @link startGeofenceService @/link to try again. The notification's <code>userInfo</code> will have the <code>\@"error"</code> key set to the error.
 */
extern NSString *const SMLocationManagerAlwaysOnLocationServicesDisabled NS_SWIFT_NAME(disabledAlwaysOnLocationServicesNotification);

/*!
 @const SMLocationManagerMonitoredEventLimit
 @abstract The default maximum size for the amount of monitored location events in the @link locationEvents @/link array.
 */
extern NSUInteger const SMLocationManagerMonitoredEventLimit NS_SWIFT_NAME(monitoredEventLimit);

/*!
 @const SMLocationManagerDidUpdateGeoLocations
 @abstract Notifies observers that the currently monitored location events were updated.
 @discussion Currently monitored location events can be accessed from the notification's <code>userInfo</code> property with the @link kSMLocationManagerLocationsKey @/link key. Currently monitored geofence regions can be accessed with the @link kSMLocationManagerRegionsKey @/link key.
 */
extern NSString * const SMLocationManagerDidUpdateGeoLocations NS_SWIFT_NAME(updatedLocationEventsNotification);
/*!
 @const kSMLocationManagerLocationsKey
 @abstract Can be used to access the currently monitored location events from a notification's <code>userInfo</code> property.
 */
extern NSString * const kSMLocationManagerLocationsKey NS_SWIFT_NAME(kLocationEvents);
/*!
 @const kSMLocationManagerRegionsKey
 @abstract Can be used to access the currently monitored geofence regions from a notification's <code>userInfo</code> property.
 */
extern NSString * const kSMLocationManagerRegionsKey NS_SWIFT_NAME(kMonitoredRegions);
/*!
 @const SMLocationManagerDidTriggerLocation
 @abstract Notifies observers that a location event was triggered.
 @discussion Information about the location event and the user's location when the event was triggered can be accessed from the notification's <code>userInfo</code> property.
 */
extern NSString * const SMLocationManagerDidTriggerLocation NS_SWIFT_NAME(triggeredLocationEventNotification);


/*!
 @class SMLocationManager
 @abstract SessionM Location service interface. This is the main class in SessionM Location iOS SDK. It defines methods for all location based operations such as location and region monitoring.
 */
@interface SMLocationManager : NSObject<CLLocationManagerDelegate>

/*!
 @property isStarted
 @abstract <code>BOOL</code> indicating whether location updates have started or not.
 */
@property(nonatomic, readonly) BOOL isStarted;
/*!
 @property isGeofenceServiceStarted
 @abstract <code>BOOL</code> indicating whether geofence updates have started or not.
 */
@property(nonatomic, readonly) BOOL isGeofenceServiceStarted;
/*!
 @property currentGeoLocation
 @abstract Most current CLLocation returned by location services.
 */
@property(nullable, nonatomic, strong, readonly) CLLocation *currentGeoLocation;
/*!
 @property locationEvents
 @abstract Currently monitored events that can be triggered by entering or exiting a geofence.
 */
@property(nullable, nonatomic, strong, readonly) NSArray<SMLocationEvent *> *locationEvents;

/*!
 @abstract Returns singleton <code>SMLocationManger</code> service instance with a monitored location event limit of @link SMLocationManagerMonitoredEventLimit @/link.
 @result <code>SMLocationManger</code> service object.
 */
+ (SMLocationManager *)sharedInstance;
/*!
 @abstract In AppDelegate, application:didFinishLaunchingWithOptions: add this method so that Location services are started.
 call either @link initLocation @/link or @link initGeofence @/link
 */
+ (void)registerLocationService;
/*!
 @abstract In AppDelegate, application:didFinishLaunchingWithOptions: add this method so that Location services are started.
 call either @link initLocation @/link or @link initGeofence @/link
 */
+ (void)registerGeofenceService;
/*!
 @abstract Starts location/Geofence services.
 @discussion This call made on the <code>[SMLocationManager sharedInstance]</code> object will start location updates. If permission is denied a @link SMLocationManagerLocationServicesDisabled @/link notification will be fired. This method looks for the Cocoa Key <code>NSLocationAlwaysUsageDescription</code> to determine whether to start always-on or while-in-use monitoring.
 */
- (void)startLocationService;
/*!
 @abstract Stops location/Geofence services.
 @discussion This call made on the <code>[SMLocationManager sharedInstance]</code> object will stop location updates. This does not clear monitored regions that persist across app launches.
 */
- (void)stopLocationService;
/*!
 @abstract Refreshes region monitoring based on SessionM Mobile Marketing Cloud portal configurations.
 @discussion This call made on the <code>[SMLocationManager sharedInstance]</code> object will refresh monitoring regions based on configurations setup by the developer in the SessionM Mobile Marketing Cloud portal. Regions monitored persist across app launches and are only cleared via @link stopGeofenceService @/link. Required always-on location permission to work.
 */
- (void)refreshGeofenceService;
/*!
 @abstract Stops all region monitoring.
 @discussion This call made on the <code>[SMLocationManager sharedInstance]</code> object will stop monitoring all regions.
 */
- (void)stopGeofenceService;
/*!
 @abstract Start all region monitoring.
 @discussion This call made on the <code>[SMLocationManager sharedInstance]</code> object will stop monitoring all regions.
 */
- (void)startGeofenceService;

@end

NS_ASSUME_NONNULL_END

#endif /* __SM_LOCATION_MANAGER__ */
