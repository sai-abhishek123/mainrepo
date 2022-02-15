<?xml version="1.0" encoding="UTF-8"?>
<Workflow xmlns="http://soap.sforce.com/2006/04/metadata">
    <alerts>
        <fullName>New_Account</fullName>
        <description>New Account</description>
        <protected>false</protected>
        <recipients>
            <type>owner</type>
        </recipients>
        <recipients>
            <recipient>sai.abhishek905@gmail.com</recipient>
            <type>user</type>
        </recipients>
        <recipients>
            <recipient>th20182242@wipro.com</recipient>
            <type>user</type>
        </recipients>
        <senderType>CurrentUser</senderType>
        <template>LightningFolder/New_account_1615191141995</template>
    </alerts>
    <fieldUpdates>
        <fullName>Account_Reject</fullName>
        <field>Active__c</field>
        <literalValue>0</literalValue>
        <name>Account Reject</name>
        <notifyAssignee>false</notifyAssignee>
        <operation>Literal</operation>
        <protected>false</protected>
        <reevaluateOnChange>false</reevaluateOnChange>
    </fieldUpdates>
    <rules>
        <fullName>New Account</fullName>
        <actions>
            <name>New_account_created</name>
            <type>Task</type>
        </actions>
        <active>true</active>
        <criteriaItems>
            <field>Account.Name</field>
            <operation>notEqual</operation>
        </criteriaItems>
        <triggerType>onCreateOnly</triggerType>
    </rules>
    <tasks>
        <fullName>New_account_created</fullName>
        <assignedTo>ramuk@wipro.com</assignedTo>
        <assignedToType>user</assignedToType>
        <dueDateOffset>10</dueDateOffset>
        <notifyAssignee>false</notifyAssignee>
        <offsetFromField>User.CreatedDate</offsetFromField>
        <priority>Normal</priority>
        <protected>false</protected>
        <status>Not Started</status>
        <subject>New account created</subject>
    </tasks>
</Workflow>
