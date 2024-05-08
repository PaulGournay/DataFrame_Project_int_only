#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <cdataframe.h>
int main() {
    // Create a new column

    COLUMN *mycol = create_column("My column");
    srand(time(NULL));
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
    int val2=1;
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
    /*CDATAFRAME *df= create_dataframe(3);
    fill_dataframe_user(df );
    display_entire_dataframe(*df);
    printf("\n");
    display_row_part_dataframe(*df,2);
    display_col_part_dataframe(*df,2);*/
    /*CDATAFRAME *df2= create_dataframe(5);
    hard_fill_dataframe(df2);
    display_entire_dataframe(*df2);*/
    CDATAFRAME *df3= create_dataframe(3);
    OXO_fill_dataframe(df3);
    display_entire_dataframe(*df3);
    /*display_row_part_dataframe(*df3,2);
    display_col_part_dataframe(*df3,2);
    add_row(df3);
    printf("dataframe with new row\n");
    display_entire_dataframe(*df3);
    delete_row(df3);
    printf("dataframe with last row deleted");
    display_entire_dataframe(*df3);
    add_column(df3);
    display_entire_dataframe(*df3);
    cdata_delete_column(df3);
    printf("\nafter column deleted :\n");
    display_entire_dataframe(*df3);
    rename_col(df3,2);
    replace_val(df3,1,1,654);
    display_entire_dataframe(*df3);
    display_column_names(df3);*/
    printf("\nnbcol=%d,nbrow=%d", number_columns(*df3), number_rows(*df3));
    printf("\nthere is %d times the value %d in the cdataaframe", nb_cells_equal_to_x(*df3,val2),val2);

    return 0;
}
