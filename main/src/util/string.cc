#include <algorithm>
#include <ios>
#include <iomanip>
#include "string.h"

namespace util {
namespace string {

static const std::regex rex_left_spaces {R"(^\s*)"};
static const std::regex rex_right_spaces {R"(\s*$)"};
static const std::regex rex_spaces {R"(^\s*(.*\S)\s*$)"};

std::string &trim_left(std::string &s)
{
    std::string trimmed {std::regex_replace(s, rex_left_spaces, "")};
    s.swap(trimmed);
    return s;
}

std::string &trim_right(std::string &s)
{
    std::string trimmed {std::regex_replace(s, rex_right_spaces, "")};
    s.swap(trimmed);
    return s;
}

std::string &trim(std::string &s)
{
    std::string trimmed {std::regex_replace(s, rex_spaces, "$1")};
    s.swap(trimmed);
    return s;
}

bool starts_with(const std::string &s, const std::string &str)
{
    return std::equal(s.cbegin(), s.cbegin() + static_cast<std::string::difference_type>(str.size()), str.begin());
}

bool ends_with(const std::string &s, const std::string &str)
{
    return std::equal(s.cend() - static_cast<std::string::difference_type>(str.size()), s.cend(), str.begin());
}


} // namespace string
} // namespace util