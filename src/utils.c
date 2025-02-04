#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "../include/utils.h"

bool includes(int array[], int length, int value)
{
    for(int i = 0; i < length; i++) {
        if(array[i] == value) return true;
    }
    return false;
}

// Read at most `n` characters (newline included) into `str`.
// If present, the newline is removed (replaced by the null terminator).
// https://alexandra-zaharia.github.io/posts/how-to-rea-safely-from-stdin-in-c/
// fgets:
// The fgets() function reads at most one less than the
// number of characters specified by size from the given
// stream and stores them in the string str.  Reading stops
// when a newline character is found, at end-of-file or
// error.  The newline, if any, is retained.  If any
// characters are read and there is no error, a ‘\0’
// character is appended to end the string.
void s_gets(char str[], int n)
{
    char *str_read = fgets(str, n, stdin);
    if (!str_read)
        return;

    int i = 0;
    while (str[i] != '\n' && str[i] != '\0') {
        i++;
    }

    if (str[i] == '\n') {
        str[i] = '\0';
    }
}

void ints_from_string(char string[], int values[], int capacity)
{
    for(int i = 0; i < capacity; i++) {
        char *tail;
        int next;

        /* Skip whitespace by hand, to detect the end.  */
        while (isspace(*string)) string++;
        if (*string == 0)
            break;

        /* There is more nonwhitespace,  */
        /* so it ought to be another number.  */
        int errno = 0;
        /* Parse it.  */
        next = strtol(string, &tail, 0);
        /* Add it in, if not overflow.  */
        if (errno) {
            printf ("Overflow\n");
        } else {
            values[i] = next;
        }
        /* Advance past it.  */
        string = tail;
    }
}
