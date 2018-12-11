/*
*  decoder.c
*/


#include "../include/buttons.h";
#include "../include/decoder.h";
#include "../incldue/lcd.h"

//*****************************************************************************
// Select Correct Card From Color Sequece
// Input: None;
// Returns: index for card Definitions
//*****************************************************************************

int decode() {
    int buttonsVal;
    char code[4];
    for(int i = 0; i < 4; i++) {
        while (buttonsVal = buttons_read_all == 0);
        if(buttonsVal == 8 {
            char[i] = R
        } else if (buttonsVal == 4) {
            char[i] = O
        } else if (buttonsVal == 2) {
            char[i] = G
        } else if (buttonsVal == 1) {
            char[i] = B
        } else {
            return -1;
        }
    }

    for(int i = 0; i < 11; i++) {
        if(strcmp(cardDefinitions[i].code, this.code) == 0) {
            return i;
        }
    }
}
