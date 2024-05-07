#include <stdio.h>
#include <stdlib.h>
#include "cdataframe.h"
CDATAFRAME *create_dataframe(int size){

    CDATAFRAME *cdataframe= (CDATAFRAME *)malloc(sizeof(CDATAFRAME));
    cdataframe->columns=(COLUMN*) malloc(size*sizeof(COLUMN));
    cdataframe->physical_size=0;
    cdataframe->logical_size=0;
    for(int i=0;i<size;i++){
        char *title=(char*)malloc(100*sizeof(char));
        printf("enter the title\n");
        scanf("%s",title);
        cdataframe->columns[i]= create_column(title);
    }
    return cdataframe;
}

void fill_dataframe_user(int* dataframe){
    for(int i=0;i<10;i++){
        printf("enter value for position %d",i);
    }
}




