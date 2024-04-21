#include "column.h"
#include <stdio.h>
#include <stdlib.h>
#define REALLOC_SIZE 256


COLUMN *create_column(char* title) {
    COLUMN *new_column = malloc(sizeof(COLUMN));
    if (new_column == NULL) {
        return NULL;
    }

    int title_length = 0;
    while (title[title_length] != '\0') {
        title_length++;
    }

    new_column->title = malloc(title_length + 1);
    if (new_column->title == NULL) {
        free(new_column);
        return NULL;
    }

    for (int i = 0; i <= title_length; i++) {
        new_column->title[i] = title[i];
    }

    new_column->TL = 0;
    new_column->data = NULL;
    return new_column;
}


int insert_value(COLUMN* col, int value) {
    if (col == NULL) {
        return 0;
    }

    int new_TP;
    if (col->TP == 0) {
        new_TP = REALLOC_SIZE;
    } else {
        new_TP = col->TP + REALLOC_SIZE;
    }

    int *new_data = realloc(col->data, new_TP * sizeof(int));
    if (new_data == NULL) {
        return 0;
    }

    col->data = new_data;
    col->TP = new_TP;
    col->data[col->TL++] = value;
    return 1;
}




void delete_column(COLUMN **col) {
    if (col == NULL || *col == NULL) {
        return;
    }

    free((*col)->data);
    free((*col)->title);
    free(*col);
    *col = NULL;
}


void print_col(COLUMN* col) {
    if (col == NULL || col->data == NULL || col->TL == 0) {
        printf("La colonne est vide.\n");
        return;
    }
    for (int i = 0; i < col->TL; i++) {
        printf("[%d] %d\n", i, col->data[i]);
    }
}



int count_occurrences(COLUMN* col, int x) {
    if (col == NULL || col->data == NULL || col->TL == 0) {
        return 0; // Pas d'occurrence dans une colonne vide
    }

    int count = 0;
    for (int i = 0; i < col->TL; i++) {
        if (col->data[i] == x) {
            count++;
        }
    }
    return count;
}

int get_value_at_position(COLUMN* col, int position) {
    if (col == NULL || col->data == NULL || col->TL == 0 || position < 0 || position >= col->TL) {
        return -1; // Valeur invalide ou position hors de la plage
    }
    return col->data[position];
}

int count_values_greater_than(COLUMN* col, int x) {
    if (col == NULL || col->data == NULL || col->TL == 0) {
        return 0; // Pas de valeurs supérieures dans une colonne vide
    }

    int count = 0;
    for (int i = 0; i < col->TL; i++) {
        if (col->data[i] > x) {
            count++;
        }
    }
    return count;
}

int count_values_less_than(COLUMN* col, int x) {
    if (col == NULL || col->data == NULL || col->TL == 0) {
        return 0; // Pas de valeurs inférieures dans une colonne vide
    }

    int count = 0;
    for (int i = 0; i < col->TL; i++) {
        if (col->data[i] < x) {
            count++;
        }
    }
    return count;
}

int count_values_equal_to(COLUMN* col, int x) {
    if (col == NULL || col->data == NULL || col->TL == 0) {
        return 0; // Pas de valeurs égales dans une colonne vide
    }

    int count = 0;
    for (int i = 0; i < col->TL; i++) {
        if (col->data[i] == x) {
            count++;
        }
    }
    return count;
}
