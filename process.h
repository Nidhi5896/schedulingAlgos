#ifndef PROCESS_H
#define PROCESS_H

// Process structure to hold process details
typedef struct {
    int pid;                // Process ID
    int arrival_time;       // Arrival time
    int burst_time;        // CPU burst time
    int remaining_time;    // Remaining time for execution
    int completion_time;   // Time when process completes
    int waiting_time;      // Total waiting time
    int turnaround_time;   // Total turnaround time
} Process;

#endif 