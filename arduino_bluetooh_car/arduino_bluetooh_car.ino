/*Autor: Jutair Rios*/
/*Projeto de um carrinho controlado por bluetooh utilizando a porta serial*/
/*A project of a car controlled by bluetooh through serial port*/

#include <AFMotor.h>
AF_DCMotor motor1(1, MOTOR12_64KHZ);
AF_DCMotor motor2(2, MOTOR12_64KHZ);;
void setup() {
Serial.begin(9600); // set serial speed
motor1.setSpeed(255); //Set motor1 speed
motor2.setSpeed(255); //Set motor1 speed

}


void loop(){
while (Serial.available() == 0); // Do nothing if nothing sent
int val = Serial.read() - '0'; // Deduct ascii value of '0' to find numeric value of sent number

if (val == 1) { // 
Serial.println("Motor forward");
drive_forward(); //Call forward function
Serial.flush(); 
}
else if (val == 3)//
{
Serial.println("Motor Right!");
right(); //Call right function
Serial.flush(); 
}
if (val == 2) { // 
Serial.println("Motor backward");
drive_backward(); //Call backward function
Serial.flush(); 
}

if (val == 4) { //
Serial.println("Motor left");
left(); //Call right function
Serial.flush(); 
}

if (val == 5) { //
Serial.println("Motor stop!");
drive_stop(); //Call stop function
Serial.flush(); 
}
else // if not one of above command, do nothing
{
//val = val;
}
Serial.println(val);
Serial.flush(); // clear serial port
}
void drive_forward(){              //Motor forward function
  motor1.run(FORWARD);
  motor2.run(FORWARD);
}
void drive_backward(){                  //Motor backward function
  motor2.run(BACKWARD);
}
void drive_stop(){                //Motor stop function
 motor1.run(RELEASE); 
 motor2.run(RELEASE); 
}

void right(){ 			//Motor right function
  motor1.run(RELEASE);
  motor2.run(FORWARD);
}
void left(){			//Motor left function
   motor1.run(FORWARD);
  motor2.run(RELEASE);
}
  
