

#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\HP\source\repos\lab 6.4 itr\lab 6.4 itr\Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{		
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int n = 10;
			std::vector<double> arr = create_array(n);
			Assert::AreEqual(n, static_cast<int>(arr.size()));

		}
	};
}
