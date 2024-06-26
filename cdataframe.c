#include "cdataframe.h"
#include "column.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int in(int nb, int *Tab, int TL){
    int i;
    for (i=0; i < TL; i++){
        if (Tab[i] == nb){
            return i;
        }
    }
    return -1;
}

DATAFRAME *create_dataframe(char *title){
    DATAFRAME *new_dataframe = malloc(sizeof(DATAFRAME));
    new_dataframe->title = title;
    new_dataframe->title = (char *)malloc(strlen(title) + 1);
    if (new_dataframe->title == NULL) {
        // Handle memory allocation failure
        free(new_dataframe);
        return NULL;
    }
    strcpy(new_dataframe->title, title);

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
    int i, x=0, signe = nb;
    int Tab[10];
    if(signe < 0){
        nb = -nb;
    }
    for(i=0; i<10; i++){
        Tab[i] = nb % 10;
        nb = nb /10;
    }
    for(i=9; i>-1; i--){
        if (Tab[i] == 0 && x == 0){
            printf(" ");
        }
        else{
            if(x == 0){
                x = 1;
                if (signe < 0){
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

void print_nb_col(int nb, int max_nb){
    int i = 0, j = 0, copy_nb = nb, k;
    do{
        i += 1;
        max_nb /=10;
    }while (max_nb > 0);
    do{
        j += 1;
        copy_nb /=10;
    }while (copy_nb > 0);
    for (k=0; k <= i - j; k++){
        printf(" ");
    }
    printf("%d|", nb);

}

void print_dataframe(DATAFRAME *dataframe){
    int i, j, maxTL, val;
    maxTL = max_TL(dataframe);
    printf("%s :\n", dataframe->title);

    print_nb_col(0, maxTL);
    for (i = 0; i < dataframe->TL; i++){
        justifier(dataframe->columns[i]->title);
    }

    printf("\n");
    for (i = 0; i < maxTL; i++){
        print_nb_col(i+1, maxTL);
        for (j = 0; j < dataframe->TL; j++){
            if (dataframe->columns[j]->TL > i){
                val = dataframe->columns[j]->data[i];
                print_nb(val);
            }
            else{
                printf("     -     |");
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
        if(in(i+1,liste_c, TL) != -1)
            justifier(dataframe->columns[i]->title);
    }

    for (i = 0; i < maxTL; i++){
        for (j = 0; j < dataframe->TL; j++){
            if(in(i+1,liste_c, TL) != -1) {
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

void add_ligne_data(DATAFRAME *dataframe){
    int i, val;
    for (i=0; i<dataframe->TL; i++){
        printf("Ajouter la valeur de %s : ", dataframe->columns[i]->title);
        scanf(" %d", &val);
        printf("\n");
        insert_value(dataframe->columns[i], val);
    }
}

void del_ligne_data(DATAFRAME *dataframe, int ligne){
    int i, j;
    if (max_TL(dataframe) <= ligne){
        printf("Erreur, la ligne n'existe pas.");
    }
    else{
        for (i=0; i<dataframe->TL; i++){
            if (ligne < dataframe->columns[i]->TL) {
                for (j = ligne; j < dataframe->columns[i]->TL - 1; j++) {
                    dataframe->columns[i]->data[j] = dataframe->columns[i]->data[j + 1];
                }
                dataframe->columns[i]->TL -= 1;
            }
        }
    }
}

void del_columns_data(DATAFRAME *dataframe, int nb_col){
    COLUMN *tmp;
    int i;
    if(nb_col > dataframe->TL){
        printf("Erreur, cette colonne n'existe pas\n");
    }
    else {
        for (i = nb_col; i < dataframe->TL -1; i++) {
            delete_column(&dataframe->columns[i]);
            tmp = dataframe->columns[i +1];
            dataframe->columns[i] = tmp;
            strcpy(dataframe->columns[i]->title, dataframe->columns[i+1]->title);
        }

        dataframe->TL -= 1;
    }
}

void del_dataframe(DATAFRAME *dataframe){
    int i;
    free((dataframe)->title);
    for (i=0; i < dataframe->TL; i++){
        delete_column(&dataframe->columns[i]);
    }
    free(dataframe);
}

void rename_col_data(DATAFRAME *dataframe, int nb_col, char *new_title){
    strcpy(dataframe->columns[nb_col - 1]->title, new_title);
}

int is_in_dataframe(DATAFRAME *dataframe, int val){
    int i, pos;
    for (i=0; i < dataframe->TL; i++){
        pos = in(val, dataframe->columns[i]->data, dataframe->columns[i]->TL);
        if(pos != -1){
            printf("La valeur se trouve a la ligne %d du dataframe, dans la colonne : %s\n", pos + 1, dataframe->columns[i]->title);
            return 1;
        }
    }
    printf("La valeur ne se trouve pas dans le dataframe.\n");
    return -1;
}

void change_value_dataframe(DATAFRAME *dataframe, int ligne, int colonne, int new_val){
    if (colonne > dataframe->TL){
        printf("Erreur, cette colonne n'existe pas.\n");
    }
    else{
        while(ligne > dataframe->columns[colonne - 1]->TL ){
            insert_value(dataframe->columns[colonne - 1], 0);
        }
        dataframe->columns[colonne - 1]->data[ligne-1] = new_val;
    }

}

void print_titles_data(DATAFRAME *dataframe){
    int i;
    for (i = 0; i < dataframe->TL; i++){
        printf("%s |", dataframe->columns[i]->title);
    }
}

void nb_lignes_data(DATAFRAME *dataframe){
    printf("%s comporte %d lignes", dataframe->title, max_TL(dataframe));
}

void nb_colonnes_data(DATAFRAME *dataframe){
    printf("%s comporte %d col", dataframe->title, dataframe->TL);
}

int nb_value_equal(DATAFRAME *dataframe, int val) {
    int i, j, tot = 0, nb_lignes = max_TL(dataframe);
    for (i = 0; i < dataframe->TL; i++) {
        for (j = 0; j < nb_lignes; j++) {
            if (dataframe->columns[i]->data[j] == val) {
                tot += 1;
            }
        }
    }
    return tot;
}


int nb_value_over(DATAFRAME *dataframe, int val){
    int i, j, tot = 0, nb_lignes = max_TL(dataframe);
    for (i = 0; i < dataframe->TL; i++) {
        for (j = 0; j < nb_lignes; j++) {
            if (dataframe->columns[i]->data[j] > val) {
                tot += 1;
            }
        }
    }
    return tot;
}

int nb_value_under(DATAFRAME *dataframe, int val){
    int i, j, tot = 0, nb_lignes = max_TL(dataframe);
    for (i = 0; i < dataframe->TL; i++) {
        for (j = 0; j < nb_lignes; j++) {
            if (dataframe->columns[i]->data[j] < val) {
                tot += 1;
            }
        }
    }
    return tot;
}

void insert_value_data(DATAFRAME *dataframe, int col, int val){
    insert_value(dataframe->columns[col - 1], val);
}