#include "constants.h"
#include "system_state.h"
#include "Streaming.h"


SystemState system_state;

void setup() {
  Serial.begin(115200);
  system_state.initialize();
  attachInterrupt(digitalPinToInterrupt(WB_PIN), wb_isr, FALLING);
  //attachInterrupt(digitalPinToInterrupt(WB_PIN), wb_isr, RISING);
}

void loop() {
    system_state.process_messages();
    system_state.update_on_loop();
}

void wb_isr() {
    system_state.update_on_wb_isr();
}

