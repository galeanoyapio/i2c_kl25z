#include "i2clib.h"
#include "MKL25Z4.h"

void I2C_Init(){
    I2C0->C1 = I2C_C1_IICEN_MASK;
    I2C0->F = 0x14; //100KHz para la velocidad de transmision
}

void I2C_bStart(){
    I2C0->C1 |= I2C_C1_TX_MASK; 
    I2C0->C1 |= I2C_C1_MST_MASK;
}

void I2C_bStop(){
    I2C0->C1 |= ~(I2C_C1_TX_MASK); 
    I2C0->C1 |= ~(I2C_C1_MST_MASK);
}

int I2C_Write(uint8_t data){
    I2C0->D = data; 
    while (!(I2C0->S & I2C_S_IICIF_MASK)); //espera terminar el envio
    I2C0->S |= I2C_S_IICIF_MASK; //termina la interrupcion

}
