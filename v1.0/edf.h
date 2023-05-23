#ifndef EDF_H
#define EDF_H

#include <stdio.h>

typedef struct _edf_task_t edf_task_t;

struct _edf_task_t
{
    char *name;
    int period;
    int next_arrive;
    // int deadline;
    int sched_times;

    unsigned int font_color;

    int exec_time;
    int left_exec_time;

    struct _edf_task_t *pre;
    struct _edf_task_t *next;
};

void edf_init(void);

void edf_create_task(edf_task_t* tcb, char *name, int exec_time, int period, unsigned int font_color);

void edf_sched(int tick);

void edf_show_tasks(void);



#endif


