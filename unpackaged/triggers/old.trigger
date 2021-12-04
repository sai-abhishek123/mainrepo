trigger old on Account (before update) {
    for(Account a:Trigger.New){
        a.BillingStreet=a.Description;
    }
}