#include <NewPing.h>

int ENA =10;     //MOTOR DERECHO
int IN1 = 9;
int IN2 = 8;

int ENB = 5;     //MOTOR IZQUIERDO
int IN3 = 7;
int IN4 = 6;


const int s1 = 11;    //SENSO INFRARROJO DERECHO
const int s2 = 12;      //SENSOR INFRARROJO IZQUIERDO
int sensor;
int sensor2;


int TRIG = 4;    //SENSOR ULTRASONICO
int ECHO = 2;
int MAX_DISTANCE = 60;

NewPing sonar(TRIG, ECHO, MAX_DISTANCE);

void setup(){ //SE PONEN LOS PINES COMO ENTRADA O SALIDA
  Serial.begin(9600);
  delay(4000);
  pinMode(ENA , OUTPUT);
  pinMode(ENB , OUTPUT);
  pinMode(IN1 , OUTPUT);
  pinMode(IN2 , OUTPUT);
  pinMode(IN3 , OUTPUT);
  pinMode(IN4 , OUTPUT);
  pinMode(s1 , INPUT);
  pinMode(s2 , INPUT);
  }

void loop (){
  sensor = digitalRead(s1);
  sensor2 = digitalRead(s2);
   delay (70);
int  distance = sonar.ping_cm();



Serial.println("SENSOR ULTRASONICO");
Serial.println(distance);
Serial.println("SENSOR INFRARROJO DERECHO");
Serial.println(sensor);
Serial.println("SENSOR INFRARROJO IZQUIERDO");
Serial.println(sensor2);

 
 if (distance > 40){

       digitalWrite(IN1 , LOW);    //MOTOR DERECHO
       digitalWrite(IN2 , HIGH);
       analogWrite(ENA , 100);

       digitalWrite(IN3 , HIGH);     //MOTOR IZQUIERDO
       digitalWrite(IN4 , LOW);
       analogWrite(ENB , 100);
}
else {}
if (distance < 40 ){
  

       digitalWrite(IN1 , HIGH );   //MOTOR DERECCHO
       digitalWrite(IN2 , LOW);
       analogWrite(ENA , 255);
       digitalWrite(IN3 , HIGH);   // MOTOR IZQUIERDO
       digitalWrite(IN4 , LOW);
       analogWrite(ENB , 255);
}
//SI LOS SENSORES INFRARROJOS DETECTAN LINEA BLANCA 




          if (digitalRead(s1)==0   &&  digitalRead(s2)==0){    
  
          analogWrite(ENA , 200 );
          analogWrite(ENB , 200);
          digitalWrite(IN1 , LOW);
          digitalWrite(IN2 , HIGH);
          digitalWrite(IN3 , LOW);
          digitalWrite(IN4 , HIGH);
              delay(200);
}
else {}
//SI UNO DE LOS SENSORES DETECTA LINEA BLANCA Y EL OTRO DETECTA LINEA NEGRA 




         if (digitalRead(s1)==1   && digitalRead(s2)==0){    
 
         analogWrite(ENA , 200 );
         analogWrite(ENB , 200);
         digitalWrite(IN1 , LOW);
         digitalWrite(IN2 , HIGH);
         digitalWrite(IN3 , LOW);
         digitalWrite(IN4 , HIGH);
             delay(200);
} 
else{}  
//SI UNO DE LOS SENSORES DETECTA LINEA NEGRA Y EL OTRO DETECTA LINEA BLANCA


         if (digitalRead(s1)==0   && digitalRead(s2)==1){   
   
         analogWrite(ENA , 200 );
         analogWrite(ENB , 200);
         digitalWrite(IN1 , LOW);
         digitalWrite(IN2 , HIGH);
         digitalWrite(IN3 , LOW);
         digitalWrite(IN4 , HIGH);
             delay(200);
}
}