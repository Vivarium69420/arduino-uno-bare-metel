#include "avr/sfr_defs.h"
#include <avr/io.h>
#include <stdbool.h>
#include <util/delay.h>

#define BLINK_MS 1000

/* LED_BUILTIN PB5
 *
 * Port Pin Condiguration
 * DDxn | PORTxn |   I/O  | Comment
 *   1  |   0    | Output | Low
 *   1  |   1    | Output | High
 * */

int main(void) {
  // Set up
  DDRB |= _BV(PORTB5);

  while (true) {
    PORTB |= _BV(PORTB5);
    _delay_ms(BLINK_MS);

    PORTB &= ~_BV(PORTB5);
    _delay_ms(BLINK_MS);
  }
}
