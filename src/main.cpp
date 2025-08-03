#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>
#include "esp_timer.h"
#include "screens/activity_screen.h"
#include "screens/clock_screen.h"


#define LED_BUILTIN 2
#define TFT_CS 21 //TFT CS pin connected to esp pin 21
#define TFT_DC 19 //TFT DC pin connected to esp pin 19
#define TFT_RST 22 //TFT RST pin connected to esp pin 21
#define TFT_MOSI 5
#define TFT_SCK 18
#define BL 23

//screen and memory canvas
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCK, TFT_RST);
GFXcanvas16 canvas(128, 160);

ActivityData ad;
TimeDateData tdd;
Screens::ActivityScreen as = Screens::ActivityScreen(&canvas, &ad);
Screens::ClockScreen cs = Screens::ClockScreen(&canvas, &tdd);
 

void reset_screen(){
    tft.setCursor(0,0);
    tft.fillScreen(ST7735_WHITE);
}

void print_text_line(char * text, uint8_t size){
    tft.setTextColor(ST7735_WHITE);
    tft.setTextSize(size);
    tft.println(text);
}
   
 
void setup(void) {
    tft.initR(INITR_BLACKTAB);   // initialize a ST7735S chip, black tab 
    tft.setTextWrap(false);
    canvas.setTextWrap(false);
    tft.fillScreen(ST7735_WHITE);
    
    ad.seconds_elapsed = 0;
    ad.minutes_elapsed = 0;

    tdd.day = 2;
    tdd.month = 8;
    tdd.year = 25;
    tdd.minutes = 40;
    tdd.hours = 10;
    tdd.seconds = 0;


    cs.drawClock();
}
 
void loop() { 
    ad.seconds_elapsed = millis() / 1000;

    if (ad.seconds_elapsed % 60 == 0){
        tdd.minutes++;
    }

    //refresh canvas
    cs.drawClock();
    tft.drawRGBBitmap(0, 0, canvas.getBuffer(), canvas.width(), canvas.height());
    
}
 