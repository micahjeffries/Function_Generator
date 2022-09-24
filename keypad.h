#ifndef KEYPAD_H_
#define KEYPAD_H_

#define ROW_PORT P4
#define COL_PORT P4

#define ROWS 0x0F
#define COLS 0xF0
#define ROW_1 0x01
#define ROW_2 0x02
#define ROW_3 0x04
#define ROW_4 0x08
#define COL_1 0x10
#define COL_2 0x20
#define COL_3 0x40
#define COL_4 0x80

#define KEY_LENGTH 3
#define STAR 10
#define POUND 11
#define NO_KEY 0xFF

void keypad_init(void);
uint8_t keypad(void);

#endif /* KEYPAD_H_ */