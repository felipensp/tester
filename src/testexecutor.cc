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

void TestExecutor::executeTest(TestParser& parser)
{
	const std::string filename = "/tmp/1.php";

	std::ofstream test_file;
	test_file.open(filename);
	test_file << parser.getBody();
	test_file.close();

	const char *cmd = (m_program + " " + filename + " 2>&1").c_str();

    std::shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);

    if (!pipe) return;

    char buffer[256];

    while (!feof(pipe.get())) {
        if (fgets(buffer, sizeof(buffer), pipe.get()) != NULL) {
            m_output << buffer;
		}
    }
}

void TestExecutor::runTest(const std::string& file)
{
	TestParser parser(file);

	if (!parser.isOk()) {
		return;
	}

	executeTest(parser);

	if (m_output.str().compare(parser.getExpect()) == 0) {
		m_passes.push_back(file);
	} else {
		m_fails.push_back(file);
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
