#include <stdio.h>

typedef struct {
    char *title;
    int TP;
    int TL;
    int *tab;
}COLUMN;



COLUMN create_column(char* title){
    COLUMN col;
    col.title = *title;
}

int main() {
    COLUMN* col;

    printf("Hello, World!\n");
    return 0;
}