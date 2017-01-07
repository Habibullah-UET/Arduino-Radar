/* 

(C) HABIBULLAH , UET Peshawar.

A program that runs a Servo Motor on which a Ultrasonic sensor is attached, 
which reads distance.
If nothing is detected whithin its range,  Blue LED Blinks.
When it Detects an obsticle a Buzzer is played and Red LED  Blinks.

At the same time a LCD display the distance within which the obsticle is and display 
the messgae "Something Went Wrong" .
if there is no obsticle the LCD simply display the message "Everything is OK"

*/
#include <LiquidCrystal.h>
#include <Servo.h> 
#define TRIG 2
#define ECHO 3
#define PIEZO 4
long int HRSR04(int,int);
class Sweeper
{
  Servo servo;              // the servo
  int pos;              // current servo position 
  int increment;        // increment to move for each interval
  int  updateInterval;      // interval between updates
  unsigned long lastUpdate; // last update of position

public: 
  Sweeper(int interval)
  {
    updateInterval = interval;
    increment = 1;
  }
  
  void Attach(int pin)
  {
    servo.attach(pin);
  }
  
  void Detach()
  {
    servo.detach();
  }
  
  void Update()
  {
    if((millis() - lastUpdate) > updateInterval)  // time to update
    {
      lastUpdate = millis();
      pos += increment;
      servo.write(pos);
      Serial.println(pos);
      if ((pos >= 180) || (pos <= 0)) // end of sweep
      {
        // reverse direction
        increment = -increment;
      }
    }
  }
};

// LiquidCrystal lcd(RS, E,D4, D5, D6 , D7);
LiquidCrystal lcd(13, 12, 11, 10, 9, 8); 
Sweeper RADAR_SERVO(0);
const int red=6;
const int blue=7;
int Obsticle_Distance=0;
void setup() 
{ 
  Serial.begin(9600);
  lcd.begin(16, 2);
  RADAR_SERVO.Attach(5);
  pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);
  pinMode(red,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(PIEZO,OUTPUT);
 lcd.print("");

} 
 
void loop() 
{ 
  Obsticle_Distance = HRSR04(TRIG,ECHO);
  RADAR_SERVO.Update();
  if (Obsticle_Distance <= 50 )
    {
      digitalWrite(red,LOW);
      digitalWrite(blue,HIGH);
      digitalWrite(PIEZO,HIGH);
      lcd.print(Obsticle_Distance);
      lcd.print("cm ");
      delay(2000);
      lcd.clear();

    }
    else
    {
      digitalWrite(red,HIGH);
      digitalWrite(blue,LOW);
      digitalWrite(PIEZO,LOW); // Means OFF actually
      //lcd.print("Everything is OK");
    }
          
}

long HRSR04(int which_T,int which_E)
{
   long duration, distance;
  digitalWrite(which_T, LOW);
  delayMicroseconds(2); 
  digitalWrite(which_T, HIGH);
  delayMicroseconds(10);
  digitalWrite(which_T, LOW);
  duration = pulseIn(which_E, HIGH);
  // distance = duration*343*100/2;
  distance = (duration/2) / 29.1;
 /* if (distance < 4) {  
    digitalWrite(red,HIGH);
  digitalWrite(blue,LOW);
}
  else {
    digitalWrite(red,LOW);
    digitalWrite(blue,HIGH);
  }
  */
  if (distance >= 400 || distance <= 0){
    Serial.println("Out of Range!!!");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }
 // delay(200); 
  return distance;
}

