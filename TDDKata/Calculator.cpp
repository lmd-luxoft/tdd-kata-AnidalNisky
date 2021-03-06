#include "pch.h"
#include "Calculator.h"
#include <stdio.h>



int Calculator::Add(const char* expression)
{
    num_arg=0;
    memset(arg_mass, 0x00, sizeof(arg_mass));
    memset(&errors, 0x00, sizeof(errors));

    char cur_symb = 0x00;
    const char* pos = expression;
    unsigned long number_detected = 0;
    int res = 0;

    res = CheckMinLen(pos);
    if (res <= 0) return res;

    res = ScanDelim(pos);
    if (res < 0) return res;
    else pos += res;



    while (*pos) {
        if ((expression - pos) > MAX_SIZE_OF_INPUT_STRING) return -1;
        if (*pos == '-') {
            errors.errors[errors.num_errors++] = -2;
            pos++; //������� - ��� ������������ ��������� ������������� ������
        }
        if (isdigit(*pos)) {
            if (number_detected) {
                errors.errors[errors.num_errors++] = -2;
                return -2;
            }
            number_detected = 1;
            strncpy_s(arg_mass[num_arg], pos, MAX_SIZE_OF_ARGUMENTS);
            num_arg++;
            if (num_arg > MAX_NUM_OF_ARGUMENTS) {
                errors.errors[errors.num_errors++] = -3;
                return -3;
            }

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
        errors.errors[errors.num_errors++] = -2;
        return -2; //����������� �������
    }
    if (num_arg < MIN_NUM_OF_ARGUMENTS) {
        errors.errors[errors.num_errors++] = -1;
        return -1;
    }
    res = CalculateAdd(num_arg);

    
    if (errors.num_errors > 0) return  errors.errors[0];
    return res; 
}

CALCULATOR_ERRORS* Calculator::GetLastErrors(void)
{
    return &errors;
}

int Calculator::CheckMinLen(const char* pos)
{
    if (!pos) return 0; //������ ������ ���������� 0
    if (!*pos) return 0; //������ ������ ���������� 0
    //� ������ ����� ���� ������� ������� ���������� � ������� //_/n
    if (strlen(pos) < 3) {
        errors.errors[errors.num_errors++] = -1;
        return -1;
    }
    return 1;
}

int Calculator::ScanDelim(const char* pos)
{
    int res=0;
    if ((*pos == '/') && (*(pos + 1) == '/')) { //�������� ���������
        if ((!isdigit(*(pos + 2))) && (*(pos + 3) == '\n')) { //������ �����
            delim = *(pos + 2);
            pos += 4;
            res += 4;
        }
        else {
            errors.errors[errors.num_errors++] = -4;
            res= -4;
        }

    }
    return res;
}

int Calculator::CalculateAdd(int num)
{
    int res = 0;
    for (long i = 0; i < num; i++) {
        int arg = 0;
        if (sscanf_s(arg_mass[i], "%d", &arg) == 1) {
            res += arg;
        }
        else {
            errors.errors[errors.num_errors++] = -2;
        }

    }
    return res;
}
