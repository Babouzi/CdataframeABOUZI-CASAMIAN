#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *title;
    int TP;
    int TL;
    int *tab;
}COLUMN;



COLUMN *create_column(char* title){
    COLUMN *col = NULL;
    col = malloc(sizeof (COLUMN));
    col->title = title;
    col->TL = 0;
    return col;
}

void print_col(COLUMN* col){
    int i;
    for(i=0; i<col->TL; i++){
        printf("[%d] %d\n", i, col->tab[i]);
    }
}

int insert_value(COLUMN* col, int value){
    if (col->TL == 0){
        col->TP = 256;
        col->tab = malloc(col->TP * sizeof(int));
    }
    col->tab[col->TL] = value;
    col->TL += 1;
}


int main() {
    COLUMN* col = create_column("Colonne 1");
    printf("%s", col->title);
    insert_value(col, 5);
    print_col(col);
    return 0;
}