// Joystick x- and y- axes are connected to A1 and A0 analog pins of Arduino.
int joyY_left = A0; // y - axis of Left Joystick
int joyX_left = A1; //  X - axis of Left Joystick
int joyY_right = A2; // y - axis of Right Joystick
int joyX_right = A3; // X - axis of Right Joystick
int x_left, y_left, x_right, y_right, Direction_left, Speed_left, Direction_right, Speed_right; // initilize variable

// The X axis of the joysticks go unused in the code

void setup()
{ 
  Serial.begin(9600);
} 

void loop()
{ 
  y_left = analogRead(joyY_left);    // y value btwn 0 and 1023)
  x_left = analogRead(joyX_left);    // x value btwn 0 and 1023)
  y_right = analogRead(joyY_right);    // y value btwn 0 and 1023)  
  x_right = analogRead(joyX_right);    // x value btwn 0 and 1023) 

  Serial.print("Y Value:");
  Serial.println(y_left);
  delay(500); //wait .5 sec

/*  if (y_left >= 500) {
    Direction_left = 0; // Forward
    Speed_left = .487*y_left - 243.5; // Speed
  }
  if (y_left <= 490) {
    Direction_left = 1; // Reverse
    Speed_left = -.520*y_left + 254.8; // Speed
  }
  if (y_left <= 500 || y_left >= 490) {
    //Direction is irrelevant
    Speed_left = 0; // No motion
  }

if (y_right >= 500) {
    Direction_right = 0; // Forward
    Speed_right = .487*y_left - 243.5; // Speed
  }
  if (y_right <= 490) {
    Direction_right = 1; // Reverse
    Speed_right = -.520*y_left + 254.8; // Speed
  }
  if (y_right <= 500 || y_right >= 490) {
    //Direction is irrelevant
    Speed_right = 0; // No motion
  }
    Particle.publish("Dir_left", String(Direction_left));
    Particle.publish("Speed_left", String(Speed_left));
    Particle.publish("Dir_right", String(Direction_right));
    Particle.publish("Speed_right", String(Speed_right)); */
}
