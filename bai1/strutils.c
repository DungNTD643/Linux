#include "strutils.h"

void str_reverse(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char tmp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = tmp;
    }
}

void str_trim(char *str) {
    char *start = str;
    while (isspace((unsigned char)*start)) start++;

    char *end = str + strlen(str) - 1;
    while (end > start && isspace((unsigned char)*end)) end--;
    *(end + 1) = '\0';

    if (start != str) {
        memmove(str, start, end - start + 2); // +1 for null, +1 more for range
    }
}

int str_to_int(const char *str, int *out_num) {
    if (str == NULL || out_num == NULL) return 0;

    while (isspace((unsigned char)*str)) str++;  // B? qua kho?ng tr?ng d?u chu?i

    char *endptr;
    long val = strtol(str, &endptr, 10);

    if (*str == '\0' || *endptr != '\0') return 0; // L?i n?u không ph?i toàn s?

    *out_num = (int)val;
    return 1;
}