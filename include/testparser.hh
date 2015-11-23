#ifndef TESTER_PARSER_HH
#define TESTER_PARSER_HH

#include <string>

namespace tester {

class TestParser {
public:

	TestParser(const std::string& file);

	~TestParser() {}

	bool isOk() const {
		return !m_title.empty() && !m_body.empty() && !m_expect.empty();
	}

	const std::string& getTitle() const { return m_title; }
	const std::string& getBody() const { return m_body; }
	const std::string& getExpect() const { return m_expect; }

	const std::string& getFile() const { return m_file; }

	void dumpTest();

private:
	void readFile();
	void parseFile();
	std::string getSector(std::string);

	const std::string& m_file;
	std::string m_source;

	std::string m_title;
	std::string m_body;
	std::string m_expect;
};

} // tester

#endif // TESTER_PARSER_HH
