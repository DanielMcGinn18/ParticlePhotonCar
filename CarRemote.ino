int joyY_left = A0; // y - axis of Left Joystick
int joyX_left = A1; //  X - axis of Left Joystick
int joyY_right = A2; // y - axis of Right Joystick
int joyX_right = A3; // X - axis of Right Joystick
int sel_left = 2;
int sel_right = 3;
unsigned x_left, y_left, x_right, y_right, Direction_left, Speed_left, Direction_right, Speed_right, s_left, s_right; // initilize variable

// The X axis of the joysticks go unused in the code

// Initialize Strings used to send vlaues over the particle cloud
char Direction_left_str[40];
char Speed_left_str[40];
char Direction_right_str[40];
char Speed_right_str[40];

void setup()
{ 
 Serial.begin(9600);
Particle.variable("Left",Speed_left_str); // To view varibles in the CLI
Particle.variable("Right",Speed_right_str);
} 

void loop()
{ 
  y_left = analogRead(joyY_left)/4;    // y value btwn 0 and 1023)
  x_left = analogRead(joyX_left)/4;    // x value btwn 0 and 1023)
  y_right = analogRead(joyY_right)/4;    // y value btwn 0 and 1023)  
  x_right = analogRead(joyX_right)/4;    // x value btwn 0 and 1023) 
  s_left = digitalRead(sel_left);
  s_right = digitalRead(sel_right);

  if (y_left >= 500) {
    Direction_left = 1; // Forward
    Speed_left = .243*y_left - 121.5; // Speed
  }
  if (y_left <= 490) {
    Direction_left = 0; // Reverse
    Speed_left = -.259*y_left + 126.9; // Speed
  }
  if (y_left < 500 && y_left > 490) {
    //Direction is irrelevant
    Speed_left = 0; // No motion
  }

if (y_right >= 500) {
    Direction_right = 1; // Forward
    Speed_right = .243*y_right - 121.5; // Speed
  }
  if (y_right <= 490) {
    Direction_right = 0; // Reverse
    Speed_right = -.259*y_right + 126.9; // Speed
  }
  if (y_right < 500 && y_right > 490) {
    //Direction is irrelevant
    Speed_right = 0; // No motion
  }
  
  if (s_left == 0) {
      Speed_left = Speed_left*2;
  }
  
  if (s_right ==0) {
      Speed_right = Speed_right*2;
  }

// Publish the Speed and Direction to the cloud
    sprintf(Direction_left_str,"%d",Direction_left);
    Particle.publish("Dir_left", Direction_left_str);
    sprintf(Speed_left_str,"%d",Speed_left);
    Particle.publish("Speed_left", Speed_left_str);
    sprintf(Direction_right_str,"%d",Direction_right);
    Particle.publish("Dir_right", Direction_right_str);
    sprintf(Speed_right_str,"%d",Speed_right);
    Particle.publish("Speed_right", Speed_right_str);
    
// Debugging the speed control
/*    Serial.print("Left Y Value:");
    Serial.print(y_left);
    Serial.print("          Right Y Value:");
    Serial.println(y_right);
    Serial.print("Left Speed:");
    Serial.print(Speed_left);
    Serial.print("          Right Speed:");
    Serial.println(Speed_right); */
    
// Debugging Select Button
    Serial.print("Left Select:  ");
    Serial.println(s_left);
    Serial.print("Right Select:  ");
    Serial.println(s_right);
    
    delay(4000);  //the number of publish commands is limited to a certain number per minute 
}