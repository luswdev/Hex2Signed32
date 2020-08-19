/**
 * @file        cpp/Hex2Signed32.h
 * @author      LuSkywalker (info@lusw.dev)
 * @brief       hex2signed.c define header file.
 * @version     1.0
 * @date        2020-08-18
 * 
 * @copyright   Copyright (c) 2020 LuSkywalker
 * 
 */

#ifndef __CPP_HEX2SIGN_H__
#define __CPP_HEX2SIGN_H__

#ifdef __MINGW32__
#include <windows.h>
#endif

#include <iostream>
#include <string>

#ifdef __MINGW32__
#define clear_screen()      system("cls");
#elif __GNUC__
#define clear_screen()      printf("\e[1;1H\e[2J");    
#else
#define clear_screen()      {}
#endif

#define VERSION         "1.0"

/*!< signed integer max for 32-bit */
#define INT_MAX         2147483647

/*!< print description word */
void print_description(char file[], std::string from);

/**
 * @brief Hex2Signed solution class.
 * 
 */
class Hex2Signed {
private:
    unsigned int res;
    char in[100];

    int hex_to_int(int idx);
    void res_flush(void);
    void input_flush(void);
    
public:
    Hex2Signed(void);

    bool get_input(void);
    char get_input(int idx);
    void get_input(char buf[]);
    int get_input_len(void);
    int check_input_valid(void);
    int hex_to_value(void);
};

#endif /* __CPP_HEX2SIGN_H__ */
