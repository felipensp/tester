#ifndef TESTER_PARSER_HH
#define TESTER_PARSER_HH

namespace tester {

class TestParser {
public:

	TestParser(std::string& file) : m_file(file) {}

	~TestParser() {}

	bool isOk() const {
		return !m_header.empty() && !m_body.empty() && !m_expected.empty();
	}

	const std::string& getHeader() const { return m_header; }
	const std::string& getBody() const { return m_body; }
	const std::string& getExpected() const { return m_expected; }

private:
	const std::string& m_file;

	std::string m_header;
	std::string m_body;
	std::string m_expected;
};

} // tester

#endif // TESTER_PARSER_HH
