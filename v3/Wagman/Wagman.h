#include "Time.h"

const int MEDIA_SD = 0;
const int MEDIA_EMMC = 1;
const int MEDIA_INVALID = -1;

const int RELAY_UNKNOWN = 0;
const int RELAY_OFF = 1;
const int RELAY_ON = 2;

namespace Wagman
{
    void init();
//    void initPowerOn(); // to distinguish different state conditions
//    void initReset();
    
    void setRelay(int port, bool on);
    int getRelay(int port);

    int getHeartbeat(int port);

    int getCurrent();
    int getCurrent(int port);

    unsigned int getThermistor(int port);
    
    void setLED(int led, bool on);
    bool getLED(int led);
    void toggleLED(int led);
    
    float getHumidity();
    float getTemperature();

    int getBootMedia(int selector);
    void setBootMedia(int selector, int media);
    void toggleBootMedia(int selector);

    bool validPort(int port);
    bool validLED(int led);
    bool validBootSelector(int selector);

    time_t getTime();
    void setTime(int year, int month, int day, int hour, int minute, int second);

    int getAddressCurrent(int addr);
};

