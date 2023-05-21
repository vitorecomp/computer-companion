#ifndef COMMAND_H
#define COMMAND_H

enum command_output
{
    display_output
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
