#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>
#include "../utils/data_structs.h"
#include "../utils/const.h"
#include "activity_screen.h"


namespace Screens{

    //pass reference and domain to tft
    ActivityScreen::ActivityScreen(GFXcanvas16 * tft, ActivityData * ad){
        //absorb tft and activity data pointer
        tft_ref = tft; 
        ad_ref = ad;
    }

    void ActivityScreen::drawBoxes(){
        tft_ref->fillScreen(ST7735_WHITE);

        int i;

        //draw two vertical lines to separate the three boxes
        //start at 50th line and draw 5 pixels
        for (i = 49; i < 54; i++){ 
            tft_ref->drawFastHLine(0, i, MAX_X, ST7735_BLACK);
            delay(0);
        }

        //start at 95th line and draw 5 pixels
        for (i = 104; i < 109; i++){ 
            tft_ref->drawFastHLine(0, i, MAX_X, ST7735_BLACK);
            delay(0);
        }
    }

    void ActivityScreen::drawData(){
        //init
        tft_ref->setTextColor(ST7735_BLACK);
        tft_ref->setTextSize(2);

        //draw time
        tft_ref->setCursor(40, 25);
        tft_ref->printf("%d:%02d", ad_ref->minutes_elapsed, ad_ref->seconds_elapsed);

        //draw speed
        tft_ref->setCursor(40, 80);
        tft_ref->printf("%2.2f", ad_ref->speed_mph);

        //draw distance
        tft_ref->setCursor(40, 135);
        tft_ref->printf("%2.2f", ad_ref->total_miles);


        //draw labels
        tft_ref->setTextSize(1);

        //draw time
        tft_ref->setCursor(10, 10);
        tft_ref->printf("Time Elapsed:");

        //draw speed
        tft_ref->setCursor(10, 65);
        tft_ref->printf("Speed(Mph):");

        //draw distance
        tft_ref->setCursor(10, 120);
        tft_ref->printf("Total Distance");
    }

}