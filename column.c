#include <stdio.h>
#include <stdlib.h>
#include "column.h"

COLUMN *create_column(char *title){
    COLUMN *col=(COLUMN*) malloc(sizeof(COLUMN));
    col->title=title;
    col->data=NULL;
    col->physical_size=0;
    col->logical_sizes=0;
    return col;
}
int insert_value(COLUMN *col, int value) {
    if (col->data == NULL) {
        col->data = (int *) malloc(REALOC_SIZE * sizeof(int));
        if (col->data != NULL) {
            col->data[col->logical_sizes] = value;
            col->logical_sizes += 1;
            col->physical_size = REALOC_SIZE;
            return 1;
        }
        else {
            return 0;
        }

    } else if (col->logical_sizes == col->physical_size) {
        col->data = realloc(col->data, col->physical_size + REALOC_SIZE * sizeof(int));
        if (col->data != NULL) {
            col->data[col->logical_sizes] = value;
            col->logical_sizes += 1;
            col->physical_size = REALOC_SIZE;
            return 1;
        }
        else {
            return 0;
        }
    }
    else{
        col->data[col->logical_sizes] = value;
        col->logical_sizes += 1;
        return 1;
    }
}
void delete_column(COLUMN **col){
    free((*col)->data);
    (*col)->data =NULL;
    free(*col);
    *col=NULL;
}
void print_col(COLUMN *col){
    if(col==NULL){
        printf("there is an error: col is NULL");
    }
    for(int i=0;i<col->logical_sizes;i++){
        printf("[%d] %d\n",i,col->data[i]);
    }
}
int occurence_val(COLUMN *col,int val){
    if(col==NULL){
        printf("there is an error: col is NULL");
    }
    int cpt=0;
    for(int i=0;i<col->logical_sizes;i++){
        if(col->data[i] == val){
            cpt+=1;
        }
    }
    return cpt;
}
int get_index_val(COLUMN *col,int index){
    if(col==NULL || index<0 || index>col->logical_sizes){
        printf("invalid index");
        return 0;
    }
    else
    return col->data[index];
}
int nb_val_lower_than_x(COLUMN *col,int val){
    int cpt=0;
    for(int i=0;i<col->logical_sizes;i++){
        if(col->data[i]<val){
            cpt+=1;
        }
    }
    return cpt;
}
int nb_val_greater_than_x(COLUMN *col,int val){
    int cpt=0;
    for(int i=0;i<col->logical_sizes;i++){
        if(col->data[i]>val){
            cpt+=1;
        }
    }
    return cpt;
}
int count_value(COLUMN *col,int val){
    if(col==NULL){
        printf("there is an error: col is NULL");
    }
    int cpt=0;
    for(int i=0;i<col->logical_sizes;i++){
        if(col->data[i] == val){
            cpt+=1;
        }
    }
    return cpt;
}
