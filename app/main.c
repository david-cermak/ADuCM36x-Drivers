/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus)
 * Copyright (c) 2014 Liviu Ionescu.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom
 * the Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

// ----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "adi_processor.h"
#include "core_cm3.h"
#include "FreeRTOS.h"
#include "task.h"

// ----------------------------------------------------------------------------


// ----------------------------------------------------------------------------
#define TIMER_FREQUENCY_HZ (1000u)
// ----- main() ---------------------------------------------------------------
static	int i =0;

static void check_task( void *pvParameters )
{
	int x = 0;
	while (1)
	{
		i++;
	    if (i%2)
	       {GP0SET_SET1_BBA = 1;}
	    else
	       {GP0CLR_CLR1_BBA = 1;}

		vTaskDelay( 10 );
	}
}


int
main()
{
	SystemCoreClockUpdate(); // SystemCoreClock in bss, cleared by _start
	SysTick_Config(SystemCoreClock / TIMER_FREQUENCY_HZ);

	// Setup GPIO
	pADI_GP0->GPCON = (pADI_GP0->GPCON & ~GP0CON_CON1_MSK) | GP0CON_CON1_GPIO;
	GP0OEN_OEN1_BBA = 1;

	// Create simple task
	xTaskCreate( check_task, "Check", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY, NULL );

	// Start freeRTOS
	vTaskStartScheduler();

	return 0;

}


// ----------------------------------------------------------------------------
