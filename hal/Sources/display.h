/*
 * display.h
 *
 *  Created on: Aug 6, 2015
 *      Author: z0037ysj
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <stdtypes.h>

typedef struct
{
    Bool    bDisplayOn;
    Bool    bCursorOn;
    Bool    bBlinkingCursorOn;
}displayOnOffControl_t;

typedef struct
{
    Bool bShiftScreenInsteadOfCursor;
    Bool bShiftRightInsteadOfLeft;
}displayMovingDirection_t;

void displayInit();
void displayBackLightOn(const Bool bBackLightOn);
void displayClear();
void displayReturnHome();
void displayOnOffControl(const displayOnOffControl_t cControl);
void displayOrCursorShift(const displayMovingDirection_t cSetting);
void displayFunctionSet();
void displayEntryModeSet(const displayMovingDirection_t cSetting);
void displayWriteDataRam(const Byte cData);
void displayReadBusyAndAddress(Bool* pBusy, Byte* pAddress);

#endif /* DISPLAY_H_ */
