trigger AccountDuplicateTrigger on Account (before insert, before the update)
{
 for(Account a:Trigger.new)
 {
 List<Account> acc=“Select id from Account where Name=:a.Name and Rating=:a.Rating “;
 if(acc.size()>0)
 {
 acc.Name.addError('You Cannot Create the Duplicate Account'); 
 }
 }
}