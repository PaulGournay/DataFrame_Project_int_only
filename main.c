#include <stdlib.h>
#include <stdio.h>
#include <column.h>
int main(){

    COLUMN *mycol = create_column("My column");
    int val =15;
    insert_value(mycol, 52);
    insert_value(mycol, 44);
    insert_value(mycol, 18);
    insert_value(mycol, 15);
    insert_value(mycol, 15);
    print_col(mycol);
    printf("the occurence of %d is %d\n",val, occurence_val(mycol,val));
    printf("At index 2 we have the value : %d\n", get_index_val(mycol,2));
    printf("there is %d value greater than 20\n", nb_val_greater_than_x(mycol,20));
    printf("there is %d value lower than 20\n", nb_val_lower_than_x(mycol,20));

    return 0;
}