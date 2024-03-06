#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

class TrieNode {
public:
    unordered_map<char, TrieNode*> child;
    bool end;
    TrieNode() : end(0) {}
};

class Trie {
private:
    TrieNode* root;

public:
    Trie(){
        root = new TrieNode();
    }

    void insert(string& word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (curr->child.find(c) == curr->child.end()) {
                curr->child[c] = new TrieNode();
            }
            curr = curr->child[c];
        }
        curr->end = true;
    }

    bool consist(string& word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (curr->child.find(c) == curr->child.end()) {
                return false;
            }
            curr = curr->child[c];
        }
        return curr != NULL && curr->end;
    }

    vector<string> getPrefixes(string& word) {
        vector<string> prefix;
        TrieNode* curr = root;
        string pre;

        for (char c : word) {
            if (curr->child.find(c) != curr->child.end()) {
                pre += c;
                curr = curr->child[c];
                if (curr->end) {
                    prefix.push_back(pre);
                }
            } else {
                break;
            }
        }

        return prefix;
    }
};

class Solution {
private:
    Trie trie;
    deque<pair<string, string>>q;
 
public:

 void buildTrie(const std::string& filePath) {
        ifstream file(filePath);
        if (!file) {
           cout << "There was some error with the file!" <<endl;
            exit(0);
        } 
       string line;
        while (getline(file, line)) {
            
            string word =line;
            vector<string> prefixes = trie.getPrefixes(word);
            for (string& prefix : prefixes) {
                q.push_back({word, word.substr(prefix.length())});
            }
            trie.insert(word);
        }
        file.close();
    }
    pair<string, string> findLongestCompoundWords() {
        string longest_word;
        string second_longest;
        size_t max_len = 0;

        while (!q.empty()) {
            pair<string,string>p= q.front();
            string word=p.first;
            string suff=p.second;
            q.pop_front();
            if (trie.consist(suff) && word.size() > max_len){
                second_longest = longest_word;
                longest_word = word;
                max_len = word.size();
            } 
            else {
                auto prefixes = trie.getPrefixes(suff);
                for ( auto& pre : prefixes) {
                    q.push_back(make_pair(word, suff.substr(pre.size())));
                }
            }
        }   
        return make_pair(longest_word, second_longest);
    }
};
 
int main() {
    Solution sol;
    auto start = std::chrono::steady_clock::now();
    sol.buildTrie("Input_01.txt");
    auto p=sol.findLongestCompoundWords();
     string first=p.first;
     string second=p.second;
    auto end = std::chrono::steady_clock::now();

    cout << "Longest Compound Word: " << first << endl;
    cout << "Second Longest Compound Word: " << second << endl;
    auto x=std::chrono::duration<double>(end - start).count();
    cout << "Time taken: " << x<< " seconds" << endl;


string s="";
s="Longest Compound Word: ";
s+=first;
ofstream file1("Output.txt");
file1<<s<<endl;  
s="Second Longest Compound Word: ";
s+=second;
file1<<s<<endl;
s="Time taken: ";
s+=to_string(x);
s+=" seconds";
file1<<s<<endl;
file1.close();

    return 0;
}
