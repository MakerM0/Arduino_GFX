/*******************************************************************************
 * U8g2 CJK(Chinese, Japanese and Korean) font example
 * Please note this font is 1,704,862 in size and cannot fit in many platform.
 * This font is generated by U8g2 tools:
 * u8g2/tools/font/bdfconv/bdfconv -v -f 1 -m "32-127,4352-4607,11904-12255,12288-19903,19968-40943,43360-43391,44032-55203,55216-55295,63744-64255,65072-65103,65280-65519,110592-110959,127488-127743,131072-173791" unifont_jp-14.0.02.bdf -o u8g2_font_unifont_t_cjk.h -n u8g2_font_unifont_t_cjk
 ******************************************************************************/

/*******************************************************************************
 * Start of Arduino_GFX setting
 *
 * Arduino_GFX try to find the settings depends on selected board in Arduino IDE
 * Or you can define the display dev kit not in the board list
 * Defalult pin list for non display dev kit:
 * Arduino Nano, Micro and more: CS:  9, DC:  8, RST:  7, BL:  6, SCK: 13, MOSI: 11, MISO: 12
 * ESP32 various dev board     : CS:  5, DC: 27, RST: 33, BL: 22, SCK: 18, MOSI: 23, MISO: nil
 * ESP32-C3 various dev board  : CS:  7, DC:  2, RST:  1, BL:  3, SCK:  4, MOSI:  6, MISO: nil
 * ESP32-S2 various dev board  : CS: 34, DC: 38, RST: 33, BL: 21, SCK: 36, MOSI: 35, MISO: nil
 * ESP32-S3 various dev board  : CS: 40, DC: 41, RST: 42, BL: 48, SCK: 36, MOSI: 35, MISO: nil
 * ESP8266 various dev board   : CS: 15, DC:  4, RST:  2, BL:  5, SCK: 14, MOSI: 13, MISO: 12
 * Raspberry Pi Pico dev board : CS: 17, DC: 27, RST: 26, BL: 28, SCK: 18, MOSI: 19, MISO: 16
 * RTL8720 BW16 old patch core : CS: 18, DC: 17, RST:  2, BL: 23, SCK: 19, MOSI: 21, MISO: 20
 * RTL8720_BW16 Official core  : CS:  9, DC:  8, RST:  6, BL:  3, SCK: 10, MOSI: 12, MISO: 11
 * RTL8722 dev board           : CS: 18, DC: 17, RST: 22, BL: 23, SCK: 13, MOSI: 11, MISO: 12
 * RTL8722_mini dev board      : CS: 12, DC: 14, RST: 15, BL: 13, SCK: 11, MOSI:  9, MISO: 10
 * Seeeduino XIAO dev board    : CS:  3, DC:  2, RST:  1, BL:  0, SCK:  8, MOSI: 10, MISO:  9
 * Teensy 4.1 dev board        : CS: 39, DC: 41, RST: 40, BL: 22, SCK: 13, MOSI: 11, MISO: 12
 ******************************************************************************/
#include <U8g2lib.h>
#include <Arduino_GFX_Library.h>

#define GFX_BL DF_GFX_BL // default backlight pin, you may replace DF_GFX_BL to actual backlight pin

/* More dev device declaration: https://github.com/moononournation/Arduino_GFX/wiki/Dev-Device-Declaration */
#if defined(DISPLAY_DEV_KIT)
Arduino_GFX *gfx = create_default_Arduino_GFX();
#else /* !defined(DISPLAY_DEV_KIT) */

/* More data bus class: https://github.com/moononournation/Arduino_GFX/wiki/Data-Bus-Class */
Arduino_DataBus *bus = create_default_Arduino_DataBus();

/* More display class: https://github.com/moononournation/Arduino_GFX/wiki/Display-Class */
Arduino_GFX *gfx = new Arduino_ILI9341(bus, DF_GFX_RST, 0 /* rotation */, false /* IPS */);

#endif /* !defined(DISPLAY_DEV_KIT) */
/*******************************************************************************
 * End of Arduino_GFX setting
 ******************************************************************************/

/* more fonts at: https://github.com/moononournation/ArduinoFreeFontFile.git */

void setup(void)
{
#ifdef GFX_EXTRA_PRE_INIT
  GFX_EXTRA_PRE_INIT();
#endif

    gfx->begin();
    gfx->fillScreen(BLACK);
    gfx->setUTF8Print(true); // enable UTF8 support for the Arduino print() function

#ifdef GFX_BL
    pinMode(GFX_BL, OUTPUT);
    digitalWrite(GFX_BL, HIGH);
#endif

    /* select one font below and uncomment, chill7 and cubic11 are smaller size but lack of Korea characters */
    // gfx->setFont(u8g2_font_chill7_h_cjk);
    // gfx->setFont(u8g2_font_cubic11_h_cjk);
    gfx->setFont(u8g2_font_quan7_h_cjk);
    // gfx->setFont(u8g2_font_unifont_t_cjk);
    gfx->setCursor(0, 14);

    gfx->setTextColor(RED);
    gfx->println("世界你好，今天的天氣真好啊！");
    gfx->println();

    gfx->setTextColor(YELLOW);
    gfx->println("世界你好，今天的天气真好啊！");
    gfx->println();

    gfx->setTextColor(GREEN);
    gfx->println("こんにちは世界、今日はいいお天気ですね！");
    gfx->println();

    gfx->setTextColor(BLUE);
    gfx->println("안녕하세요 세계, 오늘 날씨가 너무 좋습니다!");
    gfx->println();

    gfx->setTextColor(MAGENTA);
    gfx->println("Hello world, the weather is so nice today!");
}

void loop()
{
}
