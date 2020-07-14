#ifndef UTILS_TRIE_H_
#define UTILS_TRIE_H_

#include "utils.h"
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>

namespace dudulu
{

struct TrieNode
{
    std::wstring _key;
    typedef std::unordered_map<wchar_t, std::shared_ptr<TrieNode>> NextMap;
    NextMap _map;
    TrieNode(std::wstring key = L"\0") : _key(key) {}
};

struct word_unit
{
    std::wstring word;
    double freq;
    std::string label = "\0";
    word_unit(std::wstring a, std::int32_t b, std::string c) : word(a), freq(b), label(c){};
};

class TrieTree
{
  public:
    TrieTree() : _root(std::make_shared<TrieNode>()) {}
    TrieTree(const std::unordered_map<std::wstring, std::pair<double, std::string>>& words);
    void insert(const std::wstring& word);
    bool search(const std::string&& word);
    void temp_test();

  private:
    std::unordered_map<std::wstring, std::pair<double, std::string>> _words;
    void create_trie();
    std::shared_ptr<TrieNode> _root;
};

} // namespace dudulu
#endif