ifndef IMPERAS_HOME
  IMPERAS_ERROR := $(error "IMPERAS_HOME not defined, please setup Imperas/OVP environment")
endif
IMPERAS_HOME := $(shell getpath.exe "$(IMPERAS_HOME)")

OPTIMISATION?=-O0 -g 

CROSS?=OR1K
SRC?=master.c slave.c
SRCINC?=

INCOBJ=$(patsubst %.c,%.$(CROSS).o,$(SRCINC))
EXE=$(patsubst %.c,%.$(CROSS).elf,$(SRC))
OD=$(patsubst %.c,%.$(CROSS).od,$(SRC))

-include $(IMPERAS_HOME)/lib/$(IMPERAS_ARCH)/CrossCompiler/$(CROSS).makefile.include
ifeq ($($(CROSS)_CC),)
    IMPERAS_ERROR := $(error "Error : $(CROSS)_CC not set. Please check installation of toolchain for $(CROSS)")
endif

all: $(EXE) $(OD)

%.$(CROSS).od: %.$(CROSS).elf
	@    echo "# Objdumping $(CROSS) $@"
	$(V) $($(CROSS)_OBJDUMP) -sdx $^ > $@

%.$(CROSS).elf: %.$(CROSS).o $(INCOBJ)
	@    echo "# Linking $(CROSS) $@"
	$(V) $($(CROSS)_LINK) -o $@ $^ $(IMPERAS_LDFLAGS) -lm

%.$(CROSS).o: %.c
	@    echo "# Compiling $(CROSS) $<"
	$(V) $($(CROSS)_CC) -c -o $@ $< $(OPTIMISATION)
	
clean::
	- rm -f $(EXE) $(OD) *.$(CROSS).o
