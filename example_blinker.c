#include <furi.h>
#include <furi_hal.h>

#include <gui/gui.h>
#include <input/input.h>

void blink_20_times() {
  furi_hal_gpio_write(&gpio_ext_pa7, true);
  furi_hal_gpio_init(&gpio_ext_pa7, GpioModeOutputPushPull, GpioPullNo, GpioSpeedVeryHigh);
  for(int i = 0; i < 20; i++) {
    furi_hal_gpio_write(&gpio_ext_pa7, true);
    furi_delay_ms(150);
    furi_hal_gpio_write(&gpio_ext_pa7, false);
    furi_delay_ms(150);
  }

  // Uninit GPIO
  furi_hal_gpio_init(&gpio_ext_pa7, GpioModeAnalog, GpioPullNo, GpioSpeedVeryHigh);
}

int32_t example_blinker_main(void* p) {
    UNUSED(p);
    blink_20_times();
    return 0;
}