#include "gpio.h"

extern void SystemClock_Config(void);

int main()
{
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    while(1)
    {
        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
        HAL_Delay(1000);
    }
}