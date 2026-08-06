/***************************************/
/******   Author:   Anas  Sayed  *******/
/******   File:   timer1 driver  *******/
/***************************************/

#ifndef MCAL_TIMER1_TIMER1_H_
#define MCAL_TIMER1_TIMER1_H_
#include "avr/io.h"
#include "avr/interrupt.h"
#include "Timer1_config.h"
#include "../../Bit_math.h"
#include "../../std_types.h"
typedef enum{
	TMR1_NORMAL_MODE=0,
	TMR1_PWM_PHASE_CORRECT_8BIT_MODE,
	TMR1_PWM_PHASE_CORRECT_9BIT_MODE,
	TMR1_PWM_PHASE_CORRECT_10BIT_MODE,
	TMR1_CTC_OCR1A_MODE,
	TMR1_PWM_FAST_MODE_8BIT,
	TMR1_PWM_FAST_MODE_9BIT,
	TMR1_PWM_FAST_MODE_10BIT,
	TMR1_PWM_PHASE_FRQ_ICR1_MODE,
	TMR1_PWM_PHASE_FRQ_OCR1A_MODE,
	TMR1_PWM_PHASE_CORRECT_ICR1_MODE,
	TMR1_PWM_PHASE_CORRECT_OCR1A_MODE,
	TMR1_CTC_ICR1_MODE,
	REVERSED,
	TMR1_PWM_FAST_MODE_ICR1,
	TMR1_PWM_FAST_MODE_OCR1A
}TMR1_mode;




#define TIMER1_SET_MODE(_MODE)             (TCCR1A = _MODE);



void Timer1_Init(uint8 mode ,uint8 outputa,uint8 outputb);
void Timer1_Interrupt_Enable();
void Timer1_SetCallBack(void (*tmr1_ptf)(void));
#endif /* MCAL_TIMER1_TIMER1_H_ */
