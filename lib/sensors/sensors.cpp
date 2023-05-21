#include <sensors.hpp>

void init_sensors(struct system_state *state)
{
    // init the sensors pins
    pinMode(IR_SENSOR_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);

    
    // init the serial server class
    // init the scheduler class
}

void sensors_execute_command(struct command *command, struct system_state *state)
{
    // execute the command
}

int sensors_get_commands(struct command *command, struct system_state *state)
{
    // execute the command
    return 0;
}

