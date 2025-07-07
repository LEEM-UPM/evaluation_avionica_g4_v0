#include "i2c.h"
#include "usart.h"
#include "gpio.h"

#include "WSEN_PADS_EXAMPLE.h"

extern void SystemClock_Config(void);

int main(void)
{
  HAL_Init();
  SystemClock_Config();

  MX_GPIO_Init();
  MX_I2C1_Init();
  MX_USART2_UART_Init();

  WE_padsExampleInit();

  while (1)
  {
    WE_padsExampleLoop();
  }
}
