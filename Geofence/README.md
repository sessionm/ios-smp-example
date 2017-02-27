Geofence
========

This app showcases how to use the APIs defined by the `SMLocationManager` and `SMLocationEvent` classes to track the user's location and monitor regions that the user enters and exits.

The "Map" tab contains a view of the user's immediate surroundings, and can contain three colored pin annotations:

1. Green pins and their circular overlays mark geofences that are actively being monitored. Click on a pin to see the location events associated with the geofence, and whether they are triggered by entering or exiting the geofence.
2. Red pins mark the user's location at the time of an "Enter" location event trigger. Click on a pin to see the coordinates and time of the trigger.
3. Purple pins mark the user's location at the time of an "Exit" location event trigger. Click on a pin to see the coordinates and time of the trigger.

***
Note: geofence and event trigger annotations in the same location will be clustered into one pin, and clicking on that pin will list the data for each of the contained annotations in a table.
***

The "Triggered Events" tab contains a more detailed history of event triggers.

When running the Geofence app through Xcode, the `sessionm.gpx` file is used to walk a simulated path through some of the geofences in the SessionM demo environment. To use your own GPX file, navigate in Xcode to "Debug" -> "Simulate Location" -> "Add GPX File to Workspace".


LICENSE: MIT
