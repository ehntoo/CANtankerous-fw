#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "fsl_device_registers.h"
#include "board/clock_config.h"
#include "board/pin_mux.h"
#include "board.h"
#include "fsl_power.h"

void APPInit() {
    return;
}

void APPTask() {
    return;
}

int main(void) {
    BOARD_InitBootClocks();
    BOARD_InitPins();
    /* GPIO_PortInit(GPIO, PWR_LED_PORT); */
    /* GPIO_PortInit(GPIO, ACT_LED_PORT); */


    /* set BOD VBAT level to 1.65V */
    /* POWER_SetBodVbatLevel(kPOWER_BodVbatLevel1650mv, kPOWER_BodHystLevel50mv, false); */
    /* #<{(| attach 12 MHz clock to FLEXCOMM0 (debug console) |)}># */
    /* CLOCK_AttachClk(BOARD_DEBUG_UART_CLK_ATTACH); */
    /* BOARD_InitPins(); */
    /*  */
    /* GPIO_PortSet(GPIO, PWR_LED_PORT, 1u << PWR_LED_PIN); */
    /* GPIO_PortSet(GPIO, ACT_LED_PORT, 1u << ACT_LED_PIN); */
    /* BOARD_BootClockPLL150M(); */
    /* BOARD_InitDebugConsole(); */
    /*  */
    /* NVIC_ClearPendingIRQ(USB0_IRQn); */
    /* NVIC_ClearPendingIRQ(USB0_NEEDCLK_IRQn); */
    /* NVIC_ClearPendingIRQ(USB1_IRQn); */
    /* NVIC_ClearPendingIRQ(USB1_NEEDCLK_IRQn); */
    /*  */
    /* POWER_DisablePD(kPDRUNCFG_PD_USB0_PHY); #<{(|< Turn on USB0 Phy |)}># */
    /* POWER_DisablePD(kPDRUNCFG_PD_USB1_PHY); #<{(|< Turn on USB1 Phy |)}># */
    /*  */
    /* #<{(| reset the IP to make sure it's in reset state. |)}># */
    /* RESET_PeripheralReset(kUSB0D_RST_SHIFT_RSTn); */
    /* RESET_PeripheralReset(kUSB0HSL_RST_SHIFT_RSTn); */
    /* RESET_PeripheralReset(kUSB0HMR_RST_SHIFT_RSTn); */
    /* RESET_PeripheralReset(kUSB1H_RST_SHIFT_RSTn); */
    /* RESET_PeripheralReset(kUSB1D_RST_SHIFT_RSTn); */
    /* RESET_PeripheralReset(kUSB1_RST_SHIFT_RSTn); */
    /* RESET_PeripheralReset(kUSB1RAM_RST_SHIFT_RSTn); */

    APPInit();

    while (1)
    {
        APPTask();
    }
}
