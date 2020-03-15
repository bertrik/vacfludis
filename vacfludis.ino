#include <Arduino.h>
#include <ezTime.h>
#include <ESP8266WiFi.h>
#include "VFD.h"

Timezone myTZ;
String tijd;

void setup()
{
    //pinMode(Pin_RED_LED13, OUTPUT);
    //digitalWrite(Pin_RED_LED13, HIGH);
    pinMode(D3, OUTPUT);
    digitalWrite(D3, LOW);
    Serial.begin(9600);
    Vfd.init();
    Vfd.write("Connecting Wifi");
    Serial.println("VFD Demo");
    WiFi.mode(WIFI_STA);
    WiFi.begin("revspace-pub-2.4ghz", "");

    waitForSync();

    // Or country codes for countries that do not span multiple timezones
    myTZ.setLocation(F("nl"));
    Serial.print(F("Nederland:         "));
    Serial.println(myTZ.second());
    tijd = myTZ.second() + " ";

    //Serial.println(tijd);
    Vfd.write((char *) tijd.c_str());
}

int tijdoud = 99;

void loop()
{
    events();
    //digitalWrite(Pin_RED_LED13, !digitalRead(Pin_RED_LED13));

    //
    //Vfd.write(myTZ.dateTime());
    //delay(500);
    blinkout();
    int seconde = myTZ.second();
    if (seconde < 10) {
        tijd = '0' + seconde;
    } else {
        tijd = seconde;
    }
    //tijd = myTZ.second();
    Serial.println(tijd);
    Vfd.write("            ");
    Vfd.write((char *) tijd.c_str());
    blinkin();
}

void blinkin()
{
    for (int i = 1; i <= 15; i++) {
        Vfd.setDuty(i);
        delay(40);
    }
}

void blinkout()
{
    for (int i = 1; i <= 15; i++) {
        Vfd.setDuty(16 - i);
        delay(40);
    }
}

