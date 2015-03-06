#include <vector>

class Trie {
public:
    Trie() {
        data.push_back(TrieNode());
    }

    vector<string> dump() {
        vector<string> ret;
        dumpHelper(0, "", ret);
        return ret;
    }

    void dumpHelper(int id, const string& word, vector<string>& ret) {
        const auto& node = data[id];
        for (int i = 0; i < 26; i++) {
            int link = node.links[i];
            if (!link) continue;
            auto newWord = word + string(1, i + 'a');
            if (data[link].end) {
                ret.push_back(newWord);
            }
            dumpHelper(link, newWord, ret);
        }
    }

    void insert(const std::string& word) {
        int current = 0;
        for (int i = 0; i < word.length(); i++) {
            int id = word[i] - 'a';
            auto& node = data[current];
            int next;
            if (node.links[id] == 0) {
                int size = data.size();
                node.links[id] = size;
                next = size;
                data.push_back(TrieNode());
            } else {
                next = node.links[id];
            }

            if (i == word.length() - 1) {
                data[next].end = true;
            }

            current = next;
            continue;
        }
    }

    bool contains(const std::string& word) {
        int current = 0;
        for (int i = 0; i < word.length(); i++) {
            int id = word[i] - 'a';
            int next = data[current].links[id];
            if (next == 0) {
                return false;
            } else {
                current = next;
            }
            if (i == word.length() - 1 && !data[next].end) {
                return false;
            }
        }
        return true;
    }

private:
    class TrieNode {
    public:
        TrieNode() {
            end = false;
            links = vector<int>(26, 0);
        }
        bool end;
        vector<int> links;
    };
    vector<TrieNode> data;
};