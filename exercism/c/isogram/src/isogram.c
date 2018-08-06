#include "isogram.h"

char to_lower(char c) {
    switch(c) {
        case 'A':
            return 'a';
        case 'B':
            return 'b';
        case 'C':
            return 'c';
        case 'D':
            return 'd';
        case 'E':
            return 'e';
        case 'F':
            return 'f';
        case 'G':
            return 'g';
        case 'H':
            return 'h';
        case 'I':
            return 'i';
        case 'J':
            return 'j';
        case 'K':
            return 'k';
        case 'L':
            return 'l';
        case 'M':
            return 'm';
        case 'N':
            return 'n';
        case 'O':
            return 'o';
        case 'P':
            return 'p';
        case 'Q':
            return 'q';
        case 'R':
            return 'r';
        case 'S':
            return 's';
        case 'T':
            return 't';
        case 'U':
            return 'u';
        case 'V':
            return 'v';
        case 'W':
            return 'w';
        case 'X':
            return 'x';
        case 'Y':
            return 'y';
        case 'Z':
            return 'z';
        default:
            return c;
    }
}

bool is_isogram(const char phrase[]) {

    int count_char[128];

    for (int j = 0; j < 128; j++) {
        count_char[j] = 0;
    }

    for (int i = 0; phrase[i] != '\0'; i++) {
        int c = to_lower(phrase[i]);        

        if (c >= 97 && c <= 122) {
            if (count_char[c] != 0) return false;
            count_char[c]++;
        }
    }
    return true;
}
