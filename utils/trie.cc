#include "trie.h"

namespace dudulu
{

TrieTree::TrieTree(const std::unordered_map<std::wstring, std::pair<double, std::string>>& words) : _root(std::make_shared<TrieNode>())
{
    _words = words;
    create_trie();
}

void TrieTree::insert(const std::wstring& word)
{
    auto cur_node = _root;
    for (wchar_t ch : word) {
        if (cur_node->_map.find(ch) == cur_node->_map.end()) { //not find
            cur_node->_map[ch] = std::make_shared<TrieNode>();
            cur_node = cur_node->_map[ch];
        } else { // find
            cur_node = cur_node->_map[ch];
        }
    }
    cur_node->_key = word;
}

void TrieTree::create_trie()
{
    for (auto iter = _words.begin(); iter != _words.end(); ++iter) {
        insert(iter->first);
    }
}

bool TrieTree::search(const std::string&& word)
{
    auto cur_node = _root;
    for (wchar_t ch : string2wstring(word)) {
        if (cur_node->_map.find(ch) != cur_node->_map.end()) {
            cur_node = cur_node->_map[ch];
            continue;
        }
        return false;
    }
    if (!cur_node->_key.empty()) {
        return true;
    }
    return false;
}

bool TrieTree::startswith(const std::string&& word)
{
    auto cur_node = _root;
    for (wchar_t ch : string2wstring(word)) {
        if (cur_node->_map.find(ch) != cur_node->_map.end()) {
            cur_node = cur_node->_map[ch];
            continue;
        }
        return false;
    }
    return true;
}

bool TrieTree::startswith(const std::wstring&& word)
{
    auto cur_node = _root;
    for (wchar_t ch : word) {
        if (cur_node->_map.find(ch) != cur_node->_map.end()) {
            cur_node = cur_node->_map[ch];
            continue;
        }
        return false;
    }
    return true;
}

} // namespace dudulu