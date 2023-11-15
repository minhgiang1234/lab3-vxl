/*
 * software_timer.c
 *
 *  Created on: Nov 15, 2023
 *      Author: giang
 */


#include "software_timer.h"

#define TIME_CYCLE 10

int timer1_counter = 0;
int timer1_flag = 0;
int timer_led_counter = 0;
int timer_led_flag = 0;
int timer_seg_counter = 0;
int timer_seg_flag = 0;

void setTimer1(int duration){
	timer1_counter = duration/TIME_CYCLE;
	timer1_flag = 0;
}

void timer1Run(){
	if (timer1_counter > 0) timer1_counter--;
	if (timer1_counter <= 0) {
		timer1_flag = 1;
	}
}

void setTimerLed(int duration){
	timer_led_counter = duration / TIME_CYCLE;
	timer_led_flag = 0;
}

void timerLedRun(){
	if (timer_led_counter > 0) timer_led_counter--;
	if (timer_led_counter <= 0) {
		timer_led_flag = 1;
	}
}

void setTimerSeg(int duration){
	timer_seg_counter = duration / TIME_CYCLE;
	timer_seg_flag = 0;
}

void timerSegRun(){
	if (timer_seg_counter > 0) timer_seg_counter--;
	if (timer_seg_counter <= 0) {
		timer_seg_flag = 1;
	}
}
