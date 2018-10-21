C_SRCS +=  \
		freeRTOS/croutine.c \
 		freeRTOS/event_groups.c \
 		freeRTOS/list.c \
 		freeRTOS/queue.c \
 		freeRTOS/stream_buffer.c \
 		freeRTOS/tasks.c \
 		freeRTOS/timers.c \
 		freeRTOS/port/port.c \
 		freeRTOS/mem/heap_3.c


INCS +=  -IfreeRTOS/include -IfreeRTOS/port -IfreeRTOS/config
