global class qwe implements database.Batchable<sobject>{
    global database.QueryLocator start(Database.BatchableContext BC){
        String con='Select ID,LastName,FirstName from Contact';
        return database.getQueryLocator(con);
    }
    global void execute(database.BatchableContext BC,List<Contact> con1){
        for(Contact c2:con1){
            c2.FirstName=c2.LastName+' '+ 'Edo';
        }
        update con1;
    }
    global void finish(database.BatchableContext BC){}
}