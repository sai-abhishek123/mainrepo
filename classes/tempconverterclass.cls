@isTest
private class tempconverterclass {
    @isTest static void test1(){
        Decimal cs=tempconverter.con(70);
        System.assertEquals(21.1,cs);
    }
    @isTest static void test2(){
        Decimal cs=tempconverter.con(212);
        System.assertEquals(0,cs,'Boiling point is not as expected');
    }
    
}