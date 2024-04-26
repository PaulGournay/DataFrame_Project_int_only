#include <stdio.h>
#include <stdlib.h>
#include "cdataframe.h"
#include "column.c"
#include "column.h"
COLUMN** create_cdataframe(){
    COLUMN **pt=(COLUMN **)malloc(sizeof(COLUMN));
    return pt;
};

