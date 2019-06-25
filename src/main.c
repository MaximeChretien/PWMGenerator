#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint8_t ADCflag = 1, ADCchannel = 1;
volatile uint16_t pot1=0, pot2=0;

void main() {
    //Init SP
    SP = RAMEND;

    //Disable global interrupt
    cli();

    //Set PB0 and PB1 as output and PB3 and PB4 as input
    DDRB |= (1 << DDB0) | (1 << DDB1); 
    DDRB &= ~(0 << DDB3) & ~(0 << DDB4); 
    
    //Set ADC Reference to Vcc and use right adjust for the result
    ADMUX &= ~(1 << REFS1) & ~(1 << REFS0) & ~(1 << ADLAR) & ~(1 << REFS2);
    
    //Enable ADC with interrupt and without auto trigger using ck/64 prescaler
    ADCSRA |= (1 << ADEN) | (1 << ADIE) | (1 << ADPS2) | (1 << ADPS1);
    ADCSRA &= ~(1 << ADATE) & ~(1 << ADPS0);
    
    //Set timer0 as Fast-PWM in non inverting mode
    TCCR0A |= (1 << COM0A1) | (1 << COM0B1) | (1 << WGM01) | (1 << WGM00);
    TCCR0A &= ~(1 << COM0A0) & ~(1 << COM0B0);
    
    //Enable timer0 with no prescaler
    TCCR0B &= ~(1 << FOC0A) & ~(1 << FOC0B) & ~(1 << WGM02) & ~(1 << CS02) & ~(1 << CS01);
    TCCR0B |= (1 << CS00);
    
    //Init duty cycle
    OCR0A = 0;
    OCR0B = 0;

    //Enable global Interrupt
    sei();

    while(1) {
        //Update duty cycle (pot1 and pot2 are between 0 and 1024
        //And we want something between 0 and 256
        OCR0A = pot1/4;
        OCR0B = pot2/4;

        //Set ADC channel and start read if ready
        if(ADCflag == 1) {
            ADCflag = 0; //Disable new read until last one finished
            if(ADCchannel == 1) { //ADC2 (PB4)
                ADMUX &= ~(1 << MUX3) & ~(1 << MUX2) & ~(1 << MUX0);
                ADMUX |= (1 << MUX1);

                ADCSRA |= (1 << ADSC);
            } else { //ADC3 (PB3)               
                ADMUX &= ~(1 << MUX3) & ~(1 << MUX2);
                ADMUX |= (1 << MUX1) | (1 << MUX0);

                ADCSRA |= (1 << ADSC);
            }
        }        
    }
}

//ADC interrupt 
ISR(ADC_vect) {
    //Copy the result to the correct variable
    //And set the orther channel for the next read
    if(ADCchannel == 1) {
        pot1 = ADC; 
        ADCchannel = 0;
    } else {
        pot2 = ADC;
        ADCchannel = 1;
    }

    ADCflag = 1; //Ready for new read
}

