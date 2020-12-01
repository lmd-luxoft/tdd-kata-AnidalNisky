#include "pch.h"
#include "Calculator.h"


TEST(CalcTest, NegArgRetManyError1) {
	Calculator calc;
	int expected = -2;
	int expected_errors = 2;
	int actual = calc.Add("-8,-6");
	ASSERT_EQ(expected, actual);
}

TEST(CalcTest, NegArgRetManyError2) {
	Calculator calc;
	int expected = -2;
	int expected_errors = 2;
	int actual = calc.Add("-8,-6");
	CALCULATOR_ERRORS* perrors = calc.GetLastErrors();
	ASSERT_NE((void*)perrors, (void*)NULL);

}
TEST(CalcTest, NegArgRetManyError3) {
	Calculator calc;
	int expected = -2;
	int expected_errors = 2;
	int actual = calc.Add("-8,-6");
	CALCULATOR_ERRORS* perrors = calc.GetLastErrors();
	ASSERT_EQ(perrors->num_errors, expected_errors);

}

TEST(CalcTest, NegArgRetManyError4) {
	Calculator calc;
	int expected = -2;
	int expected_errors = 2;
	int actual = calc.Add("-8,-6");
	CALCULATOR_ERRORS* perrors = calc.GetLastErrors();
	ASSERT_EQ(perrors->errors[0], expected);

}

TEST(CalcTest, NegArgRetManyError5) {
	Calculator calc;
	int expected = -2;
	int expected_errors = 2;
	int actual = calc.Add("-8,-6");
	CALCULATOR_ERRORS* perrors = calc.GetLastErrors();
	ASSERT_EQ(perrors->errors[1], expected);

}
TEST(CalcTest, OneArgRetError) {
	Calculator calc;
	int expected = -1;
	int actual = calc.Add("5");
	ASSERT_EQ(expected, actual);
}
TEST(CalcTest, FormatWithDelimRetOK) {
	Calculator calc;
	int expected = 9;
	int actual = calc.Add("//:\n5\n3,1");
	ASSERT_EQ(expected, actual);
}

TEST(CalcTest, FormatWithBadDelimRetBad) {
	Calculator calc;
	int expected = -2;
	int actual = calc.Add("/:\n5\n3,1");
	ASSERT_EQ(expected, actual);
}

TEST(CalcTest, FormatWithBad2DelimRetBad) {
	Calculator calc;
	int expected = -4;
	int actual = calc.Add("//7\n5\n3,1");
	ASSERT_EQ(expected, actual);
}
TEST(CalcTest, EmptyStringEQZero) { 
	Calculator calc; 
	int expected = 0; 
	int actual = calc.Add(""); 
	ASSERT_EQ(expected, actual); 
}

TEST(CalcTest, BigArgRetError) {
	Calculator calc;
	int expected = -2;
	int actual = calc.Add("55,5");
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

TEST(CalcTest, FourArgRetOK) {
	Calculator calc;
	int expected = 17;
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

TEST(CalcTest, BigFormatRetErr) {
	Calculator calc;
	int expected = -3;
	int actual = calc.Add("1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1");
	ASSERT_EQ(expected, actual);
}

TEST(CalcTest, NotVeryBigFormatRetOK) {
	Calculator calc;
	int expected = 16;
	int actual = calc.Add("1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1");
	ASSERT_EQ(expected, actual);
}

TEST(CalcTest, FormatWithCRRetOK) {
	Calculator calc;
	int expected = 9;
	int actual = calc.Add("5\n3,1");
	ASSERT_EQ(expected, actual);
}

