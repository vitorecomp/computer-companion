#include <ledstrip.hpp>

NeoStrip::NeoStrip() : strip(N_LEDS, STRIP_PIN, NEO_GRB + NEO_KHZ800)
{
}

void NeoStrip::init()
{
    strip.begin();
    strip.show(); // Initialize all pixels to 'off'


    for(int i =0; i < N_LEDS; i++){
        strip.setPixelColor(i, 0, 20, 20);
    }
    strip.show(); // Initialize all pixels to 'off'
}

void ledstrip_execute_command(struct command *command, NeoStrip *strip)
{
    // execute the command
    strip->strip.setPixelColor(0, 20, 0, 0);
    strip->strip.show(); // Initialize all pixels to 'off'
}
