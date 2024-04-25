#ifndef CDATAFRAME_H
#define CDATAFRAME_H
#include "column.h"

typedef struct DATAFRAME{
    COLUMN *columns;
    int TP;
    int TL;
};




#endif //CDATAFRAME_H
