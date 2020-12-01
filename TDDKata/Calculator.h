#pragma once
#include <string>
#define MAX_NUM_OF_ARGUMENTS	(3)
#define MIN_NUM_OF_ARGUMENTS	(2)
#define MAX_SIZE_OF_ARGUMENTS	(1)
#define MAX_SIZE_OF_INPUT_STRING	(1+1+1+1+1)
/// <summary>
/// Class Under test
/// </summary>
class Calculator
{
	char arg_mass[MAX_NUM_OF_ARGUMENTS][MAX_SIZE_OF_ARGUMENTS+1];
	int num_arg;
public:
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
};

