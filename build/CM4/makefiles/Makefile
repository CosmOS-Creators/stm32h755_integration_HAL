##################################################################
##             	 GENERATED FILE BY COSMOS CUSTOMBOX             ##
##################################################################
## VERSION 1.0.0                                                ##
## Date: 1.8.2020                                               ##
##################################################################
##################################################################
##                    START OF THE MAKEFILE                     ##
##################################################################
LINE=|--------------------------------------------------------------------|
##################################################################
##                            TARGET			       		    ##
##################################################################
TARGET	?= CM4
##################################################################
##					GNU ARM EMBEDDED TOOLCHAIN					##
##################################################################
CC=arm-none-eabi-gcc
CXX=arm-none-eabi-g++
LD=arm-none-eabi-ld
AR=arm-none-eabi-ar
AS=arm-none-eabi-as
CP=arm-none-eabi-objcopy
OD=arm-none-eabi-objdump
NM=arm-none-eabi-nm
SIZE=arm-none-eabi-size
A2L=arm-none-eabi-addr2line
##################################################################
##					    PROJECT DIRECTORIES					    ##
##################################################################
ROOT		 		= 	../../../../..
MCU 				=  	IntegrationLayer
OS 					= 	$(ROOT)/Cosmos
OS_CORE		 		= 	$(ROOT)/Cosmos/Core
OS_IL		 		= 	$(ROOT)/Cosmos/$(MCU)/CIL
M4_CORE	 			= 	$(ROOT)/CM4
M4_APP_LAYER		=	$(ROOT)/Cosmos/ApplicationLayer
SHARED_DRIVERS		= 	$(ROOT)/Drivers
COMMON				= 	$(ROOT)/Common
OBJECT_DIR	 		= 	$(ROOT)/Cosmos/$(MCU)/build/CM4/out/obj
BIN_DIR		 		= 	$(ROOT)/Cosmos/$(MCU)/build/CM4/bin
MAP_FILE			= 	$(ROOT)/Cosmos/$(MCU)/build/CM4/map/m4core.map
DISASSEMBLY_DIR		=   $(ROOT)/Cosmos/$(MCU)/build/CM4/disassembly
##################################################################
##					     ASSEMBLY SOURCES					    ##
##################################################################
ASOURCES = $(M4_CORE)/Core/Startup/startup_stm32h755zitx.s
##################################################################
##					     C SOURCES FILES					    ##
##################################################################
# Search path and source files for the OS sources
OS_SRC	 			= $(shell find $(OS) -name \*.c)
# Search path and source files for the m4 drivers
M4_SRC	 			= $(shell find $(M4_CORE) -name \*.c)
# Source files for shared drivers
SHARED_DRIVERS_SRC	= $(shell find $(SHARED_DRIVERS) -name \*.c)
# Source files for common sources
COMMON_SRC	= $(shell find $(COMMON) -name \*.c)
##################################################################
##					     C++ SOURCES FILES					    ##
##################################################################
# Search path and source files for the OS sources
OS_SRC_CPP	 			= $(shell find $(OS) -name \*.[c]pp)
# Search path and source files for the m4 drivers
M4_SRC_CPP	 			= $(shell find $(M4_CORE) -name \*.[c]pp)
# Source files for shared drivers
SHARED_DRIVERS_SRC_CPP	= $(shell find $(SHARED_DRIVERS) -name \*.[c]pp)
# Source files for common sources
COMMON_SRC_CPP	= $(shell find $(COMMON) -name \*.[c]pp)
##################################################################
##					   C SOURCES FILES PATHS					##
##################################################################
CSOURCES =  	$(M4_SRC) 					\
				$(OS_SRC) 					\
				$(SHARED_DRIVERS_SRC) 		\
				$(COMMON_SRC) 
##################################################################
##					   C++ SOURCES FILES PATHS					##
##################################################################
CXXSOURCES = 	$(M4_SRC_CPP) 				\
				$(OS_SRC_CPP) 				\
				$(SHARED_DRIVERS_SRC_CPP)	\
				$(COMMON_SRC_CPP)  	
##################################################################
##					   LINKER SCRIPT PATH						##
##################################################################
LDSCRIPT=$(M4_CORE)/STM32H755ZITX_FLASH.ld
##################################################################
##					    HEADER FILES PATHS					    ##
##################################################################	
INCLUDE_DIRS	 =	$(M4_CORE)/Core/Inc								\
					$(M4_CORE)/Drivers/STM32H7xx_HAL_Driver/Inc		\
					$(SHARED_DRIVERS)/STM32H7xx_HAL_Driver/Inc		\
					$(SHARED_DRIVERS)/CMSIS/Device/ST/STM32H7xx/Include	\
					$(SHARED_DRIVERS)/CMSIS/Include					\
					$(OS_CORE)/cosmosTypes/inc 						\
					$(OS_CORE)/os/inc								\
					$(OS_CORE)/cosmosApi/inc						\
					$(OS_CORE)/switch/inc							\
					$(OS_CORE)/permission/inc						\
					$(OS_CORE)/sysDefs/inc							\
					$(OS_CORE)/memory/inc							\
					$(OS_CORE)/deviceIO/inc							\
					$(OS_CORE)/scheduler/inc						\
					$(OS_CORE)/thread/inc							\
					$(OS_CORE)/task/inc								\
					$(OS_CORE)/stack/inc							\
					$(OS_CORE)/program/inc							\
					$(OS_CORE)/core/inc								\
					$(OS_CORE)/buffer/inc							\
					$(OS_CORE)/sysCalls/inc							\
					$(OS_CORE)/sysJobs/inc							\
					$(OS_CORE)/route/inc							\
					$(OS_CORE)/cosmosAssert/inc						\
					$(OS_CORE)/schedulable/inc						\
					$(M4_APP_LAYER)/inc								\
					$(OS_IL)/inc
##################################################################
##					       VPATH CONFIG					        ##
##################################################################
vpath %.s $(sort $(dir $(ASOURCES)))
vpath %.cpp $(sort $(dir $(CXXSOURCES)))
vpath %.c $(sort $(dir $(CSOURCES)))
##################################################################
##					         OBJECTS					        ##
##################################################################
OBJECTS=$(addsuffix .o,$(addprefix $(OBJECT_DIR)/,$(notdir $(basename $(ASOURCES)))))
OBJECTS+=$(addsuffix .o,$(addprefix $(OBJECT_DIR)/,$(notdir $(basename $(CSOURCES)))))
OBJECTS+=$(addsuffix .o,$(addprefix $(OBJECT_DIR)/,$(notdir $(basename $(CXXSOURCES)))))
##################################################################
##					      FLAGS CONFIG					        ##
##################################################################
MCFLAGS= -mcpu=cortex-m4 -mthumb -ffunction-sections -fdata-sections -Wall -Wextra -fstack-usage -MMD -MP -MF --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -g3 -ffixed-r9
OPTIMIZE = -O0 
DEFS= -D CORE_CM4=1 -D STM32H755xx=1 -D USE_HAL_DRIVER=1 -D ARCH_32BIT -D ADDR_32BIT
CFLAGS=-c $(MCFLAGS) $(DEFS) $(OPTIMIZE) $(addprefix -I,$(INCLUDE_DIRS)) -std=gnu11
CXXFLAGS=-c $(MCFLAGS) $(DEFS) $(OPTIMIZE) $(addprefix -I,$(INCLUDE_DIRS)) -std=c++14
CXXFLAGS+=-U__STRICT_ANSI__ 
LDFLAGS =-T $(LDSCRIPT) $(MCFLAGS) $(ARCH_FLAGS) $(LTO_FLAGS) $(DEBUG_FLAGS) --specs=nosys.specs -Wl,-Map=$(MAP_FILE) -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -lstdc++ -lsupc++ -Wl,--end-group
##################################################################
##					    OUTPUT FILES PATHS					    ##
##################################################################
TARGET_ELF=$(BIN_DIR)/$(TARGET).elf
TARGET_HEX=$(BIN_DIR)/$(TARGET).hex
TARGET_DISASSEMBLY=$(DISASSEMBLY_DIR)/$(TARGET).list
##################################################################
##					      BUILD RULES					        ##
##################################################################
$(TARGET_DISASSEMBLY): $(TARGET_ELF)
	$(OD) -h -S $(TARGET_ELF) > $(TARGET_DISASSEMBLY)
	@echo -e "\e[1;32m$(LINE)\e[0m"
	@echo -e "\e[1;32m$(INDENT)                    The ELF file parameters are\e[0m"
	@echo -e "\e[1;32m$(LINE)\e[0m"
	$(SIZE) $(TARGET_ELF)
	@echo -e "\e[1;32m$(LINE)\e[0m"
	@echo -e "\e[1;32m$(INDENT)              CosmOS was successfully built for $(TARGET)\e[0m"
	@echo -e "\e[1;32m$(LINE)\e[0m"
	@echo -e "\e[1;34mDisassembly was generated into the: $(DISASSEMBLY_DIR)\e[0m"
	@echo -e "\e[1;34mELF file was generated into the: $(BIN_DIR)\e[0m"

$(TARGET_HEX): $(TARGET_ELF)
	$(CP) -O ihex --set-start 0x8100000 $< $@

$(TARGET_ELF): $(OBJECTS)
	@echo -e "\e[1;32m$(LINE)\e[0m"
	@echo -e "\e[1;32m                   Linking phase for $(TARGET) starts\e[0m"
	@echo -e "\e[1;32m$(LINE)\e[0m"
	$(CXX) -o $@ $^ $(LDFLAGS)
	@echo -e "\e[1;32m$(LINE)\e[0m"
	@echo -e "\e[1;32m                Object dump phase for $(TARGET) starts\e[0m"
	@echo -e "\e[1;32m$(LINE)\e[0m"

$(OBJECT_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@echo -e "FOUND: \e $<"
	@echo -e "Compiling c++ code \e $(notdir $<)"
	@$(CXX) -c -o $@ $(CXXFLAGS) $<

$(OBJECT_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo -e "FOUND: \e $<"
	@echo -e "Compiling c code \e $(notdir $<)"
	@$(CC) -c -o $@ $(CFLAGS) $<

$(OBJECT_DIR)/%.o: %.s
	@mkdir -p $(dir $@)
	@echo -e "FOUND: \e $<"
	@echo -e "Compiling assembly code \e $(notdir $<)"
	@$(CC) -c -o $@ $(CFLAGS) $<
##################################################################
##					         RECIPES					        ##
##################################################################
.PHONY: all flash clean

clean:
	@echo -e "\n\e[1;32m$(LINE)\e[0m"
	@echo -e "\e[1;32m                   CosmOS clean for $(TARGET) starts\e[0m"
	@echo -e "\e[1;32m$(LINE)\e[0m"
	rm -f $(OBJECTS) $(TARGET_ELF) $(TARGET_HEX) $(MAP_FILE)
	@echo -e "\e[1;32m$(LINE)\e[0m"
	@echo -e "\e[1;32m                   CosmOS build for $(TARGET) starts\e[0m"
	@echo -e "\e[1;32m$(LINE)\e[0m"

flash: $(TARGET_HEX)
	STM32_Programmer_CLI -c port=SWD -d $(TARGET_HEX) -rst

all: $(TARGET_HEX)
	@echo -e "\e[1;32m$(LINE)\e[0m"
	@echo -e "\e[1;32m                   CosmOS build for $(TARGET) starts\e[0m"
	@echo -e "\e[1;32m$(LINE)\e[0m"

##################################################################
##                     END OF THE MAKEFILE                      ##
##################################################################