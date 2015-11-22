#ifndef TESTER_EXECUTOR_HH
#define TESTER_EXECUTOR_HH

#include <string>
#include <vector>

namespace tester {

class TestFinder;

class TestExecutor {
public:
	TestExecutor(TestFinder& finder) : m_finder(finder) {}

	void run();

	void runTest(std::string&);

private:
	TestFinder& m_finder;
};

} // tester

#endif // TESTER_EXECUTOR_HH
