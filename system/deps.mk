C_SRCS +=  \
		system/src/system_ADuCM362.c \
		system/src/cmsis/boot_vectors_362.c \
		system/src/cortexm/_initialize_hardware.c \
		system/src/cortexm/_reset_hardware.c \
		system/src/cortexm/exception_handlers.c \
		system/src/newlib/_exit.c  \
		system/src/newlib/_sbrk.c  \
		system/src/newlib/_startup.c \
		system/src/newlib/_syscalls.c \
		system/src/newlib/assert.c


INCS +=  -Isystem/include -Isystem/include/cmsis -Isystem/include/arm