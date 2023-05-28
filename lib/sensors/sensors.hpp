#ifndef SESORS_H
#define SESORS_H

#include <Arduino.h>

#include <system.hpp>
#include <command.hpp>

#include "../../include/board_pinout.hpp"
#include "../../include/constants_values.hpp"

// https://blogmasterwalkershop.com.br/arduino/como-usar-com-arduino-sensor-pir-detector-de-movimento

void init_sensors(system_state *);
uint8_t sensors_get_commands(command *, uint8_t, system_state *);
void sensors_execute_command(command *, system_state *);

void read_sensors(system_state *);
void run_sensors_average(system_state *);

#endif // SESORS_H