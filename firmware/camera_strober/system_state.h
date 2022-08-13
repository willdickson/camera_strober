#ifndef SYSTEM_STATE_H
#define SYSTEM_STATE_H
#include "averaging_buffer.h"

class SystemState {

    public:
        SystemState();
        void initialize();
        void update_on_loop();
        void update_on_wb_isr();

    protected:

        volatile bool wb_flag_ = false;
        bool is_flying_ = false;
        uint32_t last_wb_t_ = 0;
        uint32_t last_pulse_t_ = 0;
        uint32_t pulse_count_ = 0;
        uint32_t pulse_fired_ = false;
        AveragingBuffer avg_buffer_;

        bool is_new_wb();
};

#endif
