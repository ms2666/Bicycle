#include <Servo.h>

/*Circuit Basics:

      reciever pin 1 into Arduino pin 22 // left joystick vertical
      reciever pin 2 into Arduino pin 24 // right joystick horizontal
      reciever pin 3 into Arduino pin 26 // right joystick vertical
      reciever pin 4 into Arduino pin 28 // left joystick horizontal
      reciever pin 5 into Arduino pin 30 // orange switch on right of remote
      reciever pin 6 into Arduino pin 32 // bent switch on left of remote
      
      5v power line into any positive pin of reciever
                    into red lead for both servos
      GND line into any negative pin of reciever
               into black lead for both servos
      
      signal line from Arduino pin 36 to rudder servo signal line (white/blue)
      signal line from Arduino pin 34 to trim tab servo signal line (blue)
      
      switches forward is locked, backward is unlocked
*/

#define RUDDER_MIDPOINT_OUT 107
#define TRIM_TAB_MIDPOINT_OUT 90
#define SERVO_MAX_STEP_SIZE 5
#define SERVO_MIN_ANGLE 15
#define SERVO_MAX_ANGLE 165

// Define servo pins
const int trimServoPin= 34;  // yoyoyoyoyoyoy
const int rudderServoPin= 36;

// Define variables
const int leftJoystickHorizontalPin= 28;    // controls trim tab    // pin 4
const int rightJoystickHorizontalPin= 26;   // controls rudder  // pin 2
const int orangeSwitchPin= 30;              // resets trim tab    // pin 5
const int bentSwitchPin= 32;                // resets rudder      // pin 6

// Varibles to store and display the values of each channel
int leftJoystickHorizontal= TRIM_TAB_MIDPOINT_OUT; // set servo to initial value
int rightJoystickHorizontal= RUDDER_MIDPOINT_OUT; // set servo to intial value
int orangeSwitch;
int bentSwitch;

// Define servos
Servo trimServo;
Servo rudderServo;

void setup() {
  Serial.begin(9600);
  // Set input pins
  pinMode(leftJoystickHorizontalPin, INPUT);
  pinMode(rightJoystickHorizontalPin, INPUT);
  pinMode(orangeSwitchPin, INPUT);
  pinMode(bentSwitchPin, INPUT);
  
  // Attach servos
  trimServo.attach(trimServoPin);
  rudderServo.attach(rudderServoPin);
  
  // Initialize servos
  trimServo.write(leftJoystickHorizontal);
  rudderServo.write(rightJoystickHorizontal);
}

void loop() {
  // Read input channels
  int leftJoystickHorizontalIncrement = pulseIn(leftJoystickHorizontalPin, HIGH);
  int rightJoystickHorizontalIncrement = pulseIn(rightJoystickHorizontalPin, HIGH);
  orangeSwitch = pulseIn(orangeSwitchPin, HIGH);
  bentSwitch = pulseIn(bentSwitchPin, HIGH);
  
  // Map servo increments
  leftJoystickHorizontalIncrement = map(leftJoystickHorizontalIncrement, 1900, 1103, -SERVO_MAX_STEP_SIZE, SERVO_MAX_STEP_SIZE);
  // Serial.print("\nLeft joystick value: ");
  // Serial.print(leftJoystickHorizontalIncrement);
  // Serial.print("\n");
  rightJoystickHorizontalIncrement = map(rightJoystickHorizontalIncrement, 1894, 1103, -SERVO_MAX_STEP_SIZE, SERVO_MAX_STEP_SIZE);
  Serial.print("\nRight joystick value: ");
  Serial.print(rightJoystickHorizontalIncrement);
  Serial.print("\n");
  // Map switches
  orangeSwitch = map(orangeSwitch, 1894, 1100, 0, 1);
  bentSwitch = map(bentSwitch, 1497, 1867, 0, 1);
  
  // If orangeSwitch is high, reset trim tab
  // Else adjust trim tab accordingly
  if(bentSwitch == 1) {
    leftJoystickHorizontal= TRIM_TAB_MIDPOINT_OUT;
  } else {
    leftJoystickHorizontal = leftJoystickHorizontal + leftJoystickHorizontalIncrement;
    leftJoystickHorizontal= constrain(leftJoystickHorizontal, SERVO_MIN_ANGLE, SERVO_MAX_ANGLE);
  }
  // If bentSwitch is high, reset rudder
  // Else adjust rudder accordingly
  if(orangeSwitch == 1) {
    rightJoystickHorizontal= RUDDER_MIDPOINT_OUT;
  } else {
    rightJoystickHorizontal = rightJoystickHorizontal + rightJoystickHorizontalIncrement;
    rightJoystickHorizontal= constrain(rightJoystickHorizontal, SERVO_MIN_ANGLE, SERVO_MAX_ANGLE);
  }
  
  // Write values to servos
  trimServo.write(leftJoystickHorizontal);
  rudderServo.write(rightJoystickHorizontal);
  
  // Display values on serial monitor
  Serial.print("Trim tab angle: ");
  Serial.print(leftJoystickHorizontal);
  Serial.print("\tRudder angle: ");
  Serial.print(rightJoystickHorizontal);
  Serial.print("\tOrange: ");
  Serial.print(orangeSwitch);
  Serial.print("\tBent: ");
  Serial.print(bentSwitch);
  Serial.print("\n");
}
