#include "text_tokenizer.h"

namespace dudulu
{

std::unordered_map<std::wstring, std::pair<double, std::string>> TextTokenizer::_words = {};

TextTokenizer::TextTokenizer(const std::string& data_path)
{
    std::string default_dict = data_path + (data_path.back() == '/' ? "dict.txt" : "/dict.txt");
    _init_default_dict(default_dict);
    _init_trie();
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
    std::unique_ptr<TrieTree> trie(new TrieTree(_words));
    _trie = std::move(trie);
}

void TextTokenizer::temp_test()
{

    for (auto iter = _words.begin(); iter != _words.end(); iter++) {
        std::cout << wstring2string(iter->first) << ":(" << iter->second.first << "," << iter->second.second << ")" << std::endl;
    }
}

std::vector<std::string> TextTokenizer::cut(const std::string&& sentence)
{
    std::vector<std::string> res;
    std::wstring t = string2wstring(sentence);
    for (uint i = 0; i < t.size();) {
        for (uint j = 1; i + j <= t.size(); j++) {
            if (_trie->startswith(t.substr(i, j))) {
                continue;
            }
            if (j == 1) {
                res.push_back(wstring2string(t.substr(i, j)));
            } else {
                res.push_back(wstring2string(t.substr(i, --j)));
            }
            i += j;
            break;
        }
    }

    return res;
}

} // namespace dudulu