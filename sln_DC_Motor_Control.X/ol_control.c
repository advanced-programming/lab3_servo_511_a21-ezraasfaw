/*
 *		ol_control.c
 *			
 * Definition Implementation of an open loop controller.
 * 
 * Author                Date        Version     Description
 * Ezra-Fikru Asfaw      10/29/2021     1.0
 */

#include "Tick_core.h"
#include "DCMotor_model3.h"


#define TICKS_ONE_MS    TICKS_PER_SECOND/100
#define TICKS_TEN_MS    TICKS_PER_SECOND/1000

static int adc;
static int stamp;
static int pwm_test;//TEST VALUES

void ol_control(void){ 

 

if(TickDiff(stamp) > TICKS_TEN_MS){ 

 

/* Do read ADC 					*/ 
adc = readADC(2);
 

/* Do read re-scale the read value 	*/ 


pwm_test = (adc * 20000)/1023;
pwm_test = pwm_test - 10000;


 

/* Do set the PWM  				*/ 

 set_pwm(pwm_test);
 stamp = TickGet();

/* Display info to LCD ? Target mode only  */ 

 
} 

} 
