#ifndef CONNECTED_SENSORS_H
#define CONNECTED_SENSORS_H


//using the analog pins
#define POTENTIOMETER_1_PIN A0 //ok
#define POTENTIOMETER_2_PIN A1 //ok

#define KEY_1_UP_PIN A2 
#define KEY_1_DOWN_PIN A3 
#define KEY_2_UP_PIN A4
#define KEY_2_DOWN_PIN A5

#define POWER_INPUT A6
#define HD_INPUT A7



//state full key
#define STATEFUL_KEY 2


//displays
#define NOKIA_DISPLAY_RST 3 //ok
#define NOKIA_DISPLAY_CE  4 //ok
#define NOKIA_DISPLAY_DC  5 //ok
#define NOKIA_DISPLAY_DIN 6 //ok
#define NOKIA_DISPLAY_CLK 7 //ok
#define NOKIA_DISPLAY_LGT 8 //ok

#define IR_SENSOR_PIN 9 //ok

//NEO_STRIP_PORTS_H
#define N_LEDS 18 //ok
#define STRIP_PIN 10 //ok

//BUTTON 3 -> power
//BUTTON 4 -> reset
#define POWER_OUTPUT 11
#define RESET_OUTPUT 12

#define LED_PIN 13



#endif // CONNECTED_SENSORS_H