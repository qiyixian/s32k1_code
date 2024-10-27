/*!
** Copyright 2020 NXP
** @file main.c
** @brief
**         Main module.
**         This module contains user's application code.
*/
/*!
**  @addtogroup main_module main module documentation
**  @{
*/
/* MODULE main */


/* Including necessary configuration files. */
#include "sdk_project_config.h"
#include "pin_mux.h"
volatile int exit_code = 0;
/* User includes */
void TestDelay(int delay);
void TestDelay(int delay)
{
    static volatile int DelayTimer = 0;
    while(DelayTimer<delay)
    {
        DelayTimer++;
    }
    DelayTimer=0;
}
/*!
  \brief The main function for the project.
  \details The startup initialization sequence is the following:
 * - startup asm routine
 * - main()
*/
int main(void)
{
    /* Write your code here */
CLOCK_SYS_Init(g_clockManConfigsArr, CLOCK_MANAGER_CONFIG_CNT,
 						g_clockManCallbacksArr, CLOCK_MANAGER_CALLBACK_CNT);
   CLOCK_SYS_UpdateConfiguration(0U, CLOCK_MANAGER_POLICY_AGREEMENT);

	 PINS_DRV_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);
    for(;;)
    {

    	PINS_DRV_WritePin(PTE,8,0);
        TestDelay(300000);
    	PINS_DRV_WritePin(PTE,8,1);
         TestDelay(300000);
        if(exit_code != 0)
        {
            break;
        }
    }
    return exit_code;
}

/* END main */
/*!
** @}
*/
