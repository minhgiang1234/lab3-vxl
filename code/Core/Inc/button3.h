/*
 * button3.h
 *
 *  Created on: Nov 15, 2023
 *      Author: giang
 */

#ifndef INC_BUTTON3_H_
#define INC_BUTTON3_H_

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

void getKey3Input();
int isButton3Pressed();

#endif /* INC_BUTTON3_H_ */
