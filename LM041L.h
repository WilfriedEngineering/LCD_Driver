#ifndef LM041L_H
#define LM041L_H

     
     #include <xc.h>
     #include "LM0XXL.h"
    
 
     
     typedef struct LM041L_FUNCTION{
        void (*Init)(PCA9554A *pca, char lines, char cursr, char blink_cursr);
        void (*Clear)(PCA9554A *pca);
        void (*Write_Chr)(PCA9554A *pca,char x_data);
        void (*Write_String)(PCA9554A *pca, const char *ptr_data, char size_dat);     
        void (*Position)(PCA9554A *pca, char x, char y);
     }LM041L_FUNCTION;
       
          
        void LM041L_Position(PCA9554A *pca, char x, char y);
     


   
     
      extern const char LM041L_CURSOR_LINE_0;
      extern const char LM041L_CURSOR_LINE_1;
      extern const char LM041L_CURSOR_LINE_2;
      extern const char LM041L_CURSOR_LINE_3;


 #endif