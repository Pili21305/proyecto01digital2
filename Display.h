#ifndef __DISPLAY7_H__
#define __DISPLAY7_H__

#include <Arduino.h>
extern uint8_t pA, pB, pC, pD, pE, pF, pG;

void configuracionDisplay(uint8_t pinA, uint8_t pinB, uint8_t pinC, uint8_t pinD, uint8_t pinE ,uint8_t pinF ,uint8_t pinG,uint8_t pinpd);
void desplegarvalor(uint8_t valor);

void desplegarpunto(boolean punto);

#endif // __DISPLAY7_H__
