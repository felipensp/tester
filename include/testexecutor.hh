#ifndef TESTER_EXECUTOR_HH
#define TESTER_EXECUTOR_HH

namespace tester {

class TestFinder;

class TestExecutor {
public:
	TestExecutor(TestFinder&){}

	void run(){}
};

} // tester

#endif // TESTER_EXECUTOR_HH
