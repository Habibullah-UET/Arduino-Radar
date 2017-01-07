# Arduino-Radar
A sample Arduino Radar Project

# Parts Required
<ul>
<li> 1 x Ardunio (UNO or Mega) </li>
<li> 1 x HR-SR04 <li/>
<li> 1 x Servo Motor ( Tower Pro Microservo 9g ) SG90 <li/>
<li> 1 x Buzzer <li/>
<li> 1 x LED RGB <li/>
<li> 1 x LCD </li>
</ul>

# How to Connect LCD
Connect: Arduino 5v (pin 3) > plus column on breadboard
Connect: Arduino GND (pin 4 or 5) > min column on breadboard
Connect: GND row (min) on breadboard > pin 1 on LCD (VSS)
Connect: +5v row (plus) on breadboard > pin 2 on LCD (VDD)
Connect: +5v row (plus) on breadboard > pin 15 on LCD (A)
Connect: GND row (min) on breadboard > pin 16 on LCD (K)
Connect: first pin of the potmeter > GND of the breadboard
Connect: middle pin of the potmeter > pin 3 of the LCD display (VO
Connect: pin 4 of the LCD display (RS) > pin 7 of the Arduino (digital out, PWM, yellow wire) 
Connect: pin 5 of the LCD display (RW) > GND row of the breadboard (black wire)

Connect: pin 6 of the LCD display (E) > pin 8 of the Arduino (PWM)
Connect: pin 11 of the LCD display (D4) > pin 9 of the Arduino (PWM)
Connect: pin 12 of the LCD display (D5) > pin 10 of the Arduino (PWM)
Connect: pin 13 of the LCD display (D6) > pin 11 of the Arduino (PWM)
Connect: pin 14 of the LCD display (D7) > pin 12 of the Arduino (PWM)
LiquidCrystal lcd(7, 8, 9, 10, 11 , 12);
LiquidCrystal lcd(RS, E,D4, D5, D6 , D7);
# RGB LED 
![RGB LED](http://funkyimg.com/i/2n7gJ.png)
# ATMega328 
![ATMega328](http://funkyimg.com/i/2n7gH.png)
# Servo Motor 
![Servo Motor](http://funkyimg.com/view/2n7gK)

