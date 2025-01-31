#include <stdbool.h>
#include "../include/utils.h"

bool includes(int array[], int length, int value)
{
        for(int i = 0; i < length; i++) {
                if(array[i] == value) return true;
        }
        return false;
}
