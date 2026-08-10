 #include "LM0XXL.h"
 #define _XTAL_FREQ 20000000    // frequence (Khz) of oscillator of microcontroller


      const char LM0XXL_IR=0x00;                     // used to send instruction's request
      const char LM0XXL_DR=0x01;                     // used to send daten's request
      const char LM0XXL_DISPLAY_ALL_LINES= 0x28 ;    // displays one line
      const char LM0XXL_DISPLAY_ONE_LINE=0x24 ;      // displays two lines
      const char LM0XXL_ACTIVATED_CURSOR=0x02;       //shows the cursor
      const char LM0XXL_DESACTIVATED_CURSOR=0x00;    // doesn't schow the cursor
      const char LM0XXL_ACTIVATED_BLINK_CURSOR=0x01;     //blink the cursor
      const char LM0XXL_DESACTIVATED_BLINK__CURSOR=0x00; // doesn't blink the cursor
      char LM0XXL_i=0;      // for Counting in a loop


        void LM0XXL_Nibble(PCA9554A *pca, char x_rs, char x_data){
            pca->pcaf->Write(pca->pcad, x_data | (char)(x_rs<<5)); 
          __delay_us(2);
            pca->pcaf->Write(pca->pcad, x_data | (char)(x_rs<<5) |0x10);
           __delay_us(2);
        }

        void LM0XXL_Byte(PCA9554A *pca, char x_rs, char x_data){
            LM0XXL_Nibble(pca, x_rs, (char)(x_data >> 4) );
            LM0XXL_Nibble(pca, x_rs, x_data & 0x0f);
            
        }
         // initialise the lcd 
        void LM0XXL_Init(PCA9554A *pca, char lines, char cursr, char blink_cursr){
            
            pca->pcaf->Config_Or_Inverse(pca->pcad,PCA9554A_CONFIG,0x00);
            pca->pcaf->Write(pca->pcad,0x00);
            __delay_ms(100);
            for(LM0XXL_i=0; LM0XXL_i<3;LM0XXL_i++){
               LM0XXL_Nibble(pca, LM0XXL_IR, 0x03);
               __delay_ms(7);
            }
            LM0XXL_Nibble(pca, LM0XXL_IR, 0x02);
            __delay_us(50);
            LM0XXL_Byte(pca, LM0XXL_IR, lines);
            __delay_us(50);
            LM0XXL_Byte(pca, LM0XXL_IR, 0x0c | cursr | blink_cursr);
            __delay_us(50);
            LM0XXL_Byte(pca, LM0XXL_IR, 0x01);
            __delay_ms(2);
            LM0XXL_Byte(pca, LM0XXL_IR, 0x06);
            __delay_us(50);
            
        }
        // clear the lcd
        void LM0XXL_Clear(PCA9554A *pca){
            LM0XXL_Byte(pca, LM0XXL_IR, 0x01);
            __delay_ms(2);
        }

         // write a character to end of the last
        void LM0XXL_Write_Chr(PCA9554A *pca,char x_data){
            LM0XXL_Byte(pca, LM0XXL_DR, x_data);
            __delay_us(50);
        }
        // write a String to end of the last
        void LM0XXL_Write_String(PCA9554A *pca, const char *ptr_data, char size_dat){
            for(LM0XXL_i=0; LM0XXL_i<size_dat; LM0XXL_i++){
                LM0XXL_Byte(pca, LM0XXL_DR, *(ptr_data + LM0XXL_i));
                __delay_us(50);
            }
        }
