#include "cdataframe.h"
#include "column.h"
#include <stdio.h>
#include <stdlib.h>

int in(int nb, int *Tab, int TL){
    int i;
    for (i=0; i < TL; i++){
        if (Tab[i] == nb){
            return 1;
        }
    }
    return 0;
}

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

void justifier(char* string){
    int i = 0;
    while (string[i] != '\0' &&  i < 11){
        printf("%c", string[i]);
        i++;
    }
    while(i<11){
        printf(" ");
        i++;
    }
    printf("|");
}

void print_nb(int nb){
    int i, x=0;
    int Tab[10];
    for(i=0; i<10; i++){
        Tab[i] = i % 10;
        i = i /10;
    }

    for(i=9; i>-1; i++){
        if (Tab[i] == 0 && x == 0){
            printf(" ");
        }
        else{
            if(x == 0){
                x = 1;
                if (nb < 0){
                    printf("-");
                }
                else{
                    printf(" ");
                }
            }
            printf("%d", Tab[i]);
        }
    }
    printf("|");
}

void print_dataframe(DATAFRAME *dataframe){
    int i, j, maxTL, val;
    maxTL = max_TL(dataframe);
    printf("%s\n", dataframe->title);

    for (i = 0; i < dataframe->TL; i++){
        justifier(dataframe->columns[i]->title);
    }

    for (i = 0; i < maxTL; i++){
        for (j = 0; j < dataframe->TL; j++){
            if (dataframe->columns[j]->TL < i){
                printf("     -     |");
            }
            else{
                val = dataframe->columns[j]->data[i];
                print_nb(val);
            }
        }
        printf("\n");
    }
}

void lignes_dataframe(DATAFRAME* dataframe, int l_deb, int l_fin){
    int i, j, val;
    printf("%s\n", dataframe->title);

    for (i = 0; i < dataframe->TL; i++){
        justifier(dataframe->columns[i]->title);
    }

    for (i = l_deb-1; i < l_fin; i++){
        for (j = 0; j < dataframe->TL; j++){
            if (dataframe->columns[j]->TL < i){
                printf("     -     |");
            }
            else{
                val = dataframe->columns[j]->data[i];
                print_nb(val);
            }
        }
        printf("\n");
    }
}

void colonne_dataframe(DATAFRAME *dataframe, int *liste_c, int TL){
    int i, j, maxTL, val;
    maxTL = max_TL(dataframe);
    printf("%s\n", dataframe->title);

    for (i = 0; i < dataframe->TL; i++){
        if(in(i+1,liste_c, TL) == 1)
            justifier(dataframe->columns[i]->title);
    }

    for (i = 0; i < maxTL; i++){
        for (j = 0; j < dataframe->TL; j++){
            if(in(i+1,liste_c, TL) == 1) {
                if (dataframe->columns[j]->TL < i) {
                    printf("     -     |");
                } else {
                    val = dataframe->columns[j]->data[i];
                    print_nb(val);
                }
            }
        }
        printf("\n");
    }
}