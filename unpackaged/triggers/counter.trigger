trigger counter on Account(before insert){
    List<id> aid=new list<id>();
    for(Account a:Trigger.new){
        aid.add(a.id);
    }
    List<Account> acclist=[Select Id,(Select Id from Contacts) from Account where Id in:aid];
    List<Account> c=new List<Account>();
        for(Account b:acclist){
            Trigger.newmap.get(b.Id).Contact_count__c=b.Contacts.size();
           }
    }