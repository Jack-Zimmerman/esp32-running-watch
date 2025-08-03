#ifndef DATA_STRUCTS
#define DATA_STRUCTS


//contains data pertaining to speed, total distance traveled, and time
typedef struct ActivityData {
    float speed_mph; //calculated by gps module
    float total_miles; //accumalated from gps module
    uint16_t minutes_elapsed; //to be handled by gps converter
    uint16_t seconds_elapsed; //to be handled by gps converter
} ActivityData;


//all to be delivered by gps
typedef struct TimeDateData {
    uint8_t hours; 
    uint8_t minutes; 
    uint8_t seconds; 
    uint8_t month; 
    uint8_t day;
    uint8_t year;
} TimeDateData;


#endif

