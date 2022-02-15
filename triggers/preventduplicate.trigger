trigger preventduplicate on Contact(before insert){
   {
    for (Contact a:Trigger.new){
        List<Contact> con=[Select LastName from Contact where LastName=:a.LastName];
 	    if(con.size()>0){
            a.adderror('Cant insert as there is a contact with the same name');
        }
   }
}
}