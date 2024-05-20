CDataframe by Paul GOURNAY and Vrej KARAKOZIAN, INT-1
------------------------------------------------------
# CDataframe Project

## Overview
CDataframe is a C library for managing and manipulating dataframes. It provides functionalities similar to those found in popular data analysis libraries but is designed to be used within C programs. This project includes various features like creating dataframes, adding/deleting rows and columns, filling dataframes with random values, displaying data, loading from CSV files, and more.

## Features
1. **Create your own DataFrame**: Initialize a dataframe with a specified number of columns.
2. **Fill DataFrame (Random Hard Fill)**: Populate a dataframe with random values.
3. **Display DataFrame Fancy**: Display the entire dataframe in a formatted manner.
4. **Display Row of DataFrame**: Display a specific row of the dataframe.
5. **Display Column of DataFrame**: Display a specific column of the dataframe.
6. **Add Row to DataFrame**: Add a new row to the dataframe.
7. **Add Column to DataFrame**: Add a new column to the dataframe.
8. **Delete Row from DataFrame**: Remove a specified row from the dataframe.
9. **Delete Column from DataFrame**: Remove a specified column from the dataframe.
10. **Rename Column**: Change the title of a specified column.
11. **Test Value in DataFrame**: Check for the presence of a specific value in the dataframe.
12. **Replace Value in DataFrame**: Replace a value in the dataframe at specified row and column.
13. **Statistic of number of columns and rows and names of columns**: Display the names of the columns and count of rows and columns.
14. **Number of Cells Equal/Greater/Less to X**: Count the number of cells with values equal to, greater than, or less than a specified value.
15. **Load DataFrame from CSV**: Load a dataframe from a CSV file.
16. **Sort a column of your choice and display it in the right order: Sort a specified column of the dataframe and display it in the sorted order.
17. **Exit: Exit the program.

## Usage

### Menu Interface
The main interface of the program is a menu that allows the user to select from various options to manipulate and display the dataframe.

### Example Usage
Here’s a brief example to get you started:

1. **Creating a DataFrame**:
    ```c
    CDATAFRAME *dataframe = create_dataframe(3);
    fill_dataframe_user(dataframe);
    display_entire_dataframe(*dataframe);
    ```

2. **Filling DataFrame with Random Values**:
    ```c
    CDATAFRAME *dataframe = create_dataframe(3);
    hard_fill_dataframe(dataframe);
    display_entire_dataframe(*dataframe);
    ```

3. **Displaying DataFrame Fancy**:
    ```c
    display_cdataframe_fancy(dataframe);
    ```

4. **Loading DataFrame from CSV**:
    ```c
    CDATAFRAME *dataframe = load_from_csv("data.csv", NULL, 3);
    if (dataframe != NULL) {
        display_entire_dataframe(*dataframe);
    } else {
        printf("Failed to load dataframe from CSV.\n");
    }
    ```

### Functions
Here’s a list of important functions provided in the project:

#### DataFrame Operations
- `CDATAFRAME *create_dataframe(int size);`
- `void fill_dataframe_user(CDATAFRAME* dataframe);`
- `void hard_fill_dataframe(CDATAFRAME* dataframe);`
- `void OXO_fill_dataframe(CDATAFRAME* dataframe);`
- `void display_entire_dataframe(CDATAFRAME dataframe);`
- `void display_cdataframe_fancy(CDATAFRAME* dataframe);`
- `void display_row_part_dataframe(CDATAFRAME dataframe, int row);`
- `void display_col_part_dataframe(CDATAFRAME dataframe, int col);`
- `void add_row(CDATAFRAME* dataframe);`
- `void delete_row(CDATAFRAME* dataframe);`
- `void delete_column1(CDATAFRAME* dataframe);`
- `void add_column(CDATAFRAME* dataframe);`
- `void rename_col(CDATAFRAME* dataframe, int col);`
- `void test_val_in(CDATAFRAME dataframe, int val);`
- `void replace_val(CDATAFRAME* dataframe, int col, int row, int val);`
- `void display_column_names(CDATAFRAME* dataframe);`
- `int number_columns(CDATAFRAME dataframe);`
- `int number_rows(CDATAFRAME dataframe);`
- `int nb_cells_equal_to_x(CDATAFRAME dataframe, int x);`
- `int nb_cells_value_greater_than_x(CDATAFRAME dataframe, int x);`
- `int nb_cells_value_less_than_x(CDATAFRAME dataframe, int x);`
- `void sort_column(CDATAFRAME *cdataframe, int index);`
- `CDATAFRAME *load_from_csv(char *file_name, int *array, int size);`
#### Column Operations
- `COLUMN *create_column(char *title);`
- `int insert_value(COLUMN *col, int value);`
- `void delete_column(COLUMN **col);`
- `void print_col(COLUMN *col);`
- `int occurence_val(COLUMN *col, int val);`
- `int get_index_val(COLUMN *col, int index);`
- `int nb_val_lower_than_x(COLUMN *col, int val);`
- `int nb_val_greater_than_x(COLUMN *col, int val);`
- `int count_value(COLUMN *col, int val);`

### Compilation
To compile the program, ensure you have a C compiler installed. Use the following command to compile:
```sh
gcc -o cdataframe main.c cdataframe.c column.c
```

### Execution
Run the compiled program:
```sh
./cdataframe
```

### Dependencies
Ensure you have the following files in your project directory:
- `main.c`
- `cdataframe.h`
- `cdataframe.c`
- `column.h`
- `column.c`
-----------------------------------
Enjoy working with CDataframe! If you encounter any issues, please feel free to open an issue on GitHub.

Link to the github: https://github.com/PaulGournay/DataFrame_Project_int_only.git
