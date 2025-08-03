#ifndef ACTIVITY_SCREEN
#define ACTIVITY_SCREEN

#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include "../utils/data_structs.h"
#include "../utils/const.h"

namespace Screens{
    class ActivityScreen{
        public:
            ActivityScreen(GFXcanvas16 * tft, ActivityData * ad);
            void drawBoxes();
            void drawData();
        private:
            GFXcanvas16 * tft_ref;
            ActivityData * ad_ref;
    };
}

#endif