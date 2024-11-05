#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include <string>
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BTSMansionGameAutomatedTest
{
	TEST_CLASS(BTSMansionGameAutomatedTest)
	{
	public:
		
		TEST_METHOD(BTS_PlayerConstructor_Test)
		{
			Logger::WriteMessage("Hello from BTS_PlayerConstructor_Test\n");
		}
	};
}
