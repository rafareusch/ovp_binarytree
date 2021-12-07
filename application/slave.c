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
    int id = impProcessorId();
    
    while(ctrl->subVector_status[id]!=START){ /* waits the master command */ }
    printf("Processor %d starting it's task!\n", id);

    // sorts the vector
    quickSort(ctrl->vector,ctrl->subVector_startPoint[id],ctrl->subVector_finishPoint[id]);

    
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

    // informs the system that this processor is done!
	printf("%d: Stopped\n");
    ctrl->subVector_status[id] = DONE;

    return 0;
}
