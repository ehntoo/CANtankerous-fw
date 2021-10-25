#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "fsl_device_registers.h"
#include "board/clock_config.h"
#include "board/pin_mux.h"
#include "board.h"
#include "fsl_power.h"
#include "cmsis_compiler.h"
#include "LPC5514.h"

void APPInit(void) {
    ACT_LED_ON();
    uint32_t status = SysTick_Config(SystemCoreClock / 1000);
    if (status != 0) {
        __BKPT(0);
    }
    return;
}

void APPTask(void) {
    return;
}

void SysTick_Handler(void) {
    static uint32_t counter = 0;
    if (counter >= 500) {
        ACT_LED_TOGGLE();
        counter = 0;
    }
    counter++;
}

void HardFault_Handler(void) {
    __BKPT(5);
}

int main(void) {
    BOARD_InitBootClocks();
    BOARD_InitPins();

    /* set BOD VBAT level to 1.65V */
    POWER_SetBodVbatLevel(kPOWER_BodVbatLevel1650mv, kPOWER_BodHystLevel50mv, false);

    APPInit();

    while (1)
    {
        APPTask();
    }
}
