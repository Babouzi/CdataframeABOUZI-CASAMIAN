
#ifndef COLUMN_H
#define COLUMN_H
typedef struct COLUMN{
    char *title;
    int TP;
    int TL;
    int *data;
}COLUMN;

enum enum_type
{
    NULLVAL = 1 , UINT, INT, CHAR, FLOAT, DOUBLE, STRING, STRUCTURE
};
typedef enum enum_type ENUM_TYPE;

union column_type{
    unsigned int uint_value;
    signed int int_value;
    char char_value;
    float float_value;
    double double_value;
    char* string_value;
    void* struct_value;
};
typedef union column_type COL_TYPE ;

COLUMN *create_column(char* title);

/**
 * @brief Inserts a value into the specified column.
 * @param col The column to insert the value into.
 * @param value The value to insert.
 * @return 1 if the value is successfully inserted, 0 otherwise.
 */
int insert_value(COLUMN* col, int value);

/**
 * @brief Deletes a column and frees its memory.
 * @param col A pointer to the column to delete.
 */
void delete_column(COLUMN **col);

/**
 * @brief displays the content of a column
 * @param col The column to print.
 */
void print_col(COLUMN* col);

/**
 * @brief Counts the occurrences of a specific value in the column.
 * If the column is NULL or empty, it returns 0.
 * @param col The column to search in.
 * @param x The value to count occurrences of.
 * @return The number of occurrences of the value.
 */
int count_occurrences(COLUMN* col, int x);

/**
 * @brief Retrieves the value stored at a specific position in the column.
 * If the column is NULL, empty, or the position is out of range, it returns -1.
 * @param col The column to retrieve the value from.
 * @param position The position of the value to retrieve.
 * @return The value at the specified position.
 */
int get_value_at_position(COLUMN* col, int position);

/**
 * @brief Counts the number of values bigger than a specified value in the column.
 * @param col The column to count values in.
 * @param x The value to compare against.
 * @return The number of values bigger than the specified value.
 */
int count_values_greater_than(COLUMN* col, int x);

/**
 * @brief Counts the number of values less than a specified value in the column.
 * @param col The column to count values in.
 * @param x The value to compare against.
 * @return The number of values less than the specified value.
 */
int count_values_less_than(COLUMN* col, int x);

/**
 * @brief Counts the number of values equal to a specified value in the column.
 * @param col The column to count values in.
 * @param x The value to compare against.
 * @return The number of values equal to the specified value.
 */
int count_values_equal_to(COLUMN* col, int x);



#endif //COLUMN_H
