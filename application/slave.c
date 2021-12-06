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
    quickSort(ctrl->vector,ctrl->subVector_finishPoint-ctrl->subVector_size,ctrl->subVector_finishPoint);
 
    // merge process -- if needed
    // while (layer <= NUM_LAYERS)
	// {
		
	// 	if (slave_id % step != 0){
	// 		Echo("Slave is not on layer...");
	// 		break;
	// 	} 
	// 	else if ( slave_id != 0 && isPair(num_slaves_layer) && isPair(slave_id / step)){
	// 		recv_int = ReceiveFromSlave(slave_id+step);
	// 		Echo("Received from");
	// 		Echo(itoh(slave_id+step));
	// 		Echo("data:");
	// 		Echo(itoh(recv_int));
	// 		Echo(" ");
	// 		// APPLICATION 
	// 		// in this example the slave will sum received value with our internal sum
	// 		// your application must handle this received value.
	// 		internalSum += recv_int;
	// 	}
	// 	else if ( slave_id != 0 && isPair(num_slaves_layer) && isPair(slave_id / step) == FALSE ){
	// 		msg_payload[0] = internalSum;
	// 		sendIntToSlave(msg_payload,slave_id-step);
	// 		Echo("Sent to");
	// 		Echo(itoh(slave_id-step));
	// 		Echo("sum:");
	// 		Echo(itoh(internalSum));
	// 		Echo(" ");
	// 	}
	// 	else if( slave_id == 0 && num_slaves_layer > 1 ){
	// 		recv_int = ReceiveFromSlave(slave_id+step);
	// 		Echo("Received from");
	// 		Echo(itoh(slave_id+step));
	// 		Echo("data:");
	// 		Echo(itoh(recv_int));
	// 		Echo(" ");
	// 		// APPLICATION 
	// 		// in this example the slave will sum received value with our internal sum
	// 		// your application must handle this received value.
	// 		internalSum += recv_int;
	// 	} 
	// 	else if(  slave_id == 0 && num_slaves_layer <= 1 ){
	// 		Echo("Sending to master.. sum:");
	// 		Echo(itoh(internalSum));
	// 		// package application result to payload and send to master
	// 		msg_payload[0] = internalSum;
	// 		sendIntToMaster(msg_payload);
	// 		Echo(" ");
	// 		break;
	// 	}

	// 	num_slaves_layer = (NUM_SLAVES/(2^layer));
	// 	step = NUM_SLAVES / num_slaves_layer;
	// 	layer++;
	// }


    // informs the system that this processor is done!
    ctrl->subVector_status[id] = DONE;

    return 0;
}
