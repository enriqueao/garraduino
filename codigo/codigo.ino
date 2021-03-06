#include<Servo.h>
#include <Psx.h>                                      

//Definiciones de los pins del control PSX
#define dataPin 8
#define cmndPin 9
#define attPin 13
#define clockPin 10

//Definiendo cada servo dependiendo su funcion
Servo servoBase;
Servo servoIzq;
Servo servoDer;
Servo servoGarra;

//variable para girar el servo
int pos = 0;

//variables de estado de los servos
int base = 90;
int izq = 74;
int der = 0;
int posicionGarra = 25;

//Variables de los Led's
int ledIzq = 1;
int ledDer = 12;

//Variable del zumbador
int zum = 2;

Psx Psx;                                                 

unsigned int data = 0;                                 

void setup()
{
  Psx.setupPins(dataPin, cmndPin, attPin, clockPin, 10);
  
  servoBase.attach(5);
  servoIzq.attach(6);
  servoDer.attach(3);
  servoGarra.attach(11);
  
  Serial.begin(9600);
  
  servoBase.write(base);
  servoIzq.write(izq);
  servoDer.write(der);
  servoGarra.write(posicionGarra);

  pinMode(ledIzq, OUTPUT);
  pinMode(ledDer, OUTPUT);

  pinMode(zum, OUTPUT);
}

void loop()
{
  //Resetear Led's
  digitalWrite(ledIzq, LOW);
  digitalWrite(ledDer, LOW);

  //Apagar zumbador
  digitalWrite(zum,LOW);
  
  data = Psx.read();                                      

  if (data & psxR1){
    Serial.println("R1");
    posicionGarra--;
    if(posicionGarra < 1){
      posicionGarra = 1;
    }
    if(posicionGarra < 40 and posicionGarra <20){
      digitalWrite(zum, HIGH);
      delay(100);
      digitalWrite(zum, LOW);
    }
    if(posicionGarra < 20){
      digitalWrite(zum, HIGH);
      delay(50);
      digitalWrite(zum, LOW);
    }
    Serial.println(posicionGarra);
    servoGarra.write(posicionGarra);
    delay(20);
                                             
  }


  
  if (data & psxR2){
    Serial.println("R2");
    base--;
    if(base < 1){
      base = 1;
      digitalWrite(ledIzq, HIGH);
    }
    if(base < 50 and base > 250){
      digitalWrite(zum, HIGH);
      delay(100);
      digitalWrite(zum, LOW);
    }
    if(base < 25){
      digitalWrite(zum, HIGH);
      delay(50);
      digitalWrite(zum, LOW);
    }
    Serial.println(base);
    servoBase.write(base);
    delay(20);                           
  }


  
  if (data & psxL1){
    Serial.println("L1");
    posicionGarra++;
    if(posicionGarra > 64){
      posicionGarra = 63;
    }
    if(posicionGarra > 40 and posicionGarra <55){
      digitalWrite(zum, HIGH);
      delay(100);
      digitalWrite(zum, LOW);
    }
    if(posicionGarra > 55){
      digitalWrite(zum, HIGH);
      delay(50);
      digitalWrite(zum, LOW);
    }
    Serial.println(posicionGarra);
    servoGarra.write(posicionGarra);
    delay(20);
  }

  
  if (data & psxL2){
    Serial.println("L2");
    base++;
    if(base > 180){
      base = 180;
      digitalWrite(ledDer, HIGH);
    }
    if(base > 130 and base <160){
      digitalWrite(zum, HIGH);
      delay(100);
      digitalWrite(zum, LOW);
    }
    if(base > 160){
      digitalWrite(zum, HIGH);
      delay(50);
      digitalWrite(zum, LOW);
    }
    Serial.println(base);
    servoBase.write(base);
    delay(20);                           
  }


  
  if (data & psxO){
    Serial.println("Left");
    der--;
    if(der < 1){
      der = 1;
    }
    if(base < 40 and base > 20){
      digitalWrite(zum, HIGH);
      delay(100);
      digitalWrite(zum, LOW);
    }
    if(base < 20){
      digitalWrite(zum, HIGH);
      delay(50);
      digitalWrite(zum, LOW);
    }
    Serial.println(der);
    servoDer.write(der);
    delay(20);                           
  }


  
  if (data & psxSqu){
    Serial.println("Tri");
    der++;
    if(der > 90){
      der = 90;
    }
    if(base > 60 and base < 75){
      digitalWrite(zum, HIGH);
      delay(100);
      digitalWrite(zum, LOW);
    }
    if(base > 75){
      digitalWrite(zum, HIGH);
      delay(50);
      digitalWrite(zum, LOW);
    }
    Serial.println(der);
    servoDer.write(der);
    delay(20);                             
  }


  
  if (data & psxUp){
    Serial.println("UP");
    izq++;
     if(izq > 74){
      izq = 74;
    }
    if(base > 130 and base <160){
      digitalWrite(zum, HIGH);
      delay(100);
      digitalWrite(zum, LOW);
    }
    if(base > 160){
      digitalWrite(zum, HIGH);
      delay(50);
      digitalWrite(zum, LOW);
    }
    Serial.println(izq);
    servoIzq.write(izq);
    delay(20);                        
  }

  
  if (data & psxDown){
    Serial.println("Down");
    izq--;
    if(izq < 1){
      izq = 1;
    }
    if(base < 50 and base > 250){
      digitalWrite(zum, HIGH);
      delay(100);
      digitalWrite(zum, LOW);
    }
    if(base < 25){
      digitalWrite(zum, HIGH);
      delay(50);
      digitalWrite(zum, LOW);
    }
    Serial.println(izq);
    servoIzq.write(izq);
    delay(20);                             
  }
  delay(20);
}
