#ifndef LEDSTRIP_H
#define LEDSTRIP_H

#include <Adafruit_NeoPixel.h>
#include "../../include/board_pinout.hpp"

class NeoStrip{
public:
    Adafruit_NeoPixel strip;
    NeoStrip();
    void init();
};

void ledstrip_execute_command(struct command *command, NeoStrip *strip);


#endif // LEDSTRIP_H