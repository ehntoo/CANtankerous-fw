/******************************************************************************
 * @file     startup_ARMCM33.c
 * @brief    CMSIS-Core Device Startup File for Cortex-M33 Device
 * @version  V2.1.0
 * @date     16. December 2020
 ******************************************************************************/
/*
 * Copyright (c) 2009-2020 Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "fsl_device_registers.h"
#include "cmsis_compiler.h"
#include "system_ARMCM33.h"

/*----------------------------------------------------------------------------
  External References
 *----------------------------------------------------------------------------*/
extern uint32_t __INITIAL_SP;
extern uint32_t __STACK_LIMIT;
#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
extern uint32_t __STACK_SEAL;
#endif

extern __NO_RETURN void __PROGRAM_START(void);

/*----------------------------------------------------------------------------
  Internal References
 *----------------------------------------------------------------------------*/
__NO_RETURN void Reset_Handler  (void);
            void Default_Handler(void);

/*----------------------------------------------------------------------------
  Exception / Interrupt Handler
 *----------------------------------------------------------------------------*/
/* Exceptions */
void NMI_Handler            (void) __attribute__ ((weak, alias("Default_Handler")));
void HardFault_Handler      (void) __attribute__ ((weak));
void MemManage_Handler      (void) __attribute__ ((weak, alias("Default_Handler")));
void BusFault_Handler       (void) __attribute__ ((weak, alias("Default_Handler")));
void UsageFault_Handler     (void) __attribute__ ((weak, alias("Default_Handler")));
void SecureFault_Handler    (void) __attribute__ ((weak, alias("Default_Handler")));
void SVC_Handler            (void) __attribute__ ((weak, alias("Default_Handler")));
void DebugMon_Handler       (void) __attribute__ ((weak, alias("Default_Handler")));
void PendSV_Handler         (void) __attribute__ ((weak, alias("Default_Handler")));
void SysTick_Handler        (void) __attribute__ ((weak, alias("Default_Handler")));

void WDT_BOD_DriverIRQHandler               (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA0_DriverIRQHandler                  (void) __attribute__ ((weak, alias("Default_Handler")));
void GINT0_DriverIRQHandler                 (void) __attribute__ ((weak, alias("Default_Handler")));
void GINT1_DriverIRQHandler                 (void) __attribute__ ((weak, alias("Default_Handler")));
void PIN_INT0_DriverIRQHandler              (void) __attribute__ ((weak, alias("Default_Handler")));
void PIN_INT1_DriverIRQHandler              (void) __attribute__ ((weak, alias("Default_Handler")));
void PIN_INT2_DriverIRQHandler              (void) __attribute__ ((weak, alias("Default_Handler")));
void PIN_INT3_DriverIRQHandler              (void) __attribute__ ((weak, alias("Default_Handler")));
void UTICK0_DriverIRQHandler                (void) __attribute__ ((weak, alias("Default_Handler")));
void MRT0_DriverIRQHandler                  (void) __attribute__ ((weak, alias("Default_Handler")));
void CTIMER0_DriverIRQHandler               (void) __attribute__ ((weak, alias("Default_Handler")));
void CTIMER1_DriverIRQHandler               (void) __attribute__ ((weak, alias("Default_Handler")));
void SCT0_DriverIRQHandler                  (void) __attribute__ ((weak, alias("Default_Handler")));
void CTIMER3_DriverIRQHandler               (void) __attribute__ ((weak, alias("Default_Handler")));
void FLEXCOMM0_DriverIRQHandler             (void) __attribute__ ((weak, alias("Default_Handler")));
void FLEXCOMM1_DriverIRQHandler             (void) __attribute__ ((weak, alias("Default_Handler")));
void FLEXCOMM2_DriverIRQHandler             (void) __attribute__ ((weak, alias("Default_Handler")));
void FLEXCOMM3_DriverIRQHandler             (void) __attribute__ ((weak, alias("Default_Handler")));
void FLEXCOMM4_DriverIRQHandler             (void) __attribute__ ((weak, alias("Default_Handler")));
void FLEXCOMM5_DriverIRQHandler             (void) __attribute__ ((weak, alias("Default_Handler")));
void FLEXCOMM6_DriverIRQHandler             (void) __attribute__ ((weak, alias("Default_Handler")));
void FLEXCOMM7_DriverIRQHandler             (void) __attribute__ ((weak, alias("Default_Handler")));
void ADC0_DriverIRQHandler                  (void) __attribute__ ((weak, alias("Default_Handler")));
void Reserved39_DriverIRQHandler            (void) __attribute__ ((weak, alias("Default_Handler")));
void ACMP_DriverIRQHandler                  (void) __attribute__ ((weak, alias("Default_Handler")));
void Reserved41_DriverIRQHandler            (void) __attribute__ ((weak, alias("Default_Handler")));
void Reserved42_DriverIRQHandler            (void) __attribute__ ((weak, alias("Default_Handler")));
void USB0_NEEDCLK_DriverIRQHandler          (void) __attribute__ ((weak, alias("Default_Handler")));
void USB0_DriverIRQHandler                  (void) __attribute__ ((weak, alias("Default_Handler")));
void RTC_DriverIRQHandler                   (void) __attribute__ ((weak, alias("Default_Handler")));
void Reserved46_DriverIRQHandler            (void) __attribute__ ((weak, alias("Default_Handler")));
void Reserved47_DriverIRQHandler            (void) __attribute__ ((weak, alias("Default_Handler")));
void PIN_INT4_DriverIRQHandler              (void) __attribute__ ((weak, alias("Default_Handler")));
void PIN_INT5_DriverIRQHandler              (void) __attribute__ ((weak, alias("Default_Handler")));
void PIN_INT6_DriverIRQHandler              (void) __attribute__ ((weak, alias("Default_Handler")));
void PIN_INT7_DriverIRQHandler              (void) __attribute__ ((weak, alias("Default_Handler")));
void CTIMER2_DriverIRQHandler               (void) __attribute__ ((weak, alias("Default_Handler")));
void CTIMER4_DriverIRQHandler               (void) __attribute__ ((weak, alias("Default_Handler")));
void OS_EVENT_DriverIRQHandler              (void) __attribute__ ((weak, alias("Default_Handler")));
void Reserved55_DriverIRQHandler            (void) __attribute__ ((weak, alias("Default_Handler")));
void Reserved56_DriverIRQHandler            (void) __attribute__ ((weak, alias("Default_Handler")));
void Reserved57_DriverIRQHandler            (void) __attribute__ ((weak, alias("Default_Handler")));
void Reserved58_DriverIRQHandler            (void) __attribute__ ((weak, alias("Default_Handler")));
void CAN0_IRQ0_DriverIRQHandler             (void) __attribute__ ((weak, alias("Default_Handler")));
void CAN0_IRQ1_DriverIRQHandler             (void) __attribute__ ((weak, alias("Default_Handler")));
void Reserved61_DriverIRQHandler            (void) __attribute__ ((weak, alias("Default_Handler")));
void USB1_PHY_DriverIRQHandler              (void) __attribute__ ((weak, alias("Default_Handler")));
void USB1_DriverIRQHandler                  (void) __attribute__ ((weak, alias("Default_Handler")));
void USB1_NEEDCLK_DriverIRQHandler          (void) __attribute__ ((weak, alias("Default_Handler")));
void SEC_HYPERVISOR_CALL_DriverIRQHandler   (void) __attribute__ ((weak, alias("Default_Handler")));
void SEC_GPIO_INT0_IRQ0_DriverIRQHandler    (void) __attribute__ ((weak, alias("Default_Handler")));
void SEC_GPIO_INT0_IRQ1_DriverIRQHandler    (void) __attribute__ ((weak, alias("Default_Handler")));
void PLU_DriverIRQHandler                   (void) __attribute__ ((weak, alias("Default_Handler")));
void SEC_VIO_DriverIRQHandler               (void) __attribute__ ((weak, alias("Default_Handler")));
void Reserved70_DriverIRQHandler            (void) __attribute__ ((weak, alias("Default_Handler")));
void CASER_DriverIRQHandler                 (void) __attribute__ ((weak, alias("Default_Handler")));
void PUF_DriverIRQHandler                   (void) __attribute__ ((weak, alias("Default_Handler")));
void Reserved73_DriverIRQHandler            (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_DriverIRQHandler                  (void) __attribute__ ((weak, alias("Default_Handler")));
void FLEXCOMM8_DriverIRQHandler             (void) __attribute__ ((weak, alias("Default_Handler")));
void CDOG_DriverIRQHandler                  (void) __attribute__ ((weak, alias("Default_Handler")));

//*****************************************************************************
// Default application exception handlers. Override the ones here by defining
// your own handler routines in your application code. These routines call
// driver exception handlers or IntDefaultHandler() if no driver exception
// handler is included.
//*****************************************************************************
__attribute__((weak)) void WDT_BOD_IRQHandler(void)
{   WDT_BOD_DriverIRQHandler();
}

__attribute__((weak)) void DMA0_IRQHandler(void)
{   DMA0_DriverIRQHandler();
}


__attribute__((weak)) void GINT0_IRQHandler(void)
{   GINT0_DriverIRQHandler();
}

__attribute__((weak)) void GINT1_IRQHandler(void)
{   GINT1_DriverIRQHandler();
}

__attribute__((weak)) void PIN_INT0_IRQHandler(void)
{   PIN_INT0_DriverIRQHandler();
}

__attribute__((weak)) void PIN_INT1_IRQHandler(void)
{   PIN_INT1_DriverIRQHandler();
}

__attribute__((weak)) void PIN_INT2_IRQHandler(void)
{   PIN_INT2_DriverIRQHandler();
}

__attribute__((weak)) void PIN_INT3_IRQHandler(void)
{   PIN_INT3_DriverIRQHandler();
}

__attribute__((weak)) void UTICK0_IRQHandler(void)
{   UTICK0_DriverIRQHandler();
}

__attribute__((weak)) void MRT0_IRQHandler(void)
{   MRT0_DriverIRQHandler();
}

__attribute__((weak)) void CTIMER0_IRQHandler(void)
{   CTIMER0_DriverIRQHandler();
}

__attribute__((weak)) void CTIMER1_IRQHandler(void)
{   CTIMER1_DriverIRQHandler();
}

__attribute__((weak)) void SCT0_IRQHandler(void)
{   SCT0_DriverIRQHandler();
}

__attribute__((weak)) void CTIMER3_IRQHandler(void)
{   CTIMER3_DriverIRQHandler();
}

__attribute__((weak)) void FLEXCOMM0_IRQHandler(void)
{   FLEXCOMM0_DriverIRQHandler();
}

__attribute__((weak)) void FLEXCOMM1_IRQHandler(void)
{   FLEXCOMM1_DriverIRQHandler();
}

__attribute__((weak)) void FLEXCOMM2_IRQHandler(void)
{   FLEXCOMM2_DriverIRQHandler();
}

__attribute__((weak)) void FLEXCOMM3_IRQHandler(void)
{   FLEXCOMM3_DriverIRQHandler();
}

__attribute__((weak)) void FLEXCOMM4_IRQHandler(void)
{   FLEXCOMM4_DriverIRQHandler();
}

__attribute__((weak)) void FLEXCOMM5_IRQHandler(void)
{   FLEXCOMM5_DriverIRQHandler();
}

__attribute__((weak)) void FLEXCOMM6_IRQHandler(void)
{   FLEXCOMM6_DriverIRQHandler();
}

__attribute__((weak)) void FLEXCOMM7_IRQHandler(void)
{   FLEXCOMM7_DriverIRQHandler();
}

__attribute__((weak)) void ADC0_IRQHandler(void)
{   ADC0_DriverIRQHandler();
}

__attribute__((weak)) void Reserved39_IRQHandler(void)
{   Reserved39_DriverIRQHandler();
}

__attribute__((weak)) void ACMP_IRQHandler(void)
{   ACMP_DriverIRQHandler();
}

__attribute__((weak)) void Reserved41_IRQHandler(void)
{   Reserved41_DriverIRQHandler();
}

__attribute__((weak)) void Reserved42_IRQHandler(void)
{   Reserved42_DriverIRQHandler();
}

__attribute__((weak)) void USB0_NEEDCLK_IRQHandler(void)
{   USB0_NEEDCLK_DriverIRQHandler();
}

__attribute__((weak)) void USB0_IRQHandler(void)
{   USB0_DriverIRQHandler();
}

__attribute__((weak)) void RTC_IRQHandler(void)
{   RTC_DriverIRQHandler();
}

__attribute__((weak)) void Reserved46_IRQHandler(void)
{   Reserved46_DriverIRQHandler();
}

__attribute__((weak)) void Reserved47_IRQHandler(void)
{   Reserved47_DriverIRQHandler();
}

__attribute__((weak)) void PIN_INT4_IRQHandler(void)
{   PIN_INT4_DriverIRQHandler();
}

__attribute__((weak)) void PIN_INT5_IRQHandler(void)
{   PIN_INT5_DriverIRQHandler();
}

__attribute__((weak)) void PIN_INT6_IRQHandler(void)
{   PIN_INT6_DriverIRQHandler();
}

__attribute__((weak)) void PIN_INT7_IRQHandler(void)
{   PIN_INT7_DriverIRQHandler();
}

__attribute__((weak)) void CTIMER2_IRQHandler(void)
{   CTIMER2_DriverIRQHandler();
}

__attribute__((weak)) void CTIMER4_IRQHandler(void)
{   CTIMER4_DriverIRQHandler();
}

__attribute__((weak)) void OS_EVENT_IRQHandler(void)
{   OS_EVENT_DriverIRQHandler();
}

__attribute__((weak)) void Reserved55_IRQHandler(void)
{   Reserved55_DriverIRQHandler();
}

__attribute__((weak)) void Reserved56_IRQHandler(void)
{   Reserved56_DriverIRQHandler();
}

__attribute__((weak)) void Reserved57_IRQHandler(void)
{   Reserved57_DriverIRQHandler();
}

__attribute__((weak)) void Reserved58_IRQHandler(void)
{   Reserved58_DriverIRQHandler();
}

__attribute__((weak)) void CAN0_IRQ0_IRQHandler(void)
{   CAN0_IRQ0_DriverIRQHandler();
}

__attribute__((weak)) void CAN0_IRQ1_IRQHandler(void)
{   CAN0_IRQ1_DriverIRQHandler();
}

__attribute__((weak)) void Reserved61_IRQHandler(void)
{   Reserved61_DriverIRQHandler();
}

__attribute__((weak)) void USB1_PHY_IRQHandler(void)
{   USB1_PHY_DriverIRQHandler();
}

__attribute__((weak)) void USB1_IRQHandler(void)
{   USB1_DriverIRQHandler();
}

__attribute__((weak)) void USB1_NEEDCLK_IRQHandler(void)
{   USB1_NEEDCLK_DriverIRQHandler();
}

__attribute__((weak)) void SEC_HYPERVISOR_CALL_IRQHandler(void)
{   SEC_HYPERVISOR_CALL_DriverIRQHandler();
}

__attribute__((weak)) void SEC_GPIO_INT0_IRQ0_IRQHandler(void)
{   SEC_GPIO_INT0_IRQ0_DriverIRQHandler();
}

__attribute__((weak)) void SEC_GPIO_INT0_IRQ1_IRQHandler(void)
{   SEC_GPIO_INT0_IRQ1_DriverIRQHandler();
}

__attribute__((weak)) void PLU_IRQHandler(void)
{   PLU_DriverIRQHandler();
}

__attribute__((weak)) void SEC_VIO_IRQHandler(void)
{   SEC_VIO_DriverIRQHandler();
}

__attribute__((weak)) void Reserved70_IRQHandler(void)
{   Reserved70_DriverIRQHandler();
}

__attribute__((weak)) void CASER_IRQHandler(void)
{   CASER_DriverIRQHandler();
}

__attribute__((weak)) void PUF_IRQHandler(void)
{   PUF_DriverIRQHandler();
}

__attribute__((weak)) void Reserved73_IRQHandler(void)
{   Reserved73_DriverIRQHandler();
}

__attribute__((weak)) void DMA1_IRQHandler(void)
{   DMA1_DriverIRQHandler();
}

__attribute__((weak)) void FLEXCOMM8_IRQHandler(void)
{   FLEXCOMM8_DriverIRQHandler();
}

__attribute__((weak)) void CDOG_IRQHandler(void)
{   CDOG_DriverIRQHandler();
}

/*----------------------------------------------------------------------------
  Exception / Interrupt Vector table
 *----------------------------------------------------------------------------*/

#if defined ( __GNUC__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#endif

extern const VECTOR_TABLE_Type __VECTOR_TABLE[77];
       const VECTOR_TABLE_Type __VECTOR_TABLE[77] __VECTOR_TABLE_ATTRIBUTE = {
  (VECTOR_TABLE_Type)(&__INITIAL_SP),       /*     Initial Stack Pointer */
  Reset_Handler,                            /*     Reset Handler */
  NMI_Handler,                              /* -14 NMI Handler */
  HardFault_Handler,                        /* -13 Hard Fault Handler */
  MemManage_Handler,                        /* -12 MPU Fault Handler */
  BusFault_Handler,                         /* -11 Bus Fault Handler */
  UsageFault_Handler,                       /* -10 Usage Fault Handler */
  SecureFault_Handler,                      /*  -9 Secure Fault Handler */
  0,                                        /*     Reserved */
  0,                                        /*     Reserved */
  0,                                        /*     Reserved */
  SVC_Handler,                              /*  -5 SVCall Handler */
  DebugMon_Handler,                         /*  -4 Debug Monitor Handler */
  0,                                        /*     Reserved */
  PendSV_Handler,                           /*  -2 PendSV Handler */
  SysTick_Handler,                          /*  -1 SysTick Handler */

  /* Interrupts */
  WDT_BOD_IRQHandler,              // 16: Windowed watchdog timer, Brownout detect, Flash interrupt
  DMA0_IRQHandler,                 // 17: DMA0 controller
  GINT0_IRQHandler,                // 18: GPIO group 0
  GINT1_IRQHandler,                // 19: GPIO group 1
  PIN_INT0_IRQHandler,             // 20: Pin interrupt 0 or pattern match engine slice 0
  PIN_INT1_IRQHandler,             // 21: Pin interrupt 1or pattern match engine slice 1
  PIN_INT2_IRQHandler,             // 22: Pin interrupt 2 or pattern match engine slice 2
  PIN_INT3_IRQHandler,             // 23: Pin interrupt 3 or pattern match engine slice 3
  UTICK0_IRQHandler,               // 24: Micro-tick Timer
  MRT0_IRQHandler,                 // 25: Multi-rate timer
  CTIMER0_IRQHandler,              // 26: Standard counter/timer CTIMER0
  CTIMER1_IRQHandler,              // 27: Standard counter/timer CTIMER1
  SCT0_IRQHandler,                 // 28: SCTimer/PWM
  CTIMER3_IRQHandler,              // 29: Standard counter/timer CTIMER3
  FLEXCOMM0_IRQHandler,            // 30: Flexcomm Interface 0 (USART, SPI, I2C, I2S, FLEXCOMM)
  FLEXCOMM1_IRQHandler,            // 31: Flexcomm Interface 1 (USART, SPI, I2C, I2S, FLEXCOMM)
  FLEXCOMM2_IRQHandler,            // 32: Flexcomm Interface 2 (USART, SPI, I2C, I2S, FLEXCOMM)
  FLEXCOMM3_IRQHandler,            // 33: Flexcomm Interface 3 (USART, SPI, I2C, I2S, FLEXCOMM)
  FLEXCOMM4_IRQHandler,            // 34: Flexcomm Interface 4 (USART, SPI, I2C, I2S, FLEXCOMM)
  FLEXCOMM5_IRQHandler,            // 35: Flexcomm Interface 5 (USART, SPI, I2C, I2S, FLEXCOMM)
  FLEXCOMM6_IRQHandler,            // 36: Flexcomm Interface 6 (USART, SPI, I2C, I2S, FLEXCOMM)
  FLEXCOMM7_IRQHandler,            // 37: Flexcomm Interface 7 (USART, SPI, I2C, I2S, FLEXCOMM)
  ADC0_IRQHandler,                 // 38: ADC0
  Reserved39_IRQHandler,           // 39: Reserved interrupt
  ACMP_IRQHandler,                 // 40: ACMP interrupts
  Reserved41_IRQHandler,           // 41: Reserved interrupt
  Reserved42_IRQHandler,           // 42: Reserved interrupt
  USB0_NEEDCLK_IRQHandler,         // 43: USB Activity Wake-up Interrupt
  USB0_IRQHandler,                 // 44: USB device
  RTC_IRQHandler,                  // 45: RTC alarm and wake-up interrupts
  Reserved46_IRQHandler,           // 46: Reserved interrupt
  Reserved47_IRQHandler,           // 47: Reserved interrupt
  PIN_INT4_IRQHandler,             // 48: Pin interrupt 4 or pattern match engine slice 4 int
  PIN_INT5_IRQHandler,             // 49: Pin interrupt 5 or pattern match engine slice 5 int
  PIN_INT6_IRQHandler,             // 50: Pin interrupt 6 or pattern match engine slice 6 int
  PIN_INT7_IRQHandler,             // 51: Pin interrupt 7 or pattern match engine slice 7 int
  CTIMER2_IRQHandler,              // 52: Standard counter/timer CTIMER2
  CTIMER4_IRQHandler,              // 53: Standard counter/timer CTIMER4
  OS_EVENT_IRQHandler,             // 54: OS_EVENT_TIMER and OS_EVENT_WAKEUP interrupts
  Reserved55_IRQHandler,           // 55: Reserved interrupt
  Reserved56_IRQHandler,           // 56: Reserved interrupt
  Reserved57_IRQHandler,           // 57: Reserved interrupt
  Reserved58_IRQHandler,           // 58: Reserved interrupt
  CAN0_IRQ0_IRQHandler,            // 59: CAN0 interrupt0
  CAN0_IRQ1_IRQHandler,            // 60: CAN0 interrupt1
  Reserved61_IRQHandler,           // 61: Reserved interrupt
  USB1_PHY_IRQHandler,             // 62: USB1_PHY
  USB1_IRQHandler,                 // 63: USB1 interrupt
  USB1_NEEDCLK_IRQHandler,         // 64: USB1 activity
  SEC_HYPERVISOR_CALL_IRQHandler,  // 65: SEC_HYPERVISOR_CALL interrupt
  SEC_GPIO_INT0_IRQ0_IRQHandler,   // 66: SEC_GPIO_INT0_IRQ0 interrupt
  SEC_GPIO_INT0_IRQ1_IRQHandler,   // 67: SEC_GPIO_INT0_IRQ1 interrupt
  PLU_IRQHandler,                  // 68: PLU interrupt
  SEC_VIO_IRQHandler,              // 69: SEC_VIO interrupt
  Reserved70_IRQHandler,           // 70: Reserved interrupt
  CASER_IRQHandler,                // 71: CASPER interrupt
  PUF_IRQHandler,                  // 72: PUF interrupt
  Reserved73_IRQHandler,           // 73: Reserved interrupt
  DMA1_IRQHandler,                 // 74: DMA1 interrupt
  FLEXCOMM8_IRQHandler,            // 75: Flexcomm Interface 8 (SPI, , FLEXCOMM)
  CDOG_IRQHandler,                 // 76: CDOG interrupt
};

#if defined ( __GNUC__ )
#pragma GCC diagnostic pop
#endif

/*----------------------------------------------------------------------------
  Reset Handler called on controller reset
 *----------------------------------------------------------------------------*/
__NO_RETURN void Reset_Handler(void)
{
  __set_PSP((uint32_t)(&__INITIAL_SP));

  __set_MSPLIM((uint32_t)(&__STACK_LIMIT));
  __set_PSPLIM((uint32_t)(&__STACK_LIMIT));

#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
  __TZ_set_STACKSEAL_S((uint32_t *)(&__STACK_SEAL));
#endif

  SystemInit();                             /* CMSIS System Initialization */
  __PROGRAM_START();                        /* Enter PreMain (C library entry point) */
}


#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic push
  #pragma clang diagnostic ignored "-Wmissing-noreturn"
#endif

/*----------------------------------------------------------------------------
  Hard Fault Handler
 *----------------------------------------------------------------------------*/
void HardFault_Handler(void)
{
  while(1);
}

/*----------------------------------------------------------------------------
  Default Handler for Exceptions / Interrupts
 *----------------------------------------------------------------------------*/
void Default_Handler(void)
{
  while(1);
}

#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic pop
#endif
