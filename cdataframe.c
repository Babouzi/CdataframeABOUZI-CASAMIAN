#include "cdataframe.h"
#include "column.h"
#include <stdio.h>
#include <stdlib.h>

DATAFRAME *create_dataframe(char *title){
    DATAFRAME *new_dataframe = malloc(sizeof(DATAFRAME));
    new_dataframe->title = title;
    new_dataframe->TP = 10;
    new_dataframe->TL = 0;
    new_dataframe->columns = malloc(10* sizeof (COLUMN*));
    return new_dataframe;
}

int add_column(DATAFRAME *data_frame, COLUMN *column){
    if (data_frame->TL >= data_frame->TP){
        data_frame->TP += 10;
        data_frame->columns = realloc(data_frame->columns, data_frame->TP * sizeof(COLUMN*));
        if (data_frame->columns == NULL) {
            return 0;
        }
    }

    data_frame->columns[data_frame->TL] = column;
    data_frame->TL += 1;
    return 1;
}