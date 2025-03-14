#include "RIMS.h"

volatile unsigned char TimerFlag = 0;

void TimerISR() { TimerFlag = 1; }

enum GP_STATES {...} GP_State;
void GP_Tick() {

    static unsigned char i, pulse; // First blank fill in

    ... // Standard switch statments for SM
}

enum RE_States {...} RE_State;
void RE_Tick() {

    static unsigned char echoes; // Second blank fill in

    ... // Standard switch statements for SM
}

void main() {
    B = 0;
    TimerSet(200);
    TimerOn();
    GP_State = GP_Start;
    RE_State = RE_Start;

    while (1) {
        GP_Tick(); // Third blank fill in
        RE_Tick(); // Fourth blank fill in
        while (!TimerFlag) {}
        TimerFlag = 0;
    }
}