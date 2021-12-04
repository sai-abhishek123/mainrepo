trigger name on Account (before insert) {
    for(Account c:Trigger.new){
        c.Name='Welcome '+c.Name;
    }
}