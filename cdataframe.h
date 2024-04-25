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

DATAFRAME *add_column(DATAFRAME *dataFrame, COLUMN *column);

#endif //CDATAFRAME_H
