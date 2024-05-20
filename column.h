#ifndef COLUMN_H
#define COLUMN_H

// Define the reallocation size
#define REALLOC_SIZE 256

// Structure for a column
typedef struct {
    char* title; // Title of the column
    int* data; // Array to hold integer-type data
    int physical_size; // Physical size of the data array
    int logical_sizes; // Logical size of the data array
    int* index; // Index of data(used in the sorting function)
    int logical_size2;
} COLUMN;

// Function prototypes
COLUMN *create_column(char *title);
int insert_value(COLUMN *col, int value);
void delete_column(COLUMN **col);
void print_col(COLUMN *col);
int occurence_val(COLUMN *col,int val);
int get_index_val(COLUMN *col,int index);
int nb_val_lower_than_x(COLUMN *col,int val);
int nb_val_greater_than_x(COLUMN *col,int val);
int count_value(COLUMN *col,int val);
void print_index(COLUMN *col);
void print_col_sorted(COLUMN *col);
#endif