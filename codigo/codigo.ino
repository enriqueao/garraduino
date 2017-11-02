#include<Servo.h>

//Definiendo cada servo dependiendo su funcion
Servo servoBase;
Servo servoIzq;
Servo servoDer;
Servo servoGarra;

//variable para girar el servo
int pos = 0;

//Variable para llamar al servo que se va a girar(Bluetooth)
int ins = 3;

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
}

void loop()
{
//Switch para seleccionar el servo que va a funcionar
  switch(ins){
    case 0:
      girarBase(50);
      Serial.print("Girando Base \n");
      //delay(1000);
      //regresar();
      break;
    case 1:
      girarIzq(50);
      Serial.print("Girando Izquierdo \n");
      //delay(1000);
      //regresar();
      break;
    case 2:
      girarDer(50);
      Serial.print("Girando Derecho \n");
      //delay(1000);
      //regresar();
      break;
    case 3:
      girarGarra(50);
      Serial.print("Girando Garra \n");
      //delay(1000);
      //regresar();
      break;
    case 4:
      regresar();
      break;
    default:
      Serial.print("Error \n");
  }
  Serial.print("Esperando... \n");
  delay(1000);
}

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
