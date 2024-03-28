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
    return col;
}

void print_col(COLUMN* col){
    int i;
    for(i=0; i<col->TL; i++){
        printf("[%d] %d\n", i, col->tab[i]);
    }
}

int main() {
    COLUMN* col = create_column("Colonne 1");
    printf("%s", col->title);

    return 0;
}