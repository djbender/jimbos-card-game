#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "../include/utils.h"

Test(includes, a_value) {
    int arr[1];
    int length = 1;
    int value = 10;
    arr[0] = value;

    bool rval = includes(arr, length, value);
    cr_assert(rval);
}

Test(includes, a_value_in_a_larger_array) {
    int value = 10;
    int arr[] = { 1, 2, 3, value, 5 };
    int length = 5;

    bool rval = includes(arr, length, value);
    cr_assert(rval);
}

Test(includes, is_false_when_not_present) {
    int value = 10;
    int arr[] = { 1, 2, 3, 4, 5 };
    int length = 5;

    bool rval = includes(arr, length, value);
    cr_assert(rval == false);
}

Test(includes, accepts_empty_array) {
    int value = 10;
    int *arr = NULL;
    int length = 0;

    bool rval = includes(arr, length, value);
    cr_assert(rval == false);
}

Test(includes, accepts_empty_array_with_mismatched_length) {
    int value = 42;
    int *arr = NULL;
    int length = 1;

    bool rval = includes(arr, length, value);
    cr_assert(rval == false);
}

Test(ints_from_string, a_single_int) {
    int capacity = 1;
    char input[] = "1";
    int rval[capacity];

    ints_from_string(input, rval, capacity);
    cr_assert(rval[0] == 1);
}

Test(ints_from_string, two_ints) {
    int capacity = 2;
    char input[] = "1 2";
    int rval[capacity];

    ints_from_string(input, rval, capacity);
    cr_assert(rval[0] == 1);
    cr_assert(rval[1] == 2);
}

Test(ints_from_string, multi_digit_ints) {
    int capacity = 3;
    char input[] = "1 20 300";
    int rval[capacity];

    ints_from_string(input, rval, capacity);
    cr_assert(rval[0] == 1);
    cr_assert(rval[1] == 20);
    cr_assert(rval[2] == 300);
}
