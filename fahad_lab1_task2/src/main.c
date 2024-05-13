#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <hal/nrf_gpio.h>

/* Define the GPIO pin numbers for the LEDs */
#define LED_PIN_1  13
#define LED_PIN_2  14
#define LED_PIN_3  15
#define LED_PIN_4  16

/* Define the delay time in milliseconds */
#define DELAY_TIME_MS 5000

void main(void)
{
    /* Initialize GPIO pins for LEDs */
    nrf_gpio_cfg_output(LED_PIN_1);
    nrf_gpio_cfg_output(LED_PIN_2);
    nrf_gpio_cfg_output(LED_PIN_3);
    nrf_gpio_cfg_output(LED_PIN_4);

    while (1) {
        /* Turn on all LEDs */
        nrf_gpio_pin_set(LED_PIN_1);
        nrf_gpio_pin_set(LED_PIN_2);
        nrf_gpio_pin_set(LED_PIN_3);
        nrf_gpio_pin_set(LED_PIN_4);
        k_msleep(DELAY_TIME_MS);

        /* Turn off all LEDs */
        nrf_gpio_pin_clear(LED_PIN_1);
        nrf_gpio_pin_clear(LED_PIN_2);
        nrf_gpio_pin_clear(LED_PIN_3);
        nrf_gpio_pin_clear(LED_PIN_4);
        k_msleep(DELAY_TIME_MS);
    }
}
