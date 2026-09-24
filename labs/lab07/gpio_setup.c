#define LED0 4     // LED0 on GPIO 4
#define LED1 2     // LED0 on GPIO 2

// Output enable register
volatile unsigned long * GPIO0_output_en = (unsigned long*) 0x10012008;
// Note |=, not =, to avoid disturbing other GPIO pins
*GPIO0_output_en |= (1 << LED0) | (1 << LED1);
