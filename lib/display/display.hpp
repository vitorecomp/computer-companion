#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include <Arduino.h>
#include <avr/pgmspace.h> 

#include "../../include/board_pinout.hpp"
#include "../../include/display_images.hpp"



class NokiaDisplay
{
private:
    Adafruit_PCD8544 display;
    void drawBitmap(const byte bitmap[]);
public:
    void init();
    NokiaDisplay();
    ~NokiaDisplay();
};




void display_execute_command(struct command *command, NokiaDisplay *display);

#endif // DISPLAY_HPP