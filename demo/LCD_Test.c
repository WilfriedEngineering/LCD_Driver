
#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include "BUS_I2C.h"
#include "PCA9554A.h"
#include "LM016L.h"
#include "LM041L.h"
#include "LM020L.h"
#include "LM0XXL.h"

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#define _XTAL_FREQ 20000000 


BUS_I2C mbus={BUS_I2C_Init,BUS_I2C_Start,BUS_I2C_Repeated_Start,BUS_I2C_Write,BUS_I2C_Read, BUS_I2C_Stop}; // Defining of functions operating on the I2C bus



PCA9554A_DATA d1={&mbus,0x00};
PCA9554A_DATA d2={&mbus,0x01};
PCA9554A_DATA d3={&mbus,0x03};

PCA9554A_FUNCTION myfunct={PCA9554A_Write, PCA9554A_Config_Or_Inverse, PCA9554A_Read_Port, PCA9554A_Read_Reg};
PCA9554A mypca1={&d1,&myfunct};
PCA9554A mypca2={&d2,&myfunct};
PCA9554A mypca3={&d3,&myfunct};

LM020L_FUNCTION lcdf1={LM0XXL_Init, LM0XXL_Clear, LM0XXL_Write_Chr, LM0XXL_Write_String,LM020L_Position};
LM016L_FUNCTION lcdf2={LM0XXL_Init, LM0XXL_Clear, LM0XXL_Write_Chr, LM0XXL_Write_String,LM016L_Position};
LM041L_FUNCTION lcdf3={LM0XXL_Init, LM0XXL_Clear, LM0XXL_Write_Chr, LM0XXL_Write_String,LM041L_Position};


int main(int argc, char** argv) {
    const char MY_LINE1[15]={'H','E','L','L','O',' ','M','Y',' ','F','R','I','E','N','D'};
    const char MY_LINE2[13]={' ','H','O','W',' ','A','R','E',' ','Y','O','U','?'};
    const char MY_LINE3[15]={' ','F','I','N','E','.',' ','A','N','D',' ','Y','O','U','?'};
    const char MY_LINE4[15]={' ','-','-','-','-','-',' ','F','I','N','E','-','-','-','-'};
 
    
    mbus.Init(20000000,100000);
    lcdf1.Init(&mypca1, LM0XXL_DISPLAY_ALL_LINES, LM0XXL_ACTIVATED_CURSOR, LM0XXL_ACTIVATED_BLINK_CURSOR);
    lcdf2.Init(&mypca2, LM0XXL_DISPLAY_ALL_LINES, LM0XXL_ACTIVATED_CURSOR, LM0XXL_ACTIVATED_BLINK_CURSOR);
    lcdf3.Init(&mypca3, LM0XXL_DISPLAY_ALL_LINES, LM0XXL_ACTIVATED_CURSOR, LM0XXL_ACTIVATED_BLINK_CURSOR);
    
    while(1){
        lcdf1.Clear(&mypca1);
        lcdf2.Clear(&mypca2);
        lcdf3.Clear(&mypca3);
        
        lcdf1.Position(&mypca1,0,0);
        lcdf1.Write_String(&mypca1,MY_LINE1,15);
        
        lcdf2.Position(&mypca2,0,0);
        lcdf2.Write_String(&mypca2,MY_LINE1,15);
        lcdf2.Position(&mypca2,0,1);
        lcdf2.Write_String(&mypca2,MY_LINE2,13);
        
        lcdf3.Position(&mypca3,0,0);
        lcdf3.Write_String(&mypca3,MY_LINE1,15);
        lcdf3.Position(&mypca3,0,1);
        lcdf3.Write_String(&mypca3,MY_LINE2,13);
        lcdf3.Position(&mypca3,0,2);
        lcdf3.Write_String(&mypca3,MY_LINE3,15);
        lcdf3.Position(&mypca3,0,3);
        lcdf3.Write_String(&mypca3,MY_LINE4,15);
        
        __delay_ms(3000);
        
        
    }

    return (EXIT_SUCCESS);
}

