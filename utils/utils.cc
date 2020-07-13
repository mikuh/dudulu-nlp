#include "utils.h"

namespace dudulu
{

void string_split(const std::string& str, const std::string& delimiters, std::vector<std::string>& tokens)
{
    // Skip delimiters at beginning.
    std::string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    // Find first "non-delimiter".
    std::string::size_type pos = str.find_first_of(delimiters, lastPos);
    while (std::string::npos != pos || std::string::npos != lastPos) {
        // Found a token, add it to the vector.
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        // Skip delimiters.
        lastPos = str.find_first_not_of(delimiters, pos);
        // Find next "non-delimiter"
        pos = str.find_first_of(delimiters, lastPos);
    }
}

void wstring_split(const std::wstring& str, const std::wstring& delimiters, std::vector<std::wstring>& tokens)
{
    // Skip delimiters at beginning.
    std::wstring::size_type lastPos = str.find_first_not_of(delimiters, 0);
    // Find first "non-delimiter".
    std::wstring::size_type pos = str.find_first_of(delimiters, lastPos);
    while (std::wstring::npos != pos || std::wstring::npos != lastPos) {
        // Found a token, add it to the vector.
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        // Skip delimiters.
        lastPos = str.find_first_not_of(delimiters, pos);
        // Find next "non-delimiter"
        pos = str.find_first_of(delimiters, lastPos);
    }
}

std::wstring string2wstring(const std::string& str)
{
    static std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    return converter.from_bytes(str);
}

std::string wstring2string(const std::wstring& wstr)
{
    static std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    return converter.to_bytes(wstr);
}

// trim from start (in place)
inline void ltrim(std::string& s)
{
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
                return !std::isspace(ch);
            }));
}

// trim from end (in place)
inline void rtrim(std::string& s)
{
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
                return !std::isspace(ch);
            }).base(),
            s.end());
}

// trim from both ends (in place)
inline void trim(std::string& s)
{
    ltrim(s);
    rtrim(s);
}

} // namespace dududlu
