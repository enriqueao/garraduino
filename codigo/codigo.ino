#include<Servo.h>

//Definiendo cada servo dependiendo su funcion
Servo servoBase;
Servo servoIzq;
Servo servoDer;
Servo servoGarra;

//variable para girar el servo
int pos = 0;

//variables de estado de los servos
int base = 0;
int garra = 0;
int alturaGarra = 0;
int posicionGarra = 0;

//Variable para llamar al servo que se va a girar(Bluetooth)
int ins = 3;

///request of serial

char req = "";

void setup()
{
  servoBase.attach(0);
  servoIzq.attach(1);
  servoDer.attach(2);
  servoGarra.attach(3);
  
  Serial.begin(9600);
  
  servoBase.write(90);
  servoIzq.write(0);
  servoDer.write(0);
  servoGarra.write(0);

  while (!Serial) {
    // wait for serial port to connect. Needed for native USB port only
  }

}

void loop()
{
  while (Serial.available() > 0) {
    req = Serial.read();
    
    if (req = "C") {
      switch(){
        case "U":
        break;

        case "D";
        break;

        case "L":
        break;

        case "R":
        break;

        default:
        
        break;
      }
    }
    
    if (req = "B") {
      int gi = req.toInt();
      girarBase(int gi);
    }

    if (req = "P") {
      int gi = req.toInt();
      girarGarra(int gi);
    }
  }

  if(Serial.available() < 0){
    regresar()
  }
}
/************************************************************************************/
//Funcion para girar la base de la garra
void girarBase(int pos){
  servoBase.write(pos);
}

//Funcion para girar el servo del lado izquierdo
void girarIzq(int pos){
  servoIzq.write(pos);
}

//Funcion para girar el servo de la derecha
void girarDer(int pos){
  servoDer.write(pos);
}

//Funcion para girar el servo que controla la garra
void girarGarra(int pos){
  servoGarra.write(pos);
}

//Funcion para regresar todos los servos a la posicion 0
void regresar(){
  servoBase.write(90);
  servoIzq.write(0);
  servoDer.write(0);
  servoGarra.write(0);
}
