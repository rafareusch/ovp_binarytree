#!/bin/bash

# Parameters
SIZE=$1
SIZE=$(($SIZE-1))

rm module.op.tcl

echo "ihwnew -name twoProcessorShared" >> module.op.tcl
for i in $(seq 0 $SIZE);
do
    echo "#" >> module.op.tcl
    echo "# Sub-System "$i >> module.op.tcl
    echo "#" >> module.op.tcl
    echo "" >> module.op.tcl
    echo "# add the processor" >> module.op.tcl
    echo "ihwaddprocessor -type or1k -instancename P"$i" -semihostname  or1kNewlib -variant generic" >> module.op.tcl
    echo "" >> module.op.tcl
    echo "# add local memory" >> module.op.tcl
    echo "ihwaddmemory -type ram -instancename localLow"$i"" >> module.op.tcl
    echo "ihwaddmemory -type ram -instancename localHigh"$i"" >> module.op.tcl
    echo "" >> module.op.tcl
    echo "# add the local bus" >> module.op.tcl
    echo "ihwaddbus -instancename bus"$i" -addresswidth "32"" >> module.op.tcl
    echo "" >> module.op.tcl
    echo "# add the bus bridge" >> module.op.tcl
    echo "ihwaddbridge -instancename bridge"$i"" >> module.op.tcl
    echo "" >> module.op.tcl
    echo "# add connections to bus"$i"" >> module.op.tcl
    echo "ihwconnect -bus bus"$i" -instancename P"$i"         -busmasterport \"INSTRUCTION\"" >> module.op.tcl
    echo "ihwconnect -bus bus"$i" -instancename P"$i"         -busmasterport \"DATA\"" >> module.op.tcl
    echo "ihwconnect -bus bus"$i" -instancename localLow"$i"  -busslaveport  \"sp"$i"\" -loaddress \"0x00000000\" -hiaddress \"0x10ffffff\"" >> module.op.tcl
    echo "ihwconnect -bus bus"$i" -instancename bridge"$i"    -busslaveport  \"sp"$i"\" -loaddress \"0x11000000\" -hiaddress \"0x11ffffff\"" >> module.op.tcl
    echo "ihwconnect -bus bus"$i" -instancename localHigh"$i" -busslaveport  \"sp"$i"\" -loaddress \"0x12000000\" -hiaddress \"0xffffffff\"" >> module.op.tcl
    echo "" >> module.op.tcl
done
echo "#" >> module.op.tcl
echo "# Shared Resources" >> module.op.tcl
echo "#" >> module.op.tcl
echo "" >> module.op.tcl
echo "# add the shared memory" >> module.op.tcl
echo "ihwaddmemory -type ram -instancename ramShared" >> module.op.tcl
echo "" >> module.op.tcl
echo "# add the shared bus" >> module.op.tcl
echo "ihwaddbus -instancename busShare -addresswidth "32"" >> module.op.tcl
echo "" >> module.op.tcl
echo "# add connections to busShare" >> module.op.tcl
echo "# bridge master connections mapping from processor sub-systems" >> module.op.tcl
for i in $(seq 0 $SIZE);
do
    echo "ihwconnect -bus busShare -instancename bridge"$i"   -busmasterport \"mp"$i"\" -loaddress \"0x00000000\" -hiaddress \"0x00ffffff\" " >> module.op.tcl
done
echo "# connection of shared memory" >> module.op.tcl
echo "ihwconnect -bus busShare -instancename ramShared -busslaveport  \"sp0\" -loaddress \"0x00000000\" -hiaddress \"0x00ffffff\" " >> module.op.tcl
