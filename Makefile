TARGET_NAME = test_app
RM := rm -rf

# Needed libs
include system/deps.mk
include freeRTOS/deps.mk
DEFINE_DEVICE=__ADUCM360__
LD_FILE=ADuCM360
SECONDARY_FLASH += $(TARGET_NAME).hex

#FLASH_INFO = system/src/cmsis/boot_vectors_362
FLASH_INFO = system/src/cmsis/boot_vectors_360
SRCS +=  i2c/i2c_exec.cpp
C_SRCS +=  app/main.c app/rtos_def.c
OBJECTS += $(SRCS:.cpp=.o)
OBJECTS += $(C_SRCS:.c=.o)


# All Target
all: clean_map $(TARGET_NAME).map $(TARGET_NAME).elf $(TARGET_NAME).hex

.PHONY: clean_map
clean_map: 
	rm -f $(TARGET_NAME).map

%.o: %.c
	@echo 'CC $<'
	@arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -D__ADUCM360__ -DDEBUG $(INCS) -std=gnu11 -Wno-missing-prototypes -Wno-padded -Wno-missing-declarations -MMD -MP -MF"$(@:%.o=%.d)" -c -o "$@" "$<"

%.o: %.cpp
	@echo 'C++ $<'
	@arm-none-eabi-g++ -mcpu=cortex-m3 -mthumb -O0 -ffreestanding -fsingle-precision-constant -fno-move-loop-invariants  -g3 -D__ADUCM360__ -DDEBUG -DTRACE  $(INCS) -std=gnu++1y -fabi-version=0 -fno-exceptions -fno-rtti -fno-use-cxa-atexit -fno-threadsafe-statics -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	

# Tool invocations
$(TARGET_NAME).map: $(OBJECTS)
	@echo 'LD $@ -- first time'
	@arm-none-eabi-g++ -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -T ld/$(LD_FILE).ld  -Xlinker --gc-sections -L"../ldscripts" -Wl,-Map,"$(TARGET_NAME).map"  --specs=nosys.specs  -u _printf_float -u _scanf_float -o "$(TARGET_NAME).elf" $(OBJECTS) $(LIBS)

$(TARGET_NAME).elf: $(OBJECTS)
	@echo 'LD $@ -- with flash info'
	@arm-none-eabi-g++ -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -T ld/mem.ld -T ld/sections.ld -nostartfiles -Xlinker --gc-sections -L"../ldscripts" -Wl,-Map,"$(TARGET_NAME).map" --specs=nano.specs  -u _printf_float -u _scanf_float -o "$(TARGET_NAME).elf" $(OBJECTS) $(LIBS)

$(TARGET_NAME).hex: $(TARGET_NAME).elf
	@echo 'Invoking: GNU ARM Cross Create Flash Image'
	arm-none-eabi-objcopy -O ihex "$(TARGET_NAME).elf"  "$(TARGET_NAME).hex"
	@echo 'Finished building: $@'
	@echo ' '

clean:
	rm -rf $(OBJECTS).o $(TARGET_NAME).map $(TARGET_NAME).elf $(TARGET_NAME).hex
	-@echo ' '


.PHONY: all clean dependents

