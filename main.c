#include <stdio.h>
#include <stdlib.h>
#include "column.h"
#include "cdataframe.h"

int main() {
    COLUMN *col1 = create_column("Colonne 1"), *col2 = create_column("Colonne 2"), *col3 = create_column("Colonne 3");
    DATAFRAME *dataframe = create_dataframe("Dataframe 1");
    insert_value(col1, 5);
    insert_value(col1,4);
    insert_value(col1,7);
    insert_value(col2,4);
    insert_value(col2,7);
    insert_value(col3, 5);
    insert_value(col3,4);
    insert_value(col3,7);
    insert_value(col3,4);
    insert_value(col3,-107);
    add_column(dataframe, col1);
    add_column(dataframe, col2);
    add_column(dataframe, col3);
    add_column(dataframe, create_column("Colonne 4"));
    add_ligne_data(dataframe);
    print_dataframe(dataframe);
    del_ligne_data(dataframe, 2);
    ///del_columns_data(dataframe, 1);
    print_dataframe(dataframe);
    del_dataframe(dataframe);
    return 0;
}
