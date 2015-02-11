var b = require('bonescript');
var inputPin = 'P8_19';  // input pin
b.pinMode(inputPin, b.INPUT); // assigns pin mode to GPIO
// assigns an interrupt to listen to the input pin for a change
b.attachInterrupt(inputPin, true, b.CHANGE, interruptCallback);
// the following function can be deleted so that BBB listens to the port forever
setTimeout(detach, 12000);

// prints out the pin state when a change is detected
// This function can be used to do anything, such as kill the motor control program
function interruptCallback(x) {
    console.log(JSON.stringify(x));
}

// stops BBB from listening to the port
function detach() {
    b.detachInterrupt(inputPin);
    console.log('Interrupt detached');
}