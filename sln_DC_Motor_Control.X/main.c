/*
 *		main.c
 *			
 * Lab to control the position of a BDC motor
 * 
 * Author                Date        Version     Description
 * Ezra-Fikru Asfaw      10/29/2021     1.0         I implemented a scale to retrieve the correct pwm in a new file called ol_control.c.
 * Ezra-Fikru Asfaw      11/02/2021     2.0         I modified the code in o_control so that it work in target mode by implementing a loop control task on a real motor. 
 *                                                  It was able to display properly PV and PVM on the board LCD.
 */

#include <xc.h>
#include <stdint.h>
#include <stdio.h>
#include "initBoard.h"
#include "console32.h"
#include "DCMotor_model3.h"
#include "pwm.h"
#include "pv_measure.h"
#include "configuration.h"
#include "public.h" 
#include "Tick_core.h"

int main(void){
    /* init IOs */
    initIO();
    
    /* init position measure */
    initPV_measure();
    
    /* init UARTs */
    initUart1();
    initUart2();
    
    /* init LCD */
    LCDInit();
    
    /* ADC init*/
    initADC();
 
    /* init PWM */
    initPWM();
    
    /* Test Uarts */
    fprintf2(C_UART1, "Uart1 says: Board reset \n");
    fprintf2(C_UART2, "Uart2 says: Board reset\n");
    
    /* Super loop */
	while (1){
        // call tasks here
        ol_control();
    }   
}


