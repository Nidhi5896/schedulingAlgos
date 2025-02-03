#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "process.h"

// Function declarations for different scheduling algorithms
void fcfs_schedule(Process *processes, int n);
void sjf_schedule(Process *processes, int n);
void round_robin_schedule(Process *processes, int n, int quantum);

#endif 