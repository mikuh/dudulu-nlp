#include "text_tokenizer.h"

namespace dudulu
{

std::unordered_map<std::wstring, std::pair<double, std::string>> TextTokenizer::_words = {};

TextTokenizer::TextTokenizer(const std::string& data_path)
{
    std::string default_dict = data_path + (data_path.back() == '/' ? "dict.txt" : "/dict.txt");
    _init_default_dict(default_dict);
}

void TextTokenizer::_init_default_dict(const std::string& file)
{
    std::ifstream fin(file);
    std::string line;
    std::vector<std::string> w;
    while (std::getline(fin, line)) {
        string_split(line, " ", w);
        _words[string2wstring(w[0])] = std::make_pair(atof(w[1].c_str()), w.size() == 3 ? w[2] : "\0");
        w.clear();
    }
}

std::unordered_map<std::wstring, std::pair<double, std::string>>& TextTokenizer::get_words()
{
    return _words;
}

void TextTokenizer::_init_trie()
{
}

void TextTokenizer::temp_test()
{

    for (auto iter = _words.begin(); iter != _words.end(); iter++) {
        std::cout << wstring2string(iter->first) << ":(" << iter->second.first << "," << iter->second.second << ")" << std::endl;
    }
}

} // namespace dudulu