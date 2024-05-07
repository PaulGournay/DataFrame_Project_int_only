#include "column.h"

typedef struct {
    COLUMN **columns;
    int physical_size;
    int logical_size;
} CDATAFRAME;

CDATAFRAME *create_dataframe(int size);
void fill_dataframe_user(int* dataframe);
void hard_fill_dataframe(int* dataframe);
void display_entire_dataframe(int* dataframe);
void display_row_part_dataframe(int* dataframe,int row);
void display_col_part_dataframe(int* dataframe,int col);
void add_row(int* dataframe);
void delete_row(int** dataframe);
void add_column(int* dataframe);
void rename_col(int* dataframe);
int test_val_in(int* dataframe);
void replace_val(int* dataframe);