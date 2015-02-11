var b = require('bonescript');
var varOut = 'P8_12';
var conOut = 'P8_13';
var buttonOne = 'P8_19';
var buttonTwo = 'P8_46';


// Set the following pins to output and input
b.pinMode(varOut, b.OUTPUT);
b.pinMode(conOut, b.OUTPUT);
b.pinMode(buttonOne, b.INPUT);
b.pinMode(buttonTwo, b.INPUT);


// Attatch interrupts
b.attachInterrupt(buttonOne, true, b.RISING, stopTimer);
b.attachInterrupt(buttonTwo, true, b.RISING, stopRC);


// initialize variables, set constant output to high
var state = 0;
console.log("State is of variable output is: " + state);
b.digitalWrite(conOut, b.HIGH);


// Produce the digital signal
function changeAndWriteState() {
    b.digitalWrite(varOut, state);
	if (state === 1) {
		state = 0;
	} else {
		state = 1;
	}
	console.log("State is of variable output is: " + state);
}


// ==================Timing functions==========================
var timer = setInterval(changeAndWriteState, 1000);         
												             
// Cancels the operation of the flashing LED                
function stopTimer() {
	clearInterval(timer);
	b.digitalWrite(varOut, b.LOW);				                     
}

// Cancels the continuous signal
function stopRC() {
	b.digitalWrite(conOut, b.LOW);
}
// ============================================================
