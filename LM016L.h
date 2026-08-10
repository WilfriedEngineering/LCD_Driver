#ifndef LM016L_H
#define LM016L_H

    
     #include <xc.h>
     #include "LM0XXL.h"
    
 
     
     typedef struct LM016L_FUNCTION{
        void (*Init)(PCA9554A *pca, char lines, char cursr, char blink_cursr);
        void (*Clear)(PCA9554A *pca);
        void (*Write_Chr)(PCA9554A *pca,char x_data);
        void (*Write_String)(PCA9554A *pca, const char *ptr_data, char size_dat); 
        void (*Position)(PCA9554A *pca, char x, char y);
     }LM016L_FUNCTION;
       
          
        void LM016L_Position(PCA9554A *pca, char x, char y);
     


   
     
      extern const char LM016L_CURSOR_LINE_0;
      extern const char LM016L_CURSOR_LINE_1;

        





 #endif