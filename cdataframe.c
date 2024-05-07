#include <stdio.h>
#include <stdlib.h>
#include "cdataframe.h"
#include <time.h>
CDATAFRAME *create_dataframe(int size){

    CDATAFRAME *cdataframe= (CDATAFRAME *)malloc(sizeof(CDATAFRAME));
    cdataframe->columns=(COLUMN*) malloc(size*sizeof(COLUMN));
    cdataframe->physical_size=size;
    cdataframe->logical_size=size;
    for(int i=0;i<size;i++){
        char *title=(char*)malloc(100*sizeof(char));
        printf("enter the title\n");
        scanf("%s",title);
        cdataframe->columns[i]= create_column(title);
    }
    return cdataframe;
}

void fill_dataframe_user(CDATAFRAME* dataframe){
    int val;
    int len;
    char* title;
    for(int i=0;i<(dataframe)->logical_size;i++){
        printf("how many rows do you want for the %d columns", i);
        scanf("%d",&len);


        for (int j = 0; j<len; j++) {
            scanf("%d", &val);
            insert_value(dataframe->columns[i], val);
        }
    }
}
void hard_fill_dataframe(CDATAFRAME* dataframe){
    int val;
    int len;
    char* title;
    srand(time(NULL));
    for(int i=0;i<(dataframe)->logical_size;i++){
        for (int j = 0; j< rand() % 11; j++) {

            insert_value(dataframe->columns[i], rand() % 11);
        }
    }
}
void display_entire_dataframe(CDATAFRAME dataframe){
    for (int i = 0; i<dataframe.logical_size ; i++){
        printf("title : %s\n",dataframe.columns[i]->title);

        print_col(dataframe.columns[i]);
    }
}

void display_row_part_dataframe(CDATAFRAME dataframe,int row) {
    printf("row %d: \n",row);
    for (int i = 0; i < dataframe.logical_size; i++) {
        if (dataframe.columns[i]->data[row-1] == NULL) {
            printf("NULL\t");
        }

        printf("[%d] %d\t", i, dataframe.columns[i]->data[row-1]);

    }
}
void display_col_part_dataframe(CDATAFRAME dataframe,int col){
    printf("\n");
    printf("title : %s\n",dataframe.columns[col-1]->title);
    printf("\n");
    print_col(dataframe.columns[col-1]);
}
