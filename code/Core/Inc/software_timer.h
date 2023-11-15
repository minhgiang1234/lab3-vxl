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

void setTimer1(int duration);
void timer1Run();

#endif /* INC_SOFTWARE_TIMER_H_ */
