// lab8starter.c
// Josh Brake and David_Harris@hmc.edu
// jbrake@hmc.edu
// 1/20/2020

#include "EasyREDVIO_ThingPlus.h"

int main(void)
{
    volatile uint8_t debug;
    volatile int16_t x, y, disx, disy;

    spiInit(10, 1, 1); // Initialize SPI pins

    // Setup the LIS3DH
    spiWrite(0x20, 0x77); // highest conversion rate, all axis on
    spiWrite(0x23, 0x88); // block update, and high resolution

    // Check WHO_AM_I register. should return 0x33    
    debug = spiRead(0x0F);
    
    while(1)
    {
        // Collect the X and Y values from the LIS3DH 	
  		x = spiRead(0x28) | (spiRead(0x29) << 8);
		y = spiRead(0x2A) | (spiRead(0x2B) << 8);

        delayLoop(100);
    }
}