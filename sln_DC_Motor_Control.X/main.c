/*
 *		main.c
 *			
 * Lab to control the position of a BDC motor
 * 
 * Author       Date        Version     Description
 * 
 */

#include <xc.h>
#include <stdint.h>
#include "initBoard.h"
#include "console32.h"
#include "DCMotor_model3.h"
#include <stdio.h>
#include "pwm.h"
#include "pv_measure.h"
#include "configuration.h"
#include "public.h"


int main(void){
    /* init IOs */
    //initIO();
    
    /* init position measure */
    //initPV_measure();
    
    /* init UARTs */
    initUart1();
    initUart2();
    
    /* init LCD */
    //LCDInit();
    
    /* ADC init*/
    //initADC();
 
    /* init PWM */
    //initPWM();
    
    /* Test Uarts */
    fprintf2(C_UART1, "Uart1 says: Board reset \n");
    fprintf2(C_UART2, "Uart2 says: Board reset\n");
    
    /* Super loop */
	while (1){
        // call tasks here
    }   
}


