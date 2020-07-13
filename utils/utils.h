#ifndef DUDULU_UTILS_UTILS_H_
#define DUDULU_UTILS_UTILS_H_

#include <algorithm>
#include <codecvt>
#include <locale>
#include <string>
#include <vector>

namespace dudulu
{

void string_split(const std::string& str, const std::string& delimiters, std::vector<std::string>& tokens);
void wstring_split(const std::wstring& str, const std::wstring& delimiters, std::vector<std::wstring>& tokens);
std::wstring string2wstring(const std::string& str);
std::string wstring2string(const std::wstring& wstr);
inline void ltrim(std::string& s);
inline void rtrim(std::string& s);
inline void trim(std::string& s);

} // namespace dudulu

#endif