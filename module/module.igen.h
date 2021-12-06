/*
 * Copyright (c) 2005-2021 Imperas Software Ltd., www.imperas.com
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied.
 *
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */


////////////////////////////////////////////////////////////////////////////////
//
//                W R I T T E N   B Y   I M P E R A S   I G E N
//
//                             Version 20210408.0
//
////////////////////////////////////////////////////////////////////////////////

#define UNUSED   __attribute__((unused))

// instantiate module components
static OP_CONSTRUCT_FN(instantiateComponents) {



    // Bus bus0

    optBusP bus0_b = opBusNew(mi, "bus0", 32, 0, 0);


    // Bus bus1

    optBusP bus1_b = opBusNew(mi, "bus1", 32, 0, 0);


    // Bus bus2

    optBusP bus2_b = opBusNew(mi, "bus2", 32, 0, 0);


    // Bus bus3

    optBusP bus3_b = opBusNew(mi, "bus3", 32, 0, 0);


    // Bus bus4

    optBusP bus4_b = opBusNew(mi, "bus4", 32, 0, 0);


    // Bus bus5

    optBusP bus5_b = opBusNew(mi, "bus5", 32, 0, 0);


    // Bus bus6

    optBusP bus6_b = opBusNew(mi, "bus6", 32, 0, 0);


    // Bus bus7

    optBusP bus7_b = opBusNew(mi, "bus7", 32, 0, 0);


    // Bus busShare

    optBusP busShare_b = opBusNew(mi, "busShare", 32, 0, 0);


    // Processor P0

    const char *P0_path = opVLNVString(
        0, // use the default VLNV path
        0,
        0,
        "or1k",
        0,
        OP_PROCESSOR,
        1   // report errors
    );

    optProcessorP P0_c = opProcessorNew(
        mi,
        P0_path,
        "P0",
        OP_CONNECTIONS(
            OP_BUS_CONNECTIONS(
                OP_BUS_CONNECT(bus0_b, "INSTRUCTION"),
                OP_BUS_CONNECT(bus0_b, "DATA")
            )
        ),
        OP_PARAMS(
             OP_PARAM_ENUM_SET("variant", "generic")
        )
    );

    const char *or1kNewlib_0_expath = opVLNVString(
        0, // use the default VLNV path
        0,
        0,
        "or1kNewlib",
        0,
        OP_EXTENSION,
        1   // report errors
    );

    opProcessorExtensionNew(
        P0_c,
        or1kNewlib_0_expath,
        "or1kNewlib_0_ex",
        0
    );

    // Processor P1

    const char *P1_path = opVLNVString(
        0, // use the default VLNV path
        0,
        0,
        "or1k",
        0,
        OP_PROCESSOR,
        1   // report errors
    );

    optProcessorP P1_c = opProcessorNew(
        mi,
        P1_path,
        "P1",
        OP_CONNECTIONS(
            OP_BUS_CONNECTIONS(
                OP_BUS_CONNECT(bus1_b, "INSTRUCTION"),
                OP_BUS_CONNECT(bus1_b, "DATA")
            )
        ),
        OP_PARAMS(
             OP_PARAM_UNS32_SET("cpuid", 1)
            ,OP_PARAM_ENUM_SET("variant", "generic")
        )
    );

    const char *or1kNewlib_1_expath = opVLNVString(
        0, // use the default VLNV path
        0,
        0,
        "or1kNewlib",
        0,
        OP_EXTENSION,
        1   // report errors
    );

    opProcessorExtensionNew(
        P1_c,
        or1kNewlib_1_expath,
        "or1kNewlib_1_ex",
        0
    );

    // Processor P2

    const char *P2_path = opVLNVString(
        0, // use the default VLNV path
        0,
        0,
        "or1k",
        0,
        OP_PROCESSOR,
        1   // report errors
    );

    optProcessorP P2_c = opProcessorNew(
        mi,
        P2_path,
        "P2",
        OP_CONNECTIONS(
            OP_BUS_CONNECTIONS(
                OP_BUS_CONNECT(bus2_b, "INSTRUCTION"),
                OP_BUS_CONNECT(bus2_b, "DATA")
            )
        ),
        OP_PARAMS(
             OP_PARAM_UNS32_SET("cpuid", 2)
            ,OP_PARAM_ENUM_SET("variant", "generic")
        )
    );

    const char *or1kNewlib_2_expath = opVLNVString(
        0, // use the default VLNV path
        0,
        0,
        "or1kNewlib",
        0,
        OP_EXTENSION,
        1   // report errors
    );

    opProcessorExtensionNew(
        P2_c,
        or1kNewlib_2_expath,
        "or1kNewlib_2_ex",
        0
    );

    // Processor P3

    const char *P3_path = opVLNVString(
        0, // use the default VLNV path
        0,
        0,
        "or1k",
        0,
        OP_PROCESSOR,
        1   // report errors
    );

    optProcessorP P3_c = opProcessorNew(
        mi,
        P3_path,
        "P3",
        OP_CONNECTIONS(
            OP_BUS_CONNECTIONS(
                OP_BUS_CONNECT(bus3_b, "INSTRUCTION"),
                OP_BUS_CONNECT(bus3_b, "DATA")
            )
        ),
        OP_PARAMS(
             OP_PARAM_UNS32_SET("cpuid", 3)
            ,OP_PARAM_ENUM_SET("variant", "generic")
        )
    );

    const char *or1kNewlib_3_expath = opVLNVString(
        0, // use the default VLNV path
        0,
        0,
        "or1kNewlib",
        0,
        OP_EXTENSION,
        1   // report errors
    );

    opProcessorExtensionNew(
        P3_c,
        or1kNewlib_3_expath,
        "or1kNewlib_3_ex",
        0
    );

    // Processor P4

    const char *P4_path = opVLNVString(
        0, // use the default VLNV path
        0,
        0,
        "or1k",
        0,
        OP_PROCESSOR,
        1   // report errors
    );

    optProcessorP P4_c = opProcessorNew(
        mi,
        P4_path,
        "P4",
        OP_CONNECTIONS(
            OP_BUS_CONNECTIONS(
                OP_BUS_CONNECT(bus4_b, "INSTRUCTION"),
                OP_BUS_CONNECT(bus4_b, "DATA")
            )
        ),
        OP_PARAMS(
             OP_PARAM_UNS32_SET("cpuid", 4)
            ,OP_PARAM_ENUM_SET("variant", "generic")
        )
    );

    const char *or1kNewlib_4_expath = opVLNVString(
        0, // use the default VLNV path
        0,
        0,
        "or1kNewlib",
        0,
        OP_EXTENSION,
        1   // report errors
    );

    opProcessorExtensionNew(
        P4_c,
        or1kNewlib_4_expath,
        "or1kNewlib_4_ex",
        0
    );

    // Processor P5

    const char *P5_path = opVLNVString(
        0, // use the default VLNV path
        0,
        0,
        "or1k",
        0,
        OP_PROCESSOR,
        1   // report errors
    );

    optProcessorP P5_c = opProcessorNew(
        mi,
        P5_path,
        "P5",
        OP_CONNECTIONS(
            OP_BUS_CONNECTIONS(
                OP_BUS_CONNECT(bus5_b, "INSTRUCTION"),
                OP_BUS_CONNECT(bus5_b, "DATA")
            )
        ),
        OP_PARAMS(
             OP_PARAM_UNS32_SET("cpuid", 5)
            ,OP_PARAM_ENUM_SET("variant", "generic")
        )
    );

    const char *or1kNewlib_5_expath = opVLNVString(
        0, // use the default VLNV path
        0,
        0,
        "or1kNewlib",
        0,
        OP_EXTENSION,
        1   // report errors
    );

    opProcessorExtensionNew(
        P5_c,
        or1kNewlib_5_expath,
        "or1kNewlib_5_ex",
        0
    );

    // Processor P6

    const char *P6_path = opVLNVString(
        0, // use the default VLNV path
        0,
        0,
        "or1k",
        0,
        OP_PROCESSOR,
        1   // report errors
    );

    optProcessorP P6_c = opProcessorNew(
        mi,
        P6_path,
        "P6",
        OP_CONNECTIONS(
            OP_BUS_CONNECTIONS(
                OP_BUS_CONNECT(bus6_b, "INSTRUCTION"),
                OP_BUS_CONNECT(bus6_b, "DATA")
            )
        ),
        OP_PARAMS(
             OP_PARAM_UNS32_SET("cpuid", 6)
            ,OP_PARAM_ENUM_SET("variant", "generic")
        )
    );

    const char *or1kNewlib_6_expath = opVLNVString(
        0, // use the default VLNV path
        0,
        0,
        "or1kNewlib",
        0,
        OP_EXTENSION,
        1   // report errors
    );

    opProcessorExtensionNew(
        P6_c,
        or1kNewlib_6_expath,
        "or1kNewlib_6_ex",
        0
    );

    // Processor P7

    const char *P7_path = opVLNVString(
        0, // use the default VLNV path
        0,
        0,
        "or1k",
        0,
        OP_PROCESSOR,
        1   // report errors
    );

    optProcessorP P7_c = opProcessorNew(
        mi,
        P7_path,
        "P7",
        OP_CONNECTIONS(
            OP_BUS_CONNECTIONS(
                OP_BUS_CONNECT(bus7_b, "INSTRUCTION"),
                OP_BUS_CONNECT(bus7_b, "DATA")
            )
        ),
        OP_PARAMS(
             OP_PARAM_UNS32_SET("cpuid", 7)
            ,OP_PARAM_ENUM_SET("variant", "generic")
        )
    );

    const char *or1kNewlib_7_expath = opVLNVString(
        0, // use the default VLNV path
        0,
        0,
        "or1kNewlib",
        0,
        OP_EXTENSION,
        1   // report errors
    );

    opProcessorExtensionNew(
        P7_c,
        or1kNewlib_7_expath,
        "or1kNewlib_7_ex",
        0
    );

    // Memory localLow0

    opMemoryNew(
        mi,
        "localLow0",
        OP_PRIV_RWX,
        (0x10ffffffULL) - (0x0ULL),
        OP_CONNECTIONS(
            OP_BUS_CONNECTIONS(
                OP_BUS_CONNECT(bus0_b, "sp0", .slave=1, .addrLo=0x0ULL, .addrHi=0x10ffffffULL)
            )
        ),
        0
    );

    // Memory localHigh0

    opMemoryNew(
        mi,
        "localHigh0",
        OP_PRIV_RWX,
        (0xffffffffULL) - (0x12000000ULL),
        OP_CONNECTIONS(
            OP_BUS_CONNECTIONS(
                OP_BUS_CONNECT(bus0_b, "sp0", .slave=1, .addrLo=0x12000000ULL, .addrHi=0xffffffffULL)
            )
        ),
        0
    );

    // Memory localLow1

    opMemoryNew(
        mi,
        "localLow1",
        OP_PRIV_RWX,
        (0x10ffffffULL) - (0x0ULL),
        OP_CONNECTIONS(
            OP_BUS_CONNECTIONS(
                OP_BUS_CONNECT(bus1_b, "sp1", .slave=1, .addrLo=0x0ULL, .addrHi=0x10ffffffULL)
            )
        ),
        0
    );

    // Memory localHigh1

    opMemoryNew(
        mi,
        "localHigh1",
        OP_PRIV_RWX,
        (0xffffffffULL) - (0x12000000ULL),
        OP_CONNECTIONS(
            OP_BUS_CONNECTIONS(
                OP_BUS_CONNECT(bus1_b, "sp1", .slave=1, .addrLo=0x12000000ULL, .addrHi=0xffffffffULL)
            )
        ),
        0
    );

    // Memory localLow2

    opMemoryNew(
        mi,
        "localLow2",
        OP_PRIV_RWX,
        (0x10ffffffULL) - (0x0ULL),
        OP_CONNECTIONS(
            OP_BUS_CONNECTIONS(
                OP_BUS_CONNECT(bus2_b, "sp2", .slave=1, .addrLo=0x0ULL, .addrHi=0x10ffffffULL)
            )
        ),
        0
    );

    // Memory localHigh2

    opMemoryNew(
        mi,
        "localHigh2",
        OP_PRIV_RWX,
        (0xffffffffULL) - (0x12000000ULL),
        OP_CONNECTIONS(
            OP_BUS_CONNECTIONS(
                OP_BUS_CONNECT(bus2_b, "sp2", .slave=1, .addrLo=0x12000000ULL, .addrHi=0xffffffffULL)
            )
        ),
        0
    );

    // Memory localLow3

    opMemoryNew(
        mi,
        "localLow3",
        OP_PRIV_RWX,
        (0x10ffffffULL) - (0x0ULL),
        OP_CONNECTIONS(
            OP_BUS_CONNECTIONS(
                OP_BUS_CONNECT(bus3_b, "sp3", .slave=1, .addrLo=0x0ULL, .addrHi=0x10ffffffULL)
            )
        ),
        0
    );

    // Memory localHigh3

    opMemoryNew(
        mi,
        "localHigh3",
        OP_PRIV_RWX,
        (0xffffffffULL) - (0x12000000ULL),
        OP_CONNECTIONS(
            OP_BUS_CONNECTIONS(
                OP_BUS_CONNECT(bus3_b, "sp3", .slave=1, .addrLo=0x12000000ULL, .addrHi=0xffffffffULL)
            )
        ),
        0
    );

    // Memory localLow4

    opMemoryNew(
        mi,
        "localLow4",
        OP_PRIV_RWX,
        (0x10ffffffULL) - (0x0ULL),
        OP_CONNECTIONS(
            OP_BUS_CONNECTIONS(
                OP_BUS_CONNECT(bus4_b, "sp4", .slave=1, .addrLo=0x0ULL, .addrHi=0x10ffffffULL)
            )
        ),
        0
    );

    // Memory localHigh4

    opMemoryNew(
        mi,
        "localHigh4",
        OP_PRIV_RWX,
        (0xffffffffULL) - (0x12000000ULL),
        OP_CONNECTIONS(
            OP_BUS_CONNECTIONS(
                OP_BUS_CONNECT(bus4_b, "sp4", .slave=1, .addrLo=0x12000000ULL, .addrHi=0xffffffffULL)
            )
        ),
        0
    );

    // Memory localLow5

    opMemoryNew(
        mi,
        "localLow5",
        OP_PRIV_RWX,
        (0x10ffffffULL) - (0x0ULL),
        OP_CONNECTIONS(
            OP_BUS_CONNECTIONS(
                OP_BUS_CONNECT(bus5_b, "sp5", .slave=1, .addrLo=0x0ULL, .addrHi=0x10ffffffULL)
            )
        ),
        0
    );

    // Memory localHigh5

    opMemoryNew(
        mi,
        "localHigh5",
        OP_PRIV_RWX,
        (0xffffffffULL) - (0x12000000ULL),
        OP_CONNECTIONS(
            OP_BUS_CONNECTIONS(
                OP_BUS_CONNECT(bus5_b, "sp5", .slave=1, .addrLo=0x12000000ULL, .addrHi=0xffffffffULL)
            )
        ),
        0
    );

    // Memory localLow6

    opMemoryNew(
        mi,
        "localLow6",
        OP_PRIV_RWX,
        (0x10ffffffULL) - (0x0ULL),
        OP_CONNECTIONS(
            OP_BUS_CONNECTIONS(
                OP_BUS_CONNECT(bus6_b, "sp6", .slave=1, .addrLo=0x0ULL, .addrHi=0x10ffffffULL)
            )
        ),
        0
    );

    // Memory localHigh6

    opMemoryNew(
        mi,
        "localHigh6",
        OP_PRIV_RWX,
        (0xffffffffULL) - (0x12000000ULL),
        OP_CONNECTIONS(
            OP_BUS_CONNECTIONS(
                OP_BUS_CONNECT(bus6_b, "sp6", .slave=1, .addrLo=0x12000000ULL, .addrHi=0xffffffffULL)
            )
        ),
        0
    );

    // Memory localLow7

    opMemoryNew(
        mi,
        "localLow7",
        OP_PRIV_RWX,
        (0x10ffffffULL) - (0x0ULL),
        OP_CONNECTIONS(
            OP_BUS_CONNECTIONS(
                OP_BUS_CONNECT(bus7_b, "sp7", .slave=1, .addrLo=0x0ULL, .addrHi=0x10ffffffULL)
            )
        ),
        0
    );

    // Memory localHigh7

    opMemoryNew(
        mi,
        "localHigh7",
        OP_PRIV_RWX,
        (0xffffffffULL) - (0x12000000ULL),
        OP_CONNECTIONS(
            OP_BUS_CONNECTIONS(
                OP_BUS_CONNECT(bus7_b, "sp7", .slave=1, .addrLo=0x12000000ULL, .addrHi=0xffffffffULL)
            )
        ),
        0
    );

    // Memory ramShared

    opMemoryNew(
        mi,
        "ramShared",
        OP_PRIV_RWX,
        (0xffffffULL) - (0x0ULL),
        OP_CONNECTIONS(
            OP_BUS_CONNECTIONS(
                OP_BUS_CONNECT(busShare_b, "sp0", .slave=1, .addrLo=0x0ULL, .addrHi=0xffffffULL)
            )
        ),
        0
    );

    // Bridge bridge0

    opBridgeNew(
        mi,
        "bridge0",
        OP_CONNECTIONS(
            OP_BUS_CONNECTIONS(
                OP_BUS_CONNECT(busShare_b, "mp0", .addrLo=0x0ULL, .addrHi=0xffffffULL),
                OP_BUS_CONNECT(bus0_b, "sp0", .slave=1, .addrLo=0x11000000ULL, .addrHi=0x11ffffffULL)
            )
        ),
        0
    );

    // Bridge bridge1

    opBridgeNew(
        mi,
        "bridge1",
        OP_CONNECTIONS(
            OP_BUS_CONNECTIONS(
                OP_BUS_CONNECT(busShare_b, "mp1", .addrLo=0x0ULL, .addrHi=0xffffffULL),
                OP_BUS_CONNECT(bus1_b, "sp1", .slave=1, .addrLo=0x11000000ULL, .addrHi=0x11ffffffULL)
            )
        ),
        0
    );

    // Bridge bridge2

    opBridgeNew(
        mi,
        "bridge2",
        OP_CONNECTIONS(
            OP_BUS_CONNECTIONS(
                OP_BUS_CONNECT(busShare_b, "mp2", .addrLo=0x0ULL, .addrHi=0xffffffULL),
                OP_BUS_CONNECT(bus2_b, "sp2", .slave=1, .addrLo=0x11000000ULL, .addrHi=0x11ffffffULL)
            )
        ),
        0
    );

    // Bridge bridge3

    opBridgeNew(
        mi,
        "bridge3",
        OP_CONNECTIONS(
            OP_BUS_CONNECTIONS(
                OP_BUS_CONNECT(busShare_b, "mp3", .addrLo=0x0ULL, .addrHi=0xffffffULL),
                OP_BUS_CONNECT(bus3_b, "sp3", .slave=1, .addrLo=0x11000000ULL, .addrHi=0x11ffffffULL)
            )
        ),
        0
    );

    // Bridge bridge4

    opBridgeNew(
        mi,
        "bridge4",
        OP_CONNECTIONS(
            OP_BUS_CONNECTIONS(
                OP_BUS_CONNECT(busShare_b, "mp4", .addrLo=0x0ULL, .addrHi=0xffffffULL),
                OP_BUS_CONNECT(bus4_b, "sp4", .slave=1, .addrLo=0x11000000ULL, .addrHi=0x11ffffffULL)
            )
        ),
        0
    );

    // Bridge bridge5

    opBridgeNew(
        mi,
        "bridge5",
        OP_CONNECTIONS(
            OP_BUS_CONNECTIONS(
                OP_BUS_CONNECT(busShare_b, "mp5", .addrLo=0x0ULL, .addrHi=0xffffffULL),
                OP_BUS_CONNECT(bus5_b, "sp5", .slave=1, .addrLo=0x11000000ULL, .addrHi=0x11ffffffULL)
            )
        ),
        0
    );

    // Bridge bridge6

    opBridgeNew(
        mi,
        "bridge6",
        OP_CONNECTIONS(
            OP_BUS_CONNECTIONS(
                OP_BUS_CONNECT(busShare_b, "mp6", .addrLo=0x0ULL, .addrHi=0xffffffULL),
                OP_BUS_CONNECT(bus6_b, "sp6", .slave=1, .addrLo=0x11000000ULL, .addrHi=0x11ffffffULL)
            )
        ),
        0
    );

    // Bridge bridge7

    opBridgeNew(
        mi,
        "bridge7",
        OP_CONNECTIONS(
            OP_BUS_CONNECTIONS(
                OP_BUS_CONNECT(busShare_b, "mp7", .addrLo=0x0ULL, .addrHi=0xffffffULL),
                OP_BUS_CONNECT(bus7_b, "sp7", .slave=1, .addrLo=0x11000000ULL, .addrHi=0x11ffffffULL)
            )
        ),
        0
    );

}

optModuleAttr modelAttrs = {
    .versionString        = OP_VERSION,
    .type                 = OP_MODULE,
    .name                 = MODULE_NAME,
    .objectSize           = sizeof(optModuleObject),
    .releaseStatus        = OP_UNSET,
    .purpose              = OP_PP_BAREMETAL,
    .visibility           = OP_VISIBLE,
    .vlnv          = {
        .vendor  = "defaultVendor",
        .library = "work",
        .name    = "twoProcessorShared",
        .version = "1.0"
    },
    .constructCB          = moduleConstructor,
    .preSimulateCB        = modulePreSimulate,
    .simulateCB           = moduleSimulateStart,
    .postSimulateCB       = modulePostSimulate,
    .destructCB           = moduleDestruct,
};
