/*
Normalize text.
- Clear meaningless characters.
- Normalize related characters.
- Chinese simple and traditional transfer.
*/
#ifndef TEXTNORMALIZE_H_
#define TEXTNORMALIZE_H_

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <fstream>
#include <iostream>
#include "../utils/utils.h"

namespace dudulu
{
class TextNormalize
{
  public:
    TextNormalize();
    TextNormalize(const std::string& data_path);
    std::string normalize(const std::string& text, const bool digital_normal = false);
    std::vector<std::string>& normalize(std::vector<std::string>& text_list, const bool digital_normal = false);
    std::string simple2traditional(const std::string& text, const bool precision = false);
    std::string traditional2simple(const std::string& text, const bool precision = false);

  private:
    static std::unordered_map<wchar_t, std::wstring> _char_project_dict;
    static std::unordered_map<wchar_t, wchar_t> _s2t_dict;
    static std::unordered_map<wchar_t, wchar_t> _t2s_dict;
    static std::unordered_set<wchar_t> _char_keep_set;
    void _init_dictionarys(const std::string& data_path);
    void _init_char_project_dict(const std::string& file);
    void _init_t2s_dict(const std::string& file);
    void _init_s2t_dict(const std::string& file);
    void _init_keep_char_set(const std::string& file);
  
};
} // namespace dudulu

#endif