#ifndef SESORS_H
#define SESORS_H

#include <Arduino.h>
#include "../../include/connected_sensors.hpp"

// https://blogmasterwalkershop.com.br/arduino/como-usar-com-arduino-sensor-pir-detector-de-movimento

struct system_state
{
    uint16_t sleep_time;
};

void init_sensors(struct system_state *);
int sensors_get_commands(struct command *, struct system_state *);
void sensors_execute_command(struct command *, struct system_state *);

#endif // SESORS_H