/**
 * @file        c/main.c
 * @author      LuSkywalker (info@lusw.dev)
 * @brief       Testing file of hex2signed.c
 * @version     1.1
 * @date        2020-08-18
 * 
 * @copyright   Copyright (c) 2020 LuSkywalker
 * 
 */

#include "hex2signed.h"
#include "main.h"

/**
 * @brief   Main function
 * 
 * @param   argc    input arguments count
 * @param   argv    input arguments value array
 * @return  0       exited without error
 */
int main(int argc, char* argv[])
{
    print_description(argv[0], __FILE__);

    char in[100] = "";

    printf("\nInput a hex value: \t\t0x");
    while (scanf("%s", in) != EOF) {

        if (check_input_valid(in) >= 0) {
            int idx = check_input_valid(in);
            printf("ERROR: Input format invaild, First occurs in index: %d, value: %c\n", idx, in[idx]);
            goto passing;
        }

        if (strlen(in) > 8) {
            printf("ERROR: Out of Range, length = %d (> 8).\n", strlen(in));
            goto passing;
        }

        printf("Result for \"0x%08s\": \t%s%d\n", in, (hex_to_value(in) < 0) ? "\b" : " \b",hex_to_value(in));

    passing: 
        printf("\nInput a hex value: \t\t0x");
        strcpy(in, "\0");
    }

    return 0;
}
