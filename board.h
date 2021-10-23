#ifndef _BOARD_H_
#define _BOARD_H_

#include "board/clock_config.h"
#include "fsl_common.h"
#include "fsl_reset.h"
#include "fsl_gpio.h"
#include "fsl_iocon.h"

#ifndef BOARD_ACT_LED_GPIO
#define BOARD_ACT_LED_GPIO GPIO
#endif
#define BOARD_ACT_LED_GPIO_PORT 0U
#ifndef BOARD_ACT_LED_GPIO_PIN
#define BOARD_ACT_LED_GPIO_PIN  27U
#endif

#ifndef BOARD_PWR_LED_GPIO
#define BOARD_PWR_LED_GPIO GPIO
#endif
#define BOARD_PWR_LED_GPIO_PORT 1U
#ifndef BOARD_PWR_LED_GPIO_PIN
#define BOARD_PWR_LED_GPIO_PIN  1U
#endif

#define ACT_LED_ON() \
    GPIO_PortSet(BOARD_ACT_LED_GPIO, BOARD_ACT_LED_GPIO_PORT, 1U << BOARD_ACT_LED_GPIO_PIN)
#define ACT_LED_OFF() \
    GPIO_PortClear(BOARD_ACT_LED_GPIO, BOARD_ACT_LED_GPIO_PORT, 1U << BOARD_ACT_LED_GPIO_PIN)
#define ACT_LED_TOGGLE() \
    GPIO_PortToggle(BOARD_ACT_LED_GPIO, BOARD_ACT_LED_GPIO_PORT, 1U << BOARD_ACT_LED_GPIO_PIN)

#endif /* _BOARD_H_ */
