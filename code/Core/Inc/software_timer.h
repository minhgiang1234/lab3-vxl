/*
 * software_timer.h
 *
 *  Created on: Nov 15, 2023
 *      Author: giang
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer1_counter;
extern int timer1_flag;

extern int timer_led_flag;
extern int timer_led_counter;

extern int timer_seg_flag;
extern int timer_seg_counter;

void setTimer1(int duration);
void timer1Run();

void timerLedRun();
void setTimerLed(int duration);
void timerSegRun();
void setTimerSeg(int duration);

#endif /* INC_SOFTWARE_TIMER_H_ */
