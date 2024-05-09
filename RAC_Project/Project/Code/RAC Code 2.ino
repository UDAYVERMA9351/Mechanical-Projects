/*
 * Ultrasonic Simple
 * Prints the distance read by an ultrasonic sensor in
 * centimeters. They are supported to four pins ultrasound
 * sensors (liek HC-SC04) and three pins (like PING)))
 * and Seeed Studio sensors).
 *
 * The circuit:
 * * Module HR-SC04 (four pins) or PING))) (and other with
 *   three pins), attached to digital pins as follows:
 * ---------------------    --------------------
 * | HC-SC04 | Arduino |    | 3 pins | Arduino |
 * ---------------------    --------------------
 * |   Vcc   |   5V    |    |   Vcc  |   5V    |
 * |   Trig  |   12    | OR |   SIG  |   13    |
 * |   Echo  |   13    |    |   Gnd  |   GND   |
 * |   Gnd   |   GND   |    --------------------
 * ---------------------
 * Note: You do not obligatorily need to use the pins defined above
 * 
 * By default, the distance returned by the read()
 * method is in centimeters. To get the distance in inches,
 * pass INC as a parameter.
 * Example: ultrasonic.read(INC)
 *
 * created 3 Apr 2014
 * by Erick Simões (github: @ErickSimoes | twitter: @AloErickSimoes)
 * modified 23 Jan 2017
 * by Erick Simões (github: @ErickSimoes | twitter: @AloErickSimoes)
 * modified 03 Mar 2017
 * by Erick Simões (github: @ErickSimoes | twitter: @AloErickSimoes)
 * modified 11 Jun 2018
 * by Erick Simões (github: @ErickSimoes | twitter: @AloErickSimoes)
 *
 * This example code is released into the MIT License.
 */

#include <Ultrasonic.h>

/*
 * Pass as a parameter the trigger and echo pin, respectively,
 * or only the signal pin (for sensors 3 pins), like:
 * Ultrasonic ultrasonic(13);
 */
Ultrasonic ultrasonic(12, 13);
int distance;

int buzzer = 11;
int ac = 10;
int count=0;
char data;

void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(ac, OUTPUT);
}

void loop() {
  // Pass INC as a parameter to get the distance in inches
  distance = ultrasonic.read();
  // digitalWrite(ac, HIGH);
  if(distance>8)
  {
    count++;
  }
  else
  {
    count=0;
    digitalWrite(buzzer, LOW);
  }

  if(count>10)
  {
    digitalWrite(buzzer, HIGH);
  }
  else
  {
    digitalWrite(buzzer, LOW);
  }
  
  Serial.print("Distance in CM: ");
  Serial.println(distance);

    while(Serial.available() > 0)
  {
    data = Serial.read();
    Serial.println(data);
  
    if(data == 'A')
    {
      digitalWrite(ac, HIGH);
      // Serial.println("UDAY!!");
      // digitalWrite(ac, HIGH);
    }
    if(data == 'B')
    {
      digitalWrite(ac, LOW);
      // digitalWrite(ac, LOW);
    }
    if(data == 'C')
    {
      digitalWrite(buzzer, HIGH);
    }
    if(data == 'D')
    {
      digitalWrite(buzzer, LOW);
      count=0;
    }
    
  }
  delay(500);
}
