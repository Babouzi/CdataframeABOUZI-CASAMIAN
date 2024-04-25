#include "cdataframe.h"
#include <stdio.h>
#include <stdlib.h>

DATAFRAME *create_dataframe(char *t){
    DATAFRAME *new_dataframe = malloc(sizeof(DATAFRAME));
    new_dataframe->title = t;
    new_dataframe.TP = 10;
    new_dataframe.TL = 0;

}