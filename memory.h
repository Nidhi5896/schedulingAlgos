#ifndef MEMORY_H
#define MEMORY_H

// Memory block structure
typedef struct {
    int id;             // Block ID
    int size;           // Size of memory block
    int is_allocated;   // Flag to check if block is allocated
    int process_id;     // ID of process that allocated this block
} MemoryBlock;

// Function declarations for memory allocation algorithms
void first_fit(MemoryBlock *blocks, int n_blocks, int process_id, int size);
void best_fit(MemoryBlock *blocks, int n_blocks, int process_id, int size);
void worst_fit(MemoryBlock *blocks, int n_blocks, int process_id, int size);

#endif 