#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    for(int i=0;i<((dataframe)->logical_size);i++){
        for (int j = 0; j< (rand() % 11) +1 ; j++) {
            insert_value(dataframe->columns[i], rand() % 11);
        }
    }
}

void OXO_fill_dataframe(CDATAFRAME* dataframe){
    int val;
    int len;
    char* title;
    for(int i=0;i<(dataframe)->logical_size;i++){
        for (int j = 0; j< 5; j++) {

            insert_value(dataframe->columns[i], j);
        }
    }
}

void display_entire_dataframe(CDATAFRAME dataframe){
    for (int i = 0; i<dataframe.logical_size ; i++){
        printf("title : %s\n",dataframe.columns[i]->title);

        print_col(dataframe.columns[i]);
    }
}

void display_cdataframe_fancy(CDATAFRAME* dataframe){
    int i, j;
    // Display column titles
    for (i = 0; i < dataframe -> logical_size; i++)
    {
        if (dataframe ->columns[i] != NULL)
            printf("\t%s\t", dataframe -> columns[i] -> title);
    }
    printf("\n");
    // Display data
    for (i = 0; i < dataframe -> columns[0] -> logical_sizes; i++)
    {
        printf("[%d]", i);
        for (j = 0; j < dataframe -> logical_size; j++)
        {
            if (dataframe -> columns[j] != NULL)
            {
                if (i < dataframe -> columns[j] -> logical_sizes)
                    printf("\t%d\t", dataframe -> columns[j] -> data[i]);
                else
                    printf("\t\t"); // If data does not exist
            }
        }
        printf("\n");
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

void add_row(CDATAFRAME* dataframe){
    int val=0;
    for (int i = 0; i < dataframe->logical_size; i++) {
        printf("enter a value for column %d: ", i+1);
        scanf("%d",&val);
        insert_value(dataframe->columns[i], val);
    }
}

void delete_row(CDATAFRAME* dataframe){
    if (dataframe->columns[0]->logical_sizes == 0) {
        printf("No rows to delete!\n");
    }
    for (int i = 0; i < dataframe->logical_size; i++) {
        dataframe->columns[i]->data[i] = 0;
        free(dataframe->columns[i]->data+i);
        dataframe->columns[i]->logical_sizes--;
    }
}

void add_column(CDATAFRAME* dataframe){
    int val,len;
    char *title=(char*)malloc(100*sizeof(char));
    dataframe->physical_size++;
    dataframe->logical_size++;
    printf("\nenter the number of row in the new col:\n");
    scanf("%d",&len);
    printf("\ngive us a new title");
    scanf("%s",title );
    dataframe->columns[dataframe->logical_size-1] =create_column(title);

    for (int j = 0; j< len; j++) {
        printf("enter value at row : %d\n",j);
        scanf("%d", &val);
        insert_value(dataframe->columns[dataframe->logical_size-1], val);
    }
}

void cdata_delete_column(CDATAFRAME* dataframe){
    if(dataframe->logical_size == 0) {
        printf("No columns to delete!\n");
    }
    else{
        delete_column(&(dataframe->columns[dataframe->logical_size-1]));
        dataframe->physical_size--;
        dataframe->logical_size--;
    }
}

void rename_col(CDATAFRAME * dataframe, int col){
    char* new_title=(char*)malloc(100*sizeof(char));
    printf("enter a new title for column %d",col);
    scanf("%s",new_title);
    dataframe->columns[col-1]->title=new_title;
}

int test_val_in(CDATAFRAME dataframe,int val){
    for(int i=0;i<dataframe.logical_size;i++){
        for(int j=0;j<dataframe.columns[i]->logical_sizes;j++){
            if(dataframe.columns[i]->data[j]==val){
                return 1;
            }

        }
    }
    return 0;
}

void replace_val(CDATAFRAME * dataframe,int col, int row,int val){
    dataframe->columns[col]->data[row]=val;
}

void display_column_names(CDATAFRAME * dataframe){
    printf("\n");
    for(int i=0;i<dataframe->logical_size;i++){
        printf("%s  ",dataframe->columns[i]->title);
    }
}

int number_columns(CDATAFRAME dataframe){
    return dataframe.physical_size;
}

int number_rows(CDATAFRAME dataframe){
    return dataframe.columns[0]->logical_sizes;
}

int nb_cells_equal_to_x(CDATAFRAME dataframe, int x){
    int cpt=0;
    for(int i=0;i<dataframe.logical_size;i++){
        for(int j=0;j<dataframe.columns[i]->logical_sizes;j++){
            if(dataframe.columns[i]->data[j]==x){
                cpt++;
            }
        }
    }
    return cpt;
}

int nb_cells_value_greater_than_x(CDATAFRAME dataframe, int x){
    int cpt=0;
    for(int i=0;i<dataframe.logical_size;i++){
        for(int j=0;j<dataframe.columns[i]->logical_sizes;j++){
            if(dataframe.columns[i]->data[j]>x){
                cpt++;
            }
        }
    }
    return cpt;
}

int nb_cells_value_less_than_x(CDATAFRAME dataframe, int x){
    int cpt=0;
    for(int i=0;i<dataframe.logical_size;i++){
        for(int j=0;j<dataframe.columns[i]->logical_sizes;j++){
            if(dataframe.columns[i]->data[j]>x){
                cpt++;
            }
        }
    }
    return cpt;
}


/*CDATAFRAME *load_from_csv(char *file_name, int *array, int size) {
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        perror("Unable to open file");
        return NULL;
    }

    CDATAFRAME *dataframe = (CDATAFRAME*)malloc(sizeof(CDATAFRAME));
    dataframe->columns = (COLUMN**)malloc(size * sizeof(COLUMN*));
    dataframe->physical_size = size;
    dataframe->logical_size = 0;

    char line[1024];
    if (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, ",");
        for (int i = 0; i < size; i++) {
            dataframe->columns[i] = (COLUMN*)malloc(sizeof(COLUMN));
            dataframe->columns[i]->title = strdup(token);
            dataframe->columns[i]->data = (int*)malloc(10 * sizeof(int));
            dataframe->columns[i]->physical_size = 10;
            dataframe->columns[i]->logical_sizes = 0;
            dataframe->columns[i]->index = NULL;

            token = strtok(NULL, ",");
        }
    }

    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, ",");
        for (int i = 0; i < size; i++) {
            if (token != NULL) {
                int value = atoi(token);
                COLUMN *col = dataframe->columns[i];

                if (col->logical_sizes >= col->physical_size) {
                    col->physical_size *= 2;
                    col->data = (int*)realloc(col->data, col->physical_size * sizeof(int));
                }

                col->data[col->logical_sizes++] = value;

                token = strtok(NULL, ",");
            }
        }
        dataframe->logical_size++;
    }

    fclose(file);
    return dataframe;
}*/