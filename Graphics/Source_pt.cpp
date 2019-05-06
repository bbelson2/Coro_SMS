
http://dunkels.com/adam/pt/examples.html

static
PT_THREAD(producer(struct pt *pt))
{
  static int produced;
  PT_BEGIN(pt);
  for (produced = 0; produced < NUM_ITEMS; ++produced) {
    PT_SEM_WAIT(pt, &full);
    add_to_buffer(produce_item());
    PT_SEM_SIGNAL(pt, &empty);
  }
  PT_END(pt);
}


static struct pt_sem full, empty;

static
PT_THREAD(producer(struct pt *pt))
{
  // If produced is not declared as static, then 
  // undefined behaviour will occur that will not 
  // be detected by the compiler.
  static int produced;
  PT_BEGIN(pt);
  for (produced = 0; produced < NUM_ITEMS; ++produced) {
    PT_SEM_WAIT(pt, &full);
    add_to_buffer(produce_item());
    PT_SEM_SIGNAL(pt, &empty);
  }
  PT_END(pt);
}

static
PT_THREAD(consumer(struct pt *pt))
{
  static int consumed;
  PT_BEGIN(pt);
  for (consumed = 0; consumed < NUM_ITEMS; ++consumed) {
    PT_SEM_WAIT(pt, &empty);
    consume_item(get_from_buffer());
    PT_SEM_SIGNAL(pt, &full);
  }
  PT_END(pt);
}

//========================================================================

// Extract

static struct pt_sem full, empty;

static
PT_THREAD(producer(struct pt *pt))
{
  static int produced;
  PT_BEGIN(pt);
  for (produced = 0; produced < NUM_ITEMS; ++produced) {
    PT_SEM_WAIT(pt, &full);
    add_to_buffer(produce_item());
    PT_SEM_SIGNAL(pt, &empty);
  }
  PT_END(pt);
}

// a) Protothread example C code

static
PT_THREAD(consumer(struct pt *pt))
{
  // If consumed is not declared as static, then 
  // undefined behaviour will occur that will not 
  // be detected by the compiler.
  static int consumed;
  PT_BEGIN(pt);
  for (consumed = 0; consumed < NUM_ITEMS; ++consumed) {
    PT_SEM_WAIT(pt, &empty);
    consume_item(get_from_buffer());
    PT_SEM_SIGNAL(pt, &full);
  }
  PT_END(pt);
}

static
PT_THREAD(consumer(struct pt *pt))
{
	static int consumed;
	PT_BEGIN(pt);
	for (consumed = 0; consumed < NUM_ITEMS;
		++consumed) {
		PT_SEM_WAIT(pt, &empty);
		consume_item(get_from_buffer());
		PT_SEM_SIGNAL(pt, &full);
	}
	PT_END(pt);
}

// b) C++ example code

task<> consumer(semaphore& sem)
{
  auto producer = async_producer(sem, NUM_ITEMS);
  for co_await(auto consumed : producer)
  {
    consume_item(get_fom_buffer());
  }
}

static struct pt_sem full, empty;

// c) C FSM code
void consumer_task() {
	static int state = 0, consumed = 0;
	switch (state) {
	case 0: if (buffer_empty()) return;
					else {
						consume_item(get_from_buffer());
						state = 1;
					}
					break;
	case 1: 
	}
}


// State-machine example
volatile int state = 0; // state variable
float tem;              // global data cache

void sensor_task() {
  switch (state) {
  case 1: request_temp(TEMP_PIN);
    state = 2; break;
  case 2: /* waiting */ break;
  case 3: process_data(tem);
    state = 1; break;
  }
}
// Interrupt service routine
void isr() {
  /* ... copy data from register to tem ... */
  state = 3;
}
