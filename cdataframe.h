#include "column.h"

typedef struct {
    COLUMN **columns;
    int physical_size;
    int logical_size;
} CDATAFRAME;

CDATAFRAME *create_dataframe(int size);
void fill_dataframe_user(CDATAFRAME* dataframe);
void hard_fill_dataframe(CDATAFRAME* dataframe);
void OXO_fill_dataframe(CDATAFRAME* dataframe);
void display_entire_dataframe(CDATAFRAME dataframe);
void display_cdataframe_fancy(CDATAFRAME* dataframe);
void display_row_part_dataframe(CDATAFRAME dataframe,int row);
void display_col_part_dataframe(CDATAFRAME dataframe,int col);
void add_row(CDATAFRAME* dataframe);
void delete_row(CDATAFRAME* dataframe);
void add_column(CDATAFRAME* dataframe);
void cdata_delete_column(CDATAFRAME* dataframe);
void rename_col(CDATAFRAME * dataframe, int col);
int test_val_in(CDATAFRAME dataframe,int val);
void replace_val(CDATAFRAME * dataframe,int col, int row,int val);
void display_column_names(CDATAFRAME * dataframe);
int number_rows(CDATAFRAME dataframe);
int number_columns(CDATAFRAME dataframe);
int nb_cells_equal_to_x(CDATAFRAME dataframe, int x);
int nb_cells_value_greater_than_x(CDATAFRAME dataframe, int x);
int nb_cells_value_less_than_x(CDATAFRAME dataframe, int x);
CDATAFRAME *load_from_csv(char *file_name, int *array, int size);