#include "text_normalize.h"

namespace dudulu
{

std::unordered_map<wchar_t, std::wstring> TextNormalize::_char_project_dict = {};
std::unordered_map<wchar_t, wchar_t> TextNormalize::_s2t_dict = {};
std::unordered_map<wchar_t, wchar_t> TextNormalize::_t2s_dict = {};
std::unordered_set<wchar_t> TextNormalize::_char_keep_set = {};

TextNormalize::TextNormalize(const std::string& data_path)
{
    _init_dictionarys(data_path);
}

void TextNormalize::_init_dictionarys(const std::string& data_path)
{
    std::string char_project_file = data_path + (data_path.back() == '/' ? "char_project.txt" : "/char_project.txt");
    std::string t2s_file = data_path + (data_path.back() == '/' ? "t2s.txt" : "/t2s.txt");
    std::string s2t_file = data_path + (data_path.back() == '/' ? "s2t.txt" : "/s2t.txt");
    std::string char_keep_file = data_path + (data_path.back() == '/' ? "char_keep.txt" : "/char_keep.txt");
    _init_char_project_dict(char_project_file);
    _init_t2s_dict(t2s_file);
    _init_s2t_dict(s2t_file);
    _init_keep_char_set(char_keep_file);
    std::cout << "Dictionary initialized successfully." << std::endl;
}

void TextNormalize::_init_char_project_dict(const std::string& file)
{
    std::ifstream fin(file);
    std::string line;
    std::vector<std::wstring> pro;
    while (std::getline(fin, line)) {
        wstring_split(string2wstring(line), L",", pro);
        _char_project_dict[pro[0][0]] = pro[1][0];
        pro.clear();
    }
}

void TextNormalize::_init_t2s_dict(const std::string& file)
{

    std::ifstream fin(file);
    std::string line;
    std::vector<std::wstring> ts;
    while (std::getline(fin, line)) {
        wstring_split(string2wstring(line), L"\t", ts);
        _t2s_dict[ts[0][0]] = ts[1][0];
        ts.clear();
    }
}

void TextNormalize::_init_s2t_dict(const std::string& file)
{
    std::ifstream fin(file);
    std::string line;
    std::vector<std::wstring> st;
    while (std::getline(fin, line)) {
        wstring_split(string2wstring(line), L"\t", st);
        _s2t_dict[st[0][0]] = st[1][0];
        st.clear();
    }
}

void TextNormalize::_init_keep_char_set(const std::string& file)
{
    std::ifstream fin(file);
    std::string line;
    while (std::getline(fin, line)) {
        _char_keep_set.insert(string2wstring(line)[0]);
    }
}

std::string TextNormalize::normalize(const std::string& text, const bool digital_normal)
{
    // text: the sentence to normalize
    // digital_normal: Normalize all Numbers to ▁

    // if a char consecutive occurrences 3 times, delete
    static auto is_add = [](const wchar_t& x, wchar_t& y, int& z) -> bool {
        if (x == y) {
            y = x;
            z += 1;
        } else {
            y = x;
            z = 0;
        }
        if (z > 2)
            return true;
        return false;
    };

    std::wstring result = L"\0";
    wchar_t last_char = -1;
    int consecutive_occurrences = 0;
    std::wstring w_text = string2wstring(text);

    for (const auto ch : w_text) {
        if (_char_project_dict.find(ch) != _char_project_dict.end()) {
            if (is_add(ch, last_char, consecutive_occurrences))
                continue;
            result.append(_char_project_dict[ch]);
        } else if (_char_keep_set.find(ch) != _char_keep_set.end()) {
            if (is_add(ch, last_char, consecutive_occurrences))
                continue;
            result += ch;
        }
    }

    if (digital_normal) {
        std::wstring ret;
        static std::unordered_set<wchar_t> digital_set = {L'0', L'1', L'2', L'3', L'4', L'5', L'6', L'7', L'8', L'9', L'.'};
        bool flag = true;
        for (const auto ch : result) {
            if (digital_set.find(ch) != digital_set.end()) {
                if (flag) {
                    ret += L'▁';
                    flag = false;
                }
            } else {
                ret += ch;
                flag = true;
            }
        }
        result = ret;
    }

    return wstring2string(result);
}

std::vector<std::string>& TextNormalize::normalize(std::vector<std::string>& text_list, const bool digital_normal)
{
    for (unsigned int i = 0; i < text_list.size(); i++) {
        text_list[i] = normalize(text_list[i], digital_normal);
    }
    return text_list;
}

} // namespace dudulu