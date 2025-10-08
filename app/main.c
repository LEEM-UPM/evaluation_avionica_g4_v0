#include "app.h"
#include "system/mcu.h"

int main(void)
{
    mcu_init();
    app_init();

    while (1) {
        app_run();
    }
}