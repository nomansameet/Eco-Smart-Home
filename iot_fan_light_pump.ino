#define BLYNK_TEMPLATE_ID "TMPL3ZrKIrjcW"
#define BLYNK_TEMPLATE_NAME "IOT"
#define BLYNK_AUTH_TOKEN "z6LP69-CaOe84B5fH2kc3HpXgAsOpKCA"
//Email-same26378@gmail.com
//Password-aersen@123
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include "DHT.h"
#define REPORTING_PERIOD_MS 2000
 char auth[] = BLYNK_AUTH_TOKEN;             
char ssid[] = "mayur_5";                                     // Your WiFi credentials.
char pass[] = "mayur@1234";
BlynkTimer timer;
#define soil_pin 33
#define fan_pin 25
#define light_pin 26
#define pump1_pin 27
#define pump2_pin 14

int moisture = 0;

 void sendSensor(){
   Blynk.virtualWrite(V3, moisture);
 }

BLYNK_WRITE(V0){
  int value0 = param.asInt();
  Serial.print("value0   ");
  Serial.println(value0);
if(value0==0)
digitalWrite(fan_pin, HIGH);
if(value0==1)
digitalWrite(fan_pin, LOW);
  }

BLYNK_WRITE(V1){
  int value0 = param.asInt();
  Serial.print("value0   ");
  Serial.println(value0);
if(value0==0)
digitalWrite(light_pin, HIGH);
if(value0==1)
digitalWrite(light_pin, LOW);
  }

BLYNK_WRITE(V2){
  int value0 = param.asInt();
  Serial.print("value0   ");
  Serial.println(value0);
if(value0==0)
digitalWrite(pump2_pin, HIGH);
if(value0==1)
digitalWrite(pump2_pin, LOW);
  }

void setup()
{ 
    pinMode(fan_pin, OUTPUT);
    pinMode(light_pin, OUTPUT);
    pinMode(pump1_pin, OUTPUT);
    pinMode(pump2_pin, OUTPUT);
    digitalWrite(fan_pin, HIGH);
    digitalWrite(light_pin, HIGH);
    digitalWrite(pump1_pin, HIGH);
    digitalWrite(pump2_pin, HIGH);
    Serial.begin(115200);
    Blynk.begin(auth, ssid, pass);
    timer.setInterval(3500L, sendSensor);

}
 
void loop()
{    
  Blynk.run();
  timer.run();

  moisture = analogRead(soil_pin);
   Serial.print("moisture:  ");
  Serial.println(moisture);
  moisture = map(moisture,4095,0,0,100);
   Serial.print("moisture:  ");
  Serial.println(moisture);
  if (moisture < 20)
  digitalWrite(pump1_pin, LOW);
  else digitalWrite(pump1_pin, HIGH);

  
}