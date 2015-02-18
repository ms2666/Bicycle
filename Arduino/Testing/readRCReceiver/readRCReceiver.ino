//This will sketch will read all 6 channels of a RC reciever and input the values via serial monitor.
//Programed for the Arduino MEGA 2560
// Mukund Sudarshan
// 10/30/14

// Define Variables:
const int chA=22;  //Constant variables relating to pin locations
const int chB=24;
const int chC=26;
const int chD=28;
const int chE=30;
const int chF=32;

//Varibles to store and display the values of each channel
int ch1;  // left joystick vertical
int ch2;  // right joystick horizontal
int ch3;  // right joystick vertical
int ch4;  // left joystick horizontal
int ch5;  // orange switch on right of remote (landing gear)
int ch6;  // bent switch on left of remote



// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // Set input pins
  pinMode(chA, INPUT);
  pinMode(chB,INPUT);
  pinMode(chC,INPUT);
  pinMode(chD,INPUT);
  pinMode(chE,INPUT);
  pinMode(chF,INPUT);

}

//Main Program
void loop() {
  // read the input channels
  ch1 = pulseIn (chA,HIGH);  //Read and store channel 1
  ch1 = map(ch1, 1094, 1887, 0, 1000);
  ch1 = map(ch1, -1, 1001, 0, 100);
  Serial.print ("Ch1:\t");  //Display text string on Serial Monitor to distinguish variables
  Serial.print (ch1);     //Print in the value of channel 1
  Serial.print ("\t\t");
 
  ch2 = pulseIn (chB,HIGH);
  ch2 = map(ch2, 1894, 1103, -1000, 1000);
  ch2 = map(ch2, -995, 1002, -100, 100);
  Serial.print ("Ch2:\t");
  Serial.print (ch2);
  Serial.print ("\t\t");
// 
  ch3 = pulseIn (chC,HIGH); // MAX = 1895, MIN = 1095, STABLE = 1485
  ch3 = map(ch3, 1095, 1900, -1000, 1000);
  ch3 = map(ch3, -1000, 972, -100, 100);
  Serial.print ("Ch3:\t");
  Serial.print (ch3);
  Serial.print ("\t\t");
 
  ch4 = pulseIn (chD,HIGH);
  ch4 = map(ch4, 1893, 1098, -1000, 1000);
  ch4 = map(ch4, -999, 989, -100, 100);
  Serial.print ("Ch4:\t");
  Serial.print (ch4);
  Serial.print ("\t\t");
// 
  ch5 = pulseIn (chE,HIGH);
  ch5 = map(ch5, 1894, 1100, 0, 1);
  Serial.print ("Ch5:\t");
  Serial.print (ch5);
  Serial.print ("\t\t");
// 
  ch6 = pulseIn (chF,HIGH);
  ch6 = map(ch6, 1497, 1867, 0, 1);
  Serial.print ("Ch6:\t");
  Serial.print (ch6);
  Serial.print ("\n");
  
  delay(50);
}

