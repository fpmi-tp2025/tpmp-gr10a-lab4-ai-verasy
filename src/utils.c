#include "utils.h"
#include <stdio.h>
#include <ctype.h>

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int is_numeric(const char *str) {
    while (*str) {
        if (!isdigit(*str)) return 0;
        str++;
    }
    return 1;
}

void print_menu_header(const char *title) {
    printf("\n=== %s ===\n", title);
}
