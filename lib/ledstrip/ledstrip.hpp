#ifndef LEDSTRIP_H
#define LEDSTRIP_H

#include <Adafruit_NeoPixel.h>
#include "../../include/neo_strip_ports.hpp"

class NeoStrip{
    Adafruit_NeoPixel strip;
public:
    NeoStrip();
    void init();
};

void ledstrip_execute_command(struct command *command, NeoStrip *strip);


#endif // LEDSTRIP_H