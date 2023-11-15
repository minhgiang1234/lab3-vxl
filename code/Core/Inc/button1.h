/*
 * button.h
 *
 *  Created on: Nov 15, 2023
 *      Author: giang
 */

#ifndef INC_BUTTON1_H_
#define INC_BUTTON1_H_


#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

void getKey1Input();
int isButton1Pressed();

#endif /* INC_BUTTON1_H_ */
