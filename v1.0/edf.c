/**
 * @file edf.c
 * @author mio (648137125@qq.com)
 * @brief EDF调度改进版，对队列数据结构进行优化
 * @version 1.0
 * @date 2023-04-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "edf.h"
#include "color.h"

edf_task_t *pre_task = NULL, *cur_task = NULL;

edf_task_t edf_rdy_head = {0};
edf_task_t edf_wait_head = {0};

/* pri funcs start ***/
void        edf_task_insert_orderly(edf_task_t *head, edf_task_t *task); /**< 对比v0.0的主要改动就在有序链表上 */
edf_task_t *edf_task_get_first(edf_task_t *head);
void        edf_task_remove_from_list(edf_task_t *task);
edf_task_t *edf_get_highest(int tick);
void        edf_wait_next_arrive(edf_task_t *task);
void        edf_deal_wait_list(void);
/* pri funcs end ***/

void edf_init(void)
{
    edf_rdy_head.pre  = &edf_rdy_head;
    edf_rdy_head.next = &edf_rdy_head;

    edf_wait_head.pre  = &edf_wait_head;
    edf_wait_head.next = &edf_wait_head;
}

/**
 * @brief 创建edf任务
 * 
 * @param tcb       任务控制块
 * @param name      任务名称
 * @param exec_time 执行总时间
 * @param period    周期
 */
void edf_create_task(edf_task_t* tcb, char *name, int exec_time, int period, unsigned int font_color)
{
    tcb->name           = name;
    tcb->period         = period;
    tcb->next_arrive    = period;
    // tcb->deadline       = period;

    tcb->sched_times    = 0;

    tcb->exec_time      = exec_time;
    tcb->left_exec_time = exec_time;

    tcb->font_color = font_color;

    edf_task_insert_orderly(&edf_rdy_head, tcb);
}



void edf_sched(int tick)
{
    edf_deal_wait_list();
    cur_task = edf_get_highest(tick);
    if(NULL == cur_task)
    {
        printf("-\n");
    }
    else
    {
        if(pre_task != cur_task)
        {
            pre_task = cur_task;

            if(cur_task->left_exec_time == cur_task->exec_time)
            {
                cur_task->sched_times++;
            }

            printf("** task switch\n");
        }
        cur_task->left_exec_time--;
        
        printf("\033[%dm %.2d-%s-%d, left:%d, next_arrive:%d \033[0m\n",
            cur_task->font_color, 
            tick, 
            cur_task->name, 
            cur_task->sched_times, 
            cur_task->left_exec_time, 
            cur_task->next_arrive
        );

    }
}

void edf_show_tasks(void)
{
    edf_task_t *p = edf_rdy_head.next;

    int i = 0;
    printf("--------------------------\n");
    while(p != &edf_rdy_head)
    {
        printf("%2d:name=%s,period=%3d,next_arrive=%3d,sched_times=%8d\n",
        i++,
        p->name,
        p->period,
        p->next_arrive,
        p->sched_times
        );

        p = p->next;
    }
    printf("--------------------------\n");
}

/* pri funcs start ***/
void edf_task_insert_orderly(edf_task_t *head, edf_task_t *task)
{
    edf_task_t *p = head->next;

    if(p != head)
    {
        /* 找到差分链表中合适的位置，即截止时间比上一个任务晚且比下一个任务更早 */
        while(
            (task->next_arrive >= p->next_arrive) &&
            (p != head)
        )
        {
            task->next_arrive -= p->next_arrive;
            p = p->next;
        }

        p->next_arrive -= task->next_arrive;
    }

    task->pre = p->pre;
    task->next = p;

    p->pre->next = task;
    p->pre = task;

    // task->pre = head->pre;
    // task->next = head;

    // head->pre->next = task;
    // head->pre = task;
}

edf_task_t *edf_task_get_first(edf_task_t *head)
{
    edf_task_t *ret = NULL;
    if(head->next != head)
    {
        ret = head->next;
        head->next = ret->next;
        ret->next->pre = head;
    }

    return ret;
}

void edf_task_remove_from_list(edf_task_t *task)
{
    task->pre->next = task->next;
    task->next->pre = task->pre;
}

edf_task_t *edf_get_highest(int tick)
{
    edf_task_t *ret        = NULL;
    edf_task_t *tmp_task   = edf_rdy_head.next;
    edf_task_t *next_rdy   = NULL;//下一个就绪的任务

    

    //找到截止时间最早的任务
    //while(tmp_task != &edf_rdy_head)
    if(tmp_task != &edf_rdy_head)
    {
        //截止时间和下次到达时间均去掉一个tick
        //tmp_task->deadline--;
        tmp_task->next_arrive--;
        
        //如果剩余执行时间为零
        if(0 == tmp_task->left_exec_time)
        {
            next_rdy = tmp_task->next;

            //tmp_task->deadline = tmp_task->period;
            //tmp_task->next_arrive = tmp_task->period;
            next_rdy->next_arrive += tmp_task->next_arrive;
            edf_wait_next_arrive(tmp_task);

            tmp_task = next_rdy;//将tmp_task移动到下一个就绪的任务上
        }

        if(tmp_task != &edf_rdy_head)
        {
            ret = tmp_task;
        }
        
    }

    return ret;
}

void edf_wait_next_arrive(edf_task_t *task)
{
    edf_task_remove_from_list(task);

    //todo: 计算任务距离下次到达还有多少时间，赋值给next_arrive
    //因为在每次调度都处理了下次到达时间，这里就不用处理了
    edf_task_insert_orderly(&edf_wait_head, task);
}

void edf_deal_wait_list(void)
{
    edf_task_t *tmp_task = edf_wait_head.next;//用于遍历链表
    edf_task_t *next_wait = NULL;             //用于存储即将到达的等待任务的下一个任务

    while(tmp_task != &edf_wait_head)
    {
        

        //如果任务到了到达时间，就从等待链表取出，放入就绪链表
        if(0 == tmp_task->next_arrive)
        {
            next_wait = tmp_task->next;//如果这里不用额外指针rdy_task, tmp_task指针会跑到就绪链表中去
            edf_task_remove_from_list(tmp_task);

            //tmp_task->deadline    = tmp_task->period;
            tmp_task->next_arrive = tmp_task->period;

            tmp_task->left_exec_time = tmp_task->exec_time;

            edf_task_insert_orderly(&edf_rdy_head, tmp_task);

            tmp_task = next_wait;
        }
        else
        {
            tmp_task->next_arrive--;
            //printf("**%s next_arrive:%d\n", tmp_task->name, tmp_task->next_arrive);
            tmp_task = tmp_task->next;
        }

        


        
    }

}

/* pri funcs end ***/