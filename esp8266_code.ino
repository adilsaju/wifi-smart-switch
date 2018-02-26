/*login on Sign up a new account in Blynk using your email id.
  Click on Create New Project,choosed device esp8266 and click create.
  The auth token for this project will be delivered to your email.Replace the auth token in program with your auth token.
  create a button,edit and change its PIN to (Digital) D6.
  */
  
  
#include <Blynk.h>
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


char auth[] = "a624256ad4ab4d548ff5f210f3d6fe6a"; //Auth Token for WiM automation project provided by Blynk

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "adiljio"; //Replace with ssid(wifi name) of your home wifi hotspot
char pass[] = "8281537265"; //Replace with wpa2 password of your home wifi hotspot
int ledPin = 2;
int buttonPin = 12; 
int buttonState = 0;     

void setup()
{
  // Debug console
  Serial.begin(115200);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8442);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8442);

  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);

}

void loop()
{
   Blynk.run();
   buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
   
}
