/*
This file is generated and isn't the actual source code for this
managed global class.
This read-only file shows the class's global constructors,
methods, variables, and properties.
To enable code to compile, all methods return null.
*/
global interface ShippingManager {
    String cancelPickupRequest(String param0, String param1);
    String cancelShipment(String param0, String param1);
    Astonous_SM.PickupAvailabilityResponse checkPickUpAvailability(Astonous_SM.PickupRequest param0);
    List<Astonous_SM.ShippingRate> fetchAllShippingRates(Astonous_SM.RatingRequest param0);
    String processShipment(Astonous_SM.RatingRequest param0, String param1);
    String schedulePickupRequest(Astonous_SM.PickupRequest param0);
    Astonous_SM__Shipment_Manifest__c submitManifestRequest(Astonous_SM.PickupRequest param0);
    Astonous_SM.TrackingResponse trackByTrackingNUmber(String param0);
}
