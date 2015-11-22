#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include "testfinder.hh"
#include "testexecutor.hh"

namespace tester {

void TestExecutor::runTest(std::string& file)
{
	std::cout << file << std::endl;
}

void TestExecutor::run()
{
	std::vector<std::string>& tests = m_finder.getTests();

	std::for_each(tests.begin(), tests.end(),
		[this](std::string& s) { runTest(s); });
}

} // tester
