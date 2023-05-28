#ifndef SERIAL_SERVER_H
#define SERIAL_SERVER_H

#include <Arduino.h>
class SerialServer{

public:
    int get_commands(struct command*);
    void init();
};

void serial_server_execute_command(struct command *, SerialServer *);

#endif // SERIAL_SERVER_H