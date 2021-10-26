trigger dup1 on Opportunity (before insert) {
    for(Opportunity c:Trigger.new){
        List<Opportunity> opp=[Select Name from Opportunity where Name=:c.Name];
        if(opp.size()>0){
            c.addError('Cant insert existing opportunity');
        }
    } 
}