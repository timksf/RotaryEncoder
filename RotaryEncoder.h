#ifndef ROTARY_ENCODER_HPP
#define ROTARY_ENCODER_HPP

#include <stdint.h>

class RotaryEncoder{
private:     

    static const uint8_t s_FINALSTATE_CW;
    static const uint8_t s_FINALSTATE_CCW;

    static const int8_t s_transition_table[32];

public:

    RotaryEncoder();

    RotaryEncoder(int32_t pos);

    void update(uint8_t state_a, uint8_t state_b);

    bool inline new_pos(){ return m_new_pos; };

    int32_t inline pos(bool consume = false){ if(consume) m_new_pos = false; return m_pos; }

    uint8_t m_state{ 0 };
private:

    int32_t m_pos{ 0 };
    bool m_new_pos{ false };

};



#endif
