#include <glob.h>
#include <iostream>
#include "testfinder.hh"

namespace tester {

inline bool ends_with(std::string const& value, std::string const& ending)
{
    if (ending.size() > value.size()) return false;
    return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
}

void TestFinder::searchTests(std::string& path)
{
	glob_t glob_result;
    glob(path.c_str(), GLOB_TILDE, NULL, &glob_result);

    for (unsigned int i = 0; i < glob_result.gl_pathc; ++i){
		std::string file(glob_result.gl_pathv[i]);

        if (ends_with(file, m_ext)) {
			m_files.push_back(file);
		} else {
			searchTests(file.append("/*"));
		}
    }

    globfree(&glob_result);
}

} // tester
