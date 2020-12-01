#include "pch.h"
#include "Calculator.h"
#include <stdio.h>

int Calculator::Add(std::string expression)
{
    return -4; //реализации не будет
}

int Calculator::Add(char* expression)
{
    num_arg=0;
    memset(arg_mass, 0x00, sizeof(arg_mass));
    char cur_symb = 0x00;
    char* pos = expression;
    unsigned long number_detected = 0;
    int res = 0;
    if (!pos) return 0; //пустая строка возвращает 0
    if (!*pos) return 0; //пустая строка возвращает 0
    while (*pos) {
        if ((expression - pos) > MAX_SIZE_OF_INPUT_STRING) return -1;
        if (*pos == '-') return -2;
        if (isdigit(*pos)) {
            if (number_detected) return -2;
            number_detected = 1;
            strncpy_s(arg_mass[num_arg], pos, MAX_SIZE_OF_ARGUMENTS);
            num_arg++;
            if (num_arg > MAX_NUM_OF_ARGUMENTS) return -3;
            pos++;
            continue;
        }
        if ((*pos == ',')||(*pos=='\n')) {
            if (number_detected) {
                number_detected = 0;
                pos++;
                continue;
            }
        }
        return -2; //неизвестные символы
    }
    if (num_arg < MIN_NUM_OF_ARGUMENTS) return -1;


    for (long i = 0; i < num_arg; i++) {
        int arg = 0;
        if (sscanf_s(arg_mass[i], "%d", &arg) == 1) {
            res += arg;
        }else return -2;
        
    }

    return res; 
}
