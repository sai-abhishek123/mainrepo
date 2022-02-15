trigger nodelete on Opportunity (before delete) {
    for(Opportunity opp:Trigger.old){
        if(opp.StageName=='Qualification'&&opp.AccountId!=null){
            opp.addError('Cant delete');
        }
    }

}