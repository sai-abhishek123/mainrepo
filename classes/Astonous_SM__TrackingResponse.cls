/*
This file is generated and isn't the actual source code for this
managed global class.
This read-only file shows the class's global constructors,
methods, variables, and properties.
To enable code to compile, all methods return null.
*/
global class TrackingResponse {
    global Astonous_SM.Address destinationAddress {
        get;
        set;
    }
    global String estimatedDeliveryTimestamp {
        get;
        set;
    }
    global String notifications {
        get;
        set;
    }
    global String serviceCommitMessage {
        get;
        set;
    }
    global Astonous_SM.Address shippingAddess {
        get;
        set;
    }
    global List<Astonous_SM.TrackingResponse.ShippingEvent> shippingEvents {
        get;
        set;
    }
    global Astonous_SM.TrackingResponse.ShippingEvent statusInformation {
        get;
        set;
    }
    global Boolean trackedSuccessfully {
        get;
        set;
    }
global class ShippingEvent {
    global String eventAddressString {
        get;
        set;
    }
    global String eventDescription {
        get;
        set;
    }
    global Datetime eventTime {
        get;
        set;
    }
    global String statusCode {
        get;
        set;
    }
}
}
