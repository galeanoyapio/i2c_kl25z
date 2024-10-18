#ifndef LCD_H
#define LCD_H

void LCD_init();
void LCD_sendCmd(uint8_t command);
void LCD_clear();
void LCD_scrollDisplayLeft();
void LCD_scrollDisplayRight();
void LCD_sendByte(uint8_t data);
void LCD_setCursor(int row, int col);
void LCD_createChar(uint8_t nByte, uint8_t[] nuevoCaracter);
//PINES B0 B1


#endif