#ifndef DUDULU_UTILS_UTILS_H_
#define DUDULU_UTILS_UTILS_H_

#include <algorithm>
#include <codecvt>
#include <locale>
#include <string>

namespace dudulu
{

template <typename T>
void string_split(const std::string& str, const std::string& delimiters, T& tokens);
template <typename T>
void wstring_split(const std::wstring& str, const std::wstring& delimiters, T& tokens);

std::wstring string2wstring(const std::string& str);
std::string wstring2string(const std::wstring& wstr);
inline void ltrim(std::string& s);
inline void rtrim(std::string& s);
inline void trim(std::string& s);
auto read_file(const std::string& file);
auto write_file(const std::string& file);

template <typename T>
void string_split(const std::string& str, const std::string& delimiters, T& tokens)
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

template <typename T>
void wstring_split(const std::wstring& str, const std::wstring& delimiters, T& tokens)
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

} // namespace dudulu

#endif