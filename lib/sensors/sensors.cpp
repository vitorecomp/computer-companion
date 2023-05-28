#include <sensors.hpp>

void init_time_interrupts();
void printSensors(system_state *state);


void init_sensors(system_state *state)
{
    pinMode(POWER_OUTPUT, OUTPUT);
    digitalWrite(POWER_OUTPUT, LOW);
    pinMode(RESET_OUTPUT, OUTPUT);
    digitalWrite(RESET_OUTPUT, LOW);

    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, HIGH);

    // init the sensors pins
    pinMode(IR_SENSOR_PIN, INPUT);

    // computer input
    pinMode(POWER_INPUT, INPUT);
    pinMode(HD_INPUT, INPUT);

    // init the keys
    pinMode(KEY_1_UP_PIN, INPUT);
    pinMode(KEY_2_UP_PIN, INPUT);
    pinMode(KEY_1_DOWN_PIN, INPUT);
    pinMode(KEY_2_DOWN_PIN, INPUT);
    pinMode(STATEFUL_KEY, INPUT);

    // init the potentiometer
    pinMode(POTENTIOMETER_1_PIN, INPUT);
    pinMode(POTENTIOMETER_2_PIN, INPUT);

    // init the interrupts
    init_time_interrupts();
}

void init_time_interrupts(){

    cli();//stop interrupts

    //set timer1 interrupt at 1kHz
    TCCR1A = 0;// set entire TCCR1A register to 0
    TCCR1B = 0;// same for TCCR1B
    TCNT1  = 0;//initialize counter value to 0
    // set compare match register for 1hz increments
    OCR1A = 15;// = (16*10^6) / (10*1024) - 1 (must be <65536)
    // turn on CTC mode
    TCCR1B |= (1 << WGM12);
    // Set CS10 and CS12 bits for 1024 prescaler
    TCCR1B |= (1 << CS12) | (1 << CS10);  
    // enable timer compare interrupt
    TIMSK1 |= (1 << OCIE1A);

    sei();//allow interrupts
}

void sensors_execute_command(command *command, system_state *state)
{
    if(command->type == command_type::computer_turn_on){
        Serial.println("out: receive command to turn on the computer");
        digitalWrite(POWER_OUTPUT, HIGH);
        delay(1000);
        digitalWrite(POWER_OUTPUT, LOW);
        delay(10000);
    }
    // execute the command
}

uint8_t sensors_get_commands(command *command, uint8_t actual_command, system_state *state)
{
    uint8_t num_commands = 0;
    printSensors(state);

    if(state->sensors.power_input < MIN_HIGH_VALUE && state->sensors.stateful_key){
        //turn on the computer
        command[actual_command + num_commands].output = command_output::sensor_output;
        command[actual_command + num_commands].type = command_type::computer_turn_on;

        num_commands++;
        Serial.println("out: send command to turn on the computer");
    }

    // execute the command
    return num_commands;
}

void printSensors(system_state *state){
    unsigned long time = millis();
    // print out the value you read:
    if(time - state->lastPrint < 5000)
        return;
    Serial.print("the pin IR_SENSOR_PIN:");
    Serial.println(state->sensors.ir_sensor);

    Serial.print("the pin POWER_INPUT:");
    Serial.println(state->sensors.power_input);
    Serial.print("the pin HD_INPUT:");
    Serial.println(state->sensors.hd_input);

    Serial.print("the pin KEY_1_UP_PIN:");
    Serial.println(state->sensors.key_1_up);
    Serial.print("the pin KEY_2_UP_PIN:");
    Serial.println(state->sensors.key_2_up);
    Serial.print("the pin KEY_1_DOWN_PIN:");
    Serial.println(state->sensors.key_1_down);
    Serial.print("the pin KEY_2_DOWN_PIN:");
    Serial.println(state->sensors.key_2_down);

    Serial.print("the pin STATEFUL_KEY:");
    Serial.println(state->sensors.stateful_key);

    Serial.print("the pin POTENTIOMETER_1_PIN:");
    Serial.println(state->sensors.potentiometer_1);
    Serial.print("the pin POTENTIOMETER_2_PIN:");
    Serial.println(state->sensors.potentiometer_2);

    Serial.print("the filter POTENTIOMETER_1_PIN:");
    Serial.println(state->filtered_sensors.potentiometer_1);
    Serial.print("the filter POTENTIOMETER_2_PIN:");
    Serial.println(state->filtered_sensors.potentiometer_2);
    Serial.print("the filter HD_INPUT:");
    Serial.println(state->filtered_sensors.hd_input);
    Serial.println("====================================");

    state->lastPrint = time;
}

void read_sensors(system_state *state){
    state->sensors.ir_sensor = digitalRead(IR_SENSOR_PIN) == HIGH ? true : false;
    state->sensors.power_input = analogRead(POWER_INPUT);
    state->sensors.hd_input = analogRead(HD_INPUT);
    state->sensors.key_1_up = digitalRead(KEY_1_UP_PIN) == HIGH ? true : false;
    state->sensors.key_2_up = digitalRead(KEY_2_UP_PIN) == HIGH ? true : false;
    state->sensors.key_1_down = digitalRead(KEY_1_DOWN_PIN) == HIGH ? true : false;
    state->sensors.key_2_down = digitalRead(KEY_2_DOWN_PIN) == HIGH ? true : false;
    state->sensors.stateful_key = digitalRead(STATEFUL_KEY) == HIGH ? true : false;
    state->sensors.potentiometer_1 = analogRead(POTENTIOMETER_1_PIN);
    state->sensors.potentiometer_2 = analogRead(POTENTIOMETER_2_PIN);
}

void run_sensors_average(system_state *state){
    state->filtered_sensors.potentiometer_1 = state->filtered_sensors.potentiometer_1 * SAMPLES + (double)state->sensors.potentiometer_1 - state->filtered_sensors.potentiometer_1;
    state->filtered_sensors.potentiometer_1 /= SAMPLES;
    state->filtered_sensors.potentiometer_2 = state->filtered_sensors.potentiometer_2 * SAMPLES + (double)state->sensors.potentiometer_2 - state->filtered_sensors.potentiometer_2;
    state->filtered_sensors.potentiometer_2 /= SAMPLES;
    state->filtered_sensors.hd_input = state->filtered_sensors.hd_input * SAMPLES + (double)state->sensors.hd_input - state->filtered_sensors.hd_input;
    state->filtered_sensors.hd_input /= SAMPLES;
}
