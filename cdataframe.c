#include <stdio.h>
#include <stdlib.h>
#include "cdataframe.h"
CDATAFRAME *create_dataframe(char *title){
    CDATAFRAME *pt= (CDATAFRAME *)malloc(sizeof(CDATAFRAME));
    pt[0].columns = (COLUMN **) create_column(title);
    pt->num_columns = 0;
    return pt;
}




