#include "RIMS.h"

typedef struct task {
    int state;
    unsigned long period;
    unsigned long elapsedTime;
    int (*TickFunc)(int);
} task;

task tasks[taskNum];

const unsigned char tasksNum = 2;
const unsigned long tasksPeriodGCD = 50;
const unsigned long periodGeneratePulse = 200;
const unsigned long periodRecordEchoes = 50;

enum GP_States { ... } GP_State;
int GP_Tick(int state) { ... }

enum RE_States { ... } RE_State;
int RE_Tick(int state) { ... }

void TimerISR() {
    unsigned char i;

    for (i = 0; i < tasksNum; ++i) {

        if (tasks[i].elapsedTime >= tasks[i].period) {
            tasks[i].state = tasks[i].TickFunc(tasks[i].state);
            tasks[i].elapsedTime = 0;
        }

        tasks[i].elapsedTime += tasksPeriodGCD;
    }
}

int main() {
    unsigned char i = 0;

    tasks[i].state = GP_Start;
    tasks[i].period = periodGeneratePulse;
    tasks[i].elapsedTime = tasks[i].period;
    tasks[i].TickFunc = &GP_Tick;
    i++;
    tasks[i].state = RE_Start;
    tasks[i].period = periodRecordEchoes;
    tasks[i].elapsedTime = tasks[i].period;
    tasks[i].TickFunc = &RE_Tick;

    TimerSet(tasksPeriodGCD);
    TimerOn();

    while (1) { Sleep(); }
    return 0;
}