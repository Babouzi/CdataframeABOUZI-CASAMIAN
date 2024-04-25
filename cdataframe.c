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
        COLUMN **temp_realloc = realloc(data_frame->columns, data_frame->TP * sizeof(COLUMN*));
        data_frame->columns = temp_realloc;
    }
    data_frame->columns[data_frame->TL] = column;
    data_frame->TL += 1;
    return 1;
}

int max_TL(DATAFRAME *dataframe){
    int i, max = 0;
    for (i = 0; i < dataframe->TL; i++){
        if (max < dataframe->columns[i]->TL){
        max = dataframe->columns[i]->TL;
        }
    }
    return max;
}

void print_dataframe(DATAFRAME *dataframe){
    int i, j, maxTL, val;
    maxTL = max_TL(dataframe);
    printf("%s\n", dataframe->title);

    for (i = 0; i < dataframe->TL; i++){

    }

    for (i = 0; i < max_TL(dataframe); i++){
        for (j = 0; j < dataframe->TL; j++){
            if (dataframe->columns[j]->TL < i){
                printf(" - ");
            }
            else{
                val = dataframe->columns[j]->data[i];
                printf(" %d ", val);
            }
        }
        printf("\n");
    }

}