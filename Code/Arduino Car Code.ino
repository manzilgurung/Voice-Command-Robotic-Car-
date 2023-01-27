#include <SoftwareSerial.h>
#define trigPin 8
#define echoPin 9
SoftwareSerial BT(0,1);
String readvoice;

void setup()
{
    BT.begin(9600);
    Serial.begin(9600);
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);   
}
 
 void loop() 
 {
    long duration, distance;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) / 29.;

    if(distance < 50)
    {
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      delay(100);
    }
    else
    {
      while (BT.available())
      { 
          delay(10);  
          char c= BT.read(); 
          readvoice += c; 
      }
      if (readvoice.length() > 0)
      {
         Serial.println(readvoice);
      
      if(readvoice =="*forward#")
      {
          digitalWrite(2, LOW);
          digitalWrite(3, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(5, HIGH);
          delay(500);
      }
      else if (readvoice == "*back#")
      {
          digitalWrite(2, HIGH);
          digitalWrite(3, LOW);
          digitalWrite(4, HIGH);
          digitalWrite(5, LOW);
          delay(500);
      }
      else if (readvoice == "*left#")
      {
          digitalWrite(2, LOW);
          digitalWrite(3, LOW);
          digitalWrite(4, LOW);
          digitalWrite(5, HIGH);
          delay(1500);
      }
      else if (readvoice == "*right#")
      {
          digitalWrite(2, LOW);
          digitalWrite(3, HIGH);
          digitalWrite(4, HIGH);
          digitalWrite(5, HIGH);
          delay(1500);
      }
      else if (readvoice == "*forward left#")
      {
          digitalWrite (2, LOW);
          digitalWrite (3, LOW);
          digitalWrite (4, LOW);
          digitalWrite (5, HIGH);
          delay (1500);
          
          digitalWrite(2, LOW);
          digitalWrite(3, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(5, HIGH);
          delay(100);
       }
       else if ( readvoice == "*forward right#")
       { 
          digitalWrite (2, LOW);
          digitalWrite (3, HIGH);
          digitalWrite (4, HIGH);
          digitalWrite (5, HIGH);
          delay (1500);
              
          digitalWrite(2, LOW);
          digitalWrite(3, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(5, HIGH);
          delay(100); 
        }
        else if (readvoice == "*stop#") 
        {
           digitalWrite(2, LOW);
           digitalWrite(3, LOW);
           digitalWrite(4, LOW);
           digitalWrite(5, LOW);
           delay(100); 
        }
        else if ( readvoice == "*back right#")
       { 
          digitalWrite (2, LOW);
          digitalWrite (3, HIGH);
          digitalWrite (4, HIGH);
          digitalWrite (5, HIGH);
          delay (1500);
              
          digitalWrite(2, HIGH);
          digitalWrite(3, LOW);
          digitalWrite(4, HIGH);
          digitalWrite(5, LOW);
          delay(100); 
        }
        else if ( readvoice == "*back left#")
       { 
          digitalWrite (2, LOW);
          digitalWrite (3, LOW);
          digitalWrite (4, LOW);
          digitalWrite (5, HIGH);
          delay (1500);
              
          digitalWrite(2, HIGH);
          digitalWrite(3, LOW);
          digitalWrite(4, HIGH);
          digitalWrite(5, LOW);
          delay(100); 
        }
        readvoice=""; 
        }
          }
 }
