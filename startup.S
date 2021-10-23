/* --------------------------------------------------------------------------*/
/* @file:    startup_LPC5514.s                                                */
/* @purpose: CMSIS Cortex-M33 Core Device Startup File                       */
/*           LPC5514                                                          */
/* @version: 1.1                                                      */
/* @date:    2019-12-3                                                         */
/* --------------------------------------------------------------------------*/
/*                                                                           */
/* Copyright 1997-2016 Freescale Semiconductor, Inc.                         */
/* Copyright 2016-2021 NXP                                                   */
/* All rights reserved.                                                      */
/*                                                                           */
/* SPDX-License-Identifier: BSD-3-Clause                                     */
/*****************************************************************************/
/* Version: GCC for ARM Embedded Processors                                  */
/*****************************************************************************/


    .syntax unified
    .arch armv8-m.main

    .section .isr_vector, "a"
    .align 2
    .globl __Vectors
__Vectors:
    .long   __StackTop                                      /* Top of Stack */
    .long   Reset_Handler                                   /* Reset Handler */
    .long   NMI_Handler                                     /* NMI Handler*/
    .long   HardFault_Handler                               /* Hard Fault Handler*/
    .long   MemManage_Handler                               /* MPU Fault Handler*/
    .long   BusFault_Handler                                /* Bus Fault Handler*/
    .long   UsageFault_Handler                              /* Usage Fault Handler*/
    .long   SecureFault_Handler                             /* Secure Fault Handler*/
    .long   0                                               /* Reserved*/
    .long   0                                               /* Reserved*/
    .long   0                                               /* Reserved*/
    .long   SVC_Handler                                     /* SVCall Handler*/
    .long   DebugMon_Handler                                /* Debug Monitor Handler*/
    .long   0                                               /* Reserved*/
    .long   PendSV_Handler                                  /* PendSV Handler*/
    .long   SysTick_Handler                                 /* SysTick Handler*/

    /* External Interrupts */
    .long   WDT_BOD_IRQHandler  /* Windowed watchdog timer, Brownout detect, Flash interrupt */
    .long   DMA0_IRQHandler  /* DMA0 controller */
    .long   GINT0_IRQHandler  /* GPIO group 0 */
    .long   GINT1_IRQHandler  /* GPIO group 1 */
    .long   PIN_INT0_IRQHandler  /* Pin interrupt 0 or pattern match engine slice 0 */
    .long   PIN_INT1_IRQHandler  /* Pin interrupt 1or pattern match engine slice 1 */
    .long   PIN_INT2_IRQHandler  /* Pin interrupt 2 or pattern match engine slice 2 */
    .long   PIN_INT3_IRQHandler  /* Pin interrupt 3 or pattern match engine slice 3 */
    .long   UTICK0_IRQHandler  /* Micro-tick Timer */
    .long   MRT0_IRQHandler  /* Multi-rate timer */
    .long   CTIMER0_IRQHandler  /* Standard counter/timer CTIMER0 */
    .long   CTIMER1_IRQHandler  /* Standard counter/timer CTIMER1 */
    .long   SCT0_IRQHandler  /* SCTimer/PWM */
    .long   CTIMER3_IRQHandler  /* Standard counter/timer CTIMER3 */
    .long   FLEXCOMM0_IRQHandler  /* Flexcomm Interface 0 (USART, SPI, I2C, I2S, FLEXCOMM) */
    .long   FLEXCOMM1_IRQHandler  /* Flexcomm Interface 1 (USART, SPI, I2C, I2S, FLEXCOMM) */
    .long   FLEXCOMM2_IRQHandler  /* Flexcomm Interface 2 (USART, SPI, I2C, I2S, FLEXCOMM) */
    .long   FLEXCOMM3_IRQHandler  /* Flexcomm Interface 3 (USART, SPI, I2C, I2S, FLEXCOMM) */
    .long   FLEXCOMM4_IRQHandler  /* Flexcomm Interface 4 (USART, SPI, I2C, I2S, FLEXCOMM) */
    .long   FLEXCOMM5_IRQHandler  /* Flexcomm Interface 5 (USART, SPI, I2C, I2S, FLEXCOMM) */
    .long   FLEXCOMM6_IRQHandler  /* Flexcomm Interface 6 (USART, SPI, I2C, I2S, FLEXCOMM) */
    .long   FLEXCOMM7_IRQHandler  /* Flexcomm Interface 7 (USART, SPI, I2C, I2S, FLEXCOMM) */
    .long   ADC0_IRQHandler  /* ADC0  */
    .long   Reserved39_IRQHandler  /* Reserved interrupt */
    .long   ACMP_IRQHandler  /* ACMP interrupts */
    .long   Reserved41_IRQHandler  /* Reserved interrupt */
    .long   Reserved42_IRQHandler  /* Reserved interrupt */
    .long   USB0_NEEDCLK_IRQHandler  /* USB Activity Wake-up Interrupt */
    .long   USB0_IRQHandler  /* USB device */
    .long   RTC_IRQHandler  /* RTC alarm and wake-up interrupts */
    .long   Reserved46_IRQHandler  /* Reserved interrupt */
    .long   Reserved47_IRQHandler  /* Reserved interrupt */
    .long   PIN_INT4_IRQHandler  /* Pin interrupt 4 or pattern match engine slice 4 int */
    .long   PIN_INT5_IRQHandler  /* Pin interrupt 5 or pattern match engine slice 5 int */
    .long   PIN_INT6_IRQHandler  /* Pin interrupt 6 or pattern match engine slice 6 int */
    .long   PIN_INT7_IRQHandler  /* Pin interrupt 7 or pattern match engine slice 7 int */
    .long   CTIMER2_IRQHandler  /* Standard counter/timer CTIMER2 */
    .long   CTIMER4_IRQHandler  /* Standard counter/timer CTIMER4 */
    .long   OS_EVENT_IRQHandler  /* OS_EVENT_TIMER and OS_EVENT_WAKEUP interrupts */
    .long   Reserved55_IRQHandler  /* Reserved interrupt */
    .long   Reserved56_IRQHandler  /* Reserved interrupt */
    .long   Reserved57_IRQHandler  /* Reserved interrupt */
    .long   Reserved58_IRQHandler  /* Reserved interrupt */
    .long   CAN0_IRQ0_IRQHandler  /* CAN0 interrupt0 */
    .long   CAN0_IRQ1_IRQHandler  /* CAN0 interrupt1 */
    .long   Reserved61_IRQHandler  /* Reserved interrupt */
    .long   USB1_PHY_IRQHandler  /* USB1_PHY */
    .long   USB1_IRQHandler  /* USB1 interrupt */
    .long   USB1_NEEDCLK_IRQHandler  /* USB1 activity */
    .long   SEC_HYPERVISOR_CALL_IRQHandler  /* SEC_HYPERVISOR_CALL interrupt */
    .long   SEC_GPIO_INT0_IRQ0_IRQHandler  /* SEC_GPIO_INT0_IRQ0 interrupt */
    .long   SEC_GPIO_INT0_IRQ1_IRQHandler  /* SEC_GPIO_INT0_IRQ1 interrupt */
    .long   PLU_IRQHandler  /* PLU interrupt */
    .long   SEC_VIO_IRQHandler  /* SEC_VIO interrupt */
    .long   Reserved70_IRQHandler  /* Reserved interrupt */
    .long   CASER_IRQHandler  /* CASPER interrupt */
    .long   PUF_IRQHandler  /* PUF interrupt */
    .long   Reserved73_IRQHandler  /* Reserved interrupt */
    .long   DMA1_IRQHandler  /* DMA1 interrupt */
    .long   FLEXCOMM8_IRQHandler  /* Flexcomm Interface 8 (SPI, , FLEXCOMM) */
    .long   CDOG_IRQHandler  /* CDOG interrupt */

    .size   __Vectors, . - __Vectors

    .text
    .thumb

/* Reset Handler */
    .thumb_func
    .align 2
    .globl   Reset_Handler
    .weak    Reset_Handler
    .type    Reset_Handler, %function
Reset_Handler:
    cpsid   i               /* Mask interrupts */
    .equ    VTOR, 0xE000ED08
    ldr     r0, =VTOR
    ldr     r1, =__Vectors
    str     r1, [r0]
    ldr     r2, [r1]
    msr     msp, r2
    ldr     R0, =__StackLimit
    msr     msplim, R0
#ifndef __NO_SYSTEM_INIT
    ldr   r0,=SystemInit
    blx   r0
#endif
/*     Loop to copy data from read only memory to RAM. The ranges
 *      of copy from/to are specified by following symbols evaluated in
 *      linker script.
 *      __etext: End of code section, i.e., begin of data sections to copy from.
 *      __data_start__/__data_end__: RAM address range that data should be
 *      copied to. Both must be aligned to 4 bytes boundary.  */

    ldr    r1, =__etext
    ldr    r2, =__data_start__
    ldr    r3, =__data_end__

#if 1
/* Here are two copies of loop implemenations. First one favors code size
 * and the second one favors performance. Default uses the first one.
 * Change to "#if 0" to use the second one */
.LC0:
    cmp     r2, r3
    ittt    lt
    ldrlt   r0, [r1], #4
    strlt   r0, [r2], #4
    blt    .LC0
#else
    subs    r3, r2
    ble    .LC1
.LC0:
    subs    r3, #4
    ldr    r0, [r1, r3]
    str    r0, [r2, r3]
    bgt    .LC0
.LC1:
#endif

#ifdef __STARTUP_CLEAR_BSS
/*     This part of work usually is done in C library startup code. Otherwise,
 *     define this macro to enable it in this startup.
 *
 *     Loop to zero out BSS section, which uses following symbols
 *     in linker script:
 *      __bss_start__: start of BSS section. Must align to 4
 *      __bss_end__: end of BSS section. Must align to 4
 */
    ldr r1, =__bss_start__
    ldr r2, =__bss_end__

    movs    r0, 0
.LC2:
    cmp     r1, r2
    itt    lt
    strlt   r0, [r1], #4
    blt    .LC2
#endif /* __STARTUP_CLEAR_BSS */

/* Add stack / heap initializaiton */
    movs    r0, 0
    ldr     r1, =__HeapBase
    ldr     r2, =__HeapLimit
.LC3:
    cmp     r1, r2
    itt     lt
    strlt   r0, [r1], #4
    blt     .LC3

    ldr     r1, =__StackLimit
    ldr     r2, =__StackTop
.LC4:
    cmp     r1, r2
    itt     lt
    strlt   r0, [r1], #4
    blt     .LC4
/*End of stack / heap initializaiton */
    cpsie   i               /* Unmask interrupts */

#ifndef __START
#define __START _start
#endif
    ldr   r0,=__START
    blx   r0

    .pool
    .size Reset_Handler, . - Reset_Handler
    .end
