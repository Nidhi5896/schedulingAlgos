#include "scheduler.h"
#include <stdio.h>
#include <stdlib.h>

void fcfs_schedule(Process *processes, int n) {
    printf("FCFS Scheduling\n");
    int current_time = 0;
    
    // Sort by arrival time (assuming they're already sorted)
    for(int i = 0; i < n; i++) {
        if(current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }
        
        processes[i].completion_time = current_time + processes[i].burst_time;
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
        
        current_time = processes[i].completion_time;
        
        printf("Process %d: Completion Time = %d, Turnaround Time = %d, Waiting Time = %d\n",
               processes[i].pid,
               processes[i].completion_time,
               processes[i].turnaround_time,
               processes[i].waiting_time);
    }
}

void sjf_schedule(Process *processes, int n) {
    printf("SJF Scheduling\n");
    int current_time = 0;
    int completed = 0;
    
    while(completed < n) {
        int shortest_job = -1;
        int min_burst = 2147483647; // Maximum value for a 32-bit integer
        
        for(int i = 0; i < n; i++) {
            if(processes[i].arrival_time <= current_time && 
               processes[i].remaining_time > 0 && 
               processes[i].remaining_time < min_burst) {
                shortest_job = i;
                min_burst = processes[i].remaining_time;
            }
        }
        
        if(shortest_job == -1) {
            current_time++;
            continue;
        }
        
        processes[shortest_job].remaining_time = 0;
        processes[shortest_job].completion_time = current_time + min_burst;
        processes[shortest_job].turnaround_time = processes[shortest_job].completion_time - 
                                                processes[shortest_job].arrival_time;
        processes[shortest_job].waiting_time = processes[shortest_job].turnaround_time - 
                                             processes[shortest_job].burst_time;
        
        current_time = processes[shortest_job].completion_time;
        completed++;
        
        printf("Process %d: Completion Time = %d, Turnaround Time = %d, Waiting Time = %d\n",
               processes[shortest_job].pid,
               processes[shortest_job].completion_time,
               processes[shortest_job].turnaround_time,
               processes[shortest_job].waiting_time);
    }
}

void round_robin_schedule(Process *processes, int n, int quantum) {
    printf("Round Robin Scheduling (Quantum = %d)\n", quantum);
    int current_time = 0;
    int completed = 0;
    
    while(completed < n) {
        int flag = 0;
        for(int i = 0; i < n; i++) {
            if(processes[i].remaining_time > 0) {
                flag = 1;
                
                if(processes[i].remaining_time > quantum) {
                    current_time += quantum;
                    processes[i].remaining_time -= quantum;
                } else {
                    current_time += processes[i].remaining_time;
                    processes[i].completion_time = current_time;
                    processes[i].remaining_time = 0;
                    completed++;
                    
                    processes[i].turnaround_time = processes[i].completion_time - 
                                                 processes[i].arrival_time;
                    processes[i].waiting_time = processes[i].turnaround_time - 
                                              processes[i].burst_time;
                    
                    printf("Process %d: Completion Time = %d, Turnaround Time = %d, Waiting Time = %d\n",
                           processes[i].pid,
                           processes[i].completion_time,
                           processes[i].turnaround_time,
                           processes[i].waiting_time);
                }
            }
        }
        if(!flag) current_time++;
    }
} 