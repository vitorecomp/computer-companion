#include <serial_server.hpp>

void SerialServer::init()
{
    // init the serial port
    Serial.begin(9600);
}

int SerialServer::get_commands(struct command *command)
{
    // execute the command
    return 0;
}

void serial_server_execute_command(struct command *command, SerialServer *serial_server)
{
    //  serial_server->init();
}