#ifndef TESTER_EXECUTOR_HH
#define TESTER_EXECUTOR_HH

#include <string>
#include <vector>
#include <sstream>

namespace tester {

class TestFinder;
class TestParser;

class TestExecutor {
public:
	enum TestFile { TESTCASE, EXPECTED, OUTPUT };

	TestExecutor(TestFinder& finder) : m_finder(finder) {}

	void run();

	void runTest(const std::string&);

	void executeTest(TestParser&);

	void setProgram(const char *program) { m_program = program; }

	void createFile(TestFile, const std::string&, const std::string&);

private:
	TestFinder& m_finder;

	std::string m_program;

	std::stringstream m_output;

	std::vector<std::string> m_passes;
	std::vector<std::string> m_fails;

	std::string m_test_file;
	std::string m_out_file;
	std::string m_exp_file;
};

} // tester

#endif // TESTER_EXECUTOR_HH
