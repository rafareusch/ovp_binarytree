#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sharedData.h"
#include "sortStuff.h"
#include "math.h"
#include "simulatorIntercepts.h"


bool isEven(int val){
	if ((val % 2) == 0) {
		return true;
	}  
	else
	{ 
		return false;
	}
}


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
        ctrl->subVector_finishPoint[i] = (i)*(ctrl->subVector_size)+ctrl->subVector_size-1;
        ctrl->subVector_startPoint[i] = (ctrl->subVector_finishPoint[i]+1)-ctrl->subVector_size;
        ctrl->subVector_status[i] = START; // releases the given processor to start
        printf("id = %d // (%d,%d) \n", i, ctrl->subVector_startPoint[i] ,ctrl->subVector_finishPoint[i]);
    }

    // sort my sub vector
    printf("Processor %d starting the sort process...\n", id);
    quickSort(ctrl->vector,0,ctrl->subVector_finishPoint[0]);

    
	int layer = 0;
	int step = 1;
	int remoteStartIndex = 0;
	int remoteEndIndex = 0;
    while ((layer < (SYSTEM_SIZE/2)) && isEven(id))
	{	
		if ( isEven(id) && isEven(id / step) && (id % step == 0) && (id+step<SYSTEM_SIZE) ){ 
			while(ctrl->subVector_status[id+step]!=DONE){ /* waits for the slave to be done */ }
			remoteEndIndex = ctrl->subVector_finishPoint[id+step];
			remoteStartIndex = ctrl->subVector_startPoint[id+step]; 
			mergeSort(ctrl->vector,ctrl->subVector_startPoint[id], ctrl->subVector_finishPoint[id], 
								  ctrl->subVector_startPoint[id+step] ,ctrl->subVector_finishPoint[id+step]);
			ctrl->subVector_finishPoint[id] = remoteEndIndex;
			printf("%d: %d-%d  (from %d)\n",id,ctrl->subVector_startPoint[id], ctrl->subVector_finishPoint[id],id+step);
			
		}
		layer++;
		step = pow(2,layer);
	}
        printArray(ctrl->vector, 0, VECTOR_SIZE-1);



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
