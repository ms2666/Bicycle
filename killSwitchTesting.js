var b = require('bonescript');
var outputPin = 'P8_15';
var duration = 5000;

b.pinMode(outputPin, b.OUTPUT);

var state = 0;
console.log(state);

function changeAndWriteState() {
    b.digitalWrite(outputPin, state);
	if(state === 1) {
        state = 0;
	} else {
        state = 1;
	}
    console.log(state);
}

var start = new Date().getTime();
//================================================
var timer = setInterval(changeAndWriteState, 1000);
function stopTimer() {
	clearInterval(timer);
}
setTimeout(stopTimer, duration);
//================================================
var end = new Date().getTime();

console.log(end-start + " milliseconds");