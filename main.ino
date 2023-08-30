
//FirebaseESP8266.h must be included before ESP8266WiFi.h
#include "FirebaseESP8266.h"  // Install Firebase ESP8266 library
#include <ESP8266WiFi.h>



#define FIREBASE_HOST " " //Without http:// or https:// schemes
#define FIREBASE_AUTH " " //Get your own authentication key
#define WIFI_SSID " "//Put your own wifi ssid 
#define WIFI_PASSWORD " " //Put your own wifi password

int led1 = D2;  
int led2 = D3;  
int led3 = D4;  
int led4 = D5;    

//Define FirebaseESP8266 data object
FirebaseData firebaseData;
FirebaseData ledData;

FirebaseJson json;


void setup()
{

  Serial.begin(9600);


  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

}


void loop() {
  
  
  if (Firebase.getString(ledData, "/HomeAutomation_Firebase_4CH/D1")){
    Serial.println(ledData.stringData());
    if (ledData.stringData() == "0") {
    digitalWrite(led1, HIGH);
    }
  else if (ledData.stringData() == "1"){
    digitalWrite(led1, LOW);
    }
  }
  delay(100);

  if (Firebase.getString(ledData, "/HomeAutomation_Firebase_4CH/D2")){
    Serial.println(ledData.stringData());
    if (ledData.stringData() == "0") {
    digitalWrite(led2, HIGH);
    }
  else if (ledData.stringData() == "1"){
    digitalWrite(led2, LOW);
    }
  }
  delay(100);

  if (Firebase.getString(ledData, "/HomeAutomation_Firebase_4CH/D3")){
    Serial.println(ledData.stringData());
    if (ledData.stringData() == "0") {
    digitalWrite(led3, HIGH);
    }
  else if (ledData.stringData() == "1"){
    digitalWrite(led3, LOW);
    }
  }
  delay(100);

  if (Firebase.getString(ledData, "/HomeAutomation_Firebase_4CH/D4")){
    Serial.println(ledData.stringData());
    if (ledData.stringData() == "0") {
    digitalWrite(led4, HIGH);
    }
  else if (ledData.stringData() == "1"){
    digitalWrite(led4, LOW);
    }
  }
  delay(100);
}
