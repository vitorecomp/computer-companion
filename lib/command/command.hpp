#ifndef COMMAND_H
#define COMMAND_H

enum command_output
{
    display_output,
    audio_output,
    sensor_output,
    keyboard_output,
    ledstrip_output,
};

enum command_type
{
    init_display
};

struct command
{
    command_type type;
    command_output output;
    int data[50]; 
};

#endif // COMMAND_H
