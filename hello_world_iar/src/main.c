/*
 * Copyright (c) 2013 - 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2018 NXP
 * All rights reserved.
 *
 * THIS SOFTWARE IS PROVIDED BY NXP "AS IS" AND ANY EXPRESSED OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL NXP OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

//#include "clock_manager.h"
//#include "pins_driver.h"
/*
	Important note:
	The default debug probe is "Simulator". Prior to running the project on the board,
	the desired debug probe has to be configured in Project Options -> Debugger.
 */
 
/* This example is setup to work by default with EVB. To use it with other boards
   please comment the following line
 */

#define EVB

#ifdef EVB
	#define LED_PORT 	PORTD
	#define GPIO_PORT	PTD
	#define PCC_CLOCK	PORTD_CLK
	#define LED1		15U
	#define LED2		16U
#else
	#define LED_PORT 	PORTC
	#define GPIO_PORT	PTC
	#define PCC_CLOCK	PORTC_CLK
	#define LED1		0U
	#define LED2		1U
#endif

void delay(volatile int cycles)
{
    /* Delay function - do nothing for a number of cycles */
    while(cycles--);
}

int main(void)
{
  /* Configure clocks for PORT */
 // CLOCK_DRV_SetModuleClock(PCC_CLOCK, NULL);
  /* Set pins as GPIO */
 // PINS_DRV_SetMuxModeSel(LED_PORT, LED1, PORT_MUX_AS_GPIO);
 // PINS_DRV_SetMuxModeSel(LED_PORT, LED2, PORT_MUX_AS_GPIO);

  /* Output direction for LED0 & LED1 */
 // PINS_DRV_SetPinsDirection(GPIO_PORT, ((1 << LED1) | (1 << LED2)));

  /* Set Output value LED0 & LED1 */
 // PINS_DRV_SetPins(GPIO_PORT, 1 << LED1);
 // PINS_DRV_ClearPins(GPIO_PORT, 1 << LED2);

  for (;;)
  {
      /* Insert a small delay to make the blinking visible */
      delay(720000);

      /* Toggle output value LED0 & LED1 */
    //  PINS_DRV_TogglePins(GPIO_PORT, ((1 << LED1) | (1 << LED2)));
  }
}
