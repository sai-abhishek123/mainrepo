trigger updatecontactactive on Account (after insert,after update) {
    List <Account> acc=[Select Active__c,(Select Active__c from Contacts) from Account where Id in:Trigger.New];
    List <Contact> conlist=new List<Contact>();
    for(Account a:acc){
        Contact[] con2=a.Contacts;
        for(Contact c2:con2){
            c2.Active__c=a.Active__c;
            conlist.add(c2);
        }
    }
    update conlist;
}