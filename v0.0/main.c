#include <stdio.h>
#include "edf.h"

edf_task_t t1_tcb, t2_tcb;

int main(int argc, char **argv)
{
    edf_init();

    edf_create_task(
        &t1_tcb,
        "t1",
        2,
        4
    );

    edf_create_task(
        &t2_tcb,
        "t2",
        5,
        10
    );

    int total_time = 20;
    int sys_tick = 1;
    
    while(sys_tick <= total_time)
    {
        edf_sched(sys_tick);

        sys_tick++;
    }

    return 0;
}