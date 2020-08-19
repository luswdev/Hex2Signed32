/**
 * @file        c/Hex2Signed32.h
 * @author      LuSkywalker (info@lusw.dev)
 * @brief       hex2signed.c define header file.
 * @version     1.1
 * @date        2020-08-18
 * 
 * @copyright   Copyright (c) 2020 LuSkywalker
 * 
 */

#ifndef __C_HEX2SIGN_H__
#define __C_HEX2SIGN_H__

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef __MINGW32__
#include <windows.h>
#endif

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#ifdef __MINGW32__
#define clear_screen()      system("cls");
#elif __GNUC__
#define clear_screen()      printf("\e[1;1H\e[2J");    
#else
#define clear_screen()      {}
#endif

#define VERSION         "1.1.4"

/*!< signed integer max for 32-bit */
#define INT_MAX         2147483647

/*!< print description word */
void print_description(char file[], char from[]);

int check_input_valid(char in[]);
int hex_to_value(char in[]);
int hex_to_int(char c);
  
#ifdef __cplusplus
}
#endif

#endif /* __C_HEX2SIGN_H__ */
