/**
 * @file        Hex2Signed32.h
 * @author      LuSkywalker (info@lusw.dev)
 * @brief       hex2signed.c define header file.
 * @version     1.1
 * @date        2020-08-18
 * 
 * @copyright   Copyright (c) 2020 LuSkywalker
 * 
 */

#ifndef __HEX2SIGNED32_H__
#define __HEX2SIGNED32_H__

/*!< signed integer max for 32-bit */
#define INT_MAX 2147483647

bool check_input_valid(char in[]);
int hex_to_value(char in[]);
int hex_to_int(char c);

#endif /* __HEX2SIGNED32_H__ */
