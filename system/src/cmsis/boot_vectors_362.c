#include "cortexm/ExceptionHandlers.h"

extern unsigned int _estack;

typedef void
(* const pHandler)(void);

struct jumpTable
{
	unsigned int branch_instr_0;
	unsigned int branch_instr_1;
	pHandler           handler_0;
	pHandler           handler_1;
};

void __attribute__((weak))
Default_Handler(void);

void Reset_Handler               (void) __attribute__ ((weak));
void NMI_Handler                 (void) __attribute__ ((weak, alias("Default_Handler")));
void HardFault_Handler           (void) __attribute__ ((weak, alias("Default_Handler")));
void MemManage_Handler           (void) __attribute__ ((weak, alias("Default_Handler")));
void BusFault_Handler            (void) __attribute__ ((weak, alias("Default_Handler")));
void UsageFault_Handler          (void) __attribute__ ((weak, alias("Default_Handler")));
void SVC_Handler                 (void) __attribute__ ((weak, alias("Default_Handler")));
void DebugMon_Handler            (void) __attribute__ ((weak, alias("Default_Handler")));
void PendSV_Handler              (void) __attribute__ ((weak, alias("Default_Handler")));
void SysTick_Handler             (void) __attribute__ ((weak, alias("Default_Handler")));

void WakeUp_Int_Handler          (void) __attribute__ ((weak, alias ("Default_Handler"))); //[ 0]
void Ext_Int0_Handler            (void) __attribute__ ((weak, alias ("Default_Handler"))); //[ 1]
void Ext_Int1_Handler            (void) __attribute__ ((weak, alias ("Default_Handler"))); //[ 2]
void Ext_Int2_Handler            (void) __attribute__ ((weak, alias ("Default_Handler"))); //[ 3]
void Ext_Int3_Handler            (void) __attribute__ ((weak, alias ("Default_Handler"))); //[ 4]
void Ext_Int4_Handler            (void) __attribute__ ((weak, alias ("Default_Handler"))); //[ 5]
void Ext_Int5_Handler            (void) __attribute__ ((weak, alias ("Default_Handler"))); //[ 6]
void Ext_Int6_Handler            (void) __attribute__ ((weak, alias ("Default_Handler"))); //[ 7]
void Ext_Int7_Handler            (void) __attribute__ ((weak, alias ("Default_Handler"))); //[ 8]
void WDog_Tmr_Int_Handler        (void) __attribute__ ((weak, alias ("Default_Handler"))); //[ 9]
void GP_Tmr0_Int_Handler         (void) __attribute__ ((weak, alias ("Default_Handler"))); //[11]
void GP_Tmr1_Int_Handler         (void) __attribute__ ((weak, alias ("Default_Handler"))); //[12]
void ADC0_Int_Handler            (void) __attribute__ ((weak, alias ("Default_Handler"))); //[13]
void ADC1_Int_Handler            (void) __attribute__ ((weak, alias ("Default_Handler"))); //[14]
void SINC2_Int_Handler           (void) __attribute__ ((weak, alias ("Default_Handler"))); //[15]
void Flsh_Int_Handler            (void) __attribute__ ((weak, alias ("Default_Handler"))); //[16]
void UART_Int_Handler            (void) __attribute__ ((weak, alias ("Default_Handler"))); //[17]
void SPI0_Int_Handler            (void) __attribute__ ((weak, alias ("Default_Handler"))); //[18]
void SPI1_Int_Handler            (void) __attribute__ ((weak, alias ("Default_Handler"))); //[19]
void I2C0_Slave_Int_Handler      (void) __attribute__ ((weak, alias ("Default_Handler"))); //[20]
void I2C0_Master_Int_Handler     (void) __attribute__ ((weak, alias ("Default_Handler"))); //[21]
void DMA_Err_Int_Handler         (void) __attribute__ ((weak, alias ("Default_Handler"))); //[22]
void DMA_SPI1_TX_Int_Handler     (void) __attribute__ ((weak, alias ("Default_Handler"))); //[23]
void DMA_SPI1_RX_Int_Handler     (void) __attribute__ ((weak, alias ("Default_Handler"))); //[24]
void DMA_UART_TX_Int_Handler     (void) __attribute__ ((weak, alias ("Default_Handler"))); //[25]
void DMA_UART_RX_Int_Handler     (void) __attribute__ ((weak, alias ("Default_Handler"))); //[26]
void DMA_I2C0_STX_Int_Handler    (void) __attribute__ ((weak, alias ("Default_Handler"))); //[27]
void DMA_I2C0_SRX_Int_Handler    (void) __attribute__ ((weak, alias ("Default_Handler"))); //[28]
void DMA_I2C0_MTX_Int_Handler    (void) __attribute__ ((weak, alias ("Default_Handler"))); //[29]
void DMA_I2C0_MRX_Int_Handler    (void) __attribute__ ((weak, alias ("Default_Handler"))); //[30]
void DMA_DAC_Out_Int_Handler     (void) __attribute__ ((weak, alias ("Default_Handler"))); //[31]
void DMA_ADC0_Int_Handler        (void) __attribute__ ((weak, alias ("Default_Handler"))); //[32]
void DMA_ADC1_Int_Handler        (void) __attribute__ ((weak, alias ("Default_Handler"))); //[33]
void DMA_SINC2_Int_Handler       (void) __attribute__ ((weak, alias ("Default_Handler"))); //[34]
void DMA_SPI0_TX_Int_Handler     (void) __attribute__ ((weak, alias ("Default_Handler"))); //[35]
void DMA_SPI0_RX_Int_Handler     (void) __attribute__ ((weak, alias ("Default_Handler"))); //[36]
void DMA_UART1_TX_Int_Handler    (void) __attribute__ ((weak, alias ("Default_Handler"))); //[37]
void DMA_UART1_RX_Int_Handler    (void) __attribute__ ((weak, alias ("Default_Handler"))); //[38]
void DMA_UART2_TX_Int_Handler    (void) __attribute__ ((weak, alias ("Default_Handler"))); //[39]
void DMA_UART2_RX_Int_Handler    (void) __attribute__ ((weak, alias ("Default_Handler"))); //[40]
void PWMTRIP_Int_Handler         (void) __attribute__ ((weak, alias ("Default_Handler"))); //[41]
void PWM0_Int_Handler            (void) __attribute__ ((weak, alias ("Default_Handler"))); //[42]
void PWM1_Int_Handler            (void) __attribute__ ((weak, alias ("Default_Handler"))); //[43]
void PWM2_Int_Handler            (void) __attribute__ ((weak, alias ("Default_Handler"))); //[44]
void UART1_Int_Handler           (void) __attribute__ ((weak, alias ("Default_Handler"))); //[47]
void UART2_Int_Handler           (void) __attribute__ ((weak, alias ("Default_Handler"))); //[48]
// Define common jump table locations (vectors shared for all applications)

#define COMMON_JUMP_TABLE  0x001801
// The vector table.
#define COMMON_Reset_Handler  (pHandler)(COMMON_JUMP_TABLE + 0x00)                            // The reset handler
#define COMMON_NMI_Handler  (pHandler)(COMMON_JUMP_TABLE + 0x04)                              // The NMI handler
#define COMMON_HardFault_Handler  (pHandler)(COMMON_JUMP_TABLE + 0x10)                        // The hard fault handler
#define COMMON_MemManage_Handler  (pHandler)(COMMON_JUMP_TABLE + 0x14)                        // The MPU fault handler
#define COMMON_BusFault_Handler  (pHandler)(COMMON_JUMP_TABLE + 0x20)// The bus fault handler
#define COMMON_UsageFault_Handler  (pHandler)(COMMON_JUMP_TABLE + 0x24)// The usage fault handler
#define COMMON_SVC_Handler  (pHandler)(COMMON_JUMP_TABLE + 0x30)                              // SVCall handler
#define COMMON_DebugMon_Handler  (pHandler)(COMMON_JUMP_TABLE + 0x34)                         // Debug monitor handler
#define COMMON_PendSV_Handler  (pHandler)(COMMON_JUMP_TABLE + 0x40)                           // The PendSV handler
#define COMMON_SysTick_Handler  (pHandler)(COMMON_JUMP_TABLE + 0x44)   // The SysTick handler

#define COMMON_WakeUp_Int_Handler (pHandler)(COMMON_JUMP_TABLE + 0x50)  // [0]
#define COMMON_Ext_Int0_Handler (pHandler)(COMMON_JUMP_TABLE + 0x54)
#define COMMON_Ext_Int1_Handler (pHandler)(COMMON_JUMP_TABLE + 0x60)
#define COMMON_Ext_Int2_Handler (pHandler)(COMMON_JUMP_TABLE + 0x64)
#define COMMON_Ext_Int3_Handler (pHandler)(COMMON_JUMP_TABLE + 0x70)
#define COMMON_Ext_Int4_Handler (pHandler)(COMMON_JUMP_TABLE + 0x74)
#define COMMON_Ext_Int5_Handler (pHandler)(COMMON_JUMP_TABLE + 0x80)
#define COMMON_Ext_Int6_Handler (pHandler)(COMMON_JUMP_TABLE + 0x84)
#define COMMON_Ext_Int7_Handler (pHandler)(COMMON_JUMP_TABLE + 0x90)
#define COMMON_WDog_Tmr_Int_Handler (pHandler)(COMMON_JUMP_TABLE + 0x94)
#define COMMON_GP_Tmr0_Int_Handler (pHandler)(COMMON_JUMP_TABLE + 0xa0)
#define COMMON_GP_Tmr1_Int_Handler (pHandler)(COMMON_JUMP_TABLE + 0xa4)
#define COMMON_ADC0_Int_Handler (pHandler)(COMMON_JUMP_TABLE + 0xb0)
#define COMMON_ADC1_Int_Handler (pHandler)(COMMON_JUMP_TABLE + 0xb4)
#define COMMON_SINC2_Int_Handler (pHandler)(COMMON_JUMP_TABLE + 0xc0)
#define COMMON_Flsh_Int_Handler (pHandler)(COMMON_JUMP_TABLE + 0xc4)
#define COMMON_UART_Int_Handler (pHandler)(COMMON_JUMP_TABLE + 0xd0)
#define COMMON_SPI0_Int_Handler (pHandler)(COMMON_JUMP_TABLE + 0xd4)
#define COMMON_SPI1_Int_Handler (pHandler)(COMMON_JUMP_TABLE + 0xe0)
#define COMMON_I2C0_Slave_Int_Handler (pHandler)(COMMON_JUMP_TABLE + 0xe4)
#define COMMON_I2C0_Master_Int_Handler (pHandler)(COMMON_JUMP_TABLE + 0xf0)
#define COMMON_DMA_Err_Int_Handler (pHandler)(COMMON_JUMP_TABLE + 0xf40)
#define COMMON_DMA_SPI1_TX_Int_Handler (pHandler)(COMMON_JUMP_TABLE + 0x100)
#define COMMON_DMA_SPI1_RX_Int_Handler (pHandler)(COMMON_JUMP_TABLE + 0x104)
#define COMMON_DMA_UART_TX_Int_Handler (pHandler)(COMMON_JUMP_TABLE + 0x110)
#define COMMON_DMA_UART_RX_Int_Handler (pHandler)(COMMON_JUMP_TABLE + 0x114)
#define COMMON_DMA_I2C0_STX_Int_Handler (pHandler)(COMMON_JUMP_TABLE + 0x120)
#define COMMON_DMA_I2C0_SRX_Int_Handler (pHandler)(COMMON_JUMP_TABLE + 0x124)
#define COMMON_DMA_I2C0_MTX_Int_Handler (pHandler)(COMMON_JUMP_TABLE + 0x130)
#define COMMON_DMA_I2C0_MRX_Int_Handler (pHandler)(COMMON_JUMP_TABLE + 0x134)
#define COMMON_DMA_DAC_Out_Int_Handler (pHandler)(COMMON_JUMP_TABLE + 0x140)
#define COMMON_DMA_ADC0_Int_Handler (pHandler)(COMMON_JUMP_TABLE + 0x144)
#define COMMON_DMA_ADC1_Int_Handler (pHandler)(COMMON_JUMP_TABLE + 0x150)
#define COMMON_DMA_SINC2_Int_Handler (pHandler)(COMMON_JUMP_TABLE + 0x154)
#define COMMON_DMA_SPI0_TX_Int_Handler (pHandler)(COMMON_JUMP_TABLE + 0x160)
#define COMMON_DMA_SPI0_RX_Int_Handler (pHandler)(COMMON_JUMP_TABLE + 0x164)
#define COMMON_DMA_UART1_TX_Int_Handler (pHandler)(COMMON_JUMP_TABLE + 0x170)
#define COMMON_DMA_UART1_RX_Int_Handler (pHandler)(COMMON_JUMP_TABLE + 0x174)
#define COMMON_DMA_UART2_TX_Int_Handler (pHandler)(COMMON_JUMP_TABLE + 0x180)
#define COMMON_DMA_UART2_RX_Int_Handler (pHandler)(COMMON_JUMP_TABLE + 0x184)
#define COMMON_PWMTRIP_Int_Handler (pHandler)(COMMON_JUMP_TABLE + 0x190)
#define COMMON_PWM0_Int_Handler (pHandler)(COMMON_JUMP_TABLE + 0x194)
#define COMMON_PWM1_Int_Handler (pHandler)(COMMON_JUMP_TABLE + 0x1a0)
#define COMMON_PWM2_Int_Handler (pHandler)(COMMON_JUMP_TABLE + 0x1a4)
#define COMMON_UART1_Int_Handler (pHandler)(COMMON_JUMP_TABLE + 0x1b0)
#define COMMON_UART2_Int_Handler (pHandler)(COMMON_JUMP_TABLE + 0x1b4)   // [48]


__attribute__ ((section(".isr_vector")))
pHandler __isr_vectors[] = {
   //
   (pHandler) &_estack,                          // The initial stack pointer
   Reset_Handler,
   COMMON_NMI_Handler,                              // The NMI handler
   COMMON_HardFault_Handler,                        // The hard fault handler
   COMMON_MemManage_Handler,                        // The MPU fault handler
   COMMON_BusFault_Handler,					 // The bus fault handler
   COMMON_UsageFault_Handler,                // The usage fault handler
   0,                                        // Reserved
   0,                                        // Reserved
   0,                                        // Reserved
   0,                                        // Reserved
   COMMON_SVC_Handler,                              // SVCall handler
   COMMON_DebugMon_Handler,                         // Debug monitor handler
   0,                                        // Reserved
   COMMON_PendSV_Handler,                           // The PendSV handler
   COMMON_SysTick_Handler,                          // The SysTick handler

   // ----------------------------------------------------------------------
   // ADuCM363 vectors
   COMMON_WakeUp_Int_Handler,        //[ 0]
   COMMON_Ext_Int0_Handler,          //[ 1]
   COMMON_Ext_Int1_Handler,          //[ 2]
   COMMON_Ext_Int2_Handler,          //[ 3]
   COMMON_Ext_Int3_Handler,          //[ 4]
   COMMON_Ext_Int4_Handler,          //[ 5]
   COMMON_Ext_Int5_Handler,          //[ 6]
   COMMON_Ext_Int6_Handler,          //[ 7]
   COMMON_Ext_Int7_Handler,          //[ 8]
   COMMON_WDog_Tmr_Int_Handler,      //[ 9]
   0,                         //[10]
   COMMON_GP_Tmr0_Int_Handler,       //[11]
   COMMON_GP_Tmr1_Int_Handler,       //[12]
   COMMON_ADC0_Int_Handler,          //[13]
   COMMON_ADC1_Int_Handler,          //[14]
   COMMON_SINC2_Int_Handler,         //[15]
   COMMON_Flsh_Int_Handler,          //[16]
   COMMON_UART_Int_Handler,          //[17]
   COMMON_SPI0_Int_Handler,          //[18]
   COMMON_SPI1_Int_Handler,          //[19]
   COMMON_I2C0_Slave_Int_Handler,    //[20]
   COMMON_I2C0_Master_Int_Handler,   //[21]
   COMMON_DMA_Err_Int_Handler,       //[22]
   COMMON_DMA_SPI1_TX_Int_Handler,   //[23]
   COMMON_DMA_SPI1_RX_Int_Handler,   //[24]
   COMMON_DMA_UART_TX_Int_Handler,   //[25]
   COMMON_DMA_UART_RX_Int_Handler,   //[26]
   COMMON_DMA_I2C0_STX_Int_Handler,  //[27]
   COMMON_DMA_I2C0_SRX_Int_Handler,  //[28]
   COMMON_DMA_I2C0_MTX_Int_Handler,  //[29]
   COMMON_DMA_I2C0_MRX_Int_Handler,  //[30]
   COMMON_DMA_DAC_Out_Int_Handler,   //[31]
   COMMON_DMA_ADC0_Int_Handler,      //[32]
   COMMON_DMA_ADC1_Int_Handler,      //[33]
   COMMON_DMA_SINC2_Int_Handler,     //[34]
   COMMON_DMA_SPI0_TX_Int_Handler,   //[35]
   COMMON_DMA_SPI0_RX_Int_Handler,   //[36]
   COMMON_DMA_UART1_TX_Int_Handler,  //[37]
   COMMON_DMA_UART1_RX_Int_Handler,  //[38]
   COMMON_DMA_UART2_TX_Int_Handler,  //[39]
   COMMON_DMA_UART2_RX_Int_Handler,  //[40]
   COMMON_PWMTRIP_Int_Handler,       //[41]
   COMMON_PWM0_Int_Handler,          //[42]
   COMMON_PWM1_Int_Handler,          //[43]
   COMMON_PWM2_Int_Handler,          //[44]
   0,                         //[45]
   0,                         //[46]
   UART1_Int_Handler,         //[47]
   COMMON_UART2_Int_Handler,         //[48]
   0                          //[49]
};

void __attribute__ ((section(".after_vectors")))
Default_Handler(void)
{
   while (1) {
   }
}

#define LOAD_PC 0x47004801

__attribute__ ((section(".jmp_table")))
struct jumpTable __jmp_table[] = {
		{ LOAD_PC, LOAD_PC, Reset_Handler, NMI_Handler},
		{ LOAD_PC, LOAD_PC, HardFault_Handler, MemManage_Handler},
		{ LOAD_PC, LOAD_PC, BusFault_Handler, UsageFault_Handler},
		{ LOAD_PC, LOAD_PC, SVC_Handler, DebugMon_Handler},
		{ LOAD_PC, LOAD_PC, PendSV_Handler, SysTick_Handler},
		{ LOAD_PC, LOAD_PC, WakeUp_Int_Handler, Ext_Int0_Handler},
		{ LOAD_PC, LOAD_PC, Ext_Int1_Handler, Ext_Int2_Handler},
		{ LOAD_PC, LOAD_PC, Ext_Int3_Handler, Ext_Int4_Handler},
		{ LOAD_PC, LOAD_PC, Ext_Int5_Handler, Ext_Int6_Handler},
		{ LOAD_PC, LOAD_PC, Ext_Int7_Handler, WDog_Tmr_Int_Handler},
		{ LOAD_PC, LOAD_PC, GP_Tmr0_Int_Handler, GP_Tmr1_Int_Handler},
		{ LOAD_PC, LOAD_PC, ADC0_Int_Handler, ADC1_Int_Handler},
		{ LOAD_PC, LOAD_PC, SINC2_Int_Handler, Flsh_Int_Handler},
		{ LOAD_PC, LOAD_PC, UART_Int_Handler, SPI0_Int_Handler},
		{ LOAD_PC, LOAD_PC, SPI1_Int_Handler, I2C0_Slave_Int_Handler},
		{ LOAD_PC, LOAD_PC, I2C0_Master_Int_Handler, DMA_Err_Int_Handler},
		{ LOAD_PC, LOAD_PC, DMA_SPI1_TX_Int_Handler, DMA_SPI1_RX_Int_Handler},
		{ LOAD_PC, LOAD_PC, DMA_UART_TX_Int_Handler, DMA_UART_RX_Int_Handler},
		{ LOAD_PC, LOAD_PC, DMA_I2C0_STX_Int_Handler, DMA_I2C0_SRX_Int_Handler},
		{ LOAD_PC, LOAD_PC, DMA_I2C0_MTX_Int_Handler, DMA_I2C0_MRX_Int_Handler},
		{ LOAD_PC, LOAD_PC, DMA_DAC_Out_Int_Handler, DMA_ADC0_Int_Handler},
		{ LOAD_PC, LOAD_PC, DMA_ADC1_Int_Handler, DMA_SINC2_Int_Handler},

		{ LOAD_PC, LOAD_PC, DMA_SPI0_TX_Int_Handler, DMA_SPI0_RX_Int_Handler},
		{ LOAD_PC, LOAD_PC, DMA_UART1_TX_Int_Handler, DMA_UART1_RX_Int_Handler},
		{ LOAD_PC, LOAD_PC, DMA_UART2_TX_Int_Handler, DMA_UART2_RX_Int_Handler},


		{ LOAD_PC, LOAD_PC, PWMTRIP_Int_Handler, PWM0_Int_Handler},
		{ LOAD_PC, LOAD_PC, PWM1_Int_Handler, PWM2_Int_Handler},
		{ LOAD_PC, LOAD_PC, UART1_Int_Handler, UART2_Int_Handler},
};

#define MAGIC_ID   0xBEA70000 /* Make this record invalid  */
#define APP_START  0x00008b45
#ifndef APP_END
#define APP_END 0x1000
#warning Please recompile again with valid APP_END
#endif

__attribute__ ((section(".app_desc")))
uint32_t application_descriptors[] = {
 MAGIC_ID,
 APP_START,
 APP_END
};
