#include <Wire.h>
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>                                      
#include <BlynkSimpleEsp8266.h>

char auth[] = "XVRdqdnfebdPpu4CpBBzk8D2G2wYZyh1";              //AUTHENTICATION TOKEN OF THE BLYNK APP

char ssid[] = "realme";                                        //WIFI SSID 
char pass[] = "9502586705";                                    //WIFI PASSWORD
int vehicleCount;
int totalSlots = 3;

int slot1 = D5;                                              //SLOT 1 IR SENSOR CONNECTED TO D5 OF NODEMCU
int slot2 = D6;                                              //SLOT 2 IR SENSOR CONNECTED TO D6 OF NODEMCU
int slot3 = D7;                                              //SLOT 3 IR SENSOR CONNECTED TO D7 OF NODEMCU


 //VIRTUAL PINS
WidgetLED slot_1(V3);                                     
WidgetLED slot_2(V4);
WidgetLED slot_3(V5);

void setup(){
   Blynk.begin(auth,ssid,pass);                            //TO START CONNECTION TO BLYNK 
   
   pinMode(slot1, INPUT);
   pinMode(slot2, INPUT);
   pinMode(slot3, INPUT); 

   Serial.begin (9600);
   Wire.begin(D2, D1);
}

void loop(){

  //* CONDITIONS TO DETECT CARS AT IR SENSORS *
   if(digitalRead(slot1)==LOW){
       slot_1.on();
   }
   if(digitalRead(slot2)==LOW){
       slot_2.on();
   }
   if(digitalRead(slot3)==LOW){
       slot_3.on();
   }
   if(digitalRead(slot1)==HIGH){
       vehicleCount--;
       slot_1.off();
   }
   if(digitalRead(slot2)==HIGH){
       slot_2.off();
   }
   if(digitalRead(slot3)==HIGH){
       slot_3.off();
   }
}
