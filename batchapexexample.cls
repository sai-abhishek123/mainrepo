global class batchapexexample implements database.Batchable<sobject> {
    global database.QueryLocator start(database.BatchableContext BC){
        String query='Select ID,Name from Account';
        return database.getQueryLocator(query);
    }
    global void execute(database.BatchableContext BC,List<Account> Scope){
        for(Account a:scope){
            a.Name=a.Name+' '+'Wipro';
        }
        update scope;
    }
    global void finish(database.BatchableContext BC){}
}