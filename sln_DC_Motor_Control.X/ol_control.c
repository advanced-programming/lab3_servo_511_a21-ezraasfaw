/*
 *		ol_control.c
 *			
 * Definition Implementation of an open loop controller.
 * 
 * Author                Date        Version     Description
 * Ezra-Fikru Asfaw      10/29/2021     1.0
 */
#include <stdio.h>
#include "Tick_core.h"
#include "DCMotor_model3.h"
#include "console32.h"


#define TICKS_ONE_MS    TICKS_PER_SECOND/100
#define TICKS_TEN_MS    TICKS_PER_SECOND/1000

static int adc;
static int stamp;
static int pwm_value;//TEST VALUES
static int pv;
static int pwm = 0;
static int buf[100];

void ol_control(void){ 

 

if(TickDiff(stamp) > TICKS_TEN_MS){ 

 

/* Do read ADC 					*/ 
    
adc = readADC(2);
 

/* Do read re-scale the read value 	*/ 

pwm_value = (adc * 20000)/1023;
pwm_value = pwm_value - 10000;


 

/* Do set the PWM  				*/ 

 set_pwm(pwm_value);
 stamp = TickGet();

/* Display info to LCD ? Target mode only  */ 

 pv = get_pv(); 
 
 sprintf(buf,"PV: %d    \nPWM: %d    \n", pv, pwm_value);
 fprintf2(C_LCD, buf);
 
} 

} 
