#include "memory.h"
#include <stdio.h>
#include <limits.h>

void first_fit(MemoryBlock *blocks, int n_blocks, int process_id, int size) {
    printf("First Fit Algorithm\n");
    
    for(int i = 0; i < n_blocks; i++) {
        if(!blocks[i].is_allocated && blocks[i].size >= size) {
            blocks[i].is_allocated = 1;
            blocks[i].process_id = process_id;
            printf("Allocated block %d to process %d\n", blocks[i].id, process_id);
            return;
        }
    }
    printf("No suitable block found for process %d\n", process_id);
}

void best_fit(MemoryBlock *blocks, int n_blocks, int process_id, int size) {
    printf("Best Fit Algorithm\n");
    
    int best_fit_index = -1;
    int min_fragment = INT_MAX;

    for(int i = 0; i < n_blocks; i++) {
        if(!blocks[i].is_allocated && blocks[i].size >= size) {
            if(blocks[i].size - size < min_fragment) {
                min_fragment = blocks[i].size - size;
                best_fit_index = i;
            }
        }
    }

    if(best_fit_index != -1) {
        blocks[best_fit_index].is_allocated = 1;
        blocks[best_fit_index].process_id = process_id;
        printf("Allocated block %d to process %d\n", blocks[best_fit_index].id, process_id);
    } else {
        printf("No suitable block found for process %d\n", process_id);
    }
}

void worst_fit(MemoryBlock *blocks, int n_blocks, int process_id, int size) {
    printf("Worst Fit Algorithm\n");
    
    int worst_fit_index = -1;
    int max_fragment = -1;

    for(int i = 0; i < n_blocks; i++) {
        if(!blocks[i].is_allocated && blocks[i].size >= size) {
            if(blocks[i].size - size > max_fragment) {
                max_fragment = blocks[i].size - size;
                worst_fit_index = i;
            }
        }
    }

    if(worst_fit_index != -1) {
        blocks[worst_fit_index].is_allocated = 1;
        blocks[worst_fit_index].process_id = process_id;
        printf("Allocated block %d to process %d\n", blocks[worst_fit_index].id, process_id);
    } else {
        printf("No suitable block found for process %d\n", process_id);
    }
} 