#include <stdio.h>
#include <stdlib.h>
#include "process.h"
#include "scheduler.h"
#include "memory.h"

void handle_cpu_scheduling(void);
void handle_memory_allocation(void);

int main() {
    int choice;
    
    printf("Operating System Simulation\n");
    printf("1. CPU Scheduling\n");
    printf("2. Memory Allocation\n");
    printf("Enter your choice (1-2): ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            handle_cpu_scheduling();
            break;
        case 2:
            handle_memory_allocation();
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}

void handle_cpu_scheduling() {
    int n, scheduling_choice, quantum;
    
    printf("\nEnter number of processes: ");
    scanf("%d", &n);
    
    Process *processes = (Process *)malloc(n * sizeof(Process));
    
    // Input process details
    for(int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("\nProcess %d\n", i + 1);
        printf("Arrival time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("Burst time: ");
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
    }

    printf("\nSelect Scheduling Algorithm:\n");
    printf("1. First Come First Serve (FCFS)\n");
    printf("2. Shortest Job First (SJF)\n");
    printf("3. Round Robin\n");
    scanf("%d", &scheduling_choice);

    switch(scheduling_choice) {
        case 1:
            fcfs_schedule(processes, n);
            break;
        case 2:
            sjf_schedule(processes, n);
            break;
        case 3:
            printf("Enter time quantum: ");
            scanf("%d", &quantum);
            round_robin_schedule(processes, n, quantum);
            break;
        default:
            printf("Invalid choice!\n");
    }

    free(processes);
}

void handle_memory_allocation() {
    int n_blocks, process_id, size, choice;
    
    printf("\nEnter number of memory blocks: ");
    scanf("%d", &n_blocks);
    
    MemoryBlock *blocks = (MemoryBlock *)malloc(n_blocks * sizeof(MemoryBlock));
    
    // Initialize memory blocks
    for(int i = 0; i < n_blocks; i++) {
        blocks[i].id = i + 1;
        printf("Enter size for block %d: ", i + 1);
        scanf("%d", &blocks[i].size);
        blocks[i].is_allocated = 0;
        blocks[i].process_id = -1;
    }

    printf("\nEnter process ID: ");
    scanf("%d", &process_id);
    printf("Enter memory size needed: ");
    scanf("%d", &size);

    printf("\nSelect Memory Allocation Algorithm:\n");
    printf("1. First Fit\n");
    printf("2. Best Fit\n");
    printf("3. Worst Fit\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            first_fit(blocks, n_blocks, process_id, size);
            break;
        case 2:
            best_fit(blocks, n_blocks, process_id, size);
            break;
        case 3:
            worst_fit(blocks, n_blocks, process_id, size);
            break;
        default:
            printf("Invalid choice!\n");
    }

    free(blocks);
} 