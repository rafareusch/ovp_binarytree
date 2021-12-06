ihwnew -name twoProcessorShared
#
# Sub-System 0
#

# add the processor
ihwaddprocessor -type or1k -instancename P0 -semihostname  or1kNewlib -variant generic

# add local memory
ihwaddmemory -type ram -instancename localLow0
ihwaddmemory -type ram -instancename localHigh0

# add the local bus
ihwaddbus -instancename bus0 -addresswidth 32

# add the bus bridge
ihwaddbridge -instancename bridge0

# add connections to bus0
ihwconnect -bus bus0 -instancename P0         -busmasterport "INSTRUCTION"
ihwconnect -bus bus0 -instancename P0         -busmasterport "DATA"
ihwconnect -bus bus0 -instancename localLow0  -busslaveport  "sp0" -loaddress "0x00000000" -hiaddress "0x10ffffff"
ihwconnect -bus bus0 -instancename bridge0    -busslaveport  "sp0" -loaddress "0x11000000" -hiaddress "0x11ffffff"
ihwconnect -bus bus0 -instancename localHigh0 -busslaveport  "sp0" -loaddress "0x12000000" -hiaddress "0xffffffff"

#
# Sub-System 1
#

# add the processor
ihwaddprocessor -type or1k -instancename P1 -semihostname  or1kNewlib -variant generic

# add local memory
ihwaddmemory -type ram -instancename localLow1
ihwaddmemory -type ram -instancename localHigh1

# add the local bus
ihwaddbus -instancename bus1 -addresswidth 32

# add the bus bridge
ihwaddbridge -instancename bridge1

# add connections to bus1
ihwconnect -bus bus1 -instancename P1         -busmasterport "INSTRUCTION"
ihwconnect -bus bus1 -instancename P1         -busmasterport "DATA"
ihwconnect -bus bus1 -instancename localLow1  -busslaveport  "sp1" -loaddress "0x00000000" -hiaddress "0x10ffffff"
ihwconnect -bus bus1 -instancename bridge1    -busslaveport  "sp1" -loaddress "0x11000000" -hiaddress "0x11ffffff"
ihwconnect -bus bus1 -instancename localHigh1 -busslaveport  "sp1" -loaddress "0x12000000" -hiaddress "0xffffffff"

#
# Sub-System 2
#

# add the processor
ihwaddprocessor -type or1k -instancename P2 -semihostname  or1kNewlib -variant generic

# add local memory
ihwaddmemory -type ram -instancename localLow2
ihwaddmemory -type ram -instancename localHigh2

# add the local bus
ihwaddbus -instancename bus2 -addresswidth 32

# add the bus bridge
ihwaddbridge -instancename bridge2

# add connections to bus2
ihwconnect -bus bus2 -instancename P2         -busmasterport "INSTRUCTION"
ihwconnect -bus bus2 -instancename P2         -busmasterport "DATA"
ihwconnect -bus bus2 -instancename localLow2  -busslaveport  "sp2" -loaddress "0x00000000" -hiaddress "0x10ffffff"
ihwconnect -bus bus2 -instancename bridge2    -busslaveport  "sp2" -loaddress "0x11000000" -hiaddress "0x11ffffff"
ihwconnect -bus bus2 -instancename localHigh2 -busslaveport  "sp2" -loaddress "0x12000000" -hiaddress "0xffffffff"

#
# Sub-System 3
#

# add the processor
ihwaddprocessor -type or1k -instancename P3 -semihostname  or1kNewlib -variant generic

# add local memory
ihwaddmemory -type ram -instancename localLow3
ihwaddmemory -type ram -instancename localHigh3

# add the local bus
ihwaddbus -instancename bus3 -addresswidth 32

# add the bus bridge
ihwaddbridge -instancename bridge3

# add connections to bus3
ihwconnect -bus bus3 -instancename P3         -busmasterport "INSTRUCTION"
ihwconnect -bus bus3 -instancename P3         -busmasterport "DATA"
ihwconnect -bus bus3 -instancename localLow3  -busslaveport  "sp3" -loaddress "0x00000000" -hiaddress "0x10ffffff"
ihwconnect -bus bus3 -instancename bridge3    -busslaveport  "sp3" -loaddress "0x11000000" -hiaddress "0x11ffffff"
ihwconnect -bus bus3 -instancename localHigh3 -busslaveport  "sp3" -loaddress "0x12000000" -hiaddress "0xffffffff"

#
# Sub-System 4
#

# add the processor
ihwaddprocessor -type or1k -instancename P4 -semihostname  or1kNewlib -variant generic

# add local memory
ihwaddmemory -type ram -instancename localLow4
ihwaddmemory -type ram -instancename localHigh4

# add the local bus
ihwaddbus -instancename bus4 -addresswidth 32

# add the bus bridge
ihwaddbridge -instancename bridge4

# add connections to bus4
ihwconnect -bus bus4 -instancename P4         -busmasterport "INSTRUCTION"
ihwconnect -bus bus4 -instancename P4         -busmasterport "DATA"
ihwconnect -bus bus4 -instancename localLow4  -busslaveport  "sp4" -loaddress "0x00000000" -hiaddress "0x10ffffff"
ihwconnect -bus bus4 -instancename bridge4    -busslaveport  "sp4" -loaddress "0x11000000" -hiaddress "0x11ffffff"
ihwconnect -bus bus4 -instancename localHigh4 -busslaveport  "sp4" -loaddress "0x12000000" -hiaddress "0xffffffff"

#
# Sub-System 5
#

# add the processor
ihwaddprocessor -type or1k -instancename P5 -semihostname  or1kNewlib -variant generic

# add local memory
ihwaddmemory -type ram -instancename localLow5
ihwaddmemory -type ram -instancename localHigh5

# add the local bus
ihwaddbus -instancename bus5 -addresswidth 32

# add the bus bridge
ihwaddbridge -instancename bridge5

# add connections to bus5
ihwconnect -bus bus5 -instancename P5         -busmasterport "INSTRUCTION"
ihwconnect -bus bus5 -instancename P5         -busmasterport "DATA"
ihwconnect -bus bus5 -instancename localLow5  -busslaveport  "sp5" -loaddress "0x00000000" -hiaddress "0x10ffffff"
ihwconnect -bus bus5 -instancename bridge5    -busslaveport  "sp5" -loaddress "0x11000000" -hiaddress "0x11ffffff"
ihwconnect -bus bus5 -instancename localHigh5 -busslaveport  "sp5" -loaddress "0x12000000" -hiaddress "0xffffffff"

#
# Sub-System 6
#

# add the processor
ihwaddprocessor -type or1k -instancename P6 -semihostname  or1kNewlib -variant generic

# add local memory
ihwaddmemory -type ram -instancename localLow6
ihwaddmemory -type ram -instancename localHigh6

# add the local bus
ihwaddbus -instancename bus6 -addresswidth 32

# add the bus bridge
ihwaddbridge -instancename bridge6

# add connections to bus6
ihwconnect -bus bus6 -instancename P6         -busmasterport "INSTRUCTION"
ihwconnect -bus bus6 -instancename P6         -busmasterport "DATA"
ihwconnect -bus bus6 -instancename localLow6  -busslaveport  "sp6" -loaddress "0x00000000" -hiaddress "0x10ffffff"
ihwconnect -bus bus6 -instancename bridge6    -busslaveport  "sp6" -loaddress "0x11000000" -hiaddress "0x11ffffff"
ihwconnect -bus bus6 -instancename localHigh6 -busslaveport  "sp6" -loaddress "0x12000000" -hiaddress "0xffffffff"

#
# Sub-System 7
#

# add the processor
ihwaddprocessor -type or1k -instancename P7 -semihostname  or1kNewlib -variant generic

# add local memory
ihwaddmemory -type ram -instancename localLow7
ihwaddmemory -type ram -instancename localHigh7

# add the local bus
ihwaddbus -instancename bus7 -addresswidth 32

# add the bus bridge
ihwaddbridge -instancename bridge7

# add connections to bus7
ihwconnect -bus bus7 -instancename P7         -busmasterport "INSTRUCTION"
ihwconnect -bus bus7 -instancename P7         -busmasterport "DATA"
ihwconnect -bus bus7 -instancename localLow7  -busslaveport  "sp7" -loaddress "0x00000000" -hiaddress "0x10ffffff"
ihwconnect -bus bus7 -instancename bridge7    -busslaveport  "sp7" -loaddress "0x11000000" -hiaddress "0x11ffffff"
ihwconnect -bus bus7 -instancename localHigh7 -busslaveport  "sp7" -loaddress "0x12000000" -hiaddress "0xffffffff"

#
# Shared Resources
#

# add the shared memory
ihwaddmemory -type ram -instancename ramShared

# add the shared bus
ihwaddbus -instancename busShare -addresswidth 32

# add connections to busShare
# bridge master connections mapping from processor sub-systems
ihwconnect -bus busShare -instancename bridge0   -busmasterport "mp0" -loaddress "0x00000000" -hiaddress "0x00ffffff" 
ihwconnect -bus busShare -instancename bridge1   -busmasterport "mp1" -loaddress "0x00000000" -hiaddress "0x00ffffff" 
ihwconnect -bus busShare -instancename bridge2   -busmasterport "mp2" -loaddress "0x00000000" -hiaddress "0x00ffffff" 
ihwconnect -bus busShare -instancename bridge3   -busmasterport "mp3" -loaddress "0x00000000" -hiaddress "0x00ffffff" 
ihwconnect -bus busShare -instancename bridge4   -busmasterport "mp4" -loaddress "0x00000000" -hiaddress "0x00ffffff" 
ihwconnect -bus busShare -instancename bridge5   -busmasterport "mp5" -loaddress "0x00000000" -hiaddress "0x00ffffff" 
ihwconnect -bus busShare -instancename bridge6   -busmasterport "mp6" -loaddress "0x00000000" -hiaddress "0x00ffffff" 
ihwconnect -bus busShare -instancename bridge7   -busmasterport "mp7" -loaddress "0x00000000" -hiaddress "0x00ffffff" 
# connection of shared memory
ihwconnect -bus busShare -instancename ramShared -busslaveport  "sp0" -loaddress "0x00000000" -hiaddress "0x00ffffff" 
