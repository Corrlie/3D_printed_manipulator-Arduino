#include <Servo.h>

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

int Srv_Pos_BaseLow = 90;
int Srv_Pos_BaseAbove = 130;
int Srv_Pos_Arm1 = 100;
int Srv_Pos_Arm2 = 90;
int Srv_Pos_Grip = 90;

int input_BT;
int axis = 0;

void setup() {
  ////////////////////Servo////////////////////
  Srv_BaseLow.attach(Srv_1);
  Srv_BaseAbove.attach(Srv_2);
  Srv_Arm1.attach(Srv_3);
  Srv_Arm2.attach(Srv_4);
  Srv_Grip.attach(Srv_5);
  ////////////////////BT////////////////////
  Serial.begin(9600);

  ////////////////////Initial posistions////////////////////
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
    if (input_BT == 79) { //baseUp
      axis = 1;
    }
    else if (input_BT == 65) { //baseAboveUp
      axis = 2;
    }
    else if (input_BT == 67) { //arm1Up
      axis = 3;
    }
    else if (input_BT == 68) { //arm2Up
      axis = 4;
    }
    else if (input_BT == 69) { //gripUp
      axis = 5;
    }
    else if (input_BT == 71) { //baseDown
      axis = 6;
    }
    else if (input_BT == 72) { //baseAboveDown
      axis = 7;
    }
    else if (input_BT == 73) { //arm1Down
      axis = 8;
    }
    else if (input_BT == 74) { //arm2Down
      axis = 9;
    }
    else if (input_BT == 75) { //gripDown
      axis = 10;
    }
    else if (input_BT == 66) {
      axis = 11;
    }
  }
  switch (axis) {
    case 1:
      moveServoUp_BaseLow();
      break;
    case 2:
      moveServoUp_BaseAbove();
      break;
    case 3:
      moveServoUp_Arm1();
      break;
    case 4:
      moveServoUp_Arm2();
      break;
    case 5:
      moveServoUp_Grip();
      break;
    case 6:
      moveServoDown_BaseLow();
      break;
    case 7:
      moveServoDown_BaseAbove();
      break;
    case 8:
      moveServoDown_Arm1();
      break;
    case 9:
      moveServoDown_Arm2();
      break;
    case 10:
      moveServoDown_Grip();
      break;
    case 11:

      break;

  }

}

void moveServoUp_BaseLow() {
  if (Srv_Pos_BaseLow < 160) {
    Srv_Pos_BaseLow += 1;
    Srv_BaseLow.write(Srv_Pos_BaseLow);
    delay(50);
  }
  else {
    Srv_Pos_BaseLow = 160;
    Srv_BaseLow.write(Srv_Pos_BaseLow);
    delay(50);
  }
}
void moveServoUp_BaseAbove() {

  if (Srv_Pos_BaseAbove < 160) {
    Srv_Pos_BaseAbove += 1;
    Srv_BaseAbove.write(Srv_Pos_BaseAbove);
    delay(50);
  }
  else {
    Srv_Pos_BaseAbove = 160;
    Srv_BaseAbove.write(Srv_Pos_BaseAbove);
    delay(50);
  }


}
void moveServoUp_Arm1() {
  if (Srv_Pos_Arm1 < 160) {
    Srv_Pos_Arm1 += 1;
    Srv_Arm1.write(Srv_Pos_Arm1);
    delay(50);
  }
  else {
    Srv_Pos_Arm1 = 160;
    Srv_Arm1.write(Srv_Pos_Arm1);
    delay(50);
  }
}
void moveServoUp_Arm2() {
  if (Srv_Pos_Arm2 < 160) {
    Srv_Pos_Arm2 += 1;
    Srv_Arm2.write(Srv_Pos_Arm2);
    delay(50);
  }
  else {
    Srv_Pos_Arm2 = 160;
    Srv_Arm2.write(Srv_Pos_Arm2);
    delay(50);
  }
}
void moveServoUp_Grip() {
  if (Srv_Pos_Grip < 160) {
    Srv_Pos_Grip += 1;
    Srv_Grip.write(Srv_Pos_Grip);
    delay(50);
  }
  else {
    Srv_Pos_Grip = 160;
    Srv_Grip.write(Srv_Pos_Grip);
    delay(50);
  }
}

void moveServoDown_BaseLow() {
  if (Srv_Pos_BaseLow > 20) {
    Srv_Pos_BaseLow -= 1;
    Srv_BaseLow.write(Srv_Pos_BaseLow);
    delay(50);
  }
  else {
    Srv_Pos_BaseLow = 20;
    Srv_BaseLow.write(Srv_Pos_BaseLow);
    delay(50);
  }
}
void moveServoDown_BaseAbove() {
  if (Srv_Pos_BaseAbove > 20) {
    Srv_Pos_BaseAbove -= 1;
    Srv_BaseAbove.write(Srv_Pos_BaseAbove);
    delay(50);
  }
  else {
    Srv_Pos_BaseAbove = 20;
    Srv_BaseAbove.write(Srv_Pos_BaseAbove);
    delay(50);
  }
}
void moveServoDown_Arm1() {
  if (Srv_Pos_Arm1 > 20) {
    Srv_Pos_Arm1 -= 1;
    Srv_Arm1.write(Srv_Pos_Arm1);
    delay(50);
  }
  else {
    Srv_Pos_Arm1 = 20;
    Srv_Arm1.write(Srv_Pos_Arm1);
    delay(50);
  }
}
void moveServoDown_Arm2() {
  if (Srv_Pos_Arm2 > 20) {
    Srv_Pos_Arm2 -= 1;
    Srv_Arm2.write(Srv_Pos_Arm2);
    delay(50);
  }
  else {
    Srv_Pos_Arm2 = 20;
    Srv_Arm2.write(Srv_Pos_Arm2);
    delay(50);
  }
}
void moveServoDown_Grip() {
  if (Srv_Pos_Grip > 20) {
    Srv_Pos_Grip -= 1;
    Srv_Grip.write(Srv_Pos_Grip);
    delay(50);
  }
  else {
    Srv_Pos_Grip = 20;
    Srv_Grip.write(Srv_Pos_Grip);
    delay(50);
  }
}
