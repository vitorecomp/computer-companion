#ifndef COMMAND_H
#define COMMAND_H

enum command_output
{
    display_output,
    sensor_output,
    led_strip_output,
    serial_output,
    keyboard_output,
};

enum command_type
{

    computer_turn_on,

    //to implement
    computer_turn_off,
    computer_turn_reset,

    led_strip_turn_on,
    led_strip_turn_off,

    led_strip_enable_rotation,
    led_strip_disable_rotation,
    led_strip_rotation_speed,

    led_strip_snake_effect,
    led_strip_rainbow_effect,
    led_strip_color_effect,
    led_strip_blur_effect,
    led_strip_blink_effect,

    display_turn_on,
    display_turn_off,
    display_enable_rotation,
    display_disable_rotation,
    display_rotation_speed,

    display_home_screen,
    display_sensors_screen,
    display_computer_screen,
    display_network_screen,
    display_cpu_screen,
    display_ram_screen,
    display_storage_screen,
};

struct command
{
    command_type type;
    command_output output;
};

typedef struct command command;

#endif // COMMAND_H
