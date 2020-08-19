/**
 * @file        hex2signed.h
 * @author      LuSkywalker (info@lusw.dev)
 * @brief       hex2signed.c define header file.
 * @version     1.1
 * @date        2020-08-18
 * 
 * @copyright   Copyright (c) 2020 LuSkywalker
 * 
 */

#ifndef __HEX2SIGN_H__
#define __HEX2SIGN_H__

#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define VERSION         "1.1.4"

/*!< signed integer max for 32-bit */
#define INT_MAX         2147483647

/*!< print description word */
void print_description(char file[], char from[]);

int check_input_valid(char in[]);
int hex_to_value(char in[]);
int hex_to_int(char c);

#endif /* __HEX2SIGN_H__ */
