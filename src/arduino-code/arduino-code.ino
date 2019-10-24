/*
 * Projecr Name : Waste management
 * Project repository link : https://github.com/ajanyaraj347/waste-management
 * File name: arduino-code.ino
 * Author : Nandakishore
 * Created on : 24 Oct 2019
 * Last updated : 24 Oct 2019
 * Microcontroller: Atmega 328p
 * Pins used: Ultrasonic sensor:  Trigger pin - D3
 *                                Echo pin - D2
 */
#include <ESP8266WiFi.h> // For WiFi

const char *ssid =  "Sashwat's Note 8"; // WiFi SSID
const char *pass =  "123456789"; // WiFi PASS

int ultrasonicSensorTriggerPin = D3; // Ultrasonic sensor - trigger - digital pin 4
int ultasonicSensorEchoPin = D2; // Ultrasonic sensor - echo - digital pin 5
long durationForPulse; // Store duration from sending a pulse to receiving it
long waterLevelDistance; // Stores the distance between water and sensor in cm

WiFiClient client; // WiFi class object

void setup() {
  // put your setup code here, to run once:
  // Ultrasonic sensor
  pinMode(ultrasonicSensorTriggerPin, OUTPUT);
  pinMode(ultasonicSensorEchoPin, INPUT);
  Serial.begin(9600);
  Serial.println("Waste Management:-");
  Serial.println("Project by Nandakishore, Ajanya and Sandhya.");
  delay(10);
  Serial.print("Connecting to ");Serial.println(ssid);
  WiFi.begin(ssid, pass); // WiFi connection initialisation
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) 
          {
            delay(500);
            Serial.print(".");
          }
  Serial.println("Connected to WiFi.");
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ultrasonicSensorTriggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(ultrasonicSensorTriggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(ultrasonicSensorTriggerPin, LOW);
  durationForPulse = pulseIn(ultasonicSensorEchoPin, HIGH);
  waterLevelDistance = durationForPulse / 29 / 2; // distance formula
  Serial.print("Distance: ");Serial.print(waterLevelDistance);Serial.println(" cm"); // Display distance in cm
  delay(1000);
}
