#include <stdio.h>
#include <stdlib.h>
#include "cdataframe.h"

void menu() {
    printf("CDataframe Menu:\n");
    printf("1. Create your own DataFrame\n");
    printf("2. Fill DataFrame (Random Hard Fill)\n");
    printf("3. Display DataFrame Fancy\n");
    printf("4. Display Row of DataFrame\n");
    printf("5. Display Column of DataFrame\n");
    printf("6. Add Row to DataFrame\n");
    printf("7. Add Column to DataFrame\n");
    printf("8. Delete Row from DataFrame\n");
    printf("9. Delete Column from DataFrame\n");
    printf("10. Rename Column\n");
    printf("11. Test Value in DataFrame\n");
    printf("12. Replace Value in DataFrame\n");
    printf("13. Statistic of number of columns and rows and names of columns\n");
    printf("14. Number of Cells Equal/Greater/Less to X\n");
    printf("15. Load DataFrame from CSV\n");
    printf("16. Exit\n");
}

int main() {
    int choice, col, row, val, size, x, r;
    char filename[256];
    CDATAFRAME *hardfill = NULL;
    CDATAFRAME *dataframe = NULL;

    printf("Let's firstly create a random Cdataframe in order to test the functions\n");
    hardfill = create_dataframe(3);
    hard_fill_dataframe(hardfill);

    display_cdataframe_fancy(hardfill);
    printf("Input any number to continue...\n");
    scanf("%d", &r);
    printf("\n");

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Create your own DataFrame
                printf("How many columns do you want for your CDATAFRAME: ");
                scanf("%d", &size);
                dataframe = create_dataframe(size);
                fill_dataframe_user(dataframe);
                display_entire_dataframe(*dataframe);
                printf("Input any number to continue...\n");
                scanf("%d", &r);
                printf("\n");
                break;

            case 2: // Fill DataFrame (Random Hard Fill)
                printf("Let's hard fill another CDATAFRAME\n");
                printf("How many columns do you want for your CDATAFRAME: ");
                scanf("%d", &r);
                dataframe = create_dataframe(r);
                hard_fill_dataframe(dataframe);
                display_entire_dataframe(*dataframe);
                printf("Input any number to continue...\n");
                scanf("%d", &r);
                printf("\n");
                break;

            case 3: // Display DataFrame Fancy
                display_cdataframe_fancy(hardfill);
                printf("Input any number to continue...\n");
                scanf("%d", &r);
                printf("\n");
                break;

            case 4: // Display Row of DataFrame
                printf("Which row do you want to display: ");
                scanf("%d", &r);
                display_row_part_dataframe(*hardfill, r);
                printf("Input any number to continue...\n");
                scanf("%d", &r);
                printf("\n");
                break;

            case 5: // Display Column of DataFrame
                printf("Which column do you want to display: ");
                scanf("%d", &r);
                display_col_part_dataframe(*hardfill, r);
                printf("Input any number to continue...\n");
                scanf("%d", &r);
                printf("\n");
                break;

            case 6: // Add Row to DataFrame
                printf("Let's add a row in your dataframe\n");
                add_row(hardfill);
                display_cdataframe_fancy(hardfill);
                printf("Input any number to continue...\n");
                scanf("%d", &r);
                printf("\n");
                break;

            case 7: // Add Column to DataFrame
                printf("Let's add a column in your dataframe\n");
                add_column(hardfill);
                display_cdataframe_fancy(hardfill);
                printf("Input any number to continue...\n");
                scanf("%d", &r);
                printf("\n");
                break;

            case 8: // Delete Row from DataFrame
                printf("Let's delete a row in your dataframe\n");
                delete_row(hardfill);
                display_cdataframe_fancy(hardfill);
                printf("Input any number to continue...\n");
                scanf("%d", &r);
                printf("\n");
                break;

            case 9: // Delete Column from DataFrame
                printf("Let's delete a column in your dataframe\n");
                delete_column1(hardfill);
                display_cdataframe_fancy(hardfill);
                printf("Input any number to continue...\n");
                scanf("%d", &r);
                printf("\n");
                break;

            case 10: // Rename Column
                printf("Let's rename a column\n");
                printf("Which column do you want to rename: ");
                scanf("%d", &r);
                rename_col(hardfill, r);
                display_cdataframe_fancy(hardfill);
                printf("Input any number to continue...\n");
                scanf("%d", &r);
                printf("\n");
                break;

            case 11: // Test Value in DataFrame
                printf("Let's test a value in your dataframe\n");
                printf("Which value do you want to test: ");
                scanf("%d", &r);
                test_val_in(*hardfill, r);
                printf("Input any number to continue...\n");
                scanf("%d", &r);
                printf("\n");
                break;

            case 12: // Replace Value in DataFrame
                printf("Give me the column, the row of the value that you want to replace and finally the value by which you'll replace: ");
                scanf("%d %d %d", &col, &row, &val);
                replace_val(hardfill, col, row, val);
                display_cdataframe_fancy(hardfill);
                printf("Input any number to continue...\n");
                scanf("%d", &r);
                printf("\n");
                break;

            case 13: // Statistic of number of columns and rows and names of columns
                printf("Here are the columns' names:\n");
                display_column_names(hardfill);
                printf("The number of rows: %d\n", number_rows(*hardfill));
                printf("The number of columns: %d\n", number_columns(*hardfill));
                printf("Input any number to continue...\n");
                scanf("%d", &r);
                printf("\n");
                break;

            case 14: // Number of Cells Equal/Greater/Less to X
                printf("Which value do you want to test: ");
                scanf("%d", &r);
                printf("The number of cells less than %d: %d\n", r, nb_cells_value_less_than_x(*hardfill, r));
                printf("The number of cells equal to %d: %d\n", r, nb_cells_equal_to_x(*hardfill, r));
                printf("The number of cells greater than %d: %d\n", r, nb_cells_value_greater_than_x(*hardfill, r));
                printf("Input any number to continue...\n");
                scanf("%d", &r);
                printf("\n");
                break;

            case 15: // Load DataFrame from CSV
                if (dataframe != NULL) {
                    // Free the existing dataframe if present
                    for (int i = 0; i < dataframe->logical_size; i++) {
                        delete_column(&dataframe->columns[i]);
                    }
                    free(dataframe->columns);
                    free(dataframe);
                }
                printf("Enter the filename to load CSV from: ");
                scanf("%s", filename);
                printf("Enter the number of columns in the CSV: ");
                int num_columns;
                scanf("%d", &num_columns);
                dataframe = load_from_csv(filename, NULL, num_columns);
                if (dataframe != NULL) {
                    printf("Dataframe loaded successfully from %s.\n", filename);
                    display_entire_dataframe(*dataframe);
                } else {
                    printf("Failed to load dataframe from %s.\n", filename);
                }
                printf("Input any number to continue...\n");
                scanf("%d", &r);
                printf("\n");
                break;
            case 16: // Exit
                printf("Thank you, come back soon.\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
                scanf("%d", &r);
                printf("\n");
                break;
        }
    }
    return 0;
}
