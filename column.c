#include <stdio.h>
#include <stdlib.h>
#include "column.h"

// Function to create a new column
COLUMN *create_column(char *title){
    // Allocate memory for the column structure
    COLUMN *col = (COLUMN*) malloc(sizeof(COLUMN));
    if (col == NULL) {
        printf("Memory allocation failed\n");
    }
    // Initialize column attributes
    col->title = title;
    col->data = NULL;
    col->physical_size = 0;
    col->logical_sizes = 0;
    return col;
}

// Function to insert a value into a column
int insert_value(COLUMN *col, int value) {
    if (col->data == NULL || col->logical_sizes == col->physical_size) {
        // Reallocate memory if necessary
        int *temp = (int *) realloc(col->data, (col->physical_size + REALLOC_SIZE) * sizeof(int));
        if (temp == NULL) {
            printf("Memory allocation failed\n");
            return 0;
        }
        col->data = temp;
        col->physical_size += REALLOC_SIZE;
    }
    // Insert the value and update logical size
    col->data[col->logical_sizes++] = value;
    return 1;
}

// Function to delete a column
void delete_column(COLUMN **col){
    free((*col)->data);
    (*col)->data = NULL;
    free(*col);
    *col = NULL;
}

// Function to print column data
void print_col(COLUMN *col){
    if (col == NULL) {
        printf("Error: Column is NULL\n");
        return;
    }
    for(int i = 0; i < col->logical_sizes; i++){
        printf("[%d] %d\n", i, col->data[i]);
    }
}

// Function to count occurrences of a value in a column
int occurence_val(COLUMN *col, int val){
    if (col == NULL) {
        printf("Error: Column is NULL\n");
        return -1;
    }
    int cpt = 0;
    for(int i = 0; i < col->logical_sizes; i++){
        if (col->data[i] == val){
            cpt++;
        }
    }
    return cpt;
}

// Function to get value at a specific index in a column
int get_index_val(COLUMN *col, int index){
    if(col == NULL || index < 0 || index >= col->logical_sizes){
        printf("Invalid index\n");
        return 0;
    }
    return col->data[index];
}

// Function to count the number of values lower than a given value in a column
int nb_val_lower_than_x(COLUMN *col, int val){
    int cpt = 0;
    for(int i = 0; i < col->logical_sizes; i++){
        if (col->data[i] < val){
            cpt++;
        }
    }
    return cpt;
}

// Function to count the number of values greater than a given value in a column
int nb_val_greater_than_x(COLUMN *col, int val){
    int cpt = 0;
    for(int i = 0; i < col->logical_sizes; i++){
        if (col->data[i] > val){
            cpt++;
        }
    }
    return cpt;
}

// Function to count the occurrences of a value in a column
int count_value(COLUMN *col, int val){
    if (col == NULL) {
        printf("Error: Column is NULL\n");
        return -1;
    }
    int cpt = 0;
    for(int i = 0; i < col->logical_sizes; i++){
        if (col->data[i] == val){
            cpt++;
        }
    }
    return cpt;
}
