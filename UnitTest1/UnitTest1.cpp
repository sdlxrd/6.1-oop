#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Misha\source\repos\6.1 oop\6.1 oop\Array.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Array c = Array(5);
			
			Array::value_type* a = new Array::value_type[2];
			for (int i = 0; i < 3; i++)
			{
				a[i] = 1;
			}
			
			Array::iterator l = const_cast<Array::iterator>(c.begin());
			for (int j = 0; j < 3; j++)
			{
				*l = a[j];
			}
			
			c.Task();

			Assert::AreEqual(a[0], c.front());
		}
	};
}
