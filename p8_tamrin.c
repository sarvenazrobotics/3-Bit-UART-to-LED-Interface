#include <mega328p.h>
#include <stdio.h>
#include <delay.h>
#include <alcd.h>

// Using Arduino pins 2-6 (Port D bits 2-6)
#define LED_DDR DDRD
#define LED_PORT PORTD

void main(void)
{
    unsigned char led_buffer[3] = {0};
    unsigned char index = 0;
    char received_char;
    unsigned char new_led_state = LED_PORT & ~((1<<2)|(1<<3)|(1<<4)); // clear bits 2,3,4
    
    // Initialize LED pins (Port D bits 2-6 as outputs)
    // Bits: 7-6-5-4-3-2-1-0 ? We want bits 2,3,4,5,6
    LED_DDR |= (1<<2) | (1<<3) | (1<<4) ;
    LED_PORT = 0x00;
    
    // USART initialization
    UBRR0H = 0x00;
    UBRR0L = 0x67;    // 9600 baud
    UCSR0B = (1<<RXEN0) | (1<<TXEN0);
    UCSR0C = (1<<UCSZ01) | (1<<UCSZ00);
    
    printf("3-LED Buffer (Pins 2-6) Ready!\r\n");
    printf("Enter 3 bits (0/1) + Enter:\r\n");
    
    while(1)
    {
        if(UCSR0A & (1<<RXC0))
        {
            received_char = UDR0;
            
            if(received_char == 10 || received_char == 13)  // Enter or Carriage Return
            {
                if(led_buffer[0]) new_led_state |= (1<<2);
                if(led_buffer[1]) new_led_state |= (1<<3);
                if(led_buffer[2]) new_led_state |= (1<<4);
                LED_PORT = new_led_state;
                
               
                printf("LEDs set: %d%d%d\r\n", led_buffer[0], led_buffer[1], led_buffer[2]);
                printf("\r\nBuffer Updated!\r\n");
                index = 0;
            }
            else if(index < 3)
            {
                led_buffer[index] = (received_char == '1') ? 1 : 0;
                index++;
                putchar(received_char);
            }
        }
        delay_ms(10);
    }
}