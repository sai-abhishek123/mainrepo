@isTest
private class testqwe{
    @isTest static void tss(){
        Account a=new Account(Name='Abhishek');
        insert a;
        Contact c=new Contact();
        System.assertEquals('Abhishek', c.Description);
    }
    @isTest static void test2(){
        Account a=new Account(Name='Yolo');
        insert a;
        Contact c=new Contact();
        System.assertEquals('Yolo',c.Description);
    }
}