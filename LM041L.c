#include "LM041L.h"

      
      const char LM041L_CURSOR_LINE_0=0x80;           // address of the first position of the first line
      const char LM041L_CURSOR_LINE_1=0xc0;           // address of the first position of the second line
      const char LM041L_CURSOR_LINE_2=0x90;           // address of the first position of the third line
      const char LM041L_CURSOR_LINE_3=0xd0;           // address of the first position of the fourth line
      
      
       /* set position with (x,y): x= position of the charater on one line
            and y= position of the line
            */
      void LM041L_Position(PCA9554A *pca, char x, char y){
        if(y == 0) LM0XXL_Byte(pca, LM0XXL_IR, LM041L_CURSOR_LINE_0 | x);
        else if (y == 1) LM0XXL_Byte(pca, LM0XXL_IR, LM041L_CURSOR_LINE_1 | x);
        else if (y == 2) LM0XXL_Byte( pca, LM0XXL_IR, LM041L_CURSOR_LINE_2 | x);
        else  LM0XXL_Byte(pca, LM0XXL_IR, LM041L_CURSOR_LINE_3 | x);

      }