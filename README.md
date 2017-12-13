Only works on ATMega32u4 based arduinos (e.g. Leonardo, Micro), because USB HID functionality is needed. 

Needs HID Joystick library from here: https://github.com/MHeironimus/ArduinoJoystickLibrary

SBUS library from here: https://github.com/zendes/SBUS
BUT with some lines changed to make it work on ATMEga32u4:

Lines 11 to 17 need to be changed from this:

               TCCR2A  = 0;
               TCCR2B  = 0;
               TCNT2   = 0;
               OCR2A   = 249;
               TCCR2A |= (1 << WGM21);
               TCCR2B |= (1 << CS22);
               TIMSK2 |= (1 << OCIE2A);

to this:
               TCCR0A  = 0;
               TCCR0B  = 0;
               TCNT0   = 0;
               OCR0A   = 249;
               TCCR0A |= (1 << WGM01);
               TCCR0B |= (1 << CS00);
               TIMSK0 |= (1 << OCIE0A);
               
               
How to use:

Connect the SBUS pin of your receiver to the serial RX pin of the Arduino using an inverter, 
Vcc to the Arduino 5V pin, GND to the Arduino GND.
Upload the sketch. Profit. 

