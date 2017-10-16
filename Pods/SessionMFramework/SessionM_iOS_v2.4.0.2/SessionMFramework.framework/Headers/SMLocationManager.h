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

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

NS_ASSUME_NONNULL_BEGIN

/*!
 @group SMLocationManager Notifications
 @deprecated mPLUS Rewards APIs are deprecated. For more information, please refer to the SessionM Platform documentation site: https://mmc.sessionm.com/docs/mmc-sdk/
 */

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
 @const SMLocationManagerWhenInUseLocationServicesDisabled
 @abstract This notification is sent when region monitoring fails due to not having "when in use" permission.
 @discussion When this notification is recieved, region monitoring did not start because "when in use" permission was not granted. Simply call @link startGeofenceService @/link to try again. The notification's <code>userInfo</code> will have the <code>\@"error"</code> key set to the error.
 */
extern NSString *const SMLocationManagerWhenInUseLocationServicesDisabled NS_SWIFT_NAME(disabledWhenInUseLocationServicesNotification);

/*!
 @const SMLocationManagerMonitoredEventLimit
 @abstract The default maximum size for the amount of monitored location events in the @link locationEvents @/link array.
 */
extern NSInteger const SMLocationManagerMonitoredEventLimit NS_SWIFT_NAME(monitoredEventLimit);

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
 @deprecated mPLUS Rewards APIs are deprecated. For more information, please refer to the SessionM Platform documentation site: https://mmc.sessionm.com/docs/mmc-sdk/
 */
__attribute__((deprecated("mPLUS Rewards APIs are deprecated. For more information, please refer to the SessionM Platform documentation site: @link https://mmc.sessionm.com/docs/mmc-sdk/")))
@interface SMLocationManager : NSObject<CLLocationManagerDelegate>

/*!
 @property isLocationServiceStarted
 @abstract <code>BOOL</code> indicating whether location updates have started or not.
 */
@property(nonatomic, assign, readonly) BOOL isLocationServiceStarted;
/*!
 @property isGeofenceServiceStarted
 @abstract <code>BOOL</code> indicating whether geofence updates have started or not.
 */
@property(nonatomic, assign, readonly) BOOL isGeofenceServiceStarted;
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
 @property eventLimit
 @abstract The maximum size for the amount of monitored location events in the @link locationEvents @/link array (default value is @link SMLocationManagerMonitoredEventLimit @/link).
 @discussion Note: the recommended and default value is <code>50</code>. Using large values can result in out-of-memory exceptions.
 */
@property(nonatomic, assign, readwrite) NSInteger eventLimit;

/*!
 @abstract Returns singleton <code>SMLocationManger</code> service instance with a monitored location event limit of @link SMLocationManagerMonitoredEventLimit @/link.
 @result <code>SMLocationManger</code> service object.
 */
+ (SMLocationManager *)sharedInstance;

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
 @discussion This call made on the <code>[SMLocationManager sharedInstance]</code> object will start location updates. If permission is denied a @link SMLocationManagerLocationServicesDisabled @/link notification will be fired.
 */
- (void)startLocationService;
/*!
 @abstract Stops location updates.
 @discussion This call made on the <code>[SMLocationManager sharedInstance]</code> object will stop location updates. This does not clear monitored regions that persist across app launches.
 */
- (void)stopLocationService;

/*!
 @abstract Starts region monitoring.
 @discussion This call made on the <code>[SMLocationManager sharedInstance]</code> object will start monitoring regions.
 */
- (void)startGeofenceService;
/*!
 @abstract Refreshes region monitoring based on SessionM Platform portal configurations.
 @discussion This call made on the <code>[SMLocationManager sharedInstance]</code> object will refresh monitoring regions based on configurations setup by the developer in the SessionM Platform portal. Regions monitored persist across app launches and are only cleared via @link stopGeofenceService @/link.
 */
- (void)refreshGeofenceService;
/*!
 @abstract Stops all region monitoring.
 @discussion This call made on the <code>[SMLocationManager sharedInstance]</code> object will stop monitoring all regions.
 */
- (void)stopGeofenceService;

@end

NS_ASSUME_NONNULL_END

#pragma clang diagnostic pop

#endif /* __SM_LOCATION_MANAGER__ */
