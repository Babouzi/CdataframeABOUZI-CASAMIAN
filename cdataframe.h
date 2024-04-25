#ifndef CDATAFRAME_H
#define CDATAFRAME_H
#include "column.h"

typedef struct DATAFRAME{
    COLUMN *columns;
    char *title;
    int TP;
    int TL;
}DATAFRAME;

DATAFRAME *create_dataframe();


#endif //CDATAFRAME_H
