/*
This file is generated and isn't the actual source code for this
managed global class.
This read-only file shows the class's global constructors,
methods, variables, and properties.
To enable code to compile, all methods return null.
*/
global class ShippingController {
    @AuraEnabled
    global static String cancelPickupRequest(Astonous_SM__Scheduled_Pickup_Request__c pickUpRequest, String remark) {
        return null;
    }
    @AuraEnabled
    global static String cancelShipment(String recordID) {
        return null;
    }
    @AuraEnabled
    global static Astonous_SM.PickupAvailabilityResponse checkPickUpAvailability(Astonous_SM.PickupRequest pickUpRequest) {
        return null;
    }
    @AuraEnabled
    global static List<Astonous_SM.ShippingRate> fetchAllShippingRates(Astonous_SM.RatingRequest ratingReq) {
        return null;
    }
    @AuraEnabled
    global static String processShipment(Astonous_SM.RatingRequest ratingReq, String itemId) {
        return null;
    }
    @AuraEnabled
    global static String schedulePickupRequest(Astonous_SM.PickupRequest pickUpRequest) {
        return null;
    }
    @AuraEnabled
    global static Astonous_SM.TrackingResponse trackShipment(String trackingNumber, String shippingCarrier) {
        return null;
    }
}
