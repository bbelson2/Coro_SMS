// State-machine version
volatile int state = 0; // state variable
float tem;              // global data cache

void sensor_task() {
  for (;;) {
    switch (state) {
    case 1: request_temp(TEMP_PIN);
      state = 2; break;
    case 2: /* waiting */ break;
    case 3: process_data(tem);
      state = 1; break;
    }
  }
}
void isr() {
  /* ... copy data from register to tem ... */
  state = 3;
}



// Async/await version
void sensor_task() {
  for (;;) {
    float tem = co_await request_temp_async(
      TEMP_PIN);
    process_data(tem);
  }
}
