#include "column.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define REALLOC_SIZE 256


COLUMN *create_column(char *title) {
    COLUMN *new_column = malloc(sizeof(COLUMN));
    if (new_column == NULL) {
        return NULL;
    }

    // Allocate memory for the title and copy the string
    new_column->title = (char *)malloc(strlen(title) + 1);
    if (new_column->title == NULL) {
        // Handle memory allocation failure
        free(new_column);
        return NULL;
    }
    strcpy(new_column->title, title);

    new_column->TL = 0;
    new_column->TP = 0; // Initialize to zero, will be adjusted in insert_value
    new_column->data = NULL;
    return new_column;
}


int insert_value(COLUMN* col, int value) {
    if (col == NULL) {
        return 0; // Handle NULL pointer
    }

    int new_TP;
    if (col->TP == 0) {
        // Allocate memory for the data array if not already allocated
        col->data = malloc(REALLOC_SIZE * sizeof(int));
        if (col->data == NULL) {
            return 0; // Memory allocation failed
        }
        col->TP = REALLOC_SIZE;
    } else if (col->TL == col->TP) {
        // Reallocate memory only if there's not enough space
        int *new_data = realloc(col->data, (col->TP + REALLOC_SIZE) * sizeof(int));
        if (new_data == NULL) {
            return 0; // Memory reallocation failed
        }
        col->data = new_data;
        col->TP += REALLOC_SIZE;
    }
    // Insert the value and update TL
    col->data[col->TL++] = value;
    return 1; // Successfully inserted value
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
