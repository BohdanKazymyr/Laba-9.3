#include "pch.h"
#include "CppUnitTest.h"
#include "../Laba 9.2/Laba 9.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int N = 2;
			int p = 3;
			Create(p, N);
			Sort(p, N);
			Print(p, N);
		}
	};
}
