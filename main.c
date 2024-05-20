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
    printf("9. Add Row to DataFrame\n");
    printf("10. Delete Row from DataFrame\n");
    printf("11. Add Column to DataFrame\n");
    printf("12. Delete Column from DataFrame\n");
    printf("13. Rename Column\n");
    printf("14. Test Value in DataFrame\n");
    printf("15. Replace Value in DataFrame\n");
    printf("16. Display Column Names\n");
    printf("17. Number of Columns\n");
    printf("18. Number of Rows\n");
    printf("19. Number of Cells Equal to X\n");
    printf("20. Number of Cells Greater Than X\n");
    printf("21. Number of Cells Less Than X\n");
    printf("22. Load DataFrame from CSV\n");
    printf("23. Exit\n");
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





            default:
                printf("Invalid choice! Please try again.\n");
                scanf("%d",&r);
                printf("\n");
                break;
        }

    }


    return 0;
}
