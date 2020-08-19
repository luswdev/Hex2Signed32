/**
 * @file        cpp/main.cpp
 * @author      LuSkywalker (info@lusw.dev)
 * @brief       Testing file of hex2signed.c
 * @version     1.0
 * @date        2020-08-18
 * 
 * @copyright   Copyright (c) 2020 LuSkywalker
 * 
 */

#include "main.h"

using namespace std;

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

    Hex2Signed sol;

    printf("\nInput a hex value: \t\t0x");
    while (sol.get_input()) {

        if (sol.check_input_valid() >= 0) {
            int idx = sol.check_input_valid();
            cout << "ERROR: Input format invaild, First occurs in index: " << idx << ", value: " << sol.get_input(idx) << endl;
            goto passing;
        }

        if (sol.get_input_len() > 8) {
            cout << "ERROR: Out of Range, length = " << sol.get_input_len() << " (> 8)." << endl;
            goto passing;
        }

        char buf[10];
        sol.get_input(buf);
        cout << "Result for \"0x" << setw(8) << setfill('0') << buf << "\": \t" << ((sol.hex_to_value() < 0) ?"\b" : " \b") << sol.hex_to_value() << endl;

    passing: 
        cout << endl << "Input a hex value: \t\t0x";
    }

    return 0;
}
