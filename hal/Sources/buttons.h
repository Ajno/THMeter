/*
 * buttons.h
 *
 *  Created on: Aug 6, 2015
 *      Author: z0037ysj
 */

#ifndef BUTTONS_H_
#define BUTTONS_H_

#include "io.h"

static const io_t cButton_Lower = cPin_A1;
static const io_t cButton_Upper = cPin_A2;

void buttonsInit();

#endif /* BUTTONS_H_ */
