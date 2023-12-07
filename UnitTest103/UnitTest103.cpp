#include "pch.h"
#include "CppUnitTest.h"
#include "../Project10.3/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest103
{
	TEST_CLASS(UnitTest103)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			string testFileName = "test_addProduct.txt";
			Product testProduct = { "TestProduct", "TestShop", 10.5 };

			addProduct(testFileName, testProduct);

			ifstream file(testFileName);
			string line;
			bool found = false;
			while (getline(file, line)) {
				if (line.find("TestProduct") != string::npos) {
					found = true;
					break;
				}
			}
			Assert::IsTrue(found);
			file.close();
		}
	};
}
