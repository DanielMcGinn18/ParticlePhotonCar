//motor A connected between A01 and A02
//motor B connected between B01 and B02

int STBY = 4; //standby

//Motor A
int PWMA = 0; //Speed control
int AIN2 = 2; //Direction
int AIN1 = 3; //Direction

//Motor B
int PWMB = 1; //Speed control
int BIN1 = 6; //Direction
int BIN2 = 5; //Direction

int Direction_left;
int PWM_left;
int Direction_right;
int PWM_right;

char Dir_left[40];
char Speed_left[40];
char Dir_right[40];
char Speed_right[40];

void setup(){
pinMode(STBY, OUTPUT);

pinMode(PWMA, OUTPUT);
pinMode(AIN1, OUTPUT);
pinMode(AIN2, OUTPUT);

pinMode(PWMB, OUTPUT);
pinMode(BIN1, OUTPUT);
pinMode(BIN2, OUTPUT);

// Subscribe to variables published by the remote control
Particle.subscribe("Dir_left", Dir_left_Handler, "25003a001147343438323536");
Particle.subscribe("Speed_left", Speed_left_Handler, "25003a001147343438323536");
Particle.subscribe("Dir_right", Dir_right_Handler, "25003a001147343438323536");
Particle.subscribe("Speed_right", Speed_right_Handler, "25003a001147343438323536");

Serial.begin(9600); //begin the serial monitor
  
}

void loop(){
    move(2, PWM_left, Direction_left);
    move(1, PWM_right, Direction_right);
    delay(50);
}

void Dir_left_Handler(const char *event, const char *Dir_left) {
	Serial.printlnf("event=%s data=%s", event, Dir_left);
    Direction_left = atoi(Dir_left);
}

void Speed_left_Handler(const char *event, const char *Speed_left) {
    Serial.printlnf("event=%s data=%s", event, Speed_left);
    PWM_left = atoi(Speed_left);
}

void Dir_right_Handler(const char *event, const char *Dir_right) {
    Serial.printlnf("event=%s data=%s", event, Dir_right);
    Direction_right = atoi(Dir_right);
}

void Speed_right_Handler(const char *event, const char *Speed_right) {
    Serial.printlnf("event=%s data=%s", event, Speed_right);
    PWM_right = atoi(Speed_right);
}

void stop(){
//enable standby
digitalWrite(STBY, LOW);
}

void move(int motor, int speed, int direction){
//Move specific motor at speed and direction
//motor: 0 for B 1 for A
//speed: 0 is off, and 255 is full speed
//direction: 0 clockwise, 1 counter-clockwise

digitalWrite(STBY, HIGH); //disable standby

boolean inPin1 = LOW;
boolean inPin2 = HIGH;

if(direction == 1){
inPin1 = HIGH;
inPin2 = LOW;
}

if(motor == 1){
digitalWrite(AIN1, inPin1);
digitalWrite(AIN2, inPin2);
analogWrite(PWMA, speed);
}else{
digitalWrite(BIN1, inPin1);
digitalWrite(BIN2, inPin2);
analogWrite(PWMB, speed);
}
}