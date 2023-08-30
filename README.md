// proyecto01digital2
//******************************************************************************
// Pilar Trujillo 21305
//******************************************************************************

//******************************************************************************
// librerías
//******************************************************************************

#include <Arduino.h>
#include <driver/ledc.h>
#include "display7.h"
#include <config.h>

//******************************************************************************
// definiciones
//******************************************************************************

int lectura_t = 0.0;
volatile float temp;

#define ledRCh 0 
#define ledGCh 1
#define ledBCh 2
#define servoCh 3

#define Boton1 15
#define pinADC 35
#define Led1 27 // led amarillo
#define Led2 26 // led verde
#define Led3 25 // led roja

#define freq1 500
#define freq2 600
#define freq3 700
#define servofreq 50

#define pinA 21
#define pinB 19
#define pinC 18
#define pinD 5
#define pinE 17
#define pinF 16
#define pinG 33
#define pinpd 32

#define display1 14
#define display2 12
#define display3 13

#define servoP 23
#define resolution 8
#define servoResolution 16

#define ADC_mV 3330
#define ADC_Resolution 4096.0

float temperatura = 0.0;
void configuracionPWM();
void MoveServo(int angle);
void indicadordetemp(void);
void Sendingtemp(void);

void handleMessage(AdafruitIO_Data *data);
AdafruitIO_Feed *tempCanal = io.feed("temperatura");
AdafruitIO_Feed *LedCanal = io.feed("canal led");

//******************************************************************************
// Setup
//******************************************************************************

void setup(){
    configuracionPWM();
    configuracionDisplay(pinA, pinB, pinC, pinD, pinE, pinF, pinG, pinpd);

    pinMode(Boton1, INPUT_PULLUP);
    pinMode(pinADC, OUTPUT);
    pinMode(Led1, OUTPUT);
    pinMode(Led2, OUTPUT);
    pinMode(Led3, OUTPUT);

    pinMode(display1, OUTPUT);
    pinMode(display2, OUTPUT);
    pinMode(display3, OUTPUT);

    pinMode(pinA, OUTPUT);
    pinMode(pinB, OUTPUT);
    pinMode(pinC, OUTPUT);
    pinMode(pinD, OUTPUT);
    pinMode(pinE, OUTPUT);
    pinMode(pinF, OUTPUT);
    pinMode(pinG, OUTPUT);

    digitalWrite(display1, HIGH);
    digitalWrite(display2, HIGH);
    digitalWrite(display3, HIGH);

    digitalWrite(Led1, HIGH);
    digitalWrite(Led2, HIGH);
    digitalWrite(Led3, HIGH);

    Serial.begin(115200);
    while (!Serial);

    Serial.print("Connecting to Adafruit IO");
    io.connect();

    while (io.status() < AIO_CONNECTED){
        Serial.print(".");
        delay(500);
    }
    Serial.println();
    Serial.println(io.statusText());

    LedCanal->onMessage(handleMessage);
    LedCanal->get();
}
//******************************************************************************
// loop
//******************************************************************************

void loop(){
    int buttonState = digitalRead(Boton1);

    if (buttonState == LOW)
    {

        int lectura_t = analogRead(pinADC);
        temperatura = (lectura_t * (3300.0 / ADC_Resolution));
        temp = temperatura / 10.0;

        Serial.print("Temperatura: ");
        Serial.print(temp);
        Serial.println(" °C");
        indicadordetemp();

        Sendingtemp();
    }

    int temptot = int(temp);
    volatile int dig3 = int((temp - temptot) * 10);
    volatile int dig1 = temptot / 10;
    volatile int dig2 = temptot % 10;

    digitalWrite(display1, HIGH);
    digitalWrite(display2, LOW);
    digitalWrite(display3, LOW);
    desplegarvalor(dig1);
    delay(5);

    digitalWrite(display1, LOW);
    digitalWrite(display2, HIGH);
    digitalWrite(display3, LOW);
    desplegarvalor(dig2);
    desplegarpunto(true);
    delay(5);

    digitalWrite(display1, LOW);
    digitalWrite(display2, LOW);
    digitalWrite(display3, HIGH);
    desplegarvalor(dig3);
    desplegarpunto(false);
    delay(5);
}

void configuracionPWM(){

    ledcSetup(ledRCh, freq1, resolution);
    ledcSetup(ledGCh, freq2, resolution);
    ledcSetup(ledBCh, freq3, resolution);
    ledcSetup(servoCh, servofreq, servoResolution);

    ledcAttachPin(Led1, ledBCh);
    ledcAttachPin(Led2, ledGCh);
    ledcAttachPin(Led3, ledRCh);
    ledcAttachPin(servoP, servoCh);
}

void MoveServo(int angulo){

    int dutyCycle = map(angulo, 0, 180, 1500, 8000);
    ledcWrite(servoCh, dutyCycle);
    delay(1000);
}

void indicadordetemp(){
    
    if (temp <= 15.0)
    {
        digitalWrite(Led1, HIGH);
        digitalWrite(Led2, LOW);
        digitalWrite(Led3, LOW);

        // delay (5);

        MoveServo(0);
    }
    else if (temp > 15.0 && temp <= 18.5)
    {
        digitalWrite(Led1, LOW);
        digitalWrite(Led2, HIGH);
        digitalWrite(Led3, LOW);
        // delay(5);
        MoveServo(90);
    }
    else if (temp > 20.0)
    {
        digitalWrite(Led1, LOW);
        digitalWrite(Led2, LOW);
        digitalWrite(Led3, HIGH);
        // delay(5);
        MoveServo(180);
    }
}
void handleMessage(AdafruitIO_Data *data){

    Serial.print("received <- ");
    Serial.println(data->value());
}

void Sendingtemp(void){

    io.run();
    Serial.print("sending -> ");
    Serial.println(temp);
    tempCanal->save(temp);
    delay(3000);
} 
