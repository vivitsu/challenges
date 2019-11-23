/*
 * https://www.reddit.com/r/dailyprogrammer/comments/7r17qr/20180117_challenge_347_intermediate_linear/
 *
 */

// TODO - Handle 32bit input

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct input {
    uint32_t num_taps;
    uint32_t* tap_locations;
    uint32_t feedback_fn; // XOR (0) or XNOR (1)
    char* val_str;
    uint32_t cycles;
} input;

uint32_t get_num_taps(char* tap_loc_str, int len)
{
    uint32_t num_taps = 0;
    // Skip the opening and closing brackets
    for (int i = 1; i <= len - 2; i++)
    {
        if (tap_loc_str[i] == ',')
        {
            num_taps++;
        }
    }
    num_taps++;
    printf("Num tap locations: %d\n", num_taps);
    return num_taps;
}

uint32_t* get_tap_locations(char* tap_loc_str, int len, uint32_t num_taps)
{
    uint32_t* tap_locations = (uint32_t*)malloc(sizeof(uint32_t)*num_taps);
    int k = 0;
    for (int i = 1; i <= len - 2; i++)
    {
        if (tap_loc_str[i] == ',')
        {
            continue;
        }
        else
        {
            tap_locations[k] = tap_loc_str[i] - '0';
            k++;
        }
    }
    return tap_locations;
}

void run_lfsr(input* in)
{
    for (int i = 0; i < in->cycles + 1; i++)
    {
        printf("%d: %s\n", i, in->val_str);
        uint32_t tap = in->tap_locations[0];
        uint32_t curr_lf = in->val_str[tap] - '0';
        for (int j = 1; j < in->num_taps; j++)
        {
            tap = in->tap_locations[j];
            curr_lf ^=  in->val_str[tap] - '0';
            if (in->feedback_fn)
            {
                curr_lf = !(curr_lf);
            }
        }

        for (int k = strlen(in->val_str) - 1; k >= 1; k--)
        {
            in->val_str[k] = in->val_str[k-1];
        }
        in->val_str[0] = curr_lf + '0';
    }
}

input* parse_args(char** argv)
{
    input* in = (input*)malloc(sizeof(input)*1);
    char* tap_loc_str = argv[1];
    int len = strlen(argv[1]);
    in->num_taps = get_num_taps(tap_loc_str, len);
    in->tap_locations = get_tap_locations(tap_loc_str, len, in->num_taps);

    printf("Tap Locations: %s\n", argv[1]);
    printf("Parsed tap locations: %d", in->tap_locations[0]);
    for (int i = 1; i < in->num_taps; i++)
    {
        printf(",%d", in->tap_locations[i]);
    }
    printf("\n");
    in->feedback_fn = strcmp(argv[2], "XOR") == 0 ? 0 : 1;
    printf("Feedback Function: %s\n", (in->feedback_fn == 0 ? "XOR" : "XNOR"));
    char* val_str = (char*)malloc(sizeof(char)*strlen(argv[3]));
    in->val_str = argv[3];
    printf("Initial Value: %s\n", in->val_str);
    in->cycles = atoi(argv[4]);
    printf("Cycles: %d\n", in->cycles);
    return in;
}

int main(int argc, char** argv)
{
    if (argc < 5)
    {
        printf("Insufficient Arguments. Expected 4, got %d.\n", argc);
        exit(-1);
    }
    else if (argc > 5)
    {
        printf("Too many arguments. Expected 4, got %d\n", argc);
        exit(-1);
    }
    else {
        input* in = parse_args(argv);
        run_lfsr(in);
        free(in);
    }
    return 0;
}
