#include "lcd.h"
#include "MKL25Z4.h"

void I2C_Init(){
    SIM->SCGC5|=SIM_SCGC5_PORTC_MASK;
    SIM->SCGC4 |= SIM_SCGC4_I2C0_MASK;
    PORTC->PCR[9]=PORT_PCR_MUX(2);//SDA
    PORTC->PCR[8]=PORT_PCR_MUX(2);//SDL
    I2C0->C1=0;
    I2C0->F = 0x14; //100KHz para la velocidad de transmision
    I2C0->C1 = I2C_C1_IICEN_MASK;
}

#define LCD_I2C_ADDRESS 0x27

void LCD_sendByte(uint8_t data){
    I2C0->C1 |= I2C_C1_TX_MASK; 
    I2C0->C1 |= I2C_C1_MST_MASK;

    I2C0->D= (LCD_I2C_ADDRESS<<1); //detecta al lcd
    while (!(I2C0->S & I2C_S_IICIF_MASK));
    I2C0->S |= I2C_S_IICIF_MASK;

    I2C0->D = data; //envia el dato
    while (!(I2C0->S & I2C_S_IICIF_MASK));
    I2C0->S |= I2C_S_IICIF_MASK;

    I2C0->C1 &= ~I2C_C1_MST_MASK;
}

void LCD_sendCmd(uint8_t command){
    uint8_t parteMS = command & 0xF0;
    uint8_t parteLS = (command << 4) & 0xF0;

    LCD_sendByte(parteMS | 0x08);
    LCD_sendByte(parteLS | 0x08);
}

void LCD_clear(){
    LCD_sendCmd(0x01); //0x en hex, 0b en binario
}

void LCD_scrollDisplayLeft(){
    LCD_sendCmd(0x6);
}

void LCD_scrollDisplayRight(){
    LCD_sendCmd(0x4);
}

void LCD_setCursor(int row, int col){ //row tiene direcciones, agarrar lafila una var coininin
    int row[2];
    int col[16];
    for(int i=0; i<16; i++){
        if(row[i] == 1){
            row = 0x00;
        }
    }
}

void LCD_createChar(uint8_t nByte, uint8_t[] nuevoCaracter){
    
}
