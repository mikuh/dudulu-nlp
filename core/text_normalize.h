/*
Normalize text.
- Clear meaningless characters.
- Normalize related characters.
- Chinese simple and traditional transfer.
*/
#ifndef TEXTCLEAN_H_
#define TEXTCLEAN_H_

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace dudulu
{
class TextNormalize
{
  public:
    TextNormalize();
    TextNormalize(const std::string data_path, const bool t2s, const bool digital_letter_normal, const bool keep_space);
    std::string normalize(const std::string& text, const bool digital_normal = false);
    std::vector<std::string>& normalize(std::vector<std::string>& text_list, const bool digital_normal = false);
    std::string simple2traditional(const std::string& text, const bool precision = false);
    std::string traditional2simple(const std::string& text, const bool precision = false);

  private:
    std::unordered_map<wchar_t, std::wstring> _char_project_dict;
    std::unordered_set<wchar_t> _char_keep_set;
    void _init_char_map_dict(const std::vector<std::string>& file_lists);
    void _init_char_keep_set(const std::vector<std::string>& file_lists);
};
} // namespace dudulu

#endif