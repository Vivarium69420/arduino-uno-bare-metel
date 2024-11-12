#include "avr/sfr_defs.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdbool.h>

#define CLOCK_RATE 16000000
#define PRESCALER 256

// TIMER1 compare interrupt routine when
ISR(TIMER1_COMPA_vect) { PORTB ^= _BV(PORTB5); }

int main(void) {

  DDRB |= _BV(PORTB5);

  TCCR1B |= _BV(WGM12) | _BV(CS12); // CTC, TOP = OCR1A, prescaler = 256

  TIMSK1 |= _BV(OCIE1A); // Interrupt when TCNT1 == OCR1A

  OCR1A = ((CLOCK_RATE * 0.1) / PRESCALER) - 1; // Blink every 1s

  sei(); // Enable interrupt

  while (true) {
  }
  return 0;
}
