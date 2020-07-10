#include "text_normalize.h"
#include "utils/utils.h"

namespace dudulu
{
TextNormalize::TextNormalize(const std::string& data_path)
{
    _init_dictionary(data_path);
}

void TextNormalize::_init_dictionary(const std::string& data_path)
{

    std::string t2s_file = data_path + (data_path.back() == '/' ? "t2s.txt" : "/t2s.txt");
    std::string s2t_file = data_path + (data_path.back() == '/' ? "s2t.txt" : "/s2t.txt");
    std::string char_keep_file = data_path + (data_path.back() == '/' ? "char_keep.txt" : "/char_keep.txt");
    _init_t2s_dict(t2s_file);
    _init_s2t_dict(s2t_file);
    _init_keep_char_set(char_keep_file);
    std::cout << "Dictionary initialized successfully." << std::endl;
}

void TextNormalize::_init_t2s_dict(const std::string& file)
{

    std::ifstream fin(file);
    std::string line;
    std::vector<std::string> ts;
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
    std::vector<std::string> st;
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

} // namespace dudulu