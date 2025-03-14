#include "RIMS.h"

volatile unsigned char TimerFlag = 0;

void TimerISR() { TimerFlag = 1; }

enum GP_States { ... } GP_State;
void GP_Tick() { ... }

enum RE_States { ... } RE_State;
void RE_Tick() { ... }

void main () {

    uint16_t period = 50;

    uint16_t GP_Elapsed = 200;
    uint16_t RE_Elapsed = 50;

    B = 0;
    TimerSet(50);
    TimerOn();
    GP_State = GP_Start;
    RE_State = RE_Start;

    while(1) {

        if (GP_Elapsed >= 200) {
            GP_Tick();
            GP_Elapsed = 0;
        }
        if (RE_Elapsed >= 50) {
            RE_Tick();
            RE_Elapsed = 0;
        }

        while(!TimerFlag) {}
        TimerFlag = 0;

        GP_Elapsed += period;
        RE_Elapsed += period;

    }
}