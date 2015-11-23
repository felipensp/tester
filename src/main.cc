#include <iostream>
#include <string>
#include "common.hh"
#include "testfinder.hh"
#include "testexecutor.hh"

void usage()
{
	std::cout << "tester " << TESTER_VERSION << std::endl;
}

int main(int argc, char **argv)
{
	using namespace tester;

	TestFinder finder;

	finder.setTestExtension(".phpt");

	if (argc != 1) {
		finder.setPath(argv[1]);
	}

	finder.searchTests();

	std::cout << "Tests found: " << finder.testsFound() << std::endl;

	if (finder.hasTests()) {
		TestExecutor executor(finder);

		executor.setProgram("php");

		executor.run();
	}

	return 0;
}
