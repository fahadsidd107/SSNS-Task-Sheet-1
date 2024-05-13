#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <zephyr/drivers/gpio.h>
#define SLEEP_TIME_MS 3000
#define LED1_NODE DT_NODELABEL(led0)
#define LED2_NODE DT_NODELABEL(led1)
#define LED3_NODE DT_NODELABEL(led2)
#define LED4_NODE DT_NODELABEL(led3)

int main(void){
static const struct gpio_dt_spec led1_spec = GPIO_DT_SPEC_GET(LED1_NODE, gpios);
static const struct gpio_dt_spec led2_spec = GPIO_DT_SPEC_GET(LED2_NODE, gpios);
static const struct gpio_dt_spec led3_spec = GPIO_DT_SPEC_GET(LED3_NODE, gpios);
static const struct gpio_dt_spec led4_spec = GPIO_DT_SPEC_GET(LED4_NODE, gpios);
gpio_pin_configure_dt(&led1_spec, GPIO_OUTPUT);
gpio_pin_configure_dt(&led2_spec, GPIO_OUTPUT);
gpio_pin_configure_dt(&led3_spec, GPIO_OUTPUT);
gpio_pin_configure_dt(&led4_spec, GPIO_OUTPUT);
while (1) {
gpio_pin_set_dt(&led1_spec,1);
gpio_pin_set_dt(&led2_spec,1);
gpio_pin_set_dt(&led3_spec,1);
gpio_pin_set_dt(&led4_spec,1);
k_msleep(SLEEP_TIME_MS);

gpio_pin_set_dt(&led1_spec,0);
gpio_pin_set_dt(&led2_spec,0);
gpio_pin_set_dt(&led3_spec,0);
gpio_pin_set_dt(&led4_spec,0);
k_msleep(SLEEP_TIME_MS); 
}
}
