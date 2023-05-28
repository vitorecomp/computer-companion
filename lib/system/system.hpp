#ifndef SYSTEM_H
#define SYSTEM_H

struct sensors_state
{
    uint16_t potentiometer_1;
    uint16_t potentiometer_2;
    boolean key_1_up;
    boolean key_1_down;
    boolean key_2_up;
    boolean key_2_down;
    uint16_t power_input;
    uint16_t hd_input;
    boolean stateful_key;
    boolean ir_sensor;
};


struct filtered_sensors
{
    double potentiometer_1;
    double potentiometer_2;
    double hd_input;
};


struct system_state
{
    struct sensors_state sensors;
    struct filtered_sensors filtered_sensors;

    long lastPrint;
};

typedef struct system_state system_state;

#endif // SYSTEM_H