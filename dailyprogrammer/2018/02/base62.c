// https://www.reddit.com/r/dailyprogrammer/comments/7yyt8e/20180220_challenge_352_easy_making_imgurstyle/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char * str)
{
    int len = strlen(str);

    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}

char* base62_convert(int input, char *output)
{
    int rem = 0, quot = 0, i;

    char BASE62_ALPHABET[62] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    for (i = 0; input > 62; i++)
    {
        rem = input % 62;
        output[i] = BASE62_ALPHABET[rem];
        input = input / 62;
    }

    output[i++] = BASE62_ALPHABET[input];
    output[i] = '\0';
    
    reverse(output);
    return output;
}

int main(int argc, char **argv) 
{
    // TODO: Handle ints larger than the range - Use long long?
    for (int count = 1; count < argc; count++)
    {
        int in = atoi(argv[count]);
        char output[62];
        char *out = base62_convert(in, output);
        printf("%s\n", out);
    }
}
