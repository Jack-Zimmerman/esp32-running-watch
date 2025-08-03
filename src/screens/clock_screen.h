#ifndef CLOCK_SCREEN
#define CLOCK_SCREEN

#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include "../utils/data_structs.h"
#include "../utils/const.h"

namespace Screens{
    class ClockScreen{
        public:
            ClockScreen(GFXcanvas16 * tft, TimeDateData * tdd);
            void drawClock();
        private:
            GFXcanvas16 * tft_ref;
            TimeDateData * tdd_ref;
    };
}




#endif