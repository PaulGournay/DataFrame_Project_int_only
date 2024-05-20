#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cdataframe.h"
#include <time.h>

// Function to create a dataframe with a specified number of columns
CDATAFRAME *create_dataframe(int size){
    CDATAFRAME *cdataframe = (CDATAFRAME *)malloc(sizeof(CDATAFRAME)); // Allocate memory for the dataframe structure
    cdataframe->columns = (COLUMN*) malloc(size * sizeof(COLUMN)); // Allocate memory for the columns array
    cdataframe->physical_size = size; // Set the physical size of the dataframe
    cdataframe->logical_size = size; // Set the logical size of the dataframe

    // Loop to initialize each column
    for(int i = 0; i < size; i++){
        char *title = (char*)malloc(100 * sizeof(char)); // Allocate memory for the column title
        printf("Enter the title\n");
        scanf("%s", title);
        cdataframe->columns[i] = create_column(title); // Create and assign the column to the dataframe
    }
    return cdataframe;
}

// Function to fill a dataframe with user input values
void fill_dataframe_user(CDATAFRAME* dataframe){
    int val;
    int len;

    // Loop through each column
    for(int i = 0; i < dataframe->logical_size; i++){
        printf("How many rows do you want for the %d column", i);
        scanf("%d", &len); // Read the number of rows for the current column

        // Loop to read and insert each value into the column
        for (int j = 0; j < len; j++) {
            scanf("%d", &val); // Read the value from user input
            insert_value(dataframe->columns[i], val); // Insert the value into the column
        }
    }
}

// Function to fill a dataframe with random values
void hard_fill_dataframe(CDATAFRAME* dataframe){
    srand(time(NULL)); // Seed the random number generator

    // Loop through each column
    for(int i = 0; i < dataframe->logical_size; i++){
        // Loop to insert random values into the column
        for (int j = 0; j < (rand() % 11) + 1; j++) {
            insert_value(dataframe->columns[i], rand() % 11); // Insert a random value between 0 and 10
        }
    }
}

// Function to fill a dataframe with values from 0 to 4
void OXO_fill_dataframe(CDATAFRAME* dataframe){
    for(int i = 0; i < dataframe->logical_size; i++){
        for (int j = 0; j < 5; j++) {
            insert_value(dataframe->columns[i], j); // Insert the value into the column
        }
    }
}

// Function to display the entire dataframe
void display_entire_dataframe(CDATAFRAME dataframe){
    for (int i = 0; i < dataframe.logical_size; i++){
        printf("Title: %s\n", dataframe.columns[i]->title); // Print the column title
        print_col(dataframe.columns[i]); // Print the column data
    }
}

// Function to display the dataframe in a formatted manner
void display_cdataframe_fancy(CDATAFRAME* dataframe){
    int i, j, max = 0;
    for (int a = 1; a < dataframe->logical_size; a++){
        if(dataframe->columns[a]->logical_sizes > dataframe->columns[max]->logical_sizes){
            max = a; // Find the column with the maximum number of rows
        }
    }
    for (i = 0; i < dataframe->logical_size; i++){
        if (dataframe->columns[i] != NULL)
            printf("\t%s\t", dataframe->columns[i]->title);
    }
    printf("\n");
    for (i = 0; i < dataframe->columns[max]->logical_sizes; i++){
        printf("[%d]", i);
        for (j = 0; j < dataframe->logical_size; j++){
            if (dataframe->columns[j] != NULL){
                if (i < dataframe->columns[j]->logical_sizes)
                    printf("\t%d\t", dataframe->columns[j]->data[i]);
                else
                    printf("\t\t");  // Print empty space if data does not exist
            }
        }
        printf("\n");
    }
}

// Function to display a specific row of the dataframe
void display_row_part_dataframe(CDATAFRAME dataframe, int row) {
    printf("Row %d: \n", row);
    for (int i = 0; i < dataframe.logical_size; i++) {
        if (dataframe.columns[i]->data[row - 1] == NULL) {
            printf("NULL\t"); // Print NULL if the data does not exist
        }
        printf("[%d] %d\t", i, dataframe.columns[i]->data[row - 1]);
    }
}

// Function to display a specific column of the dataframe
void display_col_part_dataframe(CDATAFRAME dataframe, int col){
    printf("\n");
    printf("Title: %s\n", dataframe.columns[col - 1]->title);
    printf("\n");
    print_col(dataframe.columns[col - 1]); // Print the column data
}

// Function to add a new row to the dataframe
void add_row(CDATAFRAME* dataframe){
    int val = 0;
    for (int i = 0; i < dataframe->logical_size; i++) {
        printf("Enter a value for column %d: ", i + 1);
        scanf("%d", &val); // Read the value from user input
        insert_value(dataframe->columns[i], val); // Insert the value into the column
    }
}

// Function to delete a specific row from the dataframe
void delete_row(CDATAFRAME* dataframe) {
    int r;
    printf("Which row do you want to delete: ");
    scanf("%d", &r);
    r -= 1;
    if (r < 0 || r >= dataframe->columns[0]->logical_sizes) {
        printf("Invalid row number.\n"); // Check if the row index is valid
        return;
    }
    for (int i = 0; i < dataframe->logical_size; i++) {
        COLUMN *col = dataframe->columns[i];
        for (int j = r; j < col->logical_sizes - 1; j++) {
            col->data[j] = col->data[j + 1];
        }
        col->logical_sizes--;
        if (col->physical_size - col->logical_sizes >= REALLOC_SIZE) {
            col->physical_size -= REALLOC_SIZE;
            col->data = realloc(col->data, col->physical_size * sizeof(int));
        }
    }
    printf("Row %d deleted.\n", r + 1);
}

// Function to delete a specific column from the dataframe
void delete_column1(CDATAFRAME* dataframe) {
    int c;
    printf("Which column do you want to delete: ");
    scanf("%d", &c);
    c -= 1;
    if (c < 0 || c >= dataframe->logical_size) {
        printf("Invalid column number.\n");
        return;
    }
    delete_column(&(dataframe->columns[c])); // Delete the column
    for (int i = c; i < dataframe->logical_size - 1; i++) {
        dataframe->columns[i] = dataframe->columns[i + 1];
    }
    dataframe->logical_size--; // Decrease logical size of the dataframe
    printf("Column %d deleted.\n", c + 1);
}

// Function to add a new column to the dataframe
void add_column(CDATAFRAME* dataframe){
    int val, len;
    char *title = (char*)malloc(100 * sizeof(char));
    dataframe->physical_size++;
    dataframe->logical_size++;
    printf("\nEnter the number of rows in the new column:\n");
    scanf("%d", &len);
    printf("\nGive us a new title");
    scanf("%s", title);
    dataframe->columns[dataframe->logical_size - 1] = create_column(title);

    // Loop to read and insert each value into the new column
    for (int j = 0; j < len; j++) {
        printf("Enter value at row %d\n", j);
        scanf("%d", &val);
        insert_value(dataframe->columns[dataframe->logical_size - 1], val);
    }
}

// Function to delete the last column of the dataframe
void cdata_delete_column(CDATAFRAME* dataframe){
    if(dataframe->logical_size == 0) {
        printf("No columns to delete!\n");
    }
    else{
        delete_column(&(dataframe->columns[dataframe->logical_size - 1]));  // Delete the last column
        dataframe->physical_size--;
        dataframe->logical_size--;
    }
}

// Function to rename a specific column of the dataframe
void rename_col(CDATAFRAME *dataframe, int col){
    char* new_title = (char*)malloc(100 * sizeof(char));
    printf("Enter a new title for column %d", col);
    scanf("%s", new_title);  // Read the new title from user input
    dataframe->columns[col - 1]->title = new_title;  // Assign the new title to the column
}

// Function to check if a value exists in the dataframe and print its position
void test_val_in(CDATAFRAME dataframe, int val){
    for(int i = 0; i < dataframe.logical_size; i++){
        for(int j = 0; j < dataframe.columns[i]->logical_sizes; j++){
            if(dataframe.columns[i]->data[j] == val){
                printf("The value has been found here: [%d;%d] \n", i, j);  // Print the position of the value
            }
        }
    }
}

// Function to replace a value in a specific cell of the dataframe
void replace_val(CDATAFRAME *dataframe, int col, int row, int val){
    dataframe->columns[col]->data[row] = val;  // Replace the value in the specified cell
}

// Function to display the names of all columns in the dataframe
void display_column_names(CDATAFRAME *dataframe){
    printf("\n");
    for(int i = 0; i < dataframe->logical_size; i++){
        printf("%s  ", dataframe->columns[i]->title);  // Print the column title
    }
}

// Function to get the number of columns in the dataframe
int number_columns(CDATAFRAME dataframe){
    return dataframe.physical_size; // Return the physical size of the dataframe
}

// Function to get the number of rows in the dataframe
int number_rows(CDATAFRAME dataframe){
    return dataframe.columns[0]->logical_sizes; // Return the number of rows in the first column
}

// Function to count the number of cells with a specific value in the dataframe
int nb_cells_equal_to_x(CDATAFRAME dataframe, int x){
    int cpt = 0;
    for(int i = 0; i < dataframe.logical_size; i++){
        for(int j = 0; j < dataframe.columns[i]->logical_sizes; j++){
            if(dataframe.columns[i]->data[j] == x){
                cpt++; // Increment the counter if the value matches
            }
        }
    }
    return cpt;
}

// Function to count the number of cells with values greater than a specific value in the dataframe
int nb_cells_value_greater_than_x(CDATAFRAME dataframe, int x){
    int cpt = 0;
    for(int i = 0; i < dataframe.logical_size; i++){
        for(int j = 0; j < dataframe.columns[i]->logical_sizes; j++){
            if(dataframe.columns[i]->data[j] > x){
                cpt++;
            }
        }
    }
    return cpt;
}

// Function to count the number of cells with values less than a specific value in the dataframe
int nb_cells_value_less_than_x(CDATAFRAME dataframe, int x){
    int cpt = 0;
    for(int i = 0; i < dataframe.logical_size; i++){
        for(int j = 0; j < dataframe.columns[i]->logical_sizes; j++){
            if(dataframe.columns[i]->data[j] < x){
                cpt++; // Increment the counter if the value is less
            }
        }
    }
    return cpt;
}

// Function to load a dataframe from a CSV file
CDATAFRAME *load_from_csv(char *file_name, int *array, int size) {
    FILE *file = fopen(file_name, "r");  // Open the file for reading
    if (file == NULL) {
        perror("Unable to open file");
        return NULL;
    }

    CDATAFRAME *dataframe = (CDATAFRAME*)malloc(sizeof(CDATAFRAME)); // Allocate memory for the dataframe structure
    dataframe->columns = (COLUMN**)malloc(size * sizeof(COLUMN*)); // Allocate memory for the columns array
    dataframe->physical_size = size; // Set the physical size of the dataframe
    dataframe->logical_size = size; // Set the logical size of the dataframe

    char line[1024];
    if (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, ",");
        for (int i = 0; i < size; i++) {
            dataframe->columns[i] = (COLUMN*)malloc(sizeof(COLUMN));  // Allocate memory for each column
            dataframe->columns[i]->title = strdup(token); // Set the column title
            dataframe->columns[i]->data = (int*)malloc(10 * sizeof(int));  // Allocate memory for column data
            dataframe->columns[i]->physical_size = 10; // Set the initial physical size of the column
            dataframe->columns[i]->logical_sizes = 0; // Set the initial logical size of the column
            dataframe->columns[i]->index = NULL;

            token = strtok(NULL, ",");
        }
    }

    // Loop to read and insert values into the dataframe
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, ",");
        for (int i = 0; i < size; i++) {
            if (token != NULL) {
                int value = atoi(token);
                COLUMN *col = dataframe->columns[i];

                // Resize the data array if necessary
                if (col->logical_sizes >= col->physical_size) {
                    col->physical_size *= 2;
                    col->data = (int*)realloc(col->data, col->physical_size * sizeof(int));
                }

                col->data[col->logical_sizes++] = value;

                token = strtok(NULL, ",");
            }
        }
    }

    fclose(file);  // Close the file
    return dataframe;  // Return the loaded dataframe
}
void sort_column(CDATAFRAME *cdataframe, int index) {
    if (cdataframe->columns[index]== NULL || cdataframe->columns[index]->data == NULL || cdataframe->columns[index] == NULL) {
        printf("Error: Column or data is NULL\n");
        return;
    }
    if (index < 0 || index >= cdataframe->logical_size) {
        printf("Error: Invalid index\n");
        return;
    }
    // Insertion sort algorithm
    for (int i = 1; i < cdataframe->columns[index]->logical_size2; i++) {
        int key = cdataframe->columns[index]->index[i];
        int j = i - 1;

        while (j >= 0 && cdataframe->columns[index]->data[cdataframe->columns[index]->index[j]] > cdataframe->columns[index]->data[key]) {
            cdataframe->columns[index]->index[j + 1]=cdataframe->columns[index]->index[j];
            j = j - 1;
        }
        cdataframe->columns[index]->index[j + 1]=key;
    }
    printf("Column '%s' sorted by index %d.\n", cdataframe->columns[index]->title, index);
}