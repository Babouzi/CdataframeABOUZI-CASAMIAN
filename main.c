#include <stdio.h>
#include <stdlib.h>
#include "column.h"


int main() {
    COLUMN* col = create_column("Colonne 1");
    printf("%s", col->title);
    insert_value(col, 5);
    insert_value(col,4);
    insert_value(col,7);
    print_col(col);
    delete_column(col);
    return 0;
}
