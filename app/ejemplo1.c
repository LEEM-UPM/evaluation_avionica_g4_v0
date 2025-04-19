#include "gpio.h"

#define GREEN_LED_PIN GPIO_PIN_5
#define GREEN_LED_PIN_PORT GPIOA

extern void SystemClock_Config(void);

int main()
{
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    while(1)
    {
        HAL_GPIO_TogglePin(GREEN_LED_PIN_PORT, GREEN_LED_PIN);
        HAL_Delay(1000);
    }
}