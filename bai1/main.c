#include "stdio.h"
#include "strutils.h"
int main() {
    char str1[] = "hello";
    str_reverse(str1);
    printf("Reversed: %s\n", str1); // olleh

    char str2[] = "   test string   ";
    str_trim(str2);
    printf("Trimmed: '%s'\n", str2); // 'test string'

    int num;
    if (str_to_int("12345", &num)) {
        printf("Parsed number: %d\n", num); // 12345
    } else {
        printf("Invalid number\n");
    }

    return 0;
}