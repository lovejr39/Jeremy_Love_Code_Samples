//Jeremy Love & Peter Bertola

#include "stm32l476xx.h"
#include "SysClock.h"
#include "UART.h"

#include <string.h>
#include <stdio.h>

// PA.5  <--> Green LED
// PC.13 <--> Blue user button
#define LED_PIN    5
#define BUTTON_PIN 13



void demo_of_printf_scanf(){
	char rxByte;
	printf("Are you enrolled in ECE 202 (Y or N ):\r\n");
	scanf ("%c", &rxByte);
	if (rxByte == 'N' || rxByte == 'n'){
		printf("You should not be here!!!\r\n\r\n");
	}
	else if (rxByte == 'Y' || rxByte == 'y'){
		printf("Welcome!!! \n\r\n\r\n");
	}
}

	
int main(void){

	System_Clock_Init(); // Switch System Clock = 80 MHz
	UART2_Init(); // Communicate with Tera Term
	
	demo_of_printf_scanf();

	// ****************************//
	// USER CODE GOES BELOW
	// ****************************//

	// Configure PA5 (Green LED)
	
		//Enable Clock for Green LED
			RCC -> AHB2ENR &= ~0x00000005 ;
			RCC -> AHB2ENR |= 0x00000005 ;
	
		//Set Mode for Green LED to Output
			GPIOA -> MODER &= ~0x00000C00 ;
			GPIOA -> MODER |= 0x00000400 ;
	
		//Set Output Type for Green LED to Push-Pull
			GPIOA -> OTYPER &= ~0x00000020 ;
			GPIOA -> OTYPER |= 0x00000000 ;
			
		//Set Pull-Up/Pull-Down for Green LED to No-Pullup/No-Pulldown
			GPIOA -> PUPDR &= ~0x00000C00 ;
			GPIOA -> PUPDR |= 0x00000000 ;
	
	// Configure PC13 (Blue User Button)
	
		//Set Mode for Blue User Button to Input
			GPIOC -> MODER &= ~0x0C000000 ;
			GPIOC -> MODER |= 0x00000000 ;
	
		//Set Pull-Up/Pull-Down for Blue User Button to No-Pullup/No-Pulldown
			GPIOC -> PUPDR &= ~0x0C000000 ;
			GPIOC -> PUPDR |= 0x00000000 ;
	
	// Read from PC13 and Set LED light
			
			int ledState = 0 ;
			int pushed = 0 ;
			
			while(1)
			{
				//Read Button State
					uint32_t buttonState = (GPIOC -> IDR & 1UL << 13) == 1UL << 13 ;
		
				//Set Green LED
					if(buttonState == 0)
					{
						if(ledState == 0 && pushed == 0)
						{
							GPIOA -> ODR |= 1UL << 5 ;
							ledState = 1 ;
							pushed = 1 ;
						}
						else if (pushed == 0)
						{
							GPIOA -> ODR &= ~0x00000020 ;
							GPIOA -> ODR |= 0x00000000 ;
							ledState = 0 ;
							pushed = 1 ;
						}
					}
					else
					{
						pushed = 0 ;
					}
			}
		
	// The blue user button is pulled up externally. 
	// The GPIO input is low if the button is pressed down.
}
