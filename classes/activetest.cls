@isTest
public class activetest{
    static testmethod void t1(){
        Account a1=new Account();
        Contact c1=new Contact();
        a1.Active__c=True;
        insert a1;
        System.assert(a1.Active__c,c1.Active__c);
    }
}