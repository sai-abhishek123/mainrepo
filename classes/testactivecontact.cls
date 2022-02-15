@isTest
private class testactivecontact {
    @isTest static void Ac1(){
        Account acc=new Account(Active__c=True);
        insert acc;
        Contact c=new Contact();
        c.Active__c=acc.Active__c;
        c.LastName='Abhishek';
        insert c;
        System.assertEquals(acc.Active__c, c.Active__c);
    }
    @isTest static void Ac2(){
        Account acc=new Account(Active__c=False);
        Contact c=new Contact();
        c.LastName='Sai';
        c.Active__c=acc.Active__c;
        insert c;
        System.assertEquals(acc.Active__c, c.Active__c);
    }
}