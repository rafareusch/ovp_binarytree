#include <stdio.h>
#include <stdlib.h>

#include "sharedData.h"
#include "sortStuff.h"
#include "math.h"
#include "simulatorIntercepts.h"

//
// Main routine
//
int main(int argc, char **argv) {

    ctrlP ctrl = CONTROL;
    int i;
    int id = impProcessorId();
    
    // fill the vector with values
    for(i = 0; i < VECTOR_SIZE; i++){
        ctrl->vector[i] = VECTOR_SIZE-i;
    }
    printArray(ctrl->vector, 0, VECTOR_SIZE-1);

    // calculates the size of each sub-vector
    ctrl->subVector_size = VECTOR_SIZE / SYSTEM_SIZE;
   
    printf("Each slave Sub-Vector has %d values\n", ctrl->subVector_size);

    // informs to each PE the endpoint of its sub-vector
    for(i=0; i < SYSTEM_SIZE; i++){
        ctrl->subVector_finishPoint[i] = i*ctrl->subVector_size-1;
        ctrl->subVector_status[i] = START; // releases the given processor to start
        printf("id = %d // (%d,%d) \n", i, (i)*ctrl->subVector_size ,(i)*ctrl->subVector_size+ctrl->subVector_size-1);
    }

    // sort my sub vector
    printf("Processor %d starting the sort process...\n", id);
    quickSort(ctrl->vector,0,ctrl->subVector_size-1);
    // merge process -- if needed


    // informs that it's DONE!
    ctrl->subVector_status[id] = DONE;

    /* checks for erros */
    for(i = 1; i <= VECTOR_SIZE; i++){
        if(ctrl->vector[i-1] != i){
            printf("ERRO ENCONTRADO EM %d --> %d\n",i, ctrl->vector[i]);
            return 1;
        }
    }
    printf("NENHUM ERRO ENCONTRADO, PARABENS!");
    return 0;
}
