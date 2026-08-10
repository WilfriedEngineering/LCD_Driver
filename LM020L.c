#include "LM020L.h"

      
      const char LM020L_CURSOR_LINE_0=0x80;           // address of the first position of the first line
      
      
       /* set position with (x,y): x= position of the charater on one line
            and y= position of the line
            */
      void LM020L_Position(PCA9554A *pca, char x, char y){
         LM0XXL_Byte(pca, LM0XXL_IR, LM020L_CURSOR_LINE_0 | x);   
      }