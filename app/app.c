#include "app.h"

#include "sensors/pads.h"

#include <stddef.h>

#define FIFO_THRESHOLD 32

static int32_t pressure_buffer[FIFO_THRESHOLD];

static float average_pressure(int32_t *buf, size_t len);

void app_init(void)
{
    if (!pads_init(&pads1)) 
    {
        // TODO    
    }

    if (!pads_start(&pads1, FIFO_THRESHOLD)) 
    {
        // TODO
    }
}

void app_run(void)
{
    if (!pads_event_pending(&pads1))
    {
        return;
    }
        
    pads_clear_event(&pads1);

    pads_read_fifo(&pads1, pressure_buffer, FIFO_THRESHOLD);

    float avg_pressure = average_pressure(pressure_buffer, FIFO_THRESHOLD);

    (void)avg_pressure;
}

static float average_pressure(int32_t *buf, size_t len)
{
    float sum = 0.0f;
    for (size_t i = 0; i < len; i++)
    {
        sum += buf[i];
    }
    return (len > 0) ? sum / len : 0.0f;
}
