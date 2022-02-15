trigger bi on Account(after insert){
    List <Account> acc=[Select Id,Name,(Select Description,Id from Contacts) from Account where ID in:Trigger.new];
    List<Contact> con=new List<Contact>();
    for(Account a:acc){
        Contact[] c=a.Contacts;
        for(Contact c1:c){
            c1.Description=a.Name;
            con.add(c1);
        }
    }
    insert con;
}