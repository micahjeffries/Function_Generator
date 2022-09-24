#include "msp.h"
#include "keypad.h"
#include "DAC.h"

void keypad_init(void)
{
    ROW_PORT->SEL0 &= ~(ROWS);          // Set row pins to GPIO
    ROW_PORT->SEL1 &= ~(ROWS);
    COL_PORT->SEL0 &= ~(COLS);          // Set col pins to GPIO
    COL_PORT->SEL1 &= ~(COLS);
    ROW_PORT->DIR &= ~(ROWS);           // Set row pins to Input
    COL_PORT->DIR |= (COLS);            // Set col pins to Output
    ROW_PORT->REN |= (ROWS);            // Enable row pin resistors
    ROW_PORT->OUT &= ~(ROWS);           // Set row pin pull down resistors
}

uint8_t keypad(void)
{
    int row = 0;
    COL_PORT->OUT |= (COLS);            // Set cols to high

    while (row == 0) {                  // Wait for button press
        row = (ROWS & ROW_PORT->IN);    // Get the row
    }

    switch (row) {
        case ROW_1:
            COL_PORT->OUT &= ~(COLS); // Set Col 1 high
            COL_PORT->OUT |= (COL_1);
            
            if ((ROWS & ROW_PORT->IN) == ROW_1)
                return 1; // 1 was pressed

            COL_PORT->OUT &= ~(COLS); // Set Col 2 high
            COL_PORT->OUT |= (COL_2);

            if ((ROWS & ROW_PORT->IN) == ROW_1)
                return 2; // 2 was pressed

            COL_PORT->OUT &= ~(COLS); // Set Col 3 high
            COL_PORT->OUT |= (COL_3);

            if ((ROWS & ROW_PORT->IN) == ROW_1)
                return 3; // 3 was pressed

            COL_PORT->OUT &= ~(COLS); // Set Col 4 high
            COL_PORT->OUT |= (COL_4);

            if ((ROWS & ROW_PORT->IN) == ROW_1)
                return 65; // A was pressed

        case ROW_2:
            COL_PORT->OUT &= ~(COLS); // Set Col 1 high
            COL_PORT->OUT |= (COL_1);

            if ((ROWS & ROW_PORT->IN) == ROW_2)
                return 4; // 4 was pressed

            COL_PORT->OUT &= ~(COLS); // Set Col 2 high
            COL_PORT->OUT |= (COL_2);

            if ((ROWS & ROW_PORT->IN) == ROW_2)
                return 5; // 5 was pressed

            COL_PORT->OUT &= ~(COLS); // Set Col 3 high
            COL_PORT->OUT |= (COL_3);

            if ((ROWS & ROW_PORT->IN) == ROW_2)
                return 6; // 6 was pressed

            COL_PORT->OUT &= ~(COLS); // Set Col 4 high
            COL_PORT->OUT |= (COL_4);

            if ((ROWS & ROW_PORT->IN) == ROW_2)
                return 66; // B was pressed

        case ROW_3:
            COL_PORT->OUT &= ~(COLS); // Set Col 1 high
            COL_PORT->OUT |= (COL_1);

            if ((ROWS & ROW_PORT->IN) == ROW_3)
                return 7; // 7 was pressed

            COL_PORT->OUT &= ~(COLS); // Set Col 2 high
            COL_PORT->OUT |= (COL_2);

            if ((ROWS & ROW_PORT->IN) == ROW_3)
                return 8; // 8 was pressed

            COL_PORT->OUT &= ~(COLS); // Set Col 3 high
            COL_PORT->OUT |= (COL_3);

            if ((ROWS & ROW_PORT->IN) == ROW_3)
                return 9; // 9 was pressed
            
            COL_PORT->OUT &= ~(COLS); // Set Col 4 high
            COL_PORT->OUT |= (COL_4);

            if ((ROWS & ROW_PORT->IN) == ROW_3)
                return 67; // C was pressed

        case ROW_4:
            COL_PORT->OUT &= ~(COLS); // Set Col 1 high
            COL_PORT->OUT |= (COL_1);

            if ((ROWS & ROW_PORT->IN) == ROW_4)
                return STAR; // * was pressed

            COL_PORT->OUT &= ~(COLS); // Set Col 2 high
            COL_PORT->OUT |= (COL_2);

            if ((ROWS & ROW_PORT->IN) == ROW_4)
                return 0; // 0 was pressed

            COL_PORT->OUT &= ~(COLS); // Set Col 3 high
            COL_PORT->OUT |= (COL_3);

            if ((ROWS & ROW_PORT->IN) == ROW_4)
                return POUND; // # was pressed

            COL_PORT->OUT &= ~(COLS); // Set Col 4 high
            COL_PORT->OUT |= (COL_4);

            if ((ROWS & ROW_PORT->IN) == ROW_4)
                return 68; // D was pressed

        default: return NO_KEY;
    }
}