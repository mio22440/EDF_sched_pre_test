#include <stdio.h>
#include "edf.h"
#include "color.h"

#define E1  2
#define P1  30
#define C1  F_WHITE

#define E2  1
#define P2  50
#define C2  F_BLUE

#define E3  3
#define P3  40
#define C3  F_GREEN

#define E4  5
#define P4  40
#define C4  F_PRED

#define E5  4
#define P5  60
#define C5  F_QING

#define TOTAL_TIME 600

edf_task_t t1_tcb, t2_tcb, t3_tcb, t4_tcb, t5_tcb;

int main(int argc, char **argv)
{
    edf_init();

    edf_create_task(
        &t1_tcb,
        "t1",
        E1,
        P1,
        C1
    );

    edf_create_task(
        &t2_tcb,
        "t2",
        E2,
        P2,
        C2
    );

    edf_create_task(
        &t3_tcb,
        "t3",
        E3,
        P3,
        C3
    );

    edf_create_task(
        &t4_tcb,
        "t4",
        E4,
        P4,
        C4
    );

    edf_create_task(
        &t5_tcb,
        "t5",
        E5,
        P5,
        C5
    );

    int total_time = TOTAL_TIME;
    int sys_tick = 1;
    
    edf_show_tasks();

    while(sys_tick <= total_time)
    {
        edf_sched(sys_tick);

        sys_tick++;
    }

    return 0;
}