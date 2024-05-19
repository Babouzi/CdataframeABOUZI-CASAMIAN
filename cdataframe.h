#ifndef CDATAFRAME_H
#define CDATAFRAME_H
#include "column.h"

typedef struct DATAFRAME{
    COLUMN **columns;
    char *title;
    int TP;
    int TL;
}DATAFRAME;

int in(int nb, int *Tab, int TL);

DATAFRAME* create_dataframe(char *title);

int add_column(DATAFRAME *data_frame, COLUMN *column);

int max_TL(DATAFRAME *dataframe);

void justifier(char* string);

void print_nb(int nb);

void print_dataframe(DATAFRAME *dataframe);

void add_ligne_data(DATAFRAME * dataframe);

void del_ligne_data(DATAFRAME * dataframe, int ligne);

void del_columns_data(DATAFRAME *dataframe, int nb_col);

void del_dataframe(DATAFRAME *dataframe);

void rename_col_data(DATAFRAME *dataframe, int nb_col, char *new_title);

int is_in_dataframe(DATAFRAME *dataframe, int val);

void change_value_dataframe(DATAFRAME *dataframe, int ligne, int colonne, int new_val);

void print_titles_data(DATAFRAME *dataframe);

void nb_lignes_data(DATAFRAME *dataframe);

void nb_colonnes_data(DATAFRAME *dataframe);

int nb_value_equal(DATAFRAME *dataframe, int val);

int nb_value_over(DATAFRAME *dataframe, int val);

int nb_value_under(DATAFRAME *dataframe, int val);

void insert_value_data(DATAFRAME *dataframe, int col, int val);

#endif //CDATAFRAME_H
