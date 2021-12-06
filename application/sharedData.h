/*
 *
 * Copyright (c) 2005-2021 Imperas Software Ltd., www.imperas.com
 *
 * The contents of this file are provided under the Software License
 * Agreement that you accepted before downloading this file.
 *
 * This source forms part of the Software and can be used for educational,
 * training, and demonstration purposes but cannot be used for derivative
 * works except in cases where the derivative works require OVP technology
 * to run.
 *
 * For open source models released under licenses that you can use for
 * derivative works, please visit www.OVPworld.org or www.imperas.com
 * for the location of the open source models.
 *
 */

#ifndef SHARED_DATA_H
#define SHARED_DATA_H

#include "shared.h"

// the size of the vector that must be sorted
#define VECTOR_SIZE 104

// the system size
#define SYSTEM_SIZE 8

// macros
#define START   0x10101010
#define DONE    0x30303030

typedef struct ctrlS {
    // stores the vector itself
    int vector[VECTOR_SIZE]; 
    // informs the processor status
    volatile int subVector_status[SYSTEM_SIZE]; 
    // informs each processor its finish point
    volatile int subVector_finishPoint[SYSTEM_SIZE];
    // informs the size that each subVector have
    volatile int subVector_size;
} ctrl, *ctrlP;

// pointer to the struct that controls the system
#define CONTROL ((ctrlP)(SHARED_LOW+0))

#endif
