#ifndef CDATAFRAME_H
#define CDATAFRAME_H

#include "column.h"

/**
 * @brief Structure representing a dataframe.
 *
 * A dataframe is a structure containing a title, a total number of columns (TP),
 * a number of currently used columns (TL), and an array of pointers to the columns.
 */
typedef struct {
    char *title;
    int TP;
    int TL;
    COLUMN **columns;
} DATAFRAME;

/**
 * @brief Checks if a number is present in an array.
 *
 * This function iterates through an array of integers and checks if a specific number is present.
 *
 * @param nb The number to search for.
 * @param Tab The array of integers.
 * @param TL The length of the array.
 * @return The index of the number if found, -1 otherwise.
 */
int in(int nb, int *Tab, int TL);

/**
 * @brief Creates a new dataframe with a given title.
 *
 * This function allocates memory for a new dataframe structure and initializes its fields.
 *
 * @param title The title of the new dataframe.
 * @return A pointer to the new dataframe, or NULL if memory allocation fails.
 */
DATAFRAME *create_dataframe(char *title);

/**
 * @brief Adds a column to the dataframe.
 *
 * This function adds a new column to an existing dataframe. If the allocated space
 * for columns is insufficient, it is reallocated.
 *
 * @param data_frame The dataframe to which the column is to be added.
 * @param column The column to add.
 * @return 1 if the column is successfully added.
 */
int add_column(DATAFRAME *data_frame, COLUMN *column);

/**
 * @brief Finds the maximum length among all columns in the dataframe.
 *
 * This function iterates through all columns in the dataframe and returns the maximum length.
 *
 * @param dataframe The dataframe to examine.
 * @return The maximum length among all columns.
 */
int max_TL(DATAFRAME *dataframe);

/**
 * @brief Justifies a string to a fixed length.
 *
 * This function prints a string justified to a length of 11 characters.
 *
 * @param string The string to justify.
 */
void justifier(char* string);

/**
 * @brief Prints a number justified to a fixed length.
 *
 * This function prints an integer justified to a length of 10 characters.
 *
 * @param nb The number to print.
 */
void print_nb(int nb);

/**
 * @brief Prints a number with justification based on a maximum number.
 *
 * This function prints an integer justified based on the length of the maximum number.
 *
 * @param nb The number to print.
 * @param max_nb The maximum number for justification.
 */
void print_nb_col(int nb, int max_nb);

/**
 * @brief Prints the content of a dataframe.
 *
 * This function prints the titles and values of all columns in the dataframe.
 *
 * @param dataframe The dataframe to print.
 */
void print_dataframe(DATAFRAME *dataframe);

/**
 * @brief Prints a range of rows from the dataframe.
 *
 * This function prints the values of the columns for the specified rows of the dataframe.
 *
 * @param dataframe The dataframe to print.
 * @param l_deb The first row to print.
 * @param l_fin The last row to print.
 */
void lignes_dataframe(DATAFRAME *dataframe, int l_deb, int l_fin);

/**
 * @brief Prints certain columns from the dataframe.
 *
 * This function prints the values of the columns specified by a list.
 *
 * @param dataframe The dataframe to print.
 * @param liste_c The list of columns to print.
 * @param TL The length of the list of columns.
 */
void colonne_dataframe(DATAFRAME *dataframe, int *liste_c, int TL);

/**
 * @brief Adds a row of values to the dataframe.
 *
 * This function prompts the user to input values for each column and adds them as a new row in the dataframe.
 *
 * @param dataframe The dataframe to add the row to.
 */
void add_ligne_data(DATAFRAME *dataframe);

/**
 * @brief Deletes a row from the dataframe.
 *
 * This function deletes a specified row from the dataframe.
 *
 * @param dataframe The dataframe to delete the row from.
 * @param ligne The row to delete.
 */
void del_ligne_data(DATAFRAME *dataframe, int ligne);

/**
 * @brief Deletes a column from the dataframe.
 *
 * This function deletes a specified column from the dataframe.
 *
 * @param dataframe The dataframe to delete the column from.
 * @param nb_col The column to delete.
 */
void del_columns_data(DATAFRAME *dataframe, int nb_col);

/**
 * @brief Deletes the entire dataframe.
 *
 * This function frees all memory allocated for the dataframe.
 *
 * @param dataframe The dataframe to delete.
 */
void del_dataframe(DATAFRAME *dataframe);

/**
 * @brief Renames a column in the dataframe.
 *
 * This function renames a specified column in the dataframe.
 *
 * @param dataframe The dataframe containing the column.
 * @param nb_col The column to rename.
 * @param new_title The new title for the column.
 */
void rename_col_data(DATAFRAME *dataframe, int nb_col, char *new_title);

/**
 * @brief Checks if a value is present in the dataframe.
 *
 * This function searches for a specified value in the dataframe and prints its location if found.
 *
 * @param dataframe The dataframe to search.
 * @param val The value to search for.
 * @return 1 if the value is found, -1 otherwise.
 */
int is_in_dataframe(DATAFRAME *dataframe, int val);

/**
 * @brief Changes a value in the dataframe.
 *
 * This function changes a specified value in the dataframe.
 *
 * @param dataframe The dataframe containing the value.
 * @param ligne The row of the value to change.
 * @param colonne The column of the value to change.
 * @param new_val The new value.
 */
void change_value_dataframe(DATAFRAME *dataframe, int ligne, int colonne, int new_val);

/**
 * @brief Prints the titles of the columns in the dataframe.
 *
 * This function prints the titles of all columns in the dataframe.
 *
 * @param dataframe The dataframe to print the column titles from.
 */
void print_titles_data(DATAFRAME *dataframe);

/**
 * @brief Prints the number of rows in the dataframe.
 *
 * This function prints the number of rows in the dataframe.
 *
 * @param dataframe The dataframe to count the rows of.
 */
void nb_lignes_data(DATAFRAME *dataframe);

/**
 * @brief Prints the number of columns in the dataframe.
 *
 * This function prints the number of columns in the dataframe.
 *
 * @param dataframe The dataframe to count the columns of.
 */
void nb_colonnes_data(DATAFRAME *dataframe);

/**
 * @brief Counts the number of values equal to a specified value in the dataframe.
 *
 * This function counts the number of occurrences of a specified value in the dataframe.
 *
 * @param dataframe The dataframe to search.
 * @param val The value to count.
 * @return The number of occurrences of the value.
 */
int nb_value_equal(DATAFRAME *dataframe, int val);

/**
 * @brief Counts the number of values greater than a specified value in the dataframe.
 *
 * This function counts the number of values greater than a specified value in the dataframe.
 *
 * @param dataframe The dataframe to search.
 * @param val The value to compare against.
 * @return The number of values greater than the specified value.
 */
int nb_value_over(DATAFRAME *dataframe, int val);

/**
 * @brief Counts the number of values less than a specified value in the dataframe.
 *
 * This function counts the number of values less than a specified value in the dataframe.
 *
 * @param dataframe The dataframe to search.
 * @param val The value to compare against.
 * @return The number of values less than the specified value.
 */
int nb_value_under(DATAFRAME *dataframe, int val);

/**
 * @brief Inserts a value into a specific column in the dataframe.
 *
 * This function inserts a specified value into a specified column in the dataframe.
 *
 * @param dataframe The dataframe to insert the value into.
 * @param col The column to insert the value into.
 * @param val The value to insert.
 */
void insert_value_data(DATAFRAME *dataframe, int col, int val);

#endif // CDATAFRAME_H
