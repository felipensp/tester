#include <regex>
#include <string>
#include <fstream>
#include <streambuf>
#include <iostream>
#include "testparser.hh"

namespace tester {

TestParser::TestParser(const std::string& file) : m_file(file)
{
	readFile();
	parseFile();
}

void TestParser::readFile()
{
	std::ifstream infile;
	infile.open(m_file);

	std::stringstream buffer;
	buffer << infile.rdbuf();

	m_source = buffer.str();
}

void TestParser::parseFile()
{
	m_title = getSector("--TEST--");
	m_body = getSector("--FILE--");
	m_expect = getSector("--EXPECT--");
	if (m_expect.empty()) {
		m_expect = getSector("--EXPECTF--");
	}
}

void TestParser::dumpTest()
{
	std::cout << "[TEST]" << std::endl;
	std::cout << m_title << std::endl;

	std::cout << "[FILE]" << std::endl;
	std::cout << m_body << std::endl;

	std::cout << "[EXPECTF]" << std::endl;
	std::cout << m_expect << std::endl;
}

inline std::string& rtrim(std::string& s)
{
    s.erase(s.find_last_not_of(" \t\r\n") + 1);
    return s;
}

std::string TestParser::getSector(std::string sector)
{
	std::size_t bfound = m_source.find(sector);

	if (bfound == std::string::npos) return std::string();

	std::string block = m_source.substr(bfound + sector.length());

	std::size_t efound = block.find("\n--");

	if (efound == std::string::npos) {
		return rtrim(block);
	} else {
		return block.substr(0, efound);
	}
}

} // tester
