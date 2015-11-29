#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <memory>
#include "testfinder.hh"
#include "testexecutor.hh"
#include "testparser.hh"

namespace tester {

void TestExecutor::createFile(TestFile type, const std::string& filename, const std::string& buffer)
{
	std::ofstream test_file;

	test_file.open(filename);
	test_file << buffer;

	switch (type) {
		case TESTCASE: m_test_file = filename; break;
		case OUTPUT: m_out_file = filename; break;
		case EXPECTED: m_exp_file = filename; break;
	}

	test_file.close();
}

void TestExecutor::executeTest(TestParser& parser)
{
	const std::string filename = "/tmp/1.php";

	/* Create test case file */
	createFile(TESTCASE, filename, parser.getBody());

	const char *cmd = (m_program + " " + filename + " 2>&1").c_str();

    std::shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);

    if (!pipe) return;

    char buffer[256];

    while (!feof(pipe.get())) {
        if (fgets(buffer, sizeof(buffer), pipe.get()) != NULL) {
            m_output << buffer;
		}
    }

	/* Expected output file */
	createFile(EXPECTED, filename + ".exp", parser.getExpect());

	/* Test case output file */
    createFile(OUTPUT, filename + ".out", m_output.str());
}

void TestExecutor::runTest(const std::string& file)
{
	TestParser parser(file);

	if (!parser.isOk()) {
		std::cout << "[Skipping] " << file << std::endl;
		return;
	}

	executeTest(parser);

	if (m_output.str().compare(parser.getExpect()) == 0) {
		std::cout << "[Passed] " << file << std::endl;
		m_passes.push_back(file);
	} else {
		std::cout << "[Failed] " << file << std::endl;
		m_fails.push_back(file);
		system(("diff -uwp " + m_out_file + " " + m_exp_file).c_str());
	}
}

void TestExecutor::run()
{
	std::vector<std::string>& tests = m_finder.getTests();

	std::for_each(tests.begin(), tests.end(),
		[this](std::string& s) { runTest(s); });

	std::cout << "Passes: " << m_passes.size() << std::endl;
	std::cout << "Fails: " << m_fails.size() << std::endl;
}

} // tester
