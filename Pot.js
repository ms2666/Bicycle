var b = require('bonescript');
var LED = 'P9_14';  // LED pin
var potentiometer = 'P9_40';    // potentiometer input
var resolution = 250;   // sample rate

// PWM output to LED
function usePot(x) {
    b.analogWrite(LED, x.value, 2000);
}

// Reads potentiometer value
function getPot() {
    b.analogRead(potentiometer, usePot);
}

// Timers
var timer = setInterval(getPot, resolution);   // gets potentiometer value every .25 sec
function stopTimer() {
    clearInterval(timer);   // function to end above loop
}
//setTimeout(stopTimer, 15000);   // executes stopTimer after 15 sec of activity