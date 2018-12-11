/*
*  decoder.c
*/


#include "../include/ece453.h"

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
        if(buttonsVal == 8) {
            code[i] = 'R';
        } else if (buttonsVal == 4) {
            code[i] = 'O';
        } else if (buttonsVal == 2) {
            code[i] = 'G';
        } else if (buttonsVal == 1) {
            code[i] = 'B';
        } else {
            return -1;
        }
    }

    for(int i = 0; i < 11; i++) {
        if(strcmp(cardDefinitions[i].code, code) == 0) {
            return i;
        }
    }
}
