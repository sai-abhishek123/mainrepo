trigger description on Account (after update,after insert) {
    List <Account> acc= [Select Description,(Select Description from Contacts) from Account Where Id in:Trigger.New];
    List<Contact> con=new List<Contact>();
    for(Account a:acc){
        Contact[] c=a.Contacts;
        for(Contact c2:c){
            c2.Description=a.Description;
            con.add(c2);
        }
    }
	update con;
}