//--------------------------------------//
//HEADER FILES
//--------------------------------------//
#include<Servo.h>
//--------------------------------------//

//--------------------------------------//
//OBJECT CREATION
//--------------------------------------//
Servo servo1;               //BASE SERVO (Non-Continuous)
int servo1_pin=9;           //SET PIN NUMBER
Servo servo2;               //ONE AFTER BASE SERVO (Non-Continuous)
int servo2_pin=10;          //SET PIN NUMBER
Servo servo3;               //TOP-MOST SERVO (Non-Continuous)
int servo3_pin=11;          //SET PIN NUMBER
//--------------------------------------//

//--------------------------------------//
//TRACKERS
//--------------------------------------//
  //DATA TRACKERS
  int servo1_delay=0;
  int servo2_delay=0;
  int servo3_delay=0;
  String message;
  
  //DATA SETTERS (Forward Declarations)
  inline void move_servo1(int);
  inline void set_servo1(int);
  inline void move_servo2(int);
  inline void set_servo2(int);
  inline void move_servo3(int);
  inline void set_servo3(int);
  inline void set_servos(int, int, int);
  void type_character(char);

//--------------------------------------//

//--------------------------------------//
//CONSTANTS
//--------------------------------------//
const unsigned char SERVO_FORW=180;
const unsigned char SERVO_STOP=90;
const unsigned char SERVO_BACK=0;
const int MAX_DELAY=1000;
const int HALF_MAX_DELAY=500;
//--------------------------------------//


//--------------------------------------//
//BODY
//--------------------------------------//
void setup() {
  //SERVOS
  servo1.attach(servo1_pin);
  servo2.attach(servo2_pin);
  servo3.attach(servo3_pin);

  //BLUETOOTH
  Serial.begin(9600); //set baud rate
}

void loop() {
  while(Serial.available()) {
    message+=char(Serial.read());
  }
  if(!Serial.available()) {
    if(message!="") {
      for (int i=0; i<=message.length()-1; ++i) {
        Serial.print(message[i]);
        type_character(message[i]);
      }
      message="";
    }
  }
  delay(5000); //delay
}

//--------------------------------------//


//--------------------------------------//
//TRACKERS
//--------------------------------------//
  //ACTION PERFORMER
  void type_character(char input) {
    if ((input>=97 && input<=122)||(input==' ')||input=='.'||input==','||(input>=48 && input<=57)||input==13) {
      if (input>=97 && input<=122) {
        input-=32;
      }
    }
    else {
      input=' ';
    }


    //SET THE APPROPRIATE VALUES HERE
    if (input=='A') {
      set_servos(900, 900, 900);
    }
    else if (input=='B') {
      set_servos(900, 900, 900);
    }
    else if (input=='C') {
      set_servos(900, 900, 900);
    }
    else if (input=='D') {
      set_servos(900, 900, 900);
    }
    else if (input=='E') {
      set_servos(900, 900, 900);
    }
    else if (input=='F') {
      set_servos(900, 900, 900);
    }
    else if (input=='G') {
      set_servos(900, 900, 900);
    }
    else if (input=='H') {
      set_servos(900, 900, 900);
    }
    else if (input=='I') {
      set_servos(900, 900, 900);
    }
    else if (input=='J') {
      set_servos(900, 900, 900);
    }
    else if (input=='K') {
      set_servos(900, 900, 900);
    }
    else if (input=='L') {
          set_servos(900, 900, 900);
    }
    else if (input=='M') {
      set_servos(900, 900, 900);
    }
    else if (input=='N') {
      set_servos(900, 900, 900);
    }
    else if (input=='O') {
      set_servos(900, 900, 900);
    }
    else if (input=='P') {
      set_servos(900, 900, 900);
    }
    else if (input=='Q') {
      set_servos(900, 900, 900);
    }
    else if (input=='R') {
      set_servos(900, 900, 900);
    }
    else if (input=='S') {
      set_servos(900, 900, 900);
    }
    else if (input=='T') {
      set_servos(900, 900, 900);
    }
    else if (input=='U') {
      set_servos(900, 900, 900);
    }
    else if (input=='V') {
      set_servos(900, 900, 900);
    }
    else if (input=='W') {
      set_servos(900, 900, 900);
    }
    else if (input=='X') {
      set_servos(900, 900, 900);
    }
    else if (input=='Y') {
      set_servos(900, 900, 900);
    }
    else if (input=='Z') {
      set_servos(900, 900, 900);
    }
    else if (input=='1') {
      set_servos(900, 900, 900);
    }
    else if (input=='2') {
      set_servos(900, 900, 900);
    }
    else if (input=='3') {
      set_servos(900, 900, 900);
    }
    else if (input=='4') {
      set_servos(900, 900, 900);
    }
    else if (input=='5') {
      set_servos(900, 900, 900);
    }
    else if (input=='6') {
      set_servos(900, 900, 900);
    }
    else if (input=='7') {
      set_servos(900, 900, 900);
    }
    else if (input=='8') {
      set_servos(900, 900, 900);
    }
    else if (input=='9') {
      set_servos(900, 900, 900);
    }
    else if (input=='0') {
      set_servos(900, 900, 900);
    }
    else if (input=='.') {
      set_servos(900, 900, 900);
    }
    else if (input==',') {
      set_servos(900, 900, 900);
    }
    else if (input==' ') {
      set_servos(900, 900, 900);
    }
    else if (input==13) { //THIS IS THE 'ENTER' KEY
      set_servos(900, 900, 900);
    }
  }

  //DATA SETTERS
  inline void move_servo1(int input) {
    if (input>=0) {
      if (input>(MAX_DELAY-servo1_delay)) {
        int future_delay=input-(MAX_DELAY-servo1_delay);
        servo1.write(((input>=0)?(SERVO_FORW):(SERVO_BACK)));
        delay(((future_delay-servo1_delay)>=0)?(future_delay-servo1_delay):(servo1_delay-future_delay));
        servo1.write(SERVO_STOP);
        servo1_delay=future_delay;
      }
      else {
        int future_delay=servo1_delay+input;
        servo1.write(((input>=0)?(SERVO_FORW):(SERVO_BACK)));
        delay(((future_delay-servo1_delay)>=0)?(future_delay-servo1_delay):(servo1_delay-future_delay));
        servo1.write(SERVO_STOP);
        servo1_delay=future_delay;
      }
    }
    else {
      if ((-input)>(servo1_delay)) {
        int future_delay=MAX_DELAY+input+servo1_delay;
        servo1.write(((input>=0)?(SERVO_FORW):(SERVO_BACK)));
        delay(((future_delay-servo1_delay)>=0)?(future_delay-servo1_delay):(servo1_delay-future_delay));
        servo1.write(SERVO_STOP);
        servo1_delay=future_delay;
      }
      else {
        int future_delay=servo1_delay+input;
        servo1.write(((input>=0)?(SERVO_FORW):(SERVO_BACK)));
        delay(((future_delay-servo1_delay)>=0)?(future_delay-servo1_delay):(servo1_delay-future_delay));
        servo1.write(SERVO_STOP);
        servo1_delay=future_delay;
      }
    }
  }
  inline void move_servo2(int input) {
    if (input>=0) {
      if (input>(MAX_DELAY-servo2_delay)) {
        int future_delay=input-(MAX_DELAY-servo2_delay);
        servo2.write(((input>=0)?(SERVO_FORW):(SERVO_BACK)));
        delay(((future_delay-servo2_delay)>=0)?(future_delay-servo2_delay):(servo2_delay-future_delay));
        servo2.write(SERVO_STOP);
        servo2_delay=future_delay;
      }
      else {
        int future_delay=servo2_delay+input;
        servo2.write(((input>=0)?(SERVO_FORW):(SERVO_BACK)));
        delay(((future_delay-servo2_delay)>=0)?(future_delay-servo2_delay):(servo2_delay-future_delay));
        servo2.write(SERVO_STOP);
        servo2_delay=future_delay;
      }
    }
    else {
      if ((-input)>(servo2_delay)) {
        int future_delay=MAX_DELAY+input+servo2_delay;
        servo2.write(((input>=0)?(SERVO_FORW):(SERVO_BACK)));
        delay(((future_delay-servo2_delay)>=0)?(future_delay-servo2_delay):(servo2_delay-future_delay));
        servo2.write(SERVO_STOP);
        servo2_delay=future_delay;
      }
      else {
        int future_delay=servo2_delay+input;
        servo2.write(((input>=0)?(SERVO_FORW):(SERVO_BACK)));
        delay(((future_delay-servo2_delay)>=0)?(future_delay-servo2_delay):(servo2_delay-future_delay));
        servo2.write(SERVO_STOP);
        servo2_delay=future_delay;
      }
    }
  }
  inline void move_servo3(int input) {
    if (input>=0) {
      if (input>(MAX_DELAY-servo3_delay)) {
        int future_delay=input-(MAX_DELAY-servo3_delay);
        servo3.write(((input>=0)?(SERVO_FORW):(SERVO_BACK)));
        delay(((future_delay-servo3_delay)>=0)?(future_delay-servo3_delay):(servo3_delay-future_delay));
        servo3.write(SERVO_STOP);
        servo3_delay=future_delay;
      }
      else {
        int future_delay=servo3_delay+input;
        servo3.write(((input>=0)?(SERVO_FORW):(SERVO_BACK)));
        delay(((future_delay-servo3_delay)>=0)?(future_delay-servo3_delay):(servo3_delay-future_delay));
        servo3.write(SERVO_STOP);
        servo3_delay=future_delay;
      }
    }
    else {
      if ((-input)>(servo1_delay)) {
        int future_delay=MAX_DELAY+input+servo3_delay;
        servo3.write(((input>=0)?(SERVO_FORW):(SERVO_BACK)));
        delay(((future_delay-servo3_delay)>=0)?(future_delay-servo3_delay):(servo3_delay-future_delay));
        servo3.write(SERVO_STOP);
        servo3_delay=future_delay;
      }
      else {
        int future_delay=servo3_delay+input;
        servo3.write(((input>=0)?(SERVO_FORW):(SERVO_BACK)));
        delay(((future_delay-servo3_delay)>=0)?(future_delay-servo3_delay):(servo3_delay-future_delay));
        servo3.write(SERVO_STOP);
        servo3_delay=future_delay;
      }
    }
  }
  inline void set_servo1(int input) {
    if (input<0 || input>MAX_DELAY) {
      if (input<0) {
        input=input%(-MAX_DELAY);
        input=MAX_DELAY+input;
      }
      else {
        input=input%MAX_DELAY;
      }
    }

    int difference=servo1_delay-input;
    
    if (difference>=0) {
      if (difference>=HALF_MAX_DELAY && difference<=MAX_DELAY) {
        move_servo1(MAX_DELAY-difference);
      }
      else if (difference>=0 && difference<=HALF_MAX_DELAY) {
        move_servo1(-difference);
      }
    }
    else {
      difference=-difference;
      if (difference>=HALF_MAX_DELAY && difference<=MAX_DELAY) {
        move_servo1(difference-MAX_DELAY);
      }
      else if (difference>=0 && difference<=HALF_MAX_DELAY) {
        move_servo1(difference);
      }
    }
  }
  inline void set_servo2(int input) {
    if (input<0 || input>MAX_DELAY) {
      if (input<0) {
        input=input%(-MAX_DELAY);
        input=MAX_DELAY+input;
      }
      else {
        input=input%MAX_DELAY;
      }
    }

    int difference=servo2_delay-input;
    
    if (difference>=0) {
      if (difference>=HALF_MAX_DELAY && difference<=MAX_DELAY) {
        move_servo2(MAX_DELAY-difference);
      }
      else if (difference>=0 && difference<=HALF_MAX_DELAY) {
        move_servo2(-difference);
      }
    }
    else {
      difference=-difference;
      if (difference>=HALF_MAX_DELAY && difference<=MAX_DELAY) {
        move_servo2(difference-MAX_DELAY);
      }
      else if (difference>=0 && difference<=HALF_MAX_DELAY) {
        move_servo2(difference);
      }
    }
  }
  inline void set_servo3(int input) {
    if (input<0 || input>MAX_DELAY) {
      if (input<0) {
        input=input%(-MAX_DELAY);
        input=MAX_DELAY+input;
      }
      else {
        input=input%MAX_DELAY;
      }
    }

    int difference=servo3_delay-input;
    
    if (difference>=0) {
      if (difference>=HALF_MAX_DELAY && difference<=MAX_DELAY) {
        move_servo3(MAX_DELAY-difference);
      }
      else if (difference>=0 && difference<=HALF_MAX_DELAY) {
        move_servo3(-difference);
      }
    }
    else {
      difference=-difference;
      if (difference>=HALF_MAX_DELAY && difference<=MAX_DELAY) {
        move_servo3(difference-MAX_DELAY);
      }
      else if (difference>=0 && difference<=HALF_MAX_DELAY) {
        move_servo3(difference);
      }
    }
  }
inline void set_servos(int input1, int input2, int input3) {
    //RESETTING SERVOS
    servo2.write(SERVO_BACK);
    delay(servo2_delay);
    servo2.write(SERVO_STOP);
    servo2_delay=0;
    
    servo1.write(SERVO_BACK);
    delay(servo1_delay);
    servo1.write(SERVO_STOP);
    servo1_delay=0;
    
    servo3.write(SERVO_BACK);
    delay(servo3_delay);
    servo3.write(SERVO_STOP);
    servo3_delay=0;
  
    //COMPLETION OF OPERATION IN 3 STAGES
    set_servo1(input1);
    set_servo2(input2);
    set_servo3(input3);  
  }
//--------------------------------------//
