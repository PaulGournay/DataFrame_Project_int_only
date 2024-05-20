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
    printf("13. statistic of number of columns and rows and names of columns");
    printf("14. Number of Cells Equal/Greater/Less to X\n");
    printf("15. Load DataFrame from CSV\n");
    printf("16. Exit\n");
}

int main() {


    int choice, col, row, val, size, x,r;
    char filename[256];
    printf("Let's firstly create a random Cdataframe  in order to test the functions\n ");
    CDATAFRAME *hardfill = create_dataframe(3);
    hard_fill_dataframe(hardfill);

    display_cdataframe_fancy(hardfill);
    printf("input any number to continue...\n");
    scanf("%d",&r);
    printf("\n");

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1: // Create your own DataFrame

                printf("how many column do you want for your CDATAFRAME");
                scanf("%d", &size);
                CDATAFRAME *dataframe = create_dataframe(size);
                fill_dataframe_user(dataframe);
                display_entire_dataframe(*dataframe);
                printf("input any number to continue...\n");
                scanf("%d",&r);
                printf("\n");
                break;
            case 2 :


                printf("let's hard fill an ohter CDATAFRAME\n");
                printf("how many column do you want for your CDATAFRAME");
                scanf("%d", &r);
                CDATAFRAME *hardfill1 = create_dataframe(r);
                hard_fill_dataframe(hardfill1);

                display_entire_dataframe(*hardfill1);
                printf("input any number to continue...\n");
                scanf("%d",&r);
                printf("\n");
                break;
            case 3 :
                display_cdataframe_fancy(hardfill);
                printf("input any number to continue...\n");
                scanf("%d",&r);
                printf("\n");
                break;
            case 4:
                printf("Which row do you want to display\n");
                scanf("%d", &r);
                display_row_part_dataframe(*hardfill,r);
                printf("\n");



                printf("input any number to continue...\n");
                scanf("%d",&r);
                printf("\n");
                break;
            case 5:
                printf("Which colunm do you want to display\n");
                scanf("%d", &r);
                display_col_part_dataframe(*hardfill,r);
                printf("\n");



                printf("input any number to continue...\n");
                scanf("%d",&r);
                printf("\n");
                break;
            case 6 :
                printf("let's add a row in your dataframe");
                printf("\n");
                add_row(hardfill);
                display_cdataframe_fancy(hardfill);


                printf("input any number to continue...\n");
                scanf("%d",&r);
                printf("\n");
            case 7:
                printf("let's add a column in your dataframe");
                printf("\n");
                add_column(hardfill);
                display_cdataframe_fancy(hardfill);


                printf("input any number to continue...\n");
                scanf("%d",&r);
                printf("\n");
            case 8 :
                printf("let's delete a row in your dataframe");
                printf("\n");
                delete_row(hardfill);
                display_cdataframe_fancy(hardfill);


                printf("input any number to continue...\n");
                scanf("%d",&r);
                printf("\n");
            case 9 :
                printf("let's delete a column in your dataframe");
                printf("\n");
                delete_column1(hardfill);
                display_cdataframe_fancy(hardfill);


                printf("input any number to continue...\n");
                scanf("%d",&r);
                printf("\n");
            case 10:
                printf("let's rename a column");
                printf("\n");
                printf("Which colunm do you want to rename\n");
                scanf("%d", &r);
                rename_col(hardfill,r);
                display_cdataframe_fancy(hardfill);


                printf("input any number to continue...\n");
                scanf("%d",&r);
                printf("\n");
            case 11:
                printf("let's test a value in your dataframe");
                printf("\n");
                printf("Which value do you want to test\n");
                scanf("%d", &r);
                test_val_in(*hardfill,r);





                printf("input any number to continue...\n");
                scanf("%d",&r);
                printf("\n");
            case 12:
                printf("Give me the col the row of the value that you want to replace and finally the value by which you'll replace");
                scanf("%d %d %d",&col,&row,&val);
                replace_val(hardfill,col,row,val);
                display_cdataframe_fancy(hardfill);

                printf("Invalid choice! Please try again.\n");
                scanf("%d",&r);
                printf("\n");
                break;
            case 13:
                printf("here is the columns' names :");
                printf("\n");
                display_column_names(hardfill);
                printf("The number of row : %d", number_rows(*hardfill));
                printf("\n");
                printf("The number of column : %d", number_columns(*hardfill));


                printf("Invalid choice! Please try again.\n");
                scanf("%d",&r);
                printf("\n");
            case 14:
                printf("Which value do you want to test\n");
                scanf("%d", &r);
                printf("the number of cells less than %d : %d",r,nb_cells_value_less_than_x(*hardfill,r));
                printf("\n");
                printf("the number of cells less than %d : %d",r,nb_cells_equal_to_x(*hardfill,r));
                printf("\n");
                printf("the number of cells less than %d : %d",r,nb_cells_value_greater_than_x(*hardfill,r));

                printf("Invalid choice! Please try again.\n");
                scanf("%d",&r);
                printf("\n");
                break;
            case 15:


            case 16:
                printf("Thank you, come back soon");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
                scanf("%d",&r);
                printf("\n");
                break;



        }

    }


    return 0;
}
