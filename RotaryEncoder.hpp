#ifndef ROTARY_ENCODER_HPP
#define ROTARY_ENCODER_HPP

class RotaryEncoder{
private:     

    static const uint8_t s_FINALSTATE_CW;
    static const uint8_t s_FINALSTATE_CCW;

    static const int8_t s_transition_table[32];

public:

    RotaryEncoder(){};

    RotaryEncoder(int32_t pos){
        m_pos = pos;
    }

    void update(uint8_t state_a, uint8_t state_b){
        uint8_t input = state_a | (state_b << 1);

        m_state += s_transition_table[(input | (m_state << 2))];

        if((m_state & (1 << 2)) && (m_state & (1 << 1))){
            if(m_state == s_FINALSTATE_CW){
                m_pos++;
            }else if(m_state == s_FINALSTATE_CCW){
                m_pos--;
            }
            m_new_pos = true;
        }

    }

    bool new_pos(){ return m_new_pos; };

    int32_t pos(){ m_new_pos = false; return m_pos; }

private:

    uint8_t m_state{ 0 };
    int32_t m_pos{ 0 };
    bool m_new_pos{ false };

};

const uint8_t RotaryEncoder::s_FINALSTATE_CW = 6;
const uint8_t RotaryEncoder::s_FINALSTATE_CCW = 7;
const int8_t RotaryEncoder::s_transition_table[] = {
        0, 0, 0, 1,
        -1, 1, 2, 0,
        2, 0, -2, -2,
        2, -3, 0, -3,
        0, -4, 2, -4,
        0, 2, -5, -5,
        -6, -6, -6, -6,
        -7, -7, -7, -7
};

#endif
