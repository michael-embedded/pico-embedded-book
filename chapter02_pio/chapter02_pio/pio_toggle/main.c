
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "toggle.pio.h"

int main() {
    PIO pio = pio0;
    uint sm = pio_claim_unused_sm(pio, true);
    uint offset = pio_add_program(pio, &toggle_program);
    pio_sm_config c = toggle_program_get_default_config(offset);
    sm_config_set_out_pins(&c, 16, 1);
    pio_sm_init(pio, sm, offset, &c);
    pio_sm_set_enabled(pio, sm, true);

    while (true) tight_loop_contents();
}
