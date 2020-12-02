#include "pch.h"
#include "TestFixtureWithParam.h"


std::vector<Param> CreateParametersSet()
{
	std::vector<Param> p;
	p.push_back(Param("-8,-6", -2));
	p.push_back(Param("5", -1));
	p.push_back(Param("//:\n5\n3,1", 9));
	p.push_back(Param("/:\n5\n3,1", -2));
	p.push_back(Param("//7\n5\n3,1", -4));
	p.push_back(Param("", 0));
	p.push_back(Param("55,5", -2));
	p.push_back(Param("5,3", 8));
	p.push_back(Param("5,3,1", 9));
	p.push_back(Param("5,3,1,8", 17));
	p.push_back(Param("-5,5", -2));
	p.push_back(Param("5:3 1", -2));
	p.push_back(Param("1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1", -3));
	p.push_back(Param("1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1", 16));
	p.push_back(Param("5\n3,1", 9));
	return p;
}

INSTANTIATE_TEST_CASE_P(ParametrizedTest, TestFixtureWithParam,
	::testing::ValuesIn(CreateParametersSet()));