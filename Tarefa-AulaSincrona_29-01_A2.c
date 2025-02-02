#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

volatile bool isBtnUnlocked = true;

const uint PIN_RED = 13, PIN_BLUE = 12, PIN_GREEN = 11, PIN_BTN = 5;
uint32_t last_click = 0;

volatile alarm_id_t CURRENT_ALARM = 0;

int64_t off_callback(alarm_id_t id, void *user_data);
void turn_on_all_leds();

int main()
{
    stdio_init_all();

    //Inicio da configuração dos pinos
    gpio_init(PIN_RED);
    gpio_init(PIN_BLUE);
    gpio_init(PIN_GREEN);
    gpio_init(PIN_BTN);

    gpio_set_dir(PIN_RED, GPIO_OUT);
    gpio_set_dir(PIN_BLUE, GPIO_OUT);
    gpio_set_dir(PIN_GREEN, GPIO_OUT);
    gpio_set_dir(PIN_BTN, GPIO_IN);

    gpio_pull_up(PIN_BTN);
    //Fim da configuração dos pinos
    while (true)
    {
        if (isBtnUnlocked && !gpio_get(PIN_BTN))
        {
            uint32_t current_time = to_us_since_boot(get_absolute_time());

            if (current_time - last_click > 200000)
            {

                last_click = current_time;
                isBtnUnlocked = false;
                turn_on_all_leds();
                if (CURRENT_ALARM)
                {
                    cancel_alarm(CURRENT_ALARM);
                }
                CURRENT_ALARM = add_alarm_in_ms(3000, off_callback, NULL, false);
            }
        }
        sleep_ms(50);
    }
}

void turn_on_all_leds()
{
    gpio_put(PIN_RED, 1);
    gpio_put(PIN_BLUE, 1);
    gpio_put(PIN_GREEN, 1);
}

int64_t off_callback(alarm_id_t id, void *user_data)
{
    if (gpio_get(PIN_RED))
    {
        gpio_put(PIN_RED, 0);

        //Cancela o alarme anterior antes de adicionar um novo
        if (CURRENT_ALARM)
        {
            cancel_alarm(CURRENT_ALARM);
        }

        //Adiciona um novo alarme
        CURRENT_ALARM = add_alarm_in_ms(3000, off_callback, NULL, false);
        return 0;
    }
    if (gpio_get(PIN_BLUE))
    {

        gpio_put(PIN_BLUE, 0);
        //Cancela o alarme anterior antes de adicionar um novo
        if (CURRENT_ALARM)
        {
            cancel_alarm(CURRENT_ALARM);
        }
        //Adiciona um novo alarme
        CURRENT_ALARM = add_alarm_in_ms(3000, off_callback, NULL, false);
        return 0;
    }

        gpio_put(PIN_GREEN, 0);
        //Cancela o alarme anterior antes de adicionar um novo
        if (CURRENT_ALARM)
        {
            cancel_alarm(CURRENT_ALARM);
        }
        //Adiciona um novo alarme
        CURRENT_ALARM = add_alarm_in_ms(3000, off_callback, NULL, false);
        isBtnUnlocked = true;
        return 0;
    
}