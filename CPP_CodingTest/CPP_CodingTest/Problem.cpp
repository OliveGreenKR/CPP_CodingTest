#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <unordered_set>
#include <vector>

using namespace std;

struct TrieNode {
    bool isEnd;
    TrieNode* children[10]; // 10 letters from 'a' to 'j'

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 10; ++i)
        {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the trie
    bool insert(string word) {
        TrieNode* current = root;
        bool isPrefix = false;

        for (char c : word)
        {
            int index = c - 'a'; // calculate the index based on character

            if (!current->children[index])
            {
                current->children[index] = new TrieNode();
            }
            else
            {
                if (current->children[index]->isEnd)
                {
                    // If we encounter a prefix in the trie
                    return false;
                }
            }
            current = current->children[index];
        }

        current->isEnd = true;

        // If the current node has any children, it means the current word is a prefix
        for (int i = 0; i < 10; ++i)
        {
            if (current->children[i])
            {
                return false;
            }
        }

        return true;
    }
};

int main() {

    return 0;
}