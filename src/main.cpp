#include <Arduino.h>

#include <display.hpp>
#include <sensors.hpp>
#include <ledstrip.hpp>
#include <serial_server.hpp>
#include <scheduler.hpp>
#include <audio.hpp>
#include <keyboard.hpp>

#include <command.hpp>

#include "display_ports.hpp"


//if more memory is needed, i should work one event at a time
struct command commands[5];

int command_count = 0;

NokiaDisplay nokia_display = NokiaDisplay();
NeoStrip neo_strip = NeoStrip();
SerialServer serial_server = SerialServer();

struct system_state state;
struct schedules_runs runs;


void setup()
{
  Serial.begin(9600);
  // output
  // init the display
  nokia_display.init();
  // init the led strip
  neo_strip.init();
  // init the out output
  init_audio_output();

  // input
  // init the sensors
  init_sensors(&state);
  // init the scheduler class
 get_schedules(&runs);

  // input/output
  //  init the serial server class
  serial_server.init();
}

void loop()
{

  while (command_count > 0)
  {
    command_count--;
    switch (commands[command_count].output)
    {
    case command_output::display_output:
      display_execute_command(&commands[command_count], &nokia_display);
      break;
    case command_output::ledstrip_output:
      ledstrip_execute_command(&commands[command_count], &neo_strip);
      break;
    case command_output::keyboard_output:
      keyboard_execute_command(&commands[command_count]);
      break;
    case command_output::audio_output:
      audio_execute_command(&commands[command_count]);
      break;
    case command_output::sensor_output:
      sensors_execute_command(&commands[command_count], &state);
      break;
    }
  }

  
  // look for events on the sensors
  command_count += sensors_get_commands(commands, &state);
  // look for events on the serial server
  command_count += serial_server.get_commands(commands);
  // look for events on the scheduler
  command_count += scheduler_get_commands(commands, &runs);

  if (command_count == 0)
  {
    delay(state.sleep_time);
  }
}