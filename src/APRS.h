#ifndef ARDUINO_TRACKER_APRS_DRA818_APRS_H
#define ARDUINO_TRACKER_APRS_DRA818_APRS_H

#include <Arduino.h>
#include "DRA.h"
#include "GPS.h"

class APRS {
public:
    APRS(DRA *dra, GPS *gps, unsigned int secondBetweenTx, double speedDeltaTx, uint8_t txPin);

    void init(char *call, uint8_t callId, char *toCall, uint8_t toCallId, char *relays);

    bool loop(bool test = false);

    void setSecondBetweenTx(unsigned int secondBetweenTx);

    void setSpeedDeltaTx(double speedDeltaTx);
    void setComment(const char *comment);
    bool txToRadio(char *packet);

    bool sendPosition();

private:
    DRA *dra = nullptr;
    GPS *gps = nullptr;

    unsigned long lastTx = 0;
    double lastSpeed = 0;
    uint8_t txPin = 0;

    unsigned int timeBetweenTx;
    double speedDeltaTx;

    char packetBuffer[255] = {'\0'};
    char floatString[16] = {'\0'};
    const char *comment = nullptr;

    long readVccAtmega();

    float convertDegMin(float decDeg);

    void stringPadding(int number, byte width, char *dest);

    void stringPaddingf(float number, byte width, char *dest, char *tmpStr);

    void buildPacket();
};


#endif //ARDUINO_TRACKER_APRS_DRA818_APRS_H
