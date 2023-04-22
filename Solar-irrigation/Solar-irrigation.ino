//#        Motor A  ->  Screw terminal close to E1 driver pin
// #        Motor B  ->  Screw terminal close to E2 driver pin
// #
// # Note: You should connect the GND pin from the DF-MD v1.3 to your MCU controller. They should share the GND pins.
// #

#include <avr/sleep.h>
#include <avr/power.h>
#include <avr/wdt.h>

int M1 = 3;
int flag_One=0;

void setup()
{
    pinMode(M1, OUTPUT);
    Serial.begin(9600);
    flag_One=0;
}

void loop()
{
  
  // put your main code here, to run repeatedly:
    if(flag_One==0)
    {
      int data_water=analogRead(A0);
      Serial.println(data_water);
      delay(1000);
      flag_One=1;
      
      if(data_water>500)
        {
        analogWrite(M1,255);
        delay(5000);
        analogWrite(M1,0);
        delay(1000);
        set_sleep_mode(SLEEP_MODE_PWR_DOWN);
        sleep_enable();
        sleep_mode(); //Entre dans le mode veille choisi
  //le micro passe en sommeil pour 8 secondes
         }
        else{}
    }

    else{}

}
