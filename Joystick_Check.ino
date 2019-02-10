// Joystick x- and y- axes are connected to A1 and A0 analog pins of Arduino.
int joyX = A1; //  X - axis of Joystick
int joyY = A0; // y - axis of Joystick
int x, y; 

void setup()
{ 
  Serial.begin(9600);
} 

void loop()
{ 
  x = analogRead(joyX);    // y value btwn 0 and 1023) 
  y = analogRead(joyY);    // x value btwn 0 and 1023) 

  Serial.print("X Value:");
  Serial.print(x);
  Serial.print("     Y Value:");
  Serial.println(y);
  delay(500);
}
