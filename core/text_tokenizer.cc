#include "text_tokenizer.h"

namespace dudulu
{
struct word_unit
{
    std::wstring word;
    double freq;
    std::string classification = "\0";
    word_unit(std::wstring a, std::int32_t b, std::string c):word(a), freq(b), classification(c){};
};

std::vector<word_unit> TextTokenizer::_words = {};

TextTokenizer::TextTokenizer(const std::string& data_path){
    std::string default_dict = data_path + (data_path.back() == '/' ? "dict.txt" : "/dict.txt");
    _init_default_dict(default_dict);
}

void TextTokenizer::_init_default_dict(const std::string& file){
    std::ifstream fin(file);
    std::string line;
    std::vector<std::string> w;
    while (std::getline(fin, line)) {
        string_split(line, " ", w);
        _words.push_back(word_unit(string2wstring(w[0]), atof(w[1].c_str()), w.size() == 3 ? w[2] : "\0"));
        w.clear();
    }
}

void TextTokenizer::_init_trie(){
    
}

void TextTokenizer::temp_test(){
    for(word_unit w : _words){
        std::cout << wstring2string(w.word) << " " << w.freq << " " << w.classification << std::endl;
    }
}



} // namespace dudulu