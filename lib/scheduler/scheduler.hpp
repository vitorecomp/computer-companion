#ifndef SCHEDULER_H
#define SCHEDULER_H

struct schedules_runs
{
    unsigned long int last_wake_up_call_time;
};

void get_schedules(struct schedules_runs*);
int scheduler_get_commands(struct command*, struct schedules_runs*); 

#endif // SCHEDULER_H