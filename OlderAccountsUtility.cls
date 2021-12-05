public class OlderAccountsUtility{
    public static void updateOlderAccounts(){
        Account[] oldAccounts=[Select Id,Description from Account Order By CreatedDate ASC Limit 5];
        for(Account acc:oldAccounts){
            acc.Description='Heritage Account';
        }
        update oldAccounts;
    }
}