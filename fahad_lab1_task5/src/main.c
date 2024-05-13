#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <zephyr/drivers/gpio.h>

#define SLEEP_TIME_MS 2000

#define LED1_NODE DT_NODELABEL(led0)
#define LED2_NODE DT_NODELABEL(led1)
#define LED3_NODE DT_NODELABEL(led2)
#define LED4_NODE DT_NODELABEL(led3)

#define BUTTON1_NODE DT_NODELABEL(button0)
#define BUTTON2_NODE DT_NODELABEL(button1)
#define BUTTON3_NODE DT_NODELABEL(button2)
#define BUTTON4_NODE DT_NODELABEL(button3)

static const struct gpio_dt_spec led1_spec = GPIO_DT_SPEC_GET(LED1_NODE, gpios);
static const struct gpio_dt_spec led2_spec = GPIO_DT_SPEC_GET(LED2_NODE, gpios);
static const struct gpio_dt_spec led3_spec = GPIO_DT_SPEC_GET(LED3_NODE, gpios);
static const struct gpio_dt_spec led4_spec = GPIO_DT_SPEC_GET(LED4_NODE, gpios);

static const struct gpio_dt_spec button1_spec = GPIO_DT_SPEC_GET(BUTTON1_NODE, gpios);
static const struct gpio_dt_spec button2_spec = GPIO_DT_SPEC_GET(BUTTON2_NODE, gpios);
static const struct gpio_dt_spec button3_spec = GPIO_DT_SPEC_GET(BUTTON3_NODE, gpios);
static const struct gpio_dt_spec button4_spec = GPIO_DT_SPEC_GET(BUTTON4_NODE, gpios);

static struct gpio_callback button1_cb;
static struct gpio_callback button2_cb;
static struct gpio_callback button3_cb;
static struct gpio_callback button4_cb;

void button_pressed_callback(const struct device *gpiob, struct gpio_callback *cb,
                             gpio_port_pins_t pins)
{
    if (pins & BIT(button1_spec.pin)) {
        gpio_pin_toggle_dt(&led1_spec);
    } else if (pins & BIT(button2_spec.pin)) {
        gpio_pin_toggle_dt(&led2_spec);
    } else if (pins & BIT(button3_spec.pin)) {
        gpio_pin_toggle_dt(&led3_spec);
    } else if (pins & BIT(button4_spec.pin)) {
        gpio_pin_toggle_dt(&led4_spec);
    }
}

int main(void)
{
    gpio_pin_configure_dt(&led1_spec, GPIO_OUTPUT);
    gpio_pin_configure_dt(&led2_spec, GPIO_OUTPUT);
    gpio_pin_configure_dt(&led3_spec, GPIO_OUTPUT);
    gpio_pin_configure_dt(&led4_spec, GPIO_OUTPUT);

    gpio_pin_configure_dt(&button1_spec, GPIO_INPUT);
    gpio_pin_configure_dt(&button2_spec, GPIO_INPUT);
    gpio_pin_configure_dt(&button3_spec, GPIO_INPUT);
    gpio_pin_configure_dt(&button4_spec, GPIO_INPUT);

    gpio_pin_interrupt_configure_dt(&button1_spec, GPIO_INT_EDGE_TO_ACTIVE);
    gpio_pin_interrupt_configure_dt(&button2_spec, GPIO_INT_EDGE_TO_ACTIVE);
    gpio_pin_interrupt_configure_dt(&button3_spec, GPIO_INT_EDGE_TO_ACTIVE);
    gpio_pin_interrupt_configure_dt(&button4_spec, GPIO_INT_EDGE_TO_ACTIVE);

    gpio_init_callback(&button1_cb, button_pressed_callback, BIT(button1_spec.pin));
    gpio_init_callback(&button2_cb, button_pressed_callback, BIT(button2_spec.pin));
    gpio_init_callback(&button3_cb, button_pressed_callback, BIT(button3_spec.pin));
    gpio_init_callback(&button4_cb, button_pressed_callback, BIT(button4_spec.pin));

    gpio_add_callback(button1_spec.port, &button1_cb);
    gpio_add_callback(button2_spec.port, &button2_cb);
    gpio_add_callback(button3_spec.port, &button3_cb);
    gpio_add_callback(button4_spec.port, &button4_cb);

    while (1) {
        k_msleep(SLEEP_TIME_MS);
    }
}
