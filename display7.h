//******************************************************************************
//librería Display: Pilar Trujillo 21305
//******************************************************************************

#include <display7.h>

uint8_t pA, pB, pC, pD, pE, pF, pG, ppd;

void configuracionDisplay(uint8_t pinA, uint8_t pinB, uint8_t pinC, uint8_t pinD, uint8_t pinE, uint8_t pinF, uint8_t pinG, uint8_t pinpd)
{

    pA = pinA;
    pB = pinB;
    pC = pinC;
    pD = pinD;
    pE = pinE;
    pF = pinF;
    pG = pinG;
    ppd = pinpd;

    pinMode(pA, OUTPUT);
    pinMode(pB, OUTPUT);
    pinMode(pC, OUTPUT);
    pinMode(pD, OUTPUT);
    pinMode(pE, OUTPUT);
    pinMode(pF, OUTPUT);
    pinMode(pG, OUTPUT);
    pinMode(ppd, OUTPUT);

    digitalWrite(pA, LOW);
    digitalWrite(pB, LOW);
    digitalWrite(pC, LOW);
    digitalWrite(pD, LOW);
    digitalWrite(pE, LOW);
    digitalWrite(pF, LOW);
    digitalWrite(pG, LOW);
    digitalWrite(ppd, LOW);
}
void desplegarvalor(uint8_t valor)
{
    switch (valor)
    {
    case 0:
        digitalWrite(pA, HIGH);
        digitalWrite(pB, HIGH);
        digitalWrite(pC, HIGH);
        digitalWrite(pD, HIGH);
        digitalWrite(pE, HIGH);
        digitalWrite(pF, HIGH);
        digitalWrite(pG, LOW);
        break;

    case 1:
        digitalWrite(pA, LOW);
        digitalWrite(pB, HIGH);
        digitalWrite(pC, HIGH);
        digitalWrite(pD, LOW);
        digitalWrite(pE, LOW);
        digitalWrite(pF, LOW);
        digitalWrite(pG, LOW);
        break;

    case 2:
        digitalWrite(pA, HIGH);
        digitalWrite(pB, HIGH);
        digitalWrite(pC, LOW);
        digitalWrite(pD, HIGH);
        digitalWrite(pE, HIGH);
        digitalWrite(pF, LOW);
        digitalWrite(pG, HIGH);
        break;

    case 3:
        digitalWrite(pA, HIGH);
        digitalWrite(pB, HIGH);
        digitalWrite(pC, HIGH);
        digitalWrite(pD, HIGH);
        digitalWrite(pE, LOW);
        digitalWrite(pF, LOW);
        digitalWrite(pG, HIGH);
        break;

    case 4:
        digitalWrite(pA, LOW);
        digitalWrite(pB, HIGH);
        digitalWrite(pC, HIGH);
        digitalWrite(pD, LOW);
        digitalWrite(pE, LOW);
        digitalWrite(pF, HIGH);
        digitalWrite(pG, HIGH);
        break;

    case 5:
        digitalWrite(pA, HIGH);
        digitalWrite(pB, LOW);
        digitalWrite(pC, HIGH);
        digitalWrite(pD, HIGH);
        digitalWrite(pE, LOW);
        digitalWrite(pF, HIGH);
        digitalWrite(pG, HIGH);
        break;

    case 6:
        digitalWrite(pA, HIGH);
        digitalWrite(pB, LOW);
        digitalWrite(pC, HIGH);
        digitalWrite(pD, HIGH);
        digitalWrite(pE, HIGH);
        digitalWrite(pF, HIGH);
        digitalWrite(pG, HIGH);
        break;

    case 7:
        digitalWrite(pA, HIGH);
        digitalWrite(pB, HIGH);
        digitalWrite(pC, HIGH);
        digitalWrite(pD, LOW);
        digitalWrite(pE, LOW);
        digitalWrite(pF, LOW);
        digitalWrite(pG, LOW);
        break;

    case 8:
        digitalWrite(pA, HIGH);
        digitalWrite(pB, HIGH);
        digitalWrite(pC, HIGH);
        digitalWrite(pD, HIGH);
        digitalWrite(pE, HIGH);
        digitalWrite(pF, HIGH);
        digitalWrite(pG, HIGH);
        break;
        
    case 9:
        digitalWrite(pA, HIGH);
        digitalWrite(pB, HIGH);
        digitalWrite(pC, HIGH);
        digitalWrite(pD, LOW);
        digitalWrite(pE, LOW);
        digitalWrite(pF, HIGH);
        digitalWrite(pG, HIGH);
        break;

    default:
        break;
    }
}

void desplegarpunto(boolean punto)
{
    if (punto)
    {
        digitalWrite(ppd, HIGH);
    }
    else
    {
        digitalWrite(ppd, LOW);
    }
}
