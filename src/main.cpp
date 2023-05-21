#include <Arduino.h>

#include <display.hpp>
#include <sensors.hpp>

#include <command.hpp>

#include "display_ports.hpp"

#include <Adafruit_NeoPixel.h>

struct command commands[10];
int command_count = 0;

NokiaDisplay nokia_display = NokiaDisplay();
  Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, 10, NEO_GRB + NEO_KHZ800);


void setup()
{
  Serial.begin(9600);
  // output
  // init the keyboard class
  // init the display
  nokia_display.init();
  //init the led strip

	  strip.begin();
	  strip.show(); // Initialize all pixels to 'off'


  // input
  // init the sensors
  init_sensors();
  // init the serial server class
  // init the scheduler class
}

void loop()
{

  strip.setPixelColor(0, 50, 50, 50);
  strip.show(); // Initialize all pixels to 'off'
  while (command_count > 0)
  {
    command_count--;
    switch (commands[command_count].output)
    {
    case command_output::display_output:
      display_execute_command(&commands[command_count], &nokia_display);
      break;
    default:
      break;
    }
  }
  
  // if actions
  //   execute the actions
  //   update the display
  //   send commands to the keyboard

  // look for events on the sensors
  
  Serial.println(digitalRead(9));
  digitalWrite(13, digitalRead(9));
  delay(100);

  // look for events on the serial server
  // look for events on the scheduler
}