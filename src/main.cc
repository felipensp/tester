#include <iostream>
#include <string>
#include "common.hh"
#include "testfinder.hh"
#include "testexecutor.hh"

using namespace tester;

void usage()
{
	std::cout << "tester " << TESTER_VERSION << std::endl;
}

int main(int argc, char **argv)
{
	TestFinder finder;

	finder.setTestExtension(".phpt");

	if (argc != 1) {
		finder.setPath(argv[1]);
	}

	finder.searchTests();

	std::cout << "Tests found: " << finder.testsFound() << std::endl;

	if (finder.hasFiles()) {
		TestExecutor executor(finder);
		executor.run();
	}

	return 0;
}
