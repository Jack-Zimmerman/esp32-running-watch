
#include "clock_screen.h"


namespace Screens {


    ClockScreen::ClockScreen(GFXcanvas16 * tft, TimeDateData * tdd){
        tft_ref = tft;
        tdd_ref = tdd;
    }

    void ClockScreen::drawClock(){
        //get size of text
        int16_t x1, y1; //boof pointers
        int16_t x, y; //real pos
        int16_t date_x, date_y; //date position
        uint16_t w, h;
        char time_buff[6]; //hh:mm + null
        char date_buff[11]; //mm/dd/yy + null


        //time text
        sprintf(time_buff, "%02d:%02d", tdd_ref->hours, tdd_ref->minutes);
        //date text
        sprintf(date_buff, "%02d/%02d/%02d", tdd_ref->month, tdd_ref->day, tdd_ref->year);

        //fill screen white
        tft_ref->fillScreen(ST7735_WHITE);
        tft_ref->setTextColor(ST7735_BLACK);
        
        //get text bounds for time
        tft_ref->setTextSize(4);
        tft_ref->getTextBounds(time_buff, 0, 0, &x1, &y1, &w, &h);
        x = (MAX_X / 2) - (w / 2);
        y = (MAX_Y / 2) - (h / 2);

        //get text bounds for date
        tft_ref->setTextSize(2);
        tft_ref->getTextBounds(date_buff, 0, 0, &x1, &y1, &w, &h);
        date_x = (MAX_X / 2) - (w / 2);
        date_y = y - h - 5; //5 pixel separatsion
 
        //draw date
        tft_ref->setCursor(date_x, date_y);
        tft_ref->print(date_buff);

        //draw time
        tft_ref->setTextSize(4);
        tft_ref->setCursor(x,y);
        tft_ref->print(time_buff);

    }
}