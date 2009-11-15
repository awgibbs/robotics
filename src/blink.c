#include <avr/io.h>
#define F_CPU 8000000
#include <util/delay.h>

int sleep() {
  int i = 0;

  for (i = 0; i < 100; ++i)
    _delay_ms(10);

  return 1;

  /*
  int i = 0, j = 0;

  for (i = 256; i > 0; --i) {
    for (j = 256; j > 0; --j) {
    }
  }

  return i + j;
  */
}

int main(void)
{
  // Set Port D pins as all outputs
  DDRD = 0xff;

  while (1) {
    // Set all Port D pins as LOW
    PORTD = 0;

    sleep();

    // Set all Port D pins as HIGH
    PORTD = 0xff;

    sleep();
  }

  return 0;
}
