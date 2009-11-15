#include <avr/io.h>
#define F_CPU 8000000
#include <util/delay.h>

int neutral() {
  int i = 0;

  for (i = 0; i < 100; ++i)
    _delay_us(15);

  return 1;
}

int skew() {
  int i = 0;

  for (i = 0; i < 100; ++i)
    _delay_us(20);

  return 1;
}

int main(void)
{
  int i, j;

  // Set Port B pins as all outputs
  DDRB = 0xff;

  while (1) {
    for (i = 0; i < 60; ++i) {
      // Set all Port B pins as LOW
      PORTB = 0;
      
      for (j = 0; j < 10; ++j)
	neutral();
      
      // Set all Port B pins as HIGH
      PORTB = 0xff;
      
      neutral();
    }

    for (i = 0; i < 60; ++i) {
      // Set all Port B pins as LOW
      PORTB = 0;
      
      for (j = 0; j < 10; ++j)
	skew();

      // Set all Port B pins as HIGH
      PORTB = 0xff;
      
      skew();
    }
  }

  return 0;
}
