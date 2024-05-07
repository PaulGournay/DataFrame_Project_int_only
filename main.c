#include <stdlib.h>
#include <stdio.h>

#include <cdataframe.h>
int main() {
    // Create a new column
    COLUMN *mycol = create_column("My column");

    // Insert values into the column
    insert_value(mycol, 52);
    insert_value(mycol, 44);
    insert_value(mycol, 18);
    insert_value(mycol, 15);
    insert_value(mycol, 15);

    // Print the column data
    print_col(mycol);

    // Find the occurrence of a value
    int val = 15;
    printf("The occurrence of %d is %d\n", val, occurence_val(mycol, val));

    // Get value at a specific index
    int index = 2;
    printf("At index %d we have the value: %d\n", index, get_index_val(mycol, index));

    // Count the number of values greater than and lower than a certain value
    int x = 20;
    printf("There are %d values greater than %d\n", nb_val_greater_than_x(mycol, x), x);
    printf("There are %d values lower than %d\n", nb_val_lower_than_x(mycol, x));

    // Free allocated memory
    delete_column(&mycol);
    CDATAFRAME *df= create_dataframe(3);


    return 0;
}
