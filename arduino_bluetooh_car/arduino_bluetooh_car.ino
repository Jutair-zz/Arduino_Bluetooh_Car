/*Autor: Jutair Rios*/
/*Projeto de um carrinho controlado por bluetooh utilizando a porta serial*/
/*A project of a car controlled by bluetooh through serial port*/

#include <AFMotor.h>
AF_DCMotor motor1(1, MOTOR12_64KHZ);
AF_DCMotor motor2(2, MOTOR12_64KHZ);;
void setup() {
Serial.begin(9600); // set serial speed
motor1.setSpeed(255);
motor2.setSpeed(255);

}


void loop(){
while (Serial.available() == 0); // do nothing if nothing sent
int val = Serial.read() - '0'; // deduct ascii value of '0' to find numeric value of sent number

if (val == 1) { // 
Serial.println("Motor Frente");
drive_frente();
Serial.flush(); 
}
else if (val == 3)//
{
Serial.println("Para");
direita();
Serial.flush(); 
}
if (val == 2) { // 
Serial.println("Motor Volta");
drive_re();
Serial.flush(); 
}

if (val == 4) { //
Serial.println("Motor Volta");
esquerda();
Serial.flush(); 
}

if (val == 5) { //
Serial.println("Motor Volta");
drive_stop();
Serial.flush(); 
}
else // if not one of above command, do nothing
{
//val = val;
}
Serial.println(val);
Serial.flush(); // clear serial port
}
void drive_frente(){              //função drive_frente
  motor1.run(FORWARD);
  motor2.run(FORWARD);
}
void drive_re(){                  //função drive_re
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
}
void drive_stop(){                //função drive_stop
 motor1.run(RELEASE); 
 motor2.run(RELEASE); 
}

void direita(){
  motor1.run(RELEASE);
  motor2.run(FORWARD);
}
void esquerda(){
   motor1.run(FORWARD);
  motor2.run(RELEASE);
}
  
