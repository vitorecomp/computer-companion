#ifndef SERIAL_SERVER_H
#define SERIAL_SERVER_H

class SerialServer{

public:
    int get_commands(struct command*);
    void init();
};

#endif // SERIAL_SERVER_H