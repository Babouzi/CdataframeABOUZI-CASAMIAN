#include <stdio.h>
#include <stdlib.h>
#include "column.h"
#include "cdataframe.h"

void clear_endline(char *txt){
    int i;
    for (i=0; txt[i] != '\0'; i++){
        i += 1;
        if(txt[i] == '\n'){
            txt[i] = '\0';
        }
    }
    txt[i-1] = '\0';
}

int main() {
    int start = 1, all_dataframes_TL = 0, i, number, ligne, colonne;
    char command[10], title[100], empty_buffer, analyse_tool;
    DATAFRAME **all_dataframes, no_data;
    all_dataframes = malloc(10 * sizeof(DATAFRAME*));
    DATAFRAME *dataframe = &no_data;

    while (start == 1) {
        printf("Que voulez-vous faire, entrez '?' pour avoir la liste des commande :");
        fgets(command, 10, stdin);
        ///printf("\n");
        if (command[0] == '?') { ///&& command[1] == '\0'){
            printf("Liste des commandes :\n_'stop' pour arreter le programme\n_'print' pour afficher le dataframe\n");
            printf("_'new_d'pour creer un nouveau dataframe\n_'change_d' pour changer le dataframe etudie\n");
            printf("_'add_c'pour ajouter une colonne\n_'add_l' pour ajouter une ligne\n_'modif' pour modifier une case precise\n");
            printf("_'add_v'pour ajouter une valeur dans une colonne du dataframe\n_'analyse' pour ouvrir l'outil de comparaison du dataframe\n");
            printf("_'supp_l'pour supprimer une ligne du dataframe\n_'supp_d' pour supprimer le dataframe\n");
        }
        if (command[0] == 's' && command[1] == 't' && command[2] == 'o' && command[3] == 'p') {
            start = 0;
        }
        if (command[0] == 'p' && command[1] == 'r' && command[2] == 'i' && command[3] == 'n' && command[4] == 't') {
            if (dataframe == &no_data) {
                printf("Vous ne travaillez actuellement dans aucun dataframe, entrez 'change_d' pour choisir votre dataframe, ou 'new_d' pour en creer un nouveau.\n");
            } else {
                print_dataframe(dataframe);
            }

        }
        if (command[0] == 'n' && command[1] == 'e' && command[2] == 'w' && command[3] == '_' && command[4] == 'd') {
            printf("Entrez un titre pour le dataframe : \n");
            fgets(title, 100, stdin);
            clear_endline(title);
            DATAFRAME *new_dataframe = create_dataframe(title);
            if (all_dataframes_TL < 10) {
                all_dataframes_TL += 1;
                all_dataframes[all_dataframes_TL - 1] = new_dataframe;
                if (dataframe == &no_data){
                    dataframe = new_dataframe;
                    printf("Vous travaillez maintenant dans le dataframe : %s\n", dataframe->title);
                }
            } else {
                printf("Vous ne pouvez pas rajouter de dataframe car vous ne pouvez creer q'un maximum de 10 dataframe different\n");
            }

        }
        if (command[0] == 'c' && command[1] == 'h' && command[2] == 'a' && command[3] == 'n' && command[4] == 'g' &&
            command[5] == 'e' && command[6] == '_' && command[7] == 'd') {
            if (all_dataframes_TL == 0) {
                printf("Vous n'avez cree aucun dataframe.\n");
            } else {
                printf("Quel dataframe voulez-vous utiliser ?");
                for (i = 0; i < all_dataframes_TL; i++) {
                    printf("\n%d.%s", i + 1, all_dataframes[i]->title);
                }
                scanf(" %d", &number);
                dataframe = all_dataframes[number - 1];
                scanf("%c", &empty_buffer);
            }
        }
        if (command[0] == 'a' && command[1] == 'd' && command[2] == 'd' && command[3] == '_' && command[4] == 'c') {
            if (dataframe == &no_data) {
                printf("Vous ne travaillez actuellement dans aucun dataframe, entrez 'change_d' pour choisir votre dataframe, ou 'new_d' pour en creer un nouveau.\n");
            } else {
                printf("Entrez un titre pour la nouvelle colonne : \n");
                fgets(title, 100, stdin);
                clear_endline(title);
                add_column(dataframe, create_column(title));
            }

        }
        if (command[0] == 'a' && command[1] == 'd' && command[2] == 'd' && command[3] == '_' && command[4] == 'l') {
            if (dataframe == &no_data) {
                printf("Vous ne travaillez actuellement dans aucun dataframe, entrez 'change_d' pour choisir votre dataframe, ou 'new_d' pour en creer un nouveau.\n");
            } else {
                if (dataframe->TL == 0){
                    printf("Le dataframe ne comporte pas de colonne, veuillez rajoutez au moins une colonne avant  de rajouter des lignes.");
                }else{
                    add_ligne_data(dataframe);
                    scanf("%c", &empty_buffer);
                }
            }


        }
        if (command[0] == 'm' && command[1] == 'o' && command[2] == 'd' && command[3] == 'i' && command[4] == 'f') {
            if (dataframe == &no_data) {
                printf("Vous ne travaillez actuellement dans aucun dataframe, entrez 'change_d' pour choisir votre dataframe, ou 'new_d' pour en creer un nouveau.\n");
            } else {
                printf("Quelle colonne veux-tu modifier (numero commencant par 1)?");
                scanf("%d", &colonne);
                printf("Quelle ligne veux-tu modifier (numero commencant par 1)?");
                scanf("%d", &ligne);
                printf("Quelle valeur veux-tu mettre dans cette case?");
                scanf("%d", &number);
                change_value_dataframe(dataframe, ligne, colonne, number);
                scanf("%c", &empty_buffer);
            }

        }
        if (command[0] == 'a' && command[1] == 'd' && command[2] == 'd' && command[3] == '_' && command[4] == 'v') {
            if (dataframe == &no_data) {
                printf("Vous ne travaillez actuellement dans aucun dataframe, entrez 'change_d' pour choisir votre dataframe, ou 'new_d' pour en creer un nouveau.\n");
            } else {
                printf("Dans quelle colonne voulez-vous ajouter une valeur (numero commencant par 1)?");
                scanf("%d", &colonne);
                if (colonne > dataframe->TL) {
                    printf("Cette colonne n'existe pas.");
                }else{
                    printf("Quelle valeur voulez-vous ajouter?");
                    scanf("%d", &number);
                    insert_value_data(dataframe, colonne, number);
                }
                scanf("%c", &empty_buffer);
            }

        }
        if (command[0] == 'a' && command[1] == 'n' && command[2] == 'a' && command[3] == 'l' && command[4] == 'y' && command[5] == 's' && command[6] == 'e') {
            if (dataframe == &no_data) {
                printf("Vous ne travaillez actuellement dans aucun dataframe, entrez 'change_d' pour choisir votre dataframe, ou 'new_d' pour en creer un nouveau.\n");
            } else {
                printf("Quelle analyse voulez vous faire :\n_'i' pour regarder si une valeur est présente dans le dataframe\n");
                printf("_'=' pour regarder le nombre de fois qu'une valeur est presente dans le dataframe\n");
                printf("_'<' pour regarder le nombre de valeurs inferieur a une certaine valeur dans le dataframe\n");
                printf("_'>' pour regarder le nombre de valeurs superieur a une certaine valeur dans le dataframe\n");
                scanf(" %c", &analyse_tool);
                if (analyse_tool == 'i') {
                    printf("Choisissez une valeur :");
                    scanf(" %d", &number);
                    is_in_dataframe(dataframe, number);
                } else {
                    if (analyse_tool == '=') {
                        printf("Choisissez une valeur :");
                        scanf(" %d", &number);
                        printf("Cette valeur est presente %d fois dans le dataframe\n",
                               nb_value_equal(dataframe, number));
                    } else {
                        if (analyse_tool == '<') {
                            printf("Choisissez une valeur :");
                            scanf(" %d", &number);
                            printf("Il y a %d valeurs inferieur a cette valeur dans le dataframe.\n",
                                   nb_value_under(dataframe, number));
                        } else {
                            if (analyse_tool == '>') {
                                printf("Choisissez une valeur :");
                                scanf(" %d", &number);
                                printf("Il y a %d valeurs superieur a cette valeur dans le dataframe.\n",
                                       nb_value_over(dataframe, number));
                            } else {
                                printf("Cette commande n'est pas valable.\n");
                            }
                        }
                    }
                }
            }
            scanf("%c", &empty_buffer);
        }
        if (command[0] == 's' && command[1] == 'u' && command[2] == 'p' && command[3] == 'p' && command[4] == '_' && command[5] == 'l') {
            if (dataframe == &no_data) {
                printf("Vous ne travaillez actuellement dans aucun dataframe, entrez 'change_d' pour choisir votre dataframe, ou 'new_d' pour en creer un nouveau.\n");
            } else {
                printf("Quelle ligne voulez-vous supprimer?\n");
                scanf(" %d", &number);
                del_columns_data(dataframe, number);
                scanf("%c", &empty_buffer);
            }

        }
        if (command[0] == 's' && command[1] == 'u' && command[2] == 'p' && command[3] == 'p' && command[4] == '_' && command[5] == 'd') {
            if (dataframe == &no_data) {
                printf("Vous ne travaillez actuellement dans aucun dataframe, entrez 'change_d' pour choisir votre dataframe, ou 'new_d' pour en creer un nouveau.\n");
            } else {
                del_dataframe(dataframe);
                dataframe = &no_data;
                printf("Le dataframe a ete supprime.\n");
            }

        }
    }
    for(i=0; i<all_dataframes_TL; i++){
        del_dataframe(all_dataframes[i]);
    }
    return 0;


}

