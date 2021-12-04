@isTest
private class testactivecontact3 {
    @isTest static void Activecheck(){
        Account acc=new Account(Active__c=True);
        insert acc;
        Contact c=new Contact(Active__c=acc.Active__c,LastName='Sai');
        insert c;
        System.assertEquals(true, c.Active__c);
    }
    @isTest static void Ac1(){
        Account acc=new Account(Active__c=False);
        insert acc;
        Contact c=new Contact(Active__c=acc.Active__c);
        System.assertEquals(false, c.Active__c=False);
    }
}