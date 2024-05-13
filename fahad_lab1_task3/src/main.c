#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <zephyr/drivers/gpio.h>
#define SLEEP_TIME_MS 1000
#define GPIO_0_LED_1 13
#define GPIO_0_LED_2  14
#define GPIO_0_LED_3  15
#define GPIO_0_LED_4  16

int main(void){
const struct device *gpio0_dev = device_get_binding("gpio@50000000");
gpio_pin_configure(gpio0_dev, GPIO_0_LED_1, GPIO_OUTPUT); 
gpio_pin_configure(gpio0_dev, GPIO_0_LED_2, GPIO_OUTPUT); 
gpio_pin_configure(gpio0_dev, GPIO_0_LED_3, GPIO_OUTPUT); 
gpio_pin_configure(gpio0_dev, GPIO_0_LED_4, GPIO_OUTPUT); 
while (1) {
gpio_pin_set(gpio0_dev, GPIO_0_LED_1, 1);
gpio_pin_set(gpio0_dev, GPIO_0_LED_2, 1);
gpio_pin_set(gpio0_dev, GPIO_0_LED_3, 1);
gpio_pin_set(gpio0_dev, GPIO_0_LED_4, 1);
k_msleep(SLEEP_TIME_MS);
gpio_pin_set(gpio0_dev, GPIO_0_LED_1, 0);
gpio_pin_set(gpio0_dev, GPIO_0_LED_2, 0);
gpio_pin_set(gpio0_dev, GPIO_0_LED_3, 0);
gpio_pin_set(gpio0_dev, GPIO_0_LED_4, 0);
k_msleep(SLEEP_TIME_MS); 
}
}
