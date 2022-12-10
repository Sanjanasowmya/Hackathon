// Chage These Credentials with your Blynk Template credentials 
#define BLYNK_TEMPLATE_ID "TMPL7LEHylkj"
#define BLYNK_DEVICE_NAME "sanj"
#define BLYNK_AUTH_TOKEN "e_dda86NJqqhD8kBP5l1bkhnqhsY4wCE"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "V2025"; // Change your Wifi/ Hotspot Name
char pass[] = "sanjana25"; // Change your Wifi/ Hotspot Password

BlynkTimer timer;

#define MQ2 A0
//#define GREEN D5
//#define RED D6
//#define buzzer  D7
int MQ2_Val = 0;

WidgetLED led(V1);


void setup() //Setup function - only function that is run in deep sleep mode
{
  Serial.begin(9600); //Start the serial output at 115,200 baud
 // pinMode(GREEN, OUTPUT);
 // pinMode(RED, OUTPUT);
  //pinMode(buzzer, OUTPUT);
  
  Blynk.begin(auth, ssid, pass);//Splash screen delay
  delay(2000);
  timer.setInterval(1000L, mySensor);
}

void loop() //Loop function
{
  Blynk.run();
  timer.run();
}

void mySensor()
{
  MQ2_Val = analogRead(MQ2);
  for(int x = 0 ; x < 100 ; x++)
    {
        MQ2_Val = MQ2_Val + analogRead(MQ2);
    }
    MQ2_Val = MQ2_Val/100.0;
  
  Blynk.virtualWrite(V0, MQ2_Val);
    
  if (MQ2_Val > 100)
  {
    Blynk.notify("Gas Detected!");
    //digitalWrite(GREEN, LOW);
    //digitalWrite(RED, HIGH);
   //digitalWrite(buzzer, HIGH);
    led.on();
  }

  else
  {
    //digitalWrite(GREEN, HIGH);
    //digitalWrite(RED, LOW);
   // digitalWrite(buzzer, LOW);
    led.off();
  }  
  Serial.print("smoke level:");
  Serial.println(MQ2_Val);
  
}