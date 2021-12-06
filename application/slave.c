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
    int id = impProcessorId();
    
    while(ctrl->subVector_status[id]!=START){ /* waits the master command */ }
    printf("Processor %d starting it's task!\n", id);

    // sorts the vector
    quickSort(-,-,-);
 
    // merge process -- if needed

    ...


    // informs the system that this processor is done!
    ctrl->subVector_status[id] = DONE;

    return 0;
}
