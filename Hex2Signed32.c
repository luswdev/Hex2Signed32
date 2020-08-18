/**
 * @file        hex2signed.c
 * @author      LuSkywalker (info@lusw.dev)
 * @brief       Turn input hex string into dec signed integer.
 * @version     1.1
 * @date        2020-08-18
 * 
 * @copyright   Copyright (c) 2020 LuSkywalker
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "hex2signed.h"

/**
 * @brief   Main function.
 * 
 * @return  int  always return 0;
 */
int main(void)
{
    char in[100] = "";

    printf("Input a hex value: 0x");
    while (fscanf( stdin,"%s", in)) {

        if (!check_input_valid(in)) {
            printf("Error: Input format invaild!\n");
            goto failed;
        }

        if (strlen(in) > 8) {
            printf("Error: Out of Range!\n");
            goto failed;
        }

        printf("Result: %d\n", hex_to_value(in));

    failed: 
        printf("\nInput a hex value: 0x");
    }

    return 0;
}

/**
 * @brief   Check input string is hex value or not.
 * 
 * @param   in      input string to check
 * @return  true    is a hex value
 * @return  false   is NOT a hex value
 */
bool check_input_valid(char in[])
{
    for (int i=0; in[i]; ++i) {
        if (hex_to_int(in[i]) == -1) {
            return false;
        }
    }

    return true;
}

#ifdef HAKCED
/**
 * @brief   Turn a vaild hex string into signed integer, using
 *          casting unsigned into signed. 
 * 
 * @param   in      input hex string
 * @return  int     signed integer after transform
 */
int hex_to_value(char in[])
{
    unsigned int res = 0;    /* use uint to avoid overflow */
    int start = 0;

    /* hex -> dec */
    for (start; in[start]; ++start) {
        res *= 16;
        res += hex_to_int(in[start]);
    }

    return (int) res;       /* unsigned casting to signed */
}
# else
/**
 * @brief   Turn a vaild hex string into signed integer, using
 *          2's complement.
 * 
 * @param   in      input hex string
 * @return  int     signed integer after transform
 */
int hex_to_value(char in[])
{
    int res = 0;
    int start = 0;
    bool sign = true;

    int first_val = hex_to_int(in[start]);
    if (strlen(in) == 8 && first_val != -1) {
        if (first_val >= 8) {           
            first_val -= 8;
            sign = false;       /* negetive number */
        }                      
            
        res *= 16;
        res += first_val;
        ++start;                /* move on to next character */
    }

    /* hex -> dec */
    for (start; in[start]; ++start) {
        res *= 16;
        res += hex_to_int(in[start]);
    }

    return (sign) ? res : (res - INT_MAX - 1);      /* 2147483648 - res */
}
#endif

/**
 * @brief   Turn a character into numeral.
 * 
 * @param   c       character to transform
 * @return  int     numeral for input character
 * @return  -1      input format invaild
 */
int hex_to_int(char c)
{
    if ((c>='A') && (c<='F')) {             /* ABCDEF */
        return c - 'A' + 10;
    } else if ((c>='a') && (c<='f')) {      /* abcdef */
        return c - 'a' + 10;
    } else if ((c>='0') && (c<='9')) {      /* 0123456789 */
        return c - '0';
    }

    return -1;      /* return -1 for wrong input */
}
