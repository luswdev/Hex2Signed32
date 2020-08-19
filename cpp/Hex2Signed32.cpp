/**
 * @file        hex2signed.cpp
 * @author      LuSkywalker (info@lusw.dev)
 * @brief       Turn input hex string into dec signed integer.
 * @version     1.0
 * @date        2020-08-18
 * 
 * @copyright   Copyright (c) 2020 LuSkywalker
 * 
 */

#include "hex2signed.h"

/**
 * @brief Construct a new Hex 2 Signed:: Hex 2 Signed object
 * 
 */
Hex2Signed::Hex2Signed(void) 
{
    res_flush();
    input_flush();
}

/**
 * @brief   Get input with cin.
 * 
 * @return  true    cin OK
 * @return  false   cin ERROR
 */
bool Hex2Signed::get_input(void)
{
    input_flush();

    if (std::cin >> in) {
        return true;
    }

    return false;
}

/**
 * @brief   Get a copy of private value, a character of Hex2Signed::in. 
 * 
 * @param   idx     index where should copy
 * @return  char    copied value
 */
char Hex2Signed::get_input(int idx)
{
    if (get_input_len() < idx - 1) {
        return -1;
    }

    return in[idx];
}

/**
 * @brief   Get a full copy of private value: Hex2Signed::in.
 * 
* @param   buf     copy location buffer
 */
void Hex2Signed::get_input(char buf[]) {
    strcpy(buf, in);
}

/**
 * @brief   Get Hex2Signed::in length.
 * 
 * @return  int     length
 */
int Hex2Signed::get_input_len(void)
{
    return strlen(in);
}

/**
 * @brief   Check input string is hex value or not.
 * 
 * @return  -1      is a hex value
 * @return  index   where the error occurs
 */
int Hex2Signed::check_input_valid(void)
{
    for (int i=0; in[i]; ++i) {
        if (hex_to_int(i) == -1) {
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
 * @return  int     signed integer after transform
 */
int Hex2Signed::hex_to_value(void)
{
    res_flush();

    int start = 0;

    /* hex -> dec */
    for (start; in[start]; ++start) {
        res *= 16;
        res += hex_to_int(start);
    }

    return (int) res;       /* unsigned casting to signed */
}
# else
/**
 * @brief   Turn a vaild hex string into signed integer, using
 *          2's complement.
 * 
 * @return  int     signed integer after transform
 */
int Hex2Signed::hex_to_value(void)
{
    res_flush();

    int start = 0;
    bool sign = true;

    int first_val = hex_to_int(start);
    if (get_input_len() == 8 && first_val != -1) {
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
        res += hex_to_int(start);
    }

    return (sign) ? (int) res : (int) (res - INT_MAX - 1);      /* 2147483648 - res */
}
#endif

/**
 * @brief Reset result buffer.
 * 
 */
void Hex2Signed::res_flush(void)
{
    res = 0;
}

/**
 * @brief Reset input buffer.
 * 
 */
void Hex2Signed::input_flush(void)
{
    strcpy(in, "\0");
}

/**
 * @brief   Turn a character into numeral.
 * 
 * @param   idx     character index for "Hex2Signed::in" to transform
 * @return  int     numeral for input character
 * @return  -1      input format invaild
 */
int Hex2Signed::hex_to_int(int idx)
{
    char c = in[idx];

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
 * @brief   Print description words.
 * 
 * @param   file    file name which is currently executing.
 */
void print_description(char file[], std::string from)
{
    clear_screen();

    std::cout << file << " (v" << VERSION << ") compiled with " << __FILE__ << " from " << from << std::endl;
    std::cout << "Transform hex value into signed integer." << std::endl;
    std::cout << "Accept character set: [A-F, a-f, 0-9]" << std::endl;

#ifdef HACKED
    std::cout << "Flag: HACKED" << std::endl;
#endif

    std::cout << "Press CTRL+C to exit." << std::endl;
}
