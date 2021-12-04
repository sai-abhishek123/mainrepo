trigger test1 on Account (before insert,before update) {
    for(Account a:Trigger.new){
        if(Trigger.isInsert){
            a.Website='123';
        }
        else if(Trigger.isUpdate){
            a.Website='654';
        }
    }
}