#ifndef TEXT_TOKENIZER_H
#define TEXT_TOKENIZER_H

#include "../utils/utils.h"
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

namespace dudulu
{

class TextTokenizer
{
  public:
    TextTokenizer();
    TextTokenizer(const std::string& data_path);
    std::vector<std::string> cut(const std::string& sentence);
    std::vector<std::pair<std::string, std::string>> tag(const std::string& sentence);
    void set_dictionary(const std::string& file);
    std::unordered_map<std::wstring, std::pair<double, std::string>>& get_words();
    void temp_test();
    

  private:
    static std::unordered_map<std::wstring, std::pair<double, std::string>> _words;
    void _init_default_dict(const std::string& file);
    void _init_trie();
};
} // namespace dudulu

#endif