#ifndef LM0xxL_H
#define LM0xxL_H

     #include "PCA9554A.h"
     #include <xc.h>
     
        /*  configuration of PCA9554A -----> LCD
         * pin0 -----> LCD_D4
         * pin1 -----> LCD_5
         * pin2 -----> LCD_6
         * pin3 -----> LCD_7
         * pin4 -----> LCD_E
         * pin5 -----> LCD_RS
         
         */
    
                 
        void LM0XXL_Nibble(PCA9554A *pca, char x_rs, char x_data);
        void LM0XXL_Byte(PCA9554A *pca, char x_rs, char x_data);

        void LM0XXL_Init(PCA9554A *pca, char lines, char cursr, char blink_cursr);
        void LM0XXL_Clear(PCA9554A *pca);
        void LM0XXL_Write_Chr(PCA9554A *pca,char x_data);
        void LM0XXL_Write_String(PCA9554A *pca, const char *ptr_data, char size_dat);

      extern const char LM0XXL_IR;
      extern const char LM0XXL_DR;
      extern const char LM0XXL_DISPLAY_ALL_LINES;
      extern const char LM0XXL_DISPLAY_ONE_LINE;
      extern const char LM0XXL_ACTIVATED_CURSOR;
      extern const char LM0XXL_DESACTIVATED_CURSOR;
      extern const char LM0XXL_ACTIVATED_BLINK_CURSOR;
      extern const char LM0XXL_DESACTIVATED_BLINK__CURSOR;
      extern char LM0XXL_i;

 #endif