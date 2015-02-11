var start = new Date().getTime();
for (i=0; i<10; i++) {
	console.log("wasting time");
}
var end = new Date().getTime();

console.log(end-start + " milliseconds");