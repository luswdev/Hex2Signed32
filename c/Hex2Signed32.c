/**
 * @file        hex2signed.c
 * @author      LuSkywalker (info@lusw.dev)
 * @brief       Turn input hex string into dec signed integer.
 * @version     1.1.1
 * @date        2020-08-19
 * 
 * @copyright   Copyright (c) 2020 LuSkywalker
 * 
 */

#include "hex2signed.h"

/**
 * @brief   Check input string is hex value or not.
 * 
 * @param   in      input string to check
 * @return  -1      is a hex value
 * @return  index   where the error occurs
 */
int check_input_valid(char in[])
{
    for (int i=0; in[i]; ++i) {
        if (hex_to_int(in[i]) == -1) {
            return i;
   
        }
    }

    return -1;
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

/**
 * @brief   print description words.
 * 
 * @param   file    file name which is currently executing.
 */
void print_description(char file[], char from[])
{
    system("cls");
    printf("%s (v%s) compiled with %s from %s\n", file, VERSION, __FILE__, from);
    printf("Transform hex value into signed integer.\n");
    printf("Accept character set: [A-F, a-f, 0-9]\n");

#ifdef HACKED
    printf("Flag: HACKED\n");
#endif

    printf("Press CTRL+C to exit.\n");
}
