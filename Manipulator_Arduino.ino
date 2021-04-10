#include <Servo.h>

// defined arduino pins
#define Srv_1 3
#define Srv_2 5
#define Srv_3 6
#define Srv_4 9
#define Srv_5 10

Servo Srv_BaseLow;
Servo Srv_BaseAbove;
Servo Srv_Arm1;
Servo Srv_Arm2;
Servo Srv_Grip;

// initial positions for all servomechanisms
int Srv_Pos_BaseLow = 90;
int Srv_Pos_BaseAbove = 130;
int Srv_Pos_Arm1 = 100;
int Srv_Pos_Arm2 = 90;
int Srv_Pos_Grip = 90;

char input_BT;
int axis = 0;

// two functions to move servos: 1) up; 2) down
// 160 is software upper position limit and 20 is lower software position limit for servomechanism  
void moveServoUp(Servo Srv_chosen, int* Srv_pos){
  if(*Srv_pos<160){
    *Srv_pos += 1;
    Srv_chosen.write(*Srv_pos);
    delay(50);
  }
  else { // softwarte upper limit for servo
    *Srv_pos = 160;
    Srv_chosen.write(*Srv_pos);
    delay(50);
  }
}

void moveServoDown(Servo Srv_chosen, int* Srv_pos){
  if(*Srv_pos>20){
    *Srv_pos -= 1;
    Srv_chosen.write(*Srv_pos);
    delay(50);
  }
  else { // software lowwer limit for servo
    *Srv_pos = 20;
    Srv_chosen.write(*Srv_pos);
    delay(50);
  }
}

void setup() {
  // Servo
  Srv_BaseLow.attach(Srv_1);
  Srv_BaseAbove.attach(Srv_2);
  Srv_Arm1.attach(Srv_3);
  Srv_Arm2.attach(Srv_4);
  Srv_Grip.attach(Srv_5);
  
  // BT
  Serial.begin(9600);

  // Initial posistions
  Srv_BaseLow.write(Srv_Pos_BaseLow);
  Srv_BaseAbove.write(Srv_Pos_BaseAbove);
  Srv_Arm1.write(Srv_Pos_Arm1);
  Srv_Arm2.write(Srv_Pos_Arm2);
  Srv_Grip.write(Srv_Pos_Grip);
}

void loop() {
  if (Serial.available() > 0)
  {
    input_BT = Serial.read();
    if (input_BT == 'O') { //baseUp
      axis = 1;
    }
    else if (input_BT == 'A') { //baseAboveUp
      axis = 2;
    }
    else if (input_BT == 'C') { //arm1Up
      axis = 3;
    }
    else if (input_BT == 'D') { //arm2Up
      axis = 4;
    }
    else if (input_BT == 'E') { //gripUp
      axis = 5;
    }
    else if (input_BT == 'G') { //baseDown
      axis = 6;
    }
    else if (input_BT == 'H') { //baseAboveDown
      axis = 7;
    }
    else if (input_BT == 'I') { //arm1Down
      axis = 8;
    }
    else if (input_BT == 'J') { //arm2Down
      axis = 9;
    }
    else if (input_BT == 'K') { //gripDown
      axis = 10;
    }
    else if (input_BT == 'B') {
      axis = 11;
    }
  }
  
  switch (axis) {
    case 1:
      moveServoUp(Srv_BaseLow, &Srv_Pos_BaseLow);
      break;
    case 2:
      moveServoUp(Srv_BaseAbove, &Srv_Pos_BaseAbove);
      break;
    case 3:
      moveServoUp(Srv_Arm1, &Srv_Pos_Arm1);
      break;
    case 4:
      moveServoUp(Srv_Arm2, &Srv_Pos_Arm2);
      break;
    case 5:
      moveServoUp(Srv_Grip, &Srv_Pos_Grip);
      break;
    case 6:
      moveServoDown(Srv_BaseLow, &Srv_Pos_BaseLow);
      break;
    case 7:
      moveServoDown(Srv_BaseAbove, &Srv_Pos_BaseAbove);
      break;
    case 8:
      moveServoDown(Srv_Arm1, &Srv_Pos_Arm1);
      break;
    case 9:
      moveServoDown(Srv_Arm2, &Srv_Pos_Arm2);
      break;
    case 10:
      moveServoDown(Srv_Grip, &Srv_Pos_Grip);
      break;
    case 11:
      break;
  }
}
