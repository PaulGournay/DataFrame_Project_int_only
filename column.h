#define REALOC_SIZE 256
#ifndef COLUMN_H
#define COLUMN_H

typedef struct
{
    char* title;
    int* data;
    int physical_size;
    int logical_sizes;
}COLUMN;

COLUMN *create_column(char *title);
int insert_value(COLUMN *col, int value);
void delete_column(COLUMN **col);
void print_col(COLUMN *col);
int occurence_val(COLUMN *col,int val);
int get_index_val(COLUMN *col,int index);
int nb_val_lower_than_x(COLUMN *col,int val);
int nb_val_greater_than_x(COLUMN *col,int val);
int count_value(COLUMN *col,int val);
#endif
