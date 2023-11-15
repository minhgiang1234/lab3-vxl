/*
 * global.h
 *
 *  Created on: Nov 15, 2023
 *      Author: giang
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include <stdint.h>

#define INIT 1
#define RED_GREEN 2
#define RED_YELLOW 3
#define GREEN_RED 4
#define YELLOW_RED 5

#define MOD_RED 11
#define MOD_YELLOW 12
#define MOD_GREEN 13

extern int status;
extern uint8_t seg_buffer[4];





#endif /* INC_GLOBAL_H_ */
