#include "LM016L.h"

      
      const char LM016L_CURSOR_LINE_0=0x80;           // address of the first position of the first line
      const char LM016L_CURSOR_LINE_1=0xc0;          // address of the first position of the second line
      
      
       /* set position with (x,y): x= position of the charater on one line
            and y= position of the line
            */
      void LM016L_Position(PCA9554A *pca, char x, char y){
        if(y == 0) LM0XXL_Byte(pca, LM0XXL_IR, LM016L_CURSOR_LINE_0 | x);
        else LM0XXL_Byte(pca, LM0XXL_IR, LM016L_CURSOR_LINE_1 | x);
      }


        
      
       
       
        
        