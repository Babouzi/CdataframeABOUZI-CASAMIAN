#ifndef CDATAFRAME_H
#define CDATAFRAME_H
#include "column.h"

typedef struct DATAFRAME{
    COLUMN **columns;
    char *title;
    int TP;
    int TL;
}DATAFRAME;

DATAFRAME *create_dataframe(char *title);

int add_column(DATAFRAME *data_frame, COLUMN *column);

int max_TL(DATAFRAME *dataframe);

void print_dataframe(DATAFRAME *dataframe);

#endif //CDATAFRAME_H
