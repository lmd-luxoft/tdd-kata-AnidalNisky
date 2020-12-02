#pragma once
#include <string>
#define MAX_NUM_OF_ARGUMENTS	(16)
#define MIN_NUM_OF_ARGUMENTS	(2)
#define MAX_SIZE_OF_ARGUMENTS	(1)
#define MAX_SIZE_OF_INPUT_STRING	(1+1+1+1+1)
/// <summary>
/// Class Under test
/// </summary>
struct CALCULATOR_ERRORS{
	int num_errors;
	int errors[MAX_NUM_OF_ARGUMENTS];
 };
class Calculator
{
	char arg_mass[MAX_NUM_OF_ARGUMENTS][MAX_SIZE_OF_ARGUMENTS+1];
	int num_arg;
	char delim;
	
public:
	CALCULATOR_ERRORS errors;
	/// <summary>
	/// Sum of elements expression
	/// </summary>
	/// <param name="expression">Input expression</param>
	/// <returns>Value of sum expression of expression</returns>
	int Add(std::string expression);
	/// <summary>
	/// Sum of elements expression
	/// </summary>
	/// <param name="expression">Input expression</param>
	/// <returns>Value of sum expression of expression</returns>
	int Add(char* expression);
	CALCULATOR_ERRORS *GetLastErrors(void);
	/// <summary>
	/// Return pos if correct
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	int CheckMinLen(char*);
	/// <summary>
	/// return size of delim or neg error code
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	int ScanDelim(char*);
	/// <summary>
	/// Add scaned arg
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	int CalculateAdd(int);

};

