import { LightningElement } from 'lwc';
export default class Helloworld extends LightningElement {
    greeting = "World";
    changehandler(event){
        this.greeting=event.target.value;
    }
}