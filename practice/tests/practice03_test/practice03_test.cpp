#include "pch.h"
#include "CppUnitTest.h"
#include "MathUtils.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace practice03test
{
	TEST_CLASS(practice03test)
	{
	public:
		
		TEST_METHOD(TestSumRange1)
		{
			Assert::AreEqual(15, MathUtils::sumRange(1, 5));
		}
		TEST_METHOD(TestSumRange2)
		{
			Assert::AreEqual(0, MathUtils::sumRange(0, 0));
		}
		TEST_METHOD(TestSumRange3)
		{
			Assert::AreEqual(6, MathUtils::sumRange(-5, 6));
		}
		TEST_METHOD(TestContainsNegative1)
		{
			std::vector<int> values = { 3, -1, 5, 7 };
			Assert::IsTrue(MathUtils::containsNegative(values));
		}
		TEST_METHOD(TestContainsNegative2)
		{
			std::vector<int> values = { 3, 0, 5, 7 };
			Assert::IsFalse(MathUtils::containsNegative(values));
		}
		TEST_METHOD(TestContainsNegative3)
		{
			std::vector<int> values;
			Assert::IsFalse(MathUtils::containsNegative(values));
		}
		TEST_METHOD(TestFindMax1)
		{
			std::vector<int> values = { 4, 3, 2, 10 };
			Assert::AreEqual(10, MathUtils::findMax(values));
		}
		TEST_METHOD(TestFindMax2)
		{
			std::vector<int> values = { 10, 2, 3, 4 };
			Assert::AreEqual(10, MathUtils::findMax(values));
		}
		TEST_METHOD(TestFindMax3)
		{
			std::vector<int> values = { 0 };
			Assert::AreEqual(0, MathUtils::findMax(values));
		}
		TEST_METHOD(TestFindMax4)
		{
			std::vector<int> values;
			Assert::AreEqual(0, MathUtils::findMax(values));
		}
		TEST_METHOD(TestFindMax5)
		{
			std::vector<int> values = { -5, -5, -5 };
			Assert::AreEqual(-5, MathUtils::findMax(values));
		}
	};
}
