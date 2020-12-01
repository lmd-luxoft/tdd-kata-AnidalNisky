#include "pch.h"
#include "Calculator.h"
TEST(CalcTest, EmptyStringEQZero) { 
	Calculator calc; 
	int expected = 0; 
	int actual = calc.Add(""); 
	ASSERT_EQ(expected, actual); 
}

TEST(CalcTest, OneArgRetError) {
	Calculator calc;
	int expected = -1;
	int actual = calc.Add("5");
	ASSERT_EQ(expected, actual);
}

TEST(CalcTest, TwoArgRetOK) {
	Calculator calc;
	int expected = 8;
	int actual = calc.Add("5,3");
	ASSERT_EQ(expected, actual);
}

TEST(CalcTest, ThreeArgRetOK) {
	Calculator calc;
	int expected = 9;
	int actual = calc.Add("5,3,1");
	ASSERT_EQ(expected, actual);
}

TEST(CalcTest, FourArgRetErr) {
	Calculator calc;
	int expected = -3;
	int actual = calc.Add("5,3,1,8");
	ASSERT_EQ(expected, actual);
}


TEST(CalcTest, NegArgRetErr) {
	Calculator calc;
	int expected = -2;
	int actual = calc.Add("-5,5");
	ASSERT_EQ(expected, actual);
}

TEST(CalcTest, BAdFormatRetErr) {
	Calculator calc;
	int expected = -2;
	int actual = calc.Add("5:3 1");
	ASSERT_EQ(expected, actual);
}

TEST(CalcTest, FormatWithCRRetOK) {
	Calculator calc;
	int expected = 9;
	int actual = calc.Add("5/n3,1");
	ASSERT_EQ(expected, actual);
}