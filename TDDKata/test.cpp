#include "pch.h"
#include "TextFixture.h"
#include "TestFixtureWithParam.h"


TEST_P(TestFixtureWithParam, Sample)
{
	//Arrange
	const char* op = GetParam().argument;
	int expected = GetParam().expected;
	//Act
	int actual = calc->Add(op);
	//Assert
	ASSERT_EQ(expected, actual);


}


TEST_F(TextFixture, NegArgRetManyError1) {
	int expected = -2;
	int expected_errors = 2;
	int actual = calc->Add("-8,-6");
	ASSERT_EQ(expected, actual);


}


TEST_F(TextFixture, NegArgRetManyError2) {
	
	int expected = -2;
	int expected_errors = 2;
	int actual = calc->Add("-8,-6");
	CALCULATOR_ERRORS* perrors = calc->GetLastErrors();
	ASSERT_NE((void*)perrors, (void*)NULL);

}
TEST_F(TextFixture, NegArgRetManyError3) {
	
	int expected = -2;
	int expected_errors = 2;
	int actual = calc->Add("-8,-6");
	CALCULATOR_ERRORS* perrors = calc->GetLastErrors();
	ASSERT_EQ(perrors->num_errors, expected_errors);

}

TEST_F(TextFixture, NegArgRetManyError4) {
	
	int expected = -2;
	int expected_errors = 2;
	int actual = calc->Add("-8,-6");
	CALCULATOR_ERRORS* perrors = calc->GetLastErrors();
	ASSERT_EQ(perrors->errors[0], expected);

}

TEST_F(TextFixture, NegArgRetManyError5) {
	
	int expected = -2;
	int expected_errors = 2;
	int actual = calc->Add("-8,-6");
	CALCULATOR_ERRORS* perrors = calc->GetLastErrors();
	ASSERT_EQ(perrors->errors[1], expected);

}
TEST_F(TextFixture, OneArgRetError) {
	
	int expected = -1;
	int actual = calc->Add("5");
	ASSERT_EQ(expected, actual);
}
TEST_F(TextFixture, FormatWithDelimRetOK) {
	
	int expected = 9;
	int actual = calc->Add("//:\n5\n3,1");
	ASSERT_EQ(expected, actual);
}

TEST_F(TextFixture, FormatWithBadDelimRetBad) {
	
	int expected = -2;
	int actual = calc->Add("/:\n5\n3,1");
	ASSERT_EQ(expected, actual);
}

TEST_F(TextFixture, FormatWithBad2DelimRetBad) {
	
	int expected = -4;
	int actual = calc->Add("//7\n5\n3,1");
	ASSERT_EQ(expected, actual);
}
TEST_F(TextFixture, EmptyStringEQZero) { 
	 
	int expected = 0; 
	int actual = calc->Add(""); 
	ASSERT_EQ(expected, actual); 
}

TEST_F(TextFixture, BigArgRetError) {
	
	int expected = -2;
	int actual = calc->Add("55,5");
	ASSERT_EQ(expected, actual);
}

TEST_F(TextFixture, TwoArgRetOK) {
	
	int expected = 8;
	int actual = calc->Add("5,3"); 
	ASSERT_EQ(expected, actual);
}

TEST_F(TextFixture, ThreeArgRetOK) {
	
	int expected = 9;
	int actual = calc->Add("5,3,1");
	ASSERT_EQ(expected, actual); 
}

TEST_F(TextFixture, FourArgRetOK) {
	
	int expected = 17;
	int actual = calc->Add("5,3,1,8");
	ASSERT_EQ(expected, actual);
}


TEST_F(TextFixture, NegArgRetErr) {
	
	int expected = -2;
	int actual = calc->Add("-5,5");
	ASSERT_EQ(expected, actual);
}

TEST_F(TextFixture, BAdFormatRetErr) {
	
	int expected = -2;
	int actual = calc->Add("5:3 1");
	ASSERT_EQ(expected, actual);
}

TEST_F(TextFixture, BigFormatRetErr) {
	
	int expected = -3;
	int actual = calc->Add("1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1");
	ASSERT_EQ(expected, actual);
}

TEST_F(TextFixture, NotVeryBigFormatRetOK) {
	
	int expected = 16;
	int actual = calc->Add("1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1");
	ASSERT_EQ(expected, actual);
}

TEST_F(TextFixture, FormatWithCRRetOK) {
	
	int expected = 9;
	int actual = calc->Add("5\n3,1");
	ASSERT_EQ(expected, actual);
}

