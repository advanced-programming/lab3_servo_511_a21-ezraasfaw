/*
 *		pid_control.c
 *			
 * Definition Implementation of an open loop controller.
 * 
 * Author                Date        Version     Description
 * Ezra-Fikru Asfaw      11/09/2021     1.0
 */
#include <stdio.h>
#include "Tick_core.h"
#include "DCMotor_model3.h"
#include "console32.h"


#define TICKS_ONE_MS    TICKS_PER_SECOND/100
#define TICKS_TEN_MS    TICKS_PER_SECOND/1000
#define KP    30
#define KI    0
#define WINDUP 0


static int sp;
static int stamp;
static int pwm_value;//TEST VALUES
static int pv;
static int pwm = 0;
static int buf[100];
static float e; //error (anti wipup))
static float PTerm;
static float ITerm;
static int on_time;

void pid_control(void){ 

 

if(TickDiff(stamp) > TICKS_TEN_MS){ 

 

/* Do read ADC 					*/ 
    
sp = readADC(2);
 

/* Do read re-scale the read value 	*/ 

//pwm_value = (sp * 20000)/1023;
//pwm_value = pwm_value - 10000;


pv = get_pv(); 
e = sp - pv;

ITerm = ITerm + KI * e;

if(ITerm>WINDUP) {
    ITerm=WINDUP;
}

if(ITerm<-WINDUP){
    ITerm=-WINDUP;
}

PTerm = KP * e;


/* Do set the PWM  				*/ 

on_time = PTerm + ITerm;
set_pwm(on_time);

 //set_pwm(pwm_value);
 stamp = TickGet();

/* Display info to LCD ? Target mode only  */ 

    sprintf(buf,"PV: %d    \nSP: %d    \n", pv, sp);
 fprintf2(C_LCD, buf);
 
} 

} 

