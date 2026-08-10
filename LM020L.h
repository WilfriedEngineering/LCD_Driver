#ifndef LM020L_H
#define LM020L_H

     
     #include <xc.h>
     #include "LM0XXL.h"
    
 
     
     typedef struct LM020L_FUNCTION{
        void (*Init)(PCA9554A *pca, char lines, char cursr, char blink_cursr);
        void (*Clear)(PCA9554A *pca);
        void (*Write_Chr)(PCA9554A *pca,char x_data);
        void (*Write_String)(PCA9554A *pca, const char *ptr_data, char size_dat); 
        void (*Position)(PCA9554A *pca, char x, char y);
     }LM020L_FUNCTION;
       
          
        void LM020L_Position(PCA9554A *pca, char x, char y);
     
     
      extern const char LM020L_CURSOR_LINE_0;
      
 #endif
     