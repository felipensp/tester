#ifndef TESTER_FINDER_HH
#define TESTER_FINDER_HH

#include <vector>
#include <string>

namespace tester {

class TestFinder {
public:

	TestFinder() : m_path("*"), m_files(), m_ext(".test") {}

	~TestFinder() {}

	void setPath(const char* path) { m_path = path; }

	void setTestExtension(const char *ext) { m_ext = ext; }

	void searchTests(std::string& path);
	void searchTests() { searchTests(m_path); }

	bool hasTests() const { return !m_files.empty(); }

	std::vector<std::string>& getTests() { return m_files; }

	int testsFound() const { return m_files.size(); }

private:
	/// Path to search
	std::string m_path;

	/// Test files found
	std::vector<std::string> m_files;

	/// Test file extension
	std::string m_ext;
};

} // tester

#endif // TESTER_FINDER_HH
