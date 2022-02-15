trigger email on Case (before insert) {
    for(Case d:Trigger.new){
        if(d.Origin=='Email'){
            d.Status='New';
            d.Priority='Medium';
        }
    }
}