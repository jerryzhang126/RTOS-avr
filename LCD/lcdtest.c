/*
 * Assignment #5
 *
 * Author: Santiago Pina Ros
 *
 * Size of the code: 1926 bytes
 *
 * Useful links:
 * http://www2.cs.uidaho.edu/~rinker/cs452/char-comm.pdf
 * http://www.nongnu.org/avr-libc/user-manual/group__avr__stdio.html
 */


#include "lcd.h"

#include <ctype.h>
#include <stdio.h>

#include <avr/io.h>
#include <avr/pgmspace.h>

#include <util/delay.h>

/*
 * Send character c to the LCD display. 
 */
int lcd_putchar(char c, FILE *unused){

    if(c == '\n'){
        lcd_wait_ready();
        lcd_second_row(); // If we want to print more than one row we need to change this.
    }
    else{
        lcd_wait_ready();
        lcd_outdata(c);
    }
    return 0;
}

FILE lcd_str = FDEV_SETUP_STREAM(lcd_putchar, NULL, _FDEV_SETUP_WRITE);

int main(void){
  
  lcd_init();
  stdout =  &lcd_str;

  printf("Hello\nWorld!");
  lcd_powerdown();

  return 0;
}
