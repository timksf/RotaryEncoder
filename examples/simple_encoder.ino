#include "RotaryEncoder.hpp"

#define SW PB0  //digital pin 8
#define DT PB3  //digital pin 11
#define CLK PB4 //digital pin 12

RotaryEncoder encoder;

void setup(){

    //set encoder pins as input
    DDRB &= ~(1 << SW);
    DDRB &= ~(1 << DT);
    DDRB &= ~(1 << CLK);

    //enable internal pullup for all encoder pins
    PORTB |= (1 << SW);
    PORTB |= (1 << DT);
    PORTB |= (1 << CLK);

    Serial.begin(9600);

}

void loop(){

    state_dt = (PINB & (1 << DT));      //read state of dt pin
    state_clk = (PINB & (1 << CLK));    //read state of clk pin

    encoder.update(state_dt, state_clk);

    if(encoder.new_pos()){
        Serial.println(encoder.pos());
    }

}
