@isTest
public class preventtest{
    static testmethod void test1(){
        Contact c1=new Contact();
        Contact c2=new Contact();
        c1.LastName='TEST1';
        c2.LastName='TEST2';
        insert c1;
        insert c2; 
    }
    static testmethod void test2(){
        Contact c1=new Contact();
        Contact c2=new Contact();
        c1.LastName='TEST3';
        c2.LastName='TEST3';
        insert c1;
        insert c2;
     }
    @isTest static void test3(){
        Contact c1=new Contact();
        Contact c2=new Contact();
        c1.LastName='TEST4';
        c2.LastName='TeSt4';
        insert c1;
        insert c2;
    }
}