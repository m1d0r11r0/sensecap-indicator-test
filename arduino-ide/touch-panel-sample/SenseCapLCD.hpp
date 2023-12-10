#include <Arduino.h>
#include <LovyanGFX.hpp>

#include <lgfx/v1/platforms/esp32s3/Panel_RGB.hpp>
#include <lgfx/v1/platforms/esp32s3/Bus_RGB.hpp>
#include <driver/i2c.h>

/*************** SenceCAP用クラス ***************/
namespace lgfx
{
  struct Panel_SenseCapD1 : public lgfx::Panel_ST7701
  {
    static constexpr int32_t i2c_freq = 400000;
    static constexpr int_fast16_t pca9535_i2c_addr = 0x20;
    static constexpr int_fast16_t i2c_port = I2C_NUM_0;
    static constexpr int_fast16_t i2c_sda = GPIO_NUM_39;
    static constexpr int_fast16_t i2c_scl = GPIO_NUM_40;

    Panel_SenseCapD1(void) = default;
    bool init(bool use_reset) override;
    void reset(void);
    void cs_control(bool flg) override;
  };

  struct Touch_SenseCapD1 : public lgfx::Touch_FT5x06
  {
    static constexpr int32_t i2c_freq = 400000;
    static constexpr int_fast16_t pca9535_i2c_addr = 0x20;
    static constexpr int_fast16_t i2c_port = I2C_NUM_0;

    Touch_SenseCapD1(void) = default;
    bool init(void) override;
  };
}

class LGFX : public lgfx::LGFX_Device
{
public:

  lgfx::Bus_RGB          _bus_instance;
  lgfx::Panel_SenseCapD1 _panel_instance;
  lgfx::Touch_SenseCapD1 _touch_instance;
  lgfx::Light_PWM        _light_instance;

  LGFX(void);
};
/*************** !SenceCAP用クラス ***************/

/*************** SenceCAP用定数 ***************/
static LGFX lcd;
static constexpr int32_t LCD_W = 480;
static constexpr int32_t LCD_H = 480;
static constexpr int_fast16_t BUTTON_GPIO = 38;